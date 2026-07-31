// wall.c 长城
// Ver 0.1 08/14/1998 by Freeze

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIG "长 城 脚 下");
	set("long", @LONG
这就是帝王为了稳坐江山抵御外敌，不惜劳民伤财，役使无数百姓，历经数代王朝
方筑成的长城。不知这里埋葬了多少悲伤的故事、多少百姓的尸骨...
    军汉们正役使着衣裳褴褛的民工修补长城，民工们看上去非常劳累，但稍许怠慢便
被军汉鞭笞...
LONG
	);
        set("outdoors", "jyguan");
	

	set("exits", ([
		"southeast" : __DIR__"road4",
		"east" : __DIR__"luzhou1",
		"northeast" : "/d/changcheng/changcheng21",
	]));
	
		
	setup();
	replace_program(ROOM);
}

