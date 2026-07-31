
// htmld.c

#include <net/daemons.h>
#include <net/macros.h>

#define HTML_WHO "/html/who.html"
#define HTML_FINGERD "/html/finger/"
#define HTML_SHOWTOP "/html/showtop.html"
#define TOP_LST     "/data/top_users"

mapping *top_lst;

int sort_user(object ob1, object ob2);

int sort_top(mapping a,mapping b)
{
    return a["status"]>b["status"];
}

int show_top(object me)
{
    int i;
    string  str;
        
    if (!me)    return 0;
    
    i=sizeof(top_lst);
    top_lst += ({ allocate_mapping(3) });
    if (me->query("mud_age")<3600)  return 0;
    if ( wizardp(me) )  return 0;
    top_lst[i]["id"] = me->query("id");
    top_lst[i]["name"] = me->query("name");
    top_lst[i]["status"] = (me->query("combat_exp") + me->query("max_neili")*500)/( me->query("mud_age")/3600 );

    top_lst = sort_array(top_lst,"sort_top",top_lst[0]);
    if (sizeof(top_lst)>10)
        top_lst=top_lst[0..9];
    str = "<HEAD><TITLE>"+MUD_NAME+"练功狂人榜</TITLE></HEAD>";
    str += sprintf("<body TEXT='#000000' LINK='#FF8000' VLINK='#ff0000' ALINK='#000000' background='/background1.gif'> <!-- Commonwealth Network HTML Code Version 3.2 --><a target='_top' href='http://commonwealth.riddler.com/Commonwealth/bin/statthru?380358'><p align='center'><img height='60' width='468' border='0' src='http://commonwealth.riddler.com/Commonwealth/bin/statdeploy?380358' alt='Check out our sponsor!' ISMAP></a> <br>");

    str += sprintf("<h3 align=center><font face='幼圆' color=#ff0000>%s"
                                "<font face='幼圆'color=#000000>练功狂人排行榜</font>"
                                "</h3><hr>",CHINESE_MUD_NAME);

    str += "<center><TABLE BORDER=0><br><font size=3 face=黑体>";

    foreach (mapping top in top_lst){
        str+=sprintf( "<tr><th><font size=3 face='幼圆'>%s(%s) </th> \n",top["name"],capitalize(top["id"]) );
        str+=sprintf( "<td><font size=3 face='幼圆'>%s </td></tr> \n", repeat_string("■",top["status"]/10000));
    }
     str += sprintf("</TABLE>\n<p align='center'><font color='#FF8000'><a href=http://www.topcn.com/siteinfo.asp?UserName=zhm&SiteType=0 target=_blank><img src=http://www1.topcn.com:8081/statistics.asp?zhm&referURL='+escape(top.document.referrer)+'&curURL='+escape(top.document.URL)+'&imgStyle=0'+' border=0 alt='Top中文网站龙虎榜'width=20 height=20 ></a></font></p>");
     str += "</CENTER></BODY></HTML>"; 
     return write_file(HTML_SHOWTOP,str,1);
}


int update_online() 
{
        string  ret = "<HEAD><TITLE>"+MUD_NAME+"目前在线的玩家</TITLE></HEAD>";
        string str,id;
        object *list;
        int i;

        reset_eval_cost();
        list = sort_array(users(), "sort_user", this_object());
        ret += sprintf("<body TEXT='#000000' LINK='#FF8000' VLINK='#ff0000' ALINK='#000000' background='/background1.gif'> <!-- Commonwealth Network HTML Code Version 3.2 --><a target='_top' href='http://commonwealth.riddler.com/Commonwealth/bin/statthru?380358'><p align='center'><img height='60' width='468' border='0' src='http://commonwealth.riddler.com/Commonwealth/bin/statdeploy?380358' alt='Check out our sponsor!' ISMAP></a> <br>");

        ret += sprintf("<h3 align=center><font face='幼圆' color=#ff0000>%s"
                                "<font face='幼圆'color=#000000>在线玩家列表</font>"
                                "</h3><hr>",CHINESE_MUD_NAME);

        ret += "<center><TABLE BORDER=1><br><font size=3 face=黑体>";

        foreach ( object player in list )
        {
                if( !environment(player) ) continue;
                if( wizardp(player) && player->query("env/invisibility") ) continue;
                id=player->query("id");
                ret += sprintf("<td><font size=3 face='幼圆'>"+
                "<a href=finger/%c/%s.html <em>  %s(%s)  </em></a></font>",id[0],id,player->name(1),capitalize(id));
                if( i%3 == 2 )
                        ret += "<tr>";
                i++;
        }
        ret += "</TABLE>";
        ret +="<p><hr></p><p><font size=4 face='幼圆' color=#340460>共有"+CHINESE_D->chinese_number(i)+ "个玩家连线中。</font></p></center></body>";
        str=read_file("/log/log_count");
        if (str && sscanf(str,"%d",i)){
        ret +="<p><hr></p><center><font size=3 color='#FF0000'>自一九九九年二月九日起，"+MUD_NAME+"已有</font><font color='#00FF00'>"+CHINESE_D->chinese_number(i)+"位</font><font color='#FF0000'>义士在这里闯荡江湖。</font></center>\n";
        }
        ret += sprintf("<p align='center'><font color='#FF8000'><a href=http://www.topcn.com/siteinfo.asp?UserName=zhm&SiteType=0 target=_blank><img src=http://www1.topcn.com:8081/statistics.asp?zhm&referURL='+escape(top.document.referrer)+'&curURL='+escape(top.document.URL)+'&imgStyle=0'+' border=0 alt='Top中文网站龙虎榜'width=20 height=20 ></a></font></p>");
        return write_file(HTML_WHO,ret,1);
}
int sort_user(object ob1, object ob2)
{
        if( wizardp(ob1) && !wizardp(ob2) ) return -1;
        
        if( wizardp(ob2) && !wizardp(ob1) ) return 1;

        if( wizardp(ob1) && wizardp(ob2) )
                return (int)SECURITY_D->get_wiz_level(ob2) 
                        - (int)SECURITY_D->get_wiz_level(ob1);

        if( ob1->query("id") && !ob2->query("id") )
                return -1;
        if( ob2->query("id") && !ob1->query("id") )
                return 1;
        if( !ob1->query("id") && !ob2->query("id") )
                return (int)ob2->query("combat_exp") - (int)ob1->query("combat_exp");
        return strcmp(ob2->query("id"), ob1->query("id"));
}

int finger_who(object ob,object body)
{
        string str,file;
        string id;
        
        if( !ob )    return 0;
        id=ob->query("id");
// USER_OB
        str = "<HTML><HEAD><TITLE>在线玩家查询</TITLE></HEAD>";   
        str += sprintf("<body TEXT='#000000' LINK='#FF8000' VLINK='#ff0000' ALINK='#000000' background='/background1.gif'> <!-- Commonwealth Network HTML Code Version 3.2 --><a target='_top' href='http://commonwealth.riddler.com/Commonwealth/bin/statthru?380359'><p align='center'><img height='60' width='468' border='0' src='http://commonwealth.riddler.com/Commonwealth/bin/statdeploy?380359' alt='Check out our sponsor!' ISMAP></a> <br>");

        str += sprintf("<h3 align=center><font face='幼圆' color=#ff0000>%s"
         "<font face='幼圆'color=#000000>玩家查询</font>"
         "</h3><p><hr></p>", CHINESE_MUD_NAME);
        str += sprintf("<center><TABLE BORDER=5>"
         "<TR><TH>英文代号：</TH><TD>%s</TD></TR>"
         "<TR><TH>姓    名：</TH><TD>%s</TD></TR>"
         "<TR><TH>称    谓：</TH><TD>%s</TD></TR>"
         "<TR><TH>性    别：</TH><TD>%s</TD></TR>"
         "<TR><TH>年    龄：</TH><TD>%s</TD></TR>"
         "<TR><TH>容    貌：</TH><TD>%d</TD></TR>"
         "<TR><TH>福    缘：</TH><TD>%d</TD></TR>"
         "<TR><TH>权限等级：</TH><TD>%s</TD></TR>",
        id,
        ob->query("name"),
        ob->query("title"),
        ob->query("gender"),
        chinese_number(ob->query("age")),
        ob->query("per"),
        ob->query("kar"),
         wizhood(ob),
        );


       

// LOGIN_OB
     if (objectp(body)){
     str += sprintf("<TR><TH>Email地址：</TH><TD>%s</TD></TR>",body->query("email"));
     }

     str += sprintf("</TABLE>\n<p align='center'><font color='#FF8000'><a href=http://www.topcn.com/siteinfo.asp?UserName=zhm&SiteType=0 target=_blank><img src=http://www1.topcn.com:8081/statistics.asp?zhm&referURL='+escape(top.document.referrer)+'&curURL='+escape(top.document.URL)+'&imgStyle=0'+' border=0 alt='Top中文网站龙虎榜'width=20 height=20 ></a></font></p>");
     str += "</CENTER></BODY></HTML>"; 
     file=sprintf(HTML_FINGERD+"%c/%s.html",id[0],id);
     assure_file(file);
     return write_file(file,str,1);
    show_top(ob);
}       

void create() 
{ 
    string file;
    seteuid(getuid()); 
    
    if (!restore_object(TOP_LST))
    top_lst = ({ });
}
