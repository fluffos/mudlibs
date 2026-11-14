// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/sys/object_stats.h
// Description:	Defines fuer die Object-Stats
// Author:	Garthan
//
// $Log: object_stats.h,v $
// Revision 1.2  2001/03/14 20:32:37  freaky
// CVS-log eingebaut.
//

#ifndef OBJECT_STATS_H
#define OBJECT_STATS_H 1

/* Object stats base types */

#define OS_WEAPON   1
#define OS_ARMOUR   2
#define OS_CLOTH    3
#define OS_NAHRUNG  4
#define OS_GETRAENK 5
#define OS_MONSTER  6
// insert here, change OS_MAX

#define OS_MAX      7


/* interna */

#define OS_FLAG_ROOMS 1
#define OS_FLAG_QUIET 2

#define OS_SAVE_FILENAME "/var/object_stats"
#define OS_OUTFILE "/var/OBJECT_STATS"
#define OS_SAVE_EVERY    100

#define OS_REF	 0
#define OS_STATS 1

#define OS_HEADERS \
([ OS_WEAPON : "name     \tweight\tv_min\tv_max\td_min\td_max\tlife\tclass\t\learn"; "Waffen",\
   OS_ARMOUR : "name     \tweight\tv_min\tv_max\tprot\tlife\tclass"; "Ruestungen",\
   OS_CLOTH  : "name     \tweight\tvalue\tschutz\ttyp"; "Kleidungen",\
   OS_NAHRUNG: "name     \tweight\tvalue\tamount\tdauer\theal";"Nahrung",\
   OS_GETRAENK: "name     \tweight\tvalue\tamount\tstr\theal\tin_pub";"Getraenk",\
   OS_MONSTER: "name     \tweight\thp\tsp\tarmour\talign\taggres\tstr\tint\tcon\tdex";"Monster",\
])

#endif // OBJECT_STATS_H
