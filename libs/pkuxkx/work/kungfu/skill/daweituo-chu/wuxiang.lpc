// lidi.c 大韦陀杵

#include <ansi.h>
#include <char.h>
inherit F_SSERVER;

#include "/kungfu/skill/eff_msg.h";

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

int perform(object me, object target)
{
    int damage, p;
    string msg, dodge_skill;
    object weapon;

    if( !target ) target = offensive_target(me);

    if( !objectp(target) || !target->is_character() || !me->is_fighting(target) || !living(target) )
        return notify_fail("「无相无我」只能对战斗中的对手使用。\n");

    if( (int)me->query_skill("daweituo-chu", 1) < 100 )
        return notify_fail("你的大韦陀杵还不够熟练，不能使用「无相无我」！\n");

    if (!objectp(weapon = me->query_temp("weapon"))
            || (string)weapon->query("skill_type") != "staff")
        return notify_fail(RED"装备禅杖才能使用「无相无我」!\n"NOR);

    if ( !(me->query_temp("ignore_pfm_limit") & IGNORE_PFM_LIMIT_FORCE) && 
         me->query_skill_mapped("force") != "yijin-jing")
        return notify_fail("你没有使用易筋经。\n");

    if( (int)me->query("max_neili") < 1500 )
        return notify_fail("你现在内力不足，使不出大韦陀杵的绝招！\n");     

    if( (int)me->query("neili") < 400 )
        return notify_fail("你现在内力不足，使不出大韦陀杵的绝招！\n");     

    if( (int)me->query_skill("force", 1) < 150 )
        return notify_fail("你的内力不够娴熟，使不出大韦陀杵的绝招！\n");

    if (me->query_str() < 28 )
        return notify_fail("你的力量太小，使不出用「无相无我」！\n");

    if (me->query_temp("ryb_fumo"))
            return notify_fail("你现在正在使用「金刚伏魔」神功。\n");

    if (me->query_temp("ranmu"))
            return notify_fail("你现在正在使用「天火焚心」绝技。\n");

    if( me->query_temp("sl_daweituochu") )
        return notify_fail("你刚使完「大韦陀杵」绝招，目前气血翻涌，无法再次运用！\n");

    msg = RED "\n$N"RED"双手合十道：「色即是空，空即是色，无相无色，无人无我！」说完，突然暴起！\n"NOR;
    msg += HIY"\n$N怒目圆瞪，双目电闪，舌绽春雷一声大喝：戒"+BNK+HIR"    贪\n"NOR;
    msg += HIC"$N双臂肌肉坟起，手中"+weapon->query("name")+HIC"化为漫天金光，将$n"+HIC"全身笼罩其中，铺天盖地地砸了下来！\n"NOR;
    message_vision(msg, me, target); 
    msg = "";

    me->set_temp("sl_daweituochu", 1);
    call_out("remove_effect", me->query_con()/4, me);
    if ( F_KUNGFU->hit_rate(me->query_skill("force", "yijin-jing"), target->query_skill("force"), 6, me, target) ){
        me->start_busy(1);
        if( !target->is_busy()) target->start_busy(2); 
        me->add("neili", -200);
        me->add("jing", -20);
        damage = (int)me->query_skill("daweituo-chu", 1);                
        damage = damage*2 + random(damage);
        if(me->query("neili") > target->query("neili")*2 ) damage += random(damage);
        F_KUNGFU->hit_wound("qi", damage, damage/2, me, target);
        msg += damage_msg(damage, "内伤");
        message_vision(msg, me, target); 
        COMBAT_D->report_status(target);
        call_out("perform2", 0, me, target, p);    
    } 
    else {
        me->start_busy(2);
        if( !target->is_busy()) target->start_busy(1);
        me->add("neili", -100);
        tell_object(target, HIY"你看着漫天砸来的"+weapon->query("name")+HIY"，呼吸不为一窒，连忙收回所有攻势，手忙脚乱的全力防御，险险熬了过去。\n" NOR);
        dodge_skill = target->query_skill_mapped("dodge");
        if( !dodge_skill ) dodge_skill = "dodge";
    }
    
    return 1;
}

int perform2(object me, object target, int p)
{       
    object weapon;
    int damage;
    string msg, dodge_skill;
    
    if ( !objectp(me) ) return 1;
    weapon = me->query_temp("weapon");
    
    if ( !objectp(target) ) return 1;

    if ( !objectp(weapon) || (string)weapon->query("skill_type") != "staff" )
        return notify_fail("你的手中已经没有合适的武器，不能使出「无相无我」的绝技。\n");

    if ( !target->is_fighting(me) )
       return notify_fail("对手都举手投降了，你还那么狠心干什么？");

    if ( !living(target) ) 
        return notify_fail("对手已经不能再战斗了。\n");

    if( (int)me->query("neili", 1) < 500 )
        return notify_fail("你待要再出一杖，却发现自己的内力不够了！\n");     

    msg = HIY"\n$N杖势略收，雷鸣般的声音透过重重杖影滚滚而来：定"+BNK+HIR"    嗔\n"NOR;
        msg += HIC"正当$n"HIC"手忙脚乱之际，$N将漫天光影一收，"+weapon->query("name")+HIC"化为一道精芒当头砸下！\n"NOR;

    if ( F_KUNGFU->hit_rate(me->query_skill("force", "yijin-jing"), target->query_skill("force"), 4, me, target)
       && me->query_skill("daweituo-chu", 1) > 124 ) {
        me->start_busy(1);
        if( !target->is_busy()) target->start_busy(2);
        me->add("neili", -300);
        me->add("jing", -30);                
        damage = (int)me->query_skill("daweituo-chu", 1);                
        damage = damage*3 + random(damage)*2;
        if(me->query("neili") > target->query("neili")*2 ) damage += random(damage);
        F_KUNGFU->hit_wound("qi", damage, damage/2, me, target);
        msg += damage_msg(damage, "内伤");
        call_out("perform3", 0, me, target, p);  
    } 
    else {
        me->start_busy(2);
        me->add("neili", -200);
        tell_object(target, HIY"你吓得魂飞天外，就地一个懒驴打滚避了开来，"+weapon->query("name")+HIY"擦着你的脑袋中中地砸在了地上，溅起漫天碎石！\n" NOR);
        dodge_skill = target->query_skill_mapped("dodge");
        if( !dodge_skill ) dodge_skill = "dodge";
        msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
    }
    message_vision(msg, me, target); 
    COMBAT_D->report_status(target);
    return 1;
}

int perform3(object me, object target, int p)
{
    object weapon;
    int damage;
    string msg, dodge_skill;

    if ( !objectp(target) ||!objectp(me) ) return 1;
    
    weapon=me->query_temp("weapon");

    if(!objectp(weapon) || (string)weapon->query("skill_type") != "staff")
    {
        return notify_fail("你的手中已经没有合适的武器，不能使出无相无我的绝技。\n");
    }

    if (!target->is_fighting(me)){
        return notify_fail("对手都举手投降了，你还那么狠心干什么？");
    }

    if(!living(target)){
        return notify_fail("对手已经不能再战斗了。\n");
    }

    if( (int)me->query("neili", 1) < 700 )
        return notify_fail("你待要再出一杖，却发现自己的内力不够了！\n");     

    msg = HIY"\n$N满脸悲苦，无比沉重地从口中吐出两个字：破"+BNK+HIR"    痴\n"NOR;
        msg += HIC"$N将"+weapon->query("name")+HIC"收了回来，长吸一口气，浑身顿时如爆豆般噼啪作响，吐气开声，
"+weapon->query("name")+HIC"突然暴起，中宫直入，以雷霆万钧之势朝$n"HIC"胸口袭去！\n"NOR;
   
        if ( F_KUNGFU->hit_rate(me->query_skill("force", "yijin-jing"), target->query_skill("force"), 4, me, target)
      && me->query_skill("daweituo-chu", 1) > 149 ){
        me->start_busy(2);
        if( !target->is_busy()) target->start_busy(random(3));
        me->add("neili", -400);
        me->add("jing", -40);                
        damage = (int)me->query_skill("daweituo-chu", 1);                
        damage = damage*5 + random(damage)*2;
        if(me->query("neili") > target->query("neili")*2 ) damage += random(damage);
        F_KUNGFU->hit_wound("qi", damage, damage/2, me, target);
        msg += damage_msg(damage, "瘀伤");
    } else {
        me->start_busy(2);
        if( !target->is_busy()) target->start_busy(1);
        me->add("neili", -300);
        target->receive_damage("jing", 100, me);
        tell_object(target, HIY"你一声暴喝，提起毕生功力全力招架，「锵！」地一声巨响，借着力道飘然狂退三丈，双臂已然毫无知觉，却将这招硬接了下来！\n" NOR);
        dodge_skill = target->query_skill_mapped("dodge");
        if( !dodge_skill ) dodge_skill = "dodge";
        msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
    }
    message_vision(msg, me, target);
    COMBAT_D->report_status(target);
    return 1;
}

void remove_effect(object me)
{
    if (!me) return;
    me->delete_temp("sl_daweituochu");
    tell_object(me, HIC"\n你经过一段时间调气养息，又可以使用「无相无我」绝招了。\n"NOR); 
}

