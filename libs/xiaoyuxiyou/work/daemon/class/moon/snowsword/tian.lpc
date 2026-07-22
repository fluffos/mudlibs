// 漫天飞雪 Tian.c
// Last updated By 凌惊雪 12-14-2002
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int valid_perform(object me)
{
	if( me->query_level()<6 )
		return notify_fail("你的人物等级不够。\n");
	if( (int)me->query("force") < 300 )
 		return notify_fail("你的真气不够！\n");
	if( (int)me->query_skill("snowsword", 1) <60)
		return notify_fail("你的风回雪舞剑法级别还不够，使用这一招会有困难！\n");
	if( (int)me->query_skill("moonforce", 1) < 60)
		return notify_fail("你的圆月心法修为不够，使用这一招会有困难！\n");
	if( (int)me->query_skill("moondance", 1) < 60)
		return notify_fail("你的冷月凝香舞级别还不够，使用这一招会有困难！\n");
	return 1;	
}

int perform(object me, object target)
{
	object weapon;
	string str,msg,desc_msg="";
	int snowsword,moonforce,moondance,p,damage,num,ini_attack_apply,pp;
	int sword_level;

	if( !valid_perform(me) )
		return 0;
	
	snowsword = (int)me->query_skill("snowsword", 1);
	moonforce = (int)me->query_skill("moonforce", 1);
	moondance = (int)me->query_skill("moondance", 1);
	weapon = me->query_temp("weapon");
	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character()
	 || target->is_corpse() || target==me
	 || !me->is_fighting(target) )
		return notify_fail("你要对谁施展「漫天飞雪」？\n");
	
	sword_level=(int)(snowsword/50);

	if( time()-(int)me->query_temp("wuxue_end") < 6 )
		return notify_fail("绝招用多就不灵了！\n");
	
	if( (!me->query("family/family_name") || me->query("family/family_name")!="月宫")
         && me->query("chushi/chushi_moon")!="yes" )
		num = 1;
	else if(( me->query("force_factor") > 0)) 
		num = 2;
	else	num = 3;
	if( sword_level <= 1 ) 
		desc_msg = "" ; 
	else	desc_msg = chinese_number(sword_level);
  	if( sword_level > 9 ) 
  		desc_msg = "百";

	ini_attack_apply = me->query_temp("apply/attack");
	me->set_temp("wuxue_end",time());
	me->add("force",-30);
	pp = me->query_skill("sword");
	p = 0;
	// 外门招式
	if( num==1 )
	{
		msg = HIC"\n$N"HIC"轻啸一声，一招燕子凌烟，身体一个翻腾已在九空之外，紧跟着$N"HIC"在半空中一个折腰，同时手腕一转，"HIW"剑光"HIC"闪动幻作"HIW"漫天飞雪"HIC"从半空中狂卷向$n"HIC"。\n"NOR;
		me->set_temp("pfm_msg",1);
		damage = COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg);
		if( damage<1 )
			p+= pp/10;
		damage = COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,0,0,0,p);
		if( damage>0 )
			p = 0;
		else	p+= pp/3;
		COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,0,0,0,p);
		me->delete_temp("pfm_msg");
		return 1;
	}
////////// 月宫本门招式
	message_combatd(HIC"\n$N"HIC"轻啸一声，一招燕子凌烟，身体一个翻腾已在九空之外，紧跟着$N在半空中一个折腰，同时手腕接连"HIR"三"HIC"转，"HIW"剑光"HIC"闪动幻作"HIW"漫天飞雪"HIC"从半空中狂卷向$n"HIC"。\n"NOR,me,target);
	msg = HIW"$N"HIW"身形飘舞，抖手间使出了风回雪舞剑的前三招，一片剑芒似一片雪花般飘向$n"HIW"。\n"NOR;
	me->set_temp("pfm_msg",1);	
	me->set_temp("WX_perform", 1);
	damage = COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg);
	if( damage<1 )
		p+= pp/2;
	me->set_temp("WX_perform", 2);
	damage = COMBAT_D->do_attack(me, target, me->query_temp("weapon"),TYPE_PERFORM,0,0,0,p);
	if( damage<1 )
		p+= pp;
	else	p = 0;	
	me->set_temp("WX_perform", 3);	
	damage = COMBAT_D->do_attack(me, target, me->query_temp("weapon"),TYPE_PERFORM,0,0,0,p);
	if( snowsword <100 || moonforce<100 || moondance<100 || num!=3 || me->query("force")<30 )
	{
		me->delete_temp("pfm_msg");
		return 1;
	}
	me->add("force",-30);
	msg = HIC"\n$N"HIC"右脚在半空中连点，身形又陡的拔起了三丈，剑光在空中狂爆，如雨一般撒了下来！\n"NOR;
	if( damage<1 )
		p+= pp*3/2;
	else	p = 0;	
	me->set_temp("WX_perform", 4);
	damage = COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg,0,0,p);
	if( damage<1 )
	{
		p+= pp*5/4;
		me->add_temp("apply/attack",10);
	}
	else	p = 0;
	me->set_temp("WX_perform", 5);
	damage = COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,0,0,0,p);
	if( snowsword<150 || moonforce<150 || moondance<150 || num!=3 || me->query("force")<30 )
	{
		me->delete_temp("WX_perform");	
		me->set_temp("apply/attck",ini_attack_apply);
		me->delete_temp("pfm_msg");
		return 1;
	}
	me->add("force",-30);
	msg = HIG"\n$N"HIG"在空中袍袖连摆，似仙女下凡，$n"HIG"正看的入迷，两招凌厉无匹的剑招已罩了下来！正是回风雪舞剑的精华！\n"NOR;
	if( damage<1 )
	{
		p+= pp*2;
		me->add_temp("apply/attack",moondance/10);
	}
	else	p = 0;
	me->set_temp("WX_perform",6);	
	damage = COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg,0,0,p);
	if( damage<1 )
		me->add_temp("apply/attack",moondance/5);
	me->set_temp("WX_perform",7);		
	damage = COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM);
	if( snowsword<350 || moonforce<350 || moondance<350 || num!=3 || me->query("force")<30 ) 
	{
		me->delete_temp("WX_perform");	
		me->set_temp("apply/attck",ini_attack_apply);
		me->delete_temp("pfm_msg");
		return 1;
	}
	me->add("force",-30);
	me->delete_temp("pfm_msg");
	me->delete_temp("WX_perform");	
	msg = HIW"\n$N"HIW"一套回风雪舞剑舞罢，但觉剑意勃发难以抑制，掌中$w"HIW"铮鸣不绝，发出炫目光芒，直射$n"HIW"面门要害！\n"NOR;
	if( damage<1 )
		me->add_temp("apply/attack",moondance);
	COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg,0,"头部");
	me->set_temp("apply/attck",ini_attack_apply);
	
	if( target 
	&& (target->query("eff_kee")<0 || (!living(target) && target->query("kee")<0) ) )
	{
		str = target->name()+NOR+HIM"被"+me->name()+NOR+HIM"用月宫绝招「"NOR+GRNMAG"漫天飞雪"NOR+HIM"」杀死了，听说尸体上有"+desc_msg+"十多道深可见骨的伤痕！"NOR;
		if( time()>=me->query("channel/last_chat")+600 )
		{
			me->set("channel/last_chat",time());
			CHANNEL_D->do_channel(this_object(),"rumor",str);		
		}
	}
	return 1;
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        外功名称：漫天飞雪
        外功所属：回风雪舞剑
        外功效果：对敌连续进行三次攻击，如上一击未命中则下一击伤害叠加。
        	  外功需求技能达100级增加2次攻击，内力消耗增加30点
        	  外功需求技能达150级增加2次攻击，内力消耗增加30点
        	  外功需求技能达350级增加1次要害攻击，内力消耗增加30点
        	  非月宫(不包括出师)或加力大于0只能发出前三招
        	  化狐状态下使用，伤害加倍
                  使用后冷却6秒
        外功条件：
        	  人物等级6级
                  内力300点，消耗30点
                  风回雪舞剑 60 级
                  圆月心法   60 级
                  冷月凝香舞 60 级
                  
STR;
        me->start_more(str);
        return 1;
}
