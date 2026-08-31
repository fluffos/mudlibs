inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("small demon");
  set_alias("demon");
  set_short("Small demon");
  set_long("He just is here to guard the stairs\n");
  set_race("demon");
  set_level(25);
  set_al(-100);
  add_money(3000);
  set_hp(1000);
  set_wc(20);
  set_ac(20);
  set_aggressive(1);
  return 1;
}

query_moncreator() { return "warlord"; }

query_monmaker() { return 1; }
