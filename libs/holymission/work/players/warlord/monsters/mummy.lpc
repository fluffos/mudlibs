inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("mummy");
  set_short("Mummy");
  set_long("This is a small and weak mummy, probably only A couple hundred years old\n");
  set_level(10);
  set_wc(12);
  set_ac(8);
  set_hp(200);
  set_al(100);
  set_aggressive(1);
  add_money(500);
  return 1;
}

query_moncreator() { return "warlord"; }

query_monmaker() { return 1; }
