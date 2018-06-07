// Someone else's code can't work throufh it though 
// Shadowing issue
// #include <iostream>
// #include <vector>

// using namespace std;

// // Node is defined as :
// typedef struct node
// {
//     int val;
//     struct node* left;
//     struct node* right;
//     int ht;
// } node;

// int setHeight(node* root){

//     int height = -1;

//     if(!root){
//         height = -1;
//     }

//     else if((!root->left)&&(!root->right)){
//         height = 0;
//         root->ht = height;
//     }
//     else{
//         height = max(setHeight(root->left),setHeight(root->right)) + 1;
//         root->ht = height;
//     }
//     return height;
// }

// int getBalanceFactor(node * root){
//     int lht,rht;

//     if(!root->left)
//         lht = -1;
//     else
//         lht = root->left->ht;
//     if(!root->right)
//         rht = -1;
//     else
//         rht = root->right->ht;
//     return (lht - rht);
// }

// node * leftRightFun(node* root){
//     node* tmp = root->left;
//     root->left = tmp->right;

//     tmp->right = tmp->right->left;
//     root->left->left = tmp;
//     root->left->ht = setHeight(root->left);
//     root->left->left->ht = setHeight(root->left->left);

//     return root;
// }

// node * leftLeftFun(node * root){
//     node *tmp = root->left;
//     root->left = tmp->right;
//     tmp->right = root;

//     root->ht = setHeight(root);

//     return tmp;
// }

// node * rightLeftFun(node * root){
//     node * tmp = root->right;
//     root->right = tmp->left;
//     tmp->left = tmp->left->right;
//     root->right->right = tmp;

//     root->right->ht = setHeight(root->right);
//     root->right->right->ht = setHeight(root->right->right);

//     return root;
// }

// node * rightRightFun(node * root){
//     node * tmp = root->right;
//     root->right = tmp->left;
//     tmp->left = root;

//     root->ht = setHeight(root);

//     return tmp;
// }

// node * BalanceInsertT(node * root){
//     node * curr = root;
//     int bf = getBalanceFactor(curr);

//     if(bf == -2){
//         int tmpBF = getBalanceFactor(curr->right);
//         if(tmpBF == 1)
//         {
//             curr = rightLeftFun(curr);
//             root = rightRightFun(curr);
//         }
//         else if (tmpBF == -1 || tmpBF == 0)
//             root = rightRightFun(curr);
//         else
//             curr->right = BalanceInsertT(curr->right);
//     }
//     else if(bf == 2){
//         int tmpBF = getBalanceFactor(curr->left);
//         if(tmpBF == -1)
//         {
//             curr = leftRightFun(curr);
//             root = leftLeftFun(curr);
//         }
//         else if (tmpBF == 1 || tmpBF == 0)
//             root = leftLeftFun(curr);
//         else
//             curr->left = BalanceInsertT(curr->left);
//     }

//     return root;

// }


// node * insert(node * root,int val)
// {
//     //Creat the node
//     node* pNode = new node();
//     pNode->val = val;
//     pNode->left = NULL;
//     pNode->right = NULL;
//     pNode->ht = 0;

//     if(!root)
//         return pNode;

//     node * curr = root;

//     //Insert the new aded node
//     while(curr){
//         if(curr->val > val){
//             if(curr->left == NULL){
//                 curr->left = pNode;
//                 break;
//             }
//             else
//                 curr = curr->left;
//         }
//         else{
//             if(curr->right == NULL){
//                 curr->right = pNode;
//                 break;
//             }
//             else
//                 curr = curr->right;
//         }
//     }
//     node* temp = root;
//     setHeight(temp);

//     //Balance the tree
//     root = BalanceInsertT(root);
//     setHeight(root);
//     return root;
// }

// node * creatNode(int val){
//     node * pNode = new node();
//     pNode->val = val;
//     pNode->ht = 0;
//     pNode->left = NULL;
//     pNode->right = NULL;
//     return pNode;
// }
// node * insertNode(node* root, node* tmp){

//     node * curr = root;
//     while(curr){
//         if((tmp->val < curr->val ) && (curr->left == NULL))
//             curr->left = tmp;
//         else if((tmp->val < curr->val) &&(curr->left != NULL))
//             curr = curr->left;
//         else if((tmp->val > curr->val) && (curr->right == NULL))
//             curr->right = tmp;
//         else
//             curr = curr->right;
//     }
//     setHeight(root);
//     return root;

// }


// int main(int argc, char *argv[])
// {
//     //vector<int> vec = {14, 25, 21, 10, 23, 7, 26, 12, 30, 16};
//     //vector<int> vec = {3, 2, 4, 5};
//     //vector<int> vec = {5,3};
//     vector<int> vec = {17, 6, 10, 18, 22, 16};
//     //Creat a tree;
//     int i = 0;
//     node * root = NULL;
//     while(i < vec.size()){

//         node * tmp = creatNode(vec[i]);
//         if(!root)
//             root = tmp;
//         else
//             insertNode(root,tmp);
//         i++;
//     }

//     root = insert(root,21);

//     return 0;
// }
// /* Node is defined as :
// typedef struct node
// {
//     int val;
//     struct node* left;
//     struct node* right;
//     int ht;
// } node; */
// #define COUNT 10
// void print(node *root, int space=0)
// {
//     if (root == NULL)
//         return;
//     space += COUNT;
//     print(root->right, space);
//     printf("\n");
//     for (int i = COUNT; i < space; i++)
//         printf(" ");
//     printf("(%d, %d)\n", root->val, root->ht);
//     print(root->left, space);
// }

 int height(node* root) 
{
       if(root == nullptr)
            return -1;
       return max(height(root->left),height(root->right))+1;
}


node* newnode(int key){
    node* root = new node;
    root->val   = key;
    root->left   = nullptr;
    root->right  = nullptr;
    root->ht = 0;
    return root;
}

node *rightRotate(node *y) {
    node * x  = y -> left;
    node * T2 = x -> right;
    
    x -> right = y;
    y -> left = T2;
    
//     Update heights
    y->ht = max(height(y->left), height(y->right))+1;
    x->ht = max(height(x->left), height(x->right))+1;
    return x;
}

node * leftRotate(node *x) {
    node * y  = x -> right;
    node * T2 = y -> left;
    
    y -> left  = x;
    x -> right = T2;
    
//     Update heights
    y->ht = max(height(y->left), height(y->right))+1;
    x->ht = max(height(x->left), height(x->right))+1;
    return y;
}

int getBalance(node * N) {
    if (N == nullptr)
        return 0;
    return height(N->left) - height(N->right);
}

node * insert(node * root, int val){
    if(root == nullptr) {
        return(newnode(val));
    }
    if(root->val > val) {
        root->left = insert(root->left, val);
    } else if (root->val < val) {
        root->right = insert(root->right, val);
    } else {
        return root;;
    }
    root->ht = height(root);
    int balance = getBalance(root);
//     left left
    if (balance > 1 && val < root->left->val)
        return rightRotate(root);
//     right right
    if (balance < -1 && val > root->right->val)
        return leftRotate(root);
//     left right
    if (balance > 1 && val > root->left->val) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
//     right left
    if (balance < -1 && val < root->right->val) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
//     if unchanged
    return root;
}

// my foolish attempt :'(
// int maxHeight(node * root, int index = 0) {
//     if(root) {
//         // cout<<"IN MAX -> "<<root->val<<endl;
//         if(!root->left && !root->right)
//             return index;
//         else {
//             index++;
//             return max(maxHeight(root -> left, index), maxHeight(root -> right, index));
//         }
//     }
//     return 0;
// }

// void redoHeights(node * root) {
//     if(root) {
//         root -> ht = maxHeight(root);
//         redoHeights(root->left);
//         redoHeights(root->right);
//     }
// }

// node * insert(node * root, int val){
//     // print(root);
//     if(root == nullptr) {
//         root = new (nothrow) (node);
//         root->val = val;
//         root->ht = 0;
//         return root;
//     }
//     string path = "";
//     node * temp = root, *temp2 = root;
//     while(true) {
//         if(temp->val > val) {
//             path += '0';
//             if(temp->left) {
//                 cout<<"Gone left";
//                 temp = temp->left;
//             } else {
//                 cout<<"Inserted at left";
//                 temp->left = new (nothrow) (node);
//                 temp->left->val = val;
//                 temp->left->ht = 0;
//                 break;
//             }
//         } else {
//             path += '1';
//             if(temp -> right) {
//                 // cout<<"Gone right";
//                 temp = temp->right;
//             } else {
//                 // cout<<"Inserted right";
//                 temp->right = new (nothrow) (node);
//                 temp->right->val = val;
//                 temp->right->ht = 0;
//                 break;
//             }
//         }
//     }
//     // cout<<"\n=========";
//     print(root);
//     temp = root;
//     for(int i = 0; i < (int)path.length(); i++) {
//         temp->ht = maxHeight(temp);
//         if(path[i] == '0') {
//             temp = temp -> left;
//         } else {
//             temp = temp->right;
//         }
//     }
//     temp = root;
//     cout<<"\nEntire path -> "<<path<<" pathlen -> "<<path.length()<<endl;
//     for(int i = 0; i < (int)path.length() - 2; i++) {
//         cout<<"Pathlen - 2 "<<(int)path.length() - 2<<endl;
//         cout<<"path["<<i<<"] -> "<<path[i]<<endl;
//         if(path[i] == '0') {
//             temp = temp -> left;
//             if(i < path.length() - 3)
//                 temp2 = temp2 -> left;
//         }
//         else {
//             temp = temp->right;
//             if(i < path.length() - 3)
//                 temp2 = temp2->right;
//         }
//     }
//     redoHeights(root);
//     // cout<<"temp -> "<<temp->val<<" temp2 -> "<<temp2->val<<endl;
//     // cout<<"left height-> "<<maxHeight(temp->left)<<" right height -> "<<maxHeight(temp->right)<<endl;
//     int diff = maxHeight(temp2->left) - maxHeight(temp2->right);
//     cout<<"diff -> "<<diff<<endl;
//     if(abs(maxHeight(temp2->left) - maxHeight(temp2->right)) > 1) {
//         if(diff > 0) {
//             if(temp->left->right) { // 5 3 4 case
//                 temp -> left -> right -> left = temp -> left;
//                 temp -> left = temp -> left -> right;
//                 temp -> left -> left -> right = nullptr;
//             }
//             // 5 4 3 case
//             temp -> left -> right = temp;
//             temp = temp -> left;
//             temp -> right -> left = nullptr;
//         } else {
//             if(temp->right->left) { // 3 5 4 case
//                 temp -> right -> left -> right = temp -> right;
//                 temp -> right = temp -> right -> left;
//                 temp -> right -> right -> left = nullptr;
//             }
//             // 3 4 5 case
//             temp -> right -> left = temp;
//             temp = temp -> right;
//             temp -> left -> right = nullptr;
//         }
//         if(path[path.length() - 3] == '0')
//             temp2 -> left = temp;
//         else
//             temp2 -> right = temp;
//     }
//     print(root);
//     return root;
// }
