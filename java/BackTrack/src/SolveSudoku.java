
public class SolveSudoku {
	/**
	 * nowcoder version
	 *
	*/
	private static boolean[][] row = new boolean[9][9];//
    private static boolean[][] col = new boolean[9][9];
    private static boolean[][] square = new boolean[9][9];
    private static char[][] result = new char[9][9];
    private static int times=0;
    
    public static void solveSudoku(char[][] board) {
        for(int i=0; i<9; ++i){// initialize
            for(int j=0; j<9; ++j){
                row[i][j] = true;
                col[i][j] = true;
                square[i][j] = true;
            }
        }
        // 
        for(int i=0; i<9; ++i){
            for(int j=0; j<9; ++j){
                if(board[i][j] == '.') {continue;}
                int t = board[i][j] - '1';
                row[t][i] = false;
                col[t][j] = false;
                square[t][(i/3)*3 + (j/3)] = false;
            }
        }
        backTracking(0, board);
        board = result;
        displayMatrix(result);
    }
    
    public static boolean backTracking(int position, char[][] B){
    	times++;
        if (position>80) {result = B; return true;}
        int i = position/9;
        int j = position%9;
//        displayMatrix(B);
        if(B[i][j]=='.'){
            for(int t=0; t<9; ++t){
                if(row[t][i] && col[t][j] && square[t][(i/3)*3 + (j/3)]){
                    row[t][i] = false;
                    col[t][j] = false;
                    square[t][(i/3)*3 + (j/3)] = false;
                    B[i][j] = (char)(t+1+'0');
//                    displayMatrix(B);
                    if(backTracking(position+1, B)) {return true;}
                    row[t][i] = true;
                    col[t][j] = true;
                    square[t][(i/3)*3 + (j/3)] = true;
                    B[i][j] = '.';
//                    displayMatrix(B);
                }
            }
            return false;
        }
        else{
            return backTracking(position+1, B);
        }
    }

    public static void displayMatrix(char[][] matr) {
    	int len = matr.length;
    	for(int i=0; i<len; i++) {
    		displayArray(matr[i]);
    		if((i+1)%3==0) {System.out.println();}
    	}
    	System.out.println();
    }

    public static void displayArray(char[] arr) {
    	int len = arr.length;
    	System.out.print("[ ");
    	for(int i=0; i<len; i++) {
    		System.out.print(arr[i] + " ");
    		if((i+1)%3==0 && (i+1)/3!=3) {System.out.print(" ");}
    	}
    	System.out.print("]");
    	System.out.println();
    }

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		char[][] board = {{'5','3','.','.','7','.','.','.','.'},
						  {'6','.','.','1','9','5','.','.','.'},
						  {'.','9','8','.','.','.','.','6','.'},
						  {'8','.','.','.','6','.','.','.','3'},
						  {'4','.','.','8','.','3','.','.','1'},
						  {'7','.','.','.','2','.','.','.','6'},
						  {'.','6','.','.','.','.','2','8','.'},
						  {'.','.','.','4','1','9','.','.','5'},
						  {'.','.','.','.','8','.','.','7','9'}};

		char[][] board1 =  {{'.','.','9','.','.','.','7','.','.'},
							{'.','2','8','.','.','.','6','4','.'},
							{'.','.','.','.','.','.','.','.','.'},
							{'.','.','.','7','.','6','.','.','.'},
							{'.','.','.','.','1','.','.','.','.'},
							{'.','.','.','2','.','5','.','.','.'},
							{'.','.','.','.','.','.','.','.','.'},
							{'.','9','4','.','.','.','8','2','.'},
							{'.','.','7','.','.','.','5','.','.'}};

		char[][] board2 =  {{'.','.','1','.','.','5','.','7','.'},
							{'.','.','.','.','.','.','5','.','9'},
							{'9','.','.','.','.','1','.','4','.'},
							{'.','.','.','.','6','.','3','.','.'},
							{'.','.','.','.','.','.','.','.','.'},
							{'4','.','6','.','7','.','.','.','.'},
							{'.','3','.','9','.','.','.','.','7'},
							{'2','.','5','.','.','.','.','.','.'},
							{'.','1','.','4','.','.','6','.','.'}};
		displayMatrix(board2);
		solveSudoku(board2);
		System.out.println(times);
	}
}
