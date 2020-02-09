#pragma once
#include <iostream>
using namespace std;
class String{
	friend istream & operator>>(istream & inStream,String & string);
	friend ostream & operator<<(ostream & outStream,String & string);
	
public:
	String();
	String(const char *string);
	String(const String &other);
	String &operator =(char *string);
	String &operator =(const String &other);
	String &operator +(char *string);
	String &operator +(const String &other);
	String &operator +=(char *string);
	String &operator +=(const String &other);
	String &operator -(char *string);
	String &operator -=(char *string);
	
	~String();
	void push_back(const char &c);
	void pop_back();
	void resize(int size);
	size_t capacity();
	size_t size();
	void shrink_to_fit();
	char * begin();
	char * end();
	char * rbegin();
	char * rend();
	void copy(char arr,size_t len,int pos);
	void swap(String &other);
private:
	char *string;
	size_t lenght;
	
};
