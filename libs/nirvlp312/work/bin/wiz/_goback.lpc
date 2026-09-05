mapping rooms;

void reset(int x)
{
  if(x) return;

  rooms = ([]);
}

void set_room(string nm, string fn)
{
  rooms[nm]=fn;
}

int cmd_goback()
{
  string fn;
  if(!(fn=rooms[(string)this_player()->query_real_name()]))
  {
    write("You haven't updated your environment since reboot.\n");
    write("Quit slacking.\n");
    return 1;
  }
  write("\nYou return to your updated location...\n");
  this_player()->move_player("X#"+fn);
  return 1;
}

