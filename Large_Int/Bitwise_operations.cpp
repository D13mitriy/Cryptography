#include "Large_Int.h"
#include <cstdio>
#include <bitset>


Large_int::Large_int(const Large_int& other) : nymbl_front_pos(other.nymbl_front_pos)
{
	value_ = other.value_;
}

// bitwice methods
//complement
Large_int operator~(const Large_int& largeInteger)//friend
{
	Large_int current(largeInteger);
	vit p = current.value_.begin(), q = current.value_.end();
	if (current.nymbl_front_pos)
	{
		(*p) = ~(*p);
		uf64 one = std::numeric_limits<uf64>::max();
		one >>= (current.nymbl_front_pos);
		(*p) &= one;
		++p;
	}
	for (; p != q; ++p)
	{
		(*p) = ~(*p);
	}
	return current;
}
void Large_int::operator~()//member
{
	vit p = this->value_.begin(), q = this->value_.end();
	if (this->nymbl_front_pos)
	{
		(*p) <<= ~(*p);
		uf64 one = std::numeric_limits<uf64>::max();
		one >>= (this->nymbl_front_pos);
		(*p) &= one;
		++p;
	}
	for (; p != q; ++p)
	{
		(*p) = ~(*p);
	}
}
//XOR
void elongate(Large_int* const n, size_t lesser, size_t bigger)
{
	size_t diff = bigger - lesser;
	while (diff)
	{
		n->value_.emplace(n->value_.begin(), uf64(0x0));
		--diff;
	}
    
}
void fit_size(Large_int * const l, size_t lsize,  Large_int * const r, size_t rsize)
{
	if (lsize < rsize)
	{
		elongate(l, lsize, rsize);
	}
	else if (rsize < lsize)
	{
		elongate(r, rsize, lsize);
	};
}

void compare_size(Large_int* const l, Large_int* r)
{
	size_t lsize = l->value_.size(), rsize = r->value_.size();
	if (lsize != rsize) { fit_size(l, lsize, r, rsize); }
}

Large_int Large_int::operator^ (const  Large_int& other) const
{
	Large_int * l = new Large_int(*this);
	Large_int * r = new Large_int(other);
	compare_size(l, r);

	vit lb = l->value_.begin(), le = l->value_.end();
	vit rb = r->value_.begin(), re = r->value_.end();
	
	for (; lb != le; ++lb)
	{
		*lb = (*lb) ^ (*rb);
	}	
	delete r;
	return *l;
}

Large_int Large_int::operator|(const  Large_int& other) const
{
	Large_int* l = new Large_int(*this);
	Large_int* r = new Large_int(other);
	compare_size(l, r);

	vit lb = l->value_.begin(), le = l->value_.end();
	vit rb = r->value_.begin(), re = r->value_.end();

	for (; lb != le; ++lb)
	{
		*lb = (*lb) | (*rb);
	}
	delete r;
	return *l;
}

Large_int Large_int::operator& (const  Large_int& other) const
{
	Large_int* l = new Large_int(*this);
	Large_int* r = new Large_int(other);
	compare_size(l, r);
	
	vit lb = l->value_.begin(), le = l->value_.end();
	vit rb = r->value_.begin(), re = r->value_.end();

	for (; lb != le; ++lb)
	{
		*lb = (*lb) & (*rb);
	}
	delete r;
	return *l;
}

Large_int Large_int::operator<<(const size_t& bit_shift) const
{
	std::unique_ptr<Large_int> l(new Large_int{ *this });
	size_t bit_size = (this->value_.size()) * 64;
	size_t isblock_shift = bit_shift % 64;
	size_t block_shift = bit_shift / 64;
	vit b = l->value_.begin(), e = l->value_.end(), next;

	if (bit_size <= bit_shift)
	{
		for (auto& block : (l->value_))
		{
			block = 0x0;
		}
	}
	else if(!isblock_shift)
	{
		

		for (; block_shift != 0;--block_shift)
		{
			l->value_.erase(b);
			l->value_.emplace_back(uf64(0x0));
		}
	}
	else
	{
		while (b != e)
		{
			(*b) <<= bit_shift;
			next = b + 1;
			if (next == e) { break; }
			uf64 tmp = (*next);			
			tmp  >>= (64 - bit_shift);
			(*b)  |= tmp;
			++b;
		}
	}
	
	
	return *l;
}
Large_int Large_int::operator>>(const size_t& bit_shift) const
{
	std::unique_ptr<Large_int> l(new Large_int{ *this });
	size_t bit_size = (this->value_.size()) * 64;
	size_t isblock_shift = bit_shift % 64;
	size_t block_shift = bit_shift / 64;
	vit b = l->value_.begin(), e = l->value_.end();

	if (bit_size <= bit_shift)
	{
		for (auto& block : (l->value_))
		{
			block = 0x0;
		}
	}
	else if (!isblock_shift)
	{


		for (; block_shift != 0; --block_shift)
		{
			l->value_.pop_back();
			l->value_.emplace(b, uf64(0x0));
		}
	}
	else
	{
		std::vector<uf64>::reverse_iterator rb = l->value_.rbegin(), re = l->value_.rend(), prev;
		while (b != e)
		{
			(*rb) >>= bit_shift;
			prev = rb + 1;
			if (prev == re) { break; }
			uf64 tmp = (*prev);
			tmp <<= (64 - bit_shift);
			(*rb) |= tmp;
			++b;
		}
	}


	return *l;
}
/*
Large_int& operator^= (const  Large_int& r);
Large_int& operator|= (const  Large_int& r);
Large_int& operator&= (const  Large_int& r);
Large_int& operator<<=(const size_t& shift);
Large_int& operator>>=(const size_t& shift);
*/
int main()
{
	std::string v = "b2701acfaef3fbfc4567b8a300526", x = "e035c6cfa42609b998b883bc1699df885cef74e2b2cc372eb8fa7e7";
	Large_int l1(v), l2(x);
	std::unique_ptr<Large_int> p({ new Large_int() });
	*p = l1 ^ l2;
	std::cout << *p << std::endl;

	return 0;
}