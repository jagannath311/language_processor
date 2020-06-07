#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <cctype>
#include <cstring>

using namespace std;




struct token{
	int id;
	char var;
	string type;
	token *next;
};


char firsttoken(token**,string);
char gettoken(int);
void maketoken(string);

void s(char,string);
void idl(char,string);
void E(char,string);
void T(char,string);
void F(char,string);
void R(char,string);
void R1(char,string);
void match(char a,char);
