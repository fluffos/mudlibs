// 东天目山，一座随机生成的区域。玩家副本 Zine 2014/7/14
inherit ROOM;
#include <ansi.h>
#include "/d/menggu/entry_migong.h"
void create()
{
	set("short", "大觉寺");
	set("long", @LONG
这里是大觉寺，因为地处偏僻，香火并不旺盛。
LONG
	);
        set("outdoors", "dongtianmu");

	set("exits", ([
		"enter" : __DIR__"dajue",
		//"southwest" : __DIR__"xiaoxib",
		"north" : __DIR__"shanlus1",
		//"west" : __DIR__"wall1",
	]));

	set("objects", ([
		//__DIR__"npc/wujiang" : 1,
		//__DIR__"npc/songbing_y" : 2,
        ]));
	set("entry_direction","north");
    set("migong","/d/southmountain/dongtianmu/dongtianmu");
    set("migong_posi","south");
    set("look_refuse_msg","东天目山不高，但这时雾气太重，看不清楚。\n");
    set("enter_refuse_msg","东天目山这时雾气太重，进山不太容易。\n");
	setup();
}

void init()
{
	add_action("do_look",({"look","l"}));
}