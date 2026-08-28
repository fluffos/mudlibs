inherit "/std/Object";

void create() {
  //  Finds the position of a player in the landscape.
  ::create();
  set_name("sextant");
  set_id( ({ "sextant" }) );
  set_weight(25);
  set_value(80);
  set_short("A sextant");
  set_long(
"This device can be used to determine geographical position relative to a "
"known point.  Coordinates are meaured from the origin (0S, 0E) at the "
"northwest corner of the known world map.  This device may only be used "
"outside in the landscape.  Type 'locate'.");
  return;
}

void init() {
  ::init();
    add_action("find_pos", "locate");
    return;
}

int find_pos(string null) {
  int S, E;

  if(sscanf(base_name(environment(this_player())),
	    "/d/damned/virtual/room_%d_%d.world", E, S) != 2) {
    write("This device must be used outside.");
    return 1;
  }
  write("Your position relative to the nortwest corner of the map is:\n"+
	sprintf("    -*> %d South, %d East <*-", S, E));
  return 1;
}



