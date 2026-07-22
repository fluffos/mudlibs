// yaozhong.c

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIG "药种" NOR, ({"yao zhong","zhong zi","zhong" })); 
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long",
                "这是一枚可以种(zhong)在药圃里的药种，");
		set("unit", "枚");
		set("no_sell",1);
		set("5type","土");
		set("location",1);
		//set("8type","乾");
	}
}

void init()
{
	add_action("do_zhong","zhong");
}

int do_zhong(string arg)
{
	object ob,obj;
	object me=this_player();
	object room;

	if(!arg || !objectp(ob=present(arg, me)) || (ob!=this_object()))
		return notify_fail("你要种什么？\n");
	if(!objectp(room=environment(me)) || (room->query("can_zhong")!=1))
		return notify_fail("你不能在这里种药。\n");
	if(!objectp(obj=new(__DIR__"yaomiao")))
		return notify_fail("你现在不能种药，等一会再种吧。\n");
	obj->set("5type",ob->query("5type"));
	obj->set("8type",room->query("8type"));
	obj->set("long",obj->query("long")+obj->query("8type")+obj->query("5type")+"性。\n");
	obj->set("stime",uptime());
	obj->set("jtime",uptime());
	obj->set("name","幼小的药苗");
	obj->move(room);
	message_vision("$N把一枚药种埋到土里，浇了一瓢水，慢慢地，从土里长出了一株幼苗。\n",me);
	call_out("destructing", 1, ob); 
	return 1;
}

void destructing(object ob)
{
	destruct(ob);
}