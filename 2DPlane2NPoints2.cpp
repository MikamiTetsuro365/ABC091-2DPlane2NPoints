#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <cmath>
#include <utility>

using namespace std;

bool compare_by_b(pair<int, int> a, pair<int, int> b) {
    if(a.second != b.second){
        return a.second < b.second;
    }else{
        return a.first < b.first;
    }
}

int main(){

    int N = 0;
    cin >> N;

    vector<pair<int, int> > r(N);
    vector<pair<int, int> > b(N); 

    for(int i = 0; i < N; i++){
        int x, y = 0;
        cin >> x >> y;
        r[i] = make_pair(x,y);
    }
    for(int i = 0; i < N; i++){
        int x, y = 0;
        cin >> x >> y;
        b[i] = make_pair(x,y);
    }

    sort(b.begin(),b.end());
    //sort(bx.begin(),bx.end());

    pair<int, int> maxry;
    maxry = make_pair(-1, -1);

    int pairNum = 0;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(b[i].first > r[j].first && r[j].first >= 0){
                if(b[i].second > r[j].second){
                    if(maxry.first < r[j].second){
                        maxry = make_pair(r[j].second, j);
                    }
                }
            }
        }
        //ペア決定
        if(!(maxry.first == -1)){
            pairNum++;
            //ペアにしたやつはもうペアにはしない
            r[maxry.second].first = -1;
            r[maxry.second].second = -1;
            //初期化
            maxry = make_pair(-1, -1);
        }
    }
    
    std::cout << pairNum << std::endl;
}