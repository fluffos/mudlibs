inherit ROOM;

create_room ()
{
  set_short ("Underwater");
  set_long (
    "You are diving underwater. The oxygen is running out rapidly "
  + "and you feel urge to get on the surface.");

  set_light (-3);

  set_sounds (10, ({ "A shoal of fishes moves past you.",
                     "The water here is freezing cold!",
                     "You feel your lungs running out of oxygen.",
                     "A mermaid greets you.",
                     "The stream of water moves you forward.",
                     "A shark circles around you, obviously waiting your death.",
                     "You are helplessly falling down in the realm of fishes." }));

  set_heart_beat (1);
  add_exit ("north", "/world/misc/underwater");
  add_exit ("south", "/world/misc/underwater");
  add_exit ("east", "/world/misc/underwater");
  add_exit ("west", "/world/misc/underwater");
  add_exit ("northwest", "/world/misc/underwater");
  add_exit ("northeast", "/world/misc/underwater");
  add_exit ("southeast", "/world/misc/underwater");
  add_exit ("southwest", "/world/misc/underwater");
}

heart_beat ()
{
  object o, *all;

  all = all_inventory(THOB);

  if (!all || sizeof(all) == 0)
    return;

  foreach (o in all)
    {
      if (living(o))
        o->add_hp (-random(100));
    }
}
