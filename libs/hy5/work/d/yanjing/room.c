// Room: /d/yanjing/room.c

inherit ROOM;

void create()
{
	set("short", "大屋子");
	set("long", @LONG
高高的屋顶,粗大的柱子,南北两边是直通的两扇巨门.看来没五六
个人别想推动.墙壁上插了两枝牛油火把,光线忽明忽暗,一阵阵的黑烟
从火把上冒出来,把附近的墙壁熏黑了一大块.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/kanshou.c" : 2,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"gardon2",
  "north" : __DIR__"tianjing1",
]));

	setup();
}

int valid_leave(object me,string dir)
{
	object npc;

	npc=present("kan shou",this_object());
	if(dir=="north" && objectp(npc) && living(npc))
	return notify_fail("看守冲你一瞪眼怒道：他姥姥的，干什么你干！\n");
	return ::valid_leave(me,dir);
}

