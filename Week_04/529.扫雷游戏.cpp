/*
 * @lc app=leetcode.cn id=529 lang=cpp
 *
 * [529] 扫雷游戏
 */

// @lc code=start
class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        //取出单击的行列号
        int row = click[0];
        int col = click[1];
        if( board[row][col] == 'M') //规则1
        {
            board[row][col] = 'X';
        }
        else if( board[row][col] == 'E') //规则2、3
        {
            updateBoard(board,row,col);
        }
        return board;
    }
    void  updateBoard(vector<vector<char>>& board, int row,int col )
    {
        int rowcount = board.size();
        int colcount = board[0].size();
        if( row > rowcount-1 || row < 0) return;
        if( col < 0 || col > colcount -1 ) return;
        if( board[row][col] == 'E')//规则3
        {
            int Mcount = getMcount(board,row,col);
            if( Mcount > 0)
            {
                board[row][col] = Mcount +'0';
            }
            else//规则2
            {
                board[row][col] = 'B';
                //递归各个方向
                updateBoard(board,row-1,col);
                updateBoard(board,row-1,col+1);
                updateBoard(board,row,col+1);
                updateBoard(board,row+1,col+1);
                updateBoard(board,row+1,col);
                updateBoard(board,row+1,col-1);
                updateBoard(board,row,col-1);
                updateBoard(board,row-1,col-1);
            }
        }
    }
    int getMcount(vector<vector<char>>& board,int row,int col)
    {
        //传入时 row col已经合法，所以只需要检测row±1  col±1是否合法
        int count = 0;
        int rowcount = board.size();
        int colcount = board[0].size();
        //统计正上方
        if( row-1 >=0 && board[row-1][col] == 'M')
            count++;
        //统计右上角
        if ( row-1>=0 && col+1 < colcount && board[row-1][col+1] == 'M')
            count++;
        //统计右侧
        if( col+1 < colcount && board[row][col+1] == 'M')
            count++;
        //统计右下角
        if( row+1 < rowcount && col+1 < colcount && board[row+1][col+1] == 'M')
            count++;
        //统计正下方
        if( row+1 <rowcount &&  board[row+1][col] == 'M')
            count++;
        //统计左下角
        if( row+1 <rowcount && col-1 >=0 && board[row+1][col-1] == 'M')
            count++;
        //统计左侧
        if( col-1 >=0 && board[row][col-1] == 'M')
            count++;
        //统计左上角
        if( col-1 >=0 && row-1>=0 && board[row-1][col-1] == 'M')
            count++;
        return count; 
    }
};
// @lc code=end

