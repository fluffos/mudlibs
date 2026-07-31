// Room: /d/quanzhou/jxnanmen.c
// Date: May 21, 96   Jay

inherit ROOM;

void create()
{
	set("short", "关哨卡口");
	set("long", @LONG
这里是一个关哨卡口。周围长着茂密的竹林。东面是座庙宇。
向南可入福建。
LONG );
	set("exits", ([
                "north" : __DIR__"jiaxing",
                //"east" : __DIR__"tieqiang",
		"south" : __DIR__"qzroad4",
		//"southeast": "/d/hangzhou/road1",
	]));
	
        set("objects", ([
            "/d/city/npc/bing" : 3
        ]));	
	set("no_clean_up", 0);
	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}

