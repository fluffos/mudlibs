
#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIW "无极仙丹" NOR, ({ "wuji xiandan", "dan" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一颗仙丹，散发出阵阵清香，据说可以治愈一个人的暗疾。\n");
		set("value", 500000);
		set("yuanbao", 300);
		set("unit", "颗");
        set("no_sell",1);
        set("no_give",1);
        set("no_drop",1);
        set("no_get",1);        
		set("only_do_effect", 1);
		set("suit_point",300);
	}
}

int do_effect(object me)
{
	mapping my;

	log_file("static/using", sprintf("%s(%s) eat 无极仙丹 at %s.\n",
		 me->name(1), me->query("id"), ctime(time())));

	message_vision("$N一仰脖，吞下了一" + query("unit") + name() + "。\n", me);
	if (me->query("gift/xiandan_fail") > 0 && random(2))
	{
		write(HIM "你觉得自己的头脑更清醒了。"NOR"\n");
		me->add("gift/xiandan_fail", -1);
		me->add("int", 1);
		write("\n "+HIR+"恭喜你："+NOR+HIG+"服用"+name()+"成功，《先天悟性》增加了！！！"NOR"\n");
	}

	if (me->query("gift/unknowdan_fail") > 0 && random(2))
	{
		write(HIR "你觉得自己的腿脚更灵活了。"NOR"\n");
		me->add("gift/unknowdan_fail", -1);
		me->add("dex", 1);
		write("\n "+HIR+"恭喜你："+NOR+HIG+"服用"+name()+"成功，《先天身法》增加了！！！"NOR"\n");
	}

	if (me->query("gift/xisuidan_fail") > 0 && random(2))
	{
		write(HIC "你觉得自己的内息更通畅了。"NOR"\n");
		me->add("gift/xisuidan_fail", -1);
		me->add("con", 1);
		 write("\n "+HIR+"恭喜你："+NOR+HIG+"服用"+name()+"成功，《先天体质》增加了！！！"NOR"\n");
	}

	if (me->query("gift/shenliwan_fail") > 0 && random(2))
	{
		write(HIG "你觉得自己的膂力更强健了。"NOR"\n");
		me->add("gift/shenliwan_fail", -1);
		me->add("str", 1);
		write("\n "+HIR+"恭喜你："+NOR+HIG+"服用"+name()+"成功，《先天臂力》增加了！！！"NOR"\n");
	}
	write(HIM "冥冥中你有所感悟。只觉得灵台一片空明，纯净无比。"NOR"\n");
	me->add("magic_points", 600+random(1000));
	me->add("gift/xuelian", 1);
	my = me->query_entire_dbase();
	my["eff_jing"] = my["max_jing"];
	my["jing"] = my["max_jing"];
	my["eff_qi"] = my["max_qi"];
	my["qi"] = my["max_qi"];
	if (my["jingli"] < my["max_jingli"])
		my["jingli"] = my["max_jingli"];
	if (my["neili"] < my["max_neili"])
		my["neili"] = my["max_neili"];
	write(HIY "一阵畅快之后，你觉得浑身是劲！"NOR"\n");
	destruct(this_object());
	return 1;
}

int query_autoload() { return 1; }