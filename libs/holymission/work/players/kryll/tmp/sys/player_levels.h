#ifndef __PLAYER_LEVEL_H__

#define __PLAYER_LEVEL_H__

// Prototypes:

nomask int set_level(int val);
nomask int add_exp(int val);
nomask int add_experience(int val);
nomask int query_has_been_here(string str);
void set_has_been_here(string str);
nomask int query_immortal();
nomask int query_newwiz();
nomask int query_wizard();
nomask int query_sage();
nomask int query_lord();
nomask int query_elder();
nomask int query_archwiz();
nomask int query_implementor();

// End prototypes.


// Global variables:

string         explored;            // alternative XP receiving

// End global variables.

#endif // __PLAYER_LEVEL_H__
