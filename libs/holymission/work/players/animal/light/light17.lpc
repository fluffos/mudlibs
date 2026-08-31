inherit "room/room"; 
 
reset(arg) { 
    if (arg) return; 
#if 0 
    ::reset(arg); 
    set_outdoors(4); 
#endif
    set_light(1); 
    short_desc = "End of the praire"; 
    no_castle_flag = 0; 
    long_desc = "Praire end\n\n" + 
          "     The praire comes to an end here. The rest of the\n" 
        + "     praire will be open one day. Not for awhile though.\n" 
        + "\n"; 
    dest_dir =  
        ({ 
        "players/animal/light/light16", "west", 
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
