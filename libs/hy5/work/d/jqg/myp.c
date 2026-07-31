// Room: /u/dubei/u/gumu/jqg/myp
// by dubei
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "梅雨瀑");
	set("long", @LONG
这道瀑布从危崖峭壁顶上悬挂直下，出瀑口不远遇一横突岩
石，激石飞溅，化作毛毛细雨，类似五、六月梅雨，故名梅雨瀑。
LONG
	);

	set("exits", ([
                "west" : __DIR__"glt", 
	]));

   set("outdoors", "襄阳");
	setup();
	replace_program(ROOM);
}

