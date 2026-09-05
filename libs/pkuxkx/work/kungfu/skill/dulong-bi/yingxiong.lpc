// yingxiong.c  毒龙匕法「英雄三招」
// kiden
// 加入瞎眼时间最长限制by yhzzyahoo
// 命中稍作调整 by yhzzyahoo
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
    
    if( !(me->query_temp("ignore_pfm_limit") & IGNORE_PFM_LIMIT_FAMILY) && 
        !me->query("shenlong/yingxiong"))
        return notify_fail("你还没学会「英雄三招」！\n");

    if( !target ) target = offensive_target(me);

    if( !objectp(target) || !target->is_character() || !me->is_fighting(target) || !living(target) )
        return notify_fail("「英雄三招」只能对战斗中的对手使用。\n");

    if( (int)me->query_skill("dulong-bi", 1) < 150 )
        return notify_fail("你的毒龙匕法还不够熟练，不能使用「英雄三招」对敌！\n");

    if ( !objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "dagger")
        return notify_fail(RED"装备匕首才能使用「英雄三招」!\n"NOR);

    if ( !(me->query_temp("ignore_pfm_limit") & IGNORE_PFM_LIMIT_FORCE) && 
         me->query_skill_mapped("force") != "shenlong-xinfa")
        return notify_fail("激发神龙心法才能使用「英雄三招」!\n");

    if( (int)me->query("neili") < 300 )
        return notify_fail("你现在内力不足，使不出毒龙匕法的绝招！\n");     

    if( (int)me->query_skill("force", "shenlong-xinfa") < 150 )
        return notify_fail("你的内力不够娴熟，使不出毒龙匕法的绝招！\n");

    if( me->query_temp("sl_hero") >time())
        return notify_fail("你刚刚使用过「英雄三招」，一口气还没有缓上来呢！\n");

    msg = HIB "\n$N大喝一声，"+HIR"「子胥举鼎」"+HIB"！左手轻搔$n腋底“极泉穴”，$n缩手之间已被$N抓住衣领奋力向外摔出！\n"NOR;
    message_vision(msg, me, target);
    msg = "";

    me->set_temp("sl_hero", time()+(40-me->query("dex"))/4);
//命中率级别C-
    if ( F_KUNGFU->hit_rate( me->query_skill("dodge"), target->query_skill("dodge"), 9, me, target) )
    {
        me->start_busy(1);
        me->add("neili", -100);
        me->add("jing", -20);
        damage = (int)me->query_skill("dulong-bi", 1);                
        damage = damage*2 + random(damage);
		if (target->query_temp("block_msg/all"))
		{
		    damage = damage*2;
		}
        F_KUNGFU->hit_wound("qi", damage, damage/3, me, target);
        msg += HIR"$n肘后“小海穴”和腋下“极泉穴”被制，动弹不得，被重重摔在地上，跌了个七荤八素，几欲昏去！\n"NOR;
        message_vision(msg, me, target); 
        COMBAT_D->report_status(target);
    } 
    else
    {
        me->start_busy(2);
        if(!target->is_busy()) 
        target->start_busy(1);
        me->add("neili", -100);
        msg +=HIW"$n只觉肘后“小海穴”和腋下“极泉穴”一麻，急忙运气闭住穴道，在半空中一挺身，艰难的站住。\n"NOR;
        message_vision(msg, me, target);
        call_out("perform2", 0, me, target, p);
    }
    
    return 1;
}

int perform2(object me, object target, int p)
{
    int damage;
    string msg, dodge_skill;

    if (!target || !me)	return 1;
		
    if(!living(target)) 
    {
        return notify_fail("对手已经不能再战斗了。\n");
    }

    if( (int)me->query("neili", 1) < 500 )
        return notify_fail("你的内力不够了！\n");     

    msg = HIB "\n$N见$n没有中招，并不慌乱，又大喝一声"+HIR"「鲁达拔柳」"+HIB"，乘$n站立未稳之际，急冲上前，抓向$n右脚足踝！\n"NOR;
    message_vision(msg, me, target);
    msg = "";
//命中率级别C+
    if ( F_KUNGFU->hit_rate( me->query_skill("dodge"), target->query_skill("dodge"), 7, me, target) &&
         me->query_skill("dulong-bi", 1) > 124 )
    {
        me->start_busy(1);
        me->add("neili", -100);
        me->add("jing", -30);                
        damage = (int)me->query_skill("dulong-bi", 1);                
        damage = damage*3 + random(damage)*2;
		if (target->query_temp("block_msg/all"))
		{
		    damage = damage*3/2;
		}

        F_KUNGFU->hit_wound("qi", damage, damage/2, me, target);
        msg += HIR"$n喘息未定，一惊之下，胸口“神藏”、“神封”、“步廊”等要穴已被$N踢中，只觉得痛入心肺。\n"NOR ;
        message_vision(msg, me, target);
        COMBAT_D->report_status(target);
    } 
    else 
    {
        me->start_busy(2);
        if(!target->is_busy()) 
        target->start_busy(1);
        me->add("neili", -200);
        msg += HIW"$n见势不妙，左脚踢出，右脚退后，已绕到$N身后。\n" NOR;
        dodge_skill = target->query_skill_mapped("dodge");
        if( !dodge_skill ) dodge_skill = "dodge";
        msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
        p = (int)target->query("qi")*100/(int)target->query("max_qi");
        message_vision(msg, me, target);
        call_out("perform3", 0, me, target, p);
    }
    return 1;
}

int perform3(object me, object target, int p)
{
    int damage,dur_time;
    string msg, dodge_skill;

    if (!target || !me)	return 1;

    if(!living(target))
    {
        return notify_fail("对手已经不能再战斗了。\n");
    }

    if( (int)me->query("neili", 1) < 300 )
        return notify_fail("你待要再发一招，却发现自己的内力不够了！\n");     

    msg = HIB "\n$N见$n已在身后，心中暗喜，使出"+HIR"「狄青降龙」"+HIB"，反手向$n胸口大穴抓落！\n"NOR;

    //命中率级别B+ fix by yhzzyahoo
    if ( F_KUNGFU->hit_rate( me->query_skill("dodge"), target->query_skill("dodge"), 5, me, target) &&
            me->query_skill("dulong-bi", 1) > 149 )
    {
        me->start_busy(2);
        me->add("neili", -100);
        me->add("jing", -40);                
        damage = (int)me->query_skill("dulong-bi", 1);                
        damage = damage*6 + random(2*damage);
		if ((target->query("neili") > me->query("neili")) && target->query("neili")>40000) damage += random(damage);
//        if(me->query("neili") > target->query("neili")*2 ) damage += random(damage*3/2);
		if (target->query_temp("block_msg/all"))
		{
		    damage = damage*3/2;
		}
        F_KUNGFU->hit_wound("qi", damage, damage/2, me, target);
        msg +=HIR"$n急忙侧身避让，不料$N突然一个倒翻筋斗，身子跃起，双腿一分，已跨在$n肩头，同时中指用力向$n眼睛按落！\n"NOR;    
        msg +=HIR"$n只觉得眼睛剧痛，双眼难睁，眼前一片漆黑！\n"NOR;
        message_vision(msg, me, target);
        COMBAT_D->report_status(target);
        if( !target->is_killing(me->query("id")) ) target->kill_ob(me);
        if(!target->is_busy())
          F_KUNGFU->hit_busy( "body", random(10), target ); 
		dur_time=(int)me->query_skill("dulong-bi",1)/40+random(2);
		if (dur_time>80)
		{
			dur_time=80;
		}
        call_out("set_block", 1, target);
        call_out("remove_block", dur_time, target);
    }
    else 
    {
        me->start_busy(2);
        if(!target->is_busy()) 
        target->start_busy(1);
        me->add("neili", -100);
        target->add("jing", -100);
        msg +=HIW"$n用尽全身力量向后一纵一滚，躲开了$N这致命的一击！\n" NOR;
        message_vision(msg, me, target);
    }
    return 1;
}


void remove_block(object me)
{
    if (!me || !me->query_temp("block_msg/all") || !living(me) || me->is_ghost()) return;

    me->delete_temp("block_msg/all");
    tell_object(me, HIC"\n你觉得眼前慢慢明亮，终于可以看清楚东西了！\n"NOR); 
}

void set_block(object me)
{
    if (!me || me->query_temp("block_msg/all") || !living(me) || me->is_ghost()) return;

    tell_object(me, HIY"你觉得眼前越来越模糊，终于什么也看不见了！"NOR);
    me->set_temp("block_msg/all",1);
}

