#include <bits/stdc++.h>
using namespace std;
// int ans=0;
// bool cmp (int a, int b){
//     if (a<b){
//         ans++;
//     }
//     return a<b;
// }
int main (){
    // int n=0;
    // while (cin>>n){
    //     ans=0;
    //     int s[n];
    //     for (int i=0;i<n;i++){
    //         cin>>s[i];
    //     }
    //     sort(s,s+n, cmp);
    //     cout<<"Minimum exchange operations : "<<ans<<endl;
    // }
    // vector<int> v;
    // v.push_back(1);
    // v.push_back(2);
    // v.push_back(3);
    // v.push_back(4);
    // v.push_back(5);
    // v.erase(v.begin() + 3);
    // for(auto i : v)
    //     printf("%d ", i);
    // puts("");
    multiset<int> s;
    s.insert(3);
    s.insert(2);
    s.insert(1);
    s.insert(3);
    s.insert(5);
    multiset<int>::iterator is = s.begin();
    for(int i = 0; i < s.size(); i++) {
        cout << *is << " ";
        is++;
    }
    cout << endl;

    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(3);
    pq.push(2);
    pq.push(1);
    pq.push(3);
    pq.push(5);
    int len = pq.size();
    for(int i = 0; i < len; i++) {
        cout << pq.top() << " ";
        pq.pop();
    }
}