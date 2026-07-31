// Room: /d/fengtian/wy6.c

inherit ROOM;

void create()
{
	set("short", "威远路");
	set("long", @LONG
威远路的东口，远远的已经可以看见大金国皇帝府了，所以
这里也比较肃静，路北有一家很有名的打铁铺，这里可以打造玄
铁兵器，向南就拐到李林街上了。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"ll1",
  "west" : __DIR__"wy5",
  "east" : __DIR__"jjf1",
  "north" : __DIR__"smith",
]));
        set("outdoors", "fengtian");
	setup();
	replace_program(ROOM);
}
