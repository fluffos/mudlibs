// gangrou.c

inherit F_SSERVER;
inherit YIZHAOYUN;
#include <ansi.h>
#include <char.h>
#include <combat.h>
#include "/kungfu/skill/eff_msg.h";

int main(object me, object target);
int hurt(object me, object target, int damage, int pflv);

string perform_name() { return HIR"太极刚柔"NOR; }

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

int perform(object me, object target)
{
        if( !target ) target = offensive_target(me);

        if( !objectp(target) || !target->is_character() || !me->is_fighting(target) || !living(target))
                return notify_fail("「太极刚柔」只能对战斗中的对手使用。\n");

/*        if( userp(me)  && me->query_skill_mapped("parry") != "taiji-quan" )
                return notify_fail("「太极刚柔」必须在用太极拳激发招架的情况下才能使用。\n");

        if( userp(me) && (me->query_skill_mapped("force") != "taiji-shengong" || me->query_skill_prepared("cuff") != "taiji-quan") )
                return notify_fail("你的内功或拳法不对，根本不能发挥出「太极刚柔」的优势。\n"); */

        if( !(me->query_temp("ignore_pfm_limit") & IGNORE_PFM_LIMIT_FAMILY) && 
            userp(me) && (me->query_skill_mapped("force") != "taiji-shengong" ) )
            return notify_fail("你的内功不对，根本不能发挥出「太极刚柔」的优势。\n");

        if( !me->query("taiji") )
                if( !me->query_temp("tjht") || me->query_skill("taiji-quan", 1) < 180 )
                        return notify_fail("「太极刚柔」需先求自保心脉，你没有运用「太极护体」，又如何能静心心使用「太极刚柔」？\n");

        if( (int)me->query("neili", 1) < 1000 )
                return notify_fail("你现在真气不够，强行使用「太极刚柔」是发挥不了它的威力的！\n");

        if ( target->query_temp("tjq/gr") )
                return notify_fail("对方已被「太极刚柔」柔劲抚到！\n");

        return (int)call_other( this_object(), "main", me, target);
}

int main(object me, object target)
{
        int damage = 1, j, pflv;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !objectp(target) || !target->is_character() || !me->is_fighting(target) || !living(target)
            || me->query("neili") < 1000 || me->query("jingli") < 100 )
        {
             write("你目前用不了「太极刚柔」。\n");
             return 1;
        }

        msg = HIB"\n$N使出太极拳中"RED"「太极刚柔」"HIB"的功夫，";

        if( me->query_skill("taiji-quan", 1) > 500 ){
                 msg += "右手一掌拍向$n，中和元气，拳路随意所之，意之所向，变化犹龙！\n人莫能测，运用在心，此是太极真诀！\n"NOR;
                 damage = 2;
        }else{
                 msg += "右手一翻，拍向$n！\n"NOR;
                 damage = 1;
        }

		pflv = (int)me->query("purefamily/level");
		if (pflv>0 && me->query("purefamily/family_name") != "武当派")
			pflv = 0;

		me->add("neili", -100);
        me->start_busy(1);
        if(!target->is_busy()) target->start_busy(1);
//两边福源相同的时候命中率为C-级别，随着自身的福源比对方的福源越大，命中率越高，否则越低
        if( F_KUNGFU->hit_rate(me->query("combat_exp"), target->query("combat_exp"), (50*target->query_kar()/me->query_kar())/5-1, me, target)
           && !me->query("betrayer")){
                msg += HIY"$n眼见$P攻来，嘿嘿一笑，抬手就封住了$N这一掌！\n"NOR;
                me->add("neili", -me->query_skill("taiji-quan", 1)/2);
                target->set_temp("tjq/gr", 1);
                call_out("hurt", ((pflv>=3)?(7-pflv):5), me, target, damage, pflv);
        }
//命中率级别B-级别
        else if( F_KUNGFU->hit_rate(me->query("combat_exp"), target->query("combat_exp"), 6, me, target) ) {
                damage *= (me->query_skill("taiji-quan") + me->query("jiali"));
                F_KUNGFU->hit_wound("qi", damage, damage/4, me, target);
                msg += damage_msg(damage, "内伤");
                me->add("neili", -me->query_skill("taiji-quan", 1)/3);
        }
        else{
                msg += HIY"可是$p经验老到，脚下一退，闪开了「太极刚柔」！\n"NOR;
        }
        message_vision(msg, me, target);
        COMBAT_D->report_status(target);

        if (me->query("neili") < 0) me->set("neili",0);
        me->start_busy(2+random(2));

        return 1;
}


int hurt(object me, object target, int damage, int pflv)
{
        string msg;
        int p;

        if( target ) target->delete_temp("tjq/gr");
        if( !target || !target->is_character() || !me->is_fighting(target) || !living(target))
              return 0;

        msg = HIR"突然$N全身一震，气息翻腾，原来是被「太极刚柔」左手的柔劲抚到了！\n"NOR;
        if( F_KUNGFU->hit_rate(me->query_skill("force", "taiji-shengong"), target->query_skill("force"), 14, me, target)
          && me->query("jiali") > 100){
              tell_object(target, "你猛然发觉自己真气已然枯竭耗尽，无法运劲相抗了！\n");
              msg += RED"结果只见$N猛地口中鲜血狂喷，全身骨骼碎裂，眼见是活不成了！！\n"NOR;
              message_vision(msg, target);
              // target->set_temp("last_damage_from", me);
              // target->unconcious();
			  damage = target->query("qi");
              F_KUNGFU->hit_wound("qi", damage, damage/2, me, target);
              yizhaoyun(target, me);
        }
        else{
              tell_object(target, "你提一口真气，慌忙运劲相抗了！\n");
              msg += RED"结果只见$N全身一震，口中鲜血，显然内伤不轻！！\n"NOR;
              damage = (damage+1)*(me->query_skill("taiji-quan") + me->query("jiali"));
              damage += random(damage/2);
			  if (pflv>=3)
				  damage += damage*(pflv-2)/20;
              F_KUNGFU->hit_wound("qi", damage, damage/2, me, target);
              message_vision(msg, target);
              COMBAT_D->report_status(target);
        }
        return 1;
}

