
#include <ansi.h>

inherit ITEM;

 void create()
{
	set_name("粗绳子",({"cu shengzi","shengzi"}));
	set_weight(500);
	if(clonep())
		set_default_object(__FILE__);
	else {
		set("unit","条");
		set("value",1000);
		set("long","一条用麻布搓成的绳子。\n");
	}
	setup();
}

void init()
{
	add_action("do_bang","bang");
}

int do_bang(string arg)
{
	object wood,raft;

	if( !arg || arg=="" ) return 0;
	if( arg=="mu" || arg== "mu tou") {
		if(wood=present("mu tou", environment(this_player()))) {
			if (! environment(this_player())->query("sld_boat"))
				return notify_fail("这里就绑的话，离大海太远了吧？\n");
			if(raft=present("mufa", environment(this_player())))
				tell_object(this_player(),"你正在用粗绳子将几根大木头绑在一起...\n");
			else {
				message_vision("只见$N用粗绳子将几根大木头绑在一起...\n" NOR,this_player());
				message_vision("不一会儿一个小木筏被$N扎成了。\n" NOR,this_player());
				message_vision("$N把剩下的绳子放进了怀里。\n" NOR,this_player());
				raft = new(__DIR__"mufa");
				raft->move(environment(this_player()));
				destruct(wood);
			}
			return 1;
		}
		return notify_fail("你要绑什么？\n");
	}
	return 0;
}
