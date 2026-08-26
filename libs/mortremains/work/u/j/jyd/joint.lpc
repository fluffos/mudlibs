/* File    : joint.c
// Purpose : Fun emotes
// Date    : 13/01/2000
// Author  : JYD
*/

#include <mudlib.h>

inherit OBJECT;

int smokes_left;

void create(){
    seteuid(getuid());
    set("id", ({ "joint", "spliff" }) );
    set("short", "A big, dutch joint");
    set("long", @Desc
A nice White-Widow - Nepal joint. You think smoking it will give
you much pleasure.
Desc
    );
    set("value", 0);
}

void init() {
    smokes_left = 20;
    add_action("smoke","smoke");
}

int smoke(string str) {

    if (!str) {
       write("Smoke what?\n");
       return 1;
    }
    
    if (str == "joint") {
	say(this_player()->query("cap_name")+" takes a big puff "+
      "out of his dutch joint.\n");
      write("You smoke your joint... Ahhh...\n");
      smokes_left -= 1;
      if (smokes_left < 1) {
        write("You smoked up all the joint!\n");
        destruct(this_object());
      }
      return 1;
    }
    return 0;
 
}