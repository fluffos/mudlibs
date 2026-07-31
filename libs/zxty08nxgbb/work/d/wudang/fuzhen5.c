// Room: /d/wudang/fuzhen5.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "复真观五层");
	set("long", @LONG
这里是复真观五层，靠墙是一排书架，摆满了道教的典籍，和一些武
功秘籍。这里是武当重地，武当弟子才能入内。
LONG
);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"obj/daodejing" : 1,
]));
	set("exits", ([ /* sizeof() == 1 */
  "southdown" : __DIR__"fuzhen4",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
