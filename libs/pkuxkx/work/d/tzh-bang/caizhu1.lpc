// Room: /d/tzh-bang/caizhu1:张八爷的家
// to wolf

inherit ROOM;

void create()
{
	set("short", "张八爷家的大门");
	set("long", @LONG
    一座富丽堂皇的宅院出现在你的眼前，两头高大的石狮子镇住了大门两
侧，朱漆大门足足有三寸厚。门上挂着两个灯笼，写着“张”字。张家是村庄首
富，张八爷为人比较好、但他的儿子就非常蛮横。因为你乱闯别人的家，几条狼
狗嚎叫着向你冲了过来。看来你要赶快离开为妙。南面是张八爷接待客人的地方，
LONG
	);

	set("exits", ([
		"north" : __DIR__"tzhroad11",
		"south" : __DIR__"caizhu2",
	]));

	set("objects", ([
		__DIR__"npc/wolfdog" : 2,
	]));

	setup();
	replace_program(ROOM);
}

