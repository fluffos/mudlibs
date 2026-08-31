//Tirun Sewers Monster
//By Nightshade

#include <std.h>
#include <sewer.h>

inherit MONSTER;

void create() {
 ::create();
   set_name("demon");
   set_id(({"demon", "attacking demon"}));
   set_short("Attacking Demon");
   if(random(2) == 0)
     set_gender("male");
   else
     set_gender("female");
   set_long("This demon is fighting "+possessive(this_object())+" way out of the depths of hell, "
        "trying to work "+possessive(this_object())+" way out into the "
        "world to cause havoc and chaos.");
   set_race("demon");
   set_body_type("demon");
   set_alignment(-1399);
   set_level(28);
   this_object()->add_money("gold", random(80));
   if(random(4) == 0)
     new(ARM"dhelm")->move(this_object());
   if(random(20) == 0)
     new(ARM"wingmail")->move(this_object());
   new(WEP"dblade")->move(this_object());
   force_me("wield blade");
   force_me("wear wingmail");
   force_me("wear helm");
}

void die() {
   "/d/sewers/obj/questcheck"->do_death_check(this_object()->query_current_attacker());
   ::die(1);
}

void init() {
   ::init();
   if(this_player()->query_alignment() >= 1400) {
     call_out("do_say", 2);
     this_object()->kill_ob(this_player());
   }
}

void do_say() {
     this_object()->force_me("say Curse your goodness!  Die, like all mortals should!");
}
