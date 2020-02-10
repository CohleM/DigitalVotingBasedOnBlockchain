#pragma once
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS

/*
First year project on Digital voting based on blockchain .

*/
#ifndef __BlockChain__included__
#define __BlockChain__included__



#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include "picosha2.h"

using namespace std;

class Blockchain;
// Creating a Block
struct bInfo {
	int id;
	string timestamp;
	string information;
	string previoushash;
	string hash;
};
class Block
{
	// later change this to private
public:
	int index;
	string timestamp;
	string information;
	string previousHash;
	string hash;

public:
	//Block constructor with parameter .
	Block(int id, string data);
	//setting time for timestamp of the block class
	string setTime();
	//Calculating the hash with the help of hasher function
	string hasher(const std::string& src);
};

class Blockchain
{
private:
	vector<Block> chain;

	Block createGenesisBlock();

public:
	Blockchain();
	Block getLatestBlock();

	void addBlockToTheChain(Block NewBlock);

	bool isBlockValid();

	//void DisplayBlocks();

   struct bInfo ReturnBlocks();
};
/*
int main()
{
	Blockchain b;
	b.addBlockToTheChain(Block(1, "Data1"));
	b.addBlockToTheChain(Block(2, "Data2"));
	b.DisplayBlocks();

	if (b.isBlockValid())
	{
		cout << "Block is Valid";
	}
	else
	{
		cout << "Block is not Valid";
	}
}
*/
#endif

