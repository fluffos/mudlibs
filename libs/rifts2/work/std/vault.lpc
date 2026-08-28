//	/std/vault.c
//	from the Nightmare mudlib
//	A room with as many doors as exits will allow
//	created by Descartes of Borg 23 february 1993

#include <std.h>
#include <clock.h>
#include <daemons.h>

inherit ROOM;
 
mapping doors;
string close_time, open_time;
string close_fun, open_fun;
int closed_status;
 
void set_open(string id, int open);
void set_locked(string id, int locked);
void set_func(string id, string which, string fun);
void set_string(string id, string which, string str);
void set_door_pre_exit_function(string id, string fun);
void set_close_function(string fun, string time);
void set_open_function(string fun, string time);
int query_room_closed();
int timecmp(string time1, string time2);
int query_open(string id);
int query_locked(string id);
void check_closed();

void init() {
    ::init();
    add_action("OpenDoor", "open");
    add_action("CloseDoor", "close");
    add_action("UnlockDoor", "unlock");
    add_action("LockDoor", "lock");
    check_closed();
}

void check_closed() {
  if(closed_status != query_room_closed()) {
    closed_status = query_room_closed();
    if(query_room_closed() && close_fun)
      call_other(this_object(), close_fun);
    else if(open_fun)
      call_other(this_object(), open_fun);
  }
}

void create() {
  ::create();
  closed_status = 4;
}

int timecmp(string time1, string time2) {
  int hour1, hour2, min1, min2, sec1, sec2;

  if(sscanf(time1, "%d:%d:%d", hour1, min1, sec1) != 3) return 0;
  if(sscanf(time2, "%d:%d:%d", hour2, min2, sec2) != 3) return 0;
  if(hour1 > hour2) return 1;
  if(hour2 > hour1) return 2;
  if(min1 > min2) return 1;
  if(min2 > min1) return 2;
  if(sec1 > sec2) return 1;
  if(sec2 > sec1) return 2;
  return 0;
}

int query_room_closed() {
  string time_now;

  if(!close_time && !open_time) return 0;
  time_now = sprintf("%d:%d:%d", CURRENT_HOUR(time()), CURRENT_MINUTE(time()),
		     CURRENT_SECOND(time()));
  if(timecmp(open_time, close_time) == 0) return 0;
  if(timecmp(open_time, close_time) == 2 &&
     (timecmp(time_now, open_time) == timecmp(time_now, close_time)))
    return 1;
  if(timecmp(open_time, close_time) == 1 &&
     (timecmp(time_now, open_time) != timecmp(time_now, close_time)))
    return 1;
  return 0;
}

string *debug_f() { return ({ close_time, open_time, close_fun, open_fun }); }

void set_open_function(string fun, string time) {
  open_fun = fun;
  open_time = time;
}

void set_close_function(string fun, string time) {
  close_fun = fun;
  close_time = time;
}
  
void clean_up() { return; }

void set_door(string id, string dest, string dir, string key) {
    if(!id) return;
    if(!doors) doors = ([]);
    doors[id] = (["destination":dest, "direction":dir ]);
    add_pre_exit_function(dir, "GoThroughDoor");
    if(!key) return;
    doors[id]["key"] = key;
}
 
void set_lock_level(string id, int level) {
  if(!id || !doors || !doors[id]) return;
  doors[id]["lock level"] = level;
}

int query_lock_level(string id) {
  if(!id || !doors[id]) return 0;
  if(!doors[id]["lock level"]) return 5;
  return doors[id]["lock level"];
}

string query_key(string id) {
    if(!id) return 0;
    if(!doors) return 0;
    if(!doors[id]) return 0;
    if(!doors[id]["key"]) return 0;
    return doors[id]["key"];
}

void set_locked(string id, int locked) {
    if(!doors) return;
    if(!id) return;
    if(!doors[id]) return;
    if(!doors[id]["key"]) return;
    doors[id]["locked"] = locked;
}
 
void set_open(string id, int open) {
    if(!id) return;
    if(!doors) return;
    if(!doors[id]) return;
    doors[id]["open"] = open;
}
 
void set_func(string id, string which, string fun) {
    if(!which) return;
    if(!id) return;
    if(!doors) return;
    if(!doors[id]) return;
    doors[id][which+" fun"] = fun;
}
 
void set_string(string id, string which, string str) {
    if(!id) return;
    if(!which) return;
    if(!doors) return;
    if(!doors[id]) return;
    doors[id][which+" str"] = str;
}
 
void set_door_pre_exit_function(string id, string fun) {
    if(!id) return;
    if(!doors) return;
    if(!doors[id]) return;
    doors[id]["pre exit"] = fun;
}

int query_locked(string id) {
    if(!id) return 0;
    if(!doors) return 0;
    if(!doors[id]) return 0;
    return doors[id]["locked"];
}
 
int query_open(string id) {
    if(!id) return 0;
    if(!doors) return 1;
    if(!doors[id]) return 1;
    return doors[id]["open"];
}
 
int OpenDoor(string str) {
    if(!doors) return 0;
    if(!str) {
        notify_fail("Open what?\n");
        return 0;
    }
    if(!doors[str]) {
        notify_fail("What "+str+"?\n");
        return 0;
    }
    if(doors[str]["open"]) {
        notify_fail("It is already open!\n");
        return 0;
    }
    if(doors[str]["locked"]) {
        notify_fail("It is locked.\n");
        return 0;
    }
    if(doors[str]["open fun"])
        if(!call_other(this_object(), doors[str]["open fun"])) return 1;
    if(doors[str]["open string"])
        write(doors[str]["open string"]);
    else write("You open the "+str+".\n");
    say(this_player()->query_cap_name()+" opens the "+str+".\n", this_player());
    set_open(str, 1);
    doors[str]["destination"]->set_open(str, 1);
    tell_room(doors[str]["destination"], "You notice the "+str+" suddenly open from the other side.\n");
    return 1;
}

int CloseDoor(string str) {
    if(!doors) return 0;
    if(!str) {
	notify_fail("Close what?\n");
	return 0;
    }
    if(!doors[str]) {
	notify_fail("What "+str+"?\n");
	return 0;
    }
    if(!doors[str]["open"]) {
	notify_fail("It is already closed!\n");
	return 0;
    }
    if(doors[str]["close fun"])
	if(!call_other(this_object(), doors[str]["close fun"])) return 1;
    if(doors[str]["close str"])
	write(doors[str]["close str"]);
    else write("You close the "+str+".\n");
    say(this_player()->query_cap_name()+" closes the "+str+".\n");
    set_open(str, 0);
    doors[str]["destination"]->set_open(str, 0);
    tell_room(doors[str]["destination"],
	"The "+str+" is closed by someone on the other side.\n");
    return 1;
}

int UnlockDoor(string str) {
    string ident, key;
    object ob;

    if(!doors) return 0;
    if(!str) {
	notify_fail("Unlock what?\n");
	return 0;
    }
    if(sscanf(str, "%s with %s", ident, key) != 2) {
	notify_fail("Unlock what with what?\n");
	return 0;
    }
    if(!doors[ident]) {
	notify_fail("What "+ident+"?.\n");
	return 0;
    }
    if(!doors[ident]["key"]) {
	notify_fail("It has no lock.\n");
	return 0;
    }
    if(doors[ident]["open"]) {
	notify_fail("Unlock it? It is open!\n");
	return 0;
    }
    if(!doors[ident]["locked"]) {
	notify_fail("It is already unlocked.\n");
	return 0;
    }
    if( !( ob=present(key,this_player()) ) ) {
	notify_fail("You do not have that!\n");
	return 0;
    }
    if( !ob->id(doors[ident]["key"]) ) {
	notify_fail("You fail to unlock the "+ident+" using the "+key+".\n");
	return 0;
    }
    if(doors[ident]["unlock fun"])
	if(!call_other(this_object(), doors[ident]["unlock fun"])) return 1;
    if(doors[ident]["unlock string"])
	write(doors[ident]["unlock string"]);
    else write("You unlock the "+ident+" with the "+key+".\n");
    say(this_player()->query_cap_name()+" unlocks the "+ident+" with the "+key+".\n", this_player());
    set_locked(ident, 0);
    doors[ident]["destination"]->set_locked(ident, 0);
    tell_room(doors[ident]["destination"],
	"You here some scratching noises on the other side of the "+ident+".\n");
    return 1;
}

int LockDoor(string str) {
    string ident, key;
    object ob;

    if(!doors) return 0;
    if(!str) {
	notify_fail("Lock what with what?\n");
	return 0;
    }
    if(sscanf(str, "%s with %s", ident, key) != 2) {
	notify_fail("Lock what with what?\n");
	return 0;
    }
    if(!doors[ident]) {
	notify_fail("What "+ident+"?\n");
	return 0;
    }
    if(!doors[ident]["key"]) {
	notify_fail("It has no lock.\n");
	return 0;
    }
    if(doors[ident]["open"]) {
	notify_fail("You cannot lock it while it is open.\n");
	return 0;
    }
    if(doors[ident]["locked"]) {
	notify_fail("It is already locked!\n");
	return 0;
    }
    if( !( ob=present(key, this_player()) ) ) {
	notify_fail("You do not have that!\n");
	return 0;
    }
    if(!ob->id(doors[ident]["key"])) {
	notify_fail("You fail to lock the "+ident+" with the "+key+".\n");
	return 0;
    }
    if(doors[ident]["lock fun"])
	if(!call_other(this_object(), doors[ident]["lock fun"])) return 1;
    if(doors[ident]["lock string"])
	write(doors[ident]["lock string"]);
    else write("You lock the "+ident+" with the "+key+".\n");
    say(this_player()->query_cap_name()+" locks the "+ident+" with the "+key+".\n", this_player());
    set_locked(ident, 1);
    doors[ident]["destination"]->set_locked(ident, 1);
    tell_room(doors[ident]["destination"],
	"You here some scratching noises coming from the other side of the "+ident+".\n");
    return 1;
}

int GoThroughDoor() {
    string verb, id;
    string *ind;
    int i;

    if(!doors) return 1;
    verb = query_verb();
    ind = keys(doors);
    for(i=0; i<sizeof(ind); i++)
	if(doors[ind[i]]["direction"] == verb) id = ind[i];
    if(!doors[id] || !mapp(doors[id])) return 1;
    if(!doors[id]["open"]) {
	write("You bump into the closed "+id+".\n");
	say(this_player()->query_cap_name()+" bumps into the closed "+id+".\n");
   	return 0;
    }
    if(doors[id]["pre exit"]) 
	if(!call_other(this_object(), doors[id]["pre exit"])) return 0;
    return 1;
}

int pick_lock(string str) {
    if(!doors) return 0;
    if(!doors[str]) return 0;
    set_locked(str, 0);
    doors[str]["destination"]->set_locked(str, 0);
    return 1;
}

string query_door(string dir) {
    string *ind;
    int i;

    if(!doors) return 0;
    ind = keys(doors);
    for(i=0; i<sizeof(ind); i++) 
	if(doors[ind[i]]["direction"] == dir) return ind[i];
    return 0;
}

int remove_door(string id) {
    if(!doors) return 0;
    if(!doors[id]) return 0;
    map_delete(doors, id);
    return 1;
}
