#include "/players/jenny/define.h"
inherit "/obj/monster";
int hps, ohps, dmg1, dmg2;
reset(arg)
{
   ::reset(arg);
    if (arg) return;

   set_name("testmonster");
set_alt_name("monster");
   set_alias("test monster");
   set_short("A test monster");
        set_long("This is a test monster for wizards to test weapons or\n"+
"spells on.  PLAYERS ARE NOT TO USE THIS!  DO NOT LEAVE\n"+
"THIS IN AN AREA PLAYERS CAN ACCESS.\n"+
"TO see average damage per round, type 'totals.'\n");
   set_level(1);
   set_hp(1000);
   set_al(10);
   set_wc(3);
   set_ac(0);
}
init() {
        add_action("totals","totals");
        add_action("clear","clear");
}
heart_beat(){
   int HPS;

   ::heart_beat();
   HPS=this_object()->query_hp();
   ENV(this_object());
   if(this_player()->query_attack()) {
     hps  = 1000 - HPS;
     if(hps > 0) {
       dmg1 = hps + dmg1;
       dmg2 = 1 + dmg2;
       say(""+CYN+"You did "+hps+" hp of damage."+NORM+"\n");
     }
   this_object()->heal_self(1000);
   }
}
totals() {
        if(dmg2 < 1) {
        write("The test monster says: You have to fight me first.\n");
                return 1; }
        write("Totals are as follows:\n");
        write("Total Damage: "+dmg1+"\n");
        write("Total Rounds: "+dmg2+"\n");
        write("Average Damage: "+dmg1/dmg2+"\n");
        write("\nType 'clear' to reset the variables back to 0.\n");
        return 1;
        }
clear() {
        write("Resetting all variables.\n");
        dmg1 = 0;
        dmg2 = 0;
        return 1; }
