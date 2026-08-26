/*
** FILE:    gang_d.c
** PURPOSE: The file that runs player gangs, and shit.
** CREDITS:
**     15 Feb 2000  Cyanide created the file.
*/

#include "/u/c/cyanide/debug.h"
#include <uid.h>
#include <daemons.h>
#include <gangs.h>

inherit DAEMON;

mapping gang_list = ([]), gang_members = ([]);

nomask void load_saved_data()
{
    if (!restore_object(SAVE_PATH_MAIN+SAVE_NAME))
    {
	REGISTRY_D->admin_call("ERROR: Failure in loading gangs "+
	  "registry! Attempting to load from backup copy.");
	if (!restore_object(SAVE_PATH_ATTIC+SAVE_NAME)) {
	    REGISTRY_D->admin_call("ERROR: Fatal failure loading "+
	      "backup copy. Ganags is loading an empty mapping.");
	    gang_list = ([]);
	    gang_members = ([]);
	}
    }

    return;
}                                 

nomask int save_all() {
    save_object(SAVE_PATH_MAIN+SAVE_NAME);
    save_object(SAVE_PATH_ATTIC+SAVE_NAME);
}

string *gang_list() { return keys(gang_list); }

mapping get_list_map() { return gang_list; }

mapping get_members_map() { return gang_members; }

int gang_exists(string name) {
    return gang_members[name];
}

int remove_member( string gangname ) {
    if (!gangname) gangname = "";
    gangname = lower_case(gangname);

    if (!gang_members[gangname]) return NO_SUCH_GANG;
    if (gang_members[gangname]==1) {
	gang_members[gangname]-=1;
	map_delete(gang_list, gangname);
	map_delete(gang_members, gangname);
    } else {
	gang_members[gangname] -= 1;
    }

    save_all();

    return 1;
}

int add_member( string gangname ) {
    int num;

    gangname = lower_case(gangname);

    if (!gang_exists(gangname))
	return NO_SUCH_GANG;

    num = gang_members[gangname];

    if (num >= MAX_MEMBERS) return TOO_MANY_MEMBERS;

    gang_members[gangname] += 1;

    save_all();

    return 1;
}

int query_can_make_gang( object ob ) {
    if (ob->query("gang")) {
	tell_object(ob, "You are already in a gang.\n");
	return 0;
    }

    if (TP->query_level() < MIN_LEADER_LVL) {
	tell_object(ob, "You need to be level "+MIN_LEADER_LVL+
	  " to start a gang.\n");
	return 0;
    }

    if (!ob->debit(GANG_COST)) {
	tell_object(ob, "You need "+GANG_COST+" credits to start a gang!\n");
	return 0;
    }

    return 1;
}

int create_new_gang( string name, object leader ) {
    name = lower_case(name);

    if (gang_exists(name)) return GANG_EXISTS;

    gang_list += ([ name : leader->query("name") ]);
gang_members += ([ name : 1 ]);

leader->set("gang", name);

save_all();

return 1;
}

void create()
{
    seteuid( ROOT_UID );
    load_saved_data();
}                       

/* EOF */
