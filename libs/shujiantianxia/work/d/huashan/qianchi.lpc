// Room: /d/huashan/qianchi.c
// Date: Look 99/03/25

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "千尺幢");
	set("long", @LONG
前面有一斜如天垂石梯的山阶，这就是赫赫有名的千尺幢，千尺幢是依一
陡峭岩脊的裂缝开凿而成，斜度约七十度，高约二十米，仅容一人上落。如果
不是精气十足，还是不要冒险攀登的好。
LONG
	);
	set("exits", ([
		"westdown" : __DIR__"qingke",
		"southup" : __DIR__"baichi",
	]));

	set("objects", ([ 
		__DIR__"npc/jianke" : 1,
	]));
 
	set("no_clean_up", 0);
	set("outdoors", "华山" );

	set("coor/x",60);
  set("coor/y",80);
   set("coor/z",20);
   setup();
}
 
int valid_leave(object me, string dir)
{
        if (dir == "southup") {
                me->receive_damage("jing", 30);
                me->receive_damage("qi", 30);
        }
	return 1;
}

void init2(object me)
{
        if (me->query_dex() <= random(31) && userp(me) && !wizardp(me) ) {
                me->receive_damage("qi", 50);
                message_vision(HIC"一阵山风吹来，$N一不小心脚下踏了个空，... 啊...\n"NOR, me);
                me->move(__DIR__"path1");
                tell_object(me, HIR"你从山上滚了下来，只觉得浑身无处不疼。\n"NOR);
		message("vision", HIR"只见" + me->name() + "从山上骨碌碌地滚了下来，躺在地上半天爬不起来！\n"NOR, environment(me), me);
        }
}

