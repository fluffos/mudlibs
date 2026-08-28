inherit ROOM;

create_room ()
{
  set_short ("Hell");
  set_long ("You are surrounded by a chaotical environment of fire and brimstone. 'Pray' if you feel like it.\n");
  set_no_explore (1);
  set_light (1);
}

init ()
{
  add_action ("do_hell", "", 1);
}

int
do_hell (string str)
{
  if (query_verb() == "pray")
    {
      THIS->revive();
      write ("You pray and disappear.\n");
      EXPLORE_D->teleport();
      return 1;
    }
  else if (query_verb() == "look" || query_verb() == "l" || query_verb() == "la")
    {
      "/command/mortal/look"->main(str, THIS);
      return 1;
    }
  else
    {
      write ("You are dead - unable to "+query_verb()+".\n");
      return 1;
    }
}
