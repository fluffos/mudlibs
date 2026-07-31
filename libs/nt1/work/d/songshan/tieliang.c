// Room: /d/songshan/tieliang.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
	set("short", "铁梁峡");
	set("long", @LONG
由此上山，山路越发险竣。铁梁峡右侧尽是怪石，而左边则为万
仞深谷，渺不见底。隔着峡谷，青冈峰环抱青冈坪，向上是主峰的山
路。
LONG );
	set("exits", ([
		"down"    : __DIR__"luyanpubu",
		"northup" : __DIR__"shandao5",
	]));
	set("objects", ([
		__DIR__"npc/lu" : 1,
	]));
//	set("no_clean_up", 0);
	set("outdoors", "songshan");
	setup();
	replace_program(ROOM);
}

