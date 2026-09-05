// 东天目山，一座随机生成的区域。玩家副本 Zine 2014/7/14
inherit ROOM;
#include "/d/menggu/entry_migong.h"
#include <ansi.h>
void create()
{
	set("short", "小溪");
	set("long", @LONG
这里是从天目山山涧流淌下来的一条小溪。
LONG
	);
        set("outdoors", "dongtianmu");

	set("exits", ([
		//"westdown" : __DIR__"dashi",
		"southwest" : __DIR__"xiaoxib",
		"southup" : __DIR__"shanlun1",
		//"west" : __DIR__"wall1",
	]));

	set("objects", ([
		//__DIR__"npc/wujiang" : 1,
		//__DIR__"npc/songbing_y" : 2,
        ]));
	set("entry_direction","southup");
    set("migong","/d/southmountain/dongtianmu/dongtianmu");
    set("migong_posi","north");
    set("look_refuse_msg","东天目山不高，但这时雾气太重，看不清楚。\n");
    set("enter_refuse_msg","东天目山这时雾气太重，进山不太容易。\n");
	setup();
}

void init()
{
	add_action("do_look",({"look","l"}));
}