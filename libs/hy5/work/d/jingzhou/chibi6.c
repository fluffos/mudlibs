// /d/jingzhou/chibi6.c
// netkill /98/9/10/
// 朱雀古铁

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", YEL "赤壁古战场" NOR);
        set("long", @LONG
这里就是有名的古赤壁，对岸一面巨大的悬崖上书有“赤壁”两
个大字，想当年曹操百万精兵在此被周愈杀的片甲不留，含恨而归，
大文学家苏东坡游临此地，感慨的留下了“遥想公谨当年，小乔初嫁
了，羽扇纶巾，雄姿英发，谈笑间，强虏灰飞烟灭。...”令后人引
为佳句。从这里向江面看去，只见滚滚江水东流去，江面上若隐若现
一条条大铁索(tiesuo),原来是当年吴国为了抵御曹操而修的锁江链。
LONG
        );
        set("outdoors", "jingzhou");
	set("item_desc", ([
		"teisuo" : "只见一条条铁锁链横在江中，多年江水冲击依然不朽。\n",
		]));
        set("exits", ([
                "east" : __DIR__"chibi5",
		            
        ]));

             
        setup();
	//replace_program(ROOM);
} 


void init()
{
	add_action("do_jump","jump");
	add_action("do_jump","tiao");
}

int do_jump(string arg)
{
	object me=this_player();

	if (arg=="" || ! arg ) return 0;
if (arg!="tiesuo") return 0;
	if ( (int)me->query_skill("dodge") < 100 )
		{
		message_vision("$N一闭眼，跳入了滔滔江水中\n",me);
		tell_object(me,"只觉得一股强大的水流将你推了回来！\n");
		me->unconcious();
		}
	else {
		message_vision("$N一纵身，向江面上跳去\n",me);
		tell_object(me,"轻轻的落在了铁锁上面\n");	
		me->move(__DIR__"tiesuo");
	 	}
	return 1;
}
