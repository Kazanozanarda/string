#include "string.h"
ostream & operator<<(ostream & outStream,String & string)
{
	for(unsigned i=0;i<string.lenght;i++)
	{
		outStream<<string.string[i];
	}
	return outStream;
}
istream & operator>>(istream & inStream,String & string)
{
	char temp[1000];
	inStream>>temp;
	string=temp;
	return inStream;
}

size_t strlenght(const char *string){
	size_t len=0;
	while(string[++len] != '\0');
	return len;
}
String::String(){
	lenght=0;
	string=nullptr;
}
String::String(const char * string)
{
	lenght=strlenght(string);
	this->string = new char[lenght];
	if(this->string == nullptr) 
		exit(-1);
	for(unsigned i=0;i<lenght;i++)
	{
		this->string[i]=string[i];
	}
}
String::String(const String &other)
{
	lenght=other.lenght;
	if(string != nullptr)
		delete[] string;
	string = new char[lenght];
	if(string == nullptr)
		exit(-1);
	for(unsigned i=0;i<lenght;i++)
	{
		string[i]=other.string[i];
	}
}
String::~String()
{
	delete[] string;
}

String &String::operator =(char *string){
	lenght=strlenght(string);
	if(this->string != nullptr)
		delete[] this->string;
	this->string = new char[lenght];
	if(this->string == nullptr)
		exit(-1);
	for(unsigned i=0;i<lenght;i++)
	{
		this->string[i]=string[i];
	}
	return *this;
}
String &String::operator =(const String &other)
{
	lenght=other.lenght;
	if(string != nullptr)
		delete[] string;
	string = new char[lenght];
	if(string == nullptr)
		exit(-1);
	for(unsigned i=0;i<lenght;i++)
	{
		string[i]=other.string[i];
	}
	return *this;
}
void String::push_back(const char &c)
{
	lenght=lenght+1;
	// eger nullptr ise bos string demektir
	//tekrar temp olusturup kopyalamaya gerek yok
	if(string == nullptr)
	{
		string=new char[lenght];
		if(string == nullptr)
			exit(-1);
		string[0]=c;
		return;
	}
	char temp[lenght];
	for(unsigned i=0;i<lenght-1;i++)
	{
		temp[i]=string[i];
	}
	temp[lenght-1]=c;
	delete[] string;
	string=new char[lenght];
	if(string == nullptr)
		exit(-1);
	for(unsigned i=0;i<lenght;i++)
	{
		string[i]=temp[i];
	}
}
void String::pop_back()
{		
	//cunku son karakteri yok
	if(string == nullptr)
		return;
	char temp[lenght];
	for(unsigned i=0;i<lenght;i++)
	{
		temp[i]=string[i];
	}
	lenght=lenght-1;
	delete[] string;
	string = new char[lenght];
	if(string == nullptr)
		exit(-1);
	for(unsigned i=0;i<lenght;i++)
	{
		string[i]=temp[i];
	}
}
size_t String::size()
{
	return lenght;
}
void String::swap(String &other)
{
	String temp(other);
	other=*this;
	*this=temp;
}
void String::resize(int size)
{
	string[size]='\0';
	lenght=size;
}
/*
size_t String::capacity()
{

}*/
//this'in degismemesi lazim
String &String::operator +(char *string)
{
	char *temp=new char[strlenght(string)+lenght];
	for(unsigned i=0;i<lenght;i++)
	{
		temp[i]=this->string[i];
	}
	for(unsigned i=0;i<strlenght(string);i++)
	{
		temp[lenght+i]=string[i];
	}
	String temp1(temp);
	*this=temp1;
	return *this;
}
//this'in degismemesi lazim
String &String::operator +(const String &other)
{
	char *temp=new char[lenght+other.lenght];
	for(unsigned i=0;i<lenght;i++)
	{
		temp[i]=string[i];
	}
	for(unsigned i=0;i<other.lenght;i++)
	{
		temp[lenght+i]=other.string[i];
	}
	String temp1(temp);
	*this=temp1;
	return *this;
}
String &String::operator +=(char *string)
{
	char *temp=new char[strlenght(string)+lenght];
	for(unsigned i=0;i<lenght;i++)
	{
		temp[i]=this->string[i];
	}
	for(unsigned i=0;i<strlenght(string);i++)
	{
		temp[lenght+i]=string[i];
	}
	String temp1(temp);
	*this=temp1;
	return *this;
}
String &String::operator +=(const String &other)
{
	char *temp=new char[lenght+other.lenght];
	for(unsigned i=0;i<lenght;i++)
	{
		temp[i]=string[i];
	}
	for(unsigned i=0;i<other.lenght;i++)
	{
		temp[lenght+i]=other.string[i];
	}
	String temp1(temp);
	*this=temp1;
	return *this;
}



