// Room: /d/shaolin/xiaoxi1.c
// by bren

inherit ROOM;
#include <ansi.h>
int do_jump(string arg);

void create()
{
	set("short", "溪旁空地");
	set("long", 
"这是溪旁的一块空地，地上绿草茵茵，间或点缀着一些叫不出名子的野\n"
"山花。远处树林中隐隐露出一片红墙，看来这里已经是寺中边缘地带了。前\n"
"面较为宽敞的地方，有一栋歇山重檐，高二层，建筑古朴的楼阁，楼中悬一\n"
"方横匾，上书『"HIY"藏经阁"NOR"』三个字。\n"

	);

	set("exits", ([
		"enter" : __DIR__"cjlou",
	]));

	set("outdoors", "少林");
	setup();
}

void init()
{
	add_action("do_jump", "jump");
	add_action("do_jump", "yue");
}

int do_jump(string arg)
{
	object me = this_player();

	if (arg == "river" || arg == "xiaoxi") {
		if (me->is_busy() || me->is_fighting()) write("你正忙着呢。\n");
		else if (me->query_skill("dodge", 1) >= 60) {
			message("vision", me->name() + "吸了口气，纵身向对面跃去。\n",environment(me), ({me}) );
			write("你吸了口气，纵身向对面跃去。\n");
			me->move(__DIR__"xiaoxi");
			message("vision", "只见人影一闪，" + me->name() +  "纵身跃了过来。\n",environment(me), ({me}) );
		}
		else {
			message("vision", me->name() + "纵身向对面跃去，只听“扑通”一声，" + me->name() + "摔入溪中，狼狈的爬了回来。\n", environment(me), ({me}) );
			write("你纵身向对面跃去，只听“扑通”一声，你摔入溪中，狼狈的爬了回来。\n");
                        me->receive_damage("qi",30);
		}
		return 1;
	}
	return 0;
}
