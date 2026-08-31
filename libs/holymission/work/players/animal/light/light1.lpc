inherit "room/room";
 
reset(arg) {
    if (arg) return;
#if 0 
    ::reset(arg);
    set_outdoors(4);
#endif
    set_light(1);
    short_desc = "Entry to the world of light";
    no_castle_flag = 0;
    long_desc =
        "Entry.\n"
        + "     \n"
        + "     This is the entryway to the world of good.\n"
        + "     All good things can feel safe here. You feel a\n"
        + "     strong presence of good surrounding you.\n"
        + "\n";
    dest_dir =
        ({
        "/players/animal/light/light2", "north",
        "/players/animal/enterhall", "south",
        });
}
 
query_long() {
    return long_desc;
}
query_outdoorness() {
    return 4;
}
query_light() {
    return 1;
}
 
long() {
       ::long();
	if(this_player()->query_alignment() >= 0) {
       write("You feel like good is on your side.\n");
	return 1;
       }else{
       write("You feel unwanted here....\n");
	return 1;
       }
	return 1;
}
