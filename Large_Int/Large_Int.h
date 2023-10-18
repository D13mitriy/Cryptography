#pragma once
#include <cstdint>
#include <vector>
#include <iostream>

#define _0nybl(x)  ((x) & (0xfull)) /*1st nybl*/
#define _1nybl(x)  ((x) & (0xf0ull))/*2d nybl*/
#define _2nybl(x)  ((x) & (0xf00ull))/*3d nybl*/
#define _3nybl(x)  ((x) & (0xf000ull))/*4th nybl*/
#define _4nybl(x)  ((x) & (0xf0000ull))/*5th nybl*/
#define _5nybl(x)  ((x) & (0xf00000ull))/*6th nybl*/
#define _6nybl(x)  ((x) & (0xf000000ull))/*7th nybl*/
#define _7nybl(x)  ((x) & (0xf0000000ull))/*8th nybl*/
#define _8nybl(x)  ((x) & (0xf00000000ull))/*9th nybl*/
#define _9nybl(x)  ((x) & (0xf000000000ull))/*10th nybl*/
#define _10nybl(x) ((x) & (0xf0000000000ull))/*11th nybl*/
#define _11nybl(x) ((x) & (0xf00000000000ull))/*12th nybl*/
#define _12nybl(x) ((x) & (0xf000000000000ull))/*13th nybl*/
#define _13nybl(x) ((x) & (0xf0000000000000ull))/*14th nybl*/
#define _14nybl(x) ((x) & (0xf00000000000000ull))/*15th nybl*/
#define _15nybl(x) ((x) & (0xf000000000000000ull))/*16th nybl*/


enum hex
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

using ull  = unsigned long long;
using uf64 =      uint_fast64_t;
using uf8  =       uint_fast8_t;

#define nybl(x) ((x) & (0b1111))
#define shr4(x) ((x) >>= (4))
#define get4(x) (nybl(shr4(x)))

class Large_int
{
public:

	//getter && setter methods
	Large_int() {};
	Large_int(std::string value);
	void set_hex(std::string);
	void get_hex();
	void print_hex();
	void print_hexchar();

    // bitwice methods
	Large_int operator~() const;
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
	union Nybls
	{
		uf64 first : 4;
		uf64 other : 4;
		uf64 therd : 4;
		uf64 fourth : 4;
		uf64 fifth : 4;
		uf64 sixth : 4;
		uf64 seventh : 4;
		uf64 eighth : 4;
		uf64 ninth : 4;
		uf64 tenth : 4;
		uf64 eleventh : 4;
		uf64 twelfth : 4;
		uf64 thirteenth : 4;
		uf64 fourteenth : 4;
		uf64 fifteenth : 4;
		uf64 sixteenth : 4;

		Nybls(uf64 num)
		{
			sixteenth  = nybl(num);
			fifteenth  = get4(num);
			fourteenth = get4(num);
			thirteenth = get4(num);
			twelfth    = get4(num);
			eleventh   = get4(num);
			tenth      = get4(num);
			ninth	   = get4(num);
			eighth	   = get4(num);
			seventh	   = get4(num);
			sixth	   = get4(num);
			fifth	   = get4(num);
			fourth     = get4(num);
			therd      = get4(num);
			other	   = get4(num);
			first      = get4(num);
		}
	};





};