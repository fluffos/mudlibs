#define JUKEBOX "players/arflebarfle/jukebox"
#define BLADDER "players/arflebarfle/bladder"
#define BARMAN "players/arflebarfle/barman"
reset(arg) {
    if (!arg) set_light(1);
    if(!present("jukebox"))
	move_object(clone_object(JUKEBOX), this_object());
    if(!present("barman"))
	move_object(clone_object(BARMAN), this_object());
}

init() {
    add_action("north","north");
    add_action("west","west");
    add_action("out","out");
    add_action("order", "order");
    /* Make drinking a more realistic experience! */
    if(!present("bladder", this_player()))
	move_object(clone_object(BLADDER), this_player());
}

short() {
    return "Inside an old, cosy and very comfortable bar";
}

long() {

    write("\n");
    write("You are in an old, cosy and very comfortable pub.\n");
    write("An open fire flickers brightly giving the whole room a very ");
    write("pleasent, homely feeling.  At one end of the room is a varnished ");
    write("wood bar.  The stone walls hold black and white photographs of ");
    write("Mudville as it use to be.\n\n");
    write("You feel very relaxed here.\n\n");

    write("The rest-rooms are to the west\n");
    write("To the north is a passage leading to a workroom\n");
    write("Out will take you back the way you came\n");
    write("You can 'order <name of drink>' if you want\n");
 }

north(){
    this_player()->move_player("into the workroom#players/arflebarfle/workroom");
    return 1;
}
west(){
    this_player()->move_player("into the restroom#players/arflebarfle/toilet");
    return 1;
}
out(){
    this_player()->move_player("onto the jetty#room/jetty2");
    return 1;
}    
