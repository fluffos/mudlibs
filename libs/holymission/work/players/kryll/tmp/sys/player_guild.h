#ifndef __PLAYER_GUILD_H__

#define __PLAYER_GUILD_H__

// Prototypes:

int query_guild();
nomask int query_real_guild();
nomask int query_exp_next_level();
nomask int query_exp_perc_lev();
#if 0
nomask int query_perc_advance_lev() ;
#endif
nomask int set_guild(int val);
int add_chat();
nomask object query_guild_soul();

// End prototypes.


// Global variables:

nosave object  guild_soul;          // Pointer to the guild soul if present
nosave string  guild_name;          // name of guild
nosave string  guild_room;          // the guild room path

// End global variables.

#endif // __PLAYER_GUILD_H__
