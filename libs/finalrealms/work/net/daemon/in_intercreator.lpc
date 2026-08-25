#include "intercreator.h"
#include "inet.h"

/* Dont cha love udp? */

/* Ok, now we need to check it comes form the server... */
void read_callback(int fd, string mess, string addr) {
  string mname;

  NAMESERVER->lookup_mud(INTERCREATOR_SERVER, "finish_lookup",
                          ({ addr, mess }));
} /* read_callback() */

void finish_lookup(string sname, string addr, mixed *args, int force) {
  string j_addr1, j_addr2, pname, mess, mname;

  if (!force) {
    sscanf(addr, "%s %s", j_addr1);
    sscanf(args[0], "%s %s", j_addr2);
    if (j_addr1 != j_addr2) {
      return ;
    }
  }
  sscanf(args[1], "%s %s %s", mname, pname, mess);
  if (mname)
    event(users(), "inter_creator_tell", mname, pname, mess);
} /* finish_lookup() */
