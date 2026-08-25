#pragma strict_types
#include <standard.h>
#include <cmd.h>
 
inherit CMD_BASE;
 
void setup(){
  position = 1;
}
 
protected int cmd(string str, object me) {
string *ftp_users;
 
  ftp_users = "/secure/ftpd"->query_connections();
  if (sizeof(ftp_users))
    printf("%75#s\n",implode(ftp_users,"\n"));
  else
    write("No ftp users currently on.\n");
  return 1;
} /* what_dir() */
