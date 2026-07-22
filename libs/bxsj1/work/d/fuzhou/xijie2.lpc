// Room: /d/fuzhou/xijie2.c
// Lklv 2001.9.7
inherit ROOM;

void create()
{
	set("short", "西街");
	set("long", @LONG
这里是福州的西大街，北面有一所破败的宅子。南面有一家杂货铺，专卖
一些女人家用的东西，很少有男人去那里。西南面可以看见一个大院套，一杆
大旗高高飘扬，那里是福威镖局的所在。
LONG
	);

	set("exits", ([
                "east" : __DIR__"xijie",
                "west" : __DIR__"ximen",
                "south" : __DIR__"xixiang3",
                "north" : __DIR__"xixiang2",
	]));

        set("objects", ([
                CLASS_D("gaibang/qigai") : 1,
        ]));
	set("outdoors", "福州");
	setup();
}
