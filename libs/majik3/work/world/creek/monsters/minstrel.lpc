inherit MONSTER;

create_monster ()
{
  set_name (({ "an elven minstrel", "elf", "man", "minstrel", "elven" }));
  set_short ("an elven minstrel is deep in thoughts making a new song");
  set_long (
    "A young elf who has come here to find an inspiration for his new "
  + "song. The minstrel has a golden blonde hair past his shoulders and "
  + "a fair complexion.\n");

  set_race ("lindor");
  set_gender (1);
  set_alignx (300 + random(600));
  set_aligny (300 + random(600));
  set_wander (1, 150);

  set_emote (({ "An elven minstrel ponders something.",
                "An elven minstrel tries some new chords from his luth." }));

  add_money (random(50));
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
