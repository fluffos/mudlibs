#include "path.h"
inherit "/std/outside";   

void setup ()     
{   
   add_property("no_undead",1);
        set_short("Realm of the Orc:  Staircase");   
        set_light(40);   
   set_long("\n   Realm of the Orc:  Staircase.\n\n"
            "     You are now at the begining of the hard part of the path "
		 "up to the the Tower of Grisnath. The tower is on the top "
		 "of the mountain and to get there you must climb all the way "
		 "to the top. "
		"\n\n");

        add_item(({"path", "stairs"}), "This path is leading up and down "
				       "from the Tower. The path here is "
				       "small and you can see that the "
				       "path is smaller on the way up "
				       "to the tower.\n"); 

        
add_item("tower", " \n"
"  The tower has many spires all grasping toward the heavens. "
"The spires are long and look fiendish as if they have "
"some evil purpose.\n\n");
         
	add_exit("northeast",CASTLE +"orc32","path"); 
	add_exit("down",CASTLE +"orc31","path");        

	set_zone("staircase");  
}//end setup 

