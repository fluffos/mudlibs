// Room: /chengdu/nanjie2.c
// oooc: 1998/06/20 

inherit ROOM;

void create()
{
        set("short", "南大街");
	set("long", @LONG
这里是成都的南大街，双人合抱的梧桐在街边十步一株，
青石铺就的路面打扫得干干净净。因为这里大都进出的是官
府的人，又是王府必经之路，所以不许闲杂人等无事逗留的。
东边是成都大衙，西边是个全城有名的说书场。
LONG
	);
        set("outdoors", "chengdu");

	set("exits", ([
                "south" : __DIR__"nanjie",
                "north" : __DIR__"nanjie1",
                "east" : __DIR__"cdym",
                "west" : __DIR__"cdshuchang",

	]));

	setup();
	replace_program(ROOM);
}

