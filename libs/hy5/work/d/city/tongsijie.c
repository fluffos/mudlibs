// Room: /yangzhou/tongsijie.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","通泗街");
	set("long",@LONG
通泗街由大块青石砌成，两边整齐的种着槐树，树下各有一道排水
沟。北边是扬州官衙，门前立着一对石狮，门上挂一匾额「扬州」。行
人到此多加快脚步，免惹是非，车马亦加上一鞭，加速通过。南面都是
民宅，几条小巷曲折穿插其中，偶然有一顶轿子进出。
LONG );
	set("outdoors", "city");

	set("exits", ([
		"west"      : __DIR__"xidajie1",
		"east"      : __DIR__"caohexiaojie",
		//"north"     : __DIR__"yamen",
		"south"     : __DIR__"biaoju",
		"southwest" : __DIR__"caohecexiang",
	]));
	set("objects", ([
		__DIR__"npc/xunbu" : 1,
	]));
	set("coor/x", -20);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
