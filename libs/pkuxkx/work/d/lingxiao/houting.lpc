// File		: houting.c
// Created By	: iszt@pkuxkx, 2006-08-16

inherit ROOM;

void create()
{
	set("short", "后厅");
	set("long", @LONG
这里是掌门人或大弟子会见、宴请重要客人的所在，虽不如大厅宽敞，却多
了几分雅致。
LONG);
	
	set("indoors", "凌霄城");
	set("exits", ([
		"south" : __DIR__"dating",
	]));
	set("objects", ([
		__DIR__"npc/dizi" : 1,
                __DIR__"npc/wenwanfu" : 1,
	]));

	setup();
	replace_program(ROOM);
}
