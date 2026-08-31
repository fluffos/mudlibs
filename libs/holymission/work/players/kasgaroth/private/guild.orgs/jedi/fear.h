fear(str) {
  object obj;
  if(str=="all") {
    fear_all();
    return 1;
  }
  if(!str) {
    write("Whom do you want to suggest fear?\n");
    return 1;
  }
  obj=present(str,ENV(TP));
  if(!obj) {
    write(CAP(str)+" isn't here.\n");
    return 1;
  }
  if(obj==TP) {
    write("You don't really want to do that.\n");
    return 1;
  }
  if(!living(obj)) {
    write(CAP(str)+" is actually not a living thing.\n");
    return 1;
  }
  if(obj->query_guild()==guild) {
    write(obj->NAME+" is a Jedi, too. You cannot fake him.\n");
    tell_object(obj,TPN+" tries to fear you.\n");
    return 1;
  }
  if(obj->query_wis()-10>TP->query_wis()) {
    write(obj->NAME+" is to wise to fall for that.\n");
    return 1;
  }
  write("You concentrate your Force and say some words.\n");
  say(TPN+" speaks some strange words and waves with a hand.\n");
  tell_object(obj,"As you look up to "+TPN+" you get an unusual "+
    "feeling.\nYour hands begin to sweat.\nYou panic.\n");
  obj->run_away();
}
 
fear_all() {
  object obj,wimps;
  int i;
  int allow;
 
  wimps=all_inventory(ENV(TP));
  i=sizeof(wimps)-1;
 
  say(TPN+" murmurs something you don't understand.\n");
  while(i>=0) {
    allow=1;
    if(living(wimps[i]) && wimps[i]!=TP) {
      if(wimps[i]->query_guild()==guild) {
	write(wimps[i]->NAME+" is a Jedi, too. You cannot fake him.\n");
	tell_object(wimps[i],TPN+" tries to fear you.\n");
	allow=0;
      }
      if(wimps[i]->query_wis()-10>TP->query_wis()) {
	write(wimps[i]->NAME+" is to wise to fall for that.\n");
	allow=0;
      }
      if(allow) {
	tell_object(wimps[i],"As you look up to "+TPN+" you get an unusual "+
		   "feeling.\nYour hands begin to sweat.\nYou panic.\n");
	wimps[i]->run_away();
      }
    }
    i--;
  }
  return 1;
}
