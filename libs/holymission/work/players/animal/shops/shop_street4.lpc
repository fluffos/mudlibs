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
	+ "\tThis is the new section of town, shops are being added\n"+
	"\teveryday, not just shops though, specialty places also!\n"+
	"\tTo the north lies the lobby of Condo Village! \n"+
	"\tThere is a pet store south.\n\n";
        items = ({
        "shop","This is the little shop of Animal's horrors",
        "magic shop", "This place sells magic items",
          });
    dest_dir =
        ({
	"players/animal/shops/pstore","south",
	"players/animal/shops/ss5","west",
        "players/animal/closed/lobby","north",
	"players/animal/shops/shop_street3","east",
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
