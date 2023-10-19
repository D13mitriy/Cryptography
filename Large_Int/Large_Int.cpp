#include <iostream>
#include <ios>
#include <string>
#include <bitset>
#include <future>
#include <iterator>
#include <utility>
#include "Large_Int.h"







char to_char(uf64 num)
{
	switch (num)
	{
	case 0: return '0';
		break;
	case 1: return '1';
		break;
	case 2: return '2';
		break;
	case 3: return '3';
		break;
	case 4: return '4';
		break;
	case 5: return '5';
		break;
	case 6: return '6';
		break;
	case 7: return '7';
		break;
	case 8: return '8';
		break;
	case 9: return '9';
		break;
	case 10: return 'a';
		break;
	case 11: return 'b';
		break;
	case 12: return 'c';
		break;
	case 13: return 'd';
		break;
	case 14: return 'e';
		break;
	case 15: return 'f';
		break;
	default:  std::cout << "Invalid value!" << std::endl;
	}
	return 16;
}

std::string binaty_to_hex(const uf64& block)
{
	std::string result;
	Large_int::Nybls digit(block);
	result.push_back(to_char(digit.first));
	result.push_back(to_char(digit.other));
	result.push_back(to_char(digit.third));
	result.push_back(to_char(digit.fourth));
	result.push_back(to_char(digit.fifth));
	result.push_back(to_char(digit.sixth));
	result.push_back(to_char(digit.seventh));
	result.push_back(to_char(digit.eighth));
	result.push_back(to_char(digit.ninth));
	result.push_back(to_char(digit.tenth));
	result.push_back(to_char(digit.eleventh));
	result.push_back(to_char(digit.twelfth));
	result.push_back(to_char(digit.thirteenth));
	result.push_back(to_char(digit.fourteenth));
	result.push_back(to_char(digit.fifteenth));
	result.push_back(to_char(digit.sixteenth));
	return result;
}

std::string Large_int::get_hex() const
{
	std::string result;
	for (const auto& block : value_)
	{
		result += binaty_to_hex(block);
	}
	return result;
}

uf64 Large_int::hex_to_binary(char hex_digit)
{
	uf64 buff;
	switch (hex_digit)
	{
	case '0':  return buff = static_cast<uf64>(Large_int::hex::_0x0);
		break;
	case '1':  return buff = static_cast<uf64>(Large_int::hex::_0x1);
		break;
	case '2':  return buff = static_cast<uf64>(Large_int::hex::_0x2);
		break;
	case '3':  return buff = static_cast<uf64>(Large_int::hex::_0x3);
		break;
	case '4':  return buff = static_cast<uf64>(Large_int::hex::_0x4);
		break;
	case '5':  return buff = static_cast<uf64>(Large_int::hex::_0x5);
		break;
	case '6':  return buff = static_cast<uf64>(Large_int::hex::_0x6);
		break;
	case '7':  return buff = static_cast<uf64>(Large_int::hex::_0x7);
		break;
	case '8':  return buff = static_cast<uf64>(Large_int::hex::_0x8);
		break;
	case '9':  return buff = static_cast<uf64>(Large_int::hex::_0x9);
		break;
	case 'a':  return buff = static_cast<uf64>(Large_int::hex::_0xa);
		break;
	case 'b':  return buff = static_cast<uf64>(Large_int::hex::_0xb);
		break;
	case 'c':  return buff = static_cast<uf64>(Large_int::hex::_0xc);
		break;
	case 'd':  return buff = static_cast<uf64>(Large_int::hex::_0xd);
		break;
	case 'e':  return buff = static_cast<uf64>(Large_int::hex::_0xe);
		break;
	case 'f':  return buff = static_cast<uf64>(Large_int::hex::_0xf);
		break;
	}
	return hex_digit;
}

void Large_int::set_chank(std::string::const_iterator begin, std::string::const_iterator end)
{
	uf64 block = 0x0ull;
	size_t shift = 64 - static_cast<size_t>(4); // Each hexadecimal digit takes 4 bits. So, we have to shift the buffer by four bits to the left each time 
	                                 //we translate hexadecimal digit into its binary representation.
	for (;begin != end; ++begin)
	{
		uf64 nymbl = 0x0ull;
		nymbl  |= hex_to_binary(*begin);
		nymbl <<= shift;
		block |= nymbl;
		shift -= static_cast<size_t>(4);
	}
	block &= static_cast<uf64>(0xffffffffffffffff);
	value_.push_back(block);
}
size_t chanks(const size_t size)
{
	const size_t nchanks = size / static_cast<size_t>(16);       // 16 is total ammount of hex digits(string symbols) 
	const size_t    tail = (size % static_cast<size_t>(16)) && 1; //is suetable to be placed into one variable of type uf64.
	return (nchanks + tail);
}

void Large_int::set_hex(const std::string& value)
{
	const size_t n_blocks = chanks(value.size());
	auto chank_start = value.begin();
	auto   chank_end = value.begin();
	for (size_t idx = 0, vector_size = n_blocks; idx < vector_size; ++idx)
	{
		std::string substr(value, static_cast<size_t>(idx * 16), static_cast<size_t>(16));
		chank_start = substr.begin();
		chank_end = substr.end();
	
		this->set_chank(chank_start, chank_end);
		
	}

}

std::ostream& operator <<(std::ostream& output, const Large_int& s)
{
	output << "0x";// << s.get_hex();
	for (const auto& block : s.value_)
	{
		output << std::hex << block;
	}
	return output;
}

int main()
{
	std::string v = "8e5a08b2701ab3fb4eb89427d82f3";
	Large_int ff;
	ff.set_hex(v);
	std::cout << ff << std::endl;
    


	return 0;
}