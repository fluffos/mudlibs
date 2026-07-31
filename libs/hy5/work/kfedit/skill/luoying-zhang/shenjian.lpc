// shenjian.c 桃花影里飞神剑

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

#include "/kungfu/skill/eff_msg.h"

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
        string msg;
        object weapon;
        int damage, rand, p;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("桃花影里飞神剑只能对战斗中的对手使用。\n");

//        if (!(me->query("thd/perform") & 2))
//                return notify_fail("你虽然听说过“桃花影里飞神剑”这一招，可是却未获传授。\n");
        if( objectp(me->query_temp("weapon")) )
               return notify_fail("你必须空手使用桃花影里飞神剑！\n");
        if( (int)me->query_skill("luoying-zhang", 1) < 80 )
                return notify_fail("你的落英神剑掌不够娴熟，无法使用桃花影里飞神剑。\n");
        if ((int)me->query_skill("bibo-shengong", 1) < 80)
                return notify_fail("你的碧波神功火候不够，无法施展桃花影里飞神剑。\n");
        if ( (int)me->query("neili") < 120)
                return notify_fail("你的内力不够，无法使用桃花影里飞神剑。\n");
        if ( me->query_skill_mapped("strike") != "luoying-zhang")
                return notify_fail("你现在无法使用桃花影里飞神剑进行攻击！\n");

        msg = CYN "\n$N双掌竖起，默运碧波神功，掌缘便似剑锋一样发出丝丝的"GRN"剑气"CYN"，分别从左右两边斩向$n！\n"NOR;
        rand = random(me->query("combat_exp"));
        if( rand > (int)target->query("combat_exp")/3 ) {
                me->add("neili", -100);
                me->start_busy(2);
                damage = (int)me->query_skill("luoying-zhang", 1)*2+random(damage/2);
                damage += random(damage);
                target->receive_damage("qi", damage*2);
                target->receive_wound("qi", damage);
                p = (int)target->query("qi") * 100 / (int)target->query("max_qi");
                msg += damage_msg(damage, "劈伤");
                msg += "( $n" + eff_status_msg(p) + " )\n";
                } 
        else {
                me->add("neili", -50);
                me->start_busy(1);
                msg += HIY"$n大吃一惊，退步抽身，万分惊险中堪堪躲过了这招，早已吓出了一身冷汗！\n" NOR;
        }
        message_vision(msg, me, target);


me->add_temp("apply/attack", 80);
me->add_temp("apply/damage", 300);
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
me->add_temp("apply/attack", -80);
me->add_temp("apply/damage", -300);

        return 1;
}
