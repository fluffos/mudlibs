#include <ansi.h>
#include <combat.h>
#include "/kungfu/skill/eff_msg.h";
#define ZHUAN "「" HIR "转乾坤" NOR "」"

inherit F_SSERVER;
string *xue_name1 = ({ 
        "大锥穴",
        "百会穴",
        "志室穴",
        "肩井穴",
        "劳宫穴",
        "内关穴",
        "外关穴",
        "会宗穴",
});
string *xue_name2 = ({
        "曲池穴",
        "冲阳穴",
        "臂儒穴",
        "白海穴",
        "灵台穴",
        "风府穴",
        "神风穴",
        "玉书穴",
}); 
string *xue_name3 = ({
        "青门穴",
        "商阳穴",
        "丝空竹穴",
        "气海穴",
        "冲门穴",
        "大椎穴",
        "百里穴",
        "槐阳穴",
}); 
string* xuedao = ({
	"巨骨穴",
	"地仓穴",
	"肩井穴",
	"颊车穴",
	"承泣穴",
	"风池穴",
	"章门穴",
	"风府穴",
	"精促穴",
	"陶道穴",
	"强间穴",
	"少海穴",
	"犊鼻穴",
	"神门穴",
	"华盖穴",
	"大椎穴",
	"凤尾穴",
	"至阳穴",
	"劳宫穴",
	"百会穴",
	"灵台穴",
	"太阳穴",
	"膻中穴",
	"命门穴",
	"鸠尾穴",
	"三阴交",
	"天柱穴"
});
int perform(object me, object target)
{
        object weapon;
        int ap, dp, damage,skill;
        string msg;
        string pmsg;

skill=(int)me->query_skill("tanzhi-shentong", 1);
        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(ZHUAN "只能对战斗中的对手使用。\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(ZHUAN "只能空手施展。\n");

        if ((int)me->query_skill("tanzhi-shentong", 1) < 220)
                return notify_fail("你的弹指神通不够娴熟，难以施展" ZHUAN "。\n");

        if ((int)me->query_skill("qimen-wuxing", 1) < 200)
                return notify_fail("你的奇门五行修为不够，难以施展" ZHUAN "。\n");
 
        if (me->query_skill_mapped("finger") != "tanzhi-shentong")
                return notify_fail("你没有激发弹指神通，难以施展" ZHUAN "。\n");

        if (me->query_skill_prepared("finger") != "tanzhi-shentong")
                return notify_fail("你没有准备弹指神通，难以施展" ZHUAN "。\n");
        if ((int)me->query_skill("bibo-shengong", 1) < 120)
                return notify_fail("你的碧波神功火候太浅。\n");
        if ((int)me->query_skill("anying-fuxiang", 1) < 120)
                return notify_fail("你的暗影浮香火候太浅。\n");
        if ((int)me->query_skill("lanhua-shou", 1) < 120)
                return notify_fail("你的兰花拂穴手火候太浅。\n");
        if ((int)me->query_skill("luoying-shenjian", 1) < 120)
                return notify_fail("你的落英神剑火候太浅。\n");
        if ((int)me->query_skill("luoying-zhang", 1) < 120)
                return notify_fail("你的落英神剑掌火候太浅。\n");
        if ((int)me->query_skill("tanzhi-shentong", 1) < 120)
                return notify_fail("你的弹指神通火候太浅。\n");
        if ((int)me->query_skill("xuanfeng-leg", 1) < 120)
                return notify_fail("你的旋风扫叶腿火候太浅。\n");
        if ((int)me->query_skill("yuxiao-jian", 1) < 120)
                return notify_fail("你的玉箫剑法火候太浅。\n");
       if ((int)me->query_skill("count", 1) < 120)
                return notify_fail("你的阴阳八卦火候太浅。\n");
       if ((int)me->query_skill("qimen-wuxing", 1) < 120)
                return notify_fail("你的奇门五行火候太浅。\n");
        if (me->query("max_neili") < 3500)
                return notify_fail("你的内力修为不足，难以施展" ZHUAN "。\n");

        if (me->query("neili") < 800)
                return notify_fail("你现在的真气不够，难以施展" ZHUAN "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIC "$N" HIC "将全身功力聚于一指，指劲按照二十八宿方位云贯而出，正"
              "是桃花岛「" HIR "转乾坤" HIC "」绝技。\n" NOR;

        ap = me->query_skill("finger") + me->query_skill("qimen-wuxing", 1);
        dp = target->query_skill("dodge") + target->query_skill("qimen-wuxing", 1);

        if (ap * 11 / 20 + random(ap) > dp)
        {
                damage = 0;
                if (me->query("max_neili") > target->query("max_neili") * 2)
                {
                        me->start_busy(2);
                        msg += HIR "霎那间$n" HIR "只见寒芒一闪，$N" HIR "食指"
                               "已钻入$p" HIR "印堂半尺，指劲顿时破脑而入。\n"
                               HIW "你听到“噗”的一声，身上竟然溅到几滴脑浆！"
                               "\n" NOR "( $n" RED "受伤过重，已经有如风中残烛"
                               "，随时都可能断气。" NOR ")\n";
                        damage = -1;
                } else
                {
                        me->start_busy(3);
                        damage = me->query_skill("finger");
                        me->add("neili", -500);
target->add("qi",-damage*3);
target->add("eff_qi",-damage*2);

                        msg +=HIR "霎那间$n" HIR "只见寒芒一闪，$N"
                                                   HIR "食指已钻入$p" HIR "胸堂半尺，指劲"
                                                   "顿时破体而入。\n你听到“嗤”的一声，"
                                                   "身上竟然溅到几滴鲜血！\n" NOR;

                }
        } else
        {
                me->start_busy(3);
                me->add("neili", -300);
                msg += CYN "$p" CYN "见$P" CYN "招式奇特，不感大"
                       "意，顿时向后跃数丈，躲闪开来。\n" NOR;
        }
        message_combatd(msg, me, target);

        if (damage < 0)
        {
                target->receive_wound("qi", 9000);
                target->receive_wound("jing", 2000);
                //target->die(me);
        }

        msg = HIG "\n紧跟着 突然间$N" HIG "指锋一转，力聚指尖“嗤”的弹出一道紫芒，直袭$n"
              HIG "气海大穴。\n" NOR;

        ap = me->query_skill("finger");
        dp = target->query_skill("force");

        damage = me->query_skill("finger");

        if (ap * 3 / 2 + random(ap) > dp)
        {
                target->receive_damage("jing", damage+100);
                target->receive_wound("jing", damage+100);
                target->add("neili", -damage * 3);

                if (target->query("neili") < 0)
                        target->set("neili", 0);

                msg += HIR "$n" HIR "只觉$N" HIR "指风袭体，随即上体一"
                       "阵冰凉，顿感真气涣散几欲晕厥。\n" NOR;
                me->start_busy(3);
        } else
        {
                msg += CYN "可是$p" CYN "防守严密，紧守门户，顿时令$P"
                       CYN "的攻势化为乌有。\n" NOR;
                me->start_busy(4);
        }
        message_combatd(msg, me, target);
    msg = HIC "\n最后$N" HIC "合指轻弹，只听破空声大作，一枚石子疾速飞出" +
             "，打向$n" HIC "。\n" NOR;

        me->start_busy(2);
        ap = me->query_skill("finger") + me->query_skill("throwing");
        dp = target->query_skill("dodge") + target->query_skill("parry");

        if (ap / 2 + random(ap) > dp)
        {
                msg += HIR "石子来得好快，$n"
                       HIR + "一个闪避不及，被打了个正中，浑身一"
                       "阵剧痛，整个人几乎都要散架了。\n" NOR;
                target->receive_damage("qi", damage+skill  + random(skill)+100);
                target->receive_wound("qi", damage+skill  + random(skill)+100);
                COMBAT_D->clear_ahinfo();

                if (stringp(pmsg = COMBAT_D->query_ahinfo()))
                        msg += pmsg;
                message_combatd(msg, me, target);
        } else
        {
                msg += CYN "可是$p" CYN "轻轻一闪，躲过了$P" HIG "发出的石子。\n" NOR;
                message_combatd(msg, me, target);
        }
me->add_temp("apply/attack", 100);
me->add_temp("apply/damage", 1500);
if (random(3)==0) target->start_busy(3);
	msg = CYN "$N双手一前一后，缓缓伸出，中指突地一弹，两道劲风汇成一股，“咝咝”有声，直袭$n前胸。\n";
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
 msg = HIY "$N扣住中指，哧哧哧连弹三下，三缕指风锋锐若剑，风驰电挚般射向$n的"+xuedao[random(sizeof(xuedao))]+"、"+xuedao[random(sizeof(xuedao))]+"、"+xuedao[random(sizeof(xuedao))];
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
 msg = HIC"$N扣起中指、无名指，一齐弹出，中指指劲激射$n"+xuedao[random(sizeof(xuedao))]+"，无名指上暗劲则已悄无声息的掩至"+xuedao[random(sizeof(xuedao))];
COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
msg= HIR"$N双足不丁不八，踏着东方乙木之位，食中二指反扣住拇指，一声长啸，反手弹出，但见一股凌厉无极的指劲激射向$n的"+xuedao[random(sizeof(xuedao))];
COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
msg=HIB"$N冷哼一声，双手笼入袖中，脸上青气一闪即逝，几缕指风已无声无息的袭向$n的"+xuedao[random(sizeof(xuedao))]+"、"+xuedao[random(sizeof(xuedao))]+"、"+xuedao[random(sizeof(xuedao))]+"数处要穴";
COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
msg=HIG"$N身子滴溜溜的打了半个圈子，丹田中提一口真气，青芒犹似长蛇般伸缩不定，蓦地真气突盛，刺向$n的"+xuedao[random(sizeof(xuedao))];
COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);        
me->add_temp("apply/attack", -100);
me->add_temp("apply/damage", -1500);

        return 1;
}

