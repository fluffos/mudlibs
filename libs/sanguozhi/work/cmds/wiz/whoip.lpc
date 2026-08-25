// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

//  Yaynu@Lima Bean 950723
//  Prints out a list of IP connections.
//  Arguments: <none> - Reports all players IP names+numbers.
//             <ipname,ipnum> - Reports all who are from that address.
//             <name> - Reports out players ip name and number.

// Emperor@sgz 20010725
//      Sort all players IP.

// Updated by xiaobai@sgz on 25 Oct 2001
//      with option "-all" can show all users id(including those are offline)
//       logged in with a given ip
 
#include <mudlib.h>
//Emperor #include <playerflags.h>
#include <ansi.h>

// #define _DEBUG_ID   "xiaobai"

#define DIVIDER \
"-------------------------------------------------------------------------\n"

inherit CMD;

nosave protected mixed * color_sort = ({HIM, HIG, CYN, MAG, ORG, WHT, YEL, GRN});

//! only show online users who satisfiy the condition
private void show_onlineonly( string par_strPara );

//! show all users who satisfy the condition
private void show_all( string par_strPara );

//! 如果 ip 的前某段想等，返回1，否则返回0
private int filter_ip( string par_strId, int par_nLength, string par_strPara );
 
private void main(string arg)
{
    object user;
    int x,i,j;
    object ob;
    string *n, ip, str, c_n, c_str;
    object * userlist;
    string strOption;
    string strPara = "xiaobai";
    int nTest;
    mapping u_m;
    
    if ( !arg )
    {
        outf("%s:  (当地时间: %s)\n%s",
               mud_name(), ctime(time()), DIVIDER);
        out("名字         IP number                 IP name\n"+DIVIDER);

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
        foreach ( user in userlist )
        {
         if(user->query_body()!=0)
          if(user->query_body()->query_primary_id()!=0)
            if( stringp(c_n = CHAR_D->get_char(user->query_body()->query_primary_id(),"nation")) != 0 )
                c_n = COUNTRY_D->get_country(c_n,"name");
            //c_n = AREA_D->get_area(CHAR_D->get_char(user->query_body()->query_primary_id(),"area"),"name");
            //c_n = CHAR_D->get_char(user->query_body()->query_primary_id(),"nation");
            j = member_array(user, userlist);
            if (j == 0) c_str = RED;
            else
            {
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
    else
    {
        nTest = sscanf( arg, "-%s %s", strOption, strPara );
        
        if ( nTest == 0 )
        {
            nTest = sscanf( arg, "%s", strPara );
            
        }
        
#ifdef _DEBUG_ID
    TELL_BUG( _DEBUG_ID, sprintf( "option: %s\tparameter: %s", strOption, strPara ) );
#endif  // _DEBUG_ID
        
    }
    
    if ( strOption == "all" )
        show_all( strPara );
    else
        show_onlineonly( strPara );        

}  
 
//! only show online users who satisfiy the condition
private void show_onlineonly( string par_strPara )
{
    object user;
    int x;
    object ob;
    string *n, ip, str;
    object * userlist;

    if (ob = find_user(par_strPara))
    // the parameter is an user id
    {
        ip = query_ip_number(ob); 
        userlist = filter(users(), (: query_ip_number($1) == $2 :), ip);
    }
    else if (sscanf(implode(explode(par_strPara,"."),""),"%d",x) == 1)
    // the parameter is an ip number
    {
        userlist = filter(users(), (: query_ip_number($1) == $2 :), par_strPara);  
    } 
    else if (sscanf(implode(explode(par_strPara,"."),""),"%s",x) == 1)
    // the parameter is a host name
    {
        userlist = filter(users(), (: query_ip_name($1) == $2 :), par_strPara);  
    } 
    else 
    {
        out( "Please use id or ip as parameter\n" );             
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


//! show all users who satisfy the condition
private void show_all( string par_strPara )
{
    int x;
    object ob;
    string ip;
    string * strLastDataArr = ({});
    string * strUserIdArr;
    int nIpLength;   
 
    
    strUserIdArr = LAST_LOGIN_D->list_allusers();
    
    if ( member_array( par_strPara, strUserIdArr ) >= 0 )
    // the parameter is an user id
    {
        ip = LAST_LOGIN_D->query_last( par_strPara )[1]; 
        strUserIdArr = filter_array( strUserIdArr, (: LAST_LOGIN_D->query_last($1)[1] == $2 :), ip );
    }
    else if (sscanf(implode(explode(par_strPara,"."),""),"%d",x) == 1)
    // the parameter is an ip number
    {
        ip = par_strPara;
        nIpLength = sizeof( ip );
        strUserIdArr = filter_array( strUserIdArr, (: filter_ip :), nIpLength, ip );
    } 
//    else if (sscanf(implode(explode(par_strPara,"."),""),"%s",x) == 1)
    // the parameter is a host name
//    {
//        userlist = filter(users(), (: query_ip_name($1) == $2 :), par_strPara);  
//    } 
    else 
    {
        out( "Please use id or ip as parameter\n" );
        return;             
    }    

    if ( ( x = sizeof( strUserIdArr ) ) > 0 )
    {
        outf("有 %d 位从 %s 上线的玩家:\n", x, ip );  
        outf("%-=78s",implode( strUserIdArr, ", " )+".\n");
    }
    else
        out("没有人从那个地址连线。\n");
}

private int filter_ip( string par_strId, int par_nLength, string par_strPara )
{
    int nRet = 0;
    string strIpPiece;
        
    strIpPiece = LAST_LOGIN_D->query_last( par_strId )[1];
    
    if ( strIpPiece )
        strIpPiece = strIpPiece[0..(par_nLength-1)];
        
#ifdef _DEBUG_ID
    else
        TELL_BUG( _DEBUG_ID, sprintf( "no ip for %s", par_strId ) );
#endif  // _DEBUG_ID
    
    if ( strIpPiece == par_strPara )
        nRet = 1;
    
    return nRet;
    
}  // end filter

