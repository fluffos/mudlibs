//  Mud user login/logout Announcer Daemon
//  Created by Glenn Ferguson (Watcher@TMI) 09/26/92
//  Visibility check added by Pallando, 93-08-19
//  Autobow/Autowave hack added by Robocoder, 94.08.27
//
//  Must have connecting hooks within the mudlib system to inform
//  the daemon when a user has enter/left the mud.
//
//  Type 0  :   entered     Type 1  :   left
//  Type 2  :   re-entered  Type 3  :   net-dead

#include <mudlib.h>
#include <uid.h>
#include <daemons.h>

#undef AUTOACTION
 
inherit DAEMON;
 
void create() {
    seteuid(ROOT_UID);
}
 
int announce_user(object who, int type) {
    mixed *list, *ann;
    string name, what, mud;
    int loop, s, member;
    object ob;
#ifdef AUTOACTION
    mixed *myann;
    int autoaction;
    string lname, lmember;
#endif
 
    if (!who)  return 0;
    if (name = (string)who->query("name"))
        name = capitalize(name);
    else
        name = "NONAME";

#ifdef AUTOACTION
    myann = (mixed *)who->query("announce");
    if (type == 0)       autoaction = (int)who->query_env("autobow");
    else if (type == 1)  autoaction = (int)who->query_env("autowave");
#endif
    
    if (mud_name())
        mud = capitalize(mud_name());
    else
        mud = "the game";
 
    list = users();
    s = sizeof(list);
    for (loop=0; loop < s; loop++) {
        if (((ob = list[loop]) == who) ||
              !environment(ob) ||
              !visible(who, ob))
            continue;

        ann = (mixed *)ob->query("announce");
        if (!ann || !pointerp(ann) || !sizeof(ann))  continue;

#ifdef AUTOACTION
        lname = lower_case((string)ob->query("name"));
	lmember = -1;
#endif
        if (base_name(ob) == "/std/user" &&
              (((member = member_array(lower_case(name), ann)) != -1) ||
#ifdef AUTOACTION
              (lname && myann &&
              ((lmember = member_array(lname, myann)) != -1)) ||
#endif
              (member_array("ON", ann) != -1))) {
            switch (type) {
              case 0:
                message("announce", "[ " + name + " has entered " + mud +
                      (adminp(geteuid(ob)) ?
                      " from " + query_ip_name(who) : "") +
                      " ]\n", ob);
#ifdef AUTOACTION
                if ((member != -1) && ob->query_env("autobow"))
                    ob->force_me("bow " + name);
                if ((lmember != -1) && autoaction)
                    who->force_me("bow " + lname);
#endif
                break;
              case 1:
#ifdef AUTOACTION
                if ((member != -1) && ob->query_env("autowave"))
                    ob->force_me("wave " + name);
                if ((lmember != -1) && autoaction)
                    who->force_me("wave " + lname);
#endif
                message("announce", "[ " + name + " has left " + mud +
                      (query_ip_name(who) ?
                      ((adminp(geteuid(ob)) ?
                      " from " + query_ip_name(who) : "")) : "") +
                      " ]\n", ob);
                break;
              case 2:
                message("announce", "[ " + name + " has re-entered " + mud +
                      (adminp(geteuid(ob)) ?
                      " from " + query_ip_name(who) : "") +
                      " ]\n", ob);
                break;
              case 3:
                message("announce", "[ " + name + " has gone net-dead ]\n", ob);
                break;
            }
        }
    }
 
    return 1;
}
