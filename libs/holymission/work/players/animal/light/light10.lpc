inherit "room/room";
 
#define me capitalize(this_player()->query_name())
 
reset(arg) {
    if(arg) return;
#if 0 
    ::reset(arg);
    set_light(1);
    set_outdoors(4);
#endif
    set_light(1);
    long_desc = "A cheerful forest.\n" +
         "\n" +
         "     You have entered a cheerfull looking forest. Birds\n" +
         "     are singing and squirrels are running through the trees.\n" +
         "     You have a sense of total tranquility here.\n" +
         "\n";
    short_desc = "Cheerful forest";
    dest_dir = ({
        "/players/animal/light/light19", "west",
        "/players/animal/light/light3", "east"
    });
    items = ({
        "squirrels","Many small squirrels run around here",
        "trees","The trees are all oak trees, and HUGE ones at that",
        "birds","Birds of all kinds are singing happily in the trees",
    });
    return;
}
 
query_long() {
    return long_desc;
}
 
query_light() {
    return 1;
}
 
init() {
          ::init();
          add_action("search","search");
}
 
search(str) {
    if (!str) str = "room";
    if (str == "room") {
          write("You find nothing unusual.\n");
          say(me + " searches the room.\n");
            return 1;
        }
     return 0;
}
 
query_outdoorness() { return 4; }
 
 
