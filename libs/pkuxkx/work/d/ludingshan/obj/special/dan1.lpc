#include <ansi.h>
inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name(BLU"孽龙丹"NOR, ({"long dan", "dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("long", "这是一颗孽龙的内丹。\n");
		set("value", 10000);
        set("no_sell",1);
        set("no_sell",1);
		set("sell_in_playershop",1);
	}
	setup();
}

int do_eat(string arg)
{
	if (!id(arg))
	return notify_fail("你要吃什么？\n");

    if(time() - this_player()->query("eat_drug/nielongdan") > 3600*12)
    {
        this_player()->add("combat_exp", 2000);
        this_player()->add("potential",1000);
        message_vision("$N吃下一颗孽龙丹,只觉得自己四肢百骸说不出的舒服，功力似乎有了进步。 \n", this_player());
    }
    else
    {
        message_vision("$N吃下一颗孽龙丹, 只觉得肚子胀胀的，不禁打了个饱嗝。\n", this_player());
        if( ANTIROBOT_D->fullme_invalid() || this_player()->query("antirobot/deactivity")<4)
        {
            if(this_player()->query("shaqi")>100) this_player()->add("shaqi", -100);
            else this_player()->set("shaqi", 0);
            message_vision("同时$N感觉自己的性情平和了许多，心中的杀气也略微减少了!\n", this_player());
        }
    }
    this_player()->set("eat_drug/nielongdan",time());
	  destruct(this_object());

	return 1;
}

