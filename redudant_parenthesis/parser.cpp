#include "header.h"

int i=0;
int value=0;
void s(char lat,string buffer){
	idl(lat,buffer);
	match('=',lat);
	cout<<"=";
	E(lat,buffer);
	
	return;
}
void idl(char lat,string buffer){
	cout<<lat;
	i++;
	lat=gettoken(i);
	return;
}
void E(char lat,string buffer){
	T(lat,buffer);
	R(lat,buffer);
	return;
}
void T(char lat,string buffer){
	F(lat,buffer);
	R1(lat,buffer);
	return;
	
}
void R(char lat,string buffer){
	if(lat=='+'){
		match('+',lat);
		cout<<"+";
		T(lat,buffer);
		R(lat,buffer);
	}
	else if(lat=='-'){
		match('-',lat);
		cout<<"-";
		T(lat,buffer);
		R(lat,buffer);
	}
	return;
}
void R1(char lat,string buffer){
	if(lat=='*'){
		match('*',lat);
		cout<<"*";
		F(lat,buffer);
		R1(lat,buffer);
	}
	else if (lat=='/'){
		match('/',lat);
		cout<<"/";
		F(lat,buffer);
		R1(lat,buffer);
		
	}
	return;
}
void F(char lat,string buffer){
	if(lat=='('){
		int j=i-1;
		match('(',lat);
		string s;
	for(int r=j;r<buffer.length();r++){
		if(buffer[r]=='+' || buffer[r]=='-' ||buffer[r]=='*' ||buffer[r]=='/' ||buffer[r]=='(' ||buffer[r]==')' || buffer[r]=='=' ){
			s+=buffer[r];
		}
		
	}	
		
		char str[3];
		str[0]=s[2];
		str[1]=s[3];
		str[2]=s[4];
		if(!strcmp(str,"+)*") || !strcmp(str,"-)*") || !strcmp(str,"+)/") || !strcmp(str,"-)/") || !strcmp(str,"-)-") || !strcmp(str,"/)/")){
			cout<<"(";
			value=value+1;
		}
		
		char str1[3];
		str1[0]=s[0];
		str1[1]=s[1];
		str1[2]=s[2];
		
		if(!strcmp(str1,"*(+") || !strcmp(str1,"*(-") || !strcmp(str1,"/(+") || !strcmp(str1,"/(-") || !strcmp(str1,"-(-") || !strcmp(str1,"/(/")){
			cout<<"(";
			value=value+1;
		}	
		E(lat,buffer);
		match(')',lat);
		if(value>0){
			cout<<")";
			value=value-1;
		}
	}
	else{
	
	cout<<lat;
	i++;
	lat=gettoken(i);
}
	return;
}

void match(char a,char lat){

	if(lat==a){
	i=i+1;
	lat=gettoken(i);
	
	}
	else{
		cout<<"error";
	}
	
return;
}

