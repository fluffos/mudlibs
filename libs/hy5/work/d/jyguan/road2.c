// road2.c 官道
// west to jiayuguan,est to lanzhou
// Ver 0.1 08/14/1998 by Freeze

inherit ROOM;

void create()
{
	set("short", "官 道");
	set("long", @LONG
这是一条宽阔的大路，不时地有商队从你的身边走过。这便是丝绸之路，各国商
人大多由此进入九州，是重要的通商渠道。
    此路连接嘉峪关和兰州。
LONG
	);	
        set("outdoors", "jyguan");

	set("exits", ([
		"southeast" : __DIR__"road1",
		"southwest" : __DIR__"road3",
//		"eastup" : "d/xingxiu/xxroad3",
	]));
	
//	set("objects", ([
//		__DIR__"npc/guest" : 1]));
		
	setup();
	replace_program(ROOM);
}

