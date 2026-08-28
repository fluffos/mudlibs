inherit MONSTER;

create_monster ()
{
  set_name (({ "a drunk", "drunk", "man" }));
  set_short ("a drunk is boozing here");
  set_long (
    "A smelly disgusting old man. He is drinking spirits here and "
  + "sobbing how bad a person he is.\n");

  set_race ("thari");
  set_wander (1, random(60) + 128);
  set_gender (1);
  set_alignx (-250 + random(500));
  set_aligny (-250 + random(500));

  set_skill_chance("dodge", 5);

  set_talk (({ "Give me a dime, please.. ",
               "Gglglg... " }));

  set_emote (({ "A drunk whines.",
                "A drunk takes a drink.",
                "A drunk smells bad." }));

  add_money (random(3));
}
