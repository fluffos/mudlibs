// File		: armorroom.c
// Created By	: iszt@pkuxkx, 2007-02-16

inherit ROOM;

void create()
{
	set("short", "武器库");
	set("long", @LONG
这里是凌霄城中的防具库，四壁上挂的都是各色防具，包括雪山上必备的冰
爪、皮靴、皮手套、皮甲等物品。一个黑黑瘦瘦的雪山弟子正在看管着，应
是负责发放防具。此处离练武场不远，隐隐有长剑相击的声音传来。
LONG);

	set("indoors", "凌霄城");
	set("exits", ([
		"north" : __DIR__"stonen4",
	]));
	set("objects", ([
		__DIR__"npc/baowanye" : 1,
	]));

	setup();
	replace_program(ROOM);
}