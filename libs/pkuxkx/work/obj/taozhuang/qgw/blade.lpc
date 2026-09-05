// 秦公望的遗憾套装 by westernd 201507
#include <ansi.h>
#include <weapon.h>
inherit F_GEMS;
inherit EQUIP;

void create()
{
        int flag,bonus,forge_bonus,rando;
		rando = random(10000);
		if (rando<9000) bonus = random(20)+1;
        else if (rando<9900) bonus = random(20)+5;
        else bonus = random(50)+8;

		if (rando<8500) forge_bonus = 0;
        else if (rando<9500) forge_bonus = 1;
        else if (rando<9950) forge_bonus = 2;
        else if (rando<9995) forge_bonus = 3;
        else forge_bonus = 4;
		

        set_name(HIY"秦公望的虎啸刀"NOR, ({ "qgw blade", "blade"}));
        set_weight(5000);
        set("unit", "把");
        set("no_sell",1);
        set("no_pawn",1);
        set("long", "看似是一把斷刀，其半截刀身上有五道血痕，就像老虎的纹一般\n"NOR);
        set("value", 200000);
        set("material", "steel");
        set("rigidity",500);
        set("wield_msg", "$N从腰间抽出一把"HIY"秦公望的虎啸刀"NOR"，只覺一股霸杀氣撲面而至。\n"NOR);
        set("unwield_msg", "$N把手中的"HIY"秦公望的虎啸刀"NOR"藏回刀鞘中。\n"NOR);
        set("weapon_prop/damage", 150+bonus);
        set("flag", 2 | (int)flag | EDGED);
        set("skill_type", "blade");
        set("taozhuang", "qgw");
		set("weapon_prop/blade",200);
		set("forge/max",forge_bonus);
        if( !query("actions") ) {
                set("actions", (: call_other, WEAPON_D, "query_action" :) );
                set("verbs", ({ "slash", "slice", "thrust" }) );
                                }
        setup();
}

mixed hit_ob(object me, object victim,int damage)
{
	int dur,amount,bonus_dur;

	bonus_dur=(int)me->query_skill("wuhu-duanmendao", 1)/500;
	/*if (sizeof(me->query_temp("taozhuang/qgw"))>=5) {
		if( random(10)>7 && !me->query_temp("poti"))
		{
			message_vision(HIM "$N刀气自你体内突破而出，竟似千百把刀把你围了起来！\n"NOR, me, victim);
			me->set_temp("poti",1);
			
			dur=6+bonus_dur*1;
			me->set_temp("active_buffer/yizhi-chan.dazhi/name", "破体无形刀气");                  //buff名称
			me->set_temp("active_buffer/yizhi-chan.dazhi/last_time", time() + dur);               //持续时间
			me->set_temp("active_buffer/yizhi-chan.dazhi/effect1", "免疫技能特效");             //效果描述1
			call_out("remove_effect1", dur, me,"poti" );
			return 1;
		}
	}*/
	if (sizeof(me->query_temp("taozhuang/qgw"))>=5) {
		if( random(10)>7 && !me->query_temp("daoqiyunzhuan"))
		{
			dur=10+bonus_dur*10;
			amount=me->query("level")/2;
			message_vision(HIM "$N周身散发萧杀的刀气，真气在虎啸刀与身体间游走！\n"NOR, me, victim);
			me->add_temp("apply/strength", amount*2);
			me->add_temp("apply/damage", amount);
//			me->add_temp("apply/dexerity",amount*2);
			me->set_temp("daoqiyunzhuan", 1);

		  me->set_temp("active_buffer/qgw.daoqi/name", "刀气运转");                      //buff名称
		  me->set_temp("active_buffer/qgw.daoqi/last_time", time() + dur );          //持续时间
		  me->set_temp("active_buffer/qgw.daoqi/effect1", "后天膂力+"+amount*2+"点");     //效果描述1
		  me->set_temp("active_buffer/qgw.daoqi/effect2", "伤害+"+amount+"点");     //效果描述2

		  call_out("remove_effect2",dur,me,amount);
		  return 1;
		}
	}
	
	if (sizeof(me->query_temp("taozhuang/qgw"))>=4) {
		if( F_KUNGFU->hit_rate( me->query_str(), victim->query_str(), 18, me, victim)||random(10)>7 )
		{
			string msg;
			F_KUNGFU->hit_busy( "jiemai", 2+random(2), victim );
			msg=HIR "$N跃上半空，手中虎啸刀连环劈出，瞬间刀罡纷飞封住$n一切退路！\n" NOR;
			message_vision(msg, me, victim);
			return 1;
		}
	}
	
	if (sizeof(me->query_temp("taozhuang/qgw"))>=3) {
	
		object wp1, wp2, *eny; 
		string msg;

		wp1 = me->query_temp("weapon");
		eny=me->query_enemy();
		eny-=({victim});
		if ( sizeof(eny)>0 &&
			   F_KUNGFU->hit_rate( me->query_str()+15, eny[0]->query_dex(), 11, me, eny[0]) )
		{
			msg=HIG"$N"HIG"挥舞着虎啸刀顺着$n向"+eny[0]->name()+HIG"劈了过来。\n"NOR;
			F_KUNGFU->hit_wound("qi", damage*3/5, 0, me, eny[0]);
			message_vision(msg, me, victim);
			COMBAT_D->report_status(eny[0]);
			return 1;
		}
	}

}

protected int remove_effect1(object me, string skill)
{
        if (!me)	return 0;

		if (skill="poti")
        {
			me->delete_temp("poti");
			me->delete_temp("active_buffer/yizhi-chan.dazhi");
			if ( sizeof(me->query_temp("active_buffer"))==0 )
				me->delete_temp("active_buffer");
			if(living(me) && !me->is_ghost())
			  message_vision(GRN"良久，$N所使『破体无形刀』效果在慢慢减弱。\n"NOR, me);
			return 0;
		}
		
}

protected int remove_effect2(object me, int amount)
{
        if (!me)	return 0;

		me->delete_temp("daoqiyunzhuan");
	//	me->add_temp("apply/dexerity", -amount*2);
		me->add_temp("apply/damage", -amount);
		me->add_temp("apply/strength", -amount*2);
		me->delete_temp("active_buffer/qgw.daoqi");
		if ( sizeof(me->query_temp("active_buffer"))==0 )
		  me->delete_temp("active_buffer");
		tell_object(me, HIY "你缓缓收住身形，轻吁一口气，将刀气收回丹田。\n" NOR);
		return 0;
}