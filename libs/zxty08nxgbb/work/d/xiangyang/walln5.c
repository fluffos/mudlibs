// Room: /d/xiangyang/walln5.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "石阶");
	set("long", @LONG
这是登向城头的石阶，因为城墙很高，所以很陡。石阶两
侧有可供拉车上下的斜坡道。
LONG );
        set("outdoors", "xiangyang");
	set("no_clean_up", 0);

	set("exits", ([
		"eastup"   : __DIR__"walln7",
		"westdown" : __DIR__"walln3",
	]));
	setup();
}
int valid_leave(object me, string dir)
{
	int c_exp,c_skill;
	me = this_player();
	if (dir == "eastup" )
	{
		c_exp=me->query("combat_exp");
		c_skill=me->query_skill("dodge",1);
		me->receive_damage("qi",10);
		if (((c_skill*c_skill*c_skill/10)< c_exp) && (c_skill<101))
		me->improve_skill("dodge", (int)me->query_skill("dodge", 1));
	}
	return 1;
}


