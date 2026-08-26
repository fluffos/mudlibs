// Petrarch
// Merentha Lib 1.0
// room.h

#ifndef __ROOM_H__
#define __ROOM_H__

int is_room();
varargs int cmd_go(string str);
string get_long_exits();
string describe_room(int verbose);
void set_smells(mapping args);
void set_smell(string item, string smell);
void add_smell(string item, string smell);
void remove_smell(string item);
mapping query_smells();
string query_smell(string item);
void set_sounds(mapping args);
void set_sound(string item, string sound);
void add_sound(string item, string sound);
void remove_sound(string item);
mapping query_sounds();
string query_sound(string item);
void set_exits(mapping args);
void add_exit(string dir, string dest);
void remove_exit(string dir);
string query_exit(string dir);
string *query_exits();
void set_exit_invis(string dir);
void set_exit_vis(string dir);
void set_items(mapping args);
void add_item(string item, string desc);
void remove_item(string item);
string query_item(string item);

#endif
