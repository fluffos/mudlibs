inherit ITEM;
#include <ansi.h>

void create()
{
	set_name(HIC"采矿学进阶"NOR, ({"caikuang jinjie","caikuang","book"}));
	set_weight(300);
	if (clonep())
		set_default_object(__FILE__);
	else 
    {
            set("long", "这是一本采矿学进阶，可以学会合成矿石碎片的技术。\n");
            set("unit", "本");
            set("value", 10000000);
    }
	setup();
}

void init()
{
	add_action("do_study",({"study","read","du","yanjiu"}));
}

int do_study(string arg)
{
	object me=this_player();
	if (me->is_busy())
	{
		write("你正忙着呢。\n");
		return 1;
	}
	if (me->query("weapon_cast/mine_unite"))
	{
		write("你已经学会了合成矿石碎片的技术了。\n");
		return 1;
	}
	me->set("weapon_cast/mine_unite",1);
	message_vision("$N仔细阅读$n，从中学会了采矿学中的一些不传之秘。\n",me,this_object());
	tell_object(me,"unite <矿石碎片>可以合成矿石碎片为一块可锻造的矿石材料。\n");
	destruct(this_object());
	return 1;
}

