#include <iostream>
#include <string.h>
#include <windows.h>
#include <mysql.h>
#include "RSAalgorithm.h"
#include "CasteVote.h"
#include "BlockChain.h"



using namespace std;

int main() {
	MYSQL* connection;
	MYSQL_ROW row;
	MYSQL_RES* res;
	string query, id_Number, FirstName, LastName, a, b;
	int val;
	string messageForEncryption;
	string Emessage, Dmessage;
	struct keys k1;
	struct keys AppServer;
	int c;



	connection = mysql_init(0);
	connection = mysql_real_connect(connection, "localhost", "root", "", "applicationserver", 0, NULL, 0);
	cout << "Enter your Credentials in this Format , > Identification number , FirstName, LastName " << endl;
	cin >> id_Number >> FirstName >> LastName;
	query = "select * from credentials";
	const char* q = query.c_str();
	if (connection) {
		val = mysql_query(connection, q);
	}
	else {
		cout << "Error";
	}

	if (!val) {
		res = mysql_store_result(connection);
		while (row = mysql_fetch_row(res)) {
			if (row[0] == id_Number && row[1] == FirstName && row[2] == LastName) {  // Checking if credentials match on the database
				cout << "Credentials Matched Generating Ballot Id and your Keys" << endl;
				k1 = genKeys(); // generating private and public keys
				cout << "Your Private and Public keys are " << k1.pr1 << " and " << k1.pu1 << endl;
				a = to_string(k1.pr1);
				b = to_string(k1.pu1);
				// query = "DELETE FROM credentials where id_Number = '"+id_Number+"'";
				query = "UPDATE credentials SET Private_key = '" + a + "', Public_key = '" + b + "' WHERE id_Number = '" + id_Number + "'  ";
				const char* q = query.c_str();

				val = mysql_query(connection, q);
				if (!val) {
					cout << "Keys inserted successfully";

				}
				else {
					cout << "Error : " << mysql_error(connection) << endl;
				}
			}
		}
	}

	Emessage = encrypt(k1.pu1, FirstName);
	cout << Emessage << endl;
	cout << " and \n";
	Dmessage = decrypt(k1.pr1, Emessage);
	cout << Dmessage << flush;

	query = "INSERT INTO ballotid(ID,Public_key) values('" + Emessage + "','" + b + "') ";
	const char* v = query.c_str();
	if (!(mysql_query(connection, v))) {
		cout << "Inserted Successfully" << endl;
	}
	else {
		cout << "Error : " << mysql_error(connection);
	}

	AppServer = genKeys();

	cout << "Press 1 to Cast Vote and 0 to exit  " << endl;
	cin >> c;

	if (c) {
		CasteVote(AppServer.pu1);
	}
	else {
		cout << "err";
	}



	cout << "Want to see all the votes " << endl;
	DisplayVotes(AppServer.pr1);
	return 0;


}
