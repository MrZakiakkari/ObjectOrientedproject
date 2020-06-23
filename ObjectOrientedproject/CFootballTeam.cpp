#include "stdafx.h"
#include "CFootballTeam.h"

using namespace std;
CFootballTeam::CFootballTeam(void)
	:m_Name("")
	,m_GamesPlayed(0)
	, m_GoalsFor(0)
	, m_GoalsAgainst(0)
	, m_Points(0)
{
}


 CFootballTeam::CFootballTeam(string name)

	
	:m_Name(name)
		,m_GamesPlayed(0)
		, m_GoalsFor(0)
		, m_GoalsAgainst(0)
		, m_Points(0)
 {
}


 CFootballTeam::CFootballTeam(string name, int gamesPlayed, int goalsFor, int goalsAgainst, int points)
{
	m_Name = name;
	m_GamesPlayed = gamesPlayed;
	m_GoalsFor = goalsFor;
	m_GoalsAgainst = goalsAgainst;
	m_Points = points;
}


string CFootballTeam::GetName()
{
	return CFootballTeam::m_Name;
}


int CFootballTeam::GetGamesPlayed()
{
	return m_GamesPlayed=0;
}


int CFootballTeam::GetGoalsFor()
{
	return m_GoalsFor=0;
}


int CFootballTeam::GetGoalsAgainst()
{
	return m_GoalsAgainst=0;
}


int CFootballTeam::GetPoints()
{
	return m_Points=0;
}


bool CFootballTeam::HasName(string searchname)
{
	if (searchname == m_Name)
		return true;
	else
		return false;
}


void CFootballTeam::Display(void)
{ 
	cout <<"  "<< m_Name<< "         "<< m_GamesPlayed <<"           "<<  m_GoalsFor <<"           "
		  <<m_GoalsAgainst <<"          "<<   m_Points << endl;
}


void CFootballTeam::UpdateOnResult(int goalsfor, int goalsagainst)
{
	m_GoalsFor += goalsfor;
	m_GoalsAgainst += goalsagainst;

	if (goalsfor > goalsagainst)
		m_Points += 3;
	else
		if (goalsfor == goalsagainst)
			m_Points += 1;


}


void CFootballTeam::DeductPoints(int num)
{
	m_Points -= num;
}




/*/bool CFootballTeam::IssLessThan(CFootballTeam& team)
{
	if (m_Points < team.getpoints())
		return true;
	else
		if ((m_Points == team.getpoints()) && ((m_GoalsFor - m_GoalsAgainst) < (team.getgoalsfor - team.getgoalsagainst)))
			return true;
		else
			if ((m_Points == team.getpoints()) && ((m_GoalsFor - m_GoalsAgainst) == (team.getgoalsfor - team.getgoalsagainst)) && (m_GamesPlayed < team.getgamesplayed()))
				return true;
			else
				return false;
}
*/