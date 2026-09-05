// File		: weaponroom.c
// Created By	: iszt@pkuxkx, 2007-02-16

inherit ROOM;

void create()
{
	set("short", "武器库");
	set("long", @LONG
这里是凌霄城中的武器库，四壁上挂的都是各色武器，以雪山弟子最常用的
长剑为多，也有若干并非长剑的武器。一个黑黑瘦瘦的雪山弟子正在看管着，应
是负责发放武器，此处离练武场不远，隐隐有长剑相击的声音传来。
LONG);

	set("indoors", "凌霄城");
	set("exits", ([
		"north" : __DIR__"stonen2",
	]));
	set("objects", ([
		__DIR__"npc/sunwannian" : 1,
	]));

	setup();
	replace_program(ROOM);
}