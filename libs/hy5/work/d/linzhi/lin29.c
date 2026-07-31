// Room: /d/linzhi/lin29.c

inherit ROOM;

void create()
{
	set("short", "高原曲坡");
	set("long", @LONG
这里是高原曲坡，山道曲折弯向前方。一座座山峰起伏在你
左右，秃鹰在天空翱翔。你打起精神，奋步向前。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"lin10",
  "southwest" : __DIR__"lin30",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 2600);
	setup();
	replace_program(ROOM);
}
