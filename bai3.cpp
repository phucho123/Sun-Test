#include<bits/stdc++.h>
using namespace std;


class GameManager{
private:
    vector<vector<int>>currentState;
    vector<int>magicTubes;
public:
    GameManager(vector<vector<int>>initState,vector<int>magicTubes){
        this->currentState = vector<vector<int>>(initState.size());
        for(int i = 0;i<initState.size();i++){
            for(int j = 0;j<initState[i].size();j++){
                if(initState[i][j] == 0) break;
                this->currentState[i].push_back(initState[i][j]);
            }
        }
        this->magicTubes = vector<int>(initState.size(),0);
        for(int i:magicTubes){
            this->magicTubes[i] = 1;
        }
    }
    void move(int from,int to){
        if(this->currentState[from].size() && this->currentState[to].size()<4){
            if(this->magicTubes[from]){
                int change = currentState[from][0];
                this->currentState[from].erase(this->currentState[from].begin());
                this->currentState[to].push_back(change);
            }
            else{
                int change = currentState[from].back();
                this->currentState[from].pop_back();
                this->currentState[to].push_back(change);
            }
        }else{
            cout<<"CAN'T MOVE"<<endl;
        }
        cout<<"MOVE FROM "<<from<<" TO "<<to<<endl;
        this->printState();
        if(this->isWin()) cout<<"YOU WIN";
    }
    bool isWin(){
        for(int i = 0;i<this->currentState.size();i++){
            if(this->currentState[i].size() == 0) continue;
            else if(this->currentState[i].size() != 4) return false;
            int color = this->currentState[i][0];
            for(int j = 1;j<this->currentState[i].size();j++){
                if(this->currentState[i][j] != color) return false;
            }
        }
        return true;
    }
    void printState(){
        for(int i = 4;i>=1;i--){
            for(int j = 0;j<this->currentState.size();j++){
                if(this->currentState[j].size() < i) cout<<0<<"\t";
                else cout<<this->currentState[j][i-1]<<"\t";
            }
            cout<<endl;
        }
    }
};
void Play(){
    vector<vector<int>>initState{
      {1, 2, 3, 2},
      {2, 1, 3, 1},
      {3, 1, 2, 3},
      {0, 0, 0, 0},
    }; //INIT STATE
    vector<int>magicTubes{0,1}; //MAGICTUBES INDEX
    GameManager game(initState,magicTubes);
    game.printState();
    while(!game.isWin()){
        int from,to;
        cout<<"Moving from: ";
        cin>>from;
        cout<<endl;
        cout<<"Moving to: ";
        cin>>to;
        cout<<endl;
        game.move(from,to);
    }
}
int main(){
    Play();
    return 0;
}