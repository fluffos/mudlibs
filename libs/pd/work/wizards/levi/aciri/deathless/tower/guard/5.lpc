#include <std.h>
#include <aciri.h>
inherit MONSTER;

int oi=0;

void create() {
 ::create();
   set_name("queren");
   set_short("Commander Queren, the crazed");
   set_long("Once upon a time, long, long ago, Queren's army was "
     "supreme above all others. After a long reign, the commander's "
     "troops were finally defeated, all were slain. Queren escaped "
     "to the tower, where he sought refuge. Eventually his mind "
     "snapped when he discovered the true horror of this place. "
     "Everyone is an enemy to Queren now, and as the fifth guardian "
     "of the tower, he will not let anyone pass.");
   set_level(53);
   set_race("artrell");
   set_body_type("artrell");
   set_gender("male");
   set_auto(20);
   set_properties(([ "no bump" : 1 ]));
   set_heart_beat(1);
   make(ARM"arobes");
   make(WEA"asword");
   make(WEA"asword");
   make(WEA"asword");
   make(WEA"asword");
}

void heart_beat() {
 ::heart_beat();
   if (!oi) { force_me("wear robes");    force_me("wield sword");
              force_me("wield sword 2"); force_me("wield sword 3");
              force_me("wield sword 4"); oi = 1; }
}

int stop_up() {
   write("Queren fights you back down..");
   return 1;
}

void init() {
 ::init();
   add_action("stop_up", "up");
}
