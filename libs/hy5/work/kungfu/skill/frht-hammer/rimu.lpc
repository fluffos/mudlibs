// BY cigar 2002.01
 
#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;


int perform(object me)
{
        string msg;
        object weapon, target;
        object ob;
        int skill, skill2, ap, dp,kee_wound;

        me->clean_up_enemy();
        target = me->select_opponent();

        skill = me->query_skill("hammer",1);
        skill2 = me->query_skill("parry",1);

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "hammer")
                        return notify_fail("不用锤，怎么能用“日暮途穷”？\n");



        if( !me->is_fighting()|| !living(me) )
                return notify_fail("「日暮途穷」只能在战斗中使用。\n");
if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("只能在战斗中使用。\n");

 if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "hammer")
        return notify_fail(RED"开什么玩笑，武器不对？\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "qingming-xuangong")
                return notify_fail("请使用青冥玄功!\n");

        if((int)me->query_skill("qingming-xuangong",1) < 200)
                return notify_fail("你的青冥玄功还不够。。。\n"); 


        if( (int)me->query("max_neili") < 800 )
                return notify_fail("你的内力修为还不够高！\n");

        if( (int)me->query("neili") < 800 )
                return notify_fail("你现在的内力不足！\n");

        if( skill < 100)
                return notify_fail("你的基本锤法功还不行! \n");

        if( skill2 < 90)
                return notify_fail("基本功还不行! \n");

        if( me->query_skill_mapped("hammer") != "frht-hammer") 
                return notify_fail("无法使用「日暮途穷」！\n");
 
 msg = HIY "\n$N容光焕发，心无杂念，“日月经天，江河行地”之气势顿增。\n手中小流星锤，耍的酣畅淋漓。\n\n"NOR;
                message_vision(msg, me, target);
 me->add_temp("apply/attack", 200); 
  me->add_temp("apply/damage", 3000); 

                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
  me->add_temp("apply/damage", -3000); 
 me->add_temp("apply/attack", -200); 


 msg = HIY "$N抬起左手指向$n，脚步慢慢加快，成迅雷不及掩耳之势围绕$n旋转起来。
\n"HIC"霎时间$N似雷火、似狂风、似闪电的迅猛一般腾空而起。
\n\n"HIC"$N手持"+weapon->query("name")+HIC"牵带着空中雾、云、风形成一道巨大的屏障遮住了$n周围的一切。
\n\n"HIW"          ==== 日月经天，江河行地，“日暮途穷你奈何 ...” ====
\n\n"HIY"此时的一切早已在这"+HIR"无形、缥缈"+HIY"的幻界之中，万物生灵早已形成"+HIM"“无可奈何花落去”"+HIY"之势。\n\n" NOR;
                message_vision(msg, me, target);

                ap = ((me->query("combat_exp",1))+(me->query_str()));
                dp = ((target->query("combat_exp",1))+(target->query_str()));

                if( dp < 1 )
                        dp = 1;
                if( random(ap) > dp/3 )

                {
 msg = HIR "$n在这黑暗的幻界早已迷失了自己、迷失了生存的希望，万分感慨油然而生！\n$n无可奈何之下，减慢脚步。\n\n"NOR;
                        message_vision(msg, me, target);
                        kee_wound = 80 + skill + random(skill*2);
if(kee_wound > 18000) kee_wound=18000;
                        if(kee_wound > target->query("qi")) kee_wound = (target->query("qi") + 1);
        target->receive_wound("qi", kee_wound,me);
        target->receive_damage("qi", (kee_wound/2),me);
                        COMBAT_D->report_status(target, 0);
                        me->start_busy(2);
                        me->add("neili",-50);
                }
                else
                {
                        msg = HIG "$n对着周围发生的一切无所用心，冷笑一声，加快脚步离开了这里！\n\n"NOR;
                        message_vision(msg, me, target);
                        me->start_busy(2);
                        me->add("neili",-10);
                }

                return 1;

}


