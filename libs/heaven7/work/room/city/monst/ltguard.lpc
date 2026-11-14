inherit "inherit/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("earothas");
  set_short("Lieutenant Earothas of the city guard");
  set_long(
	"The lieutenant is a strong, sturdy elf of about 22 human years, \n"+
	"with the muscle many warriors would be jealous of. He is here   \n"+
	"to make sure that no one gets into any trouble.\n");
  set_al(1000);
  set_race("elf");
  set_wander(45, 500);
  add_spell_immune("charm");
  set_gender(1);

  load_chat(10, ({ "Earothas says: Move along quietly then.\n",
	"Earothas asks: What are you doing here, fair stranger?\n",
	"Earothas polishes his longsword.\n",
	"Earothas polishes his breastplate.\n",
	"Earothas watches your movements closely.\n",
	"Earothas says: Make no trouble while you stay in Tempus.\n"
  }));
  load_l_chat(8, "elf", ({ "If you see the banshee, destroy her!",
	"The banshee is deadly, don't allow her scream to kill you",
	"Welcome my friend to Tempus",
	"Visit the Tempus gardens if you have the chance, so much like home!",
	"Friend, stay at Skandles Downfall if you have the chance"
  }));
  load_spells(20, ({ "bn", "mm", "cl", "ice", "acd", "pwk"}));

  set_level(17);
  set_hp(1400);
  move_object(clone_object("room/city/obj/lsword"),this_object());
  init_command("wield sword");
  set_wc(24);
  move_object(clone_object("room/city/obj/plate"),this_object());
  init_command("wear armour");
  set_ac(13);
  add_money(100 + random(500));
  set_magic_resist(25 + random(50));
}
