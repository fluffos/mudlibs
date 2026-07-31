// Room: qianzhuang.c
// congw 980830
inherit ROOM;

void create()
{
	set("short", "荆州钱庄");
	set("long", @LONG
这是一家老字号的钱庄，已有几百年的历史，在全国各地都有分店。它发行的银票
信誉非常好，通行全国。
LONG
	);

	set("exits", ([
		"east" : __DIR__"beidajie1",
	]));
set("no_fight",1);
	set("objects", ([
		__DIR__"npc/qian" : 1
	]));

	setup();
	replace_program(ROOM);
}

