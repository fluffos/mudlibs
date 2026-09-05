/* Temporarily had to change this. I used a function called Recalc_ac() which
   cannot be used because of the private in set_ac. I will change it back whenever
   the changes are added to living.c   Maledicta (7.99) */
#define USER environment(this_object())
#include "/players/maledicta/ansi.h"
inherit "obj/armor";
object shield;
int on;

reset(arg) {
set_name("shield");
set_alias("wrist");
set_short("Wrist Shield");
set_long(
"   A powerful wrist shield bracer. A focusing crystal is mounted\n"+
"on the top of it which projects a solid barrier of energy capable\n"+
"of deflecting nearly any attack. The shield feeds from the bodies\n"+
"natural energy, in a very efficient way.\n");
set_ac(2);
set_params("other|electric", 2, 5, "do_spec");
set_type("shield");  
set_weight(1);
set_value(1000);
}
short(){
	if(worn){
	return "Wrist Shield <"+HIY+"activated"+NORM+"> (worn)";
        }
	else{
 	return "Wrist Shield";
        }
       }


do_spec(object owner){
    if(!random(5)){
      tell_object(owner,
      "The shield crackles with power as it resists the energy!\n");
      return 0502;
      }
return 0;
}
wear(str)
{
  if(!id(str)) return 0;
if(worn) return 0;
if(this_player()->query_sp() < 60){
write("Your body does not have the energy to supply the wrist shield.\n");
return 1;
}
::wear(str);
this_player()->add_spell_point(-60);
write("You activate the wrist shield.\n"+
      "A focused field of energy sprouts from the focusing crystal.\n");
     return 1;
}
