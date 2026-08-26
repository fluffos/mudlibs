#include <std.h>

#include "/d/islands/tonerra/areadefs.h"
inherit ROOM;

void create(){
   ::create();

  set_no_clean(1);
   set_name("crevise");
   set_short("A crevise in the wall");
   set_long("%^C202%^This small tunnel in the wall is barely a foot in diameter. Small pebbles line the flooring and sparse "
			"%^C082%^vegetation %^C202%^covers the ceiling above you. The light from the volcano outside %^C190%^illuminates %^C202%^the area around you, "
			"however as you proceed it seems to get %^C052%^darker%^C202%^.\n");
   set_smell("default","Fumes from the still raging fires outside singe your nose.");
}

int GoThroughDoor(){
	if(TP->query_size() > 1 && TP->query_size() < 3){
	write("That is much to steep for you.");
return 0;}}
