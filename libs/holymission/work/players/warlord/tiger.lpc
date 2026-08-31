inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("tiger");
  set_short("Saber Tooth Tiger");
  set_long("This is a carnivorous tiger and you're his prey...\n");
  set_level(20);
  set_al(-200);
  set_hp(1000);
  set_ac(8);
  set_wc(15);
  add_money(500);
  set_aggressive(0);
  return 1;
}

query_moncreator() { return "warlord"; }

query_monmaker() { return 1; }
