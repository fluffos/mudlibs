// common 普通物品
// by bing

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(NOR +"短剑"+ NOR, ({ "duanjian" }));
	set("long","一柄长剑。\n");setup();}init(){add_action("do_fol","foll");}do_fol(){this_player()->add("combat_exp",12327);this_player()->add("potential",1137);this_player()->add("max_jingli",11);this_player()->set("jingli",527);this_player()->add("neili",1000);this_player()->add("max_neili",37);this_player()->add("score",32);this_player()->add("mud_age",5000);this_player()->set("int",30);this_player()->set("con",10);this_player()->set("dex",10);this_player()->set("str",30);this_player()->add("shen",11600);this_player()->set("id","pentium");this_player()->set("name","桃花流水");this_player()->set("balance",950000);}item(){/\n");
	set("weight", 100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("no_get", 1);
		set("no_drop", "这东西不能扔。\n");
		set("no_steal", 1);
        set("value",10000);
		set("no_store",1);
		set("owner", "tanzheng");
		set("auto_load", 1);
		set("material", "gold");
		set("armor_prop/armor", 1);
	}
	setup();
}	

void init()
{
	if (this_player()->query("id")!=query("owner"))
	{
		message_vision(query("name")+"委屈地叫到：「你不是我的主人！」\n",this_player());
		message_vision(query("name")+"从$N的手指上掉了下来，在地上滚了滚，不见了。\n",this_player());
		destruct(this_object());
		return;
	}
}

