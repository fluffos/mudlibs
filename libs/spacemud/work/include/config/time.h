/* Do not remove the headers from this file! see /USAGE for more info. */

// Automatically generated file, do not edit by hand. Use admtool.
#ifndef __TIME_H__
#define __TIME_H__

// Use game time? Will show in 'time' command for players.
// Default: yes
// Type: boolean
#define USE_GAME_TIME

// Days per week in the fictive world? Requires USE_GAME_TIME.
// Default: 7
// Range: 1-20
// Type: integer
#define DAYS_PER_WEEK 7

// Game days per day.  Requires USE_GAME_TIME.
// Default: 6
// Range: 1-10
// Type: integer
#define GAME_DAYS_PER_DAY 6

// Week begins on "monday". DAY_NAMES should correspond to your choice here.
// Default: yes
// Type: boolean
#define WEEK_BEGINS_MONDAY

// Name of the days (must have as many as days you defined). Requires USE_GAME_TIME.
// Default: Solday,Daybreak,Lightday,Dusktide,Shadowday,Emberday,Eventide
// Type: string
#define DAY_NAMES "Monday,Tuesday,Wednesday,Thursday,Friday,Saturday,Sunday"

// Add a number of hours to game time to better match real time or your TZ.
// Default: 0
// Range: -12-12
// Type: integer
#define ADJUST_HOURS 2


#endif /* __TIME_H__ */
