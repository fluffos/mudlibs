// Room: /d/beijing/zijin/wenyuange.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"文渊阁"NOR);
	set("long",
HIC"这是专为收藏《四库全书》而修建的一栋建筑，是紫禁城宫殿
中贮藏图书的主要地方。阁为三层楼房，仿宁波天一阁规制，楼上
通为一间，楼下分为六间，取“天一生水，地六承之”，意在防火。\n"NOR
	);
	set("exits", ([ /* sizeof() == 2 */
  	"south" : __DIR__"zhujingdian",
  	"north" : __DIR__"gzxd4",
]));

	setup();
	replace_program(ROOM);
}
