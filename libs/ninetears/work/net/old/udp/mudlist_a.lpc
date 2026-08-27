#include "udp.h"
/*
 * Someone replyed to our query and has sent us their mudlist.
 * Lets all go bing in the garden.
 */
void incoming_request(mapping info) {
  string *junk, *inf, name, value;
  int i, j;
  mapping newl, old;

  junk = keys(info);
  for (i=0;i<sizeof(junk);i++) {
    inf = explode(info[junk[i]], "|");
    newl = ([ ]);
    for (j=0;j<sizeof(inf);j++)
      if (sscanf(inf[j], "%s:%s", name, value) == 2)
        newl[name] = value;
    if (!newl["NAME"] || newl["NAME"] == mud_name()) continue;
    old = NAMESERVER_CD->query_mud_info(newl["NAME"]);
    if (!old)
      NAMESERVER_CD->set_mud_info(newl["NAME"], newl);
    else {
      inf = keys(newl);
      for (j=0;j<sizeof(inf);j++)
        old[inf[j]] = newl[inf[j]];
      NAMESERVER_CD->set_mud_info(newl["NAME"], old);
    }
  }
} /* incoming_request() */

void create() {
  seteuid(getuid());
} /* create() */
