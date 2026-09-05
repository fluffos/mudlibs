// Room: /d/beijing/zijin/jiaotaidian.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"交泰殿"NOR);
	set("long",
HIC"    大殿重檐歇山顶，四周推出单檐卷棚抱厦，黄瓦绿剪边，下檐翘角，造
型优美。殿内井口柱，抹角梁，画栋雕梁。殿的东侧还摆有计时器洞壶滴漏
和楼阁型自鸣钟。\n"NOR
	);
	set("exits", ([ /* sizeof() == 4 */
  	"west" : __DIR__"longfumen",
  	"north" : __DIR__"kunninggong",
  	"south" : __DIR__"qianqinggong",
  	"east" : __DIR__"jinghemen",
]));

	setup();
	replace_program(ROOM);
}
