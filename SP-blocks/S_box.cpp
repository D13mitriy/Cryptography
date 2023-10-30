#include <stdint.h>
#include <cstdio>
#include <ios>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#define ROTL8(x,shift) ((uint8_t) ((x) << (shift)) | ((x) >> (8 - (shift))))

void initialize_sbox(uint8_t sbox[256]) {
	uint8_t p = 1, q = 1;

	/* loop invariant: p * q == 1 in the Galois field */
	do {
		/* multiply p by 3 */
		p = p ^ (p << 1) ^ (p & 0x80 ? 0x1B : 0);

		/* divide q by 3 (equals multiplication by 0xf6) */
		q ^= q << 1;
		q ^= q << 2;
		q ^= q << 4;
		q ^= q & 0x80 ? 0x09 : 0;

		/* compute the affine transformation */
		uint8_t xformed = q ^ ROTL8(q, 1) ^ ROTL8(q, 2) ^ ROTL8(q, 3) ^ ROTL8(q, 4);

		sbox[p] = xformed ^ 0x63;
	} while (p != 1);

	/* 0 is a special case since it has no inverse */
	sbox[0] = 0x63;
}

void initialize_inv_sbox(uint8_t inv_sbox[256])
{
	uint8_t p = 1, q = 1;
	do 
	{
		p = p ^ (p << 1) ^ (p & 0x80 ? 0x1B : 0);

		q ^= q << 2;

	} while (p != 1);
	inv_sbox[0] = 0x5;
}

void s_box_encription(const char* plain_text, uint8_t sbox[256], char * cipher)
{
	size_t p_size = strlen(plain_text), idx = 0;
	while (idx < p_size)
	{
		cipher[idx] = sbox[(uint8_t)plain_text[idx]];
		++idx;
	}
}

void s_box_decription(const char* cipher_text, uint8_t sbox[256], char* plain_text)
{
	std::unordered_map<uint8_t, uint8_t> s_box_map;
	size_t idx = 0, cipher_size = strlen(cipher_text);
	while (idx < 256)
	{
		s_box_map.insert({(uint8_t)sbox[idx], (uint8_t)idx});
		++idx;
	}
	for (idx = 0; idx < cipher_size; ++idx)
	{
		
		plain_text[idx] = (char)s_box_map.at((uint8_t)cipher_text[idx]);
	}
}

void print_cs(const char* cstring)
{
	while (*cstring != '\0')
	{
		std::cout  << *cstring;
		++cstring;
	}
	std::cout << "\n";
}

int main()
{
	uint8_t sb[256];
	initialize_sbox(sb);

	const char* myplaintext = "This is a string intended to be encripted and then decripted using forward substitution table s-box and inverse s-box table, respectivly.";
	unsigned int cipher_size = strlen(myplaintext);
	char* cipher = new char[cipher_size];
	char* plain = new char[cipher_size];
	s_box_encription(myplaintext, sb, cipher);
	print_cs(myplaintext);
	print_cs(cipher);
	s_box_decription(cipher, sb, plain);
	print_cs(plain);
	delete [] cipher;
	delete [] plain;
	return 0;
}