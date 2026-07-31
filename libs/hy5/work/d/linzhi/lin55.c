// Room: /d/linzhi/lin55.c

inherit ROOM;

void create()
{
	set("short", "娘浦");
	set("long", @LONG
这里是娘浦，由此一直向南是一片古柏林，西边不远就是帕
嘎寺，而向北行则是列山古墓群了，向东方向走可以到八一镇。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"lin54",
  "northwest" : __DIR__"lin64",
  "southwest" : __DIR__"lin62",
  "southeast" : __DIR__"lin56",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 4200);
	setup();
	replace_program(ROOM);
}
