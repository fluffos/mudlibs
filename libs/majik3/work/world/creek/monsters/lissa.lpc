inherit MONSTER;

create_monster ()
{
  set_name (({ "Lissa", "lissa", "bard", "elf", "woman" }));
  set_short ("Lissa the elven bard is singing a song here");
  set_long (
    "A beautiful young elven lass who is singing softly by herself. "
  + "The song has a sad theme and tears start rolling down your cheeks. "
  + "*sniff*\n");

  set_race ("lindor");
  set_wander (1, random(256) + 128);
  set_gender (2);
  set_alignx (250 + random(500));
  set_aligny (250 + random(500));

  set_emote (({ "Lissa sings beautifully." }));

  add_money (random(200) + 50);
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
