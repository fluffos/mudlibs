// Room: /d/diaoyudao/haitan3.c 海滩
// hongdou 98.09.20

inherit ROOM;

void create()
{
	set("short", "海滩");
	set("long", @LONG
这里是钓鱼岛的北海滩，人际罕至，沙滩上到处都是碎贝壳，走在上面，
嚓嚓作响。几只大海蟹，挥动着大鳌，正在向你示威。北边是一望无际的大
海，西南方向有一个倭寇建的灯塔，东北不远有一片礁石。
LONG
	);

	set("exits", ([
                "northeast" : __DIR__"shiqun",
		"west" : __DIR__"haitan4",
	]));

	set("outdoors", "diaoyudao");
	setup();
	replace_program(ROOM);
}

