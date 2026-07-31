// Room: /yihua/shandao1.c
// rtm 2000/03/04 

inherit ROOM;

void create()
{
	set("short", "山道");
	set("long", @LONG
	这是一条宽阔的铺满了鲜花的山道，向北延伸。北边影雾
弥漫，让人有种神秘的感觉。在花丛之间依稀可见蜜蜂飞来飞去,你
向上望去只见云雾当中一座高大的宫殿依稀可见。
LONG
	);
        set("outdoors", "city");

	set("exits", ([
		"southdown" : __DIR__"shandao",
		"northup" : __DIR__"shandao2",
	]));

	setup();
	replace_program(ROOM);
}

