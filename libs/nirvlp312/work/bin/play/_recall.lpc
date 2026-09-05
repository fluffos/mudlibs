int cmd_recall(string str)
{
  if(str) return 0;
  if((int)this_player()->query_level() > 7) return 0;
  if(basename(environment(this_player())) == "/players/softly/nhall/rooms/n1")
  {
    write("You're already in the Hall of Apprentices!\n");
    return 1;
  }
  write("You teleport back to the Hall of Apprentices.\n");
  this_player()->move_player("X#/players/softly/nhall/rooms/n1");
  return 1;
}
