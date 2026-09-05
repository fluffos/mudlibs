//yhuayuan.c
//by hehe
//2003.3.5

#include <room.h>
inherit ROOM;

void create()
{
    set("short", "花园");
    set("long", @LONG
这里是燕子坞的花园，向南与还施水阁有水相隔，水中设有一些木桩(zhuang)。
花园的东侧有处花草（huacao）比较凌乱，似乎被人动过。
LONG
    );

    set("exits", ([
		"west" : __DIR__"yroad8",
    ]));
	set("item_desc", ([
		"zhuang" :
"一根根木桩深埋于水底，水面上只隐隐约约露出,不知道踩上去什么感觉?
木桩在湖中延伸，似乎可以通到水中的一处楼阁(huanshi)。\n",
    "huacao" :
"一处与众不同的花草，似乎被人动过。",    	
                     ]));
                     
    set("lingwu_family", "姑苏慕容");
    set("outdoors", "murong");
    setup();

}
void init()
{
	add_action("do_cai","cai");
	add_action("do_cai","step");
	add_action("do_bo","bo");
	add_action("do_bo","move");
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

	if ( (int)me->query_skill("dodge", 1) >= 120)
	{
		if ( arg == "huanshi" )
		{
                if(!me->query_temp("murong/tingxiang") && (string)me->query("family/master_id")!="murong bo")
		{
		tell_object(me,"你没有征得庄主的同意,不能前往还施水阁................\n");
		return 1;
		}
			tell_object(me, "\n你健步如飞，不一会就走到还施水阁前面的空地...\n\n" ) ;
			me ->move("/d/murong/yhssg");
			return 1 ;
		}
		else
		{
			return notify_fail ("不要乱跑！\n");
		}
	 }
        else if ( (int)me->query_skill("dodge", 1) < 120)
	{
	    return notify_fail ("你轻功太差无法过去！\n");
		return 1;
	}
}
int do_bo(string arg)
{
	object me=this_player();
	if (!arg) return 0;
  if (arg=="huacao" || arg=="花草")
  	{
                if (me->query("family/master_id")=="murong bo")
  		{
                tell_object(me,"你翻了翻花草，找个一个秘道钻了过去。\n");
  		me->move("/d/murong/ymishi");
  		return 1;
  	  }
  	  else
  	  {
          tell_object(me,"你翻了翻花草，却不料被刺扎了一下。\n");
  	  return 1;	
  	  }
  	}
  return 0;	
}
