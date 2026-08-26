#include <mudlib.h>

inherit ARMOR ;

void create() {
  set ("id", ({ "cap", "jester cap", "jester's cap" }) ) ;
  set ("short", "a jester's cap") ;
  set("long", @ENDLONG
A multi-colored cap with a LOT of bells hanging from each point.
ENDLONG
  );
  set ("mass", 20) ;
  set ("bulk", 15) ;
  set("value", 0) ;
  set ("armor", 0) ;
  set_armor_type("helmet") ;
  set("size", -1) ;
  set("value", 350 ) ;
} 

void init() {
  add_action("move_pl", "sneak");
  add_action("move_pl", "go");
}

int move_pl(string str) {
 if (!TO->query("equipped")) return 0 ;
  if (!str) return 0;
  say(TPN+"'s jester cap jingles noisily.\n") ;
  call_other("/cmds/std/_go", "cmd_go", str);
  say(TPN+"'s jester cap jingles noisily.\n") ;
  write("The jester cap on your head jingles noisily.\n") ;
  return 1;
}

