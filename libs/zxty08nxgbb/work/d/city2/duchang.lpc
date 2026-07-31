// Room: /d/city2/duchang.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "赌场");
	set("long", @LONG
这里是赌场的大堂，四周的房间里传出来吆五喝六的赌博声。
北边是赌「大小」的房间，墙上挂着一块牌子(paizi)。楼上可以
拱猪. 一进门，只见房中人声嘈杂，十分混乱。有一桌围着一群人，
其中一胖一瘦两个头陀十分惹眼。一个老叫化正和他们赌得起劲。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/wuliuqi" : 1,
]));
	set("no_new_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"xidan1",
  "up" : __DIR__"duchang2",
]));
	set("item_desc", ([ /* sizeof() == 1 */
  "paizi" : "二楼的拱猪房可以使用，为什么没人来呢?
",
]));
	setup();
	replace_program(ROOM);
}
