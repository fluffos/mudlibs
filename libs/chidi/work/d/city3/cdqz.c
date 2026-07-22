// Room: /chengdu/cdqz.c
// oooc: 1998/06/25 

inherit ROOM;

void create()
{
	set("short", "钱庄");
	set("long", @LONG
这是一家老字号的钱庄，已有几百年的历史，在全国各地都
有分店。它发行的银票信誉非常好，通行全国。听说这里的钱老
板跟府衙有很深的渊源，流氓土匪一般都不来这找麻烦。所以这
里生意一直很好。
LONG
	);

	set("exits", ([
                "south" : __DIR__"xijie1",
	]));

	set("objects", ([
                __DIR__"npc/qian1" : 1
	]));

	setup();
	replace_program(ROOM);
}

