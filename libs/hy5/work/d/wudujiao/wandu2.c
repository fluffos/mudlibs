// by mayue

inherit ROOM;
string* npcs = ({
	__DIR__"npc/wandu1",
	__DIR__"npc/wandu2",
	__DIR__"npc/wandu3",
	__DIR__"npc/wandu4",
	__DIR__"npc/wandu5",
});

void create()
{
	set("short", "万毒窟");
	set("long", @LONG
这里是一个天然形成的石洞，里面深邃广大。洞顶悬挂着许多
钟乳石，不时传来几声滴答的水声。走在洞中，洞内阴暗潮湿，身
旁忽然传来一阵“咝咝”的声音。洞内似乎还有个小一点的支洞。
LONG
	);
//      set("outdoors", "wudujiao");

	set("exits", ([
//		"eastup" : __DIR__"wdsl5",
              "south" : __DIR__"wandu3",
//		"westdown" : __DIR__"wdsl3",
		"north" : __DIR__"wandu1",
	]));
        set("objects", ([
	        npcs[random(sizeof(npcs))] : 1,
	]));
    

	setup();
	replace_program(ROOM);
}

