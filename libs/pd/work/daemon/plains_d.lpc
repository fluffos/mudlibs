#include <locations.h>
#include <locations.h>
// -- Seeker [ Thursday July 13 2000 -- 23:09 ]
#include <daemons.h>
#include <socket.h>
#include <security.h>

#define MUD 0
inherit DAEMON;

#define SERVER_PORT 3000

private mapping __Plainswalkers;
mapping __Muds = ([ "209.85.145.196" : 3005 ]);

void create()
{
 seteuid(UID_SOCKET);
 write("uid = "+geteuid());
 __Plainswalkers = ([]);

}
int connect_plainswalk(object ob)
{
 int i;

 if (__Plainswalkers[ob]) return 0;

 seteuid(UID_SOCKET);
 i = socket_connect(MUD, "209.85.145.196 3000", "read_callback", 
                                                "close_callback");
  write("i = "+i+" get = "+geteuid());
  seteuid(getuid());
 if (i < 0)
   return 0;
 __Plainswalkers[ob] = i;
 return 1;
}

int send_plainswalk(object ob, mixed t)
{
 socket_write(__Plainswalkers[ob], t);
 return 1;
}

void read_callback(int fd, mixed message)
{
 seteuid(UID_SOCKET);
}

void write_callback(int fd) { seteuid(UID_SOCKET); }
/*
void close_callback(int fd)
{
 int i;
 string *key;

 if (!sizeof(__Plainswalkers)) return;
 key = keys(__Plainswalkers);
 i = sizeof(key);
 while(i--) { 
   if (__Plainswalkers[key[i]]==fd)
     {
      message("info", "Your psychic connection has been lost.", key[i]);
      key[i]->move_player(SQUARE_LOC, "into nothingness");
      map_delete(__Plainswalkers, key[i]);
      return;
    }
 }
}

*/
