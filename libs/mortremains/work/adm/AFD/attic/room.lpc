// The New Room.c (probably old by the time you read this, of course)
// Brought to you by... Buddha@TMI (where else?)
// This file is part of the TMI/MudOS mudlib.  Please retain the header.
// Written 4-19-92 and onwards.
// Doors are added in the standard door object.
// The two files are seperate so that rooms without doors (ie, most) can
// save 50 or so bytes. It adds up in the end...
// Rust@TMI-2 (12-01-93) <-- (happy birthday Rust's mom!)
//        Changed the objects property, so that you can clone
//        multiple copies of an object without needing an id for each copy.
// (06-04-96) Chronos rewrote the reset function.  It still doesn't
//            clone things in quite right.  Dammit.
//            It's fixed - make that: It used to not work quite right. HA!
// (06-06-96) Chronos added the add_exit() function!

#include <config.h>
#include <exits.h>
#include <mudlib.h>
#include <daemons.h>

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
  set("capacity", 10000000);
  set("volume", 10000000);
  set("no_player_killing", 0);
  if(virtualp(this_object())) call_out("reset",0);
  else reset();
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
  if (ob_data["item_desc"] && ob_data["item_desc"][str]) return 1;
  if (ob_data["item_func"] && ob_data["item_func"][str]) 
  return 1;
}

/* Chronos sez: I really went to town on this function.  I removed about
 *              3 variables that weren't needed and simplified and 
 *              commented every line of this function. ;)
 *              I also formatted the code so you can figure out whats
 *              going on in there.  It's pretty confusing, otherwise.
 */
void reset() {
  int i, j, tally;
  string name;
  object* inv;
  string *objects;
  if (ob_data["objects"]) {
    objects = keys(ob_data["objects"]);
    for(j=0;j<sizeof(objects);j++) {
      if(!intp(ob_data["objects"][objects[j]]) && //form: <id>:<filename>
         !present(objects[j],this_object()) ) 
          clone_object(ob_data["objects"][objects[j]])->move(this_object());
      else {
        name =((string*)find_object_or_load(objects[j])->query("id"))[0];
        if(!name) continue;     // find an id for the object.
        inv = all_inventory(this_object());   // get the inv.
        tally = 0;                              // reset tally
        for(i=0;i<sizeof(inv);i++) if(inv[i]->id(name)) tally++; // tally up
        tally = (int)ob_data["objects"][objects[j]]-tally;
        for(i=0;i<tally;i++) clone_object(objects[j])->move(this_object());
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

void add_exit(string dir, string dest) {
  if (!dir) return ;
    if (!dest) return ;
  set("exits/"+dir, dest);
}
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
// Just in case we need to load the weather daemon...
  seteuid(getuid()) ;
  WEATHER_D->request_weather_notices(this_object()) ;
  return ;
}

// This calls out to the weather daemon to check the ambient light.

int query_ambient_light() {
  return (int)WEATHER_D->query_ambient_light() ;
}
/* EOF */
 
