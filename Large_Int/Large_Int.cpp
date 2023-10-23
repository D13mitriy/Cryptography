#include "Large_Int.h"


#define  NYBL_SIZE 4ull
#define BLOCK_SIZE 16ull

Large_int::Large_int(const std::string& hv)
{
	set_hex(hv);
}


inline void Large_int::set_digits(const std::string & hex_val)
{
	digits = hex_val.length();
}

size_t Large_int::get_number_of_hex_digits() const
{
	size_t v_size = this->value_.size() - 1;
	v_size = (v_size * 16) + (16 - nymbl_front_pos);
	return v_size;
}

size_t Large_int::get_digits() const
{
	return this->digits;
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

uf64 Large_int::set_chank(std::string::const_iterator begin, std::string::const_iterator end)
{
	uf64 block = 0x0ull;
	for (; begin != end; ++begin)
	{
		block <<= NYBL_SIZE;
		uf64 nymbl = 0x0ull;
		nymbl  |= hex_to_binary(*begin);
		block |= nymbl;
	}
	return block;
}
size_t Large_int::chanks(const size_t size)
{
	const size_t nchanks = size / static_cast<size_t>(16);       // 16 is total ammount of hex digits(string symbols) 
	const size_t    tail = (size % static_cast<size_t>(16)); //is suetable to be placed into one variable of type uf64.
	this->nymbl_front_pos = 16 - tail;
	const size_t t = tail && 1;
	return (nchanks + t);
}

void Large_int::set_hex(const std::string& value)
{
	set_digits(value);
	const size_t n_blocks = chanks(value.size());
	value_.resize(n_blocks);
	using const_it = std::string::const_iterator;
	auto hex_rbegin  = value.rbegin();
	auto hex_rend    =   value.rend();
	
	for (size_t idx = 0, vector_size = n_blocks; idx < vector_size; ++idx)
	{
			const_it chank_start = hex_rend.base();
			const_it chank_end = hex_rbegin.base();
			if (!(static_cast<ull>(std::distance(chank_start, chank_end)) < BLOCK_SIZE))
			{
				chank_start = chank_end - BLOCK_SIZE;
				hex_rbegin += BLOCK_SIZE;
			} 

			value_[vector_size - 1 - idx]=this->set_chank(chank_start, chank_end);
	}
}

std::ostream& operator<<(std::ostream& output, const Large_int& s)
{
	output << "0x";
	for (const auto& block : s.value_)
	{
		output << std::hex << block;
	}
	return output;
}

std::string Large_int::get_hex() const
{
	std::ostringstream result;
	result << *this;
	std::stringbuf* sb = result.rdbuf();
	return sb->str();
}
void rprint(const std::string& s)
{
	std::string::const_reverse_iterator rb = s.rbegin();
	std::string::const_reverse_iterator re = s.rend();


	while (rb != re)
	{
		std::cout << *rb;
		++rb;
	}
	std::cout << std::endl;
}



/*
int main()
{
	std::cout << sizeof(size_t) << "\n";
	size_t v1 = 0xffffffffffffffff;
	printf("%zu", v1);
	std::string v = "b2701acfaef3fbfc4567b8a300526", x = "e035c6cfa42609b998b883bc1699df885cef74e2b2cc372eb8fa7e7";
	Large_int dd(x);
	Large_int ff;
	ff.set_hex(v);

	std::cout << "v:" << ff << "\n"; std::cout << std::dec << "digits:" << ff.get_digits() << "\t" << "digits_calculated:" << ff.get_number_of_hex_digits() << std::endl;
	std::cout << "x:" << dd << "\n"; std::cout << std::dec << "digits:" << dd.get_digits() << "\t" << "digits_calculated:" << dd.get_number_of_hex_digits() << std::endl;
	
	
	rprint(ff.get_hex());
	rprint(dd.get_hex());
	
	
	return 0;
}
*/