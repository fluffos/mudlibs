
// Room: /d/snow/droad0.c


inherit ROOM;

void create()
{
        set("coor",({0,5000,10}));
	set("short", "山路");
	set("long",
"这是一条杂草从生的小路，已多年没有人从这里走过，路旁树上栖息着几只乌鸦，不时传来\n"
"凄惨又令人毛骨竦然的叫声，向前望去隐约可见一座高山。\n"
);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"happyinn1",
   "north" : __DIR__"bingying2",
  "westup": __DIR__"droad1",
]));
        set("no_npc",1);
	set("outdoors", "ny");
	setup();
//        replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
	if ( !me->query("jinyong/book2") && 
		dir == "north")
		return notify_fail("一队清兵拦住了你的去路。\n");
	return ::valid_leave(me, dir);
}      