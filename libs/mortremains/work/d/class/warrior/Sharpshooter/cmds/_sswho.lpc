#include <mudlib.h>

inherit DAEMON ;

int cmd_sswho(string str) {
  object *users ;
  int i;
  users = users() ;
  if (!users) {
     write("Haha, Nobody is logged on!\n") ;
     return 1;
  }
  write("Sharpshooters currently logged in.\n") ;
  write("---------------------------------------------------------------\n") ;
  for(i=0;i<sizeof(users);i++) {
  if (present("cybernetic eyelink", users[i])) {
      if (wizardp(users[i]) && users[i]->query("invisible")) continue ;
                  printf("[%d]\t%s\n", users[i]->query_level(), users[i]->query("short")) ;
  }
  }
  return 1;
}
