int cmd_pingall(string str) {
  object *us; int s;
  s = sizeof(us = users());
  while(s--) {
    if(us[s] && (int)us[s]->query_level() < (int)this_player()->query_level()) {
      command("ping "+(string)us[s]->query_real_name(), this_player());
    }
  }
  return 1;
}
