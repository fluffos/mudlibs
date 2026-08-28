inherit MONSTER;

create_monster ()
{
  set_name (({ "cazares", "archmage", "guildmaster" }));
  set_short ("Cazares the Archmage is here, waiting for students");
  set_long (
    "Cazares is an ageless looking man, he has a long white beard and "
  + "long hair, yet his eyes are crystal clear and he is more clever "
  + "than the young tricksters. He is wearing a robe of an archmage, "
  + "many coloured, consntatly changing from the hues of red to the "
  + "shades of blue. He looks at you as if considering are you worthly "
  + "enough to be his student.");

  set_race ("thari");
  set_gender (1);
  set_alignx (0);
  set_aligny (0);

  set_skill_chance("dodge", 100);
  set_levels (([  "caster" : 90 + random(10),
                 "fighter" : 20 + random(20) ]));

  set_emote (({ "Cazares examines you carefully.",
                "Cazares mumbles something.",
                "Cazares twiddles his thumbs." }));
}
