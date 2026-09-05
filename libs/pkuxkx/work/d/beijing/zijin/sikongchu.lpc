// Room: /d/beijing/zijin/sikongchu.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"祀孔处"NOR);
	set("long",
HIC"一进此屋，只见香烟镣绕，正对着门影影约约有一座神象，
头顶儒士巾，神采飘逸，正是大圣人孔子。此处为皇帝向至圣先
师拜祀之地，也是天下读书人的圣地。\n"NOR
	);
	set("exits", ([ /* sizeof() == 2 */
  	"west" : __DIR__"shangshufang",
  	"north" : __DIR__"yuyaofang",
]));

	setup();
	replace_program(ROOM);
}
