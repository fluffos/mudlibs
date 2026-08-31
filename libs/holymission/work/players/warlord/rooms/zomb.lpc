inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("zombie");
  set_short("Zombie");
  set_long("This is one of your typical undeads..he just hates mortals..\n");
  set_level(8);
  set_hp(180);
  set_al(-500);
  set_aggressive(1);
  add_money(500);
  return 1;
}

query_moncreator() { return "warlord"; }

query_monmaker() { return 1; }
