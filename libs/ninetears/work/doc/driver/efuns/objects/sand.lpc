/*
   Sand for FR omiq - wibble on
*/
inherit "/std/object";

setup()
{
  set_name("sand");
  set_short("sand");
  set_long("Sand\n");
  set_weight(5);
}

init()
{
  ::init();
  add_action("throw_sand", "throw*", 100);
}

throw_sand(string fish)
{
  if(!fish) return 0;
  if (fish="sand on fire" && present("omiq_fire", environment(this_player())))
  {
    write("As you throw the sand on the fire it dies down and goes out.\n");
    tell_room(environment(this_player()), this_player()->query_cap_name()+
		" throws sand on the fire and it goes out.\n", this_player());
    present("omiq_fire", environment(this_player()))->dest_me()
    call_out("dest_me", 0);
    return 1;
  }
  notify_fail("Nothing to throw.\n");
  return 0;
}
