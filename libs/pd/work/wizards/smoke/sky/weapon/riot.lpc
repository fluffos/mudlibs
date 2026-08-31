#include <std.h>
#include <cp.h>
inherit WEAPON;

int extra_wield();
int extra_unwield();
object tp;
string cap_tp;

void create() {
  ::create();

    set_name("riot blade");
    set_id( ({ "sword", "blade", "riot blade" }) );
    set_short("riot blade");
    set_long("This sword is used in the Steel Hammer Jail. The "
         "guards use it to keep the prisoners from getting out "
        "of line. It doesn't look fancy by any means.");
    set_type("blade");
    set_ac(2);
    set_wc(13);
    set_weight(25);
    set("value", 175);
    set_decay_rate(2500);
      set_wield( (: extra_wield :) );
      set_unwield( (: extra_unwield :) );
}
int extra_wield() {
      tp=this_player();
      cap_tp=tp->query_cap_name();

      message("info","%^BOLD%^%^BLACK%^The blade fits perfectly "
"in your hands.%^RESET%^ ",this_player());
      message("info",cap_tp+" wields the riot blade and is "
		 "now ready to smite some criminals.",environment(tp),tp);

      tp->add_stat_bonus("strength",2);
      tp->add_skill_bonus("attack",10);
      return 1; 
}
 int extra_unwield() {
      message("info","%^BOLD%^%^BLACK%^You wipe the blood from "
"your blade and put it away..%^RESET%^",this_player());
      message("info",cap_tp+" wipes the blood off their "
"blade and puts it away.",environment(tp),tp);

      tp->add_stat_bonus("strength",-2);
      tp->add_skill_bonus("attack",-10);
      return 1; 
}
int query_auto_load() {
      object tp=this_player();
      int tp_lvl=(this_player()->query_level());

      if(tp_lvl >=50) {return 1;}
      else {return 0;}
}
