#include <ansi.h>
#include <mudlib.h>

inherit NPC;

string remove_ansi(string str);

void create()
{
        set_name("镜头", ({ "jingtou" }) );
        set("gender", "男性");
        set("env/invisibility", 3);    
        set_skill("dodge", 500);
        set_skill("longfeng-xiang", 500);
        map_skill("dodge", "longfeng-xiang");       
        set("attitude", "friendly");
        set("location", 1);
        set_temp("apply/id", ({ "" }));
        set_temp("apply/short", ({""}));
        set_temp("leitai", 1);
        setup();
        if(clonep()){
                remove_call_out("tohtml");
                call_out("tohtml",8);
        }
}

void do_setup(object me, object target)
{
        set("master", me);
        set("target", target);
        this_object()->set_leader(target);  
        this_object()->move(environment(target));  
        "/cmds/std/look"->look_room(this_object(), environment(target));  
        call_out("checking", 1, target);          
}

void do_remove()
{ 
   destruct(this_object());  
}

int checking(object target)
{
       object where, me;
       
       if(!objectp(me = query("master"))){
           destruct(this_object());  
           return 0;
        }
        
       if(!objectp(target) || !objectp(where = environment(target))){
message("vision", HIW"\n【试剑山庄】忽然间，摄像机发出了一整异常的响声，坏了机器故障。\n"NOR, environment(me));
           me->delete_temp("jingtou");
           destruct(this_object());  
           return 0;
        }

       if(where != environment())
              this_object()->move(where);
       call_out("checking", 1, target);
       return 1;
}

string remove_ansi(string str)
{
        int i;
        string *color = ({ BLK, RED, GRN, YEL, BLU, MAG, CYN, WHT,
                           HIR, HIG, HIY, HIB, HIM, HIC, HIW,
                           HBRED, HBGRN, HBYEL, HBBLU, HBMAG, HBCYN, HBWHT,
                           BBLK, BRED, BYEL, BBLU, BMAG, BCYN,
                           NOR, BOLD });
        if( !str || !stringp(str) ) return 0;
        i = sizeof(color);
        while( i-- ) {
                str = replace_string(str, color[i], "");
                }
        return str;
}

void relay_message(string msgclass, string msg)
{
        object player, room;
        string *ary;
        int i;

        msg = "1\n" +environment(this_object())->query("short")+" - " + msg;
        ary = explode(msg, "\n");
        if(objectp(player = query("master")))
           room = environment(player);
        for (i=1;i<sizeof(ary);i++)
                if (room){
                  message("vision", HIW"【试剑山庄】"NOR+ary[i]+NOR+"\n", room);
                  write_file("/log/html/BIWU1", sprintf("%s\n", remove_ansi(ary[i])));
                }
}

//开始写mud1.html文件。
void tohtml()
{
        string *message;
        int i;
        message = explode (read_file ("/log/html/BIWU1"), "\n");
        write_file("/log/html/mud1.html", "<html>\n<head>\n<meta http-equiv='refresh' content='8;url=mud1.html'>\n<META HTTP-EQUIV='Pragma' CONTENT='no-cache'>\n<meta http-equiv='Content-Type' content='text/html; charset=gb2312'>\n<title>书剑</title>\n<link rel='stylesheet' href='http://202.96.84.26/my_style.css' type='text/css'>\n</head>\n<body>\n", 1);
        write_file("/log/html/mud1.html", "<center><font color=BLUE>"+CHINESE_MUD_NAME+"</font>　比武大会实况　"+ctime(time())[11..18]+"(自动刷新)\n<HR size=1 width='95%'>\n",0);
        write_file("/log/html/mud1.html", "<table border=0 cellpadding=0 cellspacing=0 width='95%'>\n",0);
        for (i=0; i<sizeof(message); i++)
                write_file("/log/html/mud1.html", "<tr><td width='100%' align=left>"+message[i]+"</td></tr>\n",0);
        write_file("/log/html/mud1.html", "</table>\n<HR size=1 width='95%'><a href=index.html>返回首页</a></center></body></html>",0);
        write_file("/log/html/BIWU1", "", 1);
        remove_call_out("tohtml");
        call_out("tohtml",8);
}

