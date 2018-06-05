/*
Node is defined as 

typedef struct node
{
	int data;
	node *left;
	node *right;
}node;

*/
// 1st attempt passed all cases 
// Fuckk didn't see it was a bst
// wtf this is a general solution....
// bool doCheck(node *root, int v1, int v2, bool bul = false) {
//     if(root) {
//         static bool bo_ol1 = false, bo_ol2 = false;
//         if(!bul) {
//             bo_ol1 = false;
//             bo_ol2 = false;
//             bul = true;
//         }
//         if(root -> data == v1) {
//             bo_ol1 = true;
//         }
//         else if(root -> data == v2) {
//             bo_ol2 = true;
//         }
//         if(bo_ol1 && bo_ol2) {
//             return true;
//         }
//         else {
//             return doCheck(root->left, v1, v2, bul) || doCheck(root->right, v1, v2, bul);
//         }
//     }
//     return false;
// }
// node *lca(node *root, int v1,int v2){
//     while(root) {
//         bool rut = doCheck(root, v1, v2), left = doCheck(root -> left, v1, v2), right = doCheck(root -> right, v1, v2);
//         if(rut && !left && !right) {
//             return root;
//         }
//         else {
//             if(left)
//                 root = root -> left;
//             else
//                 root = root -> right;
//         }
//     }
//     return root;
// }

// A very simple solution based on bst :'-(
// still it hurts how easy it was....
node *lca(node *root, int v1, int v2){ 
    while(root) {
        if(root->data > v1 && root->data > v2)
            root = root->left;
        else if(root->data < v1 && root->data < v2)
            root = root->right;
        else
            return root;
    }
    return root; // dunno just had to do it due to warning of no return
}
