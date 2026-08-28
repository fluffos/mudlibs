inherit MONSTER;

create_monster ()
{
  set_name (({ "a cityguard", "guard", "cityguard", "man" }));
  set_short ("a cityguard is patrolling here");
  set_long (
    "A young man who has been accepted as a cityguard of "
  + "Silvercreek. It is actually quite an honour for a lad like him, "
  + "for the Chief is very demanding and won't accept just anyone as "
  + "a guard.\n");

  set_race ("human");
  set_levels ((["fighter":50]));
  set_wander (1, 60);
  set_gender (1);
  set_alignx (250 + random(500));
  set_aligny (1000 + random(500));

  set_skill_chance("dodge", 75);

  set_talk (({ "Obey the law!" }));

  set_emote (({ "A cityguard looks around.",
                "A cityguard yawns." }));

  add_money (random(300) + 1);
}
