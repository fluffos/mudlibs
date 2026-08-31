#include <std.h>
#include <cp.h>
inherit RUNE_WEAP;

void create() {
  ::create();

    set_name("freshly forged bow");
    set_id( ({ "bow", "freshly forged bow" }) );
    set_short("a freshly forged bow");
    set_long("This bow has been freshly forged. It is "
         "made of a special steel that allows it to "
        "bend a little. The string could easily have "
	"more tension added to it. On the front of the "
	"bow are three empty slots big enough for small "
	"stones.");
    set_type("ranged");
    set_ac(1);
    set_wc(5);
    set_wield("You grasp on to your freshly forged bow.");
    set_unwield("You release your grasp on your bow.");
    set_weight(14);
    set("value", 100000);
 }
int query_auto_load() {
      object tp=this_player();
      int tp_lvl=(this_player()->query_level());
      if(tp_lvl >=1) {return 1;}
      else {return 0;}
}
