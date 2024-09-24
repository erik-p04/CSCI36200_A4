#include <iostream>

struct Node {
	int data;
	Node* left;
	Node* right;
	Node(int value){
		data = value;
		left = nullptr;
		right = nullptr;
	}
};

//build a balenced tree by using the middle as the root
Node* buildBST(int arr[], int start, int end){
	if (start > end){
		return nullptr;//base case
	}
	int middle = (start + end) / 2; 
	Node* root = new Node(arr[middle]); //set root as middle
	root->left = buildBST(arr, start, middle - 1); //build left subtree
	root->right = buildBST(arr, middle + 1, end); //build right subtree
	return root;
}

//finding the kth smallest integer
void findK(Node* root, int& k, int& ans){
	if(root == nullptr || k == 0){
		return;//base case
	}
	findK(root->left, k, ans);
	k--;
	if(k==0){//kth smallest found
		ans = root->data;
		return;
	}
	findK(root->right, k, ans);
}

//print the BST in pre-order
void printBST(Node* node){
	if(node == NULL){
		return;//base case
	}
	std::cout << node->data << " ";
	printBST(node->left);
	printBST(node->right);
}

//delete BST to free memory
void deleteBST(Node* root){
	if(root == nullptr){
		return;//base base
	}
	deleteBST(root->left);
	deleteBST(root->right);
	delete root;
}

void showTree(Node* root, int s = 0, int height = 5){
	if (root == nullptr){
		return;//base case
	}
	s += height;
	showTree(root->right, s);
	std::cout << std::endl;
	for(int i=height; i<s; i++){
		std::cout << " ";
	}
	std::cout << root->data << std::endl;
	showTree(root->left, s);
}

int main(){
	int arr[] = {6, 17, 20, 41, 45, 52, 57, 65, 71, 76, 79, 87, 92, 95, 99};
	int n = 15;
	Node* root = buildBST(arr, 0, n-1);
	int k;
	bool keepGoing = true;
	while(keepGoing){
		std::cout << "Enter value of k(1-15): " << std::endl;
		std::cin >> k;
		if(k >= 1 && k<=15){
			keepGoing = false;
		}
	}
	int tK = k;
	int ans = 0;
	findK(root, k, ans);
	std::cout << "The " << tK << "th smallest integer is: " << ans << std::endl;
	std::cout << "Pre-order traversal: ";
	printBST(root);
	std::cout << std::endl;
	showTree(root);
	deleteBST(root);
	return 0;
}
