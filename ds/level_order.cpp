int height(node* root) {
    if(root)
        return 1 + max(height(root->left), height(root->right));
    else
        return -1;
}

void printStuff(node * root, int height, int h) {
    if(root) {
        if(h == height) {
            cout<<root->data<<" ";
            return;
        }
        printStuff(root->left, height, h+1);
        printStuff(root->right, height, h+1);
    }
}

void levelOrder(node * root) {
    int hei = height(root);
    for(int i = 0; i <= hei; i++) {
        printStuff(root, i, 0);
    }
}
