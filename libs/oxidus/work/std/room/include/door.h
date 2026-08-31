#ifndef __DOOR_H__
#define __DOOR_H__

#include <classes.h>

int add_door(mixed door); // This is class Door, but cannot specify in a header file
int remove_door(string direction);
int set_door_open(string direction, int bool, int silent);
int set_door_locked(string direction, int bool, int silent);
int add_door_id(string direction, string id);
int remove_door_id(string direction, string id);
string *query_door_ids();
int set_door_short(string direction, string short);
string query_door_short(string direction);
int set_door_long(string direction, string long);
string query_door_long(string direction);
string query_door_name(string direction);
mapping query_doors();
int is_door_open(string direction);
int is_door_locked(string direction);
void reset_doors();
mixed query_door_status(string direction, int as_number);
public string resolve_direction_from_input(string direction);

#endif // __DOOR_H__
