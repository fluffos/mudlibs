#include <std.h>
#include <aciri.h>
inherit MONSTER;

int oi=0;

void create() {
 ::create();
   set_name("priest");
   set_short("a silver robed priest");
   set_long("The priest has been sent here by his church to prevent "
     "lost souls from going further into the tower. His silver robes "
     "flower gracefully about his body.");
   set_gender("male");
   set_heart_beat(1);
   make(ARM"srobes");
}

void heart_beat() {
 ::heart_beat();
   if (!oi) { force_me("wear robes"); oi = 1; }
}
