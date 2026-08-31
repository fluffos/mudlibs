parry() {
  int cost,armor,retime;
  if(!TP->query_wielded()) {
    write("You are not wielding a weapon.\n");
    return 1;
  }
  if(parrying) {
    write("You are already parrying.\n");
    return 1;
  }
  if(time()-lastparry<PARRYTIME) {
    write("You have to wait for a while.\n");
    return 1;
  }
  write("You start your parrying.\n");
  armor=TP->query_dex()/5+3+TPL/10;
  arm_obj=clone_object("players/kelly/guild/parryarmor");
  arm_obj->set_ac(armor);
  move_object(arm_obj,TP);
  TP->wear(arm_obj);
  retime=60+TPL*3+TPL*2;
  parrying=1;
  parry_heart();
  return 1;
}

low_parry(str) {
  if(str!="parry") return;
  if(!arm_obj) return; 
  arm_obj->stop();
  tell_object(TP,"You stop your parrying.\n");
  parrying=0;
  lastparry=time();
  remove_call_out("parry_heart");
  return 1;
}

parry_heart() {
  if(TP->query_spell_points()<=PARRYRANGE || !TP->query_wielded()) {
    low_parry("parry");
    return; 
  }
  spell_cost(1);
  call_out("parry_heart",5);
} 
  

 
