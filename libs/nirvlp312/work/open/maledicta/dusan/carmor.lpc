#include "/players/maledicta/ansi.h"
inherit "obj/armor";
int lights;
reset(arg) {
set_name("armor");
set_alias("combat");
set_short("Combat Armor");
set_long(
"   A suit of combat armor. It is made from a heavy material that\n"+
"is highly resistant to ballistic fire and blasts. It covers the\n"+
"torso of the wearer. A light can be found on the left shoulder.\n"+
"Use, 'lights' to toggle it on and off.\n");

set_ac(4);
set_type("armor");  
set_weight(8);
set_value(800);
set_arm_light(0); 
lights = 0;
}

init(){
   ::init();
   add_action("light_toggle", "lights");

   }

 light_toggle(){
 	if(lights){
 	lights = 0;	
 	set_arm_light(0);
 	write("You deactivate the light.\n");
	return 1;
	}       
	else{
	lights = 1;	
	set_arm_light(1);	
	write("You activate the light.\n");
	return 1;	
          }
}