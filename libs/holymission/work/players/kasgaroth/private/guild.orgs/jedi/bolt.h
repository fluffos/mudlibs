shock(str) {
  object whom;
  int damn,cost;
  damn=15+TPL/3+TP->query_wis();
  cost=30-TP->query_int()/5+TPL;
 
  if(!str) whom=TP->query_attack();
  else whom=present(str,ENV(TP));
  if(!whom) {
    if(!str) write("Whom !?\n");
    else write("No "+CAP(str)+" here.\n");
     return 1;
  }
  if(whom==TP) {
    write("You don't want to do that.\n");
    return 1;
  }
  if(!living(whom)) {
    write(CAP(str)+" is not a living thing.\n");
    return 1;
  }
 
  write("You hold your hands towards "+whom->NAME+".\n");
  if(TP->query_spell_points()<cost) {
    write("You lack the Force to finish the spell.\n");
    return 1;
  }
  write("Blue flashes of electricity crackle out of your hands and strike "+
      whom->NAME+".\n");
  say("Bolts of electricity crackle out of "+TPN+"'s hands and strike "+
      whom->NAME+".\n");
  if(whom->query_hp()<damn) damn=whom->query_hp()/2;
  /* this makes you attack the monster */
  whom->hit_player(1);
  /* This spell penetrates the armour */
  /* 930605 Llort then use the appropiated hit_player kind ! */
/*
  whom->reduce_hit_point(damn);
*/
  whom->hit_player(damn,5); /* now it's spelldammage */
  spell_cost(cost);
  return 1;
}
