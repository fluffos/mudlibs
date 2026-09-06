/* The South Plaza of Nightfall */

inherit "std/room";

void create() {
	::create();
	SetIntShort("The South Plaza");
	SetIntLong(
"You are standing on the South Plaza of Nightfall. Once this really was a "+
"nice place, but now it belongs to the worse parts of the city. You better "+
"watch your wallet, if you want to go further south.\n"+
"To the west you notice the famous Soul Food Cafe. The buildings become more "+
"and more shabby, when you look to the south.\n"+
"A rotten, wooden staircase leads down. On a dirty sign you can read C.A.R.T.\n");
        AddExit("west",   "/d/archwiz/randyandy/cafe1");
        AddExit("down",   "/d/archwiz/randyandy/station");
        AddExit("south",  "/d/archwiz/randyandy/plaza2");
        AddExit("north",  "/d/archwiz/common/room/city/southave4");  
        SetIndoors(0);
        SetIntSmell("You notice a tasty smell from the Soul Food Cafe.\n");
}

