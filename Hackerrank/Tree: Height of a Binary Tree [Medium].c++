
/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
    int height(Node* root) {
        // Write your code here.
        return heightHelper(root, 0)-1;
    }

    int heightHelper(Node* node, int counter){
        if(!node) return counter;
        counter++;
        int left = heightHelper(node->left, counter);
        int right = heightHelper(node->right, counter);
        return max(left, right);
    }   

