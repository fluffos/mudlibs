//File: BACKSTABED.c 
//Purpose: To make sure a player is only backstabed once.
//Date: July 24th, 1997
// 06 Jan 97  Cyanide added suuport for the kill_ob changes.

#include <mudlib.h>
#include <daemons.h>

void purge_invis_func();

inherit OBJECT;
void create() {
  seteuid(getuid());
  set("id", ({ "#HIDE_OB#", "#INVIS_OB#" }) );
  set("long", "If you are a player and see this, contact Nightmask.\n");
  set("prevent_get", 1);
  set("prevent_drop", 1);
  set("prevent_give", 1);
  set("prevent_insert", 1);
  set("mass", 0);
  set ("dest_at_die", 1);
 }

void init() {
add_action("go", "go");
}

int go(string str){

   this_object()->set("move_counter", 
      (this_object()->query("move_counter") - 1) );

   if ((int)this_object()->query("move_counter") == 1)	
   purge_invis_func();

return 0;
}


void purge_invis_func() {
   say(this_player()->query("cap_name")+" steps from the shadows.\n");
   write("You step from the shadows.\n");
   this_player()->set("invisible", 0);
   this_player()->do_new();
   return;
}

void upon_attacking() {
   purge_invis_func();
}
