#ifndef CRUDETIMER_H
#define CRUDETIMER_H
#include<sys/time.h>
#include<iostream>
#define Clock CrudeTimer::Instance()
unsigned int timeGetTime();
class CrudeTimer{
	double m_dStartTime;
	CrudeTimer(){m_dStartTime = timeGetTime()*0.001;}

	CrudeTimer(const CrudeTimer&);
	CrudeTimer*operator=(const CrudeTimer&);
public:
	static CrudeTimer*Instance();
	double GetCurrentTime(){return timeGetTime()*0.001 - m_dStartTime;}

};
#endif//CRUDETIMER_H
