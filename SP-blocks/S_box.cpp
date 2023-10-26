/*#include <stdint.h>
#include <cstdio>
#include <ios>
#include <iostream>

#define ROTL8(x,shift) ((uint8_t) ((x) << (shift)) | ((x) >> (8 - (shift))))

void initialize_aes_sbox(uint8_t sbox[256]) {
	uint8_t p = 1, q = 1;

	/* loop invariant: p * q == 1 in the Galois field *//*
	do {
		/* multiply p by 3 *//*
		p = p ^ (p << 1) ^ (p & 0x80 ? 0x1B : 0);

		/* divide q by 3 (equals multiplication by 0xf6) *//*
		q ^= q << 1;
		q ^= q << 2;
		q ^= q << 4;
		q ^= q & 0x80 ? 0x09 : 0;

		/* compute the affine transformation *//*
		uint8_t xformed = q ^ ROTL8(q, 1) ^ ROTL8(q, 2) ^ ROTL8(q, 3) ^ ROTL8(q, 4);

		sbox[p] = xformed ^ 0x63;
	} while (p != 1);

	/* 0 is a special case since it has no inverse */
	/*sbox[0] = 0x63;
}


int main()
{
	uint8_t sb[256];
	initialize_aes_sbox(sb);

	//printf("%u", sb[44]);

	for (size_t idx = 0; idx < 256; ++idx)
	{
		if (idx % 16 == 0) { std::cout << "\n"; }
		std::cout << static_cast<uint16_t>(sb[idx]) << " ";//printf("%u ", sb[idx]);
		
	}
	return 0;
}*/