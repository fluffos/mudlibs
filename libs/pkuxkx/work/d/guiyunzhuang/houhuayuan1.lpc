// houhuayuan1.c 后花园
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "后花园");
        set("long","这里是归云庄的后花园，种满了花草，几个庄仆正在浇花。"
        "此地乃是"GRN"含羞草"NOR"生长的地方，给人一种心旷神怡的感觉。\n");
        set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"houhuayuan",
 ]));
        set("objects", ([/* sizeof() == 2*/
		__DIR__"npc/amu":1,
                __DIR__"npc/zhuangpu" : 2,
        ]));

	
	setup();
        replace_program(ROOM);
}
