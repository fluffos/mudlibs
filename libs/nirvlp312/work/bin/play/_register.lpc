/*
Originally written by Mythos for his Sci-watch.
Modified by Feldegast for use in /bin
4-14-00
*/

int cmd_register(string str) {
  int moo;
  if(this_player()->query_ghost()) {
    write("You are a ghost!\n");
    return 1;
  }
  if(this_player()->query_fight_area())
    moo = 1;
  call_other(this_player(),"reset",1);
  this_player()->recalc_quest();
  if(moo)  /* Reset the fight area because it was unset by reset */
    this_player()->set_fight_area();
  command("soul off");
  command("soul on");
  write("Registered....\n");
  return 1; 
}
