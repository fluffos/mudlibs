#ifndef __PLAYER_GENERAL_H__

#define __PLAYER_GENERAL_H__

// Prototypes:

nomask int query_user_status(int stat);
nomask int set_user_status(int stat);
nomask int clear_user_status(int stat);
nomask int toggle_user_status(int stat);
nomask int may_not_be_snooped();
nomask int query_prevent_shadow();
nomask int query_linkdeath();
nomask int query_link_return();
nomask string version();
nomask void save_me(int val);
nomask int save_character();
nomask void set_race(string str);
nosave int compute_values(object ob);
void load_auto_obj(string str);
nomask string nsh_flag(object ob);
void reset(int arg);
nomask int query_player();
nomask int id(string str, int lvl);
int _filter(string str);
nomask nosave int quit(int val);
nomask string query_mailaddr();
int fix();
int illegal_patch(string str);
int show_hp();
nomask void set_retell_message(string str);
nomask string query_retell_message();
int do_say(string str);
int guild_line(string str);
void add_standard_commands();
string *query_hit_msg(int tmp, string name, object att, int def);
int wield(string str, int val);
int lcatch_tell(string act, string msg, object who, int kind);
int allowed_attack(object at_whom);

// End prototypes.


// Global variables:

int            ftp_user;       // ftp only, no login. *anonymous*
int            is_linkdead;    // The player is currently linkdead
int            tot_value;      // Saved values of this player
int            user_status;    // a general use variable to define certain
                               // statistics. the usage is defined in
                               // /obj/user_status.h. please talk to an
                               // archwiz if you need a bit in there.

mixed          *needed_quests; // A list of the quests we have to solve

nosave mixed call;           // stupid mixed variable - supposedly
                               // makes calls faster somewhat

nosave int     apwz;           // level of apwz
nosave int     fwz;            // level of full wiz
nosave int     ldead;          // check if player is linkdead -> destruct

nosave string  link_return;    // Where to return after a link fail
nosave string  mailaddr;       // Email address of player
nosave string  *poisonname;    // name of the poisonlevels
nosave string  ret_msg;        // the last message given by tell

// End global variables.

#endif __PLAYER_GENERAL_H__

