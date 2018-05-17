#include <iostream>
#include <string>

using namespace std;

struct node {
	int val;
	short height = 1;
	node* left;
	node* right;
	node* parent;
	node() = default;
};

class tree {
private:
	node* root = nullptr;
	size_t size = 0;
protected:
	void insert(node* n, int& v);
	void print(node* r);
	node* search(node* r, int& v);
	node* min(node* r);
	node* max(node* r);
	void fixheight(node* p);
	int bfactor(node* p);
	node* rotateright(node* p);
	node* rotateleft(node* q);
	node* balance(node* p);
	short height(node* p);
	node* balancemin(node* p);
	node* erase(node* p, int& k);
public:
	int &operator[](int j);
	size_t Size() { return this->size; }
	void Insert(int v);
	void print_tree();
	void Erase(int n);
	node* search_by_val(int v);
	node* Min();
	node* Max();
	node* Begin();
	node* End();
	node* next(node* a);
	node* prev(node* a);
	void clear();
	~tree() = default;
};

node* tree::prev(node* a) {
	if (!a) {
		return nullptr;
	}
	if (a->left != nullptr) {
		return max(a->left);
	}
	while (a->parent != nullptr && a->parent->left == a) {
		a = a->parent;
	}
	a = a->parent;
	return a;
}

node* tree::next(node* a) {
	if (!a) {
		return nullptr;
	}
	if (a->right != nullptr) {
		return min(a->right);
	}
	while (a->parent != nullptr && a->parent->right == a) {
		a = a->parent;
	}
	a = a->parent;
	return a;
}

node* tree::erase(node* p, int& k)
{
	if (!p) {
		return nullptr;
	}
	if (k < p->val) {
		p->left = erase(p->left, k);
	}
	else if (k > p->val) {
		p->right = erase(p->right, k);
	}
	else
	{
		bool is_root = false;
		if (p == root) {
			is_root = true;
		}
		size--;
		node* par = p->parent;
		node* l = p->left;
		node* r = p->right;
		delete p;
		if (!r) {
			return l;
		}
		if (!l) {
			return r;
		}
		node* m = min(r);
		m->right = balancemin(r);
		m->left = l;
		m->parent = par;
		if (m->left) {
			m->left->parent = m;
		}
		if (m->right) {
			m->right->parent = m;
		}
		if (is_root) {
			root = m;
		}
		return balance(m);
	}
	return balance(p);
}

int & tree::operator[](int j)
{
	if (j >= size) {
		cout << "no such element" << endl;
		throw ;
	}
	node* t = Begin();
	for (int i = 0; i < j; i++) {
		t = next(t);
	}
	return t->val;
}

node* tree::balancemin(node* p)
{
	if (p->left == 0) {
		return p->right;
	}
	p->left = balancemin(p->left);
	return balance(p);
}

short tree::height(node* p)
{
	return p ? p->height : 0;
}

node* tree::balance(node* p)
{
	fixheight(p);
	if (bfactor(p) == 2) {
		if (bfactor(p->right) < 0) {
			p->right = rotateright(p->right);
		}
		return rotateleft(p);
	}
	if (bfactor(p) == -2) {
		if (bfactor(p->left) > 0) {
			p->left = rotateleft(p->left);
		}
		return rotateright(p);
	}
	return p;
}

node* tree::rotateleft(node* q)
{
	node* p = q->right;
	if (!q->parent) {
		root = p;
	}
	q->right = p->left;
	if (q->right) 
		q->right->parent = q;
	p->left = q;
	p->parent = q->parent;
	q->parent = p;
	if (p->parent)
		p->parent->right = p;
	fixheight(q);
	fixheight(p);
	return p;
}

node* tree::rotateright(node* p)
{
	node* q = p->left;
	if (!p->parent) {
		root = q;
	}
	p->left = q->right;
	if (p->left)
		p->left->parent = p;
	q->right = p;
	q->parent = p->parent;
	p->parent = q;
	if (q->parent)
		q->parent->left = q;
	fixheight(p);
	fixheight(q);
	return q;
}

void tree::fixheight(node* p)
{
	short hl = height(p->left);
	short hr = height(p->right);
	p->height = (hl > hr ? hl : hr) + 1;
}

int tree::bfactor(node* p)
{
	return height(p->right) - height(p->left);
}

node* tree::min(node * ptr)
{
	if (!ptr) {
		return nullptr;
	}
	while (ptr->left != nullptr) {
		ptr = ptr->left;
	}
	return ptr;
}

node* tree::max(node* ptr) {
	if (!ptr) {
		return nullptr;
	}
	while (ptr->right != nullptr) {
		ptr = ptr->right;
	}
	return ptr;
}

void tree::insert(node * r, int& v) {
	if (!r) {
		node* t = new node();
		t->val = v;
		size++;
		root = t;
		return;
	}
	if (v < r->val && r->left) {
		insert(r->left, v);
	}
	if (v >= r->val && r->right) {
		insert(r->right, v);
	}
	if (v < r->val && !r->left) {
		node* t = new node();
		t->val = v;
		size++;
		t->parent = r;
		r->left = t;
	}
	if (v >= r->val && !r->right) {
		node* t = new node();
		t->val = v;
		size++;
		t->parent = r;
		r->right = t;
	} 
	balance(r);
}

void tree::print(node * r)
{
	if (!r) {
		return;
	}
	if (r->left) {
		print(r->left);
	}
	cout << r->val << " ";
	if (r->right) {
		print(r->right);
	}
}

node * tree::search(node * r, int& v)
{
	if (!r) {
		cout << "not found" << endl;
		return nullptr;
	}
	if (r->val == v) {
		return r;
	}
	if (r->val < v) {
		return search(r->right, v);
	}
	if (r->val > v) {
		return search(r->left, v);
	}
}

void tree::Insert(int v) {
	insert(root, v);
}

void tree::print_tree()
{
	if (!root) {
		cout << "is empty" << endl;
		return;
	}
	if (root->left) {
		print(root->left);
	}
	cout << root->val << " ";
	if (root->right) {
		print(root->right);
	}
	cout << endl;
}

void tree::Erase(int v) {
	erase(root, v);
}

node * tree::search_by_val(int v)
{
	return search(root, v);
}

node * tree::Min()
{
	node* ptr = root;
	if (!ptr) {
		return nullptr;
	}
	while (ptr->left != nullptr) {
		ptr = ptr->left;
	}
	return ptr;
}

node * tree::Max()
{
	node* ptr = root;
	if (!ptr) {
		return nullptr;
	}
	while (ptr->right != nullptr) {
		ptr = ptr->right;
	}
	return ptr;
}

node * tree::Begin()
{
	return min(root);
}

node * tree::End()
{
	return max(root);
}

void tree::clear()
{
	delete this->root;
	this->root = nullptr;
}
