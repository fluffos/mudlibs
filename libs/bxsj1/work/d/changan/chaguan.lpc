// Write By Yanyang@SJ 2001.9.26
// Room: /d/changan/chaguan.c

inherit ROOM;

void create()
{
        set("short", "茶馆");
        set("long", @LONG
这间茶馆是长安的闲人杂聚的场所，里面横七竖八的摆放着一些木制的桌
椅。一个说书人正滔滔不绝的讲书。一些茶客一边品茶，一边听书，一边交头
接耳小声议论着什么。
LONG
        );
        set("resource/water", 1);

        set("exits", ([
                "south" : __DIR__"eastjie2",
        ]));

        set("objects", ([
                __DIR__"npc/chgxiaoer" : 1,
                __DIR__"npc/shshren" : 1,
        ]));

        set("incity",1);
	setup();
}
