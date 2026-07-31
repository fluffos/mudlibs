// Room: /u/dubei/u/gumu/jqg/qlf
// by dubei
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "独峰岭");
	set("long", @LONG
这里两边山峰壁立，抬头望天，只余一线。山青水碧，景
色极尽清幽，只是四下寂无声息，隐隐透著凶险，溪心有九块
大石迎面耸立，犹如屏风一般，挡住了去路。
LONG
	);

	set("exits", ([
		"northeast" : __DIR__"glt",
                "southdown" : "/d/sdxl/conglin1",
	]));

           set("outdoors", "xiangyang");
	setup();
	replace_program(ROOM);
}

