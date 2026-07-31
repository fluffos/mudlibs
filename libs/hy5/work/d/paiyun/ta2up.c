// Room: /d/paiyun/ta2.c

inherit ROOM;

void create()
{
	set("short", "哨塔");
	set("long", @LONG
爬上哨塔的二层视线豁然开朗，树木群山层峦叠嶂，极目远
眺大“有一览群山小的意境”。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"ta2",
]));
	set("outdoors", "paiyun");
	setup();
	replace_program(ROOM);
}
