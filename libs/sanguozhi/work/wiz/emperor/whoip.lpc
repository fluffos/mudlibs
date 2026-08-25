// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

//  Yaynu@Lima Bean 950723
//  Prints out a list of IP connections.
//  Arguments: <none> - Reports all players IP names+numbers.
//             <ipname,ipnum> - Reports all who are from that address.
//             <name> - Reports out players ip name and number.

// Emperor@sgz 20010725
// Sort all players IP.
 
#include <mudlib.h>
//Emperor #include <playerflags.h>
#include <ansi.h>
#define DIVIDER \
"-----------------------------------------------------------------------------------\n"


inherit CMD;

nosave protected mixed * color_sort = ({HIM, HIG, CYN, MAG, ORG, WHT, YEL, GRN});

private void main(string arg)
{
    object user;
    int x, i, j;
    object ob;
    string *n, ip, str, c_n, c_str;
    object * userlist;
    mapping u_m;

    if ( !arg )
    {
        outf("%s:  (当地时间: %s)\n%s",
               mud_name(), ctime(time()), DIVIDER);
        out("国家            名字                     IP number                 IP name\n"+DIVIDER);
/*
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
*/
//emperor@sgz modify.
	u_m=([]);
	i = 0;
        userlist = sort_array(users(), (: strcmp(query_ip_number($1), query_ip_number($2)) :));
        foreach ( user in userlist ){
         if(user->query_body()!=0)
          if(user->query_body()->query_primary_id()!=0)
            if( stringp(c_n = CHAR_D->get_char(user->query_body()->query_primary_id(),"nation")) != 0 )
                c_n = COUNTRY_D->get_country(c_n,"name");
            //c_n = AREA_D->get_area(CHAR_D->get_char(user->query_body()->query_primary_id(),"area"),"name");
            //c_n = CHAR_D->get_char(user->query_body()->query_primary_id(),"nation");
            j = member_array(user, userlist);
            if (j == 0) c_str = RED;
            else {
            	if (query_ip_number(user) != query_ip_number(userlist[j-1])) {
            	    i += 1;
            	    c_str = color_sort[i%sizeof(color_sort)];
            	}
            	
            }
            	   out(c_str);
           	   outf("%-16s", c_n?c_n:"<No country>");
                   outf("%-24s ", sprintf("%s(%s)",user->query_chinese_id()?user->query_chinese_id():"<LOGIN>",user->query_userid()?user->query_userid():"<logind>" ));
                   outf("%-25s ", query_ip_number(user)); 
                   outf("%-25s", query_ip_name(user));
                   out("\n"+NOR);
            	/*
            outf(c_str + "%-16s%-24s %-25s %-25s\n" + NOR,
            	   c_n?c_n:"没有国家",
                   sprintf("%s(%s)",user->query_chinese_id()?user->query_chinese_id():"LOGIN",user->query_userid()?user->query_userid():"(logind)" ),
                   query_ip_number(user)?query_ip_number(user):"0", 
                   query_ip_name(user)?query_ip_name(user):"0");
*/
//            u_m += ([ query_ip_number(user):""]);

	}
        x = sizeof(userlist);
        outf("%s目前有 %d 位玩家，%d个IP地址。\n",DIVIDER, x , i+1);//sizeof(keys(u_m)));
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
 
