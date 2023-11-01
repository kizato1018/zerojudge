#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int id = 0;
    int parent = 0;
    int height = 0;
    vector<int> children;
};

// struct Node{
//     int id = 0;
//     Node* parent = nullptr;
//     int height = 0;
//     vector<Node*> children;
// };

int SetHeight(int root, Node *nodes) {
    for(int i = 0; i < nodes[root].children.size(); i++) {
        nodes[root].height = max(SetHeight(nodes[root].children[i], nodes), nodes[root].height);
    }
    // printf("current: %d, height: %d \n", root, nodes[root].height);
    return nodes[root].height + 1;
}

// int SetHeight(Node* root) {
//     // if(root == nullptr) return 0;
//     for(int i = 0; i < root->children.size(); i++) {
//         root->height = max(SetHeight(root->children[i]), root->height);
//     }
//     // printf("current: %d, height: %d \n", root->id, root->height);
//     return (root->height) + 1;
// }


int main() {
    int n;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while(cin >> n) { 
        Node nodes[100010] = {0};
        for(int i = 1; i <= n; i++) {
            int m;
            cin >> m;
            for(int j = 0; j < m; j++) {
                int c;
                cin >> c;
                nodes[i].children.push_back(c);
                nodes[c].parent = i;
            }
        }
        // for(int i = 1; i <= n; i++) {
        //     if(nodes[i].parent != 0) {
        //         printf("%d's parent is %d\n", i, nodes[i].parent);
        //     }
        //     else {
        //         printf("%d is root\n", i);
        //     }
        // }
        // for(int i = 1; i <= n; i++) {
        //     if(nodes[i] == nullptr) {
        //         printf("%d is null\n", i);
        //     }
        //     else {
        //         if(nodes[i]->parent) {
        //             printf("%d's parent is %d\n", i, nodes[i]->parent->id);
        //         }
        //         else {
        //             printf("%d is root\n", i);
        //         }
        //     }
        // }
        int root = 1;

        while(nodes[root].parent != 0) root = nodes[root].parent;

        // printf("%d is root\n", root->id);
        // 
        // for(int i = 1; i <= n; i++) {
        //     printf("%d's height is %d\n", i, nodes[i]->height);
        // }

        SetHeight(root, nodes);
        // for(int i = 1; i <= n; i++) {
        //     printf("%d's height is %d\n", i, nodes[i].height);
        // }

        int rid = root;
        long long total_height = 0;
        for(int i = 1; i <= n; i++) {
            total_height += nodes[i].height;
        }
        cout << rid << endl;
        cout << total_height << endl;
    }

    // while(cin >> n) {
    //     Node* nodes[100010] = {0};
    //     for(int i = 1; i <= n; i++) {
    //         int m;
    //         cin >> m;
    //         if(nodes[i] == nullptr) nodes[i] = new Node();
    //         nodes[i]->id = i;
    //         for(int j = 0; j < m; j++) {
    //             int c;
    //             cin >> c;
    //             if(nodes[c] == nullptr) nodes[c] = new Node();
    //             nodes[i]->children.push_back(nodes[c]);
    //             nodes[c]->parent = nodes[i];
    //         }
    //     }
    //     Node* root = nodes[1];
    //     while(root->parent) root = root->parent;
    //     SetHeight(root);
    //     int rid = root->id;
    //     long long total_height = 0;
    //     for(int i = 1; i <= n; i++) {
    //         total_height += nodes[i]->height;
    //         delete nodes[i];
    //     }
    //     cout << rid << endl;
    //     cout << total_height << endl;
    // }
}