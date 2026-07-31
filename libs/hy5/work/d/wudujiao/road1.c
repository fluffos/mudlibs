// by mayue

inherit ROOM;

void create()
{
	set("short", "黄土大道");
	set("long", @LONG
这是一条向南的黄土大道，两旁是一片片绿油油的水田
和悠闲的牧童。大道上人流熙熙攘攘，过往的行人顶着炎炎烈
日满头大汗的匆匆赶路，似乎并无心欣赏这优美的田园风光。
LONG
	);
        set("outdoors", "wudujiao");

	set("exits", ([
//		"east" : __DIR__"zuixianlou",
		"south" : __DIR__"road2",
//		"west" : __DIR__"wumiao",
		"north" : "/d/fuzhou/xichansi",
	]));
        set("objects", ([
//                "/d/npc/guojing": 1,
	]));

	setup();
	replace_program(ROOM);
}

