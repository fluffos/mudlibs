#ifndef __PLAYER_START_H__

#define __PLAYER_START_H__

// Prototypes:

nosave int try_throw_out(string str);
nosave void move_player_to_start3(string where);
nosave void getgender(string str);
nosave void move_player_to_start2(string where);
void logon(string n, int quiet);
void compute_auto_str();
void check_start_pos(object me);
void reconnect();
void time_out();
void dest_ldead();
void notify_reconnect(int val);
int start_in_guild(int val);
string start_where();

// End prototypes.


// Global variables:

int            bug_file_size;       // Used to check if there are new
int            start_at_guild;      //
int            stats_is_updated;    //

object         other_copy;          //

string         called_from_ip;      // IP number was used last time
string         start_where;         // room where to start from

nosave string  login_msg;           //
nosave string  saved_where;         // Temp
nosave int     time_to_save;        // Time to autosave

// End global variables.

#endif // __PLAYER_START_H__
