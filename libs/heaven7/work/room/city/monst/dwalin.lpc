inherit "inherit/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("dwalin");
  set_short("Dwalin, the armourer");
  set_long(
	"Dwalin is the famous dwarvish armourer from the hills of the \n"+
	"mountain kings. Although old and scruffy looking, he is really \n"+
	"quite charming for a dwarf.\n");
  set_race("dwarf");
  set_alias("armourer");
  set_gender(1);
  set_level(15);
  set_hp(1000);
  set_wc(20);
  set_ac(12);
  set_chance(10);
  set_spell_dam(75 + random(50));
  set_spell_mess1("Dwalin throws hot coals at you");
  set_spell_type("fire");
  set_spell_mess2("Dwalin throws hot coals at 0");
  load_chat(6, ({ "Dwalin hammers away at a piece of armour.\n",
	"Dwalin says: Hullo there.\n",
	"Dwalin smiles happily.\n" }));
  load_a_chat(12, ({ "Dwalin exclaims: How dare you!\n",
	"Dwalin curses the dwarvish gods for his plight.\n",
	"Dwalin says: Keep away from me, you bandit!\n",
	"Dwalin says: Help me guards!\n" }));
}
