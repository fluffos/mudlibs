#include <std.h>
#include <arlon2.h>
inherit ARMOUR;

int fix_limbs() {
  switch(this_player()->query_race()) {
    case "horse": set_limbs( ({ "torso" }) ); break;
    case "weimic": set_limbs( ({ "feline torso" }) ); break;
    default: set_limbs( ({ "horse torso" }) );
  }
  return 1;
}

void create()
{
 ::create();
 set_name("saddle");
 set_short("%^BOLD%^a platinum saddle%^RESET%^");
 set_long("This saddle is made from pure platinum, obviously belonging to one of the snobbish horses of Arlon.");
 set_ac(1);
 set_id( ({ "saddle", "platinum saddle" }) );
 set_mass(10);
 set_type("saddle");
 set_limbs(({"horse torso"}));
 set_wear( (: fix_limbs :) );
  set_curr_value("gold", 20+random(30));
}
int query_auto_load() { return 1; }
