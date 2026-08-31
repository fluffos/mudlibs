#include <std.h>
#include <tirun.h>
inherit MONSTER;
int wielded_wep=0;
void create() {
 ::create();
   set_name("giant");
   set_id(({"giant", "rock giant"}));
   set_short("a huge rock giant");
   set_long("The monsterous giant stands about 25 feet tall, and has "
       "bulky muscles under a pale grey skin. She glowers at you, "
       "waiting for you to attack.");
   set_gender("female");
   set_race("giant");
   set_body_type("human");
   set_level(26);
   set_heart_beat(1);
   new(WEP"boulder")->move(this_object());
}

void heart_beat() {
 ::heart_beat();
   if (!wielded_wep) {
      this_object()->force_me("wield boulder");
      wielded_wep = 1;
   }
}

int is_invincible() {
   this_object()->force_me("throw boulder at "+this_player()->query_name());
   return 0;
}
