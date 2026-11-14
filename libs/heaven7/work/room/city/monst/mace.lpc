/* Mace of Disruption */

inherit "inherit/weapon";

reset(arg) {
  if(arg) return;
  set_name("mace");
  set_wc(17); /* +5 mace of disruption */
  set_weight(5);
  set_value(8000);
  set_type("crush");
  set_length(36);
  set_short("A white marble mace");
  set_long(
     "This white mace bears no blemish or mark and is totally spotless.   \n"+
     "Its shaft is wrapped with a black leather with a loop to wrap       \n"+
     "around the wrist. The head of the mace is etched with designs of    \n"+
     "skeletons in gold, platinum and silver being chased away by a blast \n"+
     "of light from the hands of a tall human.\n");
  set_sell_destruct(1);
  set_hit_func(this_object());
}

weapon_hit(object target) {
  if(target -> id("undead")) {
    tell_object(environment(), "Your mace glows brightly!\n"+
    target->query_name() +" cries out in pain!\n");
    target -> turn(12);  /* turns at 12th level skill */
    return (random(17) * 3);   /* x3 vs undead */
  }
  return 0;
}
 