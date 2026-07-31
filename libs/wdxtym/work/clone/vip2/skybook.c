// change by edward
#include <ansi.h>
inherit ITEM;

void create()
{
    set_name(HIW"十四天书"NOR,({"skybook","book"}));
    set("long","大侠金庸所留下的书，据说书中有着极大的秘密，下线丢失。\n"ZJURL("cmds:study book11")+ZJSIZE(20)+"翻阅"NOR"。\n");
    set("unit","本");
    set("value",100);
		set("base_value", 10);

    setup();
}

void init()
{
       add_action("do_study", "study");
}
int do_study(string arg)
{
	string dest;

    string desc,name,file;
	mapping exit;

    object me=this_player();
    file=WABAO_D->query("file");

    desc=WABAO_D->query("desc");
	name=WABAO_D->query("short");
    if (arg=="skybook11"||arg=="book11")
        {
        if (me->query("jing")<20) return notify_fail("你太累了，先歇会儿吧。\n");
        message_vision(HIC"$N摊开"+HIW"十四天书"+HIC"，静心研读。\n"NOR,me);
        if (stringp(desc))
		{
				if(wizardp(me))
				{
            tell_object(me,"书里忽然现出一行字来：\n《"HIY+name+NOR"》 \n"HIG+desc+"\n"HIC"路径："+file+"\n"+ZJURL("cmds:goto "+file)+"瞬间移动"+NOR""+"\n"NOR);
 //           tell_object(me,"ZJURL("cmds:goto "+file)+"飞过去"+NOR"。);

//				CHANNEL_D->do_channel( this_object(), "sys", "飞贼出现了。"+ZJURL("cmds:goto "+(file))+"飞过去"+NOR"。");

				}else
				{
            tell_object(me,"书里忽然现出一行字来：\n《"HIY+name+NOR"》 \n"HIG+desc+"\n"NOR);

				}
        return 1;
		}
        }
    else return 0;
}
