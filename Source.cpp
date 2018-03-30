#include <iostream>
#include <string>
#include "tree.h"

using namespace std;

int main() {
	tree tr;
	string s;
	int n, k;
	cin >> n;
	/*for (int i = 0; i < n; i++) {
		cin >> s;
		if (s[0] == 'i') {
			cin >> k;
			tr.Insert(k);
		}
		if (s[0] == 'p') {
			tr.print_tree();
		}
		if (s[0] == 'c') {
			tr.clear();
		}
		if (s[0] == 's') {
			cin >> k;
			tr.search_by_val(k);
		}
		if (s[0] == 'e') {
			cin >> k;
			tr.Erase(k);
		}
		if (s == "min") {
			cout << tr.Min()->val << endl;
		}
		if (s == "max") {
			cout << tr.Max()->val << endl;
		}
	}*/
	for (int i = 0; i < n; i++) {
		tr.Insert(i);
	}
	for (int i = 0; i < tr.Size(); i++) {
		++tr[i];
		tr.print_tree();
	}
	cout << endl;
	for (node* i = tr.Begin(); i != tr.End(); i = tr.next(i)) {
		++i->val;
	}
	tr.print_tree();
	return 0;
}