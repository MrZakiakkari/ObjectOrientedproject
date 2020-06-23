#pragma once 
using namespace std;
class CFootballTeam
{
	string m_Name;
	int m_GamesPlayed;
	int m_GoalsFor;
	int m_GoalsAgainst;
	int m_Points;
public:
	 CFootballTeam(void);
	 CFootballTeam(string name);
	 CFootballTeam(string name, int gamesPlayed, int goalsFor, int goalsAgainst, int points);
	string GetName();
	int GetGamesPlayed();
	int GetGoalsFor();
	int GetGoalsAgainst();
	int GetPoints();
	bool HasName(string searchname);
	void Display();
	void UpdateOnResult(int goalsfor, int goalsagainst);
	void DeductPoints(int num);
	bool IssLessThan(CFootballTeam& team);
};

