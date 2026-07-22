// bishou.c 匕首
#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
	set_name( "匕首" , ({ "bi shou", "sword", "bishou", "jian" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把边缘锋利的匕首，好象可以斩(zhan)东西。\n");
		set("value", 0);
		set("material", "iron");
		set("no_get", 1);
		set("no_give", 1);
		set("no_drop", 1);
	}
	init_sword(35);
	setup();
}

void init()
{
	add_action("mark_success", ({"zhan", "斩"}));
}

int mark_success(string arg)
{
	object me, target, ob,name1;
	me = this_player();
	name1 = me->query("id"); 

	if(!arg) return notify_fail("你要斩什么？\n");  
	target = present(arg, environment(me));  

	if( me->is_busy() || me->is_fighting() )
		return notify_fail("你现在正忙着呢。\n"); 

	if(!target) 
		return notify_fail("找不到这个东西。\n");

	if(!target->is_corpse()) 
		return notify_fail("看清楚点，那不是尸体。\n");

	if (target->query("race") != "人类")
		return notify_fail("不会吧，你对动物的尸体也感兴趣？\n");

	if(target->query("no_head")) 
		return notify_fail("那具尸体已经没有首级了。\n");

	if(!target->is_character()) 
		return notify_fail("那具尸体已经腐烂了。\n");

	if( me->query_conditions_by_type("job") && target->query("kill_by") != me)
		return notify_fail("你还是安心做任务吧，乱切别人杀的人干吗啊？\n"); 

	message_vision(HIR"$N扬起匕首 ，对准$n的脖子处猛地斩了下去！\n"NOR, me, target);
	ob=new("/clone/misc/head");
	ob->set_name(target->query("victim_name")+"的首级",({"head"}));
	ob->set("long", "这是一颗"+target->query("victim_name")+"的首级。\n");    

	if(target->query("victim_user")) 
		ob->set("victim_user", 1);  
	if(target->query("kill_by")){ 
		ob->set("kill_by", target->query("kill_by"));
		target->delete("kill_by");
	}

	ob->set("victim_id", target->query("victim_id"));
	ob->set("victim_name", target->query("victim_name"));
	target->delete("victim_id");
	target->delete("victim_id");

	message_vision(HIR"$N将$n斩了下来，提在手中。\n"NOR, me, ob);
	ob->move(me);
	target->set("name", "无头尸体");
	target->set("no_head", 1);
	target->set("long", "一具无头尸体，腐臭四溢，情状可怖。\n");           
	return 1;
} 
