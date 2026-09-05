// Room: /d/diaoyudao/haitan1.c 海滩
// hongdou 98.09.20

inherit ROOM;

void create()
{
	set("short", "海滩");
	set("long", @LONG
这里是钓鱼岛的北海滩，沙滩上到处都是碎贝壳，走在上面，嚓嚓作响。
北边是一望无际的大海，西南就是倭寇建的灯塔。
LONG
	);

	set("exits", ([
                "northeast" : __DIR__"haitan2",
                  "southwest" : __DIR__"duhaitan",
	]));

	set("outdoors", "diaoyudao");
	setup();
	replace_program(ROOM);
}

