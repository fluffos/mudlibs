// Room: /d/putian/road05.c
// Lklv 2001.9.11

inherit ROOM;
#include <wanted.h>
void create()
{
        set("short", "山路");
        set("long", @LONG
山路逐渐开始变窄，并且开始蜿蜒上山了。远处的山丘全部被树木覆盖，绿得
望不到边。偶尔传来鸟儿在枝头间轻快的叫声。
LONG
        );

        set("exits", ([
                "southwest" : __DIR__"road04",
                "eastup" : __DIR__"road06",
        ]));

	set("objects",([
		NPC_D("tiao-fu") : 1,
	]));

        set("outdoors", "福州");
        setup();
}

int valid_leave(object me, string dir)
{
        if (dir == "eastup" && is_wanted(me))
        	return 0;
	return ::valid_leave(me, dir);
}
