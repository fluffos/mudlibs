// Write By Yanyang@SJ 2001.9.26
// Room: /d/changan/qingchi.c

inherit ROOM;
#include <wanted.h>

void create()
{
	set("short", "清池");
	set("long", @LONG
这里是长安城的清池。地板是上好的檀香木，光滑而略带潮湿。四面的墙
壁挂满了风干的花环，散发出醉人的香气。几个如花似玉的小丫环正在忙碌，
望向窗外，一个巨大的青铜缸架在烈火上，丫环们正在慢慢的加入清泉水。
LONG
        );
        set("no_fight", 1); 

        set("exits", ([
                "east" : __DIR__"fengchi",
                "west" : __DIR__"longchi",
                "north": __DIR__"eastjie2",
        ]));

	set("objects", ([
		__DIR__"npc/xiaoyahuan" : 1,
	]));

	set("item_desc",([            
		"east" : "里面雾气很大，你什么也看不到。\n",
		"west" : "里面雾气很大，你什么也看不到。\n",
	])); 

        set("incity",1);
	setup();
}

int valid_leave(object me,string dir)
{
	if ( dir != "north" && me->query_conditions_by_type("poison"))
		return notify_fail("啊！你身中剧毒还去洗澡，可能有危险哦！\n");
	if ( dir != "north" && is_wanted(me))
		return 0;
	if ((dir == "east" || dir == "west" )&& me->query_temp("pay_wash") < 1) {
		return notify_fail("小丫环一把拦住你说道：“要付钱的啊！一两黄金！”\n");
	}
	if ((dir == "west" && me->query("gender") == "女性")
	||(dir == "east" && me->query("gender") != "女性")) {
		return notify_fail("小丫环一把拉住你说道：“走错了，那面才是！”\n");
        }
	return ::valid_leave(me,dir);
}
