/*  -*- LPC -*-  */
#ifndef _RACE_H
#define _RACE_H
//
// race.h:  Header file for all race functions
//

/*
 * Returns the name of the race
 */
string query_race();

/*
 * Returns the base weight of the race's body
 */
int query_base_weight();

/* -------------------------- Combat Related ------------------------------- */

/*
 * The 'ID' of armours that can be worn.
 */
string *query_armour_types();

/*
 * Where the armours are worn
 * parallel to the above array
 */
string *query_armour_locations();

/*
 * returns ({ chance to hit mod(10 = 1%), damage mod })
 */
int *query_base_ac();

/*
 * The number of hands and therefore(?)
 * total number of weapons a race can wield
 */
int query_hands();

/*
 * First int is which 'hand pair' is being queried about, the 
 * second is 0 if raw score is wanted and 1 if skills for unarmed 
 * combat are to be added.  Modifiers are described within.
 * Humans have only one pair of hands, so the first int is 
 * ignored.
 */
varargs mixed *query_unarmed(int not_really_important,string wep_skill);

#endif /* _RACE_H */
