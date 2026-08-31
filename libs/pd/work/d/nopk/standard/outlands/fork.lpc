inherit "std/room";

void create() {
  ::create();
    set_property("forest", 1);
    set_property("light", 2);
    set("short", "A fork in the road");
    set("long",
        "Several paths diverge here through the jungle area "
        "known infamously as the Outlands.  Your life is in danger "
        "here as no form of law exists.  The path back to civilization "
        "is the one to the northwest.  To the north is a large thicket of bushes.");
    set_items(
        (["path" : "There are three of them here.",
	  "bushes" : "There is a large thicket of bushes.  It is doubtful you could pass through them.",
	  "paths" : "The northwest one leads towards civilization."])  );
    set_invis_exits(({"north"}));
    set_pre_exit_functions(({"north"}), ({"check_north"}));
    set_exits( 
(["northwest" : "/d/nopk/standard/outland2",
"east" : "/d/nopk/standard/outlands/t_path",
"enter" : "/d/nopk/tirun/wand/gypsy/gypsy_join",
"southwest" : "/d/nopk/standard/outlands/hideout",
"north" : "/d/guilds/lastsaints/rooms/tirunhall"]) );
}
void reset() {
    ::reset();
    if(!present("wagon"))
new("/d/nopk/tirun/obj/misc/wagon")->move(this_object());
}

int check_north() {
   if(this_player()->query_original_guild() != "lastsaints" && !wizardp(this_player())) {
	write("You cannot pass.");
	return 0;
   }
   write("You pass through the bushes with ease.");
   return 1;
}
