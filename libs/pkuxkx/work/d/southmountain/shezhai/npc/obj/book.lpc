inherit ITEM;
#include <ansi.h>

void create()
{
	set_name(CYN"采矿学入门"NOR, ({"caikuang rumen","caikuang","book"}));
	set_weight(300);
	if (clonep())
		set_default_object(__FILE__);
	else 
    {
            set("long", "这是一本采矿学入门，可以学会最初的一些采矿知识。\n");
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
	if (me->query_skill("mining",1)>5)
	{
		write("你已经学会了最初级的采矿学内容了。\n");
		return 1;
	}
	me->set_skill("mining",5);
	message_vision("$N仔细阅读$n，从中学会了采矿学的内容。\n",me,this_object());
	destruct(this_object());
	return 1;
}

