#include <windows.h>
#include <mysql.h>
#include "CasteVote.h"
#include "BlockChain.h"
#include "RSAalgorithm.h"
#include <string.h>
// #include <vector>
//#include "AppServerRSA.h"
using namespace std;

string data1;
MYSQL* conn;
MYSQL_RES* res;
MYSQL_ROW row;
string votes[100];
bool check;
string query;
int val, j=0;
Blockchain b1;


struct bInfo ServerInfo = b1.ReturnBlocks();
string id = to_string(ServerInfo.id);
string timestamp = ServerInfo.timestamp;
string information = ServerInfo.information;
string previoushash = ServerInfo.previoushash;
string currenthash = ServerInfo.hash;

void CasteVote(int key) {
	
	b1.addBlockToTheChain(Block(1, data1));
	fflush(stdin);
	cout << "Enter The Voter Name You want to vote " << flush;
	cin >> data1;
	cout << " . . . " << flush;

	cout << "You voted for " << data1 << endl;

	data1 = encrypt(key, data1);
	cout << "Encrypted"<<data1<<endl;


	 //encrypting the votes
	//b1.addBlockToTheChain(Block(2, "Data2"));
	//b1.DisplayBlocks();

	if (b1.isBlockValid())
	{
		cout << "Block is Valid" << endl;
	}
	else
	{
		cout << "Block is not Valid" << endl;
	}


	conn = mysql_init(0);
	conn = mysql_real_connect(conn, "localhost", "root", "", "votingserver", 0, NULL, 0);

	query = "insert into blockchain(id,timestamp,information,previousHash,currentHash) values('" + id + "','" + timestamp + "','" + data1 + "','" + previoushash + "','" + currenthash + "')";
	const char* q = query.c_str();

	if (conn)
	{
		val = mysql_query(conn, q);
		if (!val)
			cout << "Query executed" << endl;
		else
			cout << "Query unsuccessful" << mysql_error(conn) << endl;
	}
	else
	{
		cout << "Error" << endl;
	}



}



	
	


void DisplayVotes(int pr) {

	query = "select * from blockchain";
	const char *qB = query.c_str();
	if (conn)
	{
		val = mysql_query(conn, qB);
		cout << "Displaying";
	}
	else
	{
		cout << "Error";
	}

	if (!val)
	{
		res = mysql_store_result(conn);
		cout << "This step executed"<<endl;
		while (row = mysql_fetch_row(res))
		{
			//cout << row[2];
			cout << " . . . . . ";
			votes[j] = row[2];
			j++;
		}
		cout << "BeforeENcryption. . . "<<votes[j]<<endl;
		cout << decrypt(pr, votes[j]);
	}
	else {
		cout << "Error" << mysql_error(conn) << endl;
	}
}
