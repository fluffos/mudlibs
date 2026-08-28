inherit MONSTER;

create_monster ()
{
  set_name (({ "a ruffian", "ruffian", "man" }));
  set_short ("a ruffian stands here looking for mischief to do");
  set_long (
    "These guys always tend to get in troubles, but hey, it's their own "
  + "fault. They are always looking for a chance to do some mischief. "
  + "And they really are a pain in the ass. None will really care if "
  + "they'll get wasted. In fact many would like to see them at the "
  + "gallows pole..\n");

  set_race ("thari");
  set_levels ((["fighter":10]));
  set_wander (1, 70 + random(100));
  set_gender (random(2) + 1);
  set_alignx (-501 + random(100));
  set_aligny (-501 + random(100));

  set_aggressive (random(2));

  set_skill_chance("dodge", random(5));

  add_money (random(10));
}
