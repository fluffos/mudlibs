// change by edward
#include <ansi.h>
inherit ITEM;

void create()
{
    set_name(HIW"十四天书"NOR,({"skybook","book"}));
    set("long","大侠金庸所留下的书，据说书中有着极大的秘密。\n"
		ZJURL("cmds:study skybook")+ZJSIZE(20)+HIC"读一下"NOR"\n" );
    set("unit","本");
    set("value",1400);
    setup();
}

void init()
{
       add_action("do_study", "study");
       add_action("do_study", "du");
}
int do_study(string arg)
{
    string desc,name;
    object me=this_player();
    desc=WABAO_D->query("desc");
	name=WABAO_D->query("short");
    if (arg=="skybook"||arg=="book")
        {
        if (me->query("jing")<20) return notify_fail("你太累了，先歇会儿吧。\n");
        message_vision(HIC"$N摊开"+HIW"十四天书"+HIC"，静心研读。\n"NOR,me);
        if (stringp(desc))
            tell_object(me,"书里忽然现出一行字来：\n《"HIY+name+NOR"》 \n"HIG+desc+"\n"NOR);
        return 1;
        }
    else return 0;
}
