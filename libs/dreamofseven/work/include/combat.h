// combat.h

#ifndef __COMBAT__
#define __COMBAT__

//++ Shengsan@20030613 for New Setting
#define MAX_PPL_LEVEL		200	// 系統內定最大等級
#define MAX_PPL_ACTION_LEVEL	100	// 目前開放最大等級
//-- Shengsan@20030613 for New Setting

#define HITROLE	300
#define HITHEAVY 290
#define HITMISS	10
#define THACO	100
#define EXPCO	75
#define MAX_ENEMYS 10	//By Tmr;

#define TYPE_REGULAR	0
#define TYPE_RIPOSTE	1
#define TYPE_QUICK	2
#define TYPE_BERSERK	3
#define TYPE_HEAVY	4

#define RESULT_DODGE	-1
#define RESULT_PARRY	-2

// This is used as skill_power()'s argument to indicate which type of skill
// usage will be used in calculating skill power.
#define SKILL_USAGE_ATTACK		1
#define SKILL_USAGE_DEFENSE		2

#endif
