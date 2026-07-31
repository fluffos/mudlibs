// Room: /d/taiwan/undertree.c

inherit ROOM;

void create()
{
	set("short", "大榕树下");
	set("long", @LONG
渔村中的一个空场,中间直立一棵高大的榕树,枝条如鱼丝般垂下来, 
斑驳的树根从地上冒出来,几个小孩正围着个白须飘飘的老者,听他在讲 
着些什么. 
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"road2",
  "southwest" : __DIR__"tree1",
]));
	set("outdoors", "/d/taiwan");
	set("objects", ([ /* sizeof() == 3 */
  __DIR__"npc/laoren.c" : 1,
  __DIR__"npc/kid1.c" : 1,
  __DIR__"npc/kid2.c" : 1,
]));

	setup();
	replace_program(ROOM);
}
