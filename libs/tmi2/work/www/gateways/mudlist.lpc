/*    /www/gateways/mudlist.c
 *    from Nightmare IV
 *    a gateway to produce a mudlist for connecting to muds
 *    created by Descartes of Borg 940524
 *    Tweaked a little to work with DNS by Leto@Earth
 */

// FIXED BY AVATAR FOR NEW I3-SYSTEM!, 19/09/95-26/09/95
// CODE FROM _mudlist.c

//#include <mudlib.h>
//#include <net/daemons.h>
//#include <net/dns.h>
#include <net/i3.h>

inherit DAEMON;

string gateway(string unused)
{
  string *mud,flags,str;
  mixed vls;
  int i,j,maxi;
  mapping list,services;
  string *sorted=({});

  list = I3_DAEMON->query_mudlist();
  if (!sizeof(list))
    str = "<TITLE>%s Mudlist Gateway</TITLE><h1>The only mud at this "+
	"time that we know, is our own litle safe mud.\n</h1>";
  else
  {
    mud = keys(list);
    vls = values(list);
    maxi = sizeof(mud);

    str = sprintf("<TITLE>%s Mudlist Gateway</TITLE><h1>"
      "%s is aware of the following %d muds.</h1><OL>",capitalize(MUD_NAME),
      capitalize(MUD_NAME),maxi);

    for(i=0; i<maxi; i++)
      str += sprintf("<LI><a href=telnet://%s:%d>%s</a> (%s %d), "+
                     "Driver: %s, Mudlib: %s %s", vls[i][1], vls[i][2],
        mud[i], vls[i][1],vls[i][2],vls[i][7],vls[i][5],vls[i][9]);

    str += "</OL>This mudlist is maintained dynamically through the "+
           "Intermud network system";
  }

  return str;
}

int alphabetize_muds(string a, string b) { return strcmp(a, b); }
