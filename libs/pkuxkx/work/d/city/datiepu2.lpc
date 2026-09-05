// Room: /city/datiepu.c
// YZC 1995/12/04

inherit ROOM;

void create()
{
	set("short", "打铁铺内室");
	set("long", @LONG
这里是打铁铺的内室，专门出售一些价钱不菲的兵器。如果你要订一件属于
自己的兵器，当然还得去找老板。
LONG);
	set("exits", ([
		"north" : __DIR__"datiepu",
	]));
	set("objects", ([
	//	"/adm/npc/wang":1,
		"/d/city/npc/huoji1":1,
	]));
	setup();
	replace_program(ROOM);
}
