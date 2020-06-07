#include"header.h"




int main(){
	string buffer;
	char lat;
	cout<<"enter the expression in the for var=expr";
	getline(cin,buffer);
	token *head=NULL;
	
	
	
	lat=firsttoken(&head,buffer);
	s(lat,buffer);
	
	return 0;

	
	
}
