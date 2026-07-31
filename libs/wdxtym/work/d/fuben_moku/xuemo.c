inherit NPC;

void end_fuben(object me);
void xuemo_pfm();
#include "fuben_init_skills.h"

void create()
{
	set_name("血魔", ({"xue mo", "mo"}));
	set("long", "魔窟中产生的血魔。");
	set("combat_exp", 100000);
	set("shen",-10000);
	
	set("max_qi", 3000000);
	set("qi", 3000000);
	set("max_neili", 20000);
	set("neili", 20000);
	set("max_jing", 10000);
	set("jing", 10000);
	
	set("chat_chance_combat", 120);
	
	set_temp("apply/attack", 150);
	set_temp("apply/defense", 150);
	set_temp("apply/damage", 100);
	set_temp("apply/unarmed_damage", 100);
	set_temp("apply/armor", 200);

	setup();
}

void init()
{
    object * player;
    
    if (sizeof(player = filter_array(all_inventory(environment(this_object())), (: userp($1) :))))
    {
        if (sizeof(player))
            kill_ob(player[0]);
    }
}


void die()
{
	object me, who, gift, ob;
	
	me = this_object();
	who = environment(this_object())->query("player");
	
	if (!userp(who))
	{
	    write(query("xuemo") + "出错，请联系管理员处理。\n");
	    ::die();
	}
	
	if (me->query("xuemo") >= 100)
	{
		gift = new("/clone/money/coin");
		gift->set_amount(1);
		gift->move(who);
		gift = new("/d/fuben_jiaofei/obj/butian_suipian");
		gift->set_amount(5);
		gift->move(who);
		who->add("yuanbao", 0);
		who->add("combat_exp", 1000);
		who->add("potential", 1000);
		tell_object(who, "恭喜你你完成了魔窟挑战，获得了0灵石，5补天碎片，1筒子，1000潜能和修为。\n");
		__DIR__"moku"->restore_status(who);
		who->move("/d/city/guangchang");
		::die();
	}
	else
	{
    	init_npc(me, (ob = new(__FILE__)));
    	ob->move(environment(this_object()));
    	
		gift = new("/clone/money/silver");
		gift->set_amount(1);
		gift->move(who);
		who->add("yuanbao", 0);
		who->add("combat_exp", 100);
		who->add("potential", 200);
    	tell_object(who, "你击杀了血魔获得0灵石，1两银子，100修为和200潜能。\n");
    	::die();
	}
}

void xuemo_pfm()
{
    object who = select_opponent();
    tell_object(who, "血魔发出一声怪吼，扑向你撕咬。\n");
    if (random(2))
    {
        tell_object(who, "你被血魔咬中了，伤口开始麻痹。\n");
        who->start_busy(3);
    	who->affect_by("xuedu",
    		       ([ "level" : 200,
    			  "id"    : query("id"),
    			  "duration" : 100,]));
    }
    else
    {
        tell_object(who, "你往旁边一躲，血魔扑了个空。\n");
    }
}