// Room: /d/tianshan/shandao1.c
// By Linux

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", YEL"山道"NOR);
	set("long", @LONG
这是山道之中，越走道旁的乱草越长，放眼道路崎岖，乱石嶙峋。你向着
灯火快步走去。灯火相隔甚遥，走了好一会，仍是闪闪烁烁，瞧不清楚屋宇。
LONG);
	set("exits", ([
		"east" : __FILE__,
		"south" : __FILE__,
		"west" : __FILE__,
		"north" : __FILE__,
	]));       

	set("outdoors", "天山");
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "west") me->add_temp("mark/steps",-1);
	if (dir == "south") me->add_temp("mark/step",1);
	if (dir == "east") me->add_temp("mark/steps",1); 
        if (dir == "north") me->add_temp("mark/step",-1);

	if (me->query_temp("mark/steps") > 8 || me->query_temp("mark/step") < -8) {
		me->move(__DIR__"shanjin2");
		me->delete_temp("tonglao");
		me->delete_temp("mark");
		log_file("quest/tonglao", sprintf("%8s%-10s未通过童姥解迷第二步，福：%d，淳：%d，容：%d，次数：%d。\n",
			me->name(),"("+me->query("id")+")", me->query("kar"), me->query("pur"), 
			me->query_per(), me->query("quest/tonglao/quest")), me);
		return notify_fail(CYN"\n你喃喃骂道：「这灯可有点儿邪门。」\n"NOR"不知不觉你走回到原来的山路上。\n"NOR);
	}
	if (me->query_temp("mark/steps") == me->query_temp("tonglao/steps") 
	 && me->query_temp("mark/step") == me->query_temp("tonglao/step")) {
		if (random(me->query("kar")) >= 20
		 && random(me->query("pur")) >= 25
		 && me->query("per") < 15
		 && random (41 - me->query_per()) >= 25) {
			me->delete_temp("tonglao");
			me->set_temp("tonglao/pass2",1);
			me->delete_temp("mark");
			me->set("quest/tonglao/second", 1);
			log_file("quest/tonglao", sprintf("%8s%-10s通过童姥解迷第二步，福：%d，淳：%d，容：%d/%d，次数：%d。\n",
				me->name(),"("+me->query("id")+")", me->query("kar"), me->query("pur"), me->query("per"), 
				me->query_per(), me->query("quest/tonglao/quest")), me);
			tell_object(me, YEL"\n你凝目向山谷望去，只见那灯火发出绿油油的光芒，迥不同寻常灯火的色作\n"
					     "暗红或昏黄。你加快脚步，向绿灯又驱前里许，便看得更加清楚了。\n\n"NOR);
			me->move(__DIR__"shangu");
			return notify_fail(YEL"你发现有邪魔外道在此聚会，赶紧躲到旁边的岩石中躲了起来。\n"NOR);
	        }
		else {
			me->move(__DIR__"shanjin2");
			me->delete_temp("tonglao");
			me->delete_temp("mark");
			log_file("quest/tonglao", sprintf("%8s%-10s未通过童姥解迷第二步，福：%d，淳：%d，容：%d，次数：%d。\n",
				me->name(),"("+me->query("id")+")", me->query("kar"), me->query("pur"), 
				me->query_per(), me->query("quest/tonglao/quest")), me);
			return notify_fail(CYN"你喃喃骂道：「这灯可有点儿邪门。」\n不知不觉你走回到原来的山路上。\n"NOR);
		}
	}
        return ::valid_leave(me, dir);
}
