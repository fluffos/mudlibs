// Room: /u/ibm/qq.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
        set("short", "雷神之锤讨论室");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
);
	set("exits", ([ /* sizeof() == 1 */
  "northeast" : "/d/city/guangchang",
]));

	setup();
        "/d/board/qq_b"->foo();
}
