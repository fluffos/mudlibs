// qixing. 松鹤绝命剑

#include <ansi.h>

inherit F_SSERVER;
string query_name() { return "松鹤"ZJBR"绝命"; }
int perform(object me, object target)
{
        string msg;
        object weapon = me->query_temp("weapon");
        int ap,dp,damage;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("松鹤绝命剑只能对战斗中的对手使用。\n");

    if( (int)me->query_skill("songhe-sword", 1) < 120 )
                return notify_fail("你的松鹤剑法不够熟练，使不出松鹤绝命剑。\n");
  
    if (!weapon || weapon->query("skill_type") != "sword"
        || me->query_skill_mapped("sword") != "songhe-sword")
                return notify_fail("你现在无法使用松鹤绝命剑。\n");

    if ( (int)me->query("neili") < 1000)
                return notify_fail("你的内力不够，无法使用松鹤绝命剑。\n");

        msg = HIY"\n$N一声长啸，一抖手中剑，顿时形成一道剑幕，狂风暴雨般压向$n。就在
$n慌乱之间，剑幕中飞出七朵寒星，如流星般射向$n。\n\n"NOR;

      ap = me->query_skill("sword");
      dp = target->query_skill("dodge", 1) + target->query_skill("parry", 1); 
        if (ap / 2 + random(ap) > dp)
{
                msg +=HIR"$n躲闪不及，已然中剑！\n"NOR;
                damage = 3*(int)me->query_skill("sword");
                if (damage > target->query("neili") / 10)
                damage -= target->query("neili") / 10;
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/3);
                if( damage < 40 ) msg += HIR"$n已身中数剑，身上到处是血。\n"NOR;
                else if( damage < 80 ) msg += HIR"$n身中七剑，鲜血狂喷而出！\n"NOR;
                else msg += HIR"$n“哇”的狂叫一声，身上喷出七道血剑！\n"NOR;
                message_vision(msg, me, target);
        } 
        else {
                msg += HIC"$n情急之中向后激飞，随机趴下，堪堪躲过了这致命一击。\n"NOR;
                message_vision(msg, me, target);
        }
        me->add("neili", -80);
        me->start_busy(2);

        return 1;
}

