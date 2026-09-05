// Room: /d/quanzhou/jxnanmen.c
// Date: May 21, 96   Jay

inherit ROOM;

void create()
{
	set("short", "嘉兴南门");
	set("long", @LONG
这里是嘉兴的南门。周围长着茂密的竹林。东面是座庙宇。
向南可入福建。
LONG
	);

	set("exits", ([
                "north" : __DIR__"jiaxing",
                "east" : __DIR__"tieqiang",
		"south" : "/d/quanzhou2/qzroad4",
	     "southwest" : __DIR__"xiaojing",
	]));

        set("objects", ([
                __DIR__"npc/kezhene": 1]));
	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}

