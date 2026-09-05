// File		: chengtouw1.c
// Created By	: iszt@pkuxkx, 2006-08-15

#include <ansi.h>;

inherit ROOM;

void create()
{
	set("short", WHT"城头"NOR);
	set("long", @LONG
走上城墙，只觉一股冷气迎面扑来。这城上风极大，直吹得人摇摇晃晃，站
立不稳，就连在此值守的雪山弟子也冻的发抖。还是快点离开吧，这里没什么好
看的，你不禁想。
LONG);
	
	set("outdoors", "凌霄城");
	set("item_desc", ([
		"out" : "外面是一道深深的冰沟，那道冰沟有七八丈阔，不易跃(yue)过。\n",
	]));
	set("exits", ([
		"eastup" : __DIR__"chenglou",
		"west" : __DIR__"chengtouw2",
		"eastdown" : __DIR__"chengmen",
	]));
	set("objects", ([
		__DIR__"npc/dizixl" : 1,
	]));

	setup();
}

void init()
{
	add_action("do_yue", "yue");
}

int do_yue(string arg)
{
	if (this_player()->query_skill("dodge")<=1000)
		return notify_fail("那么宽，你的轻功不足以让你跃过！\n");
	return 1;
}

int valid_leave(object me, string dir)
{
	if (dir == "eastdown") {
		if (me->id("xueshan dizi")) 
			return 0;
	}
	return ::valid_leave(me, dir);
}
