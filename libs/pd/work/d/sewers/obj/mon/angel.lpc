//Tirun Sewers Monster
//By Nightshade

#include <std.h>
#include <sewer.h>

inherit MONSTER;

void create() {
 ::create();
   set_name("angel");
   set_id(({"angel", "archangel", "defending angel"}));
   set_short("Defending Angel");
   if(random(2) == 0)
     set_gender("male");
   else
     set_gender("female");
   set_long("The angel is fighting valiantly, protecting the world above "
        "from the carnage that would enter it if the demons here were to "
        "escape.");
   set_race("archangel");
   set_body_type("archangel");
   set_alignment(1399);
   set_level(28);
   this_object()->add_money("gold", random(80));
   if(random(4) == 0)
     new(ARM"helmoj")->move(this_object());
   if(random(20) == 0)
     new(ARM"wingmail")->move(this_object());
   new(WEP"bsabre")->move(this_object());
   force_me("wield sabre");
   force_me("wear wingmail");
   force_me("wear helm");
}

void die() {
   "/d/sewers/obj/questcheck"->do_death_check(this_object()->query_current_attacker());
   ::die(1);
}

void init() {
   ::init();
   if(this_player()->query_alignment() <= -1400) {
     call_out("do_say", 2);
     this_object()->kill_ob(this_player());
   }
}

void do_say() {
     this_object()->force_me("say Vile being!  You shall perish for your sins!");
}
