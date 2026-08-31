/* tourn_d.c - Tournament Daemon
   Seeker - Mon Oct  7 23:31:04 PDT 2002 */
#include <daemons.h>

inherit DAEMON;

mapping fees = ([ "division 1" : 10000,
                  "division 2" : 25000,
                  "division 3" : 50000,
                  "division 4" : 75000 ]);

mapping competitors;

int query_fees(string fee) { return fees[fee]; }
void create()
{
 ::create();
}

