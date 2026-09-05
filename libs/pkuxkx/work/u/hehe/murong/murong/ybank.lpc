ybank.c
//by hehe
//2003.3.5

#include <room.h>
inherit ROOM;

void create()
{
    set("short", "码头");
    set("long", @LONG
从这里可以与琴韵小筑和听香水榭遥遥相望，岸上长满了不
知名的花花草草。湖面上似乎种满了水桩伸向远方，湖面上
还停了一艘小船(boat)。
LONG
    );

    set("exits", ([
        "west" : __DIR__"yroad1",
    ]));

	set("item_desc", ([
              "boat" :
"    这是一艘小船，看来要从这里出去就要靠他了。",
                     ]));
    
    set("outdoors", "murong");
    setup();

}
void init()
{
    add_action("do_enter", "enter");
	add_action("do_cai", "cai");
}

int do_enter(string arg)
{
    object me;
    me = this_player () ;

	if(arg!="boat")
	{
		message_vision("$N看清楚往哪里钻?\n",me);
		return 0;
	}
	me->move("/d/murong/yboat");
    message_vision("\n$N跃上小舟，小船晃了晃，$N吓得脸色苍白。\n\n" ,me );
   return 1;
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
	else
	{
		if ( (int)me->query_skill("dodge", 1) >= 120)
		{ 
			if ( arg == "qinyun" )
			{
				me ->move("/d/murong/hubian2");
				tell_object(me, "\n你健步如飞，不一会就走到燕子坞...\n\n" ) ;
				return 1 ;
			}
			else if ( arg == "tingxiang" )
			{
				me ->move("/d/murong/tbank");
				tell_object(me, "\n你健步如飞，不一会就走到听香水榭...\n\n" ) ;
				return 1;
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
		    write("你走了一会儿木桩，感到腿脚有点酸痛。\n");                      
			return 1;
		}
	}
}