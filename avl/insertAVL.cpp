#include <iostream>
using namespace std;

struct node{
	int val;
	node* left;
	node* right;
	int ht;
};

void LNR(node* root){
	if(root == NULL)
		return;

	LNR(root->left);
	cout << root->val << " ";
	LNR(root->right);
}

node* insert(node * root, int val){
	if(root == NULL){
		node* newnode    = new node;
		newnode->val     = val;
		newnode->left    = NULL;
		newnode->right   = NULL;
		newnode->ht      = 0;

		return newnode;
	}
	else if(val > root->val){
		root->right = insert(root->right, val);
	}
	else if(val < root->val){
		root->left  = insert(root->left, val);
	}
	else{
		return root;
	}

	// update height for ancestor
	int height, LH, RH;
	if(!root->left){
		LH = -1;
	}
	else{
		LH = root->left->ht;
	}
	if(!root->right){
		RH = -1;
	}
	else{
		RH = root->right->ht;
	}

	root->ht = (LH  > RH ? LH : RH) + 1;


	// get the factor balanced
	int factor = LH - RH;

	if(factor > 1){ // case left
		// left left
		if(val < root->left->val){
			node* z = root, *x = root->left, *y = x->left;

			z->left = x->right;
			x->right = z;

			// update height
			int height, LH, RH;
			// update for z
			if(!z->left)
				LH = -1;
			else
				LH = z->left->ht;
			if(!z->right)
				RH = -1;
			else
				RH = z->right->ht;

			z->ht = (LH  > RH ? LH : RH) + 1;

			// update for x
			if(!x->left)
				LH = -1;
			else
				LH = x->left->ht;
			if(!x->right)
				RH = -1;
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
			
			// update height
			int LH, RH;
			// update for z
			if(!z->left)
				LH = -1;
			else
				LH = z->left->ht;
			if(!z->right)
				RH = -1;
			else
				RH = z->right->ht;

			z->ht = (LH  > RH ? LH : RH) + 1;

			// update for x
			if(!x->left)
				LH = -1;
			else
				LH = x->left->ht;
			if(!x->right)
				RH = -1;
			else
				RH = x->right->ht;

			x->ht = (LH  > RH ? LH : RH) + 1;

			// update for y
			if(!y->left)
				LH = -1;
			else
				LH = y->left->ht;
			if(!y->right)
				RH = -1;
			else
				RH = y->right->ht;

			y->ht = (LH  > RH ? LH : RH) + 1;

			return y;
		}
	}
	if(factor < -1){ // case right
		// right right
		if(root->right->val < val){
			node* z = root, *x = root->right, *y = x->right;

			z->right = x->left;
			x->left  = z;
			
			// update height
			int LH, RH;
			// update for z
			if(!z->left)
				LH = -1;
			else
				LH = z->left->ht;
			if(!z->right)
				RH = -1;
			else
				RH = z->right->ht;

			z->ht = (LH  > RH ? LH : RH) + 1;

			// update for x
			if(!x->left)
				LH = -1;
			else
				LH = x->left->ht;
			if(!x->right)
				RH = -1;
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

			// update height
			int LH, RH;
			// update for z
			if(!z->left)
				LH = -1;
			else
				LH = z->left->ht;
			if(!z->right)
				RH = -1;
			else
				RH = z->right->ht;

			z->ht = (LH  > RH ? LH : RH) + 1;

			// update for x
			if(!x->left)
				LH = -1;
			else
				LH = x->left->ht;
			if(!x->right)
				RH = -1;
			else
				RH = x->right->ht;

			x->ht = (LH  > RH ? LH : RH) + 1;

			// update for y
			if(!y->left)
				LH = -1;
			else
				LH = y->left->ht;
			if(!y->right)
				RH = -1;
			else
				RH = y->right->ht;

			y->ht = (LH  > RH ? LH : RH) + 1;

			
			return y;
		}
	}
	return root;
}

int main(){
	node* root =  NULL;

	root = insert(root, 4);
	root = insert(root, 3);
	root = insert(root, 2);
	root = insert(root, 4);
	root = insert(root, 5);
	root = insert(root, 6);

	LNR(root);

	cout << endl;
	return 0;
}
