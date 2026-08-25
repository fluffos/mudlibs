//Ljen -97
//Coded by Yalaba on the 29th of August of '96

inherit "/std/outside";
#include "path.h"

void setup(){
   set_short("Jungle Town");
   set_long("From here the path continues north and south, "
            "further north there is the orchard where a little group "
            "of elves are working on.  From here you can see to the south "
            "east a bigger shack."
	    " This seems to be a quiet part of town, where the shadows"
	    " rest deep between the shacks.\n");

   add_clone(NPC+"h_elf1",2);

   set_light(80);   

   add_exit("north" , TOWN+"d2"  ,  "path");
   add_exit("south", TOWN+"d4"   ,  "path");
}

