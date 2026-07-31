// Room: /yihua/shandao.c
// rtm 2000/03/04 

inherit ROOM;

void create()
{
	set("short", "山道");
	set("long", @LONG
	这是一条宽阔的铺满了鲜花的山道，向北延伸。北边
影雾弥漫，让人有种神秘的感觉。在花丛之间依稀可见蜜蜂飞
来飞去,你向上望去只见云雾当中一座高大的宫殿依稀可见。
LONG
	);
        set("outdoors", "city");

	set("exits", ([
		"east" :"/d/xiaoyao/hubian",
		"northup" : __DIR__"shandao1",
	]));

	setup();
	replace_program(ROOM);
}

