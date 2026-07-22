// Room: /u/mei/zhaoze/room15.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "茅屋");
	set("long", @LONG
这是间低矮的茅屋，四壁挂满了野兽的头颅和各种鸟类的羽毛。
只有茅屋中央点着一堆篝火，使整个屋子显得阴森恐怖。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"room14",
]));
        set("objects", ([ 
        __DIR__"npc/fonghuang" : 1,
]));

	set("channel_id", "茅屋");

	setup();
	replace_program(ROOM);
}
