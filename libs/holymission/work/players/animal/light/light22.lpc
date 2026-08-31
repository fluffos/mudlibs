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
    long_desc = "Forest\n\n" +
        "     The forest here is quite dense. There seems to a lack of\n" +
        "     sunlight here. The ground shows no sign of travel. Off in the\n"+
        "     distance you hear the sounds of forest creatures, but there\n" +
        "     are no sounds that are close to you. The forest ground here is\n"+
        "     bare of pine needles, and looks like it has been burnt.\n" +
         "\n";
    short_desc = "Forest";
    dest_dir = ({
        "/players/animal/light/light23", "west",
        "/players/animal/light/light19", "east"
    });
    items = ({
        "ground","The ground is barren and burnt here",
    });
    return;
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
 
