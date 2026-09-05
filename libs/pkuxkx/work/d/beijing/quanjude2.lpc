// Room: /d/beijing/west/quanjude2.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"雅座"NOR);
	set("long",
CYN"这里是全聚德烤鸭店二楼雅座，在这里的客人多是达官贵人或是
有钱有闲的八旗公子哥儿，气氛也和楼下一片喧哗大不一样。客人们
大多浅斟慢饮，店伙计也一脸笑容，服侍周到。\n"NOR
	);
	set("exits", ([ /* sizeof() == 1 */
  	"down" : __DIR__"quanjude",
]));

	set("objects", ([ /* sizeof() == 1 */
///////////////////////神龙教尚未完善，没有高级master，且有bug，暂时封掉入口
//           CLASS_D("shenlong/shou") : 1,
	  __DIR__"npc/wuliuqi" : 1,
]));

	setup();
	replace_program(ROOM);
}
