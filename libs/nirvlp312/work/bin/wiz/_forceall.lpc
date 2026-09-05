int cmd_forceall(string str) {
  object *us; int s;
  if(!str) return 0;
  s = sizeof(us = users());
  while(s--) {
    if(us[s] && (int)us[s]->query_level() < (int)this_player()->query_level()) {
      command("force "+(string)us[s]->query_real_name()+" "+str, this_player());
    }
  }
  return 1;
}
