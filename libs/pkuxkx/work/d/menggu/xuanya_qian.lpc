// Room: grass.c 草原
// created by Zine 30 Aug 2010
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", WHT"悬崖前"NOR);
	set("long", @LONG
这里是按台山的余脉，一处及其险峻的悬崖横亘当前，阻隔了和林和蒙古草
原的西部。
LONG
	);

	set("exits", ([
		"east" : __DIR__"grass1_w",
		"northeast" : __DIR__"grass_w",
        "southeast" : __DIR__"grass2_w",
		//"north" : __DIR__"menggubaoexit",
	]));
	set("outdoors", "menggu_e");
	setup();
}

void init()
{
    object me=this_player();
    add_action("do_climb","climb");
    if ((int)me->query("shediaoquest/zhebie")>=2&&!me->query_temp("shediaoquest/mayu_s1")&&!me->query("shediaoquest/mayu"))
    {
        if ((int)me->query("level")<8)
        {
            return;
        }
        me->set_temp("shediaoquest/mayu_s1",1);
        tell_object(me,"你练功练得烦闷，突发奇想要爬上(climb)这座悬崖！\n");
    }
    return;
}

int do_climb(string arg)
{
    object me=this_player(),theya=new(__DIR__"xuanya");
    string *ya=({"ya","xuan ya","xuanya","悬崖","崖",});
    if (!arg||member_array(arg,ya)==-1)
    {
        tell_object(me,"你要爬什么？\n");
        return 1;
    }
    if (!me->query_temp("shediaoquest/mayu_s1")&&!me->query("shediaoquest/mayu"))
    {
        tell_object(me,"爬上去？自杀也许还快点！\n");
        return 1;
    }
    if ((int)me->query("level")<8)
    {
        tell_object(me,"你的级别太低，此刻去爬悬崖那是找死！\n");
        return 1;
    }
	if (time()-me->query("killer/time") < 15*60)
	{
		tell_object(me,"你杀了人，这时候心慌意乱，爬悬崖当心摔死。\n");
		return 1;
	}
    message_vision("$N走到悬崖脚下，攀藤附葛，一步步的爬上去。\n",me);
    me->move(theya);
    return 1;
}