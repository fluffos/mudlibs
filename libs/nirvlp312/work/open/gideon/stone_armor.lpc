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
set_alias("crystalline platemail");
set_short(HIW+"Crystalline Platemail"+NORM);
set_long(
"  This is a beautiful suit of Crystalline Armor.  It glistens\n"+
"with an inner glow of powerful energies. This armor was forged\n"+
"by the Gods of Light for the Great Defender "+HIB+"Stone"+NORM+".\n");
set_ac(4);
set_type("armor");
set_weight(3);
set_value(15000);
}

get(){ 
if(this_player())
if(this_player()->query_real_name() != "stone" && this_player()->query_level() < 20){
write("You are unable to grasp such a powerful artifact!\n");
return 0;
}
return 1;
}



do_special(owner){
int bonus;
bonus = 0;
if(present("crystalline_shield_stone", environment())){
   bonus += 30 + random(20);
   }

if(random(90) < USER->query_attrib("int") + bonus && USER->query_soaked()){
   tell_object(USER,
   "You feel a purifying energy course through your body...\n\n"+
   "    "+HIB+" C R Y S T A L L I"+NORM+BLU+" N E  I N"+NORM+HIB+" F U S I O N"+NORM+"\n\n"+
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
	
