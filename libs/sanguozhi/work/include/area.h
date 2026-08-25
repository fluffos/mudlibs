#ifndef __AREA_H__
#define __AREA_H__

// area.h by fire on July, 3, 1998
#define MAX_POPULATION5 400000
#define MAX_POPULATION4 200000
#define MAX_POPULATION3 100000
#define MAX_POPULATION2 10000
#define MAX_POPULATION1 10000
// the maxmum strage for one area
#define MAX_LOCALGOLD	500000
#define MAX_LOCALFOOD	5000000
#define MAX_LOCALSTUFF	500000
// AI here means area importance
#define AI_BALANCE 0
#define AI_INDUSTRY 1
#define AI_AGRICULTURE 2
#define AI_BUSINESS 3
#define AI_SAFE 4
#define AI_MILITARY 5
// ST means the status of this area
#define ST_NOOFFICER 0 //no officer here
#define ST_NORMAL 1   // in normal situation
#define ST_WAR 2   // IT'S IN WAR
#define ST_TRAIN 4 // in train
#define ST_MEETING 3 // it's in meeting

#endif // __AREA_H__
