// Room: /d/xueting/square_n.c

inherit ROOM;

void create()
{
	set("short", "广场北侧");
	set("long", @LONG
这里是雪亭镇广场北边，平常是附近孩童嬉戏游玩的地方，初
一、十五则是市集的所在，东边一所大宅院里有练武的吆喝声，往
南可以看见一株大榕树；往北则是一条笔直的街道。
LONG
	);
	set("objects", ([ /* sizeof() == 2 */
        __DIR__"npc/child" : 1,
//        __DIR__"npc/child2" : 1,
	]));
	
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"street02",
  "south" : __DIR__"guangchang",
  "west" : __DIR__"bank",
  "east" : __DIR__"school1",
]));
	set("no_clean_up", 0);
        set("outdoors", "xueting");
	setup();
	replace_program(ROOM);
}
