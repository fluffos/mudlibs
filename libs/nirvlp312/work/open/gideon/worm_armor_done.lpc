/* Intox rate increased by Daranath, via spending of bug points Sept 12th, 2002 */
/* Armor increased by Daranath, via spending of additional bug points Sept 12th, 2002 */
/* All changes were gonna be done by Verte, but he left.... */

#include "/players/maledicta/ansi.h"
#define USER environment()
inherit "obj/armor";

reset(arg) {
if(arg) return;
 ::reset(arg);
set_name("platemail");
set_alias("demonic platemail");
set_short(HIR+"Demonic Platemail"+NORM);
set_long(
"  This is a demonic suit of Unholy Armor. It shimmers with\n"+
"an inner darkness of powerful energies. This armor was\n"+
"forged by Demons of dark for the Legendary Master of the\n"+
"of Underworld "+HIR+"Worm"+NORM+".\n");
set_ac(5);
set_type("armor");
set_weight(3);
set_value(15000);
}

get(){ 
if(this_player())
if(this_player()->query_real_name() != "worm" && this_player()->query_level() < 20){
write("You are unable to grasp such a powerful artifact!\n");
return 0;
}
return 1;
}



do_special(owner){
int bonus;
bonus = 0;
if(present("demonic_shield_worm", environment())){
   bonus += 33 + random(25);
   }

if(random(90) < USER->query_attrib("int") + bonus && USER->query_soaked()){
   tell_object(USER,
   "You feel a purifying energy course through your body...\n\n"+
   "    "+HIR+" D E M O N I C"+NORM+RED+"   I N"+NORM+HIR+" F U S I O N"+NORM+"\n\n"+
   "Your body is cleansed...\n");
   USER->add_soaked(-(1+random(2)));

   tell_room(environment(USER),
   USER->query_name()+" is momentarily surrounded by a cleansing aura...\n", ({USER}));
   return 1;
   }
else if(random(100) < USER->query_attrib("wil") + bonus && USER->query_stuffed()){
   tell_object(USER,
   "Your armor draws energy from the earth"+BOLD+"..."+NORM+"\n\n"+
   "     "+BOLD+"< < <  "+HIG+"C L E A N S I N G   M I G H T"+NORM+BOLD+"  > > >"+NORM+"\n\n"+
   "Impurities are carried down into the ground and dissipate.\n");
   tell_room(environment(USER),
   USER->query_name()+" is covered in a soft glow that dissipates into the ground...\n", ({ USER }));
   USER->add_stuffed(-(1+random(2)));
   return 1;
   }
return 0;
}	
	
