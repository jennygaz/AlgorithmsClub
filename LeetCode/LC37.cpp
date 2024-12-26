/* LeetCode 37 - Sudoku Solver */
/* by jennygaz */
#include <bitset>
#include <vector>
#include <functional>

using namespace std;

const int N = 3;
const int MAXN = 9;
bool solved = false;
bitset<10> rows[10], cols[10], squares[10];

inline int get_square(int x, int y) {
  return x / N * N + y / N;
}

inline bool is_invalid_position(int x, int y, int value) {
  return rows[x][value] or cols[y][value] or squares[get_square(x, y)][value];
}

void solve(int x, int y, vector<vector<char>>& board) {
  if( solved ) return;
  if( x == MAXN and y == 0 ) solved = true;
  else {
    if( board[x][y] != '.' ) {
      solve( y == MAXN - 1 ? x + 1 : x, y == MAXN - 1 ? 0 : y + 1, board );
    } else {
      for( int value {1}; value <= MAXN; ++ value ) {
	const int sq = get_square(x, y);
	if( is_invalid_position(x, y, value) ) continue;
	board[x][y] = '0' + value;
	rows[x].set(value, true);
	cols[y].set(value, true);
	squares[sq].set(value, true);
	solve( y == MAXN - 1 ? x + 1 : x, y == MAXN - 1 ? 0 : y + 1, board );
	if( solved ) return;
	rows[x].set(value, false);
	cols[y].set(value, false);
	squares[sq].set(value, false);
      }
      board[x][y] = '.';
    }
  }
}

void solveSudoku(vector<vector<char>>& board) {
  for( int i = 0; i < MAXN; ++ i ) {
    for( int j = 0; j < MAXN; ++ j ) {
      if( board[i][j] != '.' ) {
	rows[i].set( board[i][j] - '0', true);
	cols[j].set( board[i][j] - '0', true);
	squares[get_square(i, j)].set( board[i][j] - '0', true);
      }
    }
  }
  solve(0, 0, board);
}
