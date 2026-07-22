//Yanqi 08/10/2k

#include <room.h>

inherit ROOM;

void create()
{
        set("short", "采石场");
        set("long", @LONG
这里是一个采石场，最近由于官府在此大修水利，需要大量的石头这里的
也越发兴隆起来。里面不时传来阵阵的爆炸声，只见一块块巨石不断地从山上
滚落下来。
LONG );
        set("exits", ([
                "northup" : __DIR__"hhgate",
        ]));

        set("objects",([
                __DIR__"npc/li" : 1,
        ]));

        set("no_get_from", 1);
	set("no_fight",1);
	set("no_sleep_room",1);
	
        set("outdoors", "黄河");
        setup();
}
