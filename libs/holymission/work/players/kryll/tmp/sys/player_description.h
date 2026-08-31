#ifndef __PLAYER_DESCRIPTION_H__

#define __PLAYER_DESCRIPTION_H__
#define MAX_SCAR        10

// Prototypes:

string query_msgin();
string query_msgout();
string query_mmsgin();
string query_mmsgout();
varargs string short(string str);
nomask int set_description(string str);
nomask void write_description();
nomask int set_title(string str);
nomask varargs int set_pretitle(string str, int val);
nomask void long();
string query_al_title();
string query_title();
string query_pretitle();
nomask void add_alignment(int val);
nomask void set_al(int val);
nomask int set_alignment(string str);
nomask string query_alignment_title();
nomask int query_brief();
string query_religion();
nomask string query_real_religion();
nomask void set_religion(string str);
nosave void make_scar();
nosave void show_scar();
void set_cap_name();
nomask void set_incognito(int val);
nomask int query_incognito();
nosave void fix_short();

// End prototypes.


// Global variables:

int scar;

int         incognito;           // are we incognito
string         al_title;            // alignment string of player
string         pretitle;            // official title - a wiz can change it
string         real_al_title;       // real alignment string
string         religion;            // the religion string of the player
string         title;               // official pretitle - a wiz can change it

// End global variables.

#endif // __PLAYER_DESCRIPTION_H__
