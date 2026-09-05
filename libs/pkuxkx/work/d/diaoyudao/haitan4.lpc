// Room: /d/diaoyudao/haitan4.c 海滩
// hongdou 98.09.20

inherit ROOM;

void create()
{
	set("short", "海滩");
	set("long", @LONG
这里是钓鱼岛的北海滩，沙滩上到处都是碎贝壳，走在上面，嚓嚓做响。
北边便是一望无际的大海。东北方有一小片礁石群。
LONG
	);

	set("exits", ([
                "east" : __DIR__"haitan5",
		"southwest" : __DIR__"haitan3",
	]));

	set("objects", ([
                __DIR__"npc/haixie1":3,

	]));

	set("outdoors", "diaoyudao");
	setup();
	replace_program(ROOM);
}

