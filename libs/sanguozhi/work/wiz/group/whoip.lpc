// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

//  Yaynu@Lima Bean 950723
//  Prints out a list of IP connections.
//  Arguments: <none> - Reports all players IP names+numbers.
//             <ipname,ipnum> - Reports all who are from that address.
//             <name> - Reports out players ip name and number.
 
#include <mudlib.h>
#include <playerflags.h>
#define DIVIDER \
"-------------------------------------------------------------------------\n"

inherit CMD;
 
private void main(string arg)
{
    object user;
    int x;
    object ob;
int y;
    string *n, ip, str;
string test;
string *leii;
    object * userlist;

    if ( !arg )
    {
        outf("%s:  (当地时间: %s)\n%s",
               mud_name(), ctime(time()), DIVIDER);
        out("名字         IP number                 IP name\n"+DIVIDER);

        foreach ( user in users() )
        {
            string userid = user->query_userid();

            if ( !userid )
                userid = "(login)";
            else
                userid = userid;

            outf("%-12s %-25s %-25s\n",
                   userid, query_ip_number(user), query_ip_name(user));
        }                                      
        x = sizeof(users());
        outf("%s目前有 %d 位玩家。\n",DIVIDER, x);
leii=({});
        foreach(user in users())   
   {       if(sizeof(leii-({query_ip_number(user)}))==sizeof(leii))
leii = leii+ ({query_ip_number(user)});
        }
        y = sizeof(leii);
        outf("got %d real players.\n",y);
        return;
    }

    if (ob = find_user(arg)) {
        ip = query_ip_number(ob); 
        userlist = filter(users(), (: query_ip_number($1) == $2 :), ip);
    } else if (sscanf(implode(explode(arg,"."),""),"%d",x) == 1){
        userlist = filter(users(), (: query_ip_number($1) == $2 :), arg);  
    } 
    else if (sscanf(implode(explode(arg,"."),""),"%s",x) == 1){
        userlist = filter(users(), (: query_ip_name($1) == $2 :), arg);  
    } 
    else {             
        arg = lower_case(arg);
        userlist = filter(users(), (: query_ip_number($1) == $2 :), arg);  
    } 

    if ( (x = sizeof(userlist)) > 0 )
    {
        n = map(userlist->query_userid(),
                (: $1 ? $1 : "(login)" :));
        str = query_ip_name(userlist[0]);
        if (str != query_ip_number(userlist[0]))
            str += " ("+query_ip_number(userlist[0])+")";

        outf("目前有 %d 位从 %s 上线的玩家:\n", x, str);  
        outf("%-=78s",implode(n,", ")+".\n");
    }
    else
        out("没有人从那个地址连线。\n");
}  
 
