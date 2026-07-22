//Cracked by Roath
// Room: /d/xiangyang/beijie2.c

inherit ROOM;

void create()
{
	set("short", "北街");
	set("long", @LONG
这是襄阳的北街，从北而来的人们大多向东而去。东面熙熙攘攘，远远看
来像是个集市，与这清净相成比较。西边是座小庙，香火味远远的飘了过来，
却是襄阳人祈求平安的敬香场所。
LONG
	);
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : 0, "y" : 4 ]) );
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"jzjie2",
  "south" : __DIR__"beijie1",
  "north" : __DIR__"beijie3",
  "west" : __DIR__"miao",
]));
	set("outdoors", "xiangyang");

	setup();
	replace_program(ROOM);
}
