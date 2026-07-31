// This is player's own perform (Write by Lonely@nt2)
// Create by 胡骸骨(Mount) at Tue Apr 11 12:13:09 2006
// 又见飞刀(feidao)

#include <ansi.h>
#include <combat.h>

#define PFM "「" HIW "又见飞刀" NOR "」"

inherit F_SSERVER;


string *weapon_sk = ({
        "sword", "blade", "staff", "whip", "club", "hammer", "axe"
});

int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;
        int damage;
        int attack;



        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(PFM "只能对战斗中的对手使用。\n");


        if (! objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "sword"
           && (string)weapon->query("skill_type") != "blade" )
                return notify_fail("你所使用的武器不对，难以施展" PFM "。\n");

        
        if ((int)me->query_skill("daojian-guizhen", 1) < 400)
                return notify_fail("你" + to_chinese("daojian-guizhen") + "不够娴熟，难以施展" PFM "。\n");

        if (member_array("blade", weapon_sk) == -1)
        {
                if (me->query_skill_prepared("blade") != "daojian-guizhen")
                        return notify_fail("你没有准备" + to_chinese("daojian-guizhen") + "，难以施展" PFM "。\n");
        }
        	if( me->is_busy() )
		return notify_fail("( 你上一个动作还没有完成，不能施用内功。)\n");
        if (me->query("neili") < 300)
                return notify_fail("你现在的真气不够，难以施展" PFM "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIW "$N对着$n一声大吼：“看我的绝招，「小李老母的飞刀」！”，说完，抡起手中的武器向$n砸了过去，看似毫无章法，却是暗含刀道的至境！" + "\n" + NOR;

        ap = me->query_skill("blade",1);
        dp = target->query_skill("parry",1);
         
        if (ap * 2 / 3 + random(ap * 2) > dp)
        {
                damage = me->query_skill("blade",1) * 3;
                		target->add("qi",-damage);
		target->add("eff_qi",-damage/2);
                me->add("neili", -50);
		msg +=                     HIM "$n闯荡江湖多年，哪见过如此奥妙的招式，一时间无法破解，被刺个通体透凉！" + "\n" NOR;
                me->add("neili", -50);
                me->start_busy(1);
                if (! target->is_busy())
                        target->start_busy(2);
        } else
        {
                msg += NOR + CYN "$p白了$P一眼：“雕虫小技，看我的”，整个人忽地施展出狗趴式，躲过了这至命一击。" + "\n" NOR;
                me->add("neili", -50);
                me->start_busy(2);
        }
                
        message_combatd(msg, me, target);
        return 1;
}

