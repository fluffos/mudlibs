//fogang.c 
//截手九式之佛光普照
//明教伤害为0（倚天屠龙记 第十八章　倚天长剑飞寒铓）
//武当少林属于以内功为本，伤害减半。

#include <ansi.h>
#include <char.h>
#include "/kungfu/skill/eff_msg.h";
#define Menpai "峨嵋派"
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

int perform(object me, object target)
{
    int damage, ap, dp, p, pflv;
    float at;
    string msg, dodge_skill;

    if( !target ) target = offensive_target(me);

    if( !objectp(target) || !target->is_character() || !me->is_fighting(target) || !living(target))
        return notify_fail("「佛光普照」只能在战斗中使用。\n");

    if( !(me->query_temp("ignore_pfm_limit") & IGNORE_PFM_LIMIT_FAMILY) && 
        !me->query("em/foguang") )
        return notify_fail("你无法使用「佛光普照」。\n");

/*    if(objectp(me->query_temp("weapon")) )
            return notify_fail("你必须空手才能使用「佛光普照」！\n"); */

    if((int)me->query_skill("linji-zhuang", 1) < 200 )
            return notify_fail("你的临济十二庄未成，不能使用「佛光普照」！\n");

    if((int)me->query("max_neili") < 3000 )
            return notify_fail("你的内力修为不足，不能使用「佛光普照」！\n");

    if((int)me->query("neili") < 1500 )
            return notify_fail("你现在内力不足，不能使用「佛光普照」！\n");

    if((int)me->query_skill("jieshou-jiushi", 1) < 200 )
            return notify_fail("你的截手九式不够娴熟，不能使用「佛光普照」。\n");

    if((int)me->query_str() < 40)
            return notify_fail("你的膂力不足，无法发挥「佛光普照」的气势。\n");

    if((int)me->query_con() < 40)
            return notify_fail("你的根骨欠佳，无法使用「佛光普照」。\n");

/*    if(me->query_skill_prepared("hand") != "jieshou-jiushi"
     || me->query_skill_mapped("hand") != "jieshou-jiushi"
     || me->query_skill_mapped("parry") != "jieshou-jiushi")
            return notify_fail("你必须全面运用截手九式，才能使用「佛光普照」。\n"); */

    if( !(me->query_temp("ignore_pfm_limit") & IGNORE_PFM_LIMIT_FORCE) && 
        me->query("family/family_name")!=Menpai && me->query("chushi/last_family")!=Menpai 
        && !(me->query("tqt/old_family") && member_array(Menpai,me->query("tqt/old_family"))!=-1)
        && me->query_skill_mapped("force") != "linji-zhuang" )
            return notify_fail("你不使用临济十二庄，怎么能使用「佛光普照」？\n");

    msg = MAG "\n只见$N面显庄严，突然间全身骨骼中发出劈劈拍拍的轻微爆裂之声，炒豆般的响声未绝，一式「"HIY"佛光普照" NOR + MAG"」，\n"+
              "提一口真气，飘身而上，半空中手掌交错，一股内劲狭带着热浪，如风如火，似雷似电，这一招拍出，\n"+
              "击向$n，招式平平淡淡，一成不变，但却挡无可挡，避无可避！\n"NOR;
    ap = (int)me->query_skill("jieshou-jiushi",1) * (int)me->query_str()/10;
    dp = (int)target->query_skill("force", 1) * (int)target->query_con()/10;
    ap *= ((int)me->query("combat_exp")/100000+1);
    dp *= ((int)target->query("combat_exp")/100000+1);
	
	pflv = (int)me->query("purefamily/level");
	if (pflv>0 && me->query("purefamily/family_name") != "峨嵋派")  pflv=0;

    me->start_busy(1);
    if( F_KUNGFU->hit_rate( ap, dp, 6, me, target) ) 
    {
        if( !target->is_busy() )  target->start_busy(random(2));
        damage = me->query_skill("hand", "jieshou-jiushi")/2 + me->query_skill("force", "linji-zhuang") + me->query("jiali") * 10;
        if(target->query("neili") < 10) at = 4;
        else at = me->query("neili") / (target->query("neili")+1);
        if(at < 1)
        {
            if(at < 0.5) damage /= 2;
            damage /= 2;
        }
        else  damage *= at;
        damage -= target->query_temp("apply/armor") * 2;
        if (damage < 50) damage = 50;
        damage = damage + random(damage / 4);
        if (target->query_skill_mapped("force") == "jiuyang-shengong" && target->query_skill("jiuyang-shengong", 1) > 200)
        {
            tell_object(me, HIY"\n哪知你一掌打在"+target->name()+"身上，却犹如江河入海，又如水乳交融，劲力登时无影无踪！\n"NOR);
            msg += "猛听得砰然一声大响，$N已打中在$n胸口，只道$p定然全身骨骼粉碎。哪知一掌过去，\n"+
                    "$n脸露讶色，竟好端端的站着，$N却是脸如死灰，手掌微微发抖！\n";
            if( !target->is_busy() ) target->start_busy(2);
            me->add("neili", - me->query_skill("force", "linji-zhuang"));
            message_vision(msg, me, target);
            return 1;
        }
        if (target->query_skill_mapped("force") == "yijin-jing" || target->query_skill_mapped("force") == "taiji-shengong")
            damage /= 2;
        if (damage > me->query_skill("force", "linji-zhuang")*10) 
            damage = me->query_skill("force", "linji-zhuang")*10 + (damage - me->query_skill("force", "linji-zhuang")*8)/100;
		if (pflv >=3 && target->query_skill_mapped("parry") == "qiankun-danuoyi")
		{
			msg += HIR"$n一惊之下，乾坤大挪移心法自然发出，和对方拍来的掌力一挡，就在两股劲力将触将离之时，\n"
					 +"$N的掌力忽然无影无踪地消失。$n一呆，猛地里胸口犹似受了铁锤一击，哇地喷出一大口鲜血。\n"
					 +"$N这一掌忽吞忽吐，闪烁不定，引开敌人内力然后再加发力，实是内家武学中精奥之极的修为！\n"NOR;
			damage += me->query_skill("force", "linji-zhuang");
			damage += damage * (pflv-2) / 5;
			F_KUNGFU->hit_wound("qi", damage, damage/2, me, target);
		}
		else
          F_KUNGFU->hit_wound("qi", damage, random(damage/2), me, target);
        target->add("neili", -damage/8);
        me->add("neili", -(me->query("jiali")+damage/10));
        msg += damage_msg(damage, "瘀伤");
    }
    else 
    {
        dodge_skill = target->query_skill_mapped("dodge");
        if( !dodge_skill ) dodge_skill = "dodge";
        msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
        me->add("neili", -300);
    }
    message_vision(msg, me, target);
    COMBAT_D->report_status(target);

    me->start_busy(3+random(3));
    return 1;
}

