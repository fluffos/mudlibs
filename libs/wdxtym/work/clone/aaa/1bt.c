#include <ansi.h>
//更新下算法
inherit ITEM;

void create()
{
	set_name(HIR "BT丹" NOR, ({ "bt dan"}) );
	set_weight(20);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "吃过之后内精气神全部恢复\n");
		set("spectxt", "吃过之后内精气神全部恢复\n");
        set("no_sell", 1);
	    set("value", 500);
		set("unit", "颗");
		set("only_do_effect", 1);
	}
}

int do_effect(object me)
{
	mapping my;
      if (me->is_fighting()) 
		return notify_fail("你现在正在战斗！\n");

//	message_vision("$N一仰脖，吞下了一颗" + this_object()->name() +"。\n", me);
    tell_object(me,"你一仰脖，吞下了一颗" + this_object()->name() +"\n");
/*
	my = me->query_entire_dbase();
    my["jing"]  = my["eff_jing"]   = my["max_jing"];
	my["jingli"] = my["eff_jingli"] = my["max_jingli"];
	my["eff_qi"] = my["max_qi"]+me->query_gain_qi();
	my["qi"] = my["max_qi"]+me->query_gain_qi();
	my["neili"]  = my["max_neili"];
	/**/
	 me->set("eff_qi", me->query("max_qi")+me->query_gain_qi());
	 me->set("qi", me->query("max_qi")+me->query_gain_qi());
     me->set("eff_jing", me->query("max_jing")+me->query_gain_jing());
     me->set("jing", me->query("max_jing")+me->query_gain_jing());
     me->set("neili",me->query("max_neili"));
     me->set("jingli",me->query("max_jingli"));
	me->start_busy();
	return 1;
}
int query_autoload() { return 1; }