// Room: /d/beijing/zijin/jiangxue.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"绛雪轩"NOR);
	set("long",
HIC"绛雪轩出厦三间，是座凸字形建筑。门窗装饰都用楠木雕刻，窗
棂雕有“万寿无疆”花纹，十分雅致古朴。门前砌有方形五色琉璃花
池，种有太平花，牡丹花等名贵花木。\n"NOR
	);
	set("exits", ([ /* sizeof() == 1 */
  	"west" : __DIR__"yuhuayuan",
]));

	setup();
	replace_program(ROOM);
}
