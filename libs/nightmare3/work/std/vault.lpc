//	/std/vault.c
//	from the Nightmare mudlib
//	A room with as many doors as exits will allow
//	created by Descartes of Borg 23 february 1993

#include <std.h>

inherit ROOM;
 
mapping doors;
 
void set_open(string id, int open);
void set_locked(string id, int locked);
void set_func(string id, string which, string fun);
void set_string(string id, string which, string str);
void set_door_pre_exit_function(string id, string fun);
int query_open(string id);
int query_locked(string id);
int GoThroughDoor(string verb);

void init() {
    ::init();
    add_action("OpenDoor", "open");
    add_action("CloseDoor", "close");
    add_action("UnlockDoor", "unlock");
    add_action("LockDoor", "lock");
}
 
void clean_up() { return; }
 
void set_door(string id, string dest, string dir, string key) {
    if(!id) return;
    if(!doors) doors = ([]);
    doors[id] = (["destination":dest, "direction":dir ]);
    add_exit(dir, dest, (: GoThroughDoor :));
    if(!key) return;
    doors[id]["key"] = key;
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
    doors[id][which+" string"] = str;
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

int GoThroughDoor(string verb) {
    string id;
    string *ind;
    int i;

    if(!doors) return 1;
    ind = keys(doors);
    for(i=0; i<sizeof(ind); i++)
	if(doors[ind[i]]["direction"] == verb) id = ind[i];
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
