#ifndef ROOM_H
#define ROOM_H


/*************************************************************************/
/* function prototypes */

varargs string *query_door_exits(int arg);
string *query_all_exits();
string *query_open_exits();
string *query_closed_exits();


/* sets */

string set_day_desc(string str);
string set_night_desc(string str);
void   set_exits(string *arr);
void   set_extra_objects(string *arr);
void   set_items(string *arr);
int    set_climb(int i);
int    set_fall_dam(int i);
void   set_doors(mixed *arr);
varargs void set_sign_message(string sign_msg, string sign_lang);
int set_no_summon(int i);
int set_no_fight(int i);

/* query */

string query_day_desc();
string query_night_desc();
string *query_dest_dir();
string *query_extra_objects();
string *query_items();
string query_sign_message();
string query_sign_language();
int query_no_fight();
int query_no_summon();


string query_exit_filename(string str);
string query_file_exitname(string file);

mixed  *query_doors();


/* movement */

void   exits(status brief);
status ready_to_move(string str);
void   room_move(string str);

/* look direction */

status look_dir(string dir);

/* dynamic exits */   

status add_exit(string where, string dest);
status remove_exit(string dest);
status change_exit_room(string old_dest,string new_dest);

/* extra objects */

status add_extra_object(string id_extra_object, string file_extra_object);
status remove_extra_object(string id_extra_object);
status get_extra_object(string id_extra_object);

/* item_look */

status look_at(string str);

/* door */

varargs status add_door(string dir,
                       string dest,
                status closed_flag,
                  string door_desc, 
                          int lock,
                     string key_id,
                      int trap_dam,
                   status trap_set,
                   int secret_door);

status remove_door(string str);
status door_to_move(string str);
string search(string room);
status open(string str);
status close(string str);
status disarm_door_trap(string str);
varargs status set_door_trap(string dest_filename,status on,string door_id);
varargs status set_door_closed(string dest_filename,status close,string id);
void reset_doors(status arg);
int get_id_index(string arg, string *arg1);


/* end prototype */
/***************************************************************************/

#endif /* ROOM_H */

