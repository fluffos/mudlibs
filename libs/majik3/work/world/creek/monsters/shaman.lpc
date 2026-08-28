inherit MONSTER;

create_monster ()
{
  set_name (({ "an old shaman", "shaman", "old shaman", "man", "old man" }));
  set_short ("an old travelling shaman has come here to sell his magical mushrooms");
  set_long (
    "The old man has probably lost his mind. He is constantly chuckling by "
  + "himself, taking a bite from his mushroom once in a while. He is "
  + "wearing worn out leather clothes and a brown tunika. He smiles stupidly "
  + "at you and offers you a half eaten mushroom.\n");

  set_race ("ayura");
  set_levels ((["caster":50]));
  set_gender (1);
  set_alignx (-random(100) + 100);
  set_aligny (-random(100) + 100);

  set_emote (({ "An old shaman giggles madly.",
                "An old shaman chuckles.",
                "An old shaman smiles stupidly.",
                "An old shaman eats a mushroom.",
                "An old shaman looks at you.",
                "An old shaman hops around like a bunny." }));

  set_talk (({ "Buy some mushrooms!",
               "Best mushrooms in whole majik!",
               "Magic mushrooms, magic mushrooms!",
               "It's magic!",
               "These mushrooms are delicious!",
               "Hihihii!" }));

  add_money (random(500) + 100);
}
