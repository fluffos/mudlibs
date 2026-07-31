// yan.c

#include <weapon.h>
inherit BLADE;
int do_fire(string arg);

int init()
{	add_action("do_fire","fire");
}

void create()
{
	set_name("水烟筒", ({"yan tong", "tong"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是一支云南人喜爱的水烟筒。你可以(fire)来吸烟。\n");
		set("unit", "个");
		set("value", 100);
		set("material", "steel");
                set("wield_msg", "$N从身后抽出$n握在手中当做武器。\n");
                set("unwield_msg", "$N将手中的$n放了回去。\n");
	}
	init_blade(20);
        setup();

}
int do_fire(string arg)
{	
	object me=this_player(),ob;
	ob=present("yan", me);
	if (arg=="" || !arg) return notify_fail("你要干什么？\n");
	if ( (arg=="yan" || arg == "smoke") && objectp(ob) )
	{
	message_vision("你拿起水烟筒咕咕的吸了几口，缓缓的吐出烟雾，只觉的精神好多了。\n",me);
	me->add("jing",20);
	if ((int)me->query("jing") > (int)me->query("max_jing")*2)
	me->set("jing",(int)me->query("max_jing")*2);
	destruct(ob);
	}
	else return notify_fail("你已经没有烟了\n");
	return 1;
}	