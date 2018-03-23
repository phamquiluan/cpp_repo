#include <iostream>
using namespace std;

struct node{ 
	int data; 
	node* left = NULL; 
	node* right = NULL; 
	int ht = 1; 
};

void LNR(node* root){ 
	if(root == NULL) 
		return; 
	LNR(root->left); 
	cout << root->data << " "; 
	LNR(root->right); 
}

void NLR(node* root){
	if(!root) return;
	cout << root->data << " ";
	NLR(root->left);
	NLR(root->right);
}

int getBalance(node* root){
	int LH, RH;
	if(!root->left) LH = 0;
	else LH = root->left->ht;
	if(!root->right) RH = 0;
	else RH = root->right->ht;
	
	return LH - RH;
}

node* rotLeft(node* root){
	node* y = root;
	node* x = root->right;

	y->right = x->left;
	x->left  = y;
	root = x;

	// UPDATE HEIGHT
	int LH, RH;
	
	// update for y	
	if(!y->left)
		LH = 0;
	else
		LH = y->left->ht;
	if(!y->right)
		RH = 0;
	else
		RH = y->right->ht;
	y->ht = (LH > RH) ? LH : RH + 1;

	// update for x;
	if(!x->left)
		LH = 0;
	else
		LH = x->left->ht;
	if(!x->right)
		RH = 0;
	else
		RH = x->right->ht;
	x->ht = (LH > RH) ? LH : RH + 1;

	return x;
}

node* rotRight(node* root){
	node* y = root;
	node* x = root->left;

	y->left  = x->right;
	x->right = y;
	root = x;

	int LH, RH;
	// update for y	
	if(!y->left)
		LH = 0;
	else
		LH = y->left->ht;
	if(!y->right)
		RH = 0;
	else
		RH = y->right->ht;
	y->ht = (LH > RH) ? LH : RH + 1;

	// update for x;
	if(!x->left)
		LH = 0;
	else
		LH = x->left->ht;
	if(!x->right)
		RH = 0;
	else
		RH = x->right->ht;
	x->ht = (LH > RH) ? LH : RH + 1;


	return x;
}

// for case RIGHT of LEFT
node* rotLR(node* root){
	node* y = root;
	node* x = y->left;
	node* w = x->right;

	// rot left
	x->right = w->left;
	w->left  = x;

	// rot right
	y->left  = w->right;
	w->right = y;

	// UPDATE HEIGHT
	int LH, RH;

	// update for y	
	if(!y->left)
		LH = 0;
	else
		LH = y->left->ht;
	if(!y->right)
		RH = 0;
	else
		RH = y->right->ht;
	y->ht = (LH > RH) ? LH : RH + 1;

	// update for x;
	if(!x->left)
		LH = 0;
	else
		LH = x->left->ht;
	if(!x->right)
		RH = 0;
	else
		RH = x->right->ht;
	x->ht = (LH > RH) ? LH : RH + 1;

	// update for w;
	if(!w->left)
		LH = 0;
	else
		LH = w->left->ht;
	if(!w->right)
		RH = 0;
	else
		RH = w->right->ht;
	w->ht = (LH > RH) ? LH : RH + 1;

	return w;
}

// for case LEFT of RIGHT
node* rotRL(node* root){
	node* y = root;
	node* x = y->right;
	node* w = x->left;

	// rot right
	x->left  = w->right;
	w->right = x;

	// rot left
	y->right = w->left;
	w->left  = y;
	
	
	// UPDATE HEIGHT
	int LH, RH;

	// update for y	
	if(!y->left)
		LH = 0;
	else
		LH = y->left->ht;
	if(!y->right)
		RH = 0;
	else
		RH = y->right->ht;
	y->ht = (LH > RH) ? LH : RH + 1;

	// update for x;
	if(!x->left)
		LH = 0;
	else
		LH = x->left->ht;
	if(!x->right)
		RH = 0;
	else
		RH = x->right->ht;
	x->ht = (LH > RH) ? LH : RH + 1;

	// update for w;
	if(!w->left)
		LH = 0;
	else
		LH = w->left->ht;
	if(!w->right)
		RH = 0;
	else
		RH = w->right->ht;
	w->ht = (LH > RH) ? LH : RH + 1;

	return w;
}




node* insert(node * root, int data){
	if(root == NULL){
		node* newnode    = new node;
		newnode->data    = data;
		newnode->left    = NULL;
		newnode->right   = NULL;
		newnode->ht      = 0;

		return newnode;
	}
	else if(data > root->data){
		root->right = insert(root->right, data);
	}
	else if(data < root->data){
		root->left  = insert(root->left, data);
	}
	else{
		return root;
	}

	// update ht for ancestor
	int ht, LH, RH;
	if(!root->left){
		LH = 0;
	}
	else{
		LH = root->left->ht;
	}
	if(!root->right){
		RH = 0;
	}
	else{
		RH = root->right->ht;
	}

	root->ht = (LH  > RH ? LH : RH) + 1;


	// get the factor balanced
	int factor = LH - RH;

	if(factor > 1){ // case left
		// left left
		if(data < root->left->data){
			node* z = root, *x = root->left, *y = x->left;

			z->left = x->right;
			x->right = z;

			// update ht
			int ht, LH, RH;
			// update for z
			if(!z->left)
				LH = 0;
			else
				LH = z->left->ht;
			if(!z->right)
				RH = 0;
			else
				RH = z->right->ht;

			z->ht = (LH  > RH ? LH : RH) + 1;

			// update for x
			if(!x->left)
				LH = 0;
			else
				LH = x->left->ht;
			if(!x->right)
				RH = 0;
			else
				RH = x->right->ht;

			x->ht = (LH  > RH ? LH : RH) + 1;

			return x;
		}
		else{ // left right
			node* z = root, *x = root->left, *y = x->right;

			z->left     = y->right;
			y->right    = z;
			x->right    = y->left;
			y->left     = x;
			
			// update ht
			int LH, RH;
			// update for z
			if(!z->left)
				LH = 0;
			else
				LH = z->left->ht;
			if(!z->right)
				RH = 0;
			else
				RH = z->right->ht;

			z->ht = (LH  > RH ? LH : RH) + 1;

			// update for x
			if(!x->left)
				LH = 0;
			else
				LH = x->left->ht;
			if(!x->right)
				RH = 0;
			else
				RH = x->right->ht;

			x->ht = (LH  > RH ? LH : RH) + 1;

			// update for y
			if(!y->left)
				LH = 0;
			else
				LH = y->left->ht;
			if(!y->right)
				RH = 0;
			else
				RH = y->right->ht;

			y->ht = (LH  > RH ? LH : RH) + 1;

			return y;
		}
	}
	if(factor < -1){ // case right
		// right right
		if(root->right->data < data){
			node* z = root, *x = root->right, *y = x->right;

			z->right = x->left;
			x->left  = z;
			
			// update ht
			int LH, RH;
			// update for z
			if(!z->left)
				LH = 0;
			else
				LH = z->left->ht;
			if(!z->right)
				RH = 0;
			else
				RH = z->right->ht;

			z->ht = (LH  > RH ? LH : RH) + 1;

			// update for x
			if(!x->left)
				LH = 0;
			else
				LH = x->left->ht;
			if(!x->right)
				RH = 0;
			else
				RH = x->right->ht;

			x->ht = (LH  > RH ? LH : RH) + 1;

			return x;
		}
		else{ // right left
			node* z = root, *x = root->right, *y = x->left;

			z->right    = y->left;
			y->left     = z;
			x->left     = y->right;
			y->right    = x;

			// update ht
			int LH, RH;
			// update for z
			if(!z->left)
				LH = 0;
			else
				LH = z->left->ht;
			if(!z->right)
				RH = 0;
			else
				RH = z->right->ht;

			z->ht = (LH  > RH ? LH : RH) + 1;

			// update for x
			if(!x->left)
				LH = 0;
			else
				LH = x->left->ht;
			if(!x->right)
				RH = 0;
			else
				RH = x->right->ht;

			x->ht = (LH  > RH ? LH : RH) + 1;

			// update for y
			if(!y->left)
				LH = 0;
			else
				LH = y->left->ht;
			if(!y->right)
				RH = 0;
			else
				RH = y->right->ht;

			y->ht = (LH  > RH ? LH : RH) + 1;

			
			return y;
		}
	}
	return root;
}

node* deleteNode(node* root, int data){
	// STEP 1: PERFORM STANDARD BST DELETION
	if(!root) 
		return root;
	if(data < root->data)
		root->left  = deleteNode(root->left, data);
	else if(data > root->data)
		root->right = deleteNode(root->right, data);
	else{
		// this
		if(!root->left || !root->right){ // not complete 2 child
			node* temp = root->left ? root->left : root->right;
			
			if(!temp){	// case no child
				temp = root; 
				root = NULL;	
			}
			else{ // case one child;
				*root = *temp;
			}
			delete temp;
		}
		else{ // complete 2 child
			node* temp = root->right;
			while(temp->left)
				temp = temp->left;
			
			root->data = temp->data;

			root->right = deleteNode(root->right, root->data);
		}
	}
	if(!root)
		return NULL;

	// STEP 2: UPDATE HEIGHT OF CURRENT NODE
	int LH, RH;
	if(!root->left) LH = 0;
	else LH = root->left->ht;
	if(!root->right) RH = 0;
	else RH = root->right->ht;
	root->ht = (LH > RH ? LH : RH) + 1;

	// STEP 3: GET BALANCED FACTOR
	int factor = LH - RH;

	if(factor > 1 && getBalance(root->left) >= 0) // case LEFT LEFT
		return rotRight(root);	
	if(factor > 1 && getBalance(root->left) <  0) // case RIGHT of LEFT
		return rotRL(root);
	if(factor < -1 && getBalance(root->right) <= 0) // case RIGHT RIGHT
		return rotLeft(root);
	if(factor < -1 && getBalance(root->right) >  0) // case LEFT of RIGHT
		return rotLR(root);
	
	return root;
}


int main(){
	node* root =  NULL;
	
	for(int i = 0; i < 11; i++)
		root = insert(root, i);

	LNR(root); cout << endl;
	NLR(root); cout << endl;
	
	root = deleteNode(root, 1); 
	
	LNR(root); cout << endl;
	NLR(root); cout << endl;
	return 0;
}
