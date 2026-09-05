// 海潮汹涌
// By River 
// Modify By River@SJ 2000.2.22
#include <ansi.h>
#include <combat.h> 
inherit F_SSERVER;

string *xue_name = ({ 
"劳宫穴","膻中穴","曲池穴","关元穴","曲骨穴","中极穴","承浆穴","天突穴","百会穴",
"幽门穴","章门穴","大横穴","紫宫穴","冷渊穴","天井穴","极泉穴","清灵穴","至阳穴",
});

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

int perform(object me, object target)
{
        string msg,dodge_skill;
        int i,j;
        object weapon;
        mapping attack_val = ([
            "base": ([ "weapon" : "sword" ]),//基本功夫类型
            "skill" : ([ "weapon" : "xuantie-jian" ]),//高级技能名称
        ]);
		if( me->query("gender") =="男性"){
           i = me->query_skill("xuantie-jian", 1)/4;
           j = me->query_skill("sword", 1)/4;
        }
        else {
           i = me->query_skill("xuantie-jian", 1)/5;
           j = me->query_skill("sword", 1)/5;
        }
        weapon = me->query_temp("weapon");

        if( !target ) target = offensive_target(me);

        if( !objectp(target) || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("玄铁剑法的「海潮汹涌」只能在战斗中对对手使用。\n");

        if( !objectp(weapon) || weapon->query("skill_type") != "sword" )
                return notify_fail("你必须装备剑类武器才能使用「海潮汹涌」！\n");

        if((int)me->query_skill("xuantie-jian", 1) < 130 )
                return notify_fail("你的玄铁剑法还不够娴熟，使不出「海潮汹涌」绝技。\n");

          if((int)me->query_skill("jiuyin-shengong", 1) < 130 )
                return notify_fail("你的九阴神功等级还不够，使不出「海潮汹涌」绝技。\n");

        if((int)me->query_skill("force") < 180 )
                return notify_fail("你的内功等级不够，不能使用「海潮汹涌」。\n");

        if((int)me->query_str() < 33 )
                return notify_fail("你的膂力还不够强劲，使不出「海潮汹涌」来。\n");

        if((int)me->query("max_neili") < 500 )
                return notify_fail("你的内力还不足，使不出「海潮汹涌」来。\n");

        if((int)me->query("neili") < 500 )
                return notify_fail("你的内力还不足，使不出「海潮汹涌」来。\n");

        if( target->query_temp("xtjf/haichao") || target->is_busy())
                return notify_fail(target->name()+"正自顾不暇，你可以放心地进攻。\n");

        if( time()- target->query_temp("xiongyong")<5)
                return notify_fail(target->name()+"刚受到海潮汹涌攻击，已经有防备了。\n");

/*        if( me->query_skill_mapped("sword") != "xuantie-jian" && userp(me) )
                return notify_fail("你现在无法使用「海潮汹涌」！\n");

        if( me->query_skill_mapped("parry") != "xuantie-jian" && userp(me) )
                return notify_fail("你现在无法使用「海潮汹涌」！\n");
*/
        if((int)me->query("max_neili") < (me->query_skill("force")+j+200) )
                return notify_fail("你现在内力太弱，使不出「海潮汹涌」。\n");      

        message_vision(HIB"\n$N持"+weapon->query("name")+HIB"挟巨浪潮涌之势，剑气形成一个旋转的气涡，向$n笼罩过去。\n"NOR,me,target);
//命中率级别B-级别
        if ( F_KUNGFU->hit_rate( me->query_skill("sword","xuantie-jian"), target->query_skill("dodge"), 6, me, target ) 
         || me->query("combat_exp", 1) > target->query("combat_exp", 1)
         || !living(target)){
            message_vision(HIR"结果$n全身被剑气所形成的气涡所笼罩着，只觉得犹如身陷洪涛巨浪，跌跌撞撞。\n"NOR,me,target);
            F_KUNGFU->hit_busy( "confuse", i/9+random(2), target );
            me->add("neili", -i*3);
            if (present(target,environment(me)) && me->is_fighting(target))
			{
				me->set_temp("attack_val", attack_val);
				COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL);
			}
            me->start_perform(4, "「海潮汹涌」");
            target->set_temp("xiongyong", time());
            if((int)me->query_skill("xuantie-jian", 1) > 150
             &&(int)me->query("neili", 1) > (me->query_skill("force")+j)
             && present(target,environment(me))
             && me->is_fighting(target)){
             	 if ( objectp(weapon) )
                 message_vision(HIB"\n$N微笑不语，趁势将手中的"+weapon->query("name")+HIB"从轻而响，从响而轻，忽寂然无声，忽轰轰之声，向$n席卷而去。\n"NOR,me,target);
              if( F_KUNGFU->hit_rate( me->query_skill("sword","xuantie-jian"), target->query_skill("parry"), 6, me, target ) 
                || ! living(target)
                || me->query("combat_exp", 1) > target->query("combat_exp", 1) ){
                  me->add_temp("apply/strength", i);
                  me->add_temp("apply/attack", j);
                  me->set_temp("xtjf_pfm", 1);
				  me->set_temp("attack_val", attack_val);
                  COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL);
                  if (present(target,environment(me)) && me->is_fighting(target))
					COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL);
                  me->add_temp("apply/strength", -i);
                  me->add_temp("apply/attack", -j);
                  if(userp(me))
                     me->add("neili", -(me->query_skill("force")));
                  else
                  me->add("neili", -200);
                  me->add("jing", -100);
                  me->delete_temp("xtjf_pfm");
                  me->start_perform(6,"「海潮汹涌」");
               }
               else {
                   me->add("neili", -100);
                   dodge_skill = target->query_skill_mapped("dodge");
                   if( !dodge_skill ) dodge_skill = "dodge";
                   msg = SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
                   message_vision(msg, me, target);
               }
                //added by iszt@pkuxkx, 2006-09-21
                target->delete_temp("xtjf/haichao");
				me->delete_temp("attack_val");
               return 1;
            }
        }
        else {
               me->start_busy(2+random(2));
               me->add("neili", -100);
               dodge_skill = target->query_skill_mapped("dodge");
               if( !dodge_skill ) dodge_skill = "dodge";
               msg = SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
               message_vision(msg, me, target);
        }
	
	if( me->query_skill("xuantie-jian", 1) > 180)
        {
        if( objectp(target)
         && me->is_fighting(target)
         && !target->is_busy()
         && random(2) == 1
         && me->query_temp("weapon")){
          target->delete_temp("xtjf");
          call_out("perform2", 1, me,target); }
                }
        target->delete_temp("xtjf/haichao");
        return 1;
}


int perform2(object me,object target)
{
    string msg, dodge_skill,name;
    object weapon = me->query_temp("weapon");        
    int p;

    if( !target ) target = offensive_target(me);

    if( !objectp(target) || !me->is_fighting(target) )
    return notify_fail("你已经不用继续使用「海潮汹涌」了。\n");

    if( !objectp(weapon) || weapon->query("skill_type") != "sword" )
    return notify_fail("你必须装备剑类武器才能继续使用「海潮汹涌」！\n");

/*    if( me->query_skill_mapped("sword") != "xuantie-jian" && userp(me) )
    return notify_fail("你无法继续使用「海潮汹涌」！\n");

    if( me->query_skill_mapped("parry") != "xuantie-jian" && userp(me) )
    return notify_fail("你无法继续使用「海潮汹涌」！\n");
*/
    if((int)me->query("neili") < 1000)
    return notify_fail("你真气太弱，无法继续使出「海潮汹涌」。\n");

    if((int)me->query("jingli") < 500 )
    return notify_fail("你精力太弱，无法继续使出「海潮汹涌」。\n");

    if( me->query("gender")=="女性" )
    p = me->query_skill("force", "jiuyin-shengong") / 6;
    else
    p = me->query_skill("force", "jiuyin-shengong") / 8;

    name = xue_name[random(sizeof(xue_name))];
    msg =HIB"\n$n好不容易缓过劲来，$N身形飘忽，转了几转，移步向西，紧跟一剑刺向$n的"RED+name+HIB"。\n"NOR;
    if( me->query_kar()/2 > random(target->query_kar()))
    {
        msg += CYN"$n顿觉眼前一阵迷惑，一时不备，身上的"RED+name+CYN"已被"+weapon->name()+CYN"点中，身手顿时不那么灵便了。\n"NOR;
        if ( !objectp(target->query_temp("xtjf/haichao")) )
        {
            target->add_temp("apply/attack", -p/2);
            target->add_temp("apply/dodge", -p/2);
            target->add_temp("apply/parry", -p/2);
            target->set_temp("xtjf/haichao", me);
            target->set_temp("active_debuff/xuantie-jian.xiongyong/name", "海潮汹涌");                      //buff名称
            target->set_temp("active_debuff/xuantie-jian.xiongyong/last_time", time() + p );         //持续时间
            target->set_temp("active_debuff/xuantie-jian.xiongyong/effect1", "轻功技能-"+p/2+"级");       //效果描述1
            target->set_temp("active_debuff/xuantie-jian.xiongyong/effect2", "攻击命中-"+p/2+"级");       //效果描述2
            target->set_temp("active_debuff/xuantie-jian.xiongyong/effect3", "招架技能-"+p/2+"级");       //效果描述3
        }
        if( random(2) == 1)
        {
            if ( !target->query_condition("no_perform") )
            {
                target->apply_condition("no_perform", 1+ random(2));
                target->set_temp("xtjf/perform");
            }
        }
        else 
        {
            if ( !target->query_condition("no_exert") )
            {
                target->apply_condition("no_exert", 1+random(2));
                target->set_temp("xtjf/exert");
            }
        }
        me->add("neili", - p * 6);
        me->add("jingli", - p * 2);
        call_out("check_fight", 1, me, target, weapon, p );
    }
    else 
    {
        me->start_busy(2+random(2));
        me->add("neili", -100);
        dodge_skill = target->query_skill_mapped("dodge");
        if( !dodge_skill ) dodge_skill = "dodge";
        msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
    }
    message_vision(msg, me, target);
    me->start_perform(4,"「海潮汹涌」");
    return 1;
}

void check_fight(object me,object target,object weapon, int p)
{
    if( !objectp(target) ) return;
    if( !objectp(me) 
     || !me->is_fighting(target)
     || !me->query_temp("weapon")
     || ( me->query_temp("weapon") != weapon )
     || !objectp(weapon) 
     || weapon->query("skill_type") != "sword"
     || !present(target,environment(me)))
/*     || me->query_skill_mapped("sword") != "xuantie-jian"
     || me->query_skill_mapped("parry") != "xuantie-jian" */
    {
        if( target->query_temp("xtjf/perform") ) target->clear_condition("no_perform");
        if( target->query_temp("xtjf/exert") ) target->clear_condition("no_exert");

        if ( me == target->query_temp("xtjf/haichao") )
        {
            target->delete_temp("xtjf");
            target->add_temp("apply/attack", p/2);
            target->add_temp("apply/dodge", p/2);
            target->add_temp("apply/parry",p/2);
            target->delete_temp("active_debuff/xuantie-jian.xiongyong");
        }
        message_vision(HIW"\n$N竭力挣脱了纠缠，身形恢复了原先的矫捷。\n"NOR, target);
        return ;
    }
    call_out("check_fight", 1, me, target, weapon, p );
}
