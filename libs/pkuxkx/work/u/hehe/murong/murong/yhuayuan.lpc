//yhuayuan.c
//by hehe
//2003.3.5

#include <room.h>
inherit ROOM;

void create()
{
    set("short", "花园");
    set("long", @LONG
这里是燕子坞的花园，向南与还施水阁有水相隔。
LONG
    );

    set("exits", ([
		"west" : __DIR__"yroad8",
    ]));
    
    set("outdoors", "murong");
    setup();

}
void init()
{
	add_action("do_cai","cai");
}
int do_cai(string arg)
{
	object me;
    me = this_player () ;
	if( !arg )
		return notify_fail("你想游泳啊，小心淹着！");
	if ( arg == "zhuang" )
	{
		if ( (int)me->query("neili") < 80)
			return notify_fail ("$N伸脚轻轻试了试木桩，心中有点发慌，忙缩了回来。\n");
	    if ( (int)me->query("combat_exp") <10000)
	    {
			me->receive_damage("qi", 50, "掉进湖里淹死了");
            me->receive_wound("qi",  50, "掉进湖里淹死了");
            message_vision("$N只觉得脚下一个踉跄，... 啊...！\n", me);
            tell_object(me, "你掉进大湖，几经努力才爬上木桩，身上又疼又酸。\n");
            message("vision", "只见" + me->query("name") + "从湖里湿漉漉爬上来，脸色苍白已极！\n", environment(me), me);
			return 1;
		}
		me->add("jingli", (-1)*random(50), "淹死了");
		me->add("neili", (-1)*random(50));
        message_vision("$N脚踩八卦方位，走得飞快。\n", me);
		return 1;
	}

	if ( (int)me->query_skill("dodge", 1) >= 120)
	{ 
		if ( arg == "huanshi" )
		{
			me ->move("/d/murong/yhssg");
			tell_object(me, "\n你健步如飞，不一会就走到还施水阁前面的空地...\n\n" ) ;
			return 1 ;
		}
		else
		{
			return notify_fail ("不要乱跑！\n");
		}
	 }
    else if ( (int)me->query_skill("dodge", 1) < 120)
	{
		me->improve_skill("dodge", me->query("dex")); 
		me->add("jing",-15);
        message_vision("$N走了一会儿木桩，感到腿脚有点酸痛。\n",me);                      
		return 1;
	}
}
