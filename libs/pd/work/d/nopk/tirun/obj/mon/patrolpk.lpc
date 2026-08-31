#include <std.h>
#include <tirun.h>
inherit MONSTER;
int oi = 0;
void create()
{
 ::create();

 set_name("Guard");
 set_id(({"guard", "member" }));
 set_short("member of the town guard");
 set_long("The town guard is the force that enforces the laws of Tirun. They are "
"the known peacekeepers of this town.");
 set_race("human");
if (random(10) >  5)
 set_gender("female");
else
 set_gender("male");
 set_body_type("human");
 set_heart_beat(1);
 new(WEP"bclub")->move(this_object());
}

void heart_beat() {
 ::heart_beat();
 if (!oi) {
// new(WEP"bclub")->move(this_object());
 command("wield club"); 
 oi = 1;
 }
}
