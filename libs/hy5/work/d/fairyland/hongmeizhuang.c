// Room: /u/qingyun/jyzj/hongmeizhuang.c
// Written by qingyun
// Updated by jpei

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIR"红梅山庄"NOR);
	set("long", @LONG
这是一座颇大的庄子。一眼看去就知道此间主人是当地的富豪，在昆仑山
中有这么大的一座山庄确实非常少见。据说，此间主人也是武林中人，所以路
过之人也不敢随意的进入，当以江湖之礼求见。
LONG	);
	set("exits", ([
		"north" : __DIR__"dating",
		"east" : __DIR__"shanlu2",
		"westdown" : __DIR__"shanxi",
	]));
	set("objects",([
		__DIR__"npc/guanjia" : 1,
	]));
	set("outdoors", "kunlun");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
