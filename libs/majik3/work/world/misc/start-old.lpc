// coder: namhas

inherit ROOM;

string file, dir, dest, old_dir, old_dest;
int y, x, forward, old_i, delay,superspeed;

create_room ()
{
  y = random (WORLD_D->query_max_y());
  x = random (WORLD_D->query_max_x());

  file = "/world/y"+y+"x"+x;
  delay = 60;

  this_object()->move(file);

  set_light (1);
  set_name ("object");
  set_short ("Default starting room");
  set_long ("You are standing in the default starting. There is nothing special. "+
    "You can 'jump' out of this flying starting location to the wilderness.\n");
  add_exit ("up", "/world/city/wiz/hall");
  add_exit ("down", "/home/namhas/wizapp");
  add_exit ("north", "/home/namhas/office");
  add_exit ("west", "/home/dazzt/plaque");
  add_exit ("east", "/home/namhas/albert/rooms/room0");
  add_exit ("south", "/home/namhas/area1/rooms/entrance");
  add_exit ("jump","/world/y27x27");
  add_exit ("portal", "/world/misc/start");
  add_object ("/world/misc/board");

  call_out ("do_move", delay);
}

do_portal ()
{
  write ("You enter to the portal.\n");
  EXPLORE_D->teleport();
  return 1;
}

do_move ()
{
  int i;

  if (forward) {
  i = old_i;
  forward--;
  delay = 40 + random(15);
  }
  else {
  i = random(sizeof(ENV(this_object())->query_exit_dir()));
  old_i = i;
  delay = 50 + random(30);
  }

  dir = ENV(this_object())->query_exit_dir()[i];  
  dest = ENV(this_object())->query_exit_dest()[i];

  if (superspeed)
  {
    superspeed--;
    delay = random(5) + 5;
    if (!superspeed)
      message ("environment", "The room slows down.\n",
        all_inventory(this_object()));
  }
 
  if (random(100) < 5 && !superspeed)
  {
    message ("environment", "The room speeds up to the highest speed.\n",
      all_inventory(this_object()));
    superspeed = random(10) + 1;
    delay = random(5) + 5;
  }
  else if (old_dir != dir) {
    message ("environment", "The room shakes as it changes direction.\n",
      all_inventory(this_object()));
    forward = random(3)+1;
  }
  else
    message ("environment", "The room seems to move forward.\n",
      all_inventory(this_object()));
  
  old_dir = dir;
  old_dest = dest;

  tell_room (environment(), "The flying room speeds up and disappears to "+dir+".\n");
  this_object()->move(dest);
  tell_room (environment(), "The flying room slows down as it arrives from "+dir+".\n");
  file = file_name(ENV(this_object()));
  remove_call_out ("do_move");
  call_out ("do_move", delay);
}

query_short ()
{
  return "An unidentified flying object (floating)";
}

extra_long ()
{
  if (environment(THIS) != this_object())
    {
      return "This flying object seems to be the flying starting location,\n"+
                  "you can jump back to it by typing 'jump'.\n";
    }
  else
    {
      return "You are standing in a default starting location. It has small window "+
                  "on it, looking down from the window you see that we are flying over "+
                  "the "+environment(this_object())->query_terrain()+". You can jump out "+
                  "by typing 'jump'.\n";
    }
}

init ()
{
  if (environment(THIS) == this_object())
    ::init();

  add_action ("do_jump", "jump");
  add_action ("do_peer", "peer");
  add_action ("do_up", "up");
  add_action ("do_up", "u");
  add_action ("do_portal", "portal");
}

do_peer (string str)
{
  if (str == "jump") {
    write ("You can't peer down through those thick clouds.\n");
    return 1;
  }
  return 0;
}

do_up ()
{
  if (THIS->query_level() < 100)
    {
      write ("A strong magic field materializes in front of you and blocks your movement.\n");
      return 1;
    }
}

do_jump ()
{
  if (environment(THIS) != this_object())
    {
      write ("You jump to the flying starting location which is floating about 20 meters from the ground.\n");
      message ("environment", capitalize(THIS->query_name()) + " jumps up to the " +
        "flying starting location.\n", environment(THIS), THIS);
      THIS->move(this_object());
      message ("environment", capitalize(THIS->query_name()) + " jumps here through " +
        "the window.\n", environment(THIS), THIS);
      THIS->force_us("look");
      return 1;
    }

  if (   file->query_terrain() == "sea"
      || file->query_terrain() == "mountain"
      || file->query_terrain() == "peak")
    {
      write ("You can't jump to the "+file->query_terrain()+"!\n");
      return 1;
    }

  message ("environment", capitalize(THIS->query_name()) + " jumps out and lands on the " +
    file->query_terrain() + ".\n", environment(THIS), THIS);
  write ("You jump out:\n");
  THIS->move(file);
  message ("environment", capitalize(THIS->query_name()) + " jumps out from the flying room!\n", environment(THIS), THIS);
  THIS->force_us("look");
  return 1;
}

