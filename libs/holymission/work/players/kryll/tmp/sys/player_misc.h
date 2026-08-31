#ifndef __PLAYER_MISC_H__

#define __PLAYER_MISC_H__
#define DIRECTIONS ({ "north", "northeast", "east", "southeast", "south", \
                      "southwest", "west", "northwest", "up", "down", \
                      "out", "enter" })

// Prototypes:

nomask int query_balance();
nomask void set_balance(int val);
nomask void add_balance(int val);
nomask string query_wimpydir();
int check_wimpy(object attacker_ob);
nosave int in_room(string str);
nomask nosave void set_wimpydir(string str);

// End prototypes.


// Global variables:

int bank_balance;

// End global variables.

#endif // __PLAYER_MISC_H__
