// The New Room.c (probably old by the time you read this, of course)
// Brought to you by... Buddha@TMI (where else?)
// This file is part of the TMI/MudOS mudlib.  Please retain the header.
// Written 4-19-92 and onwards.
// Doors are added in the standard door object.
// The two files are seperate so that rooms without doors (ie, most) can
// save 50 or so bytes. It adds up in the end...
// No it doesn't.  But the two things should be seperate anyway =) -ed

// Rust@TMI-2 (12-01-93) <-- (happy birthday Rust's mom!)
//            Changed the objects property, so that you can clone
//	      multiple copies of an object without needing an id for each copy.

#include <config.h>
#include <exits.h>
#include <mudlib.h>
#include <daemons.h>
#include <priv.h>

inherit OBJECT ;
inherit "std/object/contents";

void reset();

void __INIT() { if (!ob_data) ob_data = ([]); }

void create() {
//call_out("reset", 0);  // this is good for virtual rooms.
//it may be good for virtual rooms, but it's bad for actual rooms,
//if you goto a room and force it to load, ob_data[objects] won't
//kick in when you enter.
//SO:
   __INIT();
       set("volume", 10000000, MASTER_ONLY); // Leto
       set("capacity", 10000000, MASTER_ONLY); // Leto
	if(virtualp(this_object()))
		call_out("reset",0);
	else
		reset();
}

int use_bogus_exit() {
	notify_fail(BOGUS_EXIT_MSG);
	return 0;
}

string *query_exit_dirs() { return keys(ob_data["exits"]); }
int valid_exit(string dir) {
	if (ob_data["exits"] && ob_data["exits"][dir]) return 1; 
}

int id(string str) {
	if (!str) return 0;
	if (ob_data["item_desc"] && ob_data["item_desc"][str]) 
		return 1;
	if (ob_data["item_func"] && ob_data["item_func"][str]) 
		return 1;
}

void reset() {
	int i, j, k, tally;
	string name;
	object* inv;
	object ob;
	string *objects;

	if (ob_data["objects"]) {
		objects = keys(ob_data["objects"]);
		i = sizeof(objects); while(i--){
//for compatibility with the old way
			if(!intp(ob_data["objects"][objects[i]])){
				if(!present(objects[i],this_object())){
  				  ob = new(ob_data["objects"][objects[i]]);
				  ob->move(this_object());
				}
			}else{
				name =((string*)find_object_or_load(objects[i])->query("id"))[0];
				if(!name) continue;
				inv = all_inventory(this_object());
					j = sizeof(inv);
					tally = 0;
					while(j--)
						if(inv[j]->id(name)) tally++;
					k = ob_data["objects"][objects[i]];
					k = k-tally;
					for(j=0;j<k;j++){
						ob = clone_object(objects[i]);
						ob->move(this_object());
					}
				}
		}
	}
	return;
}

// These functions are called from move(), but don't need to do anything.
// Should rooms fill up?  In 99% of the cases the max capacity of a room
// is irrelevant.

int receive_objects(object it) { return 1; }
// Is this one still called? I'm not sure. Moby, 10-3-92
int add_encumbrance(int x) { return 1; }

void remove_exit(string dir) {
	if(ob_data["exits"][dir]) delete("exits/" + dir);
}

// This is here to support outside rooms. If you define a room to
// be outside, then two things happen: the "outside" property is set to a
// capital letter (which indicates which weather zone it's in) and 
// the room's light property is overridden to call_out to the daemon
// to reflect outside light.

varargs void set_outside (string zone) {
	if (!zone) zone="A" ;
	set ("outside", zone) ;
	set ("light", "@@query_ambient_light") ;
// JIC we need to load the weather daemon...
	seteuid(getuid()) ;
	WEATHER_D->request_weather_notices(this_object()) ;
	return ;
}

// This calls out to the weather daemon to check the ambient light.

int query_ambient_light() {
	return (int)WEATHER_D->query_ambient_light() ;
}

/* EOF */
