// feijiane.c for huashan-jianfa by Jpei
// busy控制，如果点穴成功busy取大值，自己busy取小值，给机会继续feijian。

#include <ansi.h>
#include "/kungfu/skill/eff_msg.h";
inherit F_SSERVER;

string *xue_name = ({
"玉堂穴","大横穴","幽门穴","章门穴","晴明穴","紫宫穴","风池穴","百汇穴","太阳穴","长强穴","灵台穴"
});

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

int perform(object me, object target)
{       
        object weapon = me->query_temp("weapon");

		if (me->query("huashan_newskills/jianzong")) return notify_fail("这是气宗的武学，剑宗弟子不屑使用。\n");
        
        if( !target ) target = offensive_target(me);
        if( !objectp(target) || !target->is_fighting(me) )
                return notify_fail("「飞剑」只能对战斗中的对手使用。\n");

        if (!objectp(weapon) || weapon->query("skill_type") != "sword" )
/*         || me->query_skill_mapped("sword") != "huashan-jianfa") */
                return notify_fail("你需要装备剑类武器才能使用「飞剑」。\n");

        if((int)me->query_skill("huashan-jianfa", 1) < 180
         ||(int)me->query_skill("sword", 1) < 180
         ||(int)me->query_str() < 30   
         ||(int)me->query_dex() < 30)  
                return notify_fail("你有的功夫还不够娴熟，不会使用「飞剑」。\n");

        if((int)me->query_skill("zixia-shengong", 1) < 180 || (int)me->query_skill("huashan-neigong", 1) < 180)
                return notify_fail("你的内功修为不够，无法领悟「飞剑」的精髓。\n");

        if( (int)me->query("max_neili") < 2000 )
                return notify_fail("你的内力太弱，无法使用出「飞剑」！\n");
        
        if( (int)me->query("neili") < 1200 )
                return notify_fail("你的真气不够！\n");

        if(me->query_temp("hs/feijian"))
                return notify_fail("你正在使用飞剑攻击！\n");

        me->start_perform(5, "飞剑");
        me->set_temp("hs/feijian",1);
        message_vision(HIC"\n$N右手剑锋一转，手中"+weapon->query("name")+HIC"直斗，越舞越快，顿时使$P被一片剑辉所笼罩！\n"NOR, me, target);
        call_out("fj_perform", 1, me , target, weapon, random(4));
        return 1;
}

int fj_perform(object me, object target, object weapon, int pfm)
{
        string name, msg, *limbs;
        int damage = 10;
        int bt;

        bt = me->query("betrayer");
        
        me->delete_temp("hs/feijian");
        if( !me || !target || !weapon ) return 0;
        if( !living(me) || !living(target) ) return 0;
        if( environment(me) != environment(target) ) return 0;
        if( !me->is_fighting(target) ) return 0;
        if( me->query_temp("weapon") != weapon) return 0;
        
        if( me->query("combat_exp") > target->query("combat_exp")/2 )
                damage = 20;
        if( me->query("combat_exp") > target->query("combat_exp")/2 * 3 )
                damage = 15;
        if( target->is_busy() ) damage += 10;
        me->add("neili", -200);
        switch(pfm){
                case 0:
                        name = xue_name[random(sizeof(xue_name))];  
                        msg = HIG"\n当中突然飞出一支剑芒，奔向$n的"+name+"，";
                        me->start_perform(5, "紫霞剑芒");
        
                        if ( F_KUNGFU->hit_rate( me->query_skill("dodge")/10 * damage, target->query_skill("dodge"), 9, me, target )
                        && me->query("combat_exp") > target->query("combat_exp")*(1+bt)/2 ){
                                msg += HIR "结果$n一不留神被点中穴道，只觉得全身气脉通道阻塞，真气立受干挠！\n"NOR; 
                                if (!target->is_busy())
                                  F_KUNGFU->hit_busy( "dianxue", 4+random(3), target );
                                if( me->query_skill("huashan-jianfa", 1) > 150 && (int)me->query("neili") > 400 )
                                  call_out("fj_perform", 2, me , target, weapon, 2);
                        }
                        else {
                                msg += "其速快绝无比！\n"NOR;
                                name = target->query_skill_mapped("dodge");
                                if( !name ) name = "dodge";
                                msg += SKILL_D(name)->query_dodge_msg(target, 1);
                        }
                        message_vision(msg, me, target);
                        break;
                case 1:
                        me->start_perform(5, "紫霞飞剑");
                        msg = HIM"\n一时间$P身前剑光爆闪，数道光亮飞出，如天外流星，直向$p$l处刺去！\n"NOR;
                        limbs = target->query("limbs");
                        msg = replace_string(msg, "$l", limbs[random(sizeof(limbs))]);
                        msg = replace_string(msg, "$w", weapon->name()); 
                        message_vision(msg, me, target);
                        msg = "";
                        if( F_KUNGFU->hit_rate( me->query_str()/10*damage , target->query_str(), 9+9*bt, me, target ) ) {
                                damage *= (int)me->query_skill("sword", "huashan-jianfa") + (int)me->query_skill("force", 1);
                                damage /= 5;
                                if( damage > 3000 ) damage = 3000;
                                F_KUNGFU->hit_wound("qi", damage, damage/2, me, target);
                                msg += damage_msg(damage, "刺伤");
                                limbs = target->query("limbs");
                                msg = replace_string(msg, "$l", limbs[random(sizeof(limbs))]);
                                msg = replace_string(msg, "$w", weapon->name()); 
                                message_vision(msg, me, target);
                                COMBAT_D->report_status(target);
                        }
                        else { 
                                name = target->query_skill_mapped("dodge");
                                if( !name ) name = "dodge";
                                msg += SKILL_D(name)->query_dodge_msg(target, 1);
                                message_vision(msg, me, target);
                        }
                        
                        break;
                case 2:
                        me->start_perform(4, "夺命三仙剑");
                        msg = HIW"\n紧跟着$P身前剑辉爆涨，扫向$n，正是剑宗绝技"HIR"「夺命三仙剑」"HIW"，连环数剑奋力击出！\n"NOR;
                        message_vision(msg, me, target);
                        me->add_temp("apply/attack", me->query("int")*damage/((1+bt)*3));
                        me->add_temp("apply/damage", me->query("int")*damage/((1+bt)*3));
                        COMBAT_D->do_attack(me, target, weapon, 1);
                        if( me->is_fighting(target) )
                                COMBAT_D->do_attack(me, target, weapon, 1);
                        if( me->is_fighting(target) )
                                COMBAT_D->do_attack(me, target, weapon, 1);
                        me->add_temp("apply/attack", -me->query("int")*damage/((1+bt)*3));
                        me->add_temp("apply/damage", -me->query("int")*damage/((1+bt)*3));
                        break;
                case 3:
                        msg = HIC"\n当中$P手中剑光一晃，在$n惊魂未定时，直奔$p丹田而去，";
                        me->start_perform(5, "紫霞剑气");        
                        if ( F_KUNGFU->hit_rate( me->query_skill("sword", "huashan-jianfa") /10 * damage , target->query_skill("parry"), 9, me, target )
                        && me->query("combat_exp") > target->query("combat_exp")/2 ){
                                msg += HIR "结果一击中的，$n全身一震，提不起劲来了！\n"NOR; 
                                target->delete("jiali");
                                target->add("neili", -(int)me->query_skill("sword"));
                                if(random(me->query_skill("huashan-jianfa", 1)) > 250 && (int)me->query("neili") > 400)
                                        call_out("fj_perform", 2, me , target, weapon, 1);
                        }
                        else {
                                msg += "看来是想破掉$p的气门！\n"NOR;
                                name = target->query_skill_mapped("dodge");
                                if( !name ) name = "dodge";
                                msg += SKILL_D(name)->query_dodge_msg(target, 1);
                        }
                        message_vision(msg, me, target);
                        break;
                default: 
                	error("错误的招式模式："+pfm+"，请找wiz解决问题。");
        }
        
        me->start_busy(2+random(3));
        return 1;
}
