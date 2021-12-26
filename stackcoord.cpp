#include <stack>
#include <string>
#include <iostream>
using namespace std;


class Coord
 {
 public:
     Coord(int rr, int cc) : m_r(rr), m_c(cc) {}
     int r() const { return m_r; }
     int c() const { return m_c; }
 private:
     int m_r;
     int m_c;
 };

bool pathExists(string maze[], int nRows, int nCols, int sr, int sc, int er, int ec){
    /*if (sr>=0&&sc>=0&&sr<nRows&&sc<nCols&&er>=0&&ec>=0&&er<nRows&&ec<nCols){
        return false;
    }
     */
    stack<Coord> stk;
    
    if (maze[sr][sc]=='.'){
        stk.push(Coord(sr,sc));
        maze[sr][sc]='S';
    }
    else{
        return false;
    }
    
    while(!stk.empty()){
        
        Coord location = stk.top();
        stk.pop();
        
        if (location.r()==er && location.c()==ec) {
            return true;
        }
        
        int x=location.r();
        int y=location.c();
        
        if (maze[x][y+1] == '.') {
            stk.push(Coord(x,y+1));
            maze[x][y+1]='S';
        }
        
        if (maze[x+1][y]=='.') {
            stk.push(Coord(x+1,y));
            maze[x+1][y]='S';
        }
        
        if (maze[x][y-1]=='.'){
            stk.push(Coord(x,y-1));
            maze[x][y-1]='S';
            
        }
        
        if (maze[x-1][y]=='.'){
            stk.push(Coord(x-1,y));
            maze[x-1][y]='S';
        }
    }
    return false;
}

int main()
{
string maze[10] = {
"XXXXXXXXXX", 
"X...X..X.X",
"X..XX....X",
"X.X.XXXX.X",
"XXX......X",
"X...X.XX.X",
"X.X.X..X.X",
"X.XXXX.X.X",
"X..X...X.X",
"XXXXXXXXXX"
};
 
if (pathExists(maze, 10,10, 4,3, 1,8))
    cout << "Solvable!" << endl;
else
    cout << "Out of luck!" << endl;
    
}

