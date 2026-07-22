#include <ansi.h>
#include <combat.h>
inherit NPC;
 
void create()
{
	set_name("哮天犬", ({ "xiaotian quan","quan","dog" }) );
        set("long", 
                "杨戬的哮天犬。\n"
        );
        set("race", "野兽");
        set("title","凶神恶煞");
        set("rank_info/respect", "可爱的小狗狗");
        set("rank_info/rude", "畜生");
	set("age", 400);
	set_level(79);
        set("per", 15);
        set("attitude", "friendly");
        set_skill("dodge",790);
   	set_skill("unarmed",790);
   	set_skill("parry",790);
   	set("limbs", ({ "头部", "后心","颈部","小腹","身体","前腿","尾巴","后腿"}) );
   	set("verbs", ({ "bite", "claw" }) );
   	add_temp("apply/max_kee",20000);
   	add_temp("apply/max_sen",20000);
      	setup();
}

void die()
{
	if( environment() )
		message("vision", "\n\n啸天犬受了重伤，哀叫几声夹着尾巴往梅山逃去。。。。\n\n", environment());
	destruct(this_object());
}

void dog_hit(object who)
{
	int damage;
	remove_call_out("dog_hit");
	if( who && environment() && this_object()->is_fighting(who) )
	{
		damage = who->query_maxkee()/50+1;
		if( damage<500 )
			damage = 500;
		switch(random(5))
		{
			case 0 :
				message_vision("\n"HIW"$N"HIW"仰天长哮，迎风涨成一头三丈来高的巨犬，血盆大口朝着$n"HIW"恶狠狠咬去！\n"NOR,this_object(),who);
				if( random(3)==0 )
					message_vision(HIC"结果$N"HIC"不慌不忙，用手一指，$n"HIC"顿时呜呜直叫，摇身恢复了原状。\n\n"NOR,who,this_object());
				else
				{
					message_vision(HIR"结果$N"HIR"闪避不及，被咬了正着，顿时被撕去一大口血肉！$n"HIR"嚼了几嚼，摇身恢复了原状。\n"NOR,who,this_object());
					this_object()->receive_curing("kee",damage/5+1);
					this_object()->receive_heal("kee",damage/5+1);
					who->receive_wound("kee",damage,this_object(),TYPE_CAST);
					COMBAT_D->report_status(who,1);
				}
				break;
			case 4 :
				message_vision("\n"HIW"$N"HIW"仰天发出一阵长哮！\n"NOR,this_object(),who);
				if( random(3)==0 )
					message_vision(HIC"结果$N"HIC"置若罔闻，不受任何影响。\n\n"NOR,who);
				else
				{
					message_vision(HIR"结果$N"HIR"只觉两耳轰鸣，顿时头脑一阵迷糊。\n"NOR,who);
					this_object()->receive_curing("sen",damage/5+1);
					this_object()->receive_heal("sen",damage/5+1);
					who->receive_wound("sen",damage,this_object(),TYPE_CAST);
					COMBAT_D->report_sen_status(who,1);
				}
				break;
		}
		call_out("dog_hit",3,who);
	}
}

void kill_ob(object who)
{
	if( !query_temp("my_killer") )
	{
		set_temp("my_killer",who);
		remove_call_out("dog_hit");
		call_out("dog_hit",2,who);
	}
	::kill_ob(who);
}