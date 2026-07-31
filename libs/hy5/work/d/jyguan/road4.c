// road4.c 官道
// west to jiayuguan,est to lanzhou
// Ver 0.1 08/14/1998 by Freeze

inherit ROOM;

void create()
{
	set("short", "官 道");
	set("long", @LONG
这是一条宽阔的大路，商队往来。这便是丝绸之路，各国商
人大多由此进入九州，是重要的通商渠道。
    由此地望西看去，风沙中隐现着城楼屋宇。一群民工在
几个军汉的监看下往西北搬运砖石，不时传来打骂声，经年
累月的徭役已使这里的百姓苦不堪言。
LONG
	);	
        set("outdoors", "jyguan");


	set("exits", ([
		"west" : __DIR__"road5",
		"southeast" : __DIR__"road3",
                "northwest" : __DIR__"wall",
	]));
	
//	set("objects", ([
//		__DIR__"npc/guest" : 1]));
		
	setup();
	replace_program(ROOM);
}

