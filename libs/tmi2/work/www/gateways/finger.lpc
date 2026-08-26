/*    /www/gateways/finger.c
 *    from Nightmare IV
 *    handles dynamic World Wide Web data
 *    created by Descartes of Borg 940523
 *    ported to Tmi-2 and stripped quite a bit by Leto 060694
 *    Get a finger using: get /www/gateways/finger/leto
 *    You might want to use html's form to get a name inputed
 */

#include <mudlib.h>
#include <config.h>
#include <daemons.h>

inherit DAEMON;

string gateway(string args) {
    string str;

sscanf(args,"=%s",args);
args = replace_string(args,"%28","("); // convert brackets back
args = replace_string(args,"%29",")");
//tell_object(find_player("leto"),"FINGER GATEWAY BOOTED\n");
    str = sprintf("<TITLE>%s Finger Gateway</TITLE>", mud_name());
str = str + "<LISTING>";
str = str + (FINGER_D->finger_user(args));
//tell_object(find_player("leto"),"FINGER:"+str+"\n");
return str;
}
