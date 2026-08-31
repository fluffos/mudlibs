#ifndef __PLAYER_GROUP_H__

#define __PLAYER_GROUP_H__

// Prototypes:

nomask int query_grouped();
nomask int query_party_member(object ob);
mixed grmems_in_room();
void toggle_grouped();

// End prototypes.


// Global variables:

nosave int     grouped;             // are we grouped ?

// End global variables.

#endif // __PLAYER_GROUP_H__
