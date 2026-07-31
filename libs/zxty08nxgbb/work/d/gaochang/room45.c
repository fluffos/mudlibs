// Room: /u/mei/room45.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "湖边");
	set("long", @LONG
草原西端一座高山参天而起，耸入云霄，从山腰起全是皑皑白雪，山腰以下
却生满苍翠树木。一时口呆目瞪，心摇神驰。只听树上小鸟鸣啾，湖中冰块撞击，
与瀑布声交织成一片乐音。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"room46",
  "east" : __DIR__"room44",
]));
	set("no_new_clean_up", 0);
	set("outdoors", "room45");

	setup();
	replace_program(ROOM);
}
