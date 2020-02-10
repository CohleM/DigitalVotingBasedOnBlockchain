
/*
 * C++ Program to Implement the RSA Algorithm
 */
#include <iostream>
#include <math.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include "RSAalgorithm.h"

using namespace std;



long int p, q, n, t, flag, e[100], d[100], temp[100], j, m[100], en[100], i, flag1, flag2;
string msg;
int prime(long int);
long int cd(long int);
string encrypt(int Ke, string message);
string decrypt(int ke, string message);
struct keys genKeys();

int random() {
	return rand() % 100 + 1;
}
int prime(long int pr)
{
	int i;
	j = sqrt(pr);
	for (i = 2; i <= j; i++)
	{
		if (pr % i == 0)
			return 0;
	}
	return 1;
}
void selectPandQ()
{
	p = random();
	q = random();
	flag1 = prime(p); //

	flag2 = prime(q);
	if (flag1 == 0 || flag2 == 0 || p == q)
	{
		selectPandQ();
	}

}


void start()
{
	genKeys();
}

void mess() {
	cout << "\nENTER MESSAGE\n";
	fflush(stdin);
	getline(cin, msg);
	//cin >> msg;
	for (i = 0; msg[i] != '\0'; i++)
		m[i] = msg[i];
}
keys genKeys()
{
	struct keys TheKeys;
	selectPandQ();
	n = p * q;
	t = (p - 1) * (q - 1);
	int k;
	k = 0;
	for (i = 2; i < t; i++)
	{
		if (t % i == 0)
			continue;
		flag = prime(i);
		if (flag == 1 && i != p && i != q)
		{
			e[k] = i;
			flag = cd(e[k]);
			if (flag > 0)
			{
				d[k] = flag;
				k++;
			}
			if (k == 99)
				break;
		}
	}
	TheKeys.pr1 = e[0];
	TheKeys.pu1 = d[0];
	return TheKeys;
}
long int cd(long int x)
{
	long int k = 1;
	while (1)
	{
		k = k + t;
		if (k % x == 0)
			return (k / x);
	}
}
string encrypt(int Ke, string message)
{
	long int pt, ct, key = Ke, k, len;
	i = 0;
	len = message.length() + 2;
	char enc[100];
	while (i != len)
	{
		pt = message[i];
		pt = pt - 96;
		k = 1;
		for (j = 0; j < key; j++)
		{
			k = k * pt;
			k = k % n;
		}
		temp[i] = k;
		ct = k + 96;
		en[i] = ct;
		i++;
	}
	en[i] = -1;
	// cout << "\nTHE ENCRYPTED MESSAGE IS\n";
	for (i = 0; en[i] != -1; i++)
	{
		enc[i] = en[i];
		//  cout << enc;
	}
	return enc;
}
string decrypt(int ke, string message)
{
	char dec[100];
	long int pt, ct, key = ke, k;
	i = -1;
	while (en[i] != -1)
	{
		ct = temp[i];
		k = 1;
		for (j = 0; j < key; j++)
		{
			k = k * ct;
			k = k % n;
		}
		pt = k + 96;
		message[i] = pt;
		i++;
	}
	message[i] = -1;
	//  cout << "\nTHE DECRYPTED MESSAGE IS\n";
	for (i = 0; message[i] != -1; i++)
	{
		dec[i] = message[i];
		// cout << dec[i];
		// cout << dec[i];
		//cout << dec;

	}
	return dec;
}
