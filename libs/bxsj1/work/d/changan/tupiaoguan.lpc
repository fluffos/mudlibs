// Write By Yanyang@SJ 2001.10.2
// Room: /d/changan/tupiaoguan.c

inherit ROOM;

void create()
{
        set("short", "土嫖馆");
        set("long", @LONG
这是一间简陋的，用泥坯砌起来的低矮小房。东面的墙上有条裂缝，从右
上角一直裂到左边的墙角里。西边有一张和泥屋连为一体的土炕。炕头挂着厚
布蚊帐，炕上的被褥脏兮兮的，而且散发着难闻的气味。
LONG
        );

        set("exits", ([
                "north" : __DIR__"neijie3",
        ]));
        
        set("objects", ([
                __DIR__"npc/tuchang" : 1,
        ]));
        
        set("incity",1);
	setup();
}