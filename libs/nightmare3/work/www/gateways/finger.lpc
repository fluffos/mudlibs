/*    /www/gateways/finger.c
 *    from Nightmare IV
 *    handles dynamic World Wide Web data
 *    created by Descartes of Borg 940523
 */

#include <std.h>
#include <daemons.h>

inherit DAEMON;

string gateway(string args) {
    string *tmp;
    string str;

    str = sprintf("<TITLE>%s Finger Gateway</TITLE>", mud_name());
    if(args == "" || !args) args = 0;
    else if(!user_exists(lower_case(args)))
      return sprintf("%s<h1>%s not found.</h1>No such member of the %s"
        " reality.", str, capitalize(args), mud_name());
    tmp = explode((string)FINGER_D->user_finger_display(args), "\n");
    str = sprintf("%s<h1>%s</h1><PLAINTEXT>\n%s</PLAINTEXT>",
      str, tmp[0], implode(tmp[1..sizeof(tmp)-1], "\n")+"\n");
    return str;
}
