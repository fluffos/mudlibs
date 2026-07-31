// Room: /d/linzhi/lin42.c
// Room: /d/linzhi/lin41.c

inherit ROOM;

void create()
{
	set("short", "高原回路果林");
	set("long", @LONG
这里是藏区唯一的一片苹果林区。这里产的苹果十分有名，
红中带青，入口甘甜。每年九月份时，不少藏民都带着家伙来这
里采摘苹果。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"lin41",
  "south" : __DIR__"lin45",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 4000);
	setup();
	replace_program(ROOM);
}


