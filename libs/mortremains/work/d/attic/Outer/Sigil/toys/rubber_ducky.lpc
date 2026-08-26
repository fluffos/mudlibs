#include <mudlib.h>

inherit OBJECT;

void create() {
  set ("short", "a yellow rubber ducky");
  set ("long", @ENDLONG
It's a cute little rubber ducky, just like the one Chronos had when he
was a small child!
Maybe you could "squeeze" it.. 
ENDLONG
);
  set ("id", ({ "duck", "rubber duck", "rubber ducky", "ducky" }) );
 set("author", "Chronos") ;
  set ("mass", 1);
  set ("bulk", 1);
  set("value", 25) ;
}

void init() {
// if user types "squeeze", execute the "squeeze_ducky".
// function, passing any arguments, if any.
  add_action("squeeze_ducky", "squeeze");
}

int squeeze_ducky(string str) {
// Check arguments.
  if (str != "duck" && str != "ducky" && str != "rubber ducky") return 0;
  write("You squeeze your ducky and it squeaks merrily!\n");
  say(this_player()->query("cap_name")+ 
        " squeezes " + possessive(this_player()->query("gender")) +
                        " ducky and it squeaks merrily!\n");
  return 1;
}

