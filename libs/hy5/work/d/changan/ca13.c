// Room: /d/changan/ca13.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "长安城大街");
	set("long", @LONG
不愧为有“秦川三百里”之称的长安城，到处都是热闹非凡。这
里往西是一座碑林，南面就是大小雁塔的所在了。
LONG
);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"ca16",
  "north" : __DIR__"ca12",
  "south" : __DIR__"ca34",
]));
	set("outdoors", "changan");

	setup();
	replace_program(ROOM);
}
