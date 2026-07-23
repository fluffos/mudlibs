// ning@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string dodskill,msg;
	int extra;
	int tmp;
	object weapon;
        extra = me->query_skill("six-sword",1);
        if ( extra < 280) return notify_fail("你的［六阴追魂剑法］还不够纯熟！\n");
        if( me->query_skill("canhe-zhi",1) < 180 )
                return notify_fail("你的参合指火候不到，无法施展慕容家传绝学！\n");
        if ((int)me->query_skill("shenyuan-gong", 1) < 180)
                return notify_fail("你的神元功火候太浅。\n");
        if ((int)me->query_skill("murong-daofa", 1) < 180)
                return notify_fail("你的慕容刀法火候太浅。\n");
        if ((int)me->query_skill("yanling-shenfa", 1) < 180)
                return notify_fail("你的燕灵身法火候太浅。\n");
        if ((int)me->query_skill("xingyi-zhang", 1) < 180)
                return notify_fail("你的斗转星移掌火候太浅。\n");
        if ((int)me->query_skill("murong-jianfa", 1) < 180)
                return notify_fail("你的慕容剑法火候太浅。\n");
        if ((int)me->query_skill("qxxy-shou", 1) < 180)
                return notify_fail("你的七星星移手火候太浅。\n");
        if ((int)me->query_skill("canhe-zhi", 1) < 180)
                return notify_fail("你的参合指火候太浅。\n");
        if ((int)me->query_skill("douzhuan-xingyi", 1) < 180)
                return notify_fail("你的斗转星移火候太浅。\n");

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("［金风细雨得天下］只能对战斗中的对手使用。\n");
	weapon = me->query_temp("weapon");

        weapon = me->query_temp("weapon");
        if((int)me->query("neili") < 500 )
                return notify_fail("你现在内力不足，不能使用！\n");
                weapon = me->query_temp("weapon");
        if (!weapon || weapon->query("skill_type") != "sword"       )
                return notify_fail("你手里没有剑，无法使用！\n"); 
                if (extra>200) extra=200;
       msg = HIG  "$N使出六阴追魂剑法中的［金风细雨得天下］，一招连环两剑，\n手中的"+ weapon->name()+  HIG"闪电般向$n"HIG"攻出第一剑！" NOR;
        me->add_temp("apply/attack",extra);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/attack",-extra);
        msg = HIG  "第二剑！" NOR;
        me->add_temp("apply/damage",extra);
        me->add_temp("apply/attack",extra);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/damage",-extra);
        me->add_temp("apply/attack",-extra);
        if (extra<130) {
        me->start_busy(3);
        return 1;
        } 
        me->add_temp("apply/damage",extra*2);
        me->add_temp("apply/attack",extra);
        msg = HIG  "$N剑尖急抖，一片剑影中又攻出第三剑！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/damage",-extra*2);
        me->add_temp("apply/attack",-extra);
        me->start_busy(3);


       me->start_call_out( (: call_other, __FILE__, "third_sword", me, 
target,extra,weapon :), random(2)+1);
                         
        me->start_busy(3);
        return 1;               
        
 me->add("neili",-380);
        me->start_busy(3);
	return 1;
}
int third_sword(object me,object target,int extra,object weapon)
{
        string msg;
        int bonus, exp_bonus;
        if(!me||!target||!me->is_fighting(target)||environment(target)!=environment(me)) return 0;
        if(!present(weapon,me)||weapon->query("equipped")!="wielded") return 0;

		me->add_temp("apply/attack",100);
        me->add_temp("apply/damage",1000);
        msg = HIG  "$N剑尖急抖，一片剑影中又攻出第 三 剑!!！"+HIW"“波乱影难归。”" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
		me->add_temp("apply/attack",-100);
        me->add_temp("apply/damage",-1000);
if (random(5)==0) target->start_busy(3);
target->add("qi",-extra*2);
target->add("eff_qi",-extra);
msg = HIW"$N配合［斗转星移］双脚一顿，笔直跃起，手中"+ weapon->name() + HIW"不停地颤抖着\n随着李商隐的＜锦 瑟＞一诗剑光笼罩住$n全身！\n\n" NOR;
        message_vision(msg,me,target);
        msg = HIW  "锦瑟无端五十弦 \n" NOR + CYN "$N身形向上飘起，手中$w"NOR + CYN"虚虚实实纷纷扬扬撒向$n！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW  "一弦一柱思华年 \n" NOR + CYN "$N左手向$n面门一晃，右手$w"NOR + CYN"抖出一朵剑花刺向$n！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW  "庄生晓梦迷蝴蝶 \n" NOR + CYN "$N身形绕$n一转，手中$w"NOR + CYN"望空一指，幻出满天剑影，攻向$n！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW  "望帝春心托杜鹃 \n" NOR + CYN "$N身形飘然而起，悠然一剑手中$w若有若无淡淡刺向$n！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW  "沧海月明珠有泪 \n" NOR + CYN "$N纵起丈余，头下脚上，手中$w"NOR + CYN"舞成一个光球罩向$n！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW  "蓝田日暖玉生烟 \n" NOR + CYN "$N手中$w"NOR + CYN"嗡嗡微振，幻成一条白光刺向$n！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/damage",extra*4);
        msg = HIW  "此情可待成追忆 \n" NOR + HIC "$N纵身轻轻跃起，剑光如水，一泻千里，洒向$n全身！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/damage",-extra*4);
        me->add_temp("apply/damage",extra*10);
        msg = HIW  "只是当时已茫然 \n" NOR + HIC "$N手中$w"NOR + HIC"一沉，无声无息地滑向$n！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/damage",-extra*10);
        return 1;
}      
