// Room: /u/qingyun/jyzj/dating.c
// Written by qingyun
// Updated by jpei

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"大厅"NOR);
	set("long", @LONG
这里是山庄会客之所，大厅之中坐着此间庄主。每逢年节，就有许多仆役
在此等侯，希望主人能赏一些银子。厅子两旁放置着许多椅子和茶机，是供客
人坐的。这里虽然远离中原，但来此之客却是当真不少。厅中壁上挂着一大副
猛虎之图。这里有几个童仆来回地侍侯着。
LONG	);
	set("exits", ([
		"south" : __DIR__"hongmeizhuang",
		"north" : __DIR__"nuange",
		"east" : __DIR__"houyuan",
	]));
	set("objects",([
		__DIR__"npc/zhu-changling" : 1,
	]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
