void refreshi() {
  ::heart_beat();
  if(!present(owner,environment(this_object())) && find_player(owner) && interactive(find_player(owner))) {
    if(find_player(owner)->dead()) return;
    say(capitalize(name)+" flies away.\n");
    move_object(this_object(),environment(find_player(owner)));
    say(capitalize(name)+" flies in.\n");
  }
  if( (dsoul/100) >= dlvl) {
    say("Bear grows some.\n");
    dsoul = 0;
    dlvl++;
     set_level(1+(int)(dlvl*4));
    set_max_hp(dlvl*1000);
    set_exp(1);
  }
 call_out("refreshi",1);
}
