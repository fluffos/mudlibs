// corpse.c
// Real old. Probably came with the mudlib.n, and probably took some
// substantial hacking at TMI-1, though no one put a header on saying so.
// Converted to 0.9.0 by Mobydick@TMI-2, 9-22-92, who added this header.

#include <mudlib.h>
inherit CONTAINER ;

#define DECAY_TIME 100

string name;
int decay;

void prevent_insert() {
   write("The corpse is too big.\n");
   return ;
}

void create() {
 
   ::create() ;
 
   name = "noone";
   decay = 2;
 
   set ("mass", 2000) ;
   set ("bulk", 250) ;
   set ("short", "@@query_short") ;
   set ("capacity", 2000) ;
   set ("volume", 200) ;
   set ("prevent_insert", 1);
   set ("id", ({ "corpse", "remains", "body", "dead body",
		 "corpse of " + name }) );
}

void set_name(string str) {
 
   name = str;
 
   if(name)  name = capitalize(name);
   set_open_long("This is the dead body of " + name + ".\n");
   set("id", ({ "corpse", "remains", "body", "dead body",
		"corpse of " + name }) );
   set("cap_name", "@@query_short");
   call_out("decay", DECAY_TIME);
}
 
void decay() {
 
   decay -= 1;
 
   if(decay > 0) {
      call_out("decay", 20);
      return;
   }
   remove() ;
}
 
int can_put_and_get() { return 1; }
 
string query_short() {
   if(decay == 2)
      return "Corpse of "+name;
   else
      return "The somewhat decayed remains of "+name;
}

