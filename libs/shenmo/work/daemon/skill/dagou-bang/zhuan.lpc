//Cracked by Kafei
// zhuan.c 打狗棒封字决
// fear@xkx 99.12

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
inherit F_DBASE;

int perform(object me, object target)
{
        string* msghit, msg;
        object weapon;
        int zhuan_busy;
        int zhuan_cost;
        int zhuan_duration;
        string *limb, type, limb_hurt;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) 
        ||          !living (target) )
                return notify_fail("转字诀只能对战斗中的对手使用。\n");

        if( target->is_busy() ) {
                me->add("neili", -10);
                me->add("jing", -5);
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧　\n");
        }

        if( me->query_temp("ban",1) )
                return notify_fail("你已在使用拌字诀！\n");

        if( me->query_temp("pfmfeng",1) )
                return notify_fail("你已在使用封字诀！\n");

        if( me->query_temp("zhuan",1) )
                return notify_fail("你已在使用转字诀！\n");

        if( me->query_skill_mapped("force") != "huntian-qigong" )
                return notify_fail("你所用的并非混天气功，无法施展封字诀！\n");

        if( me->query_skill("huntian-qigong") < 100 )
                return notify_fail("你的混天气功火候未到，无法施展封字诀！\n");

        if( me->query_skill("dagou-bang") < 100 )
                return notify_fail("你的打狗棒法修为不足，还不能使用封字诀！\n");
        if( me->query_skill("staff") < 100 )
                return notify_fail("你的基本基本杖法修为不足！\n");

        if( me->query("neili") <= 1000 )
                return notify_fail("你的内力不够！\n");

        if( me->query("jing") <= 600 )
                return notify_fail("你的精力不够！\n");
	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "staff")
			return notify_fail("你使用的武器不对。\n");

        if( !objectp(weapon = me->query_temp("weapon")) )
                 return notify_fail("空手如何使用转字决？？\n");

                msghit = ({
                        "\n$N使出了「转」字诀，点打连绵不断，一点不中，又点一穴，棒影只在$n背后各穴上晃来晃去。\n",
                        "\n$N手臂抖处，已变为「转」字诀，身子凝立不动，手腕急画小圈，如陀螺般急速旋转。\n"
                });
                msg = HIG"\n"+ msghit[random(sizeof(msghit))] +"\n" NOR;
                message_vision(msg, me, target);

        if(random(me->query("combat_exp")) * me->query_skill("staff") > random(target->query("combat_exp")) * (target->query_skill("dodge")+ target->query_skill("parry"))/3)
        {
                msghit = ({
                	"\n$N手腕抖得愈快，$n转得也是愈快，手中"+ (string)weapon->name()+"就如陀螺的长柄，也是跟着滴溜溜的旋转。\n",
                	"$n脚下加劲，欲待得机转身，但$p纵跃愈快，棒端来得愈急。\n",
                	"$n绕着$N飞奔跳跃，大转圈子，举棒不离$n后心。圈子越转越大，逼得旁人不得不趋避。\n"
                });
                msg = HIY"\n"+ msghit[random(sizeof(msghit))] +"\n" NOR;
                message_vision(msg, me, target);

                zhuan_busy= me->query_skill("staff")/15;
                
                target->add("qi",-me->query_skill("staff"));
                target->add("eff_qi",-me->query_skill("staff"));
                target->start_busy(2);
                target->add("neili",-me->query_skill("staff"));
                me->set_temp("zhuan",1);
        
                me->start_busy( 1 + random(2));
                
                zhuan_duration= 5 + zhuan_busy/( weapon->weight()/1000);
                
                me->start_call_out( (: call_other, __FILE__, "remove_effect", me,target, zhuan_busy :), zhuan_duration);
                }
        else
        {
                msghit = ({
                	"$n斗然跃高，身在半空，牢牢抓住棒端，"+(string)weapon->name()+"登时便不转了，$N反而被摔了出去。\n",
                	"$N使力过重，失了轻妙之致，被$n一把抓住棒尖，且顺势一带，当下连人带棒直摔了出去。\n"
                });
                msg = CYN"\n"+ msghit[random(sizeof(msghit))] +"\n" NOR;
                me->start_busy( 2);
                me->add("qi", -me->query_skill("staff")/5);
                message_vision(msg, me, target);
        
        }

        zhuan_cost = me->query_skill("staff") / 2;
        me->add("neili", -zhuan_cost );
        me->add("jing", -zhuan_cost/2 );

        return 1;
}


private int remove_effect(object me, object target, int zhuan_busy)
{
        object weapon;
        me->delete_temp("zhuan");
        if(objectp(me) && objectp(target) && target->is_fighting(me) )
                message_vision(HIG"\n$N数招之后便已感变化不灵。\n"NOR ,me,target); 
        return 1;
}

