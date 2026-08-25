#include "path.h"   
inherit "/std/outside";   

void setup ()     
{   
   add_property("no_undead",1);
        set_short("Realm of the Orc:  Staircase");   
        set_light(40);   
        set_long("\n   Realm of the Orc:  Staircase.\n\n"
                 "     You are now at the hard part of the path up to the "
                 "the Tower of Grisnath. The path is small and you wonder "
		"why the tower is placed on a place like this. "
		"\n\n");

        add_item(({"path", "stairs"}), "This path is leading up and down "
				       "from the Tower. The path here is "
				       "small and you can see that the "
				       "path is smaller on the way up "
				       "to the tower.\n"); 

        
add_item("tower", "\n"
"  The tower has several spires reaching toward the heavens "
"in what appears to be an attempt to rip the heavens out of "
"the sky!! With fiendish 'fingers' the spires rise high "
"above the country side.\n");
                          "you're looking upon the Tower of Grishnath, "+   
	add_exit("southwest",CASTLE +"orc34","path"); 
	add_exit("up",CASTLE +"orc30","path");
        
	set_zone("staircase");  
}//end setup 
