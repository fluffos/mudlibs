// Room: /d/beijing/zijin/ningshoumen.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"宁寿门"NOR);
	set("long",
HIC"你面前是一道影壁(wall)，影壁后就是宁寿宫宫门了。宁寿
宫仿大内中轴线，前三殿，后三宫的体制，是紫禁城中最气魄雄
伟的宫殿。\n"NOR
	);
	set("exits", ([ /* sizeof() == 3 */
 	 "west" : __DIR__"guang4",
 	 "north" : __DIR__"huangjidian",
  	"northwest" : __DIR__"gzxd5",
]));
	set("item_desc", ([ /* sizeof() == 1 */
  "wall" : "“九龙壁”上面雕刻着九条盘旋飞舞的巨龙。\n",
]));
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}
