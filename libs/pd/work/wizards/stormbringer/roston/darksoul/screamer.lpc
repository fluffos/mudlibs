#include <std.h>
#include <roston.h>
inherit MONSTER;

int i;

void create() {
 ::create();
   set_name("%^BOLD%^%^BLACK%^man%^RESET%^");
   set_short("A Man");
   set_id(({"man"}));
   set_long("This man is shackled up to the wall and looks like "
            "he's in extreme pain");
   set_level(4);
   set_hp(1);
   set_gender("male");
   set_race("human");
   set_heart_beat(1);
   set_body_type("human");
 }

void heart_beat()
{
 ::heart_beat();
 i++;
 if (i > 10) {
    i = 0;
    this_object()->force_me("emote %^BOLD%^BLACK%^screams in %^RED%^agony"
        " %^BLACK%^as a spike shoots from the wall into his back!");
   }
}
