#include "header.h"


token *temp1=NULL;
token *temp2=NULL;
char firsttoken(token** head,string buffer){
	token *new_token=new token();
	new_token->id=0;
	new_token->next=NULL;
	if (isalpha(buffer[0])){
		new_token->type="var";
		new_token->var=buffer[0];
	}
	else{
		cout<<"lexical error expected a variable";
	}
	*head=new_token;
	temp1=*head;
	temp2=*head;
	maketoken(buffer);	
return buffer[0];	
}

char gettoken(int j){
	token *temp3=temp1;
	int i;
	for(i=0;i<j;i++){
		temp3=temp3->next;
	}
	
return temp3->var;	
}


void maketoken(string buffer){
	int i=1;
	
	for(i=1;i<buffer.length();i++){
		token* new_token=new token();	
		new_token->id=i;
		new_token->next=NULL;
		if(isalpha(buffer[i])){
			new_token->type="var";
			new_token->var=buffer[i];	
		}
		else{
			new_token->type="op";
			new_token->var=buffer[i];
		}
		
		temp2->next=new_token;
		temp2=temp2->next;
	}	
	
	
return;	


}
