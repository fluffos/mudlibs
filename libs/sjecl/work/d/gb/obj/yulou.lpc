#include <ansi.h>

inherit ITEM;
void create()
{
	set_name("鱼篓", ({ "yu lou","yulou", "lou" }));
	set_weight(1000);
	set_max_encumbrance(8000);

	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long","这是一个用上等竹子编制的鱼篓，由里向外透着一股寒气。\n"+
			"往这个鱼篓里装(zhuang)的鱼都会很新鲜。\n");
		set("value", 1);
	}
	setup();
}

void init()
{
	add_action("do_zhuang","zhuang");
	add_action("do_noput","put");
}

int do_zhuang(string arg)
{
	object ob,obj;
	ob=present("yu lou",this_player());
	obj=present("yu",this_player());

	if(!present("yu lou",this_player())) return notify_fail("你身上没有鱼篓。\n"); 
	if(!objectp(obj=present("yu",this_player()))) return notify_fail("你身上没有鱼。\n");
	if(!arg || arg !="yu" ) return notify_fail("这是鱼篓，只能装鱼，你想装什么进去？\n");
	if (obj->move(ob)){
		message_vision("$N将一条"+(string)obj->query("name")+"装入$n。\n",this_player(),ob);
		return 1;
	}
	return notify_fail(obj->name()+"对鱼篓来说太重了。\n");
}

int do_noput(string arg) 
{
	string item, target; 
	if(!arg) return notify_fail("你要将什么东西放进哪里？\n");
	if(sscanf(arg,"%s in %s",item,target)==2 && target == "lou"||target =="yu lou" ||target =="yulou" ) {
		write("你只可以把鱼装(zhuang)到鱼篓里。\n");
		return 1; 
	}
}
