// Room: /d/beijing/zijin/duanningdian.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"端凝殿"NOR);
	set("long",
HIC"这是存放皇帝的冠，袍，带，履的地方。房间里放满了各种大小
、不同颜色的柜子。柜门上写着一个个标签。地上已经积了一层厚厚
的的灰尘，显然很久没人来过了。\n"NOR
	);
	set("exits", ([ /* sizeof() == 2 */
  	"south" : __DIR__"rijingmen",
  	"north" : __DIR__"yuchafang",
]));

	setup();
	replace_program(ROOM);
}
