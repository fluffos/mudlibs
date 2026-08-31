/*Room description corrected by Silas*/
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
    long_desc = "Small ravine\n\n" +
         "     You have entered a small ravine. The ravine looks\n" +
         "     like it was made by water of a river long since vanished.\n" +
         "     The river walls are dry and steep.\n\n";
    short_desc = "Small ravine";
    dest_dir = ({
        "/players/animal/light/light15", "south",
        "/players/animal/light/light3", "west"
    });
    items = ({
        "walls","The river walls are way too steep to climb here",
        "wall","The wall is too steep to climb",
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
          add_action("climb","climb");
          add_action("search","search");
}
 
climb(str)  {
          if(!str) {
               write("Climb what?\n");
               return 1;
          }
               if(str == "walls" || str == "wall" || str == "the walls") {
          write("There is no way to climb here.\n");
     say(me + " tries to climb the river wall but fails.\n");
          return 1;
          }
     return 0;
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
 
