// neizain.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "内宅");
	set("long", @LONG
这里是衙门的内宅，住着知府的家眷。外人到此就该止步了。
LONG );
	set("exits", ([
		"south" : __DIR__"ymzhengting",
	]));
	set("objects", ([
		__DIR__"npc/yuhuan" : 1,
	]));
	setup();
	replace_program(ROOM);
}

