#include <ansi.h>

inherit ITEM;
void create()
{	
	set_name("车辇", ({ "che nian","che","nian"}));
	set_weight(50000000);
	set("no_get",1);
	set("long", "这是一辆天家的车辇。\n");
	set("material", "jade");
	set("unit", "辆");
	set("value", 0);
	setup();
}
int do_look(string arg)
{
	object me=this_player();
	if (me==this_object()->query("owner")&&member_array(arg,({"che nian","che","nian"}))!=-1)
	{
		tell_object(me,"车辇(che nian)\n");
		tell_object(me,"这是一辆天家的车辇，你奉命来修整(xiuzheng)它。\n");
		return 1;
	}
	return 0;
}
void init()
{
	add_action("do_look",({"l","look"}));
	add_action("do_xiuzheng","xiuzheng");
}
int result(object me)
{
	if (!me||!living(me))
	return 1;
	tell_object(me,"车辇的状况改善了很多。\n");
	if (random(10)>4)
	{
		me->set_temp("songtasks/zaozuo/1/finish",1);
		message_vision("修整完成，$N被拉走了。\n",this_object());
		destruct(this_object());
		return 1;
	}
	tell_object(me,HIM"但似乎还需要再加一把力……\n"NOR);
	me->delete_temp("songtasks/zaozuo/xiu");
	return 1;
}
int do_xiuzheng()
{
	object me=this_player();
	if (me->query_temp("songtasks/zaozuo/task")!=1)
	return 0;
	if (me->query_temp("songtasks/zaozuo/xiu"))
	{
		tell_object(me,"你正在修整车辇。\n");
		return 1;
	}
	message_vision("$N开始修整车辇……\n",me);
	me->set_temp("songtasks/zaozuo/xiu",1);
	remove_call_out("result");
	call_out("result",2+random(10),me);
	return 1;
}