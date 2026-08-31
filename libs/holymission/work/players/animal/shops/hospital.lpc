inherit "room/room";
 
reset(arg) {
    if (arg) return;
#if 0 
    ::reset(arg);
    set_outdoors(1);
#endif
    set_light(1);
    short_desc = "The soon to be done Hospital";
    no_castle_flag = 0;
    long_desc =
        "Hospital\n"
        + "\n"
        + "\tThis is the soon to be done entrance to the soon\n"
        + "\tto be done hospital of Animal's.  This will contain\n"
        + "\tall the latest in medical care, like plastic surgery\n"
        + "\tfor those UGLY scars you have, and of course, an ER.\n\n";
    dest_dir =
        ({
        "players/animal/shops/ss5", "north",
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

