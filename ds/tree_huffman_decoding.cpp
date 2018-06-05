/* 
The structure of the node is

typedef struct node
{
    int freq;
    char data;
    node * left;
    node * right;
    
}node;

*/


void decode_huff(node * root, string s) {
    int i = 0;
    string ans = "";
    node * temp;
    while(i < s.length()) {
        temp = root;
        while(temp -> left || temp -> right) {
            if(s[i++] == '0') {
                temp = temp -> left;
            } else {
                temp = temp -> right;
            }
        }
        ans += temp -> data;
    }
    cout<<ans;
}
