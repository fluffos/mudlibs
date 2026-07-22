// Write By Yanyang@SJ 2001.10.2
// Room: /d/changan/shiji.c

inherit ROOM;

void create()
{
        set("short", "市集");
        set("long", @LONG
走到内街的尽头，是一个热闹非凡的市集，里面叫卖声、砍价声、说笑声
乱做一团。市集里面人挤人，地上扔满了烂菜叶等脏物，根本无从下脚。有两
名巡捕在市集里面仔细的巡视，防止有人在这里贩卖私盐。
LONG
        );
        set("outdoors", "长安");

        set("exits", ([
                "east"  : __DIR__"neijie1",
                "south" : __DIR__"minju2",
                "west"  : __DIR__"heishi",
                "north" : __DIR__"minju1",
        ]));

        set("objects", ([
                __DIR__"npc/xunbu" : 2,
        ]));

        set("incity",1);
	setup();
}

