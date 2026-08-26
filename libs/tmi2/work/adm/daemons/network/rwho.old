/* File    : rwho.c
 * Creator : Grendel@tmi-2
 * When    : 93-08-18

 * This is an interface to the intermud rwho protocol.
 */
#include <uid.h>
#include <config.h>
#include <mudlib.h>
#include <net/dns.h>
#include <net/services.h>
#include <net/macros.h>

string
remote_who(string mud, object source)
{
  mapping minfo;

  if(geteuid(previous_object()) != ROOT_UID)
    return "rwhod: permission denied.\n";

  if(!DNS_MASTER->query_mud_info(mud))
    return "rwhod: there is no mud with that name presently active.\n";
  if(!((int)DNS_MASTER->query_service_method(mud, "rwho_q") & SVC_UDP))
    return "rwhod: "+mud+" does not support this service.\n";
  (SERVICES_PATH + "rwho_q")->send_rwho_q(mud, source, 0);

  return "rwhod: Remote who is on the way, may take some time.\n";
}

string
rwho_mud()
{
  mixed *whos;
  string who;

  whos = filter_array(users(), "visible", SIMUL_EFUN_OB);
  if(sizeof(whos))
    {
      whos = map_array(whos,"get_name",this_object());
      who = implode(whos,", ");
      who = sprintf("%s (%s driver, %s mudlib)\n(# = wiz)  %66-=s\n",
		    Mud_name(), version(), MUDLIB_VERSION, who);
    }
  else
    who = sprintf("%s (%s driver, %s mudlib)\n--Nobody logged on--\n",
		  Mud_name(), version(), MUDLIB_VERSION);

  return who;
}

string
get_name(object obj)
{
   return (wizardp(obj) ? "#" : "") +
      (geteuid(obj) ? capitalize(geteuid(obj)) : "(NO EUID)");
}
