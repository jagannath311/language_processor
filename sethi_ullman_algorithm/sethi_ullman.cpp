//required header files,...
#include<iostream>
#include<cstdio>
#include<string.h>
#include<bits/stdc++.h>


using namespace std;
//structure for the node in the expression tree...
struct node{
	node *lft;
	char var;
	int reg;
	node *rght; 
};
//stacks of permanent and temporary registers....
stack <string> rstack;
stack <string> tstack;
//node pointers that req. to built expression tree
node *left_t=NULL;
node *right_t=NULL;
node *root=NULL;
node *center_t=NULL;
string buffer;
char lah,lat;
int i=0;
int value=0;//helpful to distinct expression with or without braces....

//SDT funcitons....
void s();
void idl();
void E();
void T();
void F();
void R();
void R1();
void match(char a);

//function for constructing the terminal nodes....only operators....
void makenode(char a){
	node *newnode=new node();
			newnode->lft=left_t;
			newnode->rght=right_t;
			newnode->var=a;
			if(newnode->lft!=NULL && newnode->rght!=NULL){
			
			if(newnode->lft->reg==newnode->rght->reg)
				newnode->reg=newnode->lft->reg+1;
			else if(newnode->lft->reg>newnode->rght->reg)
				newnode->reg=newnode->lft->reg;
			else
				newnode->reg=newnode->rght->reg;
				
			}	
		else if(newnode->lft==NULL){
			newnode->reg=newnode->rght->reg;
		}
		else
			newnode->reg=newnode->lft->reg;
			
		if(value==0){
			if(center_t==NULL)
				root=newnode;
			else if(center_t->lft==NULL)
				center_t->lft=newnode;
			else 
				center_t->rght=newnode;
			center_t=newnode;
			left_t=NULL;
			right_t=NULL;
			
		}
		else{
			left_t=NULL;
			right_t=NULL;
			if(center_t->lft==NULL){
				center_t->lft=newnode;
			}
			else{
				center_t->rght=newnode;
			}
		}
	
	
	
	
	
}
 

void E(){
	T();
	R();
	return;
}
void T(){
	F();
	R1();
	return;
	
}
void R(){
	if(lat=='+'){
		match('+');
		makenode('+');
		
		T();
		R();
	}
	else if(lat=='-'){
		match('-');
		makenode('-');
		
		T();
		R();
	}
	return;
}
void R1(){
	if(lat=='*'){
		match('*');
		makenode('*');
		
		F();
		R1();
	}
	else if (lat=='/'){
		match('/');
		makenode('/');
		
		F();
		R1();
		
	}
	return;
}
void F(){
	if(lat=='('){
		match('(');
		value=value+1;
		E();
		match(')');
		value=value-1;
	}
	else{
	if(value>0){
		//node for id inside a parenthesis
		node *newnode=new node();
		
		if(left_t==NULL){
			
			newnode->lft=NULL;
			newnode->reg=1;
			newnode->var=lat;
			newnode->rght=NULL;
			left_t=newnode;
			
			
		}
		
		 else if(right_t==NULL){
			
			newnode->lft=NULL;
			newnode->reg=0;
			newnode->var=lat;
			newnode->rght=NULL;
			right_t=newnode;
			
			
		}
         if(center_t!=NULL){
		 
        	center_t->rght=newnode;
			left_t=center_t;
			right_t=center_t;
			center_t=NULL; 
     }
	}
		
	else{
		node *newnode=new node();
		//node for id not in parenthesis.....
		if(left_t==NULL){
			
			newnode->lft=NULL;
			newnode->reg=1;
			newnode->var=lat;
			newnode->rght=NULL;
			left_t=newnode;
			if(center_t!=NULL){
				if(center_t->lft==NULL){
					center_t->lft=newnode;
				}
				else
					center_t->rght=newnode;
			}
			
		}
		
		 else if(right_t==NULL){
			
			newnode->lft=NULL;
			newnode->reg=0;
			newnode->var=lat;
			newnode->rght=NULL;
			right_t=newnode;
			if(center_t!=NULL){
				
				if(center_t->lft==NULL){
					center_t->lft=newnode;
				}
				else
					center_t->rght=newnode;
			}
			
			
		}
		
		
		
	}	
	i++;
	lat=buffer[i];
	}
	return;
}

void match(char a){

	if(lat==a){
	i=i+1;
	lat=buffer[i];
	
	}
	else{
		cout<<"error";
	}
	
return;
}

//helper function in gencode.....
void swap(stack <string> s){
	string X,Y;
	X=s.top();
	s.pop();
	Y=s.top();
	s.push(Y);
	s.push(X);
	
	return;
}


void gencode(node *root){
	if(root->lft!=NULL){
	
	if((root->lft)->lft==NULL&&root->lft->rght==NULL){
		//left child is leaf node
		cout<<rstack.top()<<"<-"<<root->lft->var<<"\n";
		
		
	}}
	if(root->rght!=NULL){
	
	 if(root->rght->lft==NULL&&root->rght->lft==NULL){
		//right child is leaf node......
		gencode(root->lft);
		cout<<rstack.top()<<"<-"<<rstack.top()<<root->var<<root->rght->var<<"\n";
	}}
	if(root->lft!=NULL&&root->rght!=NULL){
	
	 if(root->lft->reg<root->rght->reg && root->rght->reg<3 ){
		//right child requires more registers and less than total
		string X;
		swap(rstack);
		gencode(root->rght);
		X=rstack.top();
		rstack.pop();
		gencode(root->lft);
		cout<<rstack.top()<<"<-"<<rstack.top()<<root->var<<"\t"<<X<<"\n";
		rstack.push(X);
		swap(rstack);
	}
	else if(root->lft->reg>=root->rght->reg && root->lft->reg<3 ){
		//left child requires more registers and less than total
		string X;
		gencode(root->lft);
		X=rstack.top();
		rstack.pop();
		gencode(root->rght);
		cout<<rstack.top()<<"<-"<<rstack.top()<<root->var<<"\t"<<X<<"\n";
		rstack.push(X);;
		
	}
 	else if(root->lft->reg>=3&&root->rght->reg>=3){
		//both require more registers....
		string X;
		gencode(root->rght);
		X=tstack.top();
		tstack.pop();
		cout<<X<<"<-"<<rstack.top();
		gencode(root->lft);
		tstack.push(X);
		cout<<rstack.top()<<"<-"<<rstack.top()<<root->var<<X<<"\n";
	}}
	return;
}


int main(){
	
	cout<<"enter the expression";
	getline(cin,buffer);
	lat=buffer[i];
	E();
	//no. of permanent registers 3
	rstack.push("r2");
	rstack.push("r1");
	rstack.push("r0");
	//no .of temporary registers 2
	tstack.push("t1");
	tstack.push("t0");
	//generates code....
	gencode(root);
	return 0;
	
}
