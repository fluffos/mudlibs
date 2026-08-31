inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("stegasaurus");
  set_alias("steg");
  set_short("Stegosaurus");
  set_long("This creature is large, dumb and dangerous\n");
  set_level(30);
  set_al(0);
  set_hp(1800);
  set_wc(40);
  set_ac(15);
  set_chance(8);
  set_spell_dam(100);
  add_money(3000);
  set_spell_mess1("Stegasaurus hits you with his tail");
  set_spell_mess2("You are catapulted high in the air by the Stegasaurus");
  set_aggressive(0);
  return 1;
}

query_moncreator() { return "warlord"; }

query_monmaker() { return 1; }
