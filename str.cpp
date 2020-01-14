///////////////////////////////////////////////////////////////////
//  str.h      -  implementation file for string class           //
//                                                               //
//                                                               //
//  Language:     Visual C++                                     //
//                                                               //
//                                                               //
//  Author:       Simuk Arya                                     //
//                Syracuse University                            //
//                MSEE 2020, siarya@syr.edu                      //
///////////////////////////////////////////////////////////////////

#include "str.h"
#include<stdexcept>
#include<cstring>

//---------------------< sized constructor>--------------------------------
str::str(int n ) : len(0),max(n),array(new char(n))
{
	//array[0] = '/0';
}

//---------------------< copy constructor>---------------------------------
str::str(str& obj):array(new char(obj.max)),len(obj.len),max(obj.max)
{
	
	for (int i = 0; i <= len; i++)
	{
		array[i] = obj.array[i];
	}
}

//---------------------< move constructor>---------------------------------

str::str(str&& obj)
{
	delete [] array;
	len = obj.len;
	max = obj.max;
	array = obj.array;
	obj.array = nullptr;
}

//---------------------< destructor>---------------------------------
str::~str()
{
	delete [] array;
	array = nullptr;
}

//---------------------< copy assignment>----------------------------
str str::operator=(const str& obj) 
{
	len = obj.len;
	max = obj.max;
	delete[] array;
	for (int i = 0; i <= len; i++)
	{
		array[i] = obj.array[i];
	}

	return *this;
}


//---------------------< move assignment>----------------------------
str str::operator=(str&& obj)
{
	if (this == &obj)
		return *this;

	delete[] array;
	len = obj.len;
	max = obj.max;

	array = obj.array;
	obj.array = nullptr;

	return *this;
}






//---------------------< character append>----------------------------
str str::operator+=(char ch)
{
	if (len + 1 > max)
	{
		max = 2 * max;
		char* temp=new char[max];
		for (int i = 0; i < len; i++)
		{
			temp[i] = array[i];
		}
		len += 1;
		temp[len] = ch;
		temp[len + 1] = '/0';
		delete[] array;
		array = temp;
	}
	else
	{
		array[len] = ch;
		array[len + 1] = '/0';
		len++;
	}
	

	return *this;
}



//---------------------< string append>----------------------------
str str::operator+=(const str& s)
{
	if (len < max - s.len) {
		int i;
		for (i = 0; i <= s.len; i++)
			array[len + i] = s.array[i];
		len += s.len;
	}
	else {
		max += max + s.len;
		char* temp = new char[max];
		for (int i = 0; i < len; i++)
			temp[i] = array[i];
		for (int i = 0; i < s.len; i++)
			temp[len + i] = s.array[i];
		temp[len + s.len] = '\0';
		len += s.len;
		delete[] array;
		array = temp;
	}
	return *this;
}


//---------------------< concatenate string >----------------------------
str str::operator+(const str& obj)
{
	str temp = *this;
	temp += obj;
	return *this;
}

//---------------------< index operator>----------------------------
char& str::operator[](int n)
{
	if (n < 0 || n >= len)
		throw std::invalid_argument("index out of bounds in operator");

	char z = array[n];

	return z;
}

//---------------------< output operator >----------------------------
ostream& operator<<(ostream& out, const str& s) {

	int i;
	char* temp = new char[s.size()];
	for (i = 0; i < s.size(); i++)
		std::cout << s.array[i];
	return out;
}

//---------------------< input operator >----------------------------
istream& operator>>(istream& in, str& s) {

	char ch;
	s.flush();
	in >> ch;
	while ((ch != '\n') && in.good()) {
		s += ch;
		in.get(ch);
	}
	return in;
}




#ifdef Test_string

int main()
{
	


	return 0;
}

#endif