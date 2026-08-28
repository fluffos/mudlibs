inherit MONSTER;

create_monster ()
{
  set_name (({ "Octavius", "high", "priest", "high priest", "man", "octavius" }));
  set_short ("Octavius, the High Priest of Aluna is performing a ceremony here");
  set_long (
    "Octavius is one of the true followers of Aluna. He is pure in his faith.\n");

  set_race ("thari");
  set_levels ((["caster":100]));
  set_gender (1);
  set_alignx (1500);
  set_aligny (1500);

  set_skill_chance("dodge", 25);

  set_talk (({ "Goodness shall rule!",
               "Let the good gods forgive your sins!",
               "Pray for Aluna!",
               "Join to the path of goodness!",
               "Aluna will save you!" }));

  set_emote (({ "Octavius blesses you.",
                "Octavius sings for Aluna.",
                "Octavius whispers a quiet prayer.",
                "Octavius smiles." }));

  add_money (random(1) + 0);
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
  "/command/mortal/shout"->main("Guards! "+ob->query_cap_name()+
    " is trying to killing me at "+lower_case(ENV(THOB)->query_short())+".");

  call_out ("wake_guard", 3 + random(5), ob);
  return 1;
}

int
wake_guard (object ob)
{
  "/world/creek/daemons/guard"->wake_guard (ob);
  return 1;
}
