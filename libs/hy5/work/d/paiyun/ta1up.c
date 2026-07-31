// Room: /d/paiyun/ta1.c

inherit ROOM;

void create()
{
	set("short", "哨塔");
	set("long", @LONG
爬上哨塔的二层视线豁然开朗，树木群山层峦叠嶂，极目远
眺大“有一览群山小的意境”。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"ta1",
]));

	set("objects", ([
		__DIR__"npc/d_guard" : 3,
	]));
	set("outdoors", "paiyun");
	setup();
	replace_program(ROOM);
}
