inherit ROOM;

#include "../path.h"

int cloned = 0;

create_room ()
{
  set_light (1);
  set_outdoors (1);
  set_no_clean_up (1);

  set_short ("Post office");
  set_long ("You are standing in a post office which once was known as "
    + "gnome & brownie co., but now poor little brownie is dead, killed "
    + "by our evil lord, Sinister. "
    + "However, gnome has now a new comrade, big one, a mailer daemon!\n");

  add_door ("down", ROOM_PATH + "vault", "door", "wooden", 0, 10, 2);

  add_exit ("south", ROOM_PATH + "room2");

  /* let's hope this doesn't clone more daemons */

  remove_call_out ("do_gnome");
  call_out ("do_gnome", 10 + random(15));
}

do_gnome ()
{
  object ob;
  remove_call_out ("do_gnome");
  if (cloned != 1)
    {
      tell_room (THOB, "Gnome crawls to his feet and whistles sharply!\n");
      ob = load_object (MONSTER_PATH + "gnome");
      ob->move (THOB);
      call_out ("do_messenger", 3 + random(3));
      cloned = 1;
    }
  return 1;
}

do_messenger ()
{
  object ob;
  remove_call_out ("do_messenger");

  ob = load_object (MONSTER_PATH + "messenger");
  ob->move (THOB);
  tell_room (THOB, "Daemon wakes up and grumbles angrily.\n");

  return 1;
}

do_alarm (object who)
{
  object gnome;

  gnome = present("gnome", THOB);
  gnome->do_alarm(who);
  return 1;
}

