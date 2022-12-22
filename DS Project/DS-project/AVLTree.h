#include<iostream>
#include<cstring>
#include<string>
#include <fstream>
using namespace std;


template<typename T> class AvlNode {

public:

	T data;


	AvlNode<T>* left;
	AvlNode<T>* right;
	AvlNode<T>() { left = right = NULL; }
	AvlNode<T>(AvlNode<T>* copy) { left = right = NULL; data = copy->data; }
	void Set(AvlNode<T>* copy) { data = copy->data; }

};


template<typename T> class AvlTree {


public:

	AvlNode<T>* root;
	AvlNode<T>* dele;

	int height;
	int lh = 0, rh = 0;
	int h = 0, a = 0;
	bool avail = 1;

	AvlTree() {

		root = dele = NULL;
		height = 0;

	}

	AvlNode<T>* getRoot()
	{
		return root;
	}

	string getKey(string key) {
		stringstream sor(key);
		string s;
		getline(sor, s, ',');
		return s;

	}
	int R_H() {
		h = 0, a = 0;
		Height(root);
		
		return 1;
	}

	int balanceFactor(AvlNode<T>* r) {

		if (!root)
			return -1;
		h = 0, a = 0;
		Height(r->left); lh = h;
		h = 0, a = 0;
		Height(r->right); rh = h;

		if (r->left) lh++;
		if (r->right) rh++;
	
		return (lh - rh);
	}

	void Height(AvlNode<T>* temp)
	{
		if (root == NULL || temp == NULL)
			return;

		if (temp->left != NULL)
		{
			
			a++;
			Height(temp->left);
		}

		
		if (temp->right)
		{
			
			a++;
			Height(temp->right);
		}

		if (h < a) {
			h = a;
		}
		a--;
		return;
	}

	void RR(AvlNode<T>** temp) {
		
		AvlNode<T>* ch;					
		ch = (*temp)->left;
		(*temp)->left = ch->right;
		ch->right = (*temp);
		(*temp) = ch;

	}

	void LL(AvlNode<T>** temp) {
	
		AvlNode<T>* ch;
		ch = (*temp)->right;
		(*temp)->right = ch->left;
		ch->left = (*temp);
		(*temp) = ch;


	}

	void Left(AvlNode<T>** temp) {
	
		LL(&((*temp)->left));
		RR(temp);

	}

	void Right(AvlNode<T>** temp) {

		RR(&((*temp)->right));
		LL(temp);


	}

	void Insert(AvlNode<T>* number, AvlNode<T>** temp)
	{
		if (number == NULL) return;
		if (root == NULL)
		{
			(root) = new AvlNode<T>;
			root = number;
			*temp = root;
			return;
		}

		else if ((*temp)->data == number->data)
		{
			return;
		}

		else if (getKey((*temp)->data ) > getKey(number->data) )
		{
			if ((*temp)->left != NULL)
			{
				Insert(number, &((*temp)->left));


				if (balanceFactor(*temp) == 2) {
					if (number->data < (*temp)->left->data) 
						RR(temp);
					else
						Left(temp);
				}

				return;
			}
			else
			{
				
				(*temp)->left = number;
				return;
			}
		}

		else if (getKey((*temp)->data) < getKey(number->data))
		{
			if ((*temp)->right != NULL)
			{
				Insert(number, &((*temp)->right));

				if (balanceFactor(*temp) == -2) {
					if (number->data > (*temp)->right->data) 
						LL(temp);
					else
						Right(temp);

				}
				return;
			}
			else
			{
			
				(*temp)->right = number;
				return;
			}
		}
	}

	void Show(AvlNode<T>* temp) {

		cout << "\ndata" << temp->data << endl;	
	}

	void display(AvlNode<T>* temp, int val = 0)  
	{
		if (temp == NULL || root == NULL)
			return;

		if (val <= 0)
			Show(temp);

		if (temp->left != NULL)
			display(temp->left, val);  

		if (val == 1)
			Show(temp);	

		if (temp->right != NULL)
			display(temp->right, val);

		if (val > 1)
			Show(temp);


	}
	ofstream myFile;
	void writeFile(AvlNode<T>* temp, int val = 0)  

	{

		if (temp == NULL || root == NULL)
			return;

		if (val <= 0)
			myFile << temp->data << "\n";	

		if (temp->left != NULL)
			writeFile(temp->left, val);   

		if (temp->right != NULL)
			writeFile(temp->right,  val);




	}
    void AvlFileRead(string fileName) {
		
		fstream file(fileName, ios::in);
		string line;
		string id;
		string rest;
		int count = 0;int c = 0;

		if (file.is_open())
		{

			while (getline(file, line)) {
				
				AvlNode<string>* an = new AvlNode<string>();
				an->data = line;
				this->Insert(an, &this->root);
				
			}
		}
		file.close();

	}


	AvlNode<T>* retrieve(T d)
	{
	}


	AvlNode<T>* minimum(AvlNode<T>* min)
	{
		if (min)
			while (min->left)
				min = min->left;
		return min;
	}

	void Bal(AvlNode<T>** temp, T number) {

		if (!(*temp)) return;

		if (balanceFactor(*temp) == 2) { 
			if (number > (*temp)->left->data) 
				RR(temp);
			else
				Left(temp);
		}
		else
			if (balanceFactor(*temp) == -2) {
				if (number < (*temp)->right->data) 
					LL(temp);
				else
					Right(temp);

			}
	}





	AvlNode<T>* Delete(AvlNode<T>** temp, T n) {
		if (*temp == NULL)
			return *temp;
		if (n > (*temp)->data)
		{
			
			Delete(&((*temp)->right), n);	
			Bal(&((*temp)), n);
		}
		else if ((*temp)->data > n)
		{
			
			Delete(&((*temp)->left), n);	
			Bal(&((*temp)), n);
		}
		else {
			if ((*temp)->left == NULL && (*temp)->right == NULL) {
			
				dele = *temp;
				*temp = NULL;
				

			}
			else if ((*temp)->left == NULL) {
				
				if (!dele)
					dele = *temp;
				*temp = (*temp)->right;
				
			}
			else if ((*temp)->right == NULL) {
			
				if (!dele)
					dele = *temp;
				*temp = (*temp)->left;


			}
			else { 
				if (!dele)
					dele = new AvlNode<T>(*temp);
				AvlNode<T>* temp1 = minimum((*temp)->right);
				(*temp)->Set(temp1);

				Delete(&((*temp)->right), temp1->data);
			}
		}
		return *temp;
	}

	bool findString(string a, string b, bool id = false) {
		stringstream sor(a);

		string s;
		while (getline(sor, s, ',')) {
			// cout << s;
			if (s.compare(b) == 0)
				return true;
			if (id) return false;
			s = "";
		}

		return false;
	}
	string updateString(string org, string field, string old, string newVal) {
	
		stringstream sor(org);

		string s;
		string lol = "";
		while (getline(sor, s, ',')) {

			if (s.compare(old) == 0)
				lol += newVal;
			else lol += s;
			lol += ",";


		}
		cout << endl << lol << endl;
		return lol;

	}



	void search(T key, AvlNode<T>* temp)
	{
		
		bool found = false;
		if (temp == NULL)
			return;
		{
			search(key, temp->right);
			
			if (findString(temp->data, key))
				cout << temp->data << '\n';
		search(key,temp->left);
		}

	}
	void deletes(T key, AvlNode<T>* temp)
	{
		
		bool found = false;
		if (temp == NULL)
			return;
		{
			deletes(key, temp->right);
			
			if (findString(temp->data, key,true))
				temp->data = "";
			deletes(key, temp->left);
		}

	}


	void update(T key, T field, T old, T newVal, AvlNode<T>* temp)
	{
	
		bool found = false;
		if (temp == NULL)
			return;
		{
			update(key,field,old,newVal, temp->right);
			
			if (findString(temp->data, key,true))
			{
				temp->data = updateString(temp->data, field, old, newVal);
							found = true;
							Bal(&root, temp->data);
			}
			update(key, field, old, newVal, temp->left);
		}

	}






};

