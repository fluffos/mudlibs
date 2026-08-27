/*    /adm/daemons/network/services/gwizlist_a.c
 *    from TMI-2
 *    handles incoming requests for a gwizlist
 *    created by Descartes of Borg 940804
 */

#include <mudlib.h>
#include <net/macros.h>

inherit DAEMON;

void incoming_request(mapping info) {
    object ob;

    if(!stringp(info["ASKWIZ"]) || !(ob=find_player(info["ASKWIZ"]))) return;
    message("system", sprintf("Intercre listing from %s:\n%s", info["NAME"],
      info["GWIZLIST"]), ob);
}

