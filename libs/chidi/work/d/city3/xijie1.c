// Room: /chengdu/xijie1.c

inherit ROOM;

void create()
{
        set("short", "西大街");
	set("long", @LONG
这里是成都的西大街，熙熙攘攘，热闹非凡，两边是鳞立栉
比的店铺，五颜六色的幌子满街飘荡煞是鲜艳。附近的百姓一般
逢十就入城来赶集，许多商贾也不失时机的推出各种平时买不到
的东西。南边是家药铺，北面则是个占卜的铺子。
LONG
	);
        set("outdoors", "chengdu");

	set("exits", ([
                "east" : __DIR__"xijie2",
                "south" : __DIR__"cdyaopu",
                "west" : __DIR__"xijie",
                "north" : __DIR__"zhanbu",

	]));

	setup();
	replace_program(ROOM);
}

