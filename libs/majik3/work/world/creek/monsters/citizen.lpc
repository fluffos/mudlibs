inherit MONSTER;

#include "../path.h"

create_monster ()
{
  set_name (({ "a citizen", "citizen", "man", "thari" }));
  set_short ("a citizen is walking here");
  set_long (
    "A normal looking man going on his daily routines, talking with "
  + "friends and planning how to spend his vacation.\n");

  set_race ("thari");
  set_wander (1, random(60) + 60);
  set_gender (random(2) + 1);
  set_alignx (-150 + random(400));
  set_aligny (-150 + random(400));

  add_money (random(10));
}

int
before_battle (object ob)
{
  call_out ("do_shout", random(3), ob);
  return 1;
}

int
do_shout (object ob)
{
  "/command/mortal/shout"->main("Help me! "+ob->query_cap_name()+
    " is killing me at "+lower_case(ENV(THOB)->query_short())+".");

  call_out ("wake_guard", 3 + random(5), ob);
  return 1;
}

int
wake_guard (object ob)
{
  "/world/creek/daemons/guard"->wake_guard (ob);
  return 1;
}
