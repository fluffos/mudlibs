// sanhui 「亢龙三悔」
// modified by jpei, refer to taiji-zhao & wuying-jian
/*
　　萧峰心下又是痛惜，又是愤怒，当即大步迈出，左手一划，右手呼的一掌，便
向丁春秋击去，正是降龙十八掌的一招“亢龙有悔”，他出掌之时，与丁春秋相距
尚有十五六丈，但说到便到，力自掌生之际，两个相距已不过七八丈。

　　天下武术之中，任你掌力再强，也决无一掌可击到五丈以外的。丁春秋素闻“
北乔峰，南慕容”的大名，对他决无半点小觑之心，然见他在十五八丈之外出掌，
万料不到此掌是针对自己而发。殊不料萧峰一掌既出，身子已抢到离他三四丈外，
又是一招“亢龙有悔”，后掌推前掌，双掌力道并在一起，排山倒海的压将过来。

　　只一瞬之间，丁春秋便觉气息窒滞，对方掌力竟如怒潮狂涌，势不可当，双如
是一堵无形的高墙，向自己身前疾冲。他大惊之下，哪里还有余裕筹思对策，但知
若是单掌出迎，势必臂断腕折，说不定全身筋骨尽碎，百忙中将阿紫向上急抛，双
掌连划三个半圆护住身前，同时足尖着力，飘身后退。

　　萧峰跟着又是一招“亢龙有悔”，前招掌力未消，次招掌力又到。丁春秋不敢
正面直撄其锋，右掌斜斜挥出，也萧峰掌力的偏势一触，但觉右臂酸麻，胸中气息
登时沉浊，当即乘势纵出三丈之外，唯恐敌人又再追击，竖掌当胸，暗暗将毒气凝
到掌上。萧峰轻伸猿臂，将从半空中附下的阿紫接住，随手解开了她的穴道。
*/

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        string msg;
        int damage, spflg;
        int m_force, t_force, m_skill, t_skill;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() ||  !me->is_fighting(target) )
                return notify_fail("「亢龙三悔」只能对战斗中的对手使用。\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("「亢龙三悔」只能空手运用。\n");

        if(userp(me) && me->query("family/family_name") != "丐帮" && me->query("chushi/last_family") != "丐帮" )
                return notify_fail("你是哪儿偷学来的武功！\n");
        if( me->query_str() < 50 )
                return notify_fail("你的力量不足以施展「亢龙三悔」！\n");

        if( me->query_dex() < 50 )
                return notify_fail("你的身法不足以施展「亢龙三悔」！\n");

        if( me->query_skill_mapped("force") != "huntian-qigong" )
                return notify_fail("你所用的内功与「亢龙三悔」气路相悖！\n");

        if( me->query_skill("huntian-qigong", 1) < 250 )
                return notify_fail("你的混天气功火候未到，无法施展「亢龙三悔」！\n");

        if( me->query_skill("xianglong-zhang", 1) < 250 )
                return notify_fail("你降龙十八掌不够娴熟，无法施展「亢龙三悔」！\n");

        if( (int)me->query("max_neili", 1) < 5000 )
                return notify_fail("你的内力修为不够，无力施展「亢龙三悔」！\n");

        if( me->query("neili") < 3000 )
                return notify_fail("你现在的内力太弱，不够使用「亢龙三悔」！\n");

        if( me->query_temp("sanhui") )
                return notify_fail("你内力尚未调息完毕，无法动用大量内力。\n");

        m_force = me->query_skill("huntian-qigong",1) + me->query_skill("force",1);
        t_force = target->query_skill("force");
        m_skill = me->query_skill("xianglong-zhang",1) + me->query_skill("strike",1);
        t_skill = target->query_skill("dodge");
 
        me->set_temp("sanhui", 1);
        call_out("remove_effect", 10, me); 
        message_vision( WHT"\n$N深吸一口气，将混天真气提于胸前，大喝一声说道：“就让你见识一下天下最霸道的掌法！”\n"NOR, me);

        msg = HIR"\n只见$N大步迈出，左手一划，右掌呼的一声，便向$n击去，正是一招"HIW"「亢龙有悔」"HIR"，力自掌生，猛不可当。\n"NOR;
        message_vision(msg, me, target);
		if ( me->query("family/family_name") == "丐帮")
		{
        spflg=(int)me->query("player_special_contribute/gb");//player_special_contribute/gb是alucar获得的提供丐帮任务素材的特殊奖励，by Zine 2011/07/23
		}
		else
		{
			m_force >>=2;
			m_force *=3;
			m_skill >>= 2;
			m_skill *= 3;
			spflg=0;
		}

		//命中率调整，各调整2,2,1个命中级别 by yhzzyahoo at 2015/3/31 总共提高3,3,2命中等级
		//对非纯门派为例进行限制 by yhzzyahoo

//命中率B-
        if( F_KUNGFU->hit_rate( m_force, t_force, 7-3*spflg, me, target) ) 
        { 
                damage = m_force; 
                damage = damage + random(damage/2 + me->query("jiali")*2 );
                F_KUNGFU->hit_wound("qi", damage, damage/10+random(damage/5), me, target);
                me->add("neili", -m_force/4);
                COMBAT_D->report_status(target);
        } else {
                msg = CYN"\n$n见$N的掌力猛不可当，连忙两个空心筋斗向后翻出，这才在间不容发之际避开了这千斤一击。\n" NOR;
                message_vision(msg, me, target);
                me->add("neili", -m_force/8 );
                target->add("neili", -t_skill/5);
        }  
        if(me->query("neili") < 2000 ){
                msg = HIW"\n$N欲再来一掌，真气一提却发现所剩无几，只得怅然收掌！\n"NOR;
                message_vision(msg, me, target);
                if( !target->is_busy()) target->start_busy(1);
                me->start_busy(1);
                return 1;
        }
        msg = HIY"\n$N一掌既出，身子抢前，又是一招"HIW"「亢龙有悔」"HIY"，後掌推前掌，双掌力道并在一起，排山倒海的向$n压将过来。\n"NOR;
        message_vision(msg, me, target);
//命中率B+
        if( F_KUNGFU->hit_rate( m_skill, t_skill, 5-3*spflg, me, target) ) {       
                damage = m_skill; 
                damage = damage + random(damage/2 + me->query("jiali")*2);
                F_KUNGFU->hit_wound("qi", damage, damage/10+random(damage/5), me, target);
                me->add("neili", -m_skill/4);
                COMBAT_D->report_status(target);
        } else {
                msg = CYN"\n只一瞬之间，$n便觉气息窒滞，$N掌力竟如怒潮狂涌，势不可当，又如是一堵无形的高墙，向自己身前疾冲。\n" NOR;
                msg += CYN"$n大惊之下，哪里还有余裕筹思对策，但知若是单掌出迎，势必臂断腕折，说不定全身筋骨尽碎，双掌连划三个半圆护住身前，同时足尖着力，飘身后退。\n" NOR;
                message_vision(msg, me, target);
                me->add("neili", -m_skill/8 );
                target->add("neili", -t_skill/5);
        }

        if(me->query("neili") < 1000 ){
                msg = HIW"$N欲再来一掌，真气一提却发现所剩无几，只得怅然收掌！\n"NOR;
                message_vision(msg, me, target);
                if( !target->is_busy()) target->start_busy(1);
                me->start_busy(1);
                return 1;
        }
        msg = HIC"\n$N跟着又是一招"HIW"「亢龙有悔」"HIC"，双掌一分，竟如怒涛狂涌，势不可挡，又如一堵无形的高墙，向$n身前疾冲。\n"NOR;
        message_vision(msg, me, target);
//命中率A
        if( F_KUNGFU->hit_rate( m_skill + m_force, t_skill, 6-2*spflg, me, target) ) {       
                damage = m_force + m_skill; 
                damage = damage + random(damage/2  + me->query("jiali")*5 );
                F_KUNGFU->hit_wound("qi", damage, damage/10+random(damage/5), me, target);
                me->add("neili", -(m_force+m_skill)/6);
                COMBAT_D->report_status(target);
        } else {
                msg = CYN"\n$n不敢正面直撄其锋，右掌斜斜挥出，与$N掌力的偏势一触，但觉右臂酸麻，胸中气息登时沉浊，当即乘势纵出三丈之外，唯恐$N又再追击，竖掌当胸，暗暗将内力凝到掌上。\n" NOR;
                message_vision(msg, me, target);
                me->add("neili", -(m_force+m_skill)/10 );
                target->add("neili", -(m_skill + m_force)/6);
                if( !target->is_busy()) target->start_busy(1+random(2));
        }
        me->start_busy(3);
        target->fight_ob(me);
        return 1;
}

void remove_effect(object me)
{
        if (!me) return;
        me->delete_temp("sanhui");
        tell_object(me, HIG"\n你经过一阵运功调息，消去了胸中所凝住的一股浊气。\n"NOR); 
}

