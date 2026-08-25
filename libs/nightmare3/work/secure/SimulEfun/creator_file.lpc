/*    /adm/SimulEfun/creator_file.c
 *    from Nightmare IV
 *    returns a user id for new objects
 *    created by Descartes of Borg 940516
 */

#include <security.h>

string creator_file(string str) {
    string *borg;
    int i, x;

    if(!(borg = explode(str, "/"))) return 0;
    if((x=member_array("open",borg)) != -1 && x != sizeof(borg)-1) return 0;
    if(!x) return 0;
    switch(borg[0]) {
        case "adm":
            return UID_ROOT;
        case "cmds":
          return (borg[1] == "system" ? UID_SYSTEM : UID_MUDLIB);
        case "daemon":
          return (borg[1] == "postal" ? UID_POSTAL : UID_MUDLIB);
        case "domains": return sprintf("%sobj", borg[1]);
        case "estates": return UID_ESTATES;
        case "realms": return sprintf("%sobj", borg[1]);
        case "secure": return UID_ROOT;
        case "std": return UID_BACKBONE; break;
        case "www": return (borg[1] == "gateways" ? UID_MUDLIB : 0);
        default: return 0;
    }
}
