#include <bits/stdc++.h>

int main() {
    char c;
    bool f = true;
    while((c=getchar())!=EOF) {
        if(c == '"') {
            if(f) printf("``");
            else printf("''");
            f = !f;
        }
        else
            putchar(c);
    }
    return 0;
}