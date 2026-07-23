/* This program is a part of RW mudlib
 * See /doc/help/copyright for more info
 -----------------------------------------
 * File   : eval.h
 * Author : Clode@RevivalWorld
 * Date   : 
 * Note   : INCLUDE file
 * Update :
 *  o 2000-00-00  
 *
 -----------------------------------------
 */

#include "location.h"

#define PRINT(x)	printf("%O\n", x)
#define write(x)	PRINT(x)

#define ME		this_player()
#define MY_ENV		environment(this_player())
#define MY_NAME		this_player()->query_idname()

#define USER(x)		find_player(x)
#define USER_ENV(x)	environment(find_player(x))
#define USER_NAME(x)	find_player(x)->query_idname()

#define ENV(x)		environment(x)

#define MY_LOC		query_temp("location", this_player())
#define MY_EAST_LOC	arrange_city_location(MY_LOC[X]+1, MY_LOC[Y], MY_LOC[CITY], MY_LOC[NUM])
#define MY_WEST_LOC	arrange_city_location(MY_LOC[X]-1, MY_LOC[Y], MY_LOC[CITY], MY_LOC[NUM])
#define MY_NORTH_LOC	arrange_city_location(MY_LOC[X], MY_LOC[Y]-1, MY_LOC[CITY], MY_LOC[NUM])
#define MY_SOUTH_LOC	arrange_city_location(MY_LOC[X], MY_LOC[Y]+1, MY_LOC[CITY], MY_LOC[NUM])
