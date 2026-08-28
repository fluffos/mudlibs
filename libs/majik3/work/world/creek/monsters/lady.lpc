inherit MONSTER;

create_monster ()
{
  set_name (({ "a lady", "lady", "woman" }));
  set_short ("a lady is here walking and chatting with people");
  set_long (
    "A good looking young lady, who has come out to walk and chat with "
  + "people. She notices you looking at her and blushes a bit for she "
  + "is not wearing her best clothes as usually.\n");

  set_race ("thari");
  set_wander (1, random(60) + 60);
  set_gender (2);
  set_alignx (250 + random(500));
  set_aligny (250 + random(500));

  set_talk (({ "Oh, what a lovely day today.",
               "Nice weather isn't it?",
               "I just love this city!" }));

  set_emote (({ "A lady smiles happily." }));

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
