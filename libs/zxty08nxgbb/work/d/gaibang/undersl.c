// Room: /d/gaibang/undersl.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "屋角边");
	set("long", @LONG
这是老乔家厨房大木柴堆下面。里面破破烂烂的，丢满了各种杂
物，还有丐帮弟子收集的破铜烂铁等。从这里通往丐帮的秘密通道。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "up" : "/d/nanyang/chufang2",
  "southwest" : __DIR__"slandao2",
]));
	set("objects", ([ /* sizeof() == 1 */
  "/kungfu/class/gaibang/he-bj" : 1,
]));
	setup();
	replace_program(ROOM);
}
