inherit MONSTER;

create_monster ()
{
  set_name (({ "a mage student", "mage student", "mage", "student" }));
  set_short ("a student of Academy of Magic is muttering some strange words here");
  set_long (
    "A young fellow dressed in deep blue robes. He is apparently a "
  + "student in the Academy of Magic. He hasn't gained full wizardhood "
  + "yet and is quite poor in his magic but he is sure he will be "
  + "something someday.");

  set_race ("thari");
  set_wander (1, random(60) + 128);
  set_gender (1);
  set_alignx (-250 + random(500));
  set_aligny (-250 + random(500));
  set_levels (([ "caster" : 10 ]));

  set_skill_chance("dodge", 5);

  set_emote (({ "A mage student concentrates on a cantrip.",
                "A mage student mutters some strange words.",
                "A mage student casts a cantrip, and smiles.",
                "A mage student fails miserably on his spell.",
                "A mage student screams loudly.",
                "A mage student gestures some arcane symbols in the air." }));

  add_money (random(3));
}
