inherit "room/room";

int no_way_out(string str);


int no_way_out(string str)
{
  string com;
  
  com=query_verb();

  if(com=="bend guild" || com=="bend church")
    {
      write("You try to return to your guild but its too far!\n");
      this_player()->move_player("vanishes!#/players/ambrose/avalon/city/cath");
      return 1;
    }
  return 0;
}
