inherit "room/room";
#include "/players/dakeyras/define.h"
#include "/players/dakeyras/color.h"
reset(arg){
    if(arg) return;
    set_light(1);
short_desc="A Fork In The Road";
long_desc=
"You have come to a fork in the road.  The road branches to the north, east, and\n"+
"west here, as well as going back south, to the clearing.  Looking down the path\n"+
"to the west it seems to grow dark and the hairs on the back of your neck rise up.\n"+
"To the north is more forest.  To the east the forest seems to grow a little\n"+
"less dense.  A signpost sits here.\n";

items=({
     "road","A well traveled dirt road",
		"path","A well traveled dirt road",
	       "forest","The trees are packed so close together as to block \n"+
	       "anything that may lay behind",
		"trees","The trees are packed so close together as to block \n"+
	       "anything that may lay behind",
		"signpost","A large wooden signpost with arms pointing in \n"+
		"different directions.  Maybe you should 'read' the signpost",
		});

	

dest_dir=({
		"/players/dakeyras/areas/ckingdom/fp1","north",
		"/players/dakeyras/areas/portal2","south",
		});
  }

init() {
  ::init();
add_action("read","read");
add_action("smell","smell");
add_action("listen","listen");
}



smell(){
	write("The smell of death from the west combatting with the fresh \n"+
			"air and smells of nature around you.\n");
	return 1;
	}

listen(){
	write("A hard wind from the west blows in odd noises that \n"+
			"make you fidgit nervously.\n");
	return 1;
}


read(str) {
if(str != "signpost") return 0;
say(TPN+" studies the signpost.\n");
write("The signpost reads:\n\n"+
"North -"+BOLD+BLU+ "Coastal Kingdom" +NORM+ "\n"+
"West -" +BOLD+ "The Dark Forest" +NORM+ "\n"+
"East -" +YEL+ "Miner's Town" +NORM+ "\n\n"+
"Mud mail me any suggestions, comments, bugs, or typos.\n\n"+
"       -Dakeyras\n");
return 1; }
