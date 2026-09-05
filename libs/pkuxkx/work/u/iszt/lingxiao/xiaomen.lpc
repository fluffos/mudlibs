// File		: xiaomen.c
// Created By	: iszt@pkuxkx, 2007-01-22

inherit ROOM;

void create()
{
	set("short", "小门");
	set("long", @LONG
这便是白自在居住的院子门口，在这里，可以看到北面庭院中满地洁白的积
雪，一派祥和的景象。小门虚掩着，两名弟子正在此处看守，一边切磋剑法。往
南走过石板路就是练武场。
LONG);

	set("outdoors", "凌霄城");
	set("exits", ([
		"north" : __DIR__"tingyuan",
		"south" : __DIR__"stonen3",
	]));
	set("objects", ([
		__DIR__"npc/dizi_xiaomen" : 2,
	]));

	setup();
	replace_program(ROOM);
}