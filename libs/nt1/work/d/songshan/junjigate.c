// Room: /d/songshan/junjigate.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
	set("short", "峻极禅院山门");
	set("long", @LONG
嵩山绝顶，古称 "峻极" 。这里是本是佛教大寺，但百年来
却已成为嵩山派掌门人的住所。西上可以到达封禅台。
LONG );
	set("exits", ([
		"southdown" : __DIR__"shandao6",
		"northup"   : __DIR__"chanyuan",
		"westup"    : __DIR__"fengchantai",
	]));
	set("objects", ([
		__DIR__"npc/tang" : 1,
		__DIR__"npc/wan" : 1,
	]));
//	set("outdoors", "songshan");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

