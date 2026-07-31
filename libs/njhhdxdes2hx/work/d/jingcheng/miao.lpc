#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", GRN"龙王庙"NOR);
	set("long", @LONG
这是长安城东北角的一座小庙，用来供奉龙王用的。古话说得好，
“临时抱佛脚”，所以当风调雨顺的时候，这里一般总是冷冷清清
的。不过求雨时还是很灵的。
LONG         
	);

      	set("objects", ([ 
        __DIR__"npc/farmer" : 1,
      ]));

	set("exits", ([ 
 "west" :__DIR__"baih2", 
 
	]));
	setup();
	replace_program(ROOM);
}

