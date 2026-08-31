#include <security.h>
#include <std.h>

inherit DAEMON;

mapping users;

void create() {
  users = ([]);
  call_out("do_log",30);
}

void add_exp(string who, int exp) {
  users[who] = exp + users[who];
}

void do_log() {
  object *all;
  int exp;

  message("info","Doing log.\n",find_player("nightshade"));

  all = users();
  seteuid(UID_LOG);

  message("info",""+(string)users["nightshade"]+"\n",find_player("nightshade"));
  for(int i=0;i < sizeof(all);i++) {
    exp = users[all[i]->query_name()];
    message("info",all[i]->query_name()+"\n",find_player("nightshade"));
    users[all[i]->query_name()] = 0;
    if(exp > 1000) {
      log_file("xphour", sprintf("%s has made %d exp in one hour at level %d.\n", all[i]->query_cap_name(), exp, all[i]->query_level()));
      message("info",sprintf("%s has made %d exp in one hour at level %d.\n", all[i]->query_cap_name(), exp, all[i]->query_level()),find_player("nightshade"));
      }
  }
}
