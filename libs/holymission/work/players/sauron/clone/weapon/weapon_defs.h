#ifndef __WEAPON_DEFS_H__
 
#define __WEAPON_DEFS_H__
 
#include <setlight.h>
#include <lw.h>
#include <obj_defs.h>
 
#pragma strict_types
 
#define STR     0x01
#define DEX     0x02
#define CON     0x04
#define INT     0x08
#define WIS     0x10
#define CHR     0x20
 
#define MAX_WEAP_CLASS  20
#define MAX_MAGIC_LVL   10
#define NO_OF_TYPES     7
#define NO_OF_KINDS     3
#define MAX_SIZE        6

#define MAX_NO_OF_SAVE  20 // Kryll: Check this figure.

#define MAX_CND        1600
#define MAGIC_CND      1000
#define CND_DIV        MAX_CND / 8

// Condition levels:
#define MAGICAL_CND     7
#define SUPER_CND       6
#define EXCELLENT_CND   5
#define FINE_CND        4
#define AVERAGE_CND     3
#define POOR_CND        2
#define VERY_POOR_CND   1
#define ABISMAL_CND     0

// Condition strings:
#define MAGICAL_MSG     "It is in much better shape than normal weapons.\n"
#define SUPER_MSG       "It is in superb condition.\n"
#define EXCELLENT_MSG   "It is in excellent condition.\n"
#define FINE_MSG        "It is in fine condition.\n"
#define AVERAGE_MSG     "It is in average condition.\n"
#define POOR_MSG        "It is in poor condition.\n"
#define VERY_POOR_MSG   "It is in very poor condition.\n"
#define ABISMAL_MSG     "It is in an abismally poor condition.\n"

#endif // __WEAPON_DEFS_H__
