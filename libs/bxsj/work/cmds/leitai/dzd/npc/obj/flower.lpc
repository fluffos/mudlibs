// /d/dzd/obj/flower.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIW"醉仙灵芙"NOR,({"flower","zuixian lingfu"}));
	set_weight(10);
	if(clonep())
		set_default_object(__FILE__);
	else {
		set("unit","朵");
		set("long",HIW"这是水仙一般的花卉，似水仙而大，花作白色，香气幽雅。\n"NOR);
		set("value",100);
		set("material","plant");
		set("no_get",1);
		set("dzd_obj",1);
	}
	setup();
}

void init()
{
	object me = this_player();
	object ob = this_object();
	object weapon;
		
	if(me->query_temp("weapon")) weapon = me->query_temp("weapon");
	
	if( ( weapon && weapon->query("id") == "tanxiang mujian") || random(me->query_skill("poison",1)) > 30 )
	{
		me->set_temp("dzd_quest/no_poison",1);
	}
	if(!ob->query_temp("poison") && !me->query_temp("dzd_quest/no_poison"))
	{
		me->add_condition("lingfu_poison",10);
		ob->set_temp("poison",1);
		call_out("out_poison",10,ob);
	}
}

void out_poison(object ob)
{
	if(!ob) return;
	ob->delete_temp("poison");
}