// dushen.c  毒神附体 2015/01/08 Zine@pkuxkx
//加强一些，加入了毒神期间化学伤害提高
#include <ansi.h>
#define COE 100000000
inherit F_CLEAN_UP;
int VerifyHidden(object me)
{
	if (!me->query("safari_skill/xx_dushen")||me->query("family/family_name")!="星宿派"||me->query("chushi")) return 0;
	return 1;
}
void remove_antibusy(object me)
{
	if (me) 
	{
		me->delete_temp("apply/cant_all_busy");
		me->delete_temp("active_force_buffer/xingxiu-duzhang.dushen1");        
	}
}
void remove_immune(object me,string stage)
{
	int remain_time;
	if (me) 
	{
		if (stage=="a")
		{
			me->add_temp("apply/week_injure",-50);
			me->add_temp("apply/kf_def_wound",-50);
			call_out("remove_immune", 20, me,"b");
		}
		if (stage=="b")
		{
			me->add_temp("apply/week_injure",-25);
			me->add_temp("apply/kf_def_wound",-25);
		}
	}
}
void remove_enforce(object me,string stage,int pts,int pts1)
{
	int remain_time;
	if (me) 
	{
		me->add_temp("apply/attack", - pts);
		me->add_temp("apply/kf_wound",- pts1);
		me->delete_temp("active_force_buffer/xingxiu-duzhang.dushen2");
		if (stage=="a")
		{
			me->add_temp("apply/attack", pts/2);
			me->add_temp("apply/kf_wound", pts1/2);
			remain_time=me->query("dushen/end_time")-time();
			me->set_temp("active_force_buffer/xingxiu-duzhang.dushen2/name", "加力");
			me->set_temp("active_force_buffer/xingxiu-duzhang.dushen2/last_time", time() + remain_time );                //持续时间
			me->set_temp("active_force_buffer/xingxiu-duzhang.dushen2/effect1", "攻击命中+"+(pts/2)+"级");       //效果描述1   
			me->set_temp("active_force_buffer/xingxiu-duzhang.dushen2/effect2", "化学伤害加强+"+(pts1/2)+"%");       //效果描述2  	
			call_out("remove_enforce", remain_time, me,"b",pts/2, pts1/2);
			message_vision(HIB"$N"+HIB+"运转毒神附体时间减长，攻击略略变慢一点。\n"+NOR,me);
		}
		if (stage=="b")
		{
			me->delete_temp("dushen");
			me->delete_temp("apply/cant_all_busy");//in case
			me->add_temp("apply/AllPoisonsImmune",-100);
			me->add_temp("apply/kf_abs_def",-25);
			me->add_temp("apply/abs_week_injure",-25);
			F_POISON->depoison(me);
			if (me->query_temp("apply/xx_dushen"))
				F_POISON->empoison(me,"xx_poison2",1,"all");
			me->delete_temp("active_force_buffer/xingxiu-duzhang.dushen1");    							
			message_vision(HIB"$N"+HIB+"散去附体的毒素。\n"+NOR,me);
		}
	}
}
int anti_damage(object me)
{
	if (!me->query_temp("dushen")) return 0;
	if (time()-me->query("dushen/init_time")<20) return 100;
	if (time()-me->query("dushen/init_time")<40) return 50;
	return 25;
}
void poison_enemies(object me)
{
	object *enemy;
	enemy=me->query_enemy();
	message_vision(HIB+"身在蓝雾中的$N"+HIB+"以不可思议的速度向对手发出了攻击……\n"+NOR,me);
	for (int i=0;i<sizeof(enemy);i++)
	{
		if (userp(enemy[i])) tell_object(enemy[i],HIW+"身在蓝雾中的"+me->query("name")+HIW+"已经攻到了你的面前。\n"+NOR);
		F_POISON->poison_attack(me,enemy[i],"xx_poison2",4+random(2));
		enemy[i]->set("dushen_poison",me->query_skill("poison",1));
	}
}
int cal_cd(object me)
{
	int res=360,*exps=({1,2,3,4,5,6,7,8}),*cds=({330,300,270,240,225,210,195,180});
	if (me->query("combat_exp")>100000000)
		for (int i=0;i<sizeof(exps);i++)
		if (me->query("combat_exp")>exps[i]*COE) res=cds[i];
	return res;
}
int cal_antibusy_period(object me)
{
	int res=15;
	if (me->query("combat_exp")<1*COE) return 12;
	if (me->query("combat_exp")<2*COE) res-=random(2);
	if (me->query("combat_exp")>4*COE&&random(100)>49) res+=1;
	else if (me->query("combat_exp")>8*COE) res+=1;
	if (me->query("combat_exp")>8*COE&&random(100)>89) res+=2;
	return res;
}
int perform(object me, object target)
{
        int skill,skill1,cd,antibusy_period,dur_time;
		if (!me->query("safari_skill/xx_dushen"))
			return notify_fail("你并没有掌握毒神附体。\n");
		if (me->query("family/family_name")!="星宿派")
			return notify_fail("只有星宿派弟子才能使用毒神附体。\n");
		if (me->query("chushi"))
			return notify_fail("只有纯粹的星宿派弟子才能使用毒神附体。\n");
        if( (int)me->query("neili") < 1500  )
                return notify_fail("你的内力不足以使用毒神附体。\n");
        if( (int)me->query_temp("dushen") )
                 return notify_fail("你已经在使用毒神附体中了。\n");
        if ((int)me->query_skill("xingxiu-duzhang", 1) < 200)
                return notify_fail("你的星宿毒掌等级太差，不能使用毒神附体。\n");
		if ((int)me->query_skill("poison", 1) < 500)
                return notify_fail("你的基本毒技等级太差，不能使用毒神附体。\n");
		cd=cal_cd(me);
		if (time()-me->query("dushen/init_time")<cd)
			return notify_fail("你刚刚使用过毒神附体，现在还没有完全恢复过来。\n");
        skill = me->query_skill("force");
		skill1 = me->query_skill("huagong-dafa",1);
		skill1 /= 15;
		dur_time=(me->query_skill("poison",1)/10);
		if (dur_time<60) dur_time=60;
		if (dur_time>120) dur_time=120;
		me->set("dushen/init_time",time());
		me->set("dushen/end_time",time()+dur_time);
        me->add("neili", -100);
		message_vision(BLU "$N"+BLU+"轻轻吟诵着不知名的语句，全身渐渐升腾起一片诡异的蓝雾。\n" NOR, me);
		antibusy_period=cal_antibusy_period(me);
		call_out("remove_antibusy", antibusy_period, me);
		me->set_temp("apply/cant_all_busy",1);
		me->set_temp("active_force_buffer/xingxiu-duzhang.dushen1/name", "Busy免疫");
		me->set_temp("active_force_buffer/xingxiu-duzhang.dushen1/last_time", time() + antibusy_period );                //持续时间
        me->set_temp("active_force_buffer/xingxiu-duzhang.dushen1/effect1", "所有Busy类攻击免疫");       //效果描述1  
		me->add_temp("apply/attack", skill/3);
		//加化学伤害query_temp("apply/kf_wound")
		me->add_temp("apply/kf_wound",skill1);
		me->set_temp("active_force_buffer/xingxiu-duzhang.dushen2/name", "加力");
        me->set_temp("active_force_buffer/xingxiu-duzhang.dushen2/last_time", time() + 20 );                //持续时间
        me->set_temp("active_force_buffer/xingxiu-duzhang.dushen2/effect1", "攻击命中+"+(skill/3)+"级");       //效果描述1  
		me->set_temp("active_force_buffer/xingxiu-duzhang.dushen2/effect2", "化学伤害加强+"+(skill1)+"%");       //效果描述2  	
		call_out("remove_enforce", 20, me,"a",skill/3,skill1);
		me->set_temp("apply/AllPoisonsImmune",100);
		F_POISON->empoison(me,"xx_poison2",3,"all");
        me->set_temp("dushen", 1);
		me->add_temp("apply/week_injure",75);
		me->add_temp("apply/kf_def_wound",75);
		me->add_temp("apply/kf_abs_def",25);
		me->add_temp("apply/abs_week_injure",25);
		call_out("remove_immune", 20, me,"a");
		poison_enemies(me);
        me->start_busy(2);
		return 1;
}



