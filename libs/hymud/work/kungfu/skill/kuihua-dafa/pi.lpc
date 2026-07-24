#include <ansi.h>
#include <combat.h>

#define PI "「" HIW "群邪辟易" NOR "」"
#define HUI "「" HIW "毁天" HIR "灭地" NOR "」"
#define WSWD "「" HIR "无"BLU"双"HIM"无"HIW"对" NOR "」"
#define WS "「" HIR "无"BLU"双" NOR "」"
#define WD "「" HIM"无"HIW"对" NOR "」"

inherit F_SSERVER;

string *finger_name = ({ "左手中指", "左手无名指", "左手食指",
                         "右手中指", "右手无名指", "右手食指", }); 

int perform(object me, object target)
{
        string msg;
        string name;
        object weapon;
        int i,j;
        int skill,lvl,ap,dp,damage;
        int count;

        int x,a;
        string nextmsg;

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! me->is_fighting(target))
                return notify_fail(PI "只能对战斗中的对手使用。\n");

        weapon = me->query_temp("weapon");

        if (weapon && weapon->query("skill_type") != "sword" &&
            weapon->query("skill_type") != "pin")
                return notify_fail("你使用的武器不对，难以施展" PI "。\n");

        if (me->query_temp("weapon"))
                name = "手中" + weapon->name();
        else
                name = finger_name[random(sizeof(finger_name))];

        skill = me->query_skill("kuihua-dafa", 1);

        if (skill < 120)
                return notify_fail("你的葵花神功不够娴熟，难以施展" PI "。\n");

        if (me->query("neili") < 300)
                return notify_fail("你现在的真气不足，难以施展" PI "。\n");
       if ((int)me->query_skill("kuihua-xinfa", 1) < 50)
               return notify_fail("你的葵花心法太低了。\n");
               
        if (weapon && me->query_skill_mapped("sword") != "kuihua-dafa")
                return notify_fail("你没有准备使用葵花神功，难以施展" PI "。\n");


        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIW "$N" HIW "身形忽然变快，蓦的冲向$n" HIW "，" + name +
              HIW "幻作数道虚影，顿时无数星光一齐射向$n" HIW "！\n" NOR;
        message_vision(msg, me, target);

        count = skill / 5;
        me->add_temp("apply/attack", 200);
        me->add_temp("apply/damage", 1800);
me->set_temp("action_flag", 1);
        me->add_temp("pixie-jian/hit_msg", 1);

        for (i = 0; i < 8; i++)
        {
                if (! me->is_fighting(target))
                        break;

                if (random(2) == 0 && ! target->is_busy())
                        target->start_busy(2);

	msg = HIY "$N身形奇快无比，接连向$n攻出第"+chinese_number(i+1)+"招！！\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        }
        me->add("neili", -100);
        me->start_busy(3);
        me->add_temp("apply/attack", -200);
        me->add_temp("apply/damage", -1800);
        me->delete_temp("pixie-jian/hit_msg");
        me->delete_temp("action_flag");
if (skill>300 && target && me && weapon)
{
lvl = me->query_skill("kuihua-dafa", 1);

        //message_vision("\n\t\t" + BBLU + HIR "毁    天    " HIW "灭    地\n" NOR, me);

        // 第一式-----毁天
        ap = me->query_skill("force") + me->query_skill("dodge");
        dp=target->query_skill("force")+target->query_skill("dodge");

        message_vision(HIW "\n忽然间$N" HIW "身形猛转，刹时狂风如潮，遮云蔽"
                     "日，天地为之变色，这正是《葵花宝典》所记载绝学「" HIR "毁天"
                     "式" HIW "」。\n转眼间$N" HIW "已不见了踪影，只听得一声尖啸，一"
                     "道白光从天而下将$n" HIW "笼罩！" NOR, me, target);

        if (ap * 4 / 5 + random(ap) > dp || random(3)==0)
        {
                damage = ap+300 ;
           target->receive_damage("qi",damage,me);
           target->receive_wound("qi",damage/2,me);


                msg =HIR "\n$n" HIR "心中大惊，只见$N" HIR "一道"
               "耀眼白光一闪，已晃至自己跟前，躲闪不及，被击"
               "个正中。\n";

        } else
        {
                msg = HIC "\n$p" HIC "眼明身快，纵身向旁一跳，竟躲过这招。。\n" NOR;
        }
        message_vision(msg, me, target);

}

if (skill>400 && target && me && weapon)
{
  message_vision(HIM "\n紧跟着$N" HIM "身形一晃，已没了踪迹，刹那间，$n" HIM "只觉得地动"
                     "山摇，风起云涌。\n正犹豫间，$N" HIM "已蹿至$n" HIM "身后，一招"
                     "「" HIR "灭地诀" HIM "」使出 ……\n" NOR, me, target);

        ap = me->query_skill("force") + me->query_skill("dodge")+500;
        dp=target->query_skill("force")+target->query_skill("dodge");

        if (ap * 4 / 5 + random(ap) > dp  || random(3)==0)
        {
           target->receive_damage("qi",damage,me);
           target->receive_wound("qi",damage/2,me);

                msg += HIR "\n只听$n" HIR "一声惨嚎，被$N" HIR
                "击中背心，“喀嚓喀嚓”肋骨已震断。\n";

                                           
        } else
        {
                msg = HIC "\n$p" HIC "只觉身后风声呼呼，猛地提气跃开，躲过了这招。\n" NOR;
        }
        message_vision(msg, me, target);
}

if (skill>500 && target && me && weapon)
{
   msg = HIM "\n$N突然身形一转眨眼间使用葵花魔功的终极绝招----" NOR
                WSWD HIM "之" NOR WS "\n"HIW"$N眼神莹然有光，似乎进入了魔境之中。\n" +
                "$N手中" + weapon->name() + "化做无双剑影攻向$n。\n";
        ap=me->query_skill("kuihua-dafa",1)*1+me->query("dex")*20+
                me->query_skill("dodge", 1);
        dp=target->query_skill("parry")+target->query("dex")*10+
                target->query_skill("dodge", 1);

        me->start_busy(2);


        if (ap / 2 + random(ap) < dp  && random(2)==0)
        {
            msg += HIG "然而$n" HIG "抵挡得法，将$N" HIG
                    "的攻势一一化解。\n" NOR;
        } else
        {
            damage = ap +600;
           target->receive_damage("qi",damage,me);
           target->receive_wound("qi",damage/2,me);

                msg += HIY "$n" BLU "只觉得已经跌入了万劫魔域之中，" HIY
                    "$N手中" + weapon->name() + WHT
                    "如同地狱中的鬼火般，从各个方位刺了过来，避无可避！\n" NOR;

        }
       message_vision(msg, me, target);
}
if (skill>600 && target && me  && weapon)
{
 nextmsg = HIM "\n说是迟那时快，$N身形逆转使出了" NOR WSWD "之" WD HIM
                "式，刹那间天空阴云密布，\n" NOR HIM "$n的心脏几乎停止了跳动，呆呆的望着$N\n" NOR;
        ap=me->query_skill("kuihua-dafa",1)*1+me->query("dex")*20+
                me->query_skill("dodge", 1);
        dp=target->query_skill("parry")+target->query("dex")*10+
                target->query_skill("dodge", 1);

        me->start_busy(2);


        if ( ap / 2 + random(ap) < dp && !(target->is_busy()) && random(2)==0)
        {
                nextmsg += HIG "这时$n屏住呼吸" HIG "抵挡得法，将$N" HIG
                        "的攻势一一化解。\n" NOR;
        } else
        {

                damage = ap  +800;
           target->receive_damage("qi",damage,me);
           target->receive_wound("qi",damage/2,me);
                nextmsg += HIY "$n" BLU "只觉身上如同万剑穿心一般，" HIY "$N"
                        WHT "如同死神一般，势必要取$n性命！\n" NOR
                        HIM "此时此刻$N挥舞着手中" + weapon->name() + HIM
                        "，瞬间变化了几个剑招，可是$n就是无法找出破解之法，\n" +
                        "说时迟那时快" + weapon->name() + HIM
                        "已经刺进了$n的胸膛，鲜血溅了一地！！\n" NOR;
 
        }
        message_vision(nextmsg, me, target);
}

        return 1;
}