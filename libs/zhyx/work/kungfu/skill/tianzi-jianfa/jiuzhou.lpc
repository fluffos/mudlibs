//青，徐，冀，扬，荆,并,幽,豫,交
/* 【笑谈天下】澄浪[Wzw]：小楼一夜听春雨
【笑谈天下】信息通告：本泥潭有特色的趣味任务(help funquest)及宝镜任务(help mirror)
小呆走了进来。
【笑谈天下】澄浪[Wzw]：昨夜西风碉碧树
【笑谈天下】澄浪[Wzw]：云破月来花弄影
【笑谈天下】澄浪[Wzw]：迢迢不断如春水 */


#include <ansi.h>
#include <combat.h>

#define JIUZHOU "「" HIW "九州臣服" NOR "」"

inherit F_SSERVER;

string final1(object me, object target, int damage, object weapon, int lvl);
string final2(object me, object target, int damage);
string final3(object me, object target, int damage, object weapon, int lvl);
string final4(object me, object target, int damage, object weapon, int lvl);


int perform(object me, object target)
{
        int damage;
        string msg, sub_msg;
        int ap, dp;
        object weapon;       
        int lvl;

        if (userp(me) && ! me->query("can_perform/tianzi-jianfa/jiuzhou"))
                return notify_fail("你所使用的外功中没有这种功能。\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(JIUZHOU "只能对战斗中的对手使用。\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对，难以施展" JIUZHOU "。\n");   
        if (me->query_skill_mapped("sword") != "tianzi-jianfa")
                return notify_fail("你没有激发天子剑法，难以施展" JIUZHOU "。\n");

        if ((int)me->query("max_neili") < 10000)
                return notify_fail("你内力修为不够，难以施展" JIUZHOU "。\n");

        lvl = (int)me->query_skill("tianzi-jianfa", 1);
        if (lvl < 340)
                return notify_fail("你天子剑法火候不够，难以施展" JIUZHOU "。\n");
   

        if ((int)me->query("neili") < 850)
                return notify_fail("你现在真气不够，难以施展" JIUZHOU "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        message_sort(HIY "\n$N" HIY "突显帝王之态，纵声高呼：\n"NOR
                     HIR" “普天之下，莫非王土。天子降世，九州臣服！”\n"NOR
                     HIW "     旋即但见" HIW "天边似乎飞来千军万马，连同$N的剑招尽数袭向$n"
                          HIW "。\n" NOR, me, target);

       ap = lvl + me->query_skill("sword", 1);
       

        // 第一招，判断对方悟性
        dp = target->query_int() * 2 + target->query_skill("dodge", 1) 
             + target->query_skill("parry", 1);

        message_sort(HIG "\n$N" HIG "高呼：第一招，天子取青州！"
                     "一剑直刺$n顶门。\n" NOR, me, target);
        if (ap * 4 / 5 + random(ap) > dp)
        {
                damage = ap + random(ap);
                 msg = COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 80 + random(10),
                                           (: final2, me, target, damage :));
              
        } else
        {
                msg = HIC "$n" HIC "气贯双臂，凝神以对，竟将$N" HIC "之力卸去。\n" NOR;
        }
        message_sort(msg, me, target);

        // 第二招，判断对方臂力
        dp = target->query_str() * 2 + target->query_skill("unarmed", 1) + 
             target->query_skill("parry", 1);
        message_sort(HIM "\n$N" HIM "高呼：第二招，天子取徐州！"
                     "剑招突变，改攻$n" HIM "双臂。\n" NOR, me, target);

        if (ap * 4 / 5 + random(ap) > dp)
        {
                damage = ap + random(ap);
                msg = COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 95 + random(10),
                                          HIR "$n" HIR "觉得$N" HIR "此招肤浅之极，于"
                                          "是随意招架，猛然间，「噗嗤」！一声，" + weapon->name() +
                                          HIR "已刺中$n" HIR "的双臂，鲜血不断涌出。\n" NOR, me , target);
        } else
        {
                msg = HIC "$n" HIC "不敢大意，凝神以对，竟将$N这招化去。\n" NOR;
        }
        message_sort(msg, me, target);

        // 第三招，判断对方根骨
        dp = target->query_con() * 2 + target->query_skill("force", 1) + 
             target->query_skill("parry", 1);

        message_sort(HIC "\n两招使毕，紧接着第三招天子取冀州又至。但见$N" HIC "更"
                    "不思索，直取$n丹田。\n" NOR, me,target);

        if (ap * 4 / 5 + random(ap) > dp)
        {
                damage = ap + random(ap);
                msg = COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 80 + random(10),
                                         (: final1, me, target, damage, weapon, lvl :));
        } else
        {
                msg = HIC "$n" HIC "气运丹田，硬生生抵挡住$N" HIC "这招。\n" NOR;
        }
        message_sort(msg, me, target);

        // 第四招，判断对方身法
        dp = target->query_dex() * 2 + target->query_skill("dodge", 1) + 
             target->query_skill("parry", 1);

        message_sort(HIW "\n$n尚未回过神来，但见$N又使出第四招，天子取扬州，"
                     HIW "攻的乃是$n下盘。\n" NOR, me,target);

        if (ap * 4 / 5 + random(ap) > dp)
        {
                damage = ap + random(ap);
                msg = COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 80 + random(10),
                                          (: final3, me, target, damage, weapon, lvl :));
        } else
        {
                msg = HIC "$n" HIC "见这招来势凶猛，身形疾退，瞬间飘出三"
                      "丈，方才躲过$N" HIC "这招。\n" NOR;
        }
        message_sort(msg, me, target);


        // 第五招，判断对方武学修养，读书识字
        ap += ( me->query_skill("martial-cognize",1) + me->query_skill("literate", 1) ) / 2;
        dp = target->query_skill("martial-cognize",1) + target->query_skill("literate", 1) + 
             target->query_skill("parry", 1);

        message_sort(HIB "\n$N使出最后一招，荆并幽豫交五州并取，"
                     HIB "手中" + weapon->name() + "刷刷刷攻出五剑，"
                     "以迅雷不及掩耳之势攻向$n全身要穴。\n" NOR, me,target);

        if (ap * 4 / 5 + random(ap) > dp)
        {
                damage = ap + random(ap);
                msg = COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 80 + random(10),
                                          (: final4, me, target, damage, weapon, lvl :));
        } else
        {
                msg = HIC "$n" HIC "见这招来势凶猛，身形疾退，瞬间飘出三"
                      "丈，方才躲过$N" HIC "这招。\n" NOR;
        }
        message_sort(msg, me, target);



        me->start_busy(2 + random(3));
        me->add("neili", -800 - random(800));
        return 1;
}

string final1(object me, object target, int damage, object weapon, int lvl)
{
        target->add("neili", -(lvl + random(lvl)));

        return  HIR "$n" HIR "却觉$N" HIR "这招气势恢弘，于是运力奋力抵挡。但是无奈这"
                "招威力惊人，$n" HIR "闷哼一声，倒退几步，顿觉内息涣散，" + weapon->name() + HIR 
                "上早已染满鲜血！\n" NOR;
}

string final2(object me, object target, int damage)
{
        target->receive_damage("jing", damage / 2, me);
        target->receive_wound("jing", damage / 4, me);
        return  HIY "$n" HIY "心中一惊，但见$N" HIY "这几招奇异无比，招式变化莫测，"
                "但威力却依然不减，正犹豫间，$n" HIY "却已中招，顿感精力不济，浑"
                "身无力。\n" NOR;
}

string final3(object me, object target, int damage, object weapon, int lvl)
{
   
        target->start_busy(4 + random(lvl / 40));
  
        return  HIY "$N" HIY  "法奇妙无比，手中" + weapon->name() + HIY "时而宛若游龙，时而"
                "宛若惊鸿，霎那间$n" HIY "已遍体鳞伤，$N" HIY "猛然将手中" + weapon->name() + HIY "一"
                "转，剑势陡然加快，将$n" HIY "团团围住，竟无一丝空隙！\n" NOR;

}

string final4(object me, object target, int damage, object weapon, int lvl)
{
   
         
        return  HIY "$N" HIY  "法奇妙无比，手中" + weapon->name() + HIY "时而宛若游龙，时而"
                "宛若惊鸿，霎那间$n" HIY "已遍体鳞伤，$N" HIY "猛然将手中" + weapon->name() + HIY "一"
                "转，剑势陡然加快，将$n" HIY "团团围住，竟无一丝空隙！\n" NOR;

}
