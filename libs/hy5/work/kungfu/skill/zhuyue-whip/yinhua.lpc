//BY Cigar 2002.01 yinhua.c [吟花一笑]
#include <ansi.h>

#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg;
        object weapon;
//        string msg;
        int skill, ap, dp, neili_wound, qi_wound;
        int i, attack_time;
        
        if (!target ) target = offensive_target(me);
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "whip")
             return notify_fail(MAG"开什么玩笑，没装备就想使「吟花一笑」？\n"NOR);
        if (!target || !target->is_character() || !me->is_fighting(target) )
             return notify_fail("「吟花一笑」只能对战斗中的对手使用。\n");

        if ((int)me->query_skill("zhuyue-whip",1) < 100 )
             return notify_fail(WHT"你的逐月鞭法不够娴熟，还使不出「吟花一笑」。\n"NOR);
        if ((int)me->query("max_neili")<1000)
             return notify_fail(RED"你的内力修为不足，无法运足「吟花一笑」的内力。\n"NOR);
        if ((int)me->query("neili")<500)
        {
               return notify_fail(HIC"你现在内力不够，没能将「吟花一笑」使完！\n"NOR);
        }
        

      if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("只能在战斗中使用。\n");
        
    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "whip")
        return notify_fail(RED"开什么玩笑，武器不对？\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "bitao-shengong")
                return notify_fail("请使用碧涛心法!\n");

        if((int)me->query_skill("bitao-shengong",1) < 100)
                return notify_fail("你的碧涛心法还不够。。。\n"); 
        
        msg = HIY "$N心驰神往，似眼望窗儿外，漫山遍野、深谷幽处的千花百草，心有怜惜"+BLINK""HIR"§吟花一笑§\n"NOR;
        msg += HIG"玉肌翠袖，冰葩淡不妆，一只云髻人宜，刻玉雕琼作小葩。\n"NOR;
        msg += HIG"便舞春风，无情犹感会，一段冰壶剪就，西风偷得余香去。\n"NOR;
        msg += HIG"烛光花影，花枝红裹烛，珠星碧月彩云，人间别有几春风。\n"NOR;
        msg += HIC"昨夜雨疏，浓睡消残酒，胭脂谁与匀淡，香雾空蒙月转，试问眷恋人，知否？知否？\n"NOR;
        if (random(me->query_skill("force"))>target->query_skill("force")/2|| 
           random(me->query("combat_exp"))>(int)target->query("combat_exp")/3 || random(3)==0)
        {
                me->start_busy(2);
                target->start_busy(1+random(3));
                damage = (int)me->query_skill("whip", 1);
                damage = 300+damage + random(damage);
                target->receive_damage("qi", damage,me);
                target->receive_wound("qi", damage,me);
                target->receive_damage("jing", damage,me);
                target->receive_wound("jing", damage/3,me);
        msg += HIM"$n心旷神怡，手中玉酿美酒随之坠落，破碎之声惊醒$n的春阁一梦，顿觉心乱如麻。\n"NOR;
        msg += HIM"$N的"+HIR"§吟花一笑§"+HIM"早已惊散了$n的三魂六魄......\n"NOR;
        target->apply_condition("flower_poison",15+random(25) + target->query_condition("flower_poison"));
                me->add("neili", -100);
        } else
        {
               
        msg += HIW"可是$n欣喜若狂，侧身轻跃，站在$N一旁，手持玉酿美酒小酌，欣赏此情此景。\n"NOR;
        msg += HIW"$N心中直觉郁闷无比，见欣赏才情此景的人竟是泛泛之辈，也无心吟花了。\n"NOR;
                me->add("neili", -50);
        }
        message_vision(msg, me, target);

  if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/4  || random(3)==0) {
         attack_time = random((int)me->query_skill("zhuyue-whip", 1) / 30);
        if (attack_time > 7 ) attack_time=7;
                me->add_temp("apply/attack", 100);
        me->add_temp("apply/damage", 2000);
        for(i = 0; i < attack_time; i++){
         msg = HIW "$N身法轻灵，腰肢几拧，居然幻出斑驳月影！\n" NOR;
       COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
                        }
                  me->add_temp("apply/attack", -100);
        me->add_temp("apply/damage", -2000);
        
}
me->start_busy(2);
        message_combatd(msg, me, target);
        
        //if(!target->is_fighting(me)) target->fight_ob(me);
//      if(userp(target)) target->fight_ob(me);
//      else if( !target->is_killing(me) ) target->kill_ob(me);
        return 1;
}
