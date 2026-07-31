// /d/dzd/npc/bingcan.c

#include <ansi.h>

//inherit __DIR__"animal";
inherit NPC;

void create()
{
	set_name("冰蚕",({"bingcan","can"}));
	set("race","野兽");
	set("limbs", ({ "头部", "身体" }) );
	set("verbs",({"bite"}));
	set("attitude","peaceful");
	set("age",3);
	set("combat_exp",3000000);
	set("long",HIW"这蚕虫纯白如玉，微带青色，比寻常蚕儿大了一倍有余，便似一条蚯蚓，身子透明直如水晶。\n"NOR);
	set("max_qi",10000);
	set("max_jing",3500);
	set("max_neili",7000);
	set("neili",7000);
	set("eff_jingli",4000);
	set("jingli",4000);
	set("jiali",200);
	set("str",100);
	set("con",100);
	set("dex",100);
	set("dzd_obj",1);

	set_temp("apply/attack",500);
	set_temp("apply/damage",500);
	set_temp("apply/armor",800);
	setup();
}
/*
void init()
{
	add_action("do_jian","jian");
	::init();
}
*/

int hit_ob(object me, object victim, int damage)
{
 	victim->apply_condition("bingcan_poison",
		victim->query_condition("bingcan_poison") + 6);
       return 0;
}
/*
int do_jian(string arg)
{
	////
	return 0;
}
*/