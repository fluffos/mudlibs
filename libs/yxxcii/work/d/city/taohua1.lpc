// taohua1.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "桃花林");
	set("long", @LONG
这是一片烂漫的桃花林，满山遍野的桃树枝上，开着桃红的桃花。桃
花上头，飞满了细细嗡嗡的不甘寂寞的蜜蜂。脚下是一条不宽也不窄的林
间小道，道边是密密丛丛的嫩草和争奇斗艳的小花。
LONG
);
	set("outdoors", "city");
	set("exits", ([
		"north" : __DIR__"taohua2",
		"south" : __DIR__"ximen",
	]));
	set("objects", ([
		"/d/wudang/npc/bee" : 1,
	]));
	setup();
	replace_program(ROOM);
}

