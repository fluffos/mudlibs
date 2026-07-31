#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
    int damage,damagea;
    string msg;
    object weapon;
       int p,skill;
       int d;
       
    if (!target ) target = offensive_target(me);
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "blade")
   return notify_fail(RED"开什么玩笑，没装备刀怎么使「无形幻影」？\n"NOR);
    if (!target || !target->is_character() || !me->is_fighting(target) )
   return notify_fail("「无形幻影」只能对战斗中的对手使用。\n");
    if ((int)me->query_skill("zileidao", 1) < 90 )
   return notify_fail(WHT"你的紫雷刀法不够娴熟，还使不出「无形幻影」。\n"NOR);

if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("只能在战斗中使用。\n");

 if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
        return notify_fail(RED"开什么玩笑，武器不对？\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "lengyue-shengong")
                return notify_fail("请使用冷月神功!\n");

        if((int)me->query_skill("lengyue-shengong",1) < 200)
                return notify_fail("你的冷月神功还不够。。。\n"); 
        if((int)me->query("neili") < 1800 )
                return notify_fail(WHT"你的内力不足。\n"NOR);
   
    if ((int)me->query("max_neili")<1800)
   return notify_fail(RED"你的内力修为不足，无法运足「无形幻影」的内力。\n"NOR);
    if ((int)me->query("neili")<1800)   
          return notify_fail(HIC"你现在内力不够，没能将「无形幻影」使完！\n"NOR);
  
    msg = HIC "$N大喝一声，全场四处游动，$n只看到$N化做数团身影，漫天刀光席卷而来，\n$n奋力一架，但$N刀分数路，$n只架住一刀！\n"NOR;
    if (random(me->query_skill("force")) > target->query_skill("force")/3||
   random((int)target->query("combat_exp")) < (me->query("combat_exp")) )
    {
   
   damage = 200+(int)me->query_skill("zileidao", 1);
   damage = damage + random(damage);
   target->receive_damage("qi", damage);
   target->receive_wound("qi", damage/3);

   target->receive_damage("jing", damage/4);
   msg += HIC"$n根本没法躲避，顿时几刀都砍在$n肩头！\n"+HIR"$n鲜血溅起，$n自觉眼前一片鲜红，遮住视线！\n"NOR;

     me->start_busy(random(3));

    }else
    {
   me->start_busy(2);
   msg += HIY"可是$p早以看出那是虚招，毫不在意地坦然面对，果真只有架住的是实招。\n"NOR;
    }
   me->add("neili", -150);
    message_vision(msg, me, target);
if ((int)me->query_skill("zileidao", 1)>= 200)
{
   message_vision(HIM"紧接着 $N前后游走，身形闪动，手中"+BLINK""+ weapon->name()+ NOR" "+HIM"越使越快，刀光身影绚烂如百花齐放。\n\n"HIC"$n"HIC"随着$N的"BLINK""+weapon->name()+ NOR""+HIC"来回游走，终于却被刀光惑得眼花缭乱。\n"NOR,me,target);
           target->add("neili",-300);
           target->add("qi", -50);
        if(!target->is_busy()) target->start_busy(2);
        me->add_temp("apply/attack", 100);
        me->add_temp("apply/damage", 800);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));         
        me->add_temp("apply/attack", -100);
        me->add_temp("apply/damage", -800);

}

if ((int)me->query_skill("zileidao", 1)>= 380)
{
 d = (int)me->query_skill("zileidao",1);       
 skill = me->query_skill("zileidao",1)/2;
           damage = 200+skill*2 + random(skill);
           damage = damage + random(damage);
  message_vision(HIR"\n$N刀过头顶，积聚全身力量，一刀劈出\n\n"NOR,me,target);
message_vision(MAG"\n刀锋带着一道紫色火焰划过,犹如一只火鸟\n"NOR,me,target);
     COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
if (random(me->query_skill("force")) > target->query_skill("force")/3){
          target->receive_damage("qi", damage);
          target->receive_wound("qi", damage/3);
  message_vision(HIB"\n$n周身被紫色火焰包围着......\n"NOR,me,target);
       }
       else{
  message_vision(HIG"\n$n急忙后跃，才将将躲开火焰的攻击！\n"NOR,me,target);
     me->start_busy(2);
     //me->add("qi",-100);
     me->add("neili", -100);
       }      
    message_vision(HIW"\n
$N默运冷月神功，刀爪齐施，晃晃刀影中，夹杂着无数爪风。
霎时间，风走沙滚，刀光爪影，当真是刀刀连身，爪爪要命"NOR,me,target);
       target->start_busy(2);
        me->add_temp("apply/attack", 100);
        me->add_temp("apply/damage", 800);
       COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
       COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
       COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
               me->add_temp("apply/attack", -100);
        me->add_temp("apply/damage", -800);
       target->add("neili", -skill*2);    
       target->add("qi", -100);


}

if ((int)me->query_skill("zileidao", 1)>= 680 || !userp(me))
{
	damagea=200+random((int)me->query_skill("dodge")*2);
if(random((int)target->query("combat_exp")) < (int)me->query("combat_exp"))
{
              message_vision(HIW"\n$N刀势突转使出紫雷神刀的绝学--玲珑连环！！\n"NOR,me,target); 

              message_vision(HIG"\n第一招----风玲珑，$N手中的利刃如一阵疾风般攻向$n！\n"NOR,me,target);
              // modify by mudring ....nk bug....hmm..
              target->receive_damage("qi", damagea);
              target->receive_wound("qi", damagea/2);
              target->receive_damage("jing", damagea/4);
              target->start_busy(2);
              COMBAT_D->report_status(target);
}
if ((int)me->query_skill("zileidao", 1)>= 980 || !userp(me))
{
	        me->add_temp("apply/attack", 100);
        me->add_temp("apply/damage", 800);
              message_vision(HIM"\n第二招——花玲珑，$N手中的利刃连刺五刀如一朵盛放的梅花！\n"NOR,me,target);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

                message_vision(HIW"\n第三招——雪玲珑！$N手中的利刃突闪一道寒光，如片片雪花！。\n"NOR,me,target);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

                message_vision(HIC"\n第四招——月玲珑！$N手中的利刃从上至下，之劈下来，犹如一轮弯月！”\n"NOR,me,target);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
               damage=200+(int)me->query_skill("blade")+random((int)me->query_skill("parry"));

        me->add_temp("apply/attack", -100);
        me->add_temp("apply/damage", -800);
if(random((int)target->query("combat_exp"))<(int)me->query("combat_exp"))
{

               message_vision(HIG"\n风花雪月·玲珑连环\n"NOR,me,target);

              target->receive_damage("qi", damage/2);
              target->receive_wound("qi", damage/3);
              COMBAT_D->report_status(target);
}
}
  me->add("neili", -100);



}
 me->start_busy(2);
    return 1;
}
