#include <ansi.h>
#include <combat.h>

#define XIAN "「" HIM "御剑今生" NOR "」"
string query_name() { return "御剑"ZJBR"今生"; }

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg;
        int ap, dp;



        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(XIAN "只能对战斗中的对手使用。\n");
 
        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对，难以施展" XIAN "。\n");
        if(me->query("family/family_name")!="蜀山派")
                return notify_fail("不是蜀山的不能用「御剑今生」！\n");
        
        if(me->query("shushan/jinsheng_perform")!=1)
                return notify_fail("你还没领会「御剑今生」！\n");
        

        if ((int)me->query_skill("yujianshu", 1) < 200)
                return notify_fail("你的蜀山御剑术还不到家，难以施展" XIAN "。\n");

        if ((int)me->query_skill("xianfeng-spells", 1) < 200)
                return notify_fail("你的仙风云体术还不到家，难以施展" XIAN "。\n");

        if (me->query_skill_mapped("sword") != "yujianshu")
                return notify_fail("你没有激发蜀山御剑术，难以施展" XIAN "。\n");

        if((int)me->query("max_neili") < 1500 )
                return notify_fail("你的内力不够，难以施展" XIAN "。\n");

       if ((int)me->query("max_mana") < 1500)
                return notify_fail("你的法力不够，难以施展" XIAN "。\n");

        if ((int)me->query("neili") < 500)
                return notify_fail("你的真气不够，难以施展" XIAN "。\n");

        if ((int)me->query("mana") < 500)
                return notify_fail("你的法力不够，难以施展" XIAN "。\n");        

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");
        
        msg = HIB "$N眼见不敌，想起了访宁桥上那首诗，心中默念：\n" NOR
              HIG "所有的这一切都只有等待来生了......\n"
              "$N" HIB "一念及此，身形与"+weapon->name()+NOR+HIB"化为一体直射$n～～～～～ \n" NOR;       
        
        ap = me->query_skill("sword") * 2;
        dp = target->query_skill("dodge") + target->query_skill("parry");
             
        if (ap > dp)
        {
                damage = 0;
        me->start_busy(2);
        me->add("shushan/jinsheng_perform", -1);
        me->set_skill("force", me->query_skill("force", 1) - 100);
        me->add("mana", -100);
        me->add("neili", -500);
        me->add("max_mana", -100);
        me->add("max_neili", -500);

                        msg += HIB "$n不料$N如此决绝，竟然呆立当场，瞬间一道蓝光已在$n身上当胸穿过！！！\n"
                               "半空中传来一声长叹：天绝我～～～～～ \n" NOR;
                        damage = -1;
                
        } else
        {
                me->start_busy(5);
                me->add("neili", -300);
                me->add("shushan/jinsheng_perform", -1);
                msg += CYN "可是$p" HIB "一见情势不妙，拼命向后纵越，竟然在狼狈不堪之际侥幸地躲过了这拼命的一式！！！\n" NOR;
        }
        message_combatd(msg, me, target);

        if (damage < 0)
                target->die(me);

        return 1;
}


