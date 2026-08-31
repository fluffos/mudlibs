#include <std.h>
inherit MONSTER;

void create() {
    ::create();
   set_name("general");
   set_id( ({ "general", "goblin" }) );
   set_short("a goblin general");
  set_level(5);
   set_long("A strong goblin war general. His goal in life is "
            "simply to slay the weak.");
    set_body_type("human");
   set_alignment(0);
   set("race", "goblin");
   set_gender("male");
   new("/d/tirun/obj/weapon/ssword")->move(this_object());
}
