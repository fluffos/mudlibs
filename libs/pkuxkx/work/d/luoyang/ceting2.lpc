#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HIY"侧厅"NOR);
	set("long",
HIC"这里是侧厅，靠墙是一排书架，摆满了各种拳谱、书籍。墙角有一张木床。
天地会总舵主陈近南常常在这里研习武学。\n"NOR
	);
	set("exits", ([
		"east" : __DIR__"qingmutang",
	]));
  
  set("lingwu_family", "天地会");
	setup();
	replace_program(ROOM);
}