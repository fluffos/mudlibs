// This is player's own perform (Write by Lonely@nt2)
// Create by 段左助(Rare) at Sat Apr  8 14:47:07 2006
// 六脉龙气(dragon)

#include <ansi.h>
#include <combat.h>

#define PFM "「" HIW "六脉龙气" NOR "」"

inherit F_SSERVER;


string *xue_name = ({ 
"劳宫穴", "膻中穴", "曲池穴", "关元穴", "曲骨穴", "中极穴",
"承浆穴", "天突穴", "百会穴", "幽门穴", "章门穴", "大横穴",
"紫宫穴", "冷渊穴", "天井穴", "极泉穴", "清灵穴", "至阳穴", }); 
string *weapon_sk = ({
        "sword", "blade", "staff", "whip", "club", "hammer", "axe"
});

int perform(object me, object target)
{
        object weapon;
        string msg,wp;
        int ap, dp,i;
        int damage;
        int attack;



        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(PFM "只能对战斗中的对手使用。\n");


                if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                        return notify_fail(PFM "只能空手使用。\n");             
       
        if ((int)me->query_skill("kurong-changong",1) < 180)
            return notify_fail("你的枯荣禅功太低。\n");
        if ((int)me->query_skill("duanjia-sword", 1) < 180)
		return notify_fail("你的段家剑火候太浅。\n");    
        if ((int)me->query_skill("jinyu-quan", 1) < 180)
		return notify_fail("你的金玉拳火候太浅。\n");
        if ((int)me->query_skill("wuluo-zhang", 1) < 180)
		return notify_fail("你的五罗轻烟掌火候太浅。\n");
        if ((int)me->query_skill("feifeng-whip", 1) < 180)
		return notify_fail("你的飞凤鞭火候太浅。\n");
        if ((int)me->query_skill("sun-finger", 1) < 180)
		return notify_fail("你的一阳指火候太浅。\n");

        
        if ((int)me->query_skill("yiyang-zhi", 1) < 300)
                return notify_fail("你" + to_chinese("yiyang-zhi") + "不够娴熟，难以施展" PFM "。\n");

        
        if (me->query("neili") < 300)
                return notify_fail("你现在的真气不够，难以施展" PFM "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIW "$N眼中神光湛湛，双手平伸，六大穴之中各自涌出一束剑气，随即$N双手一合，将六束剑气困于掌中，剑气激荡冲撞不止。至气势最盛之时$N双手再分，喝道：“阿录给” 六道剑气之合竟如狂龙，狂冲$n而去！" + "\n" + NOR;

        ap =  me->query_skill("finger");
        dp =  target->query_skill("parry");
         
        if (ap * 2 / 3 + random(ap * 2) > dp)
        {
                damage = me->query_skill("finger") * 3;

target->add("qi",-damage);
target->add("eff_qi",-damage);
target->apply_condition("yyz_damage",30);

                        msg +=HIM "$n眼见狂龙袭来，避无可避，躲无可躲，只得闭目受死。刹那间被龙气吞没，软瘫在地。" + "\n" NOR;
                me->add("neili", -200);
                me->start_busy(1);
                if (! target->is_busy())
                        target->start_busy(2);
        } else
        {
                msg += NOR + CYN "$p见狂龙袭来，竟无畏惧，侧身间，一把抓住龙颈，掌中使力之下，那龙气竟就此散碎了。" + "\n" NOR;
                me->add("neili", -100);
                me->start_busy(2);
        }
                
       message_combatd(msg, me, target); 
      damage = me->query_skill("finger");
        ap = me->query_skill("finger");
        dp = target->query_skill("parry");

        msg = HIW "突然间";

        if (objectp(weapon = target->query_temp("weapon")))
        {
                wp = weapon->name();
                msg += "$N" HIW "单指一扬，径点$n" HIW "持着" + wp + NOR + HIW
                       "的手腕上「" HIY "腕骨" HIW "」、「" HIY "阳谷" HIW "」"
                       "、「" HIY "养老" HIW "」三穴。\n" NOR;

                ap = me->query_skill("finger");
                dp = target->query_skill("force");

                if (ap / 2 + random(ap) > dp)
                {
                        msg += HIR "霎时间$n" HIR "只觉得手腕一麻，手中" + wp +
                               HIR "再也拿持不住，脱手掉在地上。\n\n" HIW "紧"
                               "接着";
                        me->add("neili", -150);
                        weapon->move(environment(target));
                } else
                {
                        msg += CYN "可是$n" CYN "将手中" + wp + NOR + CYN "转"
                               "动如轮，终于化解了这一招。\n\n" HIW "紧接着";
                        me->add("neili", -100);
                }
        }

        msg += "$N" HIW "凝气于指，一式「" HIR "阳关三叠" HIW "」点出，顿时一股"
               "纯阳的内力直袭$n" HIW "胸口！\n" NOR;
        if (ap / 2 + random(ap) > dp)
        {
target->add("qi",-damage);
target->add("eff_qi",-damage);
target->apply_condition("yyz_damage",30);

                        msg +=HIR "结果$n" HIR "被$N" HIR "一指点中"
                                           HIY + xue_name[random(sizeof(xue_name))] +
                                           HIR "，全身真气逆流而上，登时呕出一大"
                                           "口鲜血。\n" NOR;


                target->add_temp("yiyang-zhi/die", 1);
        } else
        {
                msg += CYN "可是$p" CYN "镇定自如，全力化解了$P"
                       CYN "这精妙的一指。\n" NOR;
        }

        ap = me->query_skill("finger");
        dp = target->query_skill("dodge");

        msg += "\n" HIW "接着$N" HIW "踏前一步，体内真气迸发，隔空一指劲点$n" HIW
               "而去，指气纵横，嗤然作响！\n" NOR;
        if (ap / 2 + random(ap) > dp)
        {
target->add("qi",-damage*2);
target->add("eff_qi",-damage);
target->apply_condition("yyz_damage",30);

                        msg +=HIR "结果$n" HIR "被$N" HIR "一指点中"
                                           HIY + xue_name[random(sizeof(xue_name))] +
                                           HIR "，全身真气逆流而上，登时呕出一大"
                                           "口鲜血。\n" NOR;



                target->add_temp("yiyang-zhi/die", 1);
        } else
        {
                msg += CYN "可是$p" CYN "镇定自如，全力化解了$P"
                       CYN "这精妙的一指。\n" NOR;
        }

        ap = me->query_skill("finger");
        dp = target->query_skill("force");

        msg += "\n" HIW "最后$N" HIW "一声猛喝，单指“嗤”的一声点出，纯阳指力同"
               "时笼罩$n" HIW "全身诸多要穴！\n" NOR;
        if (ap / 2 + random(ap) > dp)
        {
target->add("qi",-damage);
target->add("eff_qi",-damage);
target->apply_condition("yyz_damage",30);

                        msg +=HIR "结果$n" HIR "被$N" HIR "一指点中"
                                           HIY + xue_name[random(sizeof(xue_name))] +
                                           HIR "，全身真气逆流而上，登时呕出一大"
                                           "口鲜血。\n" NOR;


                target->add_temp("yiyang-zhi/die", 1);
        } else
        {
                msg += CYN "可是$p" CYN "镇定自如，全力化解了$P"
                       CYN "这精妙的一指。\n" NOR;
        }

        if (target->query_temp("yiyang-zhi/die", 1) == 3
           && target->query("neili"))
        {
                msg += HIY "\n$n" HIY "被$N" HIY "三指连中，全身真气涣"
                       "散，宛如黄河决堤，内力登时狂泻而出。\n\n" NOR;
if (userp(target))
{
                target->set("neili", 0);
}
else
{
	target->add("neili", -2000);
	target->start_busy(4);
}
        }

        target->delete_temp("yiyang-zhi/die");
        message_combatd(msg, me, target);

        if (! target->query("neili"))
                tell_object(target, HIC "你只觉丹田内竟似空空如也，一时"
                                    "说不出的难受。\n" NOR);
msg = HIR "紧接着$N" HIR "十指纷飞，接连弹出数道无形剑气，$n"
              HIR "四面八方皆被剑气所笼罩。\n"NOR;
        message_combatd(msg, me, target);

        me->add_temp("apply/attack", 100);

        for (i = 0; i < 3; i++)
        {
msg=HIR "$N第"+chinese_number(i+1)+"指点向━━━━$n的" HIY + xue_name[random(sizeof(xue_name))] +
                                           HIR "\n" NOR;
                 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        }
        me->start_busy(5);
        me->add("neili", -800);
        return 1;
}

