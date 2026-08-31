inherit "std/room";

void create() {
        ::create();
    set_property("light", 2);
    set("short", "The jungle south of Outland");
    set("long",
        "You are on a tiny path through the deep jungle south of the "
        "outlaw town of Outland.  The sounds of wild jungle animals "
        "come at you from all directions, but the brilliant colours of "
        "the deep jungle camouflage it all.  It is really hard to tell "
        "which ways you can go, and which ways you can't.");
    set_items(
        (["path" : "It is barely that.",
	  "jungle" : "The colours of all the life blur before your eyes.",
	  "trees" : "Huge tropical trees forming a humid organic cover.",
	  "plants" : "The lush vegetation is growing everywhere.",
	  "tree" : "It's huge!",
	  "plants" : "It is sooooo %^GREEN%^%^BOLD%^green.%^RESET%^",
	  "colours" : "They are really beautiful.",
	  "animals" : "You cannot see them since they are so well "
	    "camouflaged.",
	  "vegetation" : "Plants and trees."]) );
    set_exits( 
              (["north" : "/d/nopk/standard/outlands/dust3",
                "east" : "/d/nopk/standard/outlands/cover1",
                "west" : "/d/nopk/standard/outlands/cover2",
                "south" : "/d/nopk/standard/outlands/jungle2"]) );

    set_search(0, "You think you notice a way to move east and west.");
    set_search("jungle", "You think you notice a way to move both to theeast and the west.");
    set_search("trees", "You think you see a way to get through them east.");
    set_search("plants", "You think you see a way through them west.");
}

