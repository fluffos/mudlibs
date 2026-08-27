/*  -*- LPC -*-  */
//  room.h:  basic room object for use in building areas
//    Originally written by Tim McIntosh sometime in early 6/95
//
#ifndef _ROOM_H
#define _ROOM_H

#include <mudlib.h>
#include <modules.h>
#include <object_types.h>

//
// Prototypes
//
void initialize();
void init();
string long();
int receive_object(object ob);

int query_no_attack();
void set_no_attack();                     // cannot fight here

void set_exits(mapping dir_dest_mapping); // dest can be obj or string 
void add_exits(mapping args);
void remove_exits(string* keylist);
int move_to_room();                          // player command

void set_items(mapping id_to_long_mapping);  // long can be string/function
string exa_item(string item);             // returns long desc of item

#endif /* _ROOM_H */
