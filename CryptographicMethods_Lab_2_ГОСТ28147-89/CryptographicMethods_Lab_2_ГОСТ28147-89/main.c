#include <stdio.h>

typedef unsigned long u4;
typedef unsigned char byte;

typedef struct {
	u4 k[8];
	char k87[256], k65[256], k43[256], k21[256];
}gost_ctx;


void gost_enc(gost_ctx*, u4*, int);
void gost_dec(gost_ctx*, u4*, int);
void DevelopmentOfImitating(char*);
void EasyReplacementMode(void);
void gost_key(gost_ctx*, u4*);
void gost_destroy(gost_ctx*);
void ClosedLoopGauging(char*);
void gost_init(gost_ctx*);
void printMenu(void);
int actMenu(void);
void Gumming(void);


#ifdef _alpha
typedef unsigned int word32;
#else
typedef unsigned long word32;
#endif

int main() {
	int command;
	printf("%s", " -> my messages: hello world!\n");
	while ((command = actMenu()) != 5) {
		system("cls");
		switch (command)
		{
		case 1:
			EasyReplacementMode();
			break;
		case 2:
			Gumming("gumming!");
			break;
		case 3:
			ClosedLoopGauging("closed loop gauging!");
			break;
		case 4:
			DevelopmentOfImitating("development of imitating!");
			break;
		}
		printf("(Press any key)\n");
		getch();
		system("cls");
	}
	return 0;
}

void gostdecrypt(gost_ctx *c, u4 *d) {
	register word32 n1, n2;

	n1 = d[0];
	n2 = d[1];

	n2 ^= f(c, n1 + c->k[0]); n1 ^= f(c, n2 + c->k[1]);
	n2 ^= f(c, n1 + c->k[2]); n1 ^= f(c, n2 + c->k[3]);
	n2 ^= f(c, n1 + c->k[4]); n1 ^= f(c, n2 + c->k[5]);
	n2 ^= f(c, n1 + c->k[6]); n1 ^= f(c, n2 + c->k[7]);

	n2 ^= f(c, n1 + c->k[7]); n1 ^= f(c, n2 + c->k[6]);
	n2 ^= f(c, n1 + c->k[5]); n1 ^= f(c, n2 + c->k[4]);
	n2 ^= f(c, n1 + c->k[3]); n1 ^= f(c, n2 + c->k[2]);
	n2 ^= f(c, n1 + c->k[1]); n1 ^= f(c, n2 + c->k[0]);

	n2 ^= f(c, n1 + c->k[7]); n1 ^= f(c, n2 + c->k[6]);
	n2 ^= f(c, n1 + c->k[5]); n1 ^= f(c, n2 + c->k[4]);
	n2 ^= f(c, n1 + c->k[3]); n1 ^= f(c, n2 + c->k[2]);
	n2 ^= f(c, n1 + c->k[1]); n1 ^= f(c, n2 + c->k[0]);

	n2 ^= f(c, n1 + c->k[7]); n1 ^= f(c, n2 + c->k[6]);
	n2 ^= f(c, n1 + c->k[5]); n1 ^= f(c, n2 + c->k[4]);
	n2 ^= f(c, n1 + c->k[3]); n1 ^= f(c, n2 + c->k[2]);
	n2 ^= f(c, n1 + c->k[1]); n1 ^= f(c, n2 + c->k[0]);

	d[0] = n2; d[1] = n1;
}
void gostdecryptDI(gost_ctx *c, u4 *d) {
	register word32 n1, n2;

	n1 = d[0];
	n2 = d[1];

	n2 ^= f(c, n1 + c->k[0]); n1 ^= f(c, n2 + c->k[1]);
	n2 ^= f(c, n1 + c->k[2]); n1 ^= f(c, n2 + c->k[3]);
	n2 ^= f(c, n1 + c->k[4]); n1 ^= f(c, n2 + c->k[5]);
	n2 ^= f(c, n1 + c->k[6]); n1 ^= f(c, n2 + c->k[7]);

	n2 ^= f(c, n1 + c->k[7]); n1 ^= f(c, n2 + c->k[6]);
	n2 ^= f(c, n1 + c->k[5]); n1 ^= f(c, n2 + c->k[4]);
	n2 ^= f(c, n1 + c->k[3]); n1 ^= f(c, n2 + c->k[2]);
	n2 ^= f(c, n1 + c->k[1]); n1 ^= f(c, n2 + c->k[0]);

	n2 ^= f(c, n1 + c->k[7]); n1 ^= f(c, n2 + c->k[6]);
	n2 ^= f(c, n1 + c->k[5]); n1 ^= f(c, n2 + c->k[4]);
	n2 ^= f(c, n1 + c->k[3]); n1 ^= f(c, n2 + c->k[2]);
	n2 ^= f(c, n1 + c->k[1]); n1 ^= f(c, n2 + c->k[0]);

	n2 ^= f(c, n1 + c->k[7]); n1 ^= f(c, n2 + c->k[6]);
	n2 ^= f(c, n1 + c->k[5]); n1 ^= f(c, n2 + c->k[4]);
	n2 ^= f(c, n1 + c->k[3]); n1 ^= f(c, n2 + c->k[2]);
	n2 ^= f(c, n1 + c->k[1]); n1 ^= f(c, n2 + c->k[0]);

	d[0] = n2; d[1] = n1; d[2] = 0;
}
void gostcrypt(gost_ctx *c, word32 *d) {
	register word32 n1, n2;

	n1 = d[0];
	n2 = d[1];

	n2 ^= f(c, n1 + c->k[0]); n1 ^= f(c, n2 + c->k[1]);
	n2 ^= f(c, n1 + c->k[2]); n1 ^= f(c, n2 + c->k[3]);
	n2 ^= f(c, n1 + c->k[4]); n1 ^= f(c, n2 + c->k[5]);
	n2 ^= f(c, n1 + c->k[6]); n1 ^= f(c, n2 + c->k[7]);

	n2 ^= f(c, n1 + c->k[0]); n1 ^= f(c, n2 + c->k[1]);
	n2 ^= f(c, n1 + c->k[2]); n1 ^= f(c, n2 + c->k[3]);
	n2 ^= f(c, n1 + c->k[4]); n1 ^= f(c, n2 + c->k[5]);
	n2 ^= f(c, n1 + c->k[6]); n1 ^= f(c, n2 + c->k[7]);

	n2 ^= f(c, n1 + c->k[0]); n1 ^= f(c, n2 + c->k[1]);
	n2 ^= f(c, n1 + c->k[2]); n1 ^= f(c, n2 + c->k[3]);
	n2 ^= f(c, n1 + c->k[4]); n1 ^= f(c, n2 + c->k[5]);
	n2 ^= f(c, n1 + c->k[6]); n1 ^= f(c, n2 + c->k[7]);

	n2 ^= f(c, n1 + c->k[7]); n1 ^= f(c, n2 + c->k[6]);
	n2 ^= f(c, n1 + c->k[5]); n1 ^= f(c, n2 + c->k[4]);
	n2 ^= f(c, n1 + c->k[3]); n1 ^= f(c, n2 + c->k[2]);
	n2 ^= f(c, n1 + c->k[1]); n1 ^= f(c, n2 + c->k[0]);

	d[0] = n2; d[1] = n1;
}
void gostcryptG(gost_ctx *c, word32 *d) {
	register word32 n1, n2, c1, c2;

	n1 = d[0];
	n2 = d[1];
	c1 = 0x01010101;
	c2 = 0x01010104;

	n2 += c1; n1 += c2;
	n2 ^= f(c, n1 + c->k[0]); n1 ^= f(c, n2 + c->k[1]);
	n2 ^= f(c, n1 + c->k[2]); n1 ^= f(c, n2 + c->k[3]);
	n2 ^= f(c, n1 + c->k[4]); n1 ^= f(c, n2 + c->k[5]);
	n2 ^= f(c, n1 + c->k[6]); n1 ^= f(c, n2 + c->k[7]);

	n2 ^= f(c, n1 + c->k[0]); n1 ^= f(c, n2 + c->k[1]);
	n2 ^= f(c, n1 + c->k[2]); n1 ^= f(c, n2 + c->k[3]);
	n2 ^= f(c, n1 + c->k[4]); n1 ^= f(c, n2 + c->k[5]);
	n2 ^= f(c, n1 + c->k[6]); n1 ^= f(c, n2 + c->k[7]);

	n2 ^= f(c, n1 + c->k[0]); n1 ^= f(c, n2 + c->k[1]);
	n2 ^= f(c, n1 + c->k[2]); n1 ^= f(c, n2 + c->k[3]);
	n2 ^= f(c, n1 + c->k[4]); n1 ^= f(c, n2 + c->k[5]);
	n2 ^= f(c, n1 + c->k[6]); n1 ^= f(c, n2 + c->k[7]);

	n2 ^= f(c, n1 + c->k[7]); n1 ^= f(c, n2 + c->k[6]);
	n2 ^= f(c, n1 + c->k[5]); n1 ^= f(c, n2 + c->k[4]);
	n2 ^= f(c, n1 + c->k[3]); n1 ^= f(c, n2 + c->k[2]);
	n2 ^= f(c, n1 + c->k[1]); n1 ^= f(c, n2 + c->k[0]);

	d[0] = n2; d[1] = n1;
}
void gostcryptDI(gost_ctx *c, word32 *d) {
	register word32 n1, n2;

	n1 = d[0];
	n2 = d[1];

	n2 ^= f(c, n1 + c->k[0]); n1 ^= f(c, n2 + c->k[1]);
	n2 ^= f(c, n1 + c->k[2]); n1 ^= f(c, n2 + c->k[3]);
	n2 ^= f(c, n1 + c->k[4]); n1 ^= f(c, n2 + c->k[5]);
	n2 ^= f(c, n1 + c->k[6]); n1 ^= f(c, n2 + c->k[7]);

	n2 ^= f(c, n1 + c->k[0]); n1 ^= f(c, n2 + c->k[1]);
	n2 ^= f(c, n1 + c->k[2]); n1 ^= f(c, n2 + c->k[3]);
	n2 ^= f(c, n1 + c->k[4]); n1 ^= f(c, n2 + c->k[5]);
	n2 ^= f(c, n1 + c->k[6]); n1 ^= f(c, n2 + c->k[7]);

	n2 ^= f(c, n1 + c->k[0]); n1 ^= f(c, n2 + c->k[1]);
	n2 ^= f(c, n1 + c->k[2]); n1 ^= f(c, n2 + c->k[3]);
	n2 ^= f(c, n1 + c->k[4]); n1 ^= f(c, n2 + c->k[5]);
	n2 ^= f(c, n1 + c->k[6]); n1 ^= f(c, n2 + c->k[7]);

	n2 ^= f(c, n1 + c->k[7]); n1 ^= f(c, n2 + c->k[6]);
	n2 ^= f(c, n1 + c->k[5]); n1 ^= f(c, n2 + c->k[4]);
	n2 ^= f(c, n1 + c->k[3]); n1 ^= f(c, n2 + c->k[2]);
	n2 ^= f(c, n1 + c->k[1]); n1 ^= f(c, n2 + c->k[0]);

	d[0] = n2; d[1] = n1;
}
void gost_enc(gost_ctx *c, u4 *d, int blocks) {
	int i;

	for (i = 0; i < blocks; ++i) {
		gostcrypt(c, d);
		d += 2;
	}
}
void gost_dec(gost_ctx *c, u4 *d, int blocks) {
	int i;

	for (i = 0; i < blocks; ++i) {
		gostdecrypt(c, d);
		d += 2;
	}
}
static word32 f(gost_ctx *c, word32 x) {
	x = c->k87[x >> 24 & 255] << 24 | c->k65[x >> 16 & 255] << 16 | c->k43[x >> 8 & 255] << 8 | c->k21[x & 255];
	return x << 11 | x >> (32 - 11);
}
void sum2(char* a, char* b) {
	int i, k;
	for (i = k = 0; i < 12; ++i, k += i * 2) {
		int x = a[i];
		x += k;
		printf("%c", x);
	}
	for (i = k = 0; i < 12; ++i, k += i * 2) {
		int x = a[i];
		x += k;
		printf("%c", x);
	}
	printf("\n");
	return;
}
void gost_key(gost_ctx *c, u4 *k) {
	int i;
	for (i = 0; i < 8; ++i)
		c->k[i] = k[i];
}
void DevelopmentOfImitating(char* mes) {
	system("cls");
	gost_ctx gc;
	u4 k[8], data[10], sync[2], gamma[2];
	int i;
	for (i = 0; i < 8; ++i)
		k[i] = i;
	gost_init(&gc);//зап.табл.замен
	gost_key(&gc, k);//зап.ключ
	printf(" >data(64): %08lx %08lx\n", data[0] = 0x00000000, data[1] = 0x00000000);
	gostcryptDI(&gc, data);
	data[0] ^= 0x00000000; 
	data[1] ^= 0x00000000;
	gostcryptDI(&gc, data);
	data[2] = data[1] - 0x00000100;
	printf("   >cipher_text: %08lx %08lx %08lx\n", data[0], data[1], data[2]);
	gostdecryptDI(&gc, data);
	gostdecryptDI(&gc, data);
	printf("   >decoding: %08lx %08lx %08lx\n\n", data[0], data[1], data[2]);
	printf(" >data(64): %08lx %08lx\n", data[0] = 0xffffffff, data[1] = 0xffffffff);
	gostcryptDI(&gc, data);
	data[0] ^= 0x00000000;
	data[1] ^= 0x00000000;
	gostcryptDI(&gc, data);
	data[2] = data[1] - 0x00000100;
	printf("   >cipher_text: %08lx %08lx %08lx\n", data[0], data[1], data[2]);
	gostdecryptDI(&gc, data);
	gostdecryptDI(&gc, data);
	data[2] = data[1] + 0x00000000;
	printf("   >decoding: %08lx %08lx %08lx\n", data[0], data[1], data[2]);
	printf(" >mes: %s\n", mes);
	sum2(mes, gamma);
	gost_destroy(&gc);
}
void gost_destroy(gost_ctx *c) {
	int i;
	for (i = 0; i < 8; ++i) c->k[i] = 0;
}
void EasyReplacementMode(void) {
	system("cls");
	gost_ctx gc;
	u4 k[8], data[10];
	char qwe[10] = "dima314159";
	int i;
	for (i = 0; i < 8; ++i)
		k[i] = i;
	gost_init(&gc);//зап.табл.замен
	gost_key(&gc, k);//зап.ключ
	printf(" >befor: %08lx %08lx\n", data[0] = 0x00000000, data[1] = 0x00000000);
	gostcrypt(&gc, data);
	printf("   >after: %08lx %08lx\n", data[0], data[1]);
	printf(" >befor: %08lx %08lx\n", data[0] = 0xffffffff, data[1] = 0xffffffff);
	gostcrypt(&gc, data);
	printf("   >after: %08lx %08lx\n\n\n", data[0], data[1]);
	printf(" > ");
	for (i = 0; i < 10; ++i) {
		data[i] = (u4)qwe[i];
		printf("%c", data[i]);
	}
	printf("\n\n");
	for (i = 0; i < 10; i += 2)
		printf("Block %d = %c %c\n", i / 2, data[i], data[i + 1]);
	printf("\n");
	for (i = 0; i < 10; i += 2)
		printf("Block %d = %08d %08d\n", i / 2, data[i], data[i + 1]);
	printf("\n");
	gost_enc(&gc, data, 5);
	for (i = 0; i < 10; i += 2)
		printf("Block %d = %08lx %08lx\n", i / 2, data[i], data[i + 1]);
	gost_dec(&gc, data, 1);
	gost_dec(&gc, data + 2, 4);
	printf("\n");
	for (i = 0; i < 10; i += 2)
		printf("Block %d = %c %c\n", i / 2, data[i], data[i + 1]);
	gost_destroy(&gc);
}	 
void ClosedLoopGauging(char* mes) {
	system("cls");
	gost_ctx gc;
	u4 k[8], data[10], sync[2], gamma[2];
	int i;
	for (i = 0; i < 8; ++i)
		k[i] = i;
	gost_init(&gc);//зап.табл.замен
	gost_key(&gc, k);//зап.ключ
	sync[0] = sync[1] = 0;
	gostcrypt(&gc, sync);
	printf(" >sync: %08lx %08lx\n", sync[0], sync[1]);
	gamma[0] = sync[0];
	gamma[1] = sync[1];
	gostcrypt(&gc, gamma);
	printf(" >gamma(64): %08lx %08lx\n\n", gamma[0], gamma[1]);
	printf(" >data(64): %08lx %08lx\n", data[0] = 0x00000000, data[1] = 0x00000000);
	printf("   >cipher_text: %08lx %08lx\n", data[0] ^= gamma[0], data[1] ^= gamma[1]);
	printf("   >decoding: %08lx %08lx\n\n", data[0] ^= gamma[0], data[1] ^= gamma[1]);
	printf(" >data(64): %08lx %08lx\n", data[0] = 0xffffffff, data[1] = 0xffffffff);
	printf("   >cipher_text: %08lx %08lx\n", data[0] ^= gamma[0], data[1] ^= gamma[1]);
	printf("   >decoding: %08lx %08lx\n", data[0] ^= gamma[0], data[1] ^= gamma[1]);
	printf(" >mes: %s\n", mes);
	sum2(mes, gamma);
	gost_destroy(&gc);
}
void gost_init(gost_ctx *c) {
	int i;
	byte k8[16] = { 2, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7 };
	byte k7[16] = { 15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10 };
	byte k6[16] = { 10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8 };
	byte k5[16] = { 7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15 };
	byte k4[16] = { 2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9 };
	byte k3[16] = { 12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11 };
	byte k2[16] = { 4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1 };
	byte k1[16] = { 13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7 };
	for (i = 0; i < 256; ++i) {
		c->k87[i] = k8[i >> 4] << 4 | k7[i & 15];
		c->k65[i] = k6[i >> 4] << 4 | k5[i & 15];
		c->k43[i] = k4[i >> 4] << 4 | k3[i & 15];
		c->k21[i] = k2[i >> 4] << 4 | k1[i & 15];
	}
}
void printMenu(void) {
	printf("\t\t------GOST 28147-89------\n\t(Algorithm of cryptographic transformation)\n\n");
	printf(" 1> Easy replacement mode\n 2> Gamma Mode\n 3> The mode of gumming with feedback\n 4> Simulation mode\n\n 5> Exit\n");
}

void Gumming(char* mes) {
	system("cls");
	gost_ctx gc;
	u4 k[8], data[10], sync[2], gamma[2];
	int i, j;
	for (i = 0; i < 8; ++i)
		k[i] = i;
	gost_init(&gc);//зап.табл.замен
	gost_key(&gc, k);//зап.ключ
	sync[0] = sync[1] = 0;
	gostcrypt(&gc, sync);
	printf(" >sync: %08lx %08lx\n", sync[0], sync[1]);
	gamma[0] = sync[0];
	gamma[1] = sync[1];
	gostcryptG(&gc, gamma);
	printf(" >gamma(64): %08lx %08lx\n\n",gamma[0], gamma[1]);
	printf(" >data(64): %08lx %08lx\n", data[0] = 0x00000000, data[1] = 0x00000000);
	printf("   >cipher_text: %08lx %08lx\n", data[0] ^= gamma[0], data[1] ^= gamma[1]);
	printf("   >decoding: %08lx %08lx\n\n", data[0] ^= gamma[0], data[1] ^= gamma[1]);
	printf(" >data(64): %08lx %08lx\n", data[0] = 0xffffffff, data[1] = 0xffffffff);
	printf("   >cipher_text: %08lx %08lx\n", data[0] ^= gamma[0], data[1] ^= gamma[1]);
	printf("   >decoding: %08lx %08lx\n", data[0] ^= gamma[0], data[1] ^= gamma[1]);

	printf(" >mes: %s\n", mes);
	sum2(mes, gamma);
	gost_destroy(&gc);
}
int actMenu(void) {
	char command;
	while (1) {
		printMenu();
		command = getch();
		if (command > '0' && command < '6')
			return command - '0';
		system("cls");
		printf("\n >Invalid command. Press any key\n");
		getch();
		system("cls");
	}
}



