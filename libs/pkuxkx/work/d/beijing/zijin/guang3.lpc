// Room: /d/beijing/zijin/guang3.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"操场"NOR);
	set("long",
HIC"这是禁军操场，专门是为御林军操练用的。这里土地平整，
两旁的武器架上整整齐齐的堆满了擦得雪亮的兵器．每天早，中，
晚三刻，在操场上都是喊杀声不绝于耳。\n"NOR
	);
	set("exits", ([ /* sizeof() == 4 */
  	"south" : __DIR__"wuyingmen",
 	 "north" : __DIR__"wuyingdian",
 	 "west" : __DIR__"huanzhangdian",
  	"east" : __DIR__"ningdaodian",
]));

	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}
