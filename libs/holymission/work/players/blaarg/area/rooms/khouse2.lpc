#include "/players/blaarg/defs.h"
inherit "room/room";
reset(arg) {
	clone_list = ({
	     1,1,"kunoh","obj/monster", ({
		"set_name","Kunoh";
    		"set_short("Kunoh Tatewaki");
    		"set_long","Ranma's bitter enemy, Kunoh tries everything "+
			    "in his power to steal Akane and <<the " +
			    "Pigtailed Girl>> from him.\n";
		"set_level",15;
		"set_al",-1000;
		"set_hp",450;
		"set_gender",1;
		"set_race","anime";
		"add_money",250;
		"set_wc",15;
		"set_ac",8;
		"set_number_of_arms",2;
	     })
	     -1,1,"sword","obj/weapon", ({
		"set_name","sword";
		"set_alt_name","sword";
		"set_short","Kunoh's wooden sword";
		"set_long","This is Kunoh's wooden sword...despite its "+
		           "material it is quite powerful due to its weapon "+
			    "magic.\n";
		"set_type",2;
		"set_class",4;
		"set_value",1500;
		"set_weight",3;
	     }),
	});
	set_light(1);
	short_desc="Kunoh's Bedroom",
	long_desc=
	    "This is Kunoh's bedroom. He doesn't look too happy that you\n"+
	    "are disturbing his privacy, but after a few seconds he gets\n"+
	    "used to your presence. There is a bed, a window, a mat on\n"+
	    "the floor, a dresser, and a picture on the dresser.\n";
	dest_dir=({
	    AROOMS+"khouse1","south",
		 });
	items=({ 
	   "bed","A pretty nondescript bed."
	   "window","Ypu can see the mountains from here",
	   "mat","A pretty average mat",
	   "dresser","Wood, but the drawers are stuck",
	   "picture","A picture of Akane", 
	   });
	smell = "Kunoh's room smells like he hasn't cleaned it for years";
	::reset(arg);
	replace_program("room/room");
}
