//by 游侠 ranger's ednpc tools.
// chukou.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","副本出口");
	set("long","这里是副本出口，管理员尚未设定本地详细描述。");
	set("fuben2",1);
	set("exits", ([
		"west" : __DIR__"xiaolu14",
	]));
	set("objects", ([
	]));
	set("action_list", ([
		HIR"退出副本"NOR:"out_fuben yes",
	]));
	setup();
}
void init()
{
	add_action("out_fuben","out_fuben");
}
int out_fuben(string arg)
{
	object me = this_player();
	string str;

	if (me->is_busy()) {
		tell_object(me, "等你忙完再说。\n");
		return 1;
	}

	if (me->is_fighting()) {
		tell_object(me, "等你打完架再说。\n");
		return 1;
	}

	if (!arg) {
		str = sprintf("%s", "退出副本(结束任务):out_fuben yes" + ZJSEP);
		str += sprintf("%s", "取消:out_fuben no");
		tell_object(me, ZJOBLONG+"\n"+ZJOBACTS2+ZJMENUF(2,2,9,38) + str+"\n");
	}
	else if (arg == "yes"){
		tell_object(me, HIC+"删除目录(/fuben/"+me->query("id")+"/jinbing1)。\n"NOR);
		if (me->query("fuben/jinbing1")) {//副本任务清除
			"/adm/daemons/fuben_jinbing1"->dest_fb(me);
			me->delete("fuben/jinbing1");
		}
		me->move("/d/city/wumiao");
	} else
		tell_object(me, "你决定留在副本里。\n");
	return 1;
}
int no_reset() {return 1;}
