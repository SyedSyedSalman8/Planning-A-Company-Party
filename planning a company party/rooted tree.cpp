// C++ program to find Max conviviality raating of a rooted tree
#include <iostream>
#include <algorithm> // for max func
#include <string.h>
using namespace std;


//Summary
//Accepts Nodes of tree and their convivality rating as input
//Outputs the max convivality rating based on
// siblings sum, (graparent + granchildren sum( and (uncle + nephews sum)


 
class Node       
{
public:
    int val;
    string name;
    Node *child;
    Node *next;
    Node *prev;
    Node(int P,char N)      /////////////constructor
    {
        val = P;
        name = N;
        child = NULL;
        next = NULL;
        prev = NULL;
    }
};
 

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Max_conv_rating(){ /////////////to verrify the convivality rating manually using valid conditions (Not an integral part of the program)
	
	Node *root = new Node(5,'A');
    root->child = new Node(3,'B');
    root->child->next = new Node(6,'C');
    root->child->next->next = new Node(4,'D');
    root->child->next->next->next = new Node(7,'E');
    root->child->child = new Node(10,'F');
    root->child->child->next = new Node(1,'G');
    root->child->next->next->child = new Node(11,'H');
    
    
    
    int x,y=0,z;
    Node *g=root->child;
    Node *m=root->child;
    Node *n=root->child;
    Node *o=root->child->child;
    
    	
	
	int i=0,l=4;
	
	while (g != NULL && i < l){
		x=x+g->val;
		y=y + g->val;

		g=g -> next; 
		i++;
	}
	cout <<"CHILD = " << g->name <<endl;
    
	int a=root->val + y;
	int b=x;
	int c=root->child->next->val + root->child->child->val + root->child->child->next->val + root->child->next->next->val + root->child->next->next->next->val;
	int d=root->child->val + root->child->next->next->child->val + root->child->next->val + root->child->next->next->next->val;
	
	cout << "sum of root and its granchildren = " << a << endl;
	cout << "sum of all children of root = " << b << endl;
	cout << "sum of children of first child of root and all their uncles " << c << endl;
	cout << d << endl;
	
	int max;
	if ( a > b && a>c && a>d){
		max= a;
		cout << "max convivality rating is " << max <<endl;
	}
	if ( b > a && b>c && b>d){
		max= b;
		cout << "max convivality rating is " << max <<endl;
	}
	if ( c > b && c>a && c>d){
		max= c;
		cout << "max convivality rating is " << max <<endl;
		/*while ( m != NULL){
			cout << "Employee to be invited: "<< m->name << endl;
			m = m->next;
			
		}*/
	}
	if ( d > b && d>c && d>a){
		max= a;
		cout << "max convivality rating is " << max <<endl;
	}


	
	
	
}

 
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
int Sum(Node *n){     ///////////for sibling sum
	int j=0;
	Node *m = n;
	Node *z = n->prev;
	int i=1;int k=1; 
	int t=0;

	while ( m != NULL ){
				Node *l=m->child;
				while(l != NULL ){
				
			j=j+l->val;
			l=l->next;
		}
		
	m=m->next;
	}	
	

	while ( z != NULL ){
				Node *k=z->child;
				while(k != NULL ){
			j=j+ k->val;
			k=k->next;
		}
		
				
	z=z->prev;
	}
	

return j;	
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	int Sum1(Node *n){   ///////for grandchildren sum
	int j=0;
	Node *m = n;
	Node *z = n->prev;
	int i=1;int k=1; int t=0;
	



	while ( m != NULL && i<5 ){ ////outer most loop for grandparent
				Node *g=m->child;	
			while (g != NULL){          //////////////outer loop for children
				Node *l= g->child;
			
				
			while(l != NULL ){
			           ////////////actual loop for all grandchildren inc cousins
			j=j+l->val;
			l=l->next;
			
		} 
		g=g->next;
	}

		
				
	m=m->next;
	i=i+1;	
	}	
	

		while ( z != NULL && i<5 ){
				Node *k=z->child;	
			while (k != NULL){
				Node *b= k->child;
			
				
			while(b != NULL ){
			j=j+b->val;
			b=b->next;
		} 
		k=k->next;
	}

		
	z=z->prev;
	i=i+1;	
	}	
	
	return j;	
	}



int a[30];
	int k=0;
	

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int Sum2(Node *n, int sum){ //////for uncle sum
	
	int j=0;
	Node *m = n;
	Node *z = n->prev;
	int i=1; 
	int t[10];

	while ( m != NULL ){
				Node *l=m->child;
				while(l != NULL ){
					j=0;
				int b=0;
			j=j+l->val ;
			b=j + sum;
		
			Node *i=l->child;
			while (i != NULL){    
				b=b - i->val;
				i=i->next;
			}
			
			cout << b << " Uncle plus nephew sum "  <<endl;
			a[k]=b;
			k++;
			l=l->next;
			
		}
		
	m=m->next;
	}	
	

}


 int Find_Max_Conv(Node *current){               ///////////// recursion
	
	if (current->child == NULL){ ///////returns first node that has no children
		cout << "No child = " <<current->val <<endl;
		return max(0,current->val);
		}
		Node *i=current;
		Node *j=current;
		Node *l=current->child;
		Node *m=current;
	
		
		a[k]=Sum(i);
		
		k++;
	
		a[k]= Sum1(j) + current->val;
		
		k++;    
		Node *x=current;
		Node *y=x->next;
		
		cout <<Sum(i) << " sibling sum"   <<endl;
		cout  << Sum1(j) + current->val  << " grandparent plus grandchildren " <<endl;

		Sum2(m,Sum1(j));

			if( current->next == NULL){
			
						while (x != NULL ){
						y=x;
						x=x->prev;
				
			}
 				return Find_Max_Conv(y->child) ; }
		else {
			
			
		return Find_Max_Conv( current->next);}
		}
	
	
  
int main()
{
    Node *root = new Node(5,'A');                  /////////////////////Tree 1
    root->child = new Node(3,'B');
    root->child->next = new Node(6,'C');
    root->child->next->next = new Node(4,'D');
    root->child->next->next->next = new Node(7,'E'); 
    root->child->child = new Node(10,'F');
    root->child->child->next = new Node(1,'G');
    root->child->next->child = new Node(2,'G');
    root->child->next->next->child = new Node(11,'H');
    
				root->child->child->child = new Node(20,'I');
    root->child->child->child->next = new Node(15,'J');
    root->child->next->next->next->child = new Node(8,'E');
    
     root->prev=NULL;
				root->child->prev=NULL;
				root->child->next->prev=root->child;
				root->child->next->next->prev=root->child->next;
				root->child->next->next->next->prev=root->child->next->next;
				root->child->child->prev=NULL;
				root->child->child->next->prev=root->child->child;
				root->child->next->child->prev=NULL;
				root->child->next->next->child->prev=NULL;
				root->child->next->next->next->child->prev=NULL;
				root->child->child->child->prev=root->child->child;
				root->child->child->child->next->prev=root->child->child->child;
   
				  
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
				Node *root1 = new Node(10,'A'); ////////////////////Tree 2
				root1->child	= new Node(12,'B');
				root1->child->next = new Node(14,'C');
				root1->child->next->child = new Node(13,'D');

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

 		Find_Max_Conv(root);      ////// insert the root of the tree you want to run
  

	int temp;
	int final;
	for(int i=1;i<29;i++)
    {
        for(int j=0;j<28;j++)
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
               
            }
    }
    
  	for (int i=0; i < 29; i++){
	
						final = a[i];
	}    
			cout << " Max Possible convivality rating of this tree: " << final <<endl;

	return 0;
}
