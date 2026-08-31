#include <std.h>
#include <lodos.h>
inherit MONSTER;

void create() {
 ::create();
   set_short("a young maid");
   set_id( ({ "maid", "girl" }) );
   set_name("maid");
   set_level(15);
   set_long("The maid busily scrubs away at the walls and floor, "
     "always a chore on hand. The young girl looks like she just "
     "started working in the tower.");
   set_body_type("human");
   set_race("faerie");
   set_gender("female");
   make(ARM"b_dress");
   make(OBJ"mop");
   call_out("force_me", 1, "wear dress");
}

