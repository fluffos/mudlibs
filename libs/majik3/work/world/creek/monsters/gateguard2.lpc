inherit MONSTER;

create_monster ()
{
  set_name (({ "a gateguard", "guard", "gateguard", "man" }));
  set_short ("a suspicious looking gateguard stands here boredly");
  set_long (
    "This one isn't as honourable as the other guards here. He has that "
  + "wry smile and somehow suspicious outlook. The ruffians may have "
  + "bribed him to let them in. That would explain why the west gate has "
  + "been such a crime rich area.\n");

  set_race ("human");
  set_levels ((["fighter":55]));
  set_gender (1);
  set_alignx (-250 + random(500));
  set_aligny (-1000 + random(500));

  set_skill_chance("dodge", 55);

  set_emote (({ "A gateguard looks very bored.",
                "A gateguard smiles wryly.",
                "A gateguard looks at you.",
                "A gateguard smiles greedily as he looks at your money pouch." }));

  add_money (random(10) + 50);
}
