// Room: /d/fengtian/book.c

inherit ROOM;

void create()
{
	set("short", "书店");
	set("long", @LONG
书店老板是一个胖胖的家伙，为人精明能干，把小书店经营
的蒸蒸日上，而且这家伙还喜欢以文会友，所以不少书生经常光
顾这家小书店，不过最近书店老板好象有点小麻烦。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"kd3",
]));

	set("objects",([
	__DIR__"npc/book_boss" : 1,
]));

	setup();
	replace_program(ROOM);
}
