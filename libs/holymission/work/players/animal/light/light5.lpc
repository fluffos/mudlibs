inherit "room/room"; 
 
reset(arg) { 
    if (arg) return; 
#if 0 
    ::reset(arg);
    set_light(1);
    set_outdoors(4); 
#endif
    set_light(1);
    short_desc = "Open space"; 
    no_castle_flag = 0; 
    long_desc = "Open space\n\n" + 
          "   You have come to a wide open area.\n" 
        + "   Off to the north lies a dark cave.\n" 
        + "   Back to the east lies the tree.\n\n"; 
    dest_dir = 
        ({ 
        "players/animal/light/light7", "north", 
        "players/animal/light/light3", "east", 
        "players/animal/light/light8", "west", 
        }); 
} 
 
query_light() { 
    return 1;  
} 
query_outdoorness() {  return 4; }
