/*Created by Pyro789x August 10, 2008 */
#include <std.h>
#include <move.h>
#include <rooms.h>
#include <daemons.h>

#define INSTANCE_GROUP_ID_DEFAULT "default"

inherit ROOM;

string instanceGroupId;
string groupId;

/** Function Prototypes ****************************/
int is_instanced();
string query_group_id();
void set_group_id(string);
string query_instance_group_id();
void set_instance_group_id(string str);
void set_instance_dump_area(string instanceId, string room);
object query_redirect(object player);
object get_ob(string fileName);

//the following functions are meant to be
//overwritten by child objects, should they wish
int accept_player_into_instance(object player);
object get_instance_entrance(object player);
/**********************************************/

void create() { ::create(); instanceGroupId = INSTANCE_GROUP_ID_DEFAULT; groupId = "base"; }

varargs int receive_objects(object ob) {
  if (!clonep(this_object()))
    return 0;
  // don't allow anyone to enter the non-instanced version of an instance room
  // query_redirect will be called after this returns 0 and
  // the player will be moved into the object it returns

  return ::receive_objects(ob);
}

//given a file name, returns the copy of that object
//associated with this room's instance ID, or creates
//one if that object does not exist.
//A way to get instance objects (IE: rooms, daemons)
//based off of the group's instance ID used to create
//this room, instead of recalculating the group instance ID
object get_ob(string fileName) {
  return INSTANCE_D->get_instance_room(
    query_group_id(), fileName, query_instance_group_id());
}

string query_exit(string str) {
  string origExit = ::query_exit(str);
  if(!origExit || !load_object(origExit) || !(origExit->is_instanced()))
    return origExit;
  return file_name(get_ob(origExit));
}

int is_instanced() { return 1; }
int is_instance() { return 1; }

string query_instance_group_id() { 
  return ((instanceGroupId&&instanceGroupId!="") ?
      instanceGroupId:INSTANCE_GROUP_ID_DEFAULT);
} 

void set_instance_group_id(string str) { instanceGroupId = str; }

void set_instance_dump_area(string instanceId, string room) {
  if(!instanceId || instanceId=="" || instanceId == INSTANCE_GROUP_ID_DEFAULT) {
    //don't let builders change the default dump location
    return;
  }
  INSTANCE_D->set_instance_dump(instanceId, room);
}

/* This function returns 1 if the player is allowed
 * to enter the instance. This function is meant
 * to be overwritten by instance rooms if
 * they wish to supply a specific instance message
 * or have specific variables checked before accepting
 * a player. */

int accept_player_into_instance(object player) {
  message("info", "Reality seems to shake and tremble as you enter the area.", player);
  return 1;
}


/* This function is meant to find the correct room
 * to move the player into. Generally it should not be
 * overwritten, but you can if you know what you
 * are doing. It will be called whenever a player
 * attempts to move into the base version of
 * an instanced room from a non-instanced room. */
object get_instance_entrance(object player) {
  return INSTANCE_D->get_instance_room(
    INSTANCE_D->query_player_group_id(player), file_name(this_object()), query_instance_group_id());
}

/* This is not the function that should be overwritten
 * should you wish to wish to send the player to a
 * different room than the instanced version of
 * the same room. If that is your intention, overwrite
 * the function above, get_instance_entrance(object) */
object query_redirect(object player) {
  //check the instance-specific or room-specific properties
  if(!this_object()->accept_player_into_instance(player))
    return 0;

  return this_object()->get_instance_entrance(player);
}

mixed query_property(string str) {
  if(str && str == "no teleport")
    return 1;
  return ::query_property(str);
}

string query_group_id() { return groupId; }
void set_group_id(string str) { groupId = str; }
