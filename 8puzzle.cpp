#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;

// Generate possible next states by moving blank (0)
vector<vector<vector<int>>> expandStates(vector<vector<int>> board){
    int r = -1, c = -1;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j]==0){
                r=i; c=j;
                break;
            }
        }
        if(r!=-1) break;
    }

    vector<vector<vector<int>>> nextStates;
    int dr[4] = {-1,1,0,0};
    int dc[4] = {0,0,-1,1};

    for(int k=0;k<4;k++){
        int nr=r+dr[k], nc=c+dc[k];
        if(nr>=0 && nr<3 && nc>=0 && nc<3){
            vector<vector<int>> temp=board;
            swap(temp[r][c], temp[nr][nc]);
            nextStates.push_back(temp);
        }
    }
    return nextStates;
}

// Convert board into string key
string getKey(const vector<vector<int>>& b){
    string s="";
    for(auto &row: b){
        for(int x: row) s+= to_string(x);
    }
    return s;
}

// Heuristic: misplaced tiles
int heuristicMismatch(const vector<vector<int>>& b){
    int mismatch=0;
    int goal[3][3]={{1,2,3},{4,5,6},{7,8,0}};
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(b[i][j]!=goal[i][j] && b[i][j]!=0) mismatch++;
        }
    }
    return mismatch;
}

void solvePuzzle(vector<vector<int>> start){
    struct NodeCmp{
        bool operator()(const pair<int,string>& A,const pair<int,string>& B)const{
            return A.first>B.first;  // min-heap
        }
    };

    priority_queue<pair<int,string>, vector<pair<int,string>>, NodeCmp> pq;
    map<string, vector<vector<int>>> stateMap;
    set<string> seen;

    string startKey=getKey(start);
    stateMap[startKey]=start;
    pq.push({heuristicMismatch(start), startKey});

    while(!pq.empty()){
        auto cur=pq.top(); pq.pop();
        string curKey=cur.second;
        if(seen.count(curKey)) continue;
        seen.insert(curKey);

        vector<vector<int>> board=stateMap[curKey];
        int h=heuristicMismatch(board);

        cout<<"h = "<<h<<"\n";
        for(auto &row: board){
            for(int v: row) cout<<v<<" ";
            cout<<"\n";
        }
        cout<<"--------\n";

        if(h==0){
            cout<<" Goal state reached!\n";
            return;
        }

        for(auto &nxt: expandStates(board)){
            string k=getKey(nxt);
            if(!seen.count(k)){
                stateMap[k]=nxt;
                pq.push({heuristicMismatch(nxt), k});
            }
        }
    }
}

int main(){
    vector<vector<int>> init={{1,2,3},{4,0,6},{7,5,8}};

    cout<<"Starting configuration:\n";
    for(auto &r:init){
        for(int v:r) cout<<v<<" ";
        cout<<"\n";
    }
    cout<<"\n";

    solvePuzzle(init);

    return 0;
}
