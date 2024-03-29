#pragma once
#include <ios>
#include <string>
#include <future>
#include <iterator>
#include <utility>
#include <sstream>
#include <cstdint>
#include <vector>
#include <iostream>
#include <memory>


using ull  = unsigned long long;
using uf64 =      uint_fast64_t;
using uf8  =       uint_fast8_t;
using vit = std::vector<uf64>::iterator;

class Large_int
{
public:
	Large_int(): nymbl_front_pos(0), digits(0) {};
	Large_int(const std::string& hv);
	Large_int(const Large_int& other);

	//getter && setter methods
	void set_hex(const std::string& value);
		
	
	std::string get_hex() const;
	size_t get_digits() const;
	size_t get_value() const;
	size_t get_number_of_hex_digits() const;
	friend std::ostream& operator <<(std::ostream& output, const Large_int& s);
		

    // bitwice methods
	void operator~();
	friend Large_int operator~(const Large_int& largeInteger);
	Large_int operator^ (const  Large_int& r) const;
	Large_int operator| (const  Large_int& r) const;
	Large_int operator& (const  Large_int& r) const;
	Large_int operator<<(const size_t& shift) const;
	Large_int operator>>(const size_t& shift) const;

	Large_int& operator^= (const  Large_int& r);
	Large_int& operator|= (const  Large_int& r);
	Large_int& operator&= (const  Large_int& r);
	Large_int& operator<<=(const size_t& shift);
	Large_int& operator>>=(const size_t& shift);
	

	// arithmetic methods
	Large_int operator+(const Large_int& r) const;
	Large_int operator-(const Large_int& r) const;
	Large_int operator*(const Large_int& r) const;
	Large_int operator/(const Large_int& r) const;
	Large_int operator%(const Large_int& r) const;
	

	Large_int& operator+=(const Large_int& r);
	Large_int& operator-=(const Large_int& r);
	Large_int& operator*=(const Large_int& r);
	Large_int& operator/=(const Large_int& r);
	Large_int& operator%=(const Large_int& r);

	Large_int powmod(const Large_int& r, const size_t& mod) const;
private:
	std::vector<uf64> value_;
	size_t nymbl_front_pos;
	size_t digits;
	inline void set_digits(const std::string& hex_value);
	
	
	enum class hex
	{
		_0x0 = 0x0ull,
		_0x1 = 0x1ull,
		_0x2 = 0x2ull,
		_0x3 = 0x3ull,
		_0x4 = 0x4ull,
		_0x5 = 0x5ull,
		_0x6 = 0x6ull,
		_0x7 = 0x7ull,
		_0x8 = 0x8ull,
		_0x9 = 0x9ull,
		_0xa = 0xAull,
		_0xb = 0xBull,
		_0xc = 0xCull,
		_0xd = 0xDull,
		_0xe = 0xEull,
		_0xf = 0xFull
	};
	uf64 hex_to_binary(char hex_digit);
	size_t chanks(const size_t size);
	uf64 set_chank(std::string::const_iterator begin, std::string::const_iterator end);

	friend void fit_size(Large_int* const l, const size_t lsize, Large_int* const r, const size_t rsize);
	friend void elongate(Large_int* const n, size_t lesser, size_t bigger);
	friend void compare_size(Large_int* const l, Large_int* r);
};