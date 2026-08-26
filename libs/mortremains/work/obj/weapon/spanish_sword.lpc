//spanish_sword.c
//This is a spanish sword.
//It was created by Kalifax (at TMI-2, 8/28/94)

#include <mudlib.h>

inherit WEAPON ;

void create () {
      set ("id", ({ "sword", "spanish sword"}) ) ;
      set ("short", "a beautiful spanish sword") ;
      set ("long", "A finely crafted spanish sword. It's handle is decorated\n"+
        " with beautiful jewels. It's blade is incredibly sharp.\n") ;
      set_weapon_type("sword/long");
      set_material_type("metal/fine steel");
      set ("value", 1000);
      set ("name", "spanish sword") ;
      set_bonus(0,1,0);  //Non-magical, +1 to hit, +0 to damage.
      set_verbs( ({ "swing at", "slash at", "cut"}) ) ;
      set_verbs2( ({ "swings at", "slashes at", "cuts"}) ) ;
}
