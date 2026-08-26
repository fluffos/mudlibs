inherit "/std/room/basic_room";

int squish(string cmd);

void setup() {
   set_short( "jail" );
   add_property( "determinate", "the " );
   add_property("no teleport", 1);
   add_property("no godmother", 1);
   set_light( 100 );
   set_long("This room is designed to suppress players from performing "
            "many standard actions.  The allowed actions are tell, "
            "say, liaisons, who, i, inventory, give, drop, look, and "
            "emote.  No other commands, abbreviations or any other "
            "permutation of a command will work.  As this room is used "
            "for disciplinary purposes, if you find yourself alone in "
            "this room, you should contact a liaison immediately.\n");
} /* setup() */

void clean_up( int i ) { return; }

// prevents people doing things they shouldn't in here. It will screw up their
// start position and allow them to use this to trans to the drum.
void init() {
  ::init();
  if (!this_player()) return;
  this_player()->command_override((: squish :));
}

int squish(string cmd) {
  if(creatorp(TP)) {
    return 0;
  }
  if (cmd == "quit" ||
      cmd == "quit2" ||
      cmd == "save" ||
      cmd == "su" ||
      cmd == "godmother") {
    write( "I don't think so.\n" );
    return 1;
  } else if(cmd[0..3] == "tell" ||
            cmd[0..7] == "liaisons" ||
            cmd[0..2] == "who" ||
            cmd[0..2] == "say" ||
            cmd[0..0] == "i" ||
            cmd[0..8] == "inventory" ||
            cmd[0..3] == "give" ||
            cmd[0..3] == "drop" ||
            cmd[0..3] == "look" ||
            cmd[0..4] == "emote") {
      return 0;
  } else {
    write("You are in jail, and are forbidden from performing any commands.  "
          "Contact a liaison if you're the only one here.\n");
    return 1;
  }
}
