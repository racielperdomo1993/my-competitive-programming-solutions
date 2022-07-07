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
    //if(root->key==novo->key) return root;
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
int count_high(Node *root, int k) {
	if (root == NULL)
		return 0;
	if(root->key>k){
		return 1+sz(root->right)+ count_high(root->left,k);
	}
	return count_high(root->right,k);
}
Node* clear(Node* root) {
	if (root != NULL) {
		clear(root->left);
		clear(root->right);
		delete root;
	}
}

//buscar mayores iguales que val
int get(Node * v, int val)
{
    if (!v) return 0;
    if (val == v->key) return 1 + sz(v->right);
    if (val < v->key)
        return sz(v->right) + 1 + get(v->left, val);
    else
        return get(v->right, val);
}

Node * BIT[1000004];
int s;

int get(int r, int val)
{
    int res = 0;
    for(; r >= 0; r = (r & (r + 1)) - 1)
        res += get(BIT[r], val);
    return res;
}

void add(int pos, int val)
{
    for(; pos < s; pos |= pos + 1)
    {
        Node * add = new Node(val);
        BIT[pos] = insert(BIT[pos], add);
    }
}


int c;
char op[2];
int l[1000000];
int r[1000000];
int operacion[1000000];
int z[1000000];

int main() {

	char ch;
	int val,val2;
	scanf("%d",&c);
	Node *treap = NULL;

	for(int i = 0; i < c; i++){
	    scanf("%s %d %d", op, &val,&val2);
	    operacion[i] = (op[0] == '+')?0:1;
	    l[i] = val;
	    r[i] = val2;
	}

	memcpy(z, l, sizeof(l));
    sort(z, z + c);
    s = unique(z, z + c) - z;
    for(int i = 0; i < c; i++)
    {
        BIT[i] = NULL;
    }
    for(int i = 0; i < c; ++i)
    {
        l[i] = lower_bound(z, z + s, l[i]) - z;
        if (operacion[i])
            printf("%d\n", get(l[i], r[i]));
        else
            add(l[i], r[i]);
    }

	//clear(treap);
	return 0;
}
