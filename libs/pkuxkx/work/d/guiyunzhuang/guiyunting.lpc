// guiyunzhuang/guiyunting.c 归云亭
//Made By:pingpang
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIC"归云亭"NOR);
     set("long", "这是一座竹枝搭成的凉亭，它坐落在风景如画的"RED"太湖边上"NOR"。亭中放着竹台竹椅，全是多年之物，用得润了，月光
下现出淡淡黄色。竹亭之侧并肩生着两棵大松树，枝干虬盘，只怕已是数百年的古树。苍
松翠竹，清幽无比。\n");
set("exits",([/* sizeof() ==2 */
	"southdown" : __DIR__"shijie1",
        "east" : __DIR__"zoulang1",
     "west" : __DIR__"milin1",
	]));
	set("objects",([
               CLASS_D("taohua") + "/lu" : 1,
		__DIR__"npc/wangde":1,
		__DIR__"npc/chensan":1,
	]));

	set("valid_startroom",1);
        set("outdoors","guiyunzhuang");
	setup();
// replace_program(ROOM);
 "/clone/board/gy_b"->foo();
}
