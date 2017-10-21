# include <iostream>

using namespace std;


class node{
public:
	int info;
	node *l, *r;
};

node *tree = NULL; 


void push(int data, node **t){
	if ((*t) == NULL){
		(*t) = new node; 
		(*t)->info = data; 
		(*t)->l = (*t)->r = NULL; 
		return; 
	}
	
	if (data>(*t)->info) push(data, &(*t)->r); 
	else push(data, &(*t)->l); 
}


void print(node *t, int u){
	if (t == NULL) return; 
	else {
		print(t->l, ++u);
		for (int i = 0; i<u; ++i) cout << "____";
		cout << t->info << endl; 
		u--;
	}
	print(t->r, ++u);
}

int main(){
	int n,s;
	cin >> n;

	for (int i = 0; i < n; ++i){
		cout << "Enter the number  ";
		cin >> s; 

		push(s, &tree);
	}
	print(tree, 0);
	system("pause");
	return 0;
}