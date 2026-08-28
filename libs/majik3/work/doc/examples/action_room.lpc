// action_room.c
//   - example of add_action() function, by Namhas (29.07.97)

inherit ROOM;

create_room ()
{
  set_light (1);
  set_area ("example");
  set_short ("action room");
  set_long (
    "You are standing in a strange example room. You feel like you could "
  + "pull torch which is placed on the western wall.\n");

  add_item ( ({ "torch", "wall", "western wall" }),
             "You see a small wooden torch placed on the western wall. You feel "
           + "like you could pull it.\n");
}

init ()
{
  ::init();

  add_action ("do_pull", "pull");
}

do_pull (string str)
{
  if (!str || str != "torch")
    {
      notify_fail ("Pull what?\n");
      return 0;
    }

  write ("You slowly turn the torch and... *KABOOM* the room explodes!\n");
  THIS->move ("/world/hell");
  destruct (this_object ());

  return 1;
}

