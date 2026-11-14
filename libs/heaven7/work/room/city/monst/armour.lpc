/* A suit of ancient elvish chainmail */

inherit "inherit/armour";
reset(arg) {
  if(arg) return;
  set_name("chainmail");
  set_short("A suit of chainmail");
  set_long(
     "This suit of chainmail is in a fashion thousands of years old, \n"+
     "bearing a certain elvish influence in its design. Perhaps it   \n"+
     "is an ancient suit of elvish chain; a relic of the past.       \n");
  set_type("armour");
  set_ac(5);  /* +2 chainmail */
  set_weight(4);
  set_sell_destruct(1);
  set_value(9000);
}

query_info() {
  return "This suit of armour is thousands of years old, dating back to    \n"+
         "when the elves fought the ogre races during the battle of the    \n"+
         "ancients. The famous elvish hero Ekimthanis wore this armour     \n"+
         "which the Gods themselves are said to have blessed. It protected \n"+
         "him from many attacks from his enemies, fire, lightning, and     \n"+
         "even some magical attacks\n";      
}


wear(string str) {
  environment() -> add_spell_immune("fire");
  environment() -> add_spell_immune("lightning");
  environment() -> set_magic_resist(25);  /* not too bad eh! */
  ::wear(this_object()->query_name());
  return 1;
}

remove(string str) {
  object obj;
  if(!str) return;
  obj = present(lower_case(str), this_player());
  if(obj == this_object())
    ::drop();
  return 1;
}

drop() {
  ::drop();
  environment() -> remove_spell_immune("fire");
  environment() -> remove_spell_immune("lightning");
  environment() -> set_magic_resist(0);
  return 0;
}
