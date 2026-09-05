//筋斗 according to the novel
// by zine@pkuxkx, 2013-02
#include <ansi.h>
#include <char.h>
#include <combat.h>
#include "/kungfu/skill/shenghuo-lingfa/shenghuo.h"
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other";
}

int eff(object target,int type,int dur)
{
	int eff;

	if(!objectp(target)) return 0;

	target->set_temp("mj_jindou_eff",type);
  switch (type)
  {
  case 1:
		eff = (int)target->query_dex();
		target->add_temp("apply/dodge", eff);
        target->set_temp("active_buffer/family","明教");
        target->set_temp("active_buffer/shenghuo-lingfa.jindou/name", "圣火令法.筋斗");                  //buff名称
        target->set_temp("active_buffer/shenghuo-lingfa.jindou/last_time", time() + dur );               //持续时间
        target->set_temp("active_buffer/shenghuo-lingfa.jindou/effect1", "轻功技能+"+eff+"级");   //效果描述1
		call_out("remove_eff", dur, target, eff); 

	break;
  case 2:
	  	eff = (int)target->query_skill("shenghuo-lingfa",1)/6;
		if (eff<50)
		eff=50;
		target->add_temp("apply/attack_speed", eff);
        target->set_temp("active_buffer/family","明教");
        target->set_temp("active_buffer/shenghuo-lingfa.jindou/name", "圣火令法.筋斗");                  //buff名称
        target->set_temp("active_buffer/shenghuo-lingfa.jindou/last_time", time() + dur );               //持续时间
		target->set_temp("active_buffer/shenghuo-lingfa.jindou/effect1", "攻击速度+"+eff+"%");   //效果描述1
		call_out("remove_eff", dur, target, eff); 

	 break;
  case 3:
		eff = (int)target->query_dex()/2;
		target->add_temp("apply/dodge", -eff);
        target->set_temp("active_debuff/shenghuo-lingfa.jindou/name", "圣火令法.筋斗");                       //buff名称
        target->set_temp("active_debuff/shenghuo-lingfa.jindou/last_time", time() + dur/5 );                    //持续时间
		target->set_temp("active_debuff/shenghuo-lingfa.jindou/effect1", "轻功技能-"+eff+"级");   //效果描述1
		call_out("remove_eff", dur/5, target, eff); 
	break;
  case 4:
  		eff = 500-(int)target->query_skill("parry",1)/4;
		if (eff<50)
		eff=50;
		target->add_temp("apply/attack_speed", -eff);
        target->set_temp("active_debuff/shenghuo-lingfa.jindou/name", "圣火令法.筋斗");                       //buff名称
        target->set_temp("active_debuff/shenghuo-lingfa.jindou/last_time", time() + dur/5 );                    //持续时间
		target->set_temp("active_debuff/shenghuo-lingfa.jindou/effect1", "攻击速度-"+eff+"%");   //效果描述1
		call_out("remove_eff", dur/5, target, eff); 
	 break;
  }
	/*    //	target->apply_condition("mj_jindou",dur);
	/*if ( type==1 || type==2 )
	{
        target->set_temp("active_buffer/family","明教");
        target->set_temp("active_buffer/shenghuo-lingfa.jindou/name", "圣火令法.筋斗");                  //buff名称
        target->set_temp("active_buffer/shenghuo-lingfa.jindou/last_time", time() + dur );               //持续时间
    }
    else
    {
        target->set_temp("active_debuff/shenghuo-lingfa.jindou/name", "圣火令法.筋斗");                       //buff名称
        target->set_temp("active_debuff/shenghuo-lingfa.jindou/last_time", time() + dur/5 );                    //持续时间
    }


	if (type==1)
	{
		eff = (int)target->query_dex();
		target->add_temp("apply/dodge", eff);
        target->set_temp("active_buffer/shenghuo-lingfa.jindou/effect1", "轻功技能+"+eff+"级");   //效果描述1
	}
	if (type==2)
	{
		eff = (int)target->query_skill("shenghuo-lingfa",1)/6;
		if (eff<50)
		eff=50;
		target->add_temp("apply/attack_speed", eff);
		target->set_temp("active_buffer/shenghuo-lingfa.jindou/effect1", "攻击速度+"+eff+"%");   //效果描述1
	}
	if (type==3)
	{
		eff = (int)target->query_dex()/2;
		target->add_temp("apply/dodge", -eff);
		target->set_temp("active_debuffer/shenghuo-lingfa.jindou/effect1", "轻功技能-"+eff+"级");   //效果描述1
	}
	if (type==4)
	{
		eff = 500-(int)target->query_skill("parry",1)/4;
		if (eff<50)
		eff=50;
		target->add_temp("apply/attack_speed", -eff);
		target->set_temp("active_debuffer/shenghuo-lingfa.jindou/effect1", "攻击速度-"+eff+"%");   //效果描述1
	}*/
	target->set_temp("mj_jindou_value",eff);
    return 0;
}

int remove_eff(object target, int eff)
{
	int type;
	if(!objectp(target)) return 0;

	type=target->query_temp("mj_jindou_eff");
	switch (type)
	{
	case 1:
		target->add_temp("apply/dodge", -eff);
	break;
	case 2:
		target->add_temp("apply/attack_speed", -eff);
	break;
	case 3:
		target->add_temp("apply/dodge", eff);
	break;
	case 4:
		target->add_temp("apply/attack_speed", eff);
	break;
	}
	/*if (type==1)
	target->add_temp("apply/dodge", -eff);
	if (type==2)
	target->add_temp("apply/attack_speed", -eff);
	if (type==3)
	target->add_temp("apply/dodge", eff);
	if (type==4)
	target->add_temp("apply/attack_speed", eff);*/
	target->delete_temp("mj_jindou_eff");
	target->delete_temp("mj_jindou_value");
	target->delete_temp("active_buffer/shenghuo-lingfa.jindou");
	target->delete_temp("active_debuff/shenghuo-lingfa.jindou");
	return 1;
}

int perform(object me, object target)
{
    string msg,color;
    object weapon;
    int dur,i;

    if( !target ) target = offensive_target(me);

    if( !objectp(target) || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("「圣火令法」的精髓只能在战斗中使用。\n");

    if ( (int)me->query("neili") <250)
        return notify_fail("你的内力不够，无法使出「圣火令法」的精髓！\n");

    if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "dagger")
/*    if (!objectp(weapon = me->query_temp("secondary_weapon")) || (string)weapon->query("skill_type") != "dagger") */
        return notify_fail("你右手没有匕首类武器，无法使出「圣火令法」的精髓！\n");

    if( (int)me->query_skill("guangming-shenghuogong", 1) < 150 )
        return notify_fail("你的光明圣火功等级不够，不能施展「圣火令法」的精髓！\n");

    if( !(me->query_temp("ignore_pfm_limit") & IGNORE_PFM_LIMIT_FORCE) && 
        me->query_skill_mapped("force") != "guangming-shenghuogong" )
        return notify_fail("「圣火令法」的精髓需要光明圣火功驱动内力！\n");

    if ( (int)me->query_skill("shenghuo-lingfa",1) < 100 )
        return notify_fail("你的圣火令法不够娴熟，无法使出「圣火令法」的精髓！\n");
    
    if ( me->query("env/jindou")>=1 && me->query("env/jindou")<=4 )
        i=me->query("env/jindou")-1;
    else
        i=random(4);
    
    if ( i<2 && me->query_temp("mj_jindou_eff"))
        return notify_fail("你现在正在施展「圣火令法」上的诡异武功。\n");

    if ( i>=2 && target->query_temp("mj_jindou_eff") )
        return notify_fail(target->query("name")+"已经被「圣火令法」上的诡异武功打得找不着北了。\n");

    if (custom_color(me)==NOR)
        color=BRED;
    else
        color=custom_color(me);

    msg=color+"$N"+color+"直抢而前，脚下一踬，忽然一个筋斗摔了过去。$n"+color+"咦的一声，只道$N伤后立足不定。\n哪知$N"+color+"这一招使的乃是圣火令上所载的古波斯武功，身法怪异，已达极点。\n"+NOR;
    message_vision(msg, me, target);
    dur=me->query_skill("shenghuo-lingfa",1)/2;

    if (i<2)
        eff(me,i+1,dur);
    else
        eff(target,i+1,dur);

    me->add("neili",-50);
    return 1;
}
