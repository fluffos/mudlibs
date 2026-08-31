#include <std.h>
#include <aciri.h>
inherit MONSTER;

int oi=0;

void create() {
 ::create();
   set_name("rider");
   set_short("a shadow rider");
   set_long("The rider's body is composed of negative light shadows. Instead of "
     "the common black, the shadow is a light greyish white. The rider sits "
     "atop a shadowy mount, much like itself.");
   set_level(46);
   set_id(({ "shadow", "shadow rider", "rider" }));
   set_auto(6);
   set_class("fighter");
   set_race("shadow");
   set_body_type("human");
  if (random(4) >= 2)
   set_gender("female");
  else
   set_gender("male");
   set_heart_beat(1);
}

void heart_beat() {
  ::heart_beat();
   if (oi) return;
   new(MOB"mount2")->move(environment(this_object()));
   force_me("ride mount");
   oi = 1;
}
