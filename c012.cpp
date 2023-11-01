#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

bool cmp(pair<char, int> a, pair<char, int> b) {
    if(a.second == b.second) {
        return a.first > b.first;
    }
    return a.second < b.second;
} 

// struct Person{
//     string name;
//     int age;
//     char gender;
// };

// typedef struct Person myperson; // typedef 型態 型態的別名

// bool student_cmp(myperson a, myperson b) {
//     if(a.gender == b.gender) {
//         return a.age < b.age;
//     }
//     return (a.gender == 'M' && b.gender == 'F');
// }

// void test() {
//     myperson students[100];
//     for(int i = 0; i < 100; i++) {
//         // 輸入
//     }
//     sort(students, students + 100, student_cmp);
// }

int main() {
    string s;
    while(getline(cin ,s)) {
        pair<char, int> ascii[256];
        for(int i = 0; i < 255; i++) {
            ascii[i].first = i;
            ascii[i].second = 0;
        }
        for(int i = 0; i < s.size(); i++) {
            ascii[s[i]].second++;
        }
        sort(ascii, ascii+255, cmp);
        for(int i = 0; i < 256; i++) {
            if(ascii[i].second > 0) {
                printf("%d %d\n", ascii[i].first, ascii[i].second);
            }
        }
        puts("");
    }

}

/*
char a
sizeof(a) 1byte = 8bits 0000 0000
1byte 數量 2^8 範圍 0~2^8-1 = 0~255

ascii[65].first == 65 == 'A'
ascii['A'].first == 65 == 'A'

*/
