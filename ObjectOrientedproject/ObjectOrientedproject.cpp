// ObjectOrientedproject.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "CFootballTeam.h"
#include "CUser.h" 

using namespace std;
int N_users = 0;
const int max_N_teams = 25;
int N_teams = 10;
CFootballTeam league[25]; 
CUser Userlist[5];
void LoadUsersFromDatabase(void);
void SaveUsersFromDatabase(void);
void sort(void);

int  ShowApplicationManager(void); 
int  ShowApplicationAssisstant(void);
void DoInitialize (void); 
void DoDisplayLeague (void);  
void DoEnterMatchResult(void); 
void DoDeductPoints(void); 
void DoBestDefense(void); 
void DoRelegationZone(void); 
void DoAddTeamToList(void);
void DoQuit(void);

bool quitFlag = false;
int main()
{   
	LoadUsersFromDatabase();

	int option; 
	string name;
	string password;
	char userType;

	cout << "Enter your username: ";
	cin >> name;
	cout << "Enter your password: ";
	cin >> password;

	for (int i = 0; i < N_users; i++)
	{
		if (Userlist[i].HasLogIn(name, password))
		{
			userType = Userlist[i].HasType();
			break;
		}
	
	}

	if (userType == 'M')
	{
		do
		{
			option = ShowApplicationManager();
			switch (option)
			{

			case 0:
				DoInitialize();
				break;
			case 1:
				DoDisplayLeague();
				break;
			case 2:
				DoEnterMatchResult();
				break;
			case 3:
				DoDeductPoints();
				break;
			case 4:
				DoBestDefense();
				break;
			case 5:
				DoRelegationZone();
				break;
			case 6:
				DoAddTeamToList();
				break;
			case 7:
				DoQuit();
				break;
			default:
				cout << "invalid optio\n";
			}
		} while (!quitFlag);

	}
			
		
	
			
	if (userType == 'A')
	{
		do
		{
			option = ShowApplicationAssisstant();
			switch (option)
			{

			
				
		
			case 0:
				DoDisplayLeague();
				break;
			case 1:
				DoEnterMatchResult();
				break;
			case 2:
				DoDeductPoints();
				break;
			case 3:
				DoBestDefense();
				break;
			case 4:
				DoRelegationZone();
				break;
			
				
				
			case 5:
				DoQuit();
				break;
			default:
				cout << "invalid optio\n";
			}
		} while (!quitFlag);

		

			
	}
	//SaveUsersFromDatabase();
    return 0;
} 

void LoadUsersFromDatabase(void)
{
	ifstream infile("Users.dat");

	{
		string name, password; 
		char usertype ;  
		infile >> N_users;
		for (int i = 0; i < N_users; i++)
		{
			 
			infile >> name >> password >> usertype; 
			CUser user(name, password, usertype); 
			Userlist[i] = user;

		}




	}





}

void SaveUsersFromDatabase(void)
{
	if (N_users == 0)

		return;
	ofstream outfile("Users.dat");  

	outfile << N_users << endl;

	for (int i = 0; i < N_users; i++)


	{
		

		outfile << Userlist[i].GetName() << " " << Userlist[i].GetPassword() << "  " << Userlist[i].GetUserType() << "  " << endl;


	}

	outfile.close();





}




int ShowApplicationManager(void)
{
	int option; 

	cout << "\t0.             Initialize League Table\n"; 
	cout << "\t1.              Display League Table\n";
	cout << "\t2.              Enter a Match Result\n"; 
	cout << "\t3.               Deduct Points\n"; 
	cout << "\t4.               Best Defence\n"; 
	cout << "\t5.                Relegation Zone\n"; 
	cout << "\t6.                Add Team to list\n"; 
	cout << "\t7.                Quit\n"; 
	cout << "\t\t\t               Enter Option "; 
	cin >> option; 
	return option;

}

int ShowApplicationAssisstant(void)
{
	int option;

	
	cout << "\t0.              Display League Table\n";
	cout << "\t1.              Enter a Match Result\n";
	cout << "\t2.               Deduct Points\n";
	cout << "\t3.               Best Defence\n";
	cout << "\t4.                Relegation Zone\n";
	
	cout << "\t5.                Quit\n";
	cout << "\t\t\t               Enter Option ";
	cin >> option;
	return option;

}




void DoInitialize(void)
{
	cout << "enter number of teams in the league" << endl;
	int N;
	cin >> N;
	if (N <= max_N_teams)
	{
		N_teams = N;
		for (int i = 0; i < N_teams; i++)
		{
			string name;
			cout << "enter name of team " << (i + 1) << endl;

			cin >> name;
			CFootballTeam team(name);
			league[i] = team;
		}
	}
	else
	{
		cout << "Error: the number of temas in the league should not exceeds 25" << endl;
	}


}

void DoDisplayLeague(void)

{
	cout << "Displaying league table" << endl;
	cout << " Name " <<" GamesPlayed " <<" GoalsFor "<<" GoalsAgainst "<<" Points "<< endl;

	for (int i = 0; i < N_teams; i++)
	{
		league[i].Display();
	}


}

void DoEnterMatchResult(void)
{

	cout << "enter match results in the form: hometeam,homescore,awayteam,awayscore" << endl;
	string hometeam, awayteam;
	int homescore, awayscore;
	cin >> hometeam >> homescore >> awayteam >> awayscore;

	for (int i = 0; i < N_teams; i++)
	{
		if (league[i].HasName(hometeam))
			league[i].UpdateOnResult(homescore, awayscore);
		
			
				
	}  

	for (int i = 0; i < N_teams; i++)
	{
		if (league[i].HasName(awayteam))
			league[i].UpdateOnResult(awayscore, homescore);
	}
}

void DoDeductPoints(void)


{
	cout << "Enter team's name,points to be deducted" << endl;
	string name;
	int dpoints;
	cin >> name >> dpoints;

	for (int i = 0; i < N_teams; i++)

	{
		if (league[i].HasName(name))
			league[i].DeductPoints(dpoints);
	}


}

void DoBestDefense(void)
{

	int lowestgoalsagainst = 0;
	for (int i = 0; i < N_teams; i++)
	{

		if (league[i].GetGoalsAgainst() >= lowestgoalsagainst)


		{

			lowestgoalsagainst = league[i].GetGoalsAgainst();

		}


	}

	for (int i = 0; i < N_teams; i++)
	{
		if (league[i].GetGoalsAgainst() < lowestgoalsagainst)
		{

			cout << league[i].GetName() << "  " << league[i].GetGoalsAgainst();
		}
	}
}

void DoRelegationZone(void)
{
	for (int i = N_teams-3 ; i < N_teams; i++)
		cout << league[i].GetName() << " " << league[i].GetPoints() << " ";
}

void DoAddTeamToList(void)

{
	string name;
	cout << "Please enter the team's name:"; 
	cin >> name;
	CFootballTeam team(name);
	if (N_teams < max_N_teams)
	{
		league[N_teams] = team;

		N_teams++;
	}
	else
		cout << "Error: you exceded the maximum number of teams" << endl;


}



void DoQuit(void)

{

	quitFlag = true;;

}


