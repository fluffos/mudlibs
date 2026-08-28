inherit MONSTER;

int flying_level;

create_monster ()
{
  set_name ("dragon");
  set_short ("a friendly golden dragon");
  set_long ("This dragon seems to be very friendly. You can 'mount dragon' if you want.\n");
  set_msgin ("flies in");
  set_msgout ("flies away to the");
  flying_level = 0;
}

long ()
{
  if (ENV(THIS) != THOB)
    {
      return "This dragon seems to be very friendly. You can 'mount dragon' if you want.\n";
    }
  else
    {
      return "You are sitting on the dragonback. You can see below you:\n--\n"+
        ENV(THOB)->long() + "--Type 'dismount' to dismount the dragon and 'ride <direction>' to move.\n";
    }
}

init_monster ()
{
  add_action ("do_mount", "mount");
  add_action ("do_dismount", "dismount");
  add_action ("do_ride", "ride");
}

do_ride (string str)
{
  if (str == "n" || str == "s" || str == "w" || str == "e" || str == "nw" || str == "ne" || str == "sw" || str == "se")
    {
      if (!flying_level) {
        if (!random(3)) write ("The dragon suggest you to move 'up'.\n");
      }

      if (flying_level > 1) {
        write ("The dragon moves ... \n\n");
        for (int i=0;i<flying_level;i++) {
          if(i>5)
            break;
          command (str);
          write (ENV(THOB)->query_short() + "\n");
        }
        write ("\n");
      }
      else
        command (str);

      if (flying_level == 10)
        write ("The speed is incredible!\n");
      else
        write ("The dragon moves by your command.\n");
    }
  else if (str == "u" || str == "up")
    {
      if (flying_level == 10)
        write ("The dragon refuses to move more upwards.\n");
      else {
        write ("Whee! ..we are flying high!\n");
      flying_level++;
      }
    }
  else if (str == "d" || str == "down")
    {
      if (flying_level == 0)
        write ("The dragon is already on the ground.\n");
      else {
        write ("The dragon flies now slightly more near ground.\n");
      flying_level--;
      if (flying_level == 0) {
        write ("The dragon is now on the ground.\n");
        tell_room (environment(THOB), "The dragon lands.\n");
      }
      }
    }
  else
    write ("The dragon didn't quite understand.\n");

  return 1;
}

do_dismount (string str)
{
  if (!str || str != "dragon")
    return 0;

  if (flying_level)
    {
      write ("You can't, ride dragon 'down' first!\n");
      return 1;
    }

  write ("You crawl down from the dragonback.\n");
  tell_room (environment(THIS), THIS->query_cap_name() + " dismounts himself.\n", ({ THIS }));
  THIS->move (ENV(THOB));
  tell_room (environment(THIS), THIS->query_cap_name() + " jumps down from the dragonback.\n", ({ THIS }));
  return 1;
}

do_mount (string str)
{
  if (!str || str != "dragon")
    return 0;

  if (flying_level)
    {
      write ("You can't reach dragon. It is moving just too high.\n");
      return 1;
    }

  write ("You step on the dragonback.\n");
  tell_room (environment(THIS), THIS->query_cap_name() + " steps on the dragonback.\n", ({ THIS }));
  THIS->move (THOB);
  tell_room (environment(THIS), THIS->query_cap_name() + " mounts himself.\n", ({ THIS }));
  return 1;
}

query_dragon ()
{
  return flying_level;
}
