/*
 * This will connect up to an auth demon and get it to return our
 * login name.
 */
#include "socket.h"
#include "inet.h"
mapping found;

void create() {
  seteuid((string)"/secure/master"->creator_file(file_name(this_object())));
  found = ([ ]);
} /* create() */

void query_auth(string func) {
  string addr, bing;
  int port;

  addr = socket_address(previous_object());
  if (!addr) {
    call_other(previous_object(), func, 0);
    return ;
  }
  sscanf(addr, "%s %d", bing, port);
  found[addr] = ({ previous_object(), func, addr, port });
  if (!found[bing])
    found[bing] = ({ addr });
  else
    found[bing] += ({ addr });
  INETD->open_to_service("auth", STREAM, addr);
} /* query_auth() */

/* Well.  We know what service we were opening... */
void failed(string reason, string machine, string service) {
  int i;
  mixed junk;

  if (found[machine])
    for (i=0;i<sizeof(found[machine]);i++) {
      junk = found[found[machine][i]];
      if (!junk) continue;
      if (junk[0])
        call_other(junk[0], junk[1]);
      map_delete(found, found[machine][i]);
    }
  map_delete(found, machine);
} /* failed() */

/* Ok...  zap the first one from this host down the tubes. */
void connected(int fd, string host) {
  if (!found[host]) {
    previous_object()->close_fd(fd);
    return ;
  }
  previous_object()->write_fd(fd, found[found[host][0]][3]+" , 4000\n\r");
  found[fd] = found[host][0];
  found[host] = found[host][1..1000];
  if (!sizeof(found[host]))
    map_delete(found, host);
} /* connected() */

void read_callback(int fd, string mess) {
  string name, machine_type, biggles;
  int port, mine;

  sscanf(mess, "%d , %d : %s : %s : %s", mine, port, biggles, machine_type,
               name);
  if (!found[fd]) {
    previous_object()->close_fd(fd);
    map_delete(found, fd);
    return ;
  }
  call_other(found[found[fd]][0], found[found[fd]][1],
             (name?replace(name, ({ "\n", "", "\r", "" })):name));
  map_delete(found, found[fd]);
  map_delete(found, fd);
  previous_object()->close_fd(fd);
} /* read_callback() */
