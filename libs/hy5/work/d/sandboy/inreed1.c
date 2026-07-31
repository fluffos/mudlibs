// Room: /d/sandboy/inreed1.c

inherit ROOM;

void create()
{
	set("short", "芦苇荡中");
	set("long", @LONG
天上白云飘过,头顶雪白的芦花随风飘散,脚下是松软的淤泥,几株芦苇
倒了下来,搭在一起,筑成了一个窝.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"inreed",
]));
	set("outdoors", "/d/jiangnan");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/dayan.c" : 1,
]));

	setup();
	replace_program(ROOM);
}
