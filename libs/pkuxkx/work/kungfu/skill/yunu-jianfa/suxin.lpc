//左右互搏
//write by hacky

#include <ansi.h>
#include <char.h>
#include <combat.h>
inherit NPC;
inherit F_SSERVER;

void remove_effect_suxin(object me, int amount);

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

int perform(object me, object target)
{
    int skill; 
    int i;
    int j;
	int busy_time=3;
    string msg;
    object weapon;
    mapping attack_val = ([
        "base": ([ "weapon" : "sword" ]),//基本功夫类型
        "skill" : ([ "weapon" : "yunu-jianfa" ]),//高级技能名称
        ]);

    if( !target ) target = offensive_target(me);
    if( !objectp(target) || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("「玉女素心剑法」只能对战斗中的对手使用。\n");

    if( !(me->query_temp("ignore_pfm_limit") & IGNORE_PFM_LIMIT_FAMILY) &&
        !me->query("suxin") )
        return notify_fail("没有师傅的指点，你还不会「玉女素心剑法」。\n");                        

    if( !(me->query_temp("ignore_pfm_limit") & IGNORE_PFM_LIMIT_FAMILY) &&
        me->query("hubo")!=1 )
        return notify_fail("你不会左右互搏，无法使出玉女素心剑法。\n");
    
    if( me->query_skill("yunu-jianfa",1)<120 )
        return notify_fail("你的「玉女剑法」等级不够，无法使用「玉女素心剑法」。\n");
    
    if( !(me->query_temp("ignore_pfm_limit") & IGNORE_PFM_LIMIT_FAMILY) && 
        me->query("family/family_name") !="古墓派" )
          return notify_fail("非古墓派无法施展「玉女素心剑法」！\n");
    
    if( (int)me->query("neili") < 300 )
        return notify_fail("你的内力不够，无法施展「玉女素心剑法」。\n");

    if ( !objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword" )
        return notify_fail("你右手无剑，如何使得「玉女素心」？\n");
    if ( !objectp(weapon = me->query_temp("secondary_weapon")) || (string)weapon->query("skill_type") != "sword" )
        return notify_fail("你左手无剑，如何使得「玉女素心」？\n");

    if( (int)me->query_temp("yunv") ) 
        return notify_fail("你已经发动了玉女素心！\n");

    me->set_temp("yunv", 1);
    me->add("neili", -200);

    skill =(int)me->query_skill("yunu-jianfa",1);
    if (skill>=700) j=4;
    else j=3;
    skill+=(int)me->query_skill("sword",1)/2;
    skill+=(int)me->query_skill("yunu-xinfa",1)/4;
    me->add_temp("apply/attack", skill/4);
    me->add_temp("apply/damage", skill/4);
   if ( me->query("family/family_name")=="古墓派" && !me->query("chushi/done"))
	{
	 if (me->query("safari_skill/gm_xj"))
		{
		busy_time=1;
		}
	else
		{
		busy_time=2;
		}
	}
    me->start_busy(busy_time);
    me->start_call_out(__FILE__, "remove_effect_suxin", 10, me, skill); 
    me->set_temp("active_buffer/family","古墓派");
    me->set_temp("active_buffer/yunu-jianfa.suxin/name", "玉女素心剑法");                  //buff名称
    me->set_temp("active_buffer/yunu-jianfa.suxin/last_time", time() + 10 );               //持续时间
    me->set_temp("active_buffer/yunu-jianfa.suxin/effect1", "攻击命中+"+(skill/4)+"级");   //效果描述1
    me->set_temp("active_buffer/yunu-jianfa.suxin/effect2", "攻击伤害+"+(skill/4)+"点");   //效果描述2
    if( !(int)me->query_temp("can_zyhb") ) 
    {
       me->set_temp("can_zyhb", 1);
       call_out("remove_hubo", me->query_con(), me);
       me->set_temp("active_buffer/yunu-jianfa.hubo/name", "玉女素心剑法");            //buff名称
       me->set_temp("active_buffer/yunu-jianfa.hubo/last_time", time() + me->query_con() );               //持续时间
       me->set_temp("active_buffer/yunu-jianfa.hubo/effect1", "左右互搏");             //效果描述3
    }
    
    msg = RED "$N使出「玉女素心剑法」,同时默念左右互搏，向$n一阵猛刺。\n" NOR;
    message_vision(msg, me, target);

    for(i=1;(i<=(me->query_skill("yunu-jianfa",1)-90)/30)&&(i<=j);i++)
    {
        if( objectp(weapon = me->query_temp("weapon")) )
        {
            msg = HIW "$N右手出剑......\n" NOR;
            message_vision(msg, me, target);
            me->set_temp("attack_val", attack_val);
            COMBAT_D->do_attack(me, target, weapon, TYPE_SPECIAL);
        }
        me->changewield();
      
        if( objectp(weapon = me->query_temp("weapon")) )
        {
            msg = HIW "$N左手出剑......\n" NOR;
            message_vision(msg, me, target);
            me->set_temp("attack_val", attack_val);
            COMBAT_D->do_attack(me, target, weapon, TYPE_SPECIAL);
        }
        me->changewield();
    }
    return 1;                                                                   
}

void remove_effect_suxin(object me, int amount)
{
        me->add_temp("apply/attack", - amount/4);
        me->add_temp("apply/damage", - amount/4);
        me->delete_temp("active_buffer/yunu-jianfa.suxin");
        if ( sizeof(me->query_temp("active_buffer"))==1 )
          me->delete_temp("active_buffer");
        message_vision(CYN "$N的素心剑法已使用一遍，攻势暂缓，周围的人也都松了一口气。\n"NOR,me);
        me->delete_temp("yunv");
}

void remove_hubo(object me)
{
       if (!me) return;
       tell_object(me, HIY"\n你长长深呼一口气，不再左右互博出招。\n"NOR); 
       me->delete_temp("can_zyhb");
       me->delete_temp("active_buffer/yunu-jianfa.hubo");
       if ( sizeof(me->query_temp("active_buffer"))==1 )
         me->delete_temp("active_buffer");
}

