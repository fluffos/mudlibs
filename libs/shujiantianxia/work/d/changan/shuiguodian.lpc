// Write By Yanyang@SJ 2001.9.27
// Room: /d/changan/shuiguodian.c

inherit ROOM;

void create()
{
        set("short", "水果店");
        set("long", @LONG
这是长安城里唯一的一家水果店。店里面摆满了一排排的竹筐，筐里有各
式各样的水果。这儿的水果为了保持新鲜，都是每天清晨从城外的果园用快车
运来的。水果店的女店主胖嫂正热情的招呼着客人。
LONG
        );

        set("exits", ([
                "south"   : __DIR__"eastjie3",
        ]));
        set("objects", ([
                __DIR__"npc/pangsao" : 1,
        ]));
        set("incity",1);
	setup();
}
