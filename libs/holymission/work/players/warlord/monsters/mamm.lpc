inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("mammoth");
  set_alias("wooly");
  set_short("Wooly Mammoth");
  set_long("This creature is very large and very hairy...\n");
  set_level(25);
  set_wc(25);
  set_ac(10);
  set_hp(1000);
  set_al(-3);
  set_spell_mess1("");
  set_spell_mess2("");
  set_chance(20);
  set_spell_dam(40);
  add_money(2000);
  set_aggressive(0);
  return 1;
}

query_moncreator() { return "warlord"; }

query_monmaker() { return 1; }
