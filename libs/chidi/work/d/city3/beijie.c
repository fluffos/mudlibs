// Room: /chengdu/beijie.c
// oooc: 1998/06/20 

inherit ROOM;

void create()
{
        set("short", "北大街");
	set("long", @LONG
这条街上双人合抱的梧桐十步一株，整整齐齐，青石铺就的
路面打扫得干干净净。东边是个珠宝铺，西边则是闻名天下的武
侯祠。
LONG
	);
        set("outdoors", "chengdu");

	set("exits", ([
                "south" : __DIR__"beijie1",
                "east" : __DIR__"zhubaopu",
                "west" : __DIR__"wuchi",
                "north" : __DIR__"northchengmen",

	]));
        set("objects", ([
            "/d/huashan/npc/haoke" : 1,
        ]));

	setup();
	replace_program(ROOM);
}

