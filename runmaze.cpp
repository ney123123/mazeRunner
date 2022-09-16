#include "wall.h"
#include "maze.h"
#include <vector>
#include <iostream>
#include <stack>
/********************************************************************/
/*                                                                  */
/*  A1 Part 3: runMaze                                  */
/*                                                                  */
/*  Author1 Name: <name here>                                       */
/*      - class/function list/main author or main checker           */
/*  Author2 Name: <name here>                                       */
/*      - class/function list/main author or main checker           */
/*                                                                  */
/********************************************************************/
using namespace std;
int runMaze2(Maze& theMaze, std::vector<int> path2, int startCell, int endCell, stack<int> last,std::vector<int>& temV);
int runMaze(Maze& theMaze, int path[], int startCell, int endCell){
    std::vector<int> tem;
    std::vector<int> temV;
    stack<int> tem2;
    int len = 0;
    len = runMaze2(theMaze, tem, startCell, endCell,tem2,temV);
    //cout <<"temV.size() ="<<  temV.size() << endl;
    //vector<int>::iterator it = temV.begin();
    //int j = 0;
    
    for(size_t a = 0; a < temV.size() ; a++){
        
        path[a] = temV[a];
        //cout << "path[a] = " << path[a] << endl;
    }
    
    return temV.size();
    
    
}
int runMaze2(Maze& theMaze, std::vector<int> path2, int startCell, int endCell, stack<int> last,std::vector<int>& temV){
    
    int num = startCell;
    //cout << "now = " << startCell << endl;
    int available[4]={startCell+1,startCell-1,startCell+theMaze.numCols(),startCell-theMaze.numCols() };
    //for(int i = 0; i< 4 ; i++)
    
   
    theMaze.mark(startCell);
    
    if(!path2.empty()){
        if(path2.back() != startCell)
    path2.push_back(startCell);
    }
    else{
        path2.push_back(startCell);
    }

   
    if(startCell == endCell){
        //cout << "true" << endl;
        for(auto k: path2){
            temV.push_back(k);
        }
        //cout <<"temV.size() ="<<  temV.size() << endl;
        return -1;
        
    }
    int k = 0;
    for(int next: available){
        
        if(next>=0 && !(theMaze.isMarked(next)) && theMaze.canGo(startCell, next)){
            
            k++;
        }}
    
    if (k> 1){
        last.push(startCell);
    }
    if(k == 0){
        //cout << "dead end\n";
        if(!last.empty()){
        int lastCross =last.top();
        last.pop();
            while(true){
                if(path2.back()!= lastCross)
                    path2.pop_back();
                else
                    break;
            }
        runMaze2(theMaze, path2, lastCross, endCell,last,temV);
        }
        else{
            return -1;
        }
    }
    for(int next: available){
        
        if(next>=0 && !(theMaze.isMarked(next)) && theMaze.canGo(startCell, next)){
            
            //cout << "next=" << next << endl;
            
            
            num = runMaze2(theMaze, path2, next, endCell,last,temV);
            
        }
    }
    return 0;
}
