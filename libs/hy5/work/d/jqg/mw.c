// Room: /u/dubei/u/gumu/jqg/mw
// by dubei
#include <ansi.h>; 
inherit ROOM;

void create()
{
	set("short", HIY"茅屋"NOR);
	set("long", @LONG
只见屋中陈设简陋，但洁净异常，堂上只一桌一几，此
外便无别物，与古墓石室中的桌椅一模一样。
LONG
	);
        set("exits", ([
                "out" : __DIR__"gd2",
        ]));
	set("objects", ([
		//__DIR__"npc/yangguo" : 1,
	        //__DIR__"npc/xln" : 1,
	]));
        setup();
       replace_program(ROOM);
}
 