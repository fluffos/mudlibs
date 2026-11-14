inherit "inherit/monster";

void reset(status arg) {
  ::reset(arg);
  if(arg) return;

  set_name("dragonfly");
  set_gender(random(2) + 1);
  set_race("insect");
  set_level(1);
  set_short("A little dragonfly");
  set_long(
	"Its bright dazzling skin glitters as you \n"+
	"watch it dart around the garden. It is an impressive sight.\n");
  set_ac(5);
  set_hp(55);
  load_chat(12, ({ "Dragonfly buzzes around your head.\n",
	"Dragonfly darts about the flowers.\n",
	"Dragonfly hovers around you.\n",
	"Dragonfly hovers above the flowers.\n",
	"Dragonfly sniffs at a flower.\n",
	"Dragonfly flies up high.\n",
	"Dragonfly hovers around the ground.\n"
  }));
    
  set_attack_msg(({
	"missed",		"",
	"sticks",		"with its tiny tail",
	"bites",			"with its tiny teeth",
	"stings",		"with its tail",
	"hurts",		"with its tail",
	"grazes",		"with its wings",
	"buts",			"with its head, while flying",
  }));
}
