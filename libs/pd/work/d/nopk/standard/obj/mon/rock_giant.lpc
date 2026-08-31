#include <std.h>
#include <sindarii.h>
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
   new(WEP"boulder")->move(this_object());
   this_object()->force_me("wield boulder");
}

int is_invincible() {
   call_out("do_throw", 1, this_player());
   return 0;
}

void do_throw(object tp) {
   this_object()->force_me("throw boulder at "+tp->query_name());
}
