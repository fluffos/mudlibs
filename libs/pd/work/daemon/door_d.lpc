/*door_d : Door daemon
 *
 *Keeps track of the statuses of each active door and
 *allows each individual room to align themseles to a specific
 *door through ID, which makes it easier to ensure that an action
 *on a door in one room affects all the other rooms which share
 *the same door*/
// Created by Pyro789x 7/21/2008

#include <std.h>

#define MASTER_KEY_ID "MUD_Master_Key"

inherit DAEMON;

mapping doors;


void create_door(string doorId);
int door_tracked(string id);
string* query_doors_tracked();

void connect_door_to_room(string doorId, object room);
void disconnect_door_from_room(string doorId, object room);
varargs void notify_rooms_of_change(string doorId, string action, object calling_player);
varargs void message_rooms_with_door(string doorId, string message, object calling_player);

void set_locked(string id, int i);
int query_locked(string id);
void set_lock_strength(string, int);
int query_lock_strength(string);
void set_door_strength(string, int);
int query_door_strength(string);
void set_door_name(string id, string n);
string query_door_name(string id);
void set_closed(string id, int i);
int query_closed(string id);
string query_door_status(string id);
void set_door_status(string id, string str);
string query_key(string id);
void set_key(string id, string key);

string query_master_key();

void create() {
  ::create();
  doors = ([ ]);
}

//required to ensure that door information is not deleted for rooms that still exist
int clean_up() {
  string* doorsToRemove = ({ });

  foreach (string door in keys(doors)) {
    //remove all room pointers that have been set to 0
    doors[door]["rooms"] = filter(doors[door]["rooms"], (: ($1 != 0) :) );
    if(sizeof(doors[door]["rooms"]) < 1) {
      doorsToRemove += ({ door });
    }
  }

  foreach (string door in doorsToRemove) {
    map_delete(doors, door);
  }

  if(sizeof(keys(doors)) < 1) {
    return ::clean_up();
  }
  else
  return 1;
}

//ensures that there is a global door with that ID
void create_door(string doorId) {

  if(door_tracked(doorId)) {
    //doors[id]["rooms"] += room;
    return;
  }

  //create a new door to track with the daemon

  doors[doorId] = ([
    "status" : "default",
    "name" : "door",
  //the player's inventory will be searched for an item with an id that
  //fits this string in order to be able to lock and unlock the door
    "key" : 0,
    "locked" : 0,
    "closed" : 1,
  //how much locks skill to pick the lock
    "lockstrength" : 50+random(25)-random(25),
  //how much strength to break down the door
    "doorstrength" : 90+random(30)-random(30),
  //A list of objects -- the rooms that contain this specific door ID
  //used to send messages to the other rooms when 
    "rooms" : ({ }),
  ]);
}


int door_tracked(string id) {
  if(!doors[id]) return 0;
  return 1;
}

string* query_doors_tracked() { return keys(doors); }

void connect_door_to_room(string doorId, object room) {
  if(!door_tracked(doorId))
    create_door(doorId);

  if(member_array(room, doors[doorId]["rooms"]) == -1)
    doors[doorId]["rooms"] += ({room});
}

void disconnect_door_from_room(string doorId, object room) {
  int roomIndex;
  if(!door_tracked(doorId)) return;

  //remove the room from the array
  doors[doorId]["rooms"] -= room;
}

varargs void notify_rooms_of_change(string doorId, string action, object calling_player) {
  if (nullp(doorId) || nullp(action)) return;
  //remove any room from the mapping which is no longer loaded in memory
  doors[doorId]["rooms"] = filter(doors[doorId]["rooms"], (: ($1 != 0) :) );

  foreach(object room in doors[doorId]["rooms"]) {
    room->write_action_string(doorId, action, calling_player);
  }
}

varargs void message_rooms_with_door(string doorId, string message, object calling_player) {
  if (nullp(doorId) || nullp(message)) return;
  //remove any room from the mapping which is no longer loaded in memory
  doors[doorId]["rooms"] = filter(doors[doorId]["rooms"], (: ($1 != 0) :) );

  foreach(object room in doors[doorId]["rooms"]) {
    if(nullp(calling_player)) message("info", message, room);
    else message("info", message, room, calling_player);
  }
}

/*** Specific door variables accessors/setters ***********/

void set_locked(string id, int i) {
  if(!door_tracked(id)) return;
  if(doors[id]["locked"] == i) return;
  doors[id]["locked"] = i;
}

int query_locked(string id) {
  if(!door_tracked(id)) return -1;
  return doors[id]["locked"];
}

void set_lock_strength(string id, int i) {
  if (door_tracked(id)) doors[id]["lockstrength"] = i;
}

int query_lock_strength(string id) {
  return (door_tracked(id) ? doors[id]["lockstrength"] : -1);
}

void set_door_strength(string id, int i) {
  if (door_tracked(id)) doors[id]["doorstrength"] = i;
}

int query_door_strength(string id) {
  return (door_tracked(id) ? doors[id]["doorstrength"] : -1);
}

void set_door_name(string id, string n) {
  if(!door_tracked(id)) return;
  doors[id]["name"] = n;
}

string query_door_name(string id) {
  if(!door_tracked(id)) return 0;
  return doors[id]["name"];
}

void set_closed(string id, int i) {
  if(!door_tracked(id)) return;
  if(doors[id]["closed"] == i) return;

  doors[id]["closed"] = i;
}

int query_closed(string id) {
  if(!door_tracked(id)) return -1;
  return doors[id]["closed"];
}

string query_door_status(string id) {
  if(!door_tracked(id)) return 0;
  return doors[id]["status"];
}

void set_door_status(string id, string str) {
  if(!door_tracked(id)) return;
  if(str == doors[id]["status"]) return;
  doors[id]["status"] = str;
}

string query_key(string id) {
  if(!door_tracked(id)) return 0;
  return doors[id]["key"];
}

void set_key(string id, string key) {
  if(!door_tracked(id)) return;
  doors[id]["key"] = key;
}

string query_master_key() { return MASTER_KEY_ID; }
