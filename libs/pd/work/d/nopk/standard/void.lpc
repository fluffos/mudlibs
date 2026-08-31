#include <config.h>
#include <std.h>
#include <tirun.h>
inherit ROOM;

void init() {
  ::init();
if(!wizardp(this_player()))
    add_action("any_hook", "", 1);
}

void create() {
  ::create();
    set("short", "The void");
    set("long",
"Blackness.  Nothing can be seen.  Nothing exists here.\n"
"The void streches out obliterating the senses.");
    set_exits( 
	      (["square" : ROOMS"square"]) );
    set_property("light", 1);
    add_pre_exit_function("square", "go_square");
    call_out("clean_up_room", 600);
}

/* patched by Valodin April 16, 1993 */
int any_hook(string str) {
    string start;

    if(this_player()->is_monster()) return 0;
    if (start = this_player()->getenv("start"))
       this_player()->move_player(start);
    else
       this_player()->move_player(ROOMS"square");
    return 0;
}

int go_square() {
  if(!this_player()->is_player()) return 0;
  return 1;
}

int clean_up_room() {
   object *o;
   int i;
   i=sizeof(o=all_inventory(this_object()));
   while(i--)
     if(o[i]->is_player()) continue; else
    if(o[i]->id("orb_quest_tombar")) continue; else o[i]->remove();
    call_out("clean_up_room", 600);
}
