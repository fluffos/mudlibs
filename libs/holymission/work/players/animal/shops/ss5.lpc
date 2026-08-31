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
        + "\tShop street contiunues to run west and east here.\n"
        + "\tAlong this street lies many shops that are ready\n"
        + "\tto steal, er, take your money for services they\n"
        + "\tprovide. Off to the north lies the brewery and to\n"
        + "\tthe south the hospital.\n\n";
        items = ({
        "brewery","Buy a keg!",
        "hospital", "You get fixed in there",
          });
    dest_dir =
        ({
        "players/animal/shops/hospital", "south",
        "players/animal/shops/brew","north",
        "players/animal/shops/shop_street4","east",
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
