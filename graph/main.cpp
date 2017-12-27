// adjacent list
#include <iostream>
#include <queue>
using namespace std;

struct node{
	int 	dest;
	bool 	visited = false;
	node* 	next;
};

struct list{
	node* head;
};

struct graph{
	int 	countV;
	list* 	array;	
};

node* 	newNode	(int n);
graph* 	create	(int V);
void 	addEdge	(graph* g, int src, int dest);
void 	printGraph	(graph* g);
void 	BFS (graph* g, int s){
	queue<int> bf;
	bf.push(s);

	while(!bf.empty()){
		int a = bf.front();
//		cout << a << " ";
		bf.pop();

		for(node* p = g->array[a].head; p != NULL; p = p->next){
			if(!p->visited){
				cout << "push " << p->dest << " to queue!\n";
				p->visited = true;
				bf.push(p->dest);
			}
		}
	}
	cout << endl;
	// done!

	// set all visited as false
	for(int i = 0 ; i < g->countV; i++)
		for(node* p = g->array[i].head; p != NULL; p = p->next)
			p->visited = false;
}

int main(){
	graph* g = create(5);
	addEdge(g,0,1);
	addEdge(g,0,4);
	addEdge(g,1,2);
	addEdge(g,1,3);
	addEdge(g,1,4);
	addEdge(g,2,3);
	addEdge(g,3,4);
	
//	printGraph(g);

	BFS(g, 0);

	return 0;
}

node* newNode(int n){
    node* newnode = new node;
    newnode->dest = n;

    return newnode;
}

// CREATE GRAPH OF V VERTICES
graph* create(int V){
    graph* newgraph     = new graph;
    newgraph->countV    = V;
    newgraph->array     = new list[V];

    for(int i = 0; i < V; i++){
        newgraph->array[i].head = NULL;
    }

    return newgraph;
}

void addEdge(graph* g, int src, int dest){
    // add dest node to src list
    node* newDest       = newNode(dest);
    newDest->next       = g->array[src].head;
    g->array[src].head  = newDest;

    // add src node to dest list
    node* newSrc        = newNode(src);
    newSrc->next        = g->array[dest].head;
    g->array[dest].head = newSrc;
}

void printGraph(graph* g){
    for(int v = 0; v < g->countV; v++){
        cout << v;
        node* crawl = g->array[v].head;

        while(crawl){
            cout << "->" << crawl->dest;
            crawl = crawl->next;
        }

        cout << endl;
    }
}


