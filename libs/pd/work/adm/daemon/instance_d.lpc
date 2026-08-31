/** Instance Daemon *********************************************
 * Created by Pyro789x on August 10, 2008
 ****************************************************************/

#include <std.h>
#include <locations.h>
#include <daemons.h>

#define DEFAULT_INSTANCE_ID "default"

inherit DAEMON;

/** Function Prototypes ****************************************/
void initialize();
void create_group_id(string groupId);
void create_instance_id(string groupId, string instanceId);
string query_group_id(object living);
string query_mob_group_id(object mob);
string query_player_group_id(object player);

void destruct_instances_with_group_id(string groupId);
void destruct_instances_with_instance_id(string instanceId);
void destruct_group_instance_pairing(string groupId, string instanceId);
void destruct_all_instances();
void dump_players(object* players, string instanceId);
void set_instance_dump(string instanceId, string dumpLoc);
string query_instance_dump(string instanceId);

varargs object get_instance_room(string groupId, string filePath, string instanceId);
void print_instances_tracked();

int clean_up();

/** Global Variables *******************************************/
mapping roomInstances;
mapping instanceDumps;

/** Functions **************************************************/
void create() {
  ::create();
  initialize();
}

void initialize() {
  roomInstances = ([ ]);
  instanceDumps = ([ ]);
  set_instance_dump(DEFAULT_INSTANCE_ID, SQUARE_LOC);
}

void create_group_id(string groupId) {
  if(!roomInstances) initialize();
  if(roomInstances[groupId]) return;
  roomInstances[groupId] = ([ ]);
}

void create_instance_id(string groupId, string instanceId) {
  create_group_id(groupId);
  if(roomInstances[groupId][instanceId]) return;
  roomInstances[groupId][instanceId] = ([ ]);
}

string query_group_id(object living) {
  if (living->is_player())
    return query_player_group_id(living);
  else
    return query_mob_group_id(living);
}

string query_mob_group_id(object mob) {
  string id;
  object env;
  object who;
  object *temp;

  env = environment(mob);

  who = mob->query_riding();
  if (!who) {
    temp = mob->query_riders();
    if (sizeof(temp)) temp = filter(temp, (: $1->is_mob() :));
    if (sizeof(temp)) who = temp[0];
  }
  if (!who) who = mob->query_following();
  if (!who) {
    temp = mob->query_followers();
    if (sizeof(temp)) temp = filter(temp, (: $1->is_mob() :));
    if (sizeof(temp)) who = temp[0];
  }
  if (!who) who = mob->query_owner();

  if (objectp(who)) id = query_group_id(who);

  if (!id && env->is_instanced()) id = env->query_group_id();

  // if all else fails...
  id = file_name(mob);

  return id;
}

// find or generate a group ID for a certain player
string query_player_group_id(object player) {
  string party, name, id;
  object who;

  // be sure to change exits in /std/instance.c so mobs
  // can't leave an instance - maybe change wander code instead

  name = player->query_name();

  if (!id) {
    // if one is set already, use it if it isn't expired (30 minutes since last instance)
    id = player->query_property("group id");
    if (player->query_property("group id time") + 30*60 < time())
      id = 0;
  }

  if (!id) {
    if (who = player->query_riding() && who->is_player())
      id = query_player_group_id(who);
  }

  if (!id) {
    if (who = player->query_following() && who->is_player())
      id = query_player_group_id(who);
  }

  if (!id) {
    party = player->query_party();
    if (party) {
      who = PARTY_D->query_leader(party);
      // in a party with no leader - this should never happen
      if (!who)
        id = party;
      // leader of the party he's in, use his individual group ID
      else if (who == player)
        id = name;
      // everyone else in the party will use the leader's group ID (which should be his name)
      else
        id = query_player_group_id(who);
    }
  }

  // not in a party - use individual group ID (name)
  if (!id)
    id = name;

  // save it for up to 30 mins
  player->remove_property("group id");
  player->remove_property("group id time");
  player->set_property("group id", id);
  player->set_property("group id time", time());

  return id;
}


/*Finds an instance group with the group id of groupId
 *and destructs all of their instances that they may have
 *loaded in memory. As such, there should be no entry
 *for this group when this command is finished*/
void destruct_instances_with_group_id(string groupId) {
  if(!roomInstances || !roomInstances[groupId]) return;
  foreach(string instance in keys(roomInstances[groupId])) {
    foreach(string room in keys(roomInstances[groupId][instance])) {
      object rm = roomInstances[groupId][instance][room];
      if(rm) {
        object* obs = filter(all_inventory(rm), (: $1->is_player() :) );
        dump_players(obs, instance);
        rm->clean_up();
      }
    }
  }
  map_delete(roomInstances, groupId);
}

/*Finds all groups that may have a currently tracked instance
 *of an instance with an instance ID of instanceId, and then
 *deletes all those occurances of this instance. As such,
 *when this command has finished running, there should be
 *no copies of this instance in memory. */
void destruct_instances_with_instance_id(string instanceId) {
  string *groupsWithInstance = ({ });
  if(!roomInstances) return;
  foreach(string group in keys(roomInstances)) {
    if(roomInstances[group][instanceId]) {
      groupsWithInstance += ({group});
    }
  }

  //placed within its own foreach loop so as not to modify
  //the mapping while it is being accessed
  foreach(string group in groupsWithInstance) {
    destruct_group_instance_pairing(group, instanceId);
  }
}

/*If a specific player's instance group has a currently
 *tracked instance in an instance with an instance id of
 *instanceId, then those rooms will be deleted and removed
 *from that player's instance group's list of instances. */
void destruct_group_instance_pairing(string groupId, string instanceId) {
  if(!roomInstances || !roomInstances[groupId] || !roomInstances[groupId][instanceId]) return;
  foreach(string room in keys(roomInstances[groupId][instanceId])) {
    object rm = roomInstances[groupId][instanceId][room];
    if(rm) {
      object* obs = filter(all_inventory(rm), (: $1->is_player() :) );
      dump_players(obs, instanceId);
      rm->clean_up();
    }
  }
  map_delete(roomInstances[groupId], instanceId);
  if(sizeof(roomInstances[groupId]) < 1)
    map_delete(roomInstances, groupId);
}


/*Calls destruct_instances_with_group_id for all groups*/

void destruct_all_instances() {
  string* groups = keys(roomInstances);
  foreach(string group in groups) {
    destruct_instances_with_group_id(group);
  }
}

/*Attempts to dump the players outside the instance that they
 *were in. Should usually be used only when the instance
 *is destructing */
void dump_players(object* players, string instanceId) {
  object dumpRoom = 0;
  if(instanceDumps) {
    if(!instanceDumps[instanceId])
      instanceId = DEFAULT_INSTANCE_ID;
    if(instanceDumps[instanceId])
      dumpRoom = load_object(instanceDumps[instanceId]);
  }
  if(!dumpRoom)
    dumpRoom = load_object(VOID_LOC);
  if(!dumpRoom) {
    message("info", 
      "We were unable to find the room you were meant to be placed in. "
      "We are sorry, but you will now quit. Your instance ID was "
      +instanceId+".", players);
    foreach(object plyr in players) {
      plyr->save_player((string)plyr->query_name());
    }
    message("info", "Your character data has been saved.", players);
    players->quit();
    return;
  }
  players->move(dumpRoom);
}

/*sets the location that the players in a specific instance
 *will be moved to should that instance be destroyed. */
void set_instance_dump(string instanceId, string dumpLoc) {
  if(!instanceDumps) initialize();
  instanceDumps[instanceId] = dumpLoc;
}
string query_instance_dump(string instanceId) {
  if (!instanceDumps) initialize();
  return instanceDumps[instanceId];
}

/*Returns an instanced version of the room given by
 *filePath, unique to a group with the group ID of
 *groupId. If you want the player to be the only one
 *in the group, you can just pass the player's name
 *in as their groupId. instanceId is optional, adds
 *a layer of capability onto the instance daemon,
 *allowing the entire instance to be called as a group
 *as well as setting the specific room that players
 *will be sent to should the instance be destructed.*/
varargs object get_instance_room(string groupId, string filePath, string instanceId) {
  object newRoom;
  if(nullp(groupId) || nullp(filePath)) return 0;
  if(nullp(instanceId)) instanceId = DEFAULT_INSTANCE_ID;
  create_instance_id(groupId, instanceId);
  if(roomInstances[groupId][instanceId][filePath]) return roomInstances[groupId][instanceId][filePath];

  //instanced version not found. create a new one.
  if(!load_object(filePath)) return 0;
  newRoom = new(filePath);
  newRoom->set_group_id(groupId);
  roomInstances[groupId][instanceId][filePath] = newRoom;
  return newRoom;
}

/*Prints instance data */
void print_instances_tracked() {
  string ret = "";
  if(roomInstances) foreach(string groupId in keys(roomInstances)) {
    ret += "\n==( Group ID: "+groupId+")=======================\n\n";
    if(roomInstances[groupId]) foreach(string instance in keys(roomInstances[groupId])) {
      ret += "  Instance ID: "+instance+"\n";
      if(roomInstances[groupId][instance]) foreach(string room in keys(roomInstances[groupId][instance])) {
        if(roomInstances[groupId][instance][room]) ret += "    "+file_name(roomInstances[groupId][instance][room])+"\n";
      }
    }
    ret += "=================================================\n";
  }
  write(ret);
}

/*Overrides the ::clean_up() to actually clean up the
 *data that is being stored. If no data is being stored
 *after clean up, releases the daemon to ::clean_up() */
int clean_up() {
  string* GroupIdsToRemove = ({ });

  if(roomInstances) foreach (string GroupId in keys(roomInstances)) {
    string* InstancesToRemove = ({ });
    if(roomInstances[GroupId]) foreach(string instanceId in keys(roomInstances[GroupId])) {

      //remove all room pointers in roomInstances[GroupId][instanceId] that have been set to 0
      mapping nMap = ([ ]);
      map(keys(roomInstances[GroupId][instanceId]),
          (: ($2[$1]!=0 ? ($3[$1]=$2[$1]) : 0) :),
          roomInstances[GroupId][instanceId], nMap);
      roomInstances[GroupId][instanceId] = nMap;

      if(sizeof(roomInstances[GroupId][instanceId]) < 1) {
        InstancesToRemove += ({instanceId});
      }
    }
    foreach(string instanceId in InstancesToRemove) {
      map_delete(roomInstances[GroupId], instanceId);
    }

    if(sizeof(roomInstances[GroupId]) < 1) {
      GroupIdsToRemove += ({ GroupId });
    }
  }

  foreach (string GroupId in GroupIdsToRemove) {
    map_delete(roomInstances, GroupId);
  }

  if(sizeof(keys(roomInstances)) < 1) {
    return ::clean_up();
  }

  return 1;
}
