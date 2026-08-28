// file name   : /daemon/time.h
// description : header file for time daemon
// coders      : namhas, waster

#define MAXVERSECTOR 18
#define SUN_VERSECTORS 13
#define HORIZONTAL_SECTORS 16
#define PHASE_SECTOR (HORIZONTAL_SECTORS/8)
#define MOON1_NAME "Afay"
#define MOON2_NAME "Kizanth"
#define MOON3_NAME "Narcos"
#define MOON1_VERSECTORS 15
#define MOON2_VERSECTORS 12
#define MOON3_VERSECTORS 10
#define MOON1_VERMOD 0
#define MOON2_VERMOD -2
#define MOON3_VERMOD 1
#define MOON1_TIME_H 27360
// 19 Game Days
#define MOON2_TIME_H 53280
// 37 Game Days
#define MOON3_TIME_H 10080
// 7 Game Days
#define MOON1_TIME_V 15840
// 11 Game Days
#define MOON2_TIME_V 7200
// 5 Game Days
#define MOON3_TIME_V 4320
// 3 Game Day
#define FULL_MOON 0
#define WAINING_MOON 1
#define NEW_MOON 2
#define WAXING_MOON 3

#define MINUTES 60
#define HOURS 24
#define DAYS 28
#define MONTHS 8

#define GAME_MIN 2
#define GAME_HOUR (MINUTES*GAME_MIN)
#define GAME_DAY (HOURS*GAME_HOUR)
#define GAME_MONTH (DAYS*GAME_DAY)
#define GAME_YEAR (MONTHS*GAME_MONTH)
#define BIRTHDAY 868752530
