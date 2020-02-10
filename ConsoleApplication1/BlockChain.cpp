/*
First year project on Digital voting based on blockchain .

*/

#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include "picosha2.h"
#include "Blockchain.h"


using namespace std;

// Creating a Block

	//Block constructor with parameter .
Block::Block(int id, string data)
{
	index = id;
	timestamp = setTime();
	information = data;
	hash = hasher(to_string(index) + timestamp + information + previousHash);
}
//setting time for timestamp of the block class
string Block::setTime()
{
	time_t currentTime = time(0);
	char* dt = ctime(&currentTime);
	return dt;
}
//Calculating the hash with the help of hasher function
string Block::hasher(const std::string & src)
{
	return picosha2::hash256_hex_string(src);
}



Block Blockchain::createGenesisBlock()
{
	Block genesis(0, "data");
	genesis.previousHash = "Nothing";
	return genesis;
}
Blockchain::Blockchain()
{
	chain.push_back(createGenesisBlock());
}

Block Blockchain::getLatestBlock()
{
	return chain[chain.size() - 1];
}

void Blockchain::addBlockToTheChain(Block NewBlock)
{
	NewBlock.previousHash = getLatestBlock().hash;
	chain.push_back(NewBlock);
}

bool Blockchain::isBlockValid()
{
	unsigned int j;
	for (unsigned int i = 1; i < chain.size(); i++)
	{
		j = i - 1;
		Block currentBlock = chain[i];
		Block previousBlock = chain[j];
		if (currentBlock.previousHash != previousBlock.hash)
		{
			return false;
		}
		return true;
	}
}

   struct bInfo Blockchain::ReturnBlocks()
{
	struct bInfo infos; //blockchain infos
	infos.id = chain[chain.size() - 1].index;
	infos.timestamp = chain[chain.size() - 1].timestamp;
	infos.information = chain[chain.size() - 1].information;
	infos.previoushash = chain[chain.size() - 1].previousHash;
	infos.hash = chain[chain.size() - 1].hash;
	return infos;
}

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
