#include <iostream>
#include <ios>
#include <string>
#include <bitset>
#include "Large_Int.h"





//template <typename T, size_t SIZE>
//void print_bits(typename T, size_t SIZE){}

/*
void Large_int::print_hexchar(uf64 value)
{
	hex symbl = value;
	switch (symbl)
	{
	case :  return buff = 0x0;
		break;
	case '1':  return buff = 0x1;
		break;
	case '2':  return buff = 0x2;
		break;
	case '3':  return buff = 0x3;
		break;
	case '4':  return buff = 0x4;
		break;
	case '5':  return buff = 0x5;
		break;
	case '6':  return buff = 0x6;
		break;
	case '7':  return buff = 0x7;
		break;
	case '8':  return buff = 0x8;
		break;
	case '9':  return buff = 0x9;
		break;
	case 'a':  return buff = 0xa;
		break;
	case 'b':  return buff = 0xb;
		break;
	case 'c':  return buff = 0xc;
		break;
	case 'd':  return buff = 0xd;
		break;
	case 'e':  return buff = 0xe;
		break;
	case 'f':  return buff = 0xf;
		break;
	}
}
*/
void Large_int::get_hex()
{
	Large_int::print_hex();
}

uf64 get_digit(char num)
{
	uf64 buff;
	switch (num)
	{
	case '0':  return buff = 0x0;
		break;
	case '1':  return buff = 0x1;
		break;
	case '2':  return buff = 0x2;
		break;
	case '3':  return buff = 0x3;
		break;
	case '4':  return buff = 0x4;
		break;
	case '5':  return buff = 0x5;
		break;
	case '6':  return buff = 0x6;
		break;
	case '7':  return buff = 0x7;
		break;
	case '8':  return buff = 0x8;
		break;
	case '9':  return buff = 0x9;
		break;
	case 'a':  return buff = 0xa;
		break;
	case 'b':  return buff = 0xb;
		break;
	case 'c':  return buff = 0xc;
		break;
	case 'd':  return buff = 0xd;
		break;
	case 'e':  return buff = 0xe;
		break;
	case 'f':  return buff = 0xf;
		break;
	}
}

void Large_int::set_hex(std::string value)
{
	uf64 nymbl = 0x0ull;
	std::string::iterator begin = value.begin(), end = value.end();
	while (begin++ != end)
	{
		nymbl = get_digit(*begin);
		nymbl <<= std::distance(begin, end);
	}
	this->value_.push_back(nymbl);
}

int main()
{
	std::string v = "ffffffffffffffff";
	Large_int ff;
	uint_fast64_t max = (uint_fast64_t)-1;
	char ch = 'e';
	ff.set_hex(v);
    std::bitset<64> initial(max);
	std::cout << "size before:" << max  << " " << std::hex << max << " " << initial << std::endl;
	//size <<= 60;
	//std::bitset<64> modified(size);
	
	//while (size != 0)	{	};
	
    //std::cout << "size after: " << size << " " << std::hex << size << modified << std::endl;


	return 0;
}