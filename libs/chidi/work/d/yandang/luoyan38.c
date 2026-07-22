// Room: /d/yandang/luoyan38.c

inherit ROOM;

void create()
{
	set("short", "喷泉");
	set("long", @LONG
从后园的门坎跨出来,你会以为自己走错了地方,只见一片空旷的地
上,用太湖石修起了一个小水潭,潭中有一道水泉从中喷出数丈高,随之洒
落下来,发出唰唰的声音,向西是庄主的居室.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/yandang");
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"luoyan12.c",
  "northwest" : __DIR__"luoyan39",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/teiqiaos.c" : 1,
]));

	setup();
	replace_program(ROOM);
}
