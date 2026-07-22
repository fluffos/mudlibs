// Write By Yanyang@SJ 2001.10.2
// Room: /d/changan/jiuguan.c

inherit ROOM;

void create()
{
        set("short", "酒馆");
        set("long", @LONG
这是长安城居民区里的一家小酒馆。屋子并不是很宽敞，但酒水是长安城
里最廉价的，正适合居民区里的普通百姓，生意很是不错。老板原也是城中的
居民，今天不知与何人喝得酩酊大醉，连买卖也不管了。
LONG
        );

        set("exits", ([
                "north" : __DIR__"neijie1",
        ]));
        
        set("objects", ([
                __DIR__"npc/jglaoban" : 1,
        ]));
        
        set("incity",1);
	setup();
}