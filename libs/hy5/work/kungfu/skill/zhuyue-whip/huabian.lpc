//BY Cigar 2002.01 huabian.c <花变>
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;


void huabian_ok(object);

int perform(object me, object target)
{
        int damage;
        object weapon;
 string msg;
        int skill, ap, dp, neili_wound, qi_wound;
        int i, attack_time;        
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("无事花变小心天变人怨？\n");
        if(!me->is_fighting())
                return notify_fail("「花变」只能在战斗中使用！\n");
        if((int)me->query("max_neili") < 500 )
                return notify_fail("你的内力不够！\n");
          if((int)me->query("neili") < 500 )
                return notify_fail("你的内力不足！\n");
        if((int)me->query("jing") < 150 )
                return notify_fail("你的精神不足，没法子施用外功！\n");
        if((int)me->query_skill("zhuyue-whip", 1) < 100)
                return notify_fail("你的逐月鞭法不够熟练，使用这一招会有困难！\n");

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


        me->delete("env/brief_message");
        target->delete("env/brief_message");
message_vision(HIW"\n$N看着遍地含苞待放的花朵，情到一处油然而生，顺口吟道："+HIR""BLINK"≈≈花变≈≈"NOR""+HIW"吾心不变......\n"NOR,me,target);
message_vision(HIG"\n            “人间花开，春去天涯，红药万株，天然浩态狂香”。\n"NOR,me,target);
message_vision(HIG"\n            “尊贵御衣，独占花王，困倚凝香，用花千万余枝”。\n"NOR,me,target);
message_vision(HIG"\n            “人诧奇芳，结蕊当屏，怜葩就幄，红掩绿绕华堂”。\n"NOR,me,target);
message_vision(HIG"\n            “秉兰观雨，花面交相，幽意难忘，罢酒风亭梦魂”。\n"NOR,me,target);
message_vision(HIC"\n“天香染露，最忆当年，无限春风恨，夜深花睡冷香，多情芳心轻吐，问："+HIR"‘世间情为何物’"+HIC"”\n"NOR,me,target);
              damage=200+(int)me->query_skill("parry")+random((int)me->query_skill("whip"));
 if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
{
              message_vision(HIW"\n$n眼前遍地花草争奇斗艳，被这如此出奇美景早已迷的心乱如麻，顿感心力交瘁。\n"NOR,me,target);
             target->receive_damage("qi",damage,me);
              target->receive_wound("qi",damage,me);
             target->receive_damage("jing",damage,me);
              target->receive_wound("jing",damage,me);
                target->start_busy(random(2));
             COMBAT_D->report_status(target);
}
else {
  message_vision(HIY"\n$n心平气和，盘膝而座，怀中掏出玉酿美酒，合着此情此景独自享用起来。\n"NOR,me,target);
                target->start_busy(1);
             }

 if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/4 || random(3)==0) {
         attack_time = random((int)me->query_skill("zhuyue-whip", 1) / 30);
        if (attack_time > 7 ) attack_time=7;
                       me->add_temp("apply/attack", 100);
        me->add_temp("apply/damage", 2000);
        for(i = 0; i < attack_time; i++){
         msg = HIW "$N婉尔一笑，不退反进，一鞭打出 身形径向$n飘来。！\n" NOR;
       COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
                        }
                                               me->add_temp("apply/attack", -100);
        me->add_temp("apply/damage", -2000);
        me->start_busy(2);
}
if (me && target && msg)  message_combatd(msg, me, target);
me->start_busy(3);
        //me->receive_damage("jing", 50);
        me->add("neili", -100);
        me->set_temp("no_huabian",1);
                call_out("huabian_ok",1+random(2),me);


return 1;
}

void huabian_ok(object me)
{
if (!me) return;
      me->delete_temp("no_huabian");
}
