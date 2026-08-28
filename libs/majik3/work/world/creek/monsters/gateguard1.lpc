inherit MONSTER;

create_monster ()
{
  set_name (({ "a gateguard", "guard", "gateguard", "man" }));
  set_short ("a gateguard is standing here in guard");
  set_long (
    "Sturdy looking young man. He is wearing the elite guards armour and "
  + "a deadly looking halberd. He could probably chop you in two if you'd "
  + "try to attack him. He looks honest and would probably give his life "
  + "for the city in need.\n");

  set_race ("thari");
  set_levels ((["fighter":65]));
  set_gender (1);
  set_alignx (250 + random(500));
  set_aligny (1000 + random(500));

  set_skill_chance("dodge", 80);

  set_emote (({ "A gateguard examines you carefully.",
                "A gateguard looks around boredly.",
                "A gateguard polishes his deadly looking halberd.",
                "A gateguard eyes you suspiciously." }));

  add_money (random(10));
}

before_battle (object ob)
{
  call_out ("do_shout", random(5), ob);
}

do_shout (object ob)
{
  object o;

  "/command/mortal/say"->main ("Let's kick "+ob->query_cap_name()+"'s butt!");

  o = present ("gateguard 2");

  if (o)
    {
      if (o != THOB)
        {
          o->force_us("kill "+ob->query_name()+"");
        }
    }

  call_out ("wake_guard", 20 + random(10), ob);
}

wake_guard (object ob)
{
  "/world/creek/daemons/guard"->wake_guard (ob);
}
