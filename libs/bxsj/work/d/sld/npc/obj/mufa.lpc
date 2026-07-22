//mufa.c
//wzfeng
#include <ansi.h>

inherit ITEM;

void create()
{
	set_name("木筏",({"mufa"}));
	set_weight(50000);
	set("no_get",1);
	if(clonep())
		set_default_object(__FILE__);
	else {
		set("unit","个");
		set("value",50);
		set("long","这是一个用木头和绳子扎起来的小木筏，可以做(zuo)着它漂泊。\n");
	}
	setup();
}

void init()
{
	add_action("do_zuo","zuo");
	add_action("do_drop","drop");
}

int do_drop(string arg)
{
	if(arg=="mufa")
		return 1;
	else
		return 0;	
}

int do_zuo(string arg)
{
	object me,mf;

	if( !arg || arg=="" ) return 0;
	if(arg==("mufa")) {
		if(!objectp(mf=find_object(__DIR__"mu_fa1")))
			mf=load_object(__DIR__"mu_fa1");
		if(mf->query_temp("curstatus",1)=="run") {
			if(!objectp(mf=find_object(__DIR__"mu_fa2")))
				mf=load_object(__DIR__"mu_fa2");
			if(mf->query_temp("curstatus",1)=="run") {
				if(!objectp(mf=find_object(__DIR__"mu_fa3")))
					mf=load_object(__DIR__"mu_fa3");
				if(mf->query_temp("curstatus",1)=="run")
					return notify_fail("木筏还没扎结实，等下再坐吧。\n");
			}
		}
		me=this_player();
		message_vision("只见$N轻轻一跃，已坐在木筏上。\n" NOR,me);
		message_vision("只见一阵海风吹来，木筏已缓缓向东飘去。\n" NOR,me);
		tell_room(environment(me), me->name() + "坐在木筏上向东飘去。\n");
//		mf=new(__DIR__"mu_fa");
//		if(userp(me) && !wizardp(me)) me->set("invisibility",  1);
		me->move(mf);
		mf->set_temp("curstatus","run");
		destruct(this_object());
		return 1;
	}
	return notify_fail("你要坐什么？\n");
}
