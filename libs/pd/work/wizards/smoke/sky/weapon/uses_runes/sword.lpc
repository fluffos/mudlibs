#include <std.h>
#include <cp.h>
inherit RUNE_WEAP;

void create() {
  ::create();

    set_name("freshly forged sword");
    set_id( ({ "sword", "freshly forged sword" }) );
    set_short("a freshly forged sword");
    set_long("This sword is extremely basic. A long blade "
         "which could easily be sharper connects to a "
        "finely gripped handle. On the handle are three "
	"empty slots big enough for small stones.");
    set_type("blade");
    set_ac(1);
    set_wc(5);
    set_wield("You grasp on to your freshly forged sword.");
    set_unwield("You release your grasp on your sword.");
    set_weight(16);
    set("value", 100000);
 }
int query_auto_load() {
      object tp=this_player();
      int tp_lvl=(this_player()->query_level());
      if(tp_lvl >=1) {return 1;}
      else {return 0;}
}
