//tbank.c
//by hehe
//2003.3.5

#include <room.h>
inherit ROOM;

void create()
{
    set("short", "码头");
    set("long", @LONG
从这里可以与琴韵小筑和燕子坞遥遥相望，湖边的岸上长满了不
知名的花花草草。湖面上似乎种满了水桩(zhuang)伸向远方，湖
面上还停了一艘小船(boat)。
LONG
    );

    set("exits", ([
        "west" : __DIR__"troad1",
    ]));

	set("item_desc", ([
              "boat" :
"    这是一艘小船，看来要从这里出去就要靠他了。\n",
		"zhuang" :
"一根根木桩深埋于湖底，湖面上只隐隐约约露出,不知道踩上去什么感觉?
木桩在湖中延伸，似乎可以通到琴韵小筑(qinyun)和燕子坞(yanziwu)\n",
                     ]));

    set("outdoors", "murong");
    setup();

}
void init()
{
    add_action("do_enter", "enter");
	add_action("do_cai", "cai");
	add_action("do_cai", "step");
}

int do_enter(string arg)
{
    object me;
    me = this_player () ;

	if(arg!="boat")
	{
		message_vision("看清楚！你要往哪里钻?\n",me);
		return 1;
	}
	me->move("/d/murong/tboat");
    message_vision("\n$N跃上小舟，小船晃了晃，$N吓得脸色苍白。\n\n" ,me );
return 1;
}
int do_cai(string arg)
{
	object me;
    me = this_player () ;
	if( !arg )
		return notify_fail("你要踩什么？\n");
	if ( arg == "zhuang" )
	{
		if ( (int)me->query("neili") < 80)
			return notify_fail ("你伸脚轻轻试了试木桩，心中有点发慌，忙缩了回来。\n");
	    if ( (int)me->query("combat_exp") <10000)
	    {
			me->receive_damage("qi", 50, "掉进湖里淹死了");
            me->receive_wound("qi",  50, "掉进湖里淹死了");
            message_vision("$N只觉得脚下一个踉跄，... 啊...！\n", me);
            tell_object(me, "你掉进大湖，几经努力才爬上木桩，身上又疼又酸。\n");
            message("vision", "只见" + me->query("name") + "从湖里湿漉漉爬上来，脸色苍白已极！\n", environment(me), me);
			return 1;
		}
	if (me->is_busy()) return notify_fail("你的动作还没有完成，不能移动。\n");
		me->receive_damage("jing", random(50), "淹死了");
		me->add("neili", (-1)*random(50));
        message_vision("$N脚踩八卦方位，走得飞快。\n", me);
        me->start_busy(1);
        if ( me->query("combat_exp") >= me->query_skill("dodge", 1) * me->query_skill("dodge", 1) * me->query_skill("dodge", 1) / 10 )
        me->improve_skill("dodge", me->query("int") + me->query("kar"));
		return 1;
	}
	else
	{
		if ( (int)me->query_skill("dodge", 1) >= 120)
		{
			if ( arg == "yanziwu" )
			{
				me ->move("/d/murong/ybank");
				tell_object(me, "\n你健步如飞，不一会就走到燕子坞...\n\n" ) ;
				return 1 ;
			}
			else if ( arg == "qinyun" )
			{
				me ->move("/d/murong/hubian2");
				tell_object(me, "\n你健步如飞，不一会就走到琴韵小筑...\n\n" ) ;
				return 1;
			 }
			 else
			 {
				return notify_fail ("不要乱跑！\n");
			 }
		 }
		else if ( (int)me->query_skill("dodge", 1) < 120)
		{
                        return notify_fail ("你功夫没练到家，还是老老实实的坐船去吧！\n");
			return 1;
		}
	}
}
