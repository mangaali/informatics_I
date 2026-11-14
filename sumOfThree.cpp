#include <bits/stdc++.h>
using namespace std;

// The first input line has two integers n and x: the array size and the target sum.
// The second line has n integers a_1,a_2,..,a_n: the array values.

int n, x;
vector <pair<int, int>> Good;
int Search(int x);


int main(){
    cin >> n;
    cin >> x; 
    Good.resize(n);

    for(int i=0; i<n; i++){
        cin >> Good[i].first;
        Good[i].second = i + 1; 
    }

    sort(Good.begin(), Good.end());
    Search(x);
}
int Search(int a){
    int k, l, found=0;
    for(k=0; k<n; k++){
        long long target = (long long)x - Good[k].first;
        int l = k + 1;
        int m = n - 1;

        while(l < m){
            long long current = (long long)Good[l].first + Good[m].first;
            if(current==target){
                cout << Good[k].second << " " << Good[l].second << " " << Good[m].second << "\n";
                    return 0;
            }
            else if(current>target){
                m--;
        }
        else{
            l++;
        }
    }
}
    cout << "IMPOSSIBLE"<< "\n"; 
    return 0;
}

