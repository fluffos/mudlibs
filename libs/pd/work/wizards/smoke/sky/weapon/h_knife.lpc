#include <std.h>
#include <cp.h>
inherit WEAPON;

int extra_wield();
int extra_unwield();
object tp;
string cap_tp;

void create() {
  ::create();

    set_name("hunting knife");
    set_id( ({ "knife", "hunting knife" }) );
    set_short("hunting knife");
    set_long("The deadly blade glistens in the light. It has a "
         "serrated edge for skinning and gutting animal carcasses."
        " Upon touching the dagger, it glows with a %^YELLOW%^bright"
	 " golden aura.%^RESET%^");
    set_type("knife");
    set_ac(2);
    set_wc(10);
    set_weight(18);
    set("value", 150);
    set_decay_rate(2500);
      set_wield( (: extra_wield :) );
      set_unwield( (: extra_unwield :) );
}
int extra_wield() {
      tp=this_player();
      cap_tp=tp->query_cap_name();

      message("info","%^BOLD%^%^BLACK%^The dagger begins to %^YELLOW%^glow%^BLACK%^ "
"as you wrap your fingers around the handle.%^RESET%^ ",this_player());
      message("info",cap_tp+" stares at their hunting knife in awe.",environment(tp),tp);

      tp->add_stat_bonus("dexterity",2);
      tp->add_skill_bonus("murder",10);
      return 1; 
}
 int extra_unwield() {
      message("info","%^BOLD%^%^BLACK%^As you release the dagger, the %^YELLOW%^ "
"bright golden aura%^BLACK%^ fades out.%^RESET%^",this_player());
      message("info",cap_tp+" releases the hunting knife and "
"the demented look in their eyes vanishes.",environment(tp),tp);

      tp->add_stat_bonus("dexterity",-2);
      tp->add_skill_bonus("murder",-10);
      return 1; 
}
int query_auto_load() {
      object tp=this_player();
      int tp_lvl=(this_player()->query_level());

      if(tp_lvl >=50) {return 1;}
      else {return 0;}
}
