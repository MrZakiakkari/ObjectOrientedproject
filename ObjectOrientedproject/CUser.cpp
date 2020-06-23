#include "stdafx.h"
#include "CUser.h"
using namespace std; 





CUser::CUser() 
{} 

CUser::~CUser() 
{}

CUser::CUser(string name) 
	:m_Name(name)
	,m_Password()
	,m_UserType()

{
}


CUser::CUser(string name, string password, char usertype)
{ 
	m_Name = name; 
	m_Password = password;
	m_UserType = usertype;
}

string CUser::GetName(void)
{
	return m_Name;

}


string CUser::GetPassword(void)

{
	return m_Password;

}

char CUser::GetUserType(void)


{

	return m_UserType;

}






bool CUser::HasLogIn(string name, string password)
{
	if (name == m_Name && password == m_Password)



		return true;
	return false;
}
	char CUser::HasType(void)
	{
		return m_UserType;

}


	void CUser::Display(void)
	{

		cout << m_Name << m_Password << m_UserType << endl;



	}