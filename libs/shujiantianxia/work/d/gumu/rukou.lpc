// Room: /u/xdd/gumu/rukou.c
// Modify by river 98/08/29
#include <ansi.h> 
inherit ROOM;

void create()
{
	set("short", HIY"古墓"NOR);
	set("long", @LONG
你顿了顿神，发现自己已身处深谷之中，雾气蒙蒙，寒意逼人。四下是片
不小的开阔地，一座一人高的白色球型圆冢孤立其中，墓后是阴森森的松林古
木，更平添十分凄清落寞的萧瑟之意。墓门仅齐肩高，往内是古墓派所在。古
墓传人历来不轻出江湖，但不少痴情男女仰慕杨龙二人双剑合壁快意江湖的豪
情，历尽千般磨难后终成眷属惊世恋情。不远千里往来投拜。
LONG        );

	set("outdoors","古墓");

	set("exits", ([
		"enter" : __DIR__"gmqt",
		"south" : __DIR__"xuanya",
		"north" : __DIR__"guoyuan",
	]));

	setup();
	"/clone/board/gumu_b"->foo();
} 
