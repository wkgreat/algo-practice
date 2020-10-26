package wk.leetcode.t37;

import java.util.HashSet;
import java.util.Set;

/**
 * @author Ke Wang
 * @since 2020/10/20
 */
public class T37 {
    public static void main(String[] args) {
        char[][] board = new char[][]
                {
                        {'5','3','.','.','7','.','.','.','.'},
                        {'6','.','.','1','9','5','.','.','.'},
                        {'.','9','8','.','.','.','.','6','.'},
                        {'8','.','.','.','6','.','.','.','3'},
                        {'4','.','.','8','.','3','.','.','1'},
                        {'7','.','.','.','2','.','.','.','6'},
                        {'.','6','.','.','.','.','2','8','.'},
                        {'.','.','.','4','1','9','.','.','5'},
                        {'.','.','.','.','8','.','.','7','9'}
                };
        Solution1 solution = new Solution1();
        boolean b = solution.resolve(board, 0);
        System.out.println(b);
    }
}

/**
 * 简单回溯法-效率不高
 * */
class Solution1 {
    public void solveSudoku(char[][] board) {
        resolve(board, 0);
    }
    public boolean resolve(char[][] board, int m) {
        int i = m/9, j = m%9;
        if(m>=81) {
            return true;
        }
        if(board[i][j]!='.') {
            return resolve(board, m+1);
        } else {
            Set<Character> theSet = new HashSet<>();
            for(int k=0;k<9;++k) {
                theSet.add(board[i][k]);
                theSet.add(board[k][j]);
                int bi = 3*(i/3)+k/3, bj=3*(j/3)+k%3;
                theSet.add(board[bi][bj]);
                theSet.remove('.');
            }
            if(theSet.size()>=9) return false;
            for(char c='1'; c<='9'; c++) {
                if(!theSet.contains(c)) {
                    board[i][j]=c;
                    boolean b = resolve(board, m+1);
                    if(b) {
                        return true;
                    } else {
                        board[i][j]='.';
                    }
                }
            }
        }
        return false;
    }
}

