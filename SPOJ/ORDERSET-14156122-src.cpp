#include <bits/stdc++.h>

using namespace std;


struct Node {
	int key, priority, size;
	Node* left, *right;
	Node(int k, int p) :
			key(k), priority(p), left(NULL), right(NULL), size(1) {
	}
	Node(int k) :
			key(k), left(NULL), right(NULL), priority(rand()), size(1) {
	}
};
inline int sz(Node *root) {
	if (root == NULL)
		return 0;
	return root->size;
}
inline void upd(Node *root) {
	if (root != NULL) {
		root->size = 1 + sz(root->left) + sz(root->right);
	}
	return ;
}
Node* search(Node *root, int key) {
	if (root == NULL)
		return NULL;
	if (key < root->key)
		return search(root->left, key);
	if (key > root->key)
		return search(root->right, key);
	return root;
}
Node* rotRight(Node *root) {
	Node* pivot = root->left;
	root->left = pivot->right;
	pivot->right = root;
	upd(root->right),upd(root);
	return pivot;
}

Node* rotLeft(Node *root) {
	Node* pivot = root->right;
	root->right = pivot->left;
	pivot->left = root;
	upd(root->left),upd(root);
	return pivot;
}
Node* insert(Node *root, Node *novo) {
	if (root == NULL)
		return novo;
	if (root->key < novo->key) {
		root->right = insert(root->right, novo);
		if (root->right->priority > root->priority)
			root = rotLeft(root);
	} else {
		root->left = insert(root->left, novo);
		if (root->left->priority > root->priority)
			root = rotRight(root);
	}
	upd(root);
	return root;
}

Node* erase(Node* root, int key) {
	if (root == NULL) {
		return root;
	}
	if (root->key < key)
		root->right = erase(root->right, key);
	else if (root->key > key)
		root->left = erase(root->left, key);
	else {
		if (root->left != NULL) {
			if (root->right != NULL) {
				if (root->left->priority < root->right->priority) {
					root = rotLeft(root);
					root->left = erase(root->left, key);
				} else {
					root = rotRight(root);
					root->right = erase(root->right, key);
				}
			} else {
				Node* aux = root->left;
				delete root;
				return aux;
			}
		} else {
			if (root->right != NULL) {
				Node* aux = root->right;
				delete root;
				return aux;
			} else {
				delete root;
				return NULL;
			}
		}
	}
	upd(root);
	return root;
}
Node * Find_kth_Node(Node *root, int k) {
	if (sz(root) < k)
		return NULL;
	int ans = 1 + sz(root->left);
	if (ans == k)
		return root;
	if (ans < k)
		return Find_kth_Node(root->right, k - ans);
	return Find_kth_Node(root->left, k);
}
int count_less(Node *root, int k) {
	if (root == NULL)
		return 0;
	if(root->key<k){
		return 1+sz(root->left)+ count_less(root->right,k);
	}
	return count_less(root->left,k);
}
Node* clear(Node* root) {
	if (root != NULL) {
		clear(root->left);
		clear(root->right);
		delete root;
	}
}

void Traverse(Node *root, int level) {
	if (root == NULL)
		return;
	printf("[%d = > %d,%d,%d]->\n", level, root->key, root->priority,
			root->size);
	Traverse(root->left, level + 1);
	Traverse(root->right, level + 1);
}
int c;
char op[2];
int main() {

	char ch;
	int val;
	scanf("%d",&c);
	Node *treap = NULL;
	while(c--){
		scanf(" %s %d", op, &val);
		if (op[0] == 'I') {
			Node * aux = search(treap, val);
			if (aux == NULL) {
				treap = insert(treap, new Node(val));
			}
		} else if (op[0] == 'D') {
			Node * aux = search(treap, val);
			if (aux != NULL) {
				treap = erase(treap, val);
			}
		} else if (op[0] == 'C') {
			int cnt = count_less(treap, val);
			cout << cnt << '\n';
		} else if (op[0] == 'K') {
			Node *aux = Find_kth_Node(treap, val);
			if (aux != NULL) {
				cout << aux->key << '\n';
			} else {
				puts("invalid");
			}
		}
	}
	clear(treap);

	return 0;
}
