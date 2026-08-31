#include <std.h>
#include <cp.h>
inherit RUNE_WEAP;

void create() {
  ::create();

    set_name("freshly forged staff");
    set_id( ({ "staff", "freshly forged staff" }) );
    set_short("a freshly forged staff");
    set_long("This special staff has been crafted from "
         "a rare type of steel. It looks rather plain, "
        "just a long metal stick with leather wrapped "
	"around the middle for grips. In the center of "
	"the staff are three empty slots big enough for small "
	"stones.");
    set_type("blunt");
    set_ac(1);
    set_wc(5);
    set_wield("You grasp on to your freshly forged staff.");
    set_unwield("You release your grasp on your staff.");
    set_weight(14);
    set("value", 100000);
 }
int query_auto_load() {
      object tp=this_player();
      int tp_lvl=(this_player()->query_level());
      if(tp_lvl >=1) {return 1;}
      else {return 0;}
}
