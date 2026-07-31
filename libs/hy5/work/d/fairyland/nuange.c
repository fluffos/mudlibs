// Room: /u/qingyun/jyzj/nuange.c
// Written by qingyun
// Updated by jpei

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "暖阁");
	set("long", @LONG
昆仑山中一向甚为寒冷，但在此暖阁之中却温暖如春，可又不见何处生着
炭火，此间取暖方法当真巧妙无比。阁中陈设辉煌灿烂，榻上椅上都铺着锦缎
软垫，极是富丽豪华。南边是大厅。
LONG	);
	set("exits", ([
		"south" : __DIR__"dating",
	]));
/*	set("objects",([
		__DIR__"npc/zhu-jiuzhen" : 1,
	]));*/
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
