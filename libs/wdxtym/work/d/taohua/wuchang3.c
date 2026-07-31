// wuchang1.c

inherit ROOM;

void create()
{
	set("short", "修行场");
	set("long", @LONG
这里是桃花岛弹指山庄修行的场所，大部分的桃花岛弟子武功有了
一定的根基以后就在这里苦修，领悟上乘武学。与其他两处不同的
是，这里立着几个制作精巧的铁人，看上去非常剽悍。
LONG
	);
	set("exits", ([
		"north" : __DIR__"houyuan",
	]));

 	set("objects", ([
		"/clone/npc/tie-ren" : 3,
	]));

	set("outdoors", "taohua");
	set("for_family", "桃花岛");
	setup();
}
