// Room: /d/taishan/beitian.c

inherit ROOM;

void create()
{
	set("short", "北天门");
	set("long", @LONG
这里位于石马山的北麓，是岱顶的北面出口，路口有一石坊，
上面写着「玄武」二字。
LONG
	);
	set("outdoors", "taishan");
	set("exits", ([ /* sizeof() == 1 */
  "southdown" : __DIR__"zhangren",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
