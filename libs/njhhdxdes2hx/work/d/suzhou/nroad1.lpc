//ROOM: d/suzhou/nroad1.c
// by dwolf
// 97.11.4

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", MAG"北大街"NOR);
	set("long", @LONG
	     这是一条宽阔的青石街道，向南北两头延伸。南边显得很繁忙。东边
是一座三层的楼阁，挂着“八仙醉酒”的招帘，门额上悬挂一方横匾，“八仙楼”
三字擦得闪闪发亮，乃是当年颜真卿的手笔。阵阵酒肉香酒香让你垂涎欲滴。西边是
一座香火很望的庙宇，里面香火缭绕，那就是天下人所共同敬仰的武穆祠了。路上是
成群结队去游览西湖的游人。
LONG
	);
	set("no_sleep_room",0);
	set("outdoors","suzhou"); 
	set("exits", ([
		"east" : __DIR__"whci",
		"north" : __DIR__"nroad2",
		"south" : __DIR__"shizx",
		"west" : __DIR__"bxlou",
]));                                   
	set("objects", ([
		__DIR__"npc/ren" : 1,
		__DIR__"npc/girl" : 2, 
]));
	
	setup();
}





