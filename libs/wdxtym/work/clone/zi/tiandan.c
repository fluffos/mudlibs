#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIR "天丹" NOR, ({ "tian dan","dan"}) );
	set_weight(20);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "吃过之后内精气神全部恢复，内力加倍.\n");
		set("spectxt", "吃过之后内精气神全部恢复\n");
        set("no_get", 1);
		set("no_drop", 1);
		set("no_steal", 1);
	    set("no_sell", 1);set("value", 500);
		set("unit", "颗");
		set("gongxian", 10000);
		set("only_do_effect", 1);
		set("no_sell",1);
	}
}

int do_effect(object me)
{
	mapping my;
	string *enemy;
	
	if(me->is_busy())
		return notify_fail("你正忙着呢。\n");
      
	 enemy = filter_array(me->query_enemy(), (: userp($1) :));	
	
	if (sizeof(enemy) >0)	
		return notify_fail("正在和玩家对手战斗，不能使用"+ name() +"。\n");

//	message_vision("$N一仰脖，吞下了一颗" + this_object()->name() +"。\n", me);

	my = me->query_entire_dbase();
    my["jing"]   = my["eff_jing"]   = my["max_jing"];
	my["jingli"] = my["eff_jingli"] = my["max_jingli"];
	my["eff_qi"] = my["max_qi"]+me->query_gain_qi();
	my["qi"] = my["max_qi"]+me->query_gain_qi();
	my["neili"]  = my["max_neili"]*3;
	me->start_busy();
	return 1;
}
int query_autoload() { return 1; }