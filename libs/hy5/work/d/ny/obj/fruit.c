
// ffruit.c
// sill email
// zhulp@app.zju.edu.cn
//

#include <ansi.h>

inherit ITEM;
inherit F_AUTOLOAD;

int ffruit_do_e();

void create()
{
	set_name(GRN "不吃不喝果" NOR, ({"fruit"}) );
	set_weight(10);
	set("no_get",1);
	set("no_drop","这么好的东西怎么能丢呢？小雨点会生气的。\n\n");
	set("long",
		"这是小雨点送给你的一颗神奇的果实, 尝尝(eatfruit)吧！\n");
	if( clonep() )
			set_default_object(__FILE__);
	else
	{
		set("unit", "颗");
		set("material", "unknow");
	}
}

void init()
{
	add_action( "ffruit_do_e", "eatfruit" );
}

int ffruit_do_e()
{
	object	ob, me;
	int		fw;
    int maxkee, maxsen, maxgin;
	
	ob = this_object();
	me = this_player();
    maxkee = me->query("max_kee");
    maxsen = me->query("max_sen");
    maxgin = me->query("max_gin");

	if( !me->query_condition("f_condi") )
	{
		write("此果只应天上有，不因为何落人间！哇！。。 太好好吃了, 呜哇...呜哇...\n");
		tell_object(me, "Ou。。你打了个饱嗝。。。Ou...Ou...\n" );

		fw = (int)me->max_food_capacity();
		me->set("food", fw);
		fw = (int)me->max_water_capacity();
		me->set("water", fw);

		write("你再也不用吃饭喝水了！\n\n");
		me->apply_condition("f_condi", 5);
		ob->set("eated", "xixi");
	}
	else
	{

		tell_object( me, "你已经吃过了。不过再吃一次吧\n\n");
		tell_object(me, "Ou。。你打了个饱嗝。。。Ou...Ou...\n" );

		fw = (int)me->max_food_capacity();
		me->set("food", fw);
		fw = (int)me->max_water_capacity();
		me->set("water", fw);
	}
    me->set("eff_kee",maxkee);
    me->set("kee",maxkee);
    me->set("eff_sen",maxsen);
    me->set("sen",maxsen);
    me->set("eff_gin",maxgin);
    me->set("gin",maxgin);

	return 1;
}

int query_autoload()
{
	return 1;
}

