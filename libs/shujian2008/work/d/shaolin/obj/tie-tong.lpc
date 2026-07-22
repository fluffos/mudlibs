// tie-tong.c 

#include <job_mul.h>

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("大铁桶", ({"tie tong", "tong"}));
	set_weight(50000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一对大铁桶，比之寻常水桶大了两倍有余，只怕有二百多斤重。\n");
		set("unit", "对");
		set("value", 100);
		set("max_liquid", 10);
		set("shaolin", 1);
		set("no_drop", 1);
	}

	set("liquid", ([ 
		"type": "water",
		"name": "清水",
		"drunk_supply": 10,
        ]));
}

void init()
{
	if (environment() == this_player()) {
		add_action("do_fill", "fill");
		add_action("do_fill", "zhuang");
		add_action("do_pour", "pour");
		add_action("do_pour", "dao");
		add_action("do_jiao", "jiao");
	}
}

int do_fill(string arg)
{
	object me = this_player();

	if (!arg || !id(arg)) return 0;
	if (base_name(environment(me)) != "/d/shaolin/fxjing") return 0;
	message_vision("$N将$n装满清水。\n", me, this_object());
	set("liquid/remaining", query("max_liquid"));
	return 1;
}

int do_pour(string arg)
{
	object me = this_player();

	if (!arg || arg != "gang") return 0;
	if (base_name(environment(me)) != "/d/shaolin/houdian") return 0;
	if (!query("liquid/remaining")) {
		message_vision("$N拿着两只空铁桶对着大水缸比划着。\n", me);
		return 1;
	}
	if (query("liquid/remaining") < query("max_liquid")){
		message_vision("$N拿着两只没装满水的铁桶对着大水缸比划着。\n", me);
		return 1;
	}
	message_vision("$N将清水倒入大水缸中。\n", me, this_object());
	me->add("jingli", -100);
	me->improve_skill("shaolin-shenfa", 2*(me->query("dex")));
	delete("liquid/remaining");
	if (me->add("carry_count", -1) < 1){
		me->delete("carry_count");
		message_vision("$N干完活，丢下镣铐和铁桶，伸了个懒腰。\n", me);
		if (present("liao kao", me)) destruct(present("liao kao", me));
		destruct(this_object());
	}
	return 1;
}

int do_jiao(string arg)
{
	int pot,exp;
	object me = this_player();
	object ob=present("tie tong",me);
	
	if(!ob) return 0;

	if (!arg || arg != "菜") return 0;
	if (base_name(environment(me))[0..14] != "/d/shaolin/cyzi") return 0;
	if (!me->query_temp("jiaoshui_job")) return 0;
	if ( me->is_busy() || me->is_fighting()) 
		return notify_fail("你正忙着呢。\n");
	if (!ob->query("liquid/remaining")) {
		message_vision("$N拿着两只空铁桶对着菜地比划着。\n", me);
		return 1;
	}
	if (ob->query("liquid/remaining") < query("max_liquid")){
		message_vision("$N拿着两只没装满水的铁桶对着菜地比划着。\n", me);
		return 1;
	}
	message_vision("$N将桶里的清水一瓢瓢地浇在菜地里。\n", me);
	me->add_busy(1);
	me->add("jingli", -50);
	delete("liquid/remaining");
	if (me->add_temp("jiaoshui_job", 1) > 10 + random(4)){
		me->delete_temp("jiaoshui_job");
		message_vision("$N干完活，丢下铁桶，伸了个懒腰。\n", me);
		pot = 20 + random(5);		
		exp = 60 + random(me->query_skill("buddhism"))/2;
		exp = me->add_exp_combat(exp,"缘根","少林菜地");
		//me->add("combat_exp",exp);
		//me->add("job_time/少林菜地",1);
		//GIFT_D->check_count(me,"缘根","少林菜地");				
		me->add("potential",pot);		
		if( me->query("potential")>me->query("max_pot"))
			me->set("potential",me->query("max_pot"));
		destruct(this_object());
	}
	return 1;
}
