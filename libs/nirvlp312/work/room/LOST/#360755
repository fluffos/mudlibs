inherit "/room/room";

void reset(status arg) {
  object board;
  if(!present("Wizard Ideas")) {
    board=clone_object("/players/illarion/test/board");
    board->set_name("Wizard Ideas");
    move_object(board);
  }
  if(arg)
    return;
  set_light(1);
  short_desc="An inner room of the adventurer's guild";
  long_desc=
"This is the wizard idea room.  The main board is east from here.\n"+
"only wizards can access this room.\n";
  dest_dir=({"room/adv_inner","east"});
}
