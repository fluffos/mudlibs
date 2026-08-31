inherit "room/room";
 
reset(arg) {
    if (arg) return;
#if 0 
    ::reset(arg);
    set_light(1);
    set_outdoors(4);
#endif
    set_light(1);
    short_desc = "Mountain top";
    no_castle_flag = 0;
    long_desc = "Mountain top\n\n" +
          "   You feel great! You have climbed the mountain.\n"
        + "   The view from up here is magnificent! FAR down\n"
        + "   below you, you can see the great tree of Silverthorne.\n"
        + "   There appears to be a cave entrance to the north.\n\n"; 
     items = ({
     "tree", "The great tree looks TINY from up here",
     "mud", "Now why would you want to look at the mud?",
     "cave","Enter it to get a better look",
     });
    dest_dir = 
        ({ 
        "players/animal/light/light6", "north", 
        "players/animal/light/light14", "down", 
        }); 
} 
 
query_light() { 
    return 1;  
} 
 
query_outdoorness() {  return 4; }
realm() { return "NT"; }
