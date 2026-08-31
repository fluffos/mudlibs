inherit "room/room";
 
reset(arg) {
    if (arg) return;
#if 0 
    ::reset(arg);
    set_outdoors(4);
#endif
    set_light(1);
    short_desc = "Village street";
    no_castle_flag = 0;
    long_desc =
        "Village\n"
        + "\n"
        + "     This is a small little mountain village nestled in\n"
        + "     heart of the Bridger mountain range. The mountains are\n"
        + "     huge and breathtaking. Off to the east lies a pub and\n"
        + "     off to the west lies the bank.\n\n";
	items = ({
        "mountains","The mountians are beautiful",
        "pub","This is an old style pub, complete with a dragon on the sign",
        "bank","The First Bank of MUD is to the west",
	});
    dest_dir =
        ({
        "players/animal/shops/shop_street2", "north",
        "players/animal/light/light14", "south",
        "players/animal/shops/pub","east",
        "players/animal/bank/bank","west",
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
