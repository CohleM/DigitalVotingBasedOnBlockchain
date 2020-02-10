#pragma once

#ifndef __RSAalgorithm__inclue__
#define __RSAalgorithm__inclue__

struct keys
{
	int pr1;
	int pu1;
};
int prime(long int);
void ce();
long int cd(long int);
std::string encrypt(int Ke, std::string message);
std::string decrypt(int ke, std::string message);
int prime(long int pr);
void start();
struct keys genKeys();

#endif // __RSAalgorithm__inclue__

