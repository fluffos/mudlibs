// Write By Yanyang@SJ 2001.9.20
// Room: /d/changan/eastjie2.c

inherit ROOM;

void create()
{
        set("short", "东大街");
        set("long", @LONG
这是一条宽阔的青石街道，向东西两头延伸。东边是东城门通向城外。西
边则是城中心的钟楼。南边是一家门面很大的澡塘，牌匾上书“清池”二字。
北边熙熙攘攘的则是一家茶馆，里面不时传出叫好之声。
LONG
        );
        set("outdoors", "长安");

        set("exits", ([
                "east"   : __DIR__"eastjie3",
                "south"  : __DIR__"qingchi",
                "west"   : __DIR__"eastjie1",
                "north"  : __DIR__"chaguan",
        ]));

        set("incity",1);
	setup();
}