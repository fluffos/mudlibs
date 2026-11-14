#ifndef _STATS_H
#define _STATS_H
/*
** File: /sys/stats.h
**
** (c) Softbyte@OSB 10nov97
** [Softbyte] 10nov97   : Creation and basic definitions
**
**
*/
#include "attributes.h"

//#define NO_OF_STATS      7    // So many general stats exist in OSB
// NUMBER_STATS  

#define STAT_AVERAGE    65    // Average stat a player shall have at setup
#define STAT_VARIANCE   30    // Variance of the stats around the average
#define STAT_MAX        99    // Maximum stat value allowed
#define STAT_MIN         0    // Minimum stat value allowed
// #define STAT_NAMES      ({"Con","Str","Int","Agi","Qui","Wis","Cha"})
// is STATS
#define STAT_SHIFT_NO   10    // So many shifts are allowed in char setup
#define STAT_SHIFT_AMT  4     // One shift will change by that amount (avg)


// Semistats
#define STAT_PEP_DEFAULT 10   // so many PEP will be tired by default
#define STAT_MEP_DEFAULT 10   // so many MEP will be tired by default

#endif /* _STATS_H */
