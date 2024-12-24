/* LeetCode 36 - Valid Sudoku */
/* by jennygaz */

inline bool are_columns_valid(vector<vector<char>>& board) {
  bitset<9> columns[9] {};
  bitset<9> rows[9] {};
  int counts_rows[9] {}, counts_cols[9] {};
  for( int row = 0; row < 9; ++ row ) {
    for( int column = 0; column < 9; ++ column ) {
      if( board[row][column] == '.' ) continue;
      columns[column][board[row][column] - '1'] = true;
      ++ counts_cols[column];
      rows[row][board[row][column] - '1'] = true;
      ++ counts_rows[row];
    }
  }
  for( int row = 0; row < 9; ++ row )
    if( rows[row].count() != counts_rows[row] ) return false;

  for( int col = 0; col < 9; ++ col )
    if( columns[col].count() != counts_cols[col] ) return false;
  return true;
}

inline bool are_squares_valid(vector<vector<char>>& board) {
  bitset<9> squares[9] {};
  int counts[9] {};
  for( int row = 0; row < 9; ++ row ) {
    for( int col = 0; col < 9; ++ col ) {
      if( board[row][col] == '.' ) continue;
      squares[row / 3 * 3 + col / 3][board[row][col] - '1'] = true;
      ++ counts[row / 3 * 3 + col / 3];
    }
  }
  for( int sq = 0; sq < 9; ++ sq )
    if( squares[sq].count() != counts[sq] ) return false;
  return true;
}

inline bool isValidSudoku(vector<vector<char>>& board) {
  return are_columns_valid(board) and are_squares_valid(board);
}
