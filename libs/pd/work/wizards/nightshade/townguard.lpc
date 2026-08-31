#include <std.h>
#include <tirun.h>
inherit "/std/police";
int oi = 0;
void create()
{
 ::create();
 set_name("Guard");
 set_id(({"guard", "member" }));
 set_short("A town guard");
 set_long("The town guard enforces the laws of Tirun. They are "
          "known to be fair but stern.");
 set_race("human");
 add_enforce("drugs");
if (random(10) >  5)
 set_gender("female");
else
 set_gender("male");
 set_body_type("human");
 set_level(30);
 set_max_hp(2000);
 set_hp(2000);
  set_swarm(1);
 set_heart_beat(1);
 new(WEP"bclub")->move(this_object());
}
void heart_beat() {
 ::heart_beat();
 if (!oi) {
 command("wield club"); 
 oi = 1;
 }
}
