#include <ansi.h>
#include <combat.h>

#define JING "「" HIW "白首太玄经" NOR "」"

inherit F_SSERVER;


int perform(object me, object target)
{
        int damage;
        string msg, sub_msg;
        int ap, dp;
        object weapon;
        int flag = 0;
        int lvl;


        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(JING "只能对战斗中的对手使用。\n");

             weapon = me->query_temp("weapon");
	if( objectp(me->query_temp("weapon")) )
		return notify_fail("你必须空手才能使用！\n");	

        if ((int)me->query_skill("force", 1) < 340)
                return notify_fail("你内功修为不够，难以施展" JING "。\n");

        if ((int)me->query("max_neili") < 9000)
                return notify_fail("你内力修为不够，难以施展" JING "。\n");

        lvl = (int)me->query_skill("taixuan-gong", 1);
        if (lvl < 340)
                return notify_fail("你太玄功火候不够，难以施展" JING "。\n");


        if ((int)me->query("neili") < 850)
                return notify_fail("你现在真气不够，难以施展" JING "。\n");

        if (me->query_skill("force", 1) < 300)
                return notify_fail("你基本内功不足，难以施展" JING "。\n");

        if ((int)me->query_skill("literate", 1)> 5 )
                return notify_fail("你觉得太玄神功深奥之极，一时间难以领会。\n");
        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        message_vision(HIM "\n$N" HIM "情不自禁的纵声长啸，霎时之间，千百种招式纷至沓来，涌"
                     "向心头。\n$N" HIM "随手挥舞，已是不按次序，但觉无论何种招式皆能随心所欲"
                     "，既不必存想内息，\n亦不须记忆招数，石壁上的千百种招式，自然而然的从心"
                     "中传向手足，尽数袭向$n" HIM "。\n" NOR, me, target);


        if (flag)ap = lvl + me->query_skill("unarmed", 1);
        else ap = lvl + me->query_skill("parry", 1);

        // 第一招，判断对方臂力
        dp = target->query_str() * 2 + target->query_skill("unarmed", 1) + 
             target->query_skill("parry", 1);

        message_vision(HIW "\n$N" HIW "突然间只觉得右肋下‘渊液穴’上一动，一道热线沿着‘足少"
                     "阳胆经’，\n向着‘日月’、‘京门’二穴行去，\n一招‘十步杀一人’的"  + 
                     "拳法已随意使出，各种招式源源而出，将$n" HIW "笼罩。\n" NOR, me, target);

        if (ap * 4 / 5 + random(ap) > dp)
        {
                damage = ap + random(ap)+600;
target->add("qi",-damage);
		target->add("eff_qi",-damage/2);
        target->add("neili", -(lvl + random(lvl)));
                msg =HIY "$n" HIY "却觉$N" HIY "这招气势恢弘，于是运力奋力抵挡。但是无奈这"
                "招威力惊人，\n$n" HIY "闷哼一声，倒退几步，顿觉内息涣散，" + "双手" + HIY 
                "上早已染满鲜血！\n" NOR;

        } else
        {
                msg = HIC "$n" HIC "气贯双臂，凝神以对，竟将$N" HIC "之力卸去。\n" NOR;
        }
        message_vision(msg, me, target);

        // 第二招，判断对方悟性
        dp = target->query_int() * 2 + target->query_skill("dodge", 1) 
             + target->query_skill("parry", 1);

        message_vision(HIW "\n$N" HIW "肌肤如欲胀裂，内息不由自主的依着‘赵客缦胡缨’那套经脉运"
                     "行图谱转动，\n同时手舞足蹈，似是大欢喜，又似大苦恼。\n" NOR, me);

        if (ap * 4 / 5 + random(ap) > dp)
        {
                damage = ap + random(ap)+600;
target->add("qi",-damage);
		target->add("eff_qi",-damage);
                msg =HIY "$n" HIY "冷笑一声，觉得$N" HIY "此招肤浅之极，于"
                                          "是随意招架，\n猛然间，「噗嗤」！一声，" + "一拳" +
                                          HIY "已穿透$n" HIY "的胸膛，鲜血不断涌出。\n" NOR;
        } else
        {
                msg = HIC "$n" HIC "会心一笑，看出$N" HIC "这招中的破绽，随意施招竟将这招化去。\n" NOR;
        }
        message_vision(msg, me, target);

        // 第三招，判断对方根骨
        dp = target->query_con() * 2 + target->query_skill("force", 1) + 
             target->query_skill("parry", 1);

        message_vision(HIW "\n‘赵客缦胡缨’既毕，接下去便是‘吴钩霜雪明’，$N" HIW "更"
                    "不思索，\n石壁上的图谱一幅幅在脑海中自然涌出，自‘银鞍照白马’直到‘谁能书阁下’，\n"
                    "一气呵成的使了出来。\n" NOR, me);

        if (ap * 4 / 5 + random(ap) > dp)
        {
                damage = ap + random(ap);
                damage = ap + random(ap)+600;
target->add("qi",-damage);
		target->add("eff_qi",-damage/2);
if (userp(target))
target->add("jing",-damage/2);
if (userp(target))
		target->add("eff_jing",-damage/2);

                msg =HIY "$n" HIY "心中一惊，但见$N" HIY "这几招奇异无比，招式变化莫测，"
                "但威力却依然不减，\n正犹豫间，$n" HIY "却已中招，顿感精力不济，浑"
                "身无力。\n" NOR;

        } else
        {
                msg = HIC "$n" HIC "默运内功，内劲贯于全身，奋力抵挡住$N" HIC "这招。\n" NOR;
        }
        message_vision(msg, me, target);

        // 第四招，判断对方身法
        dp = target->query_dex() * 2 + target->query_skill("dodge", 1) + 
             target->query_skill("parry", 1);

        message_vision(HIW "\n待得‘谁能书阁下’这套功夫演完，$N" HIW "只觉气息逆转"
                     "，‘不惭世上英’倒使上去。\n" NOR, me);

        if (ap * 4 / 5 + random(ap) > dp)
        {
                damage = ap + random(ap)+600;
target->add("qi",-damage);
		target->add("eff_qi",-damage/2);
if (!target->is_busy()) target->start_busy(4);

                msg =HIY "$N" HIY +  "拳法奇妙无比，招式时而宛若游龙，时而"
                "宛若惊鸿，霎那间$n" HIY "已遍体鳞伤。\n$N" HIY "猛然将" + "拳风" + HIY "一"
                "转，招式陡然加快，将$n" HIY "团团围住，竟无一丝空隙！\n" NOR;


        } else
        {
                msg = HIC "$n" HIC "见这招来势凶猛，身形疾退，瞬间飘出三"
                      "丈，方才躲过$N" HIC "这招。\n" NOR;
        }
        message_vision(msg, me, target);
                if (random(3) == 1 && ! target->is_busy())
                        target->start_busy(3);
        me->start_busy(2);
        me->add("neili", -400 - random(400));
        return 1;
}

