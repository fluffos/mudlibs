#ifndef __PLAYER_CONDITION_H__

#define __PLAYER_CONDITION_H__

// Prototypes:

nomask int query_invis();
int query_vis();
nomask int query_earmuff_level();
nomask int listen_shout(string str);
nomask int test_darkness();
nomask int test_dark();
nomask int add_weight(int val);
nomask void add_intoxication(int val);
nomask void add_stuffed(int val);
nomask void add_soaked(int val);
nomask void add_poison(int val);
nomask int query_intoxication();
nomask int query_stuffed();
nomask int query_soaked();
nomask int query_poisoned();
nomask string is_hunted_by();
int drink_alcohol(int val);
int drink_alco(int val);
int drink_soft(int val);
int eat_food(int val);
nomask void set_invis(int val);
void set_vis();

// End prototypes.


// Global variables:

int            headache;      //
int            intoxicated;   // How many ticks to stay intoxicated
int            max_headache;  //
int            poisoned;      // How many ticks to stay poisoned
int            soaked;        // How many ticks to stay soaked
int            stuffed;       // How many ticks to stay stuffed

nosave int earmuff_level;     // the level to which earmuffs are set

// End global variables.

#endif // __PLAYER_CONDITION_H__

