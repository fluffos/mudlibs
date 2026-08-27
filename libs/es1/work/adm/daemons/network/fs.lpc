/*
 * Intermud finger server
 * Original author: Huthar@Portals
 * Rewritten: Blackthorn@Genocide (10/31/92)
 * TMI-2 conversion: Buddha@tmi-2 (11/5/92)
 * 93-08-14 Grendel@tmi-2 Updated to work with dns
 */

#include <uid.h>
#include <daemons.h>
#include <net/daemons.h>
#include <net/services.h>
#include <net/config.h>
#include <net/dns.h>

#define log(x) log_file("FS", x)

mapping requests;

// The interface to the mudlib
void remote_finger(object source, string user,string mud);

// The inetd functions
void service_request(int id, mixed *parms);
void read_callback(int id, string msg);
void close_callback(int id);
void timeout(int id);

void
create()
{
  seteuid(ROOT_UID);
  requests = ([ ]);
}

// this is called by the finger command.  it works out which type of protocol
// to use, then acts appropriatley
void
remote_finger(object source, string user, string mud)
{
  mapping minfo;
  int msvc;

  if(!DNS_MASTER->dns_mudp(mud))
    {
      tell_object(source, "fingerd: no mud with that name presently active\n");
      return;
    }

    (SERVICES_PATH+"gfinger_q")->send_gfinger_q(mud, user, source);
  tell_object(source, "Finger on its way.  May take some time.\n");
  return ;
}

