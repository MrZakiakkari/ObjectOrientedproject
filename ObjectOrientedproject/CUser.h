#pragma once 
using namespace std;
class CUser
{
public:
	CUser();
	~CUser();
	


private:
	string m_Name;
	string m_Password; 
	char m_UserType; 
public: 

	CUser(string name);

	CUser(string name, string password, char usertype);

	string GetName(void);
	string GetPassword(void);
	char GetUserType(void);

	bool HasLogIn(string name, string password);
	char HasType(void);

	void Display(void);




};