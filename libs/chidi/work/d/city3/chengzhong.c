// Room: /chengdu/chengzhong.c
// oooc: 1998/06/20 

inherit ROOM;

void create()
{
        set("short", "城中心");
	set("long", @LONG
这里是城市的正中心，一个很宽阔的广场，地上整齐地铺着
大青石地板。四周绿树成荫，街道东西南北纵横，路上行人不断。
来自五湖四海，三教九流的人士群集于此，更是富豪商贩们的黄
金地带。更有一些游手好闲的人在这里溜溜达达。
LONG
	);
        set("no_sleep_room",1);

	set("exits", ([
                "east" : __DIR__"dongjie2",
                "south" : __DIR__"nanjie2",
                "west" : __DIR__"xijie2",
                "north" : __DIR__"beijie2",
	]));

	set("objects", ([
                __DIR__"npc/xiaohai" : 1,
                __DIR__"npc/liumang" : 1,
                __DIR__"npc/yiren" : 1,
	]));

	setup();
}

