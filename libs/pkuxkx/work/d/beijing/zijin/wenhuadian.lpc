// Room: /d/beijing/zijin/wenhuadian.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"文华殿"NOR);
	set("long",
HIC"这是是皇太子活动的东宫，这里常举行一些经筵，即按一定日期,皇
帝和大臣们一起讲儒家经典,然后赐茶,赐宴.对面一片较矮的房子是内阁。\n"NOR
	);
	set("exits", ([ /* sizeof() == 4 */
  	"north" : __DIR__"zhujingdian",
  	"south" : __DIR__"wenhuamen",
  	"west" : __DIR__"neige",
  	"east" : __DIR__"chuanxindian",
]));

	setup();
	replace_program(ROOM);
}
