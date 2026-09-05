// Room: /d/beijing/zijin/jianting.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"箭亭"NOR);
	set("long",
HIC"整个建筑没有一扇窗户,南北向共有三十二扇隔扇门,周围是空
旷的广场,便于练习可跑马射箭.清代武士殿试,皇帝在此阅技勇。亭
内东西各陈放着各朝皇帝圣训石碑,训喻子孙居安思危,务忘骑射。\n"NOR
	);
	set("exits", ([ /* sizeof() == 3 */
  	"north" : __DIR__"guang4",
  	"south" : __DIR__"gzxd3",
  	"east" : __DIR__"yuchashanfang",
]));

	setup();
	replace_program(ROOM);
}
