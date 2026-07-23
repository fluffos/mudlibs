//by sdong 07/98

#include <ansi.h>

inherit F_SSERVER;

private int remove_effect(object me, int amount,object weapon);

int perform(object me, object target)
{
        int skill, skill1, skill2;
        object victim;
        object weapon,weapon2;
    object *inv;
    int i, count;
        string bei_skill;

        if( !victim ) victim = offensive_target(me);


        if( !victim || !victim->is_character() || !me->is_fighting(victim) )
                return notify_fail("双剑和璧左右互搏只能对战斗中的对手使用。\n");


        if(     me->query_skill("yunv-jian",1) < 1 ||
                me->query_skill("quanzhen-jian",1) < 1 
                )
                return notify_fail("必须通晓并备有玉女剑法与全真剑法才能双剑和璧左右互搏！\n");

        if(me->query_skill("quanzhen-jian",1) <120)
                return notify_fail("你的全真剑法不够熟练，不能双剑和璧左右互搏！\n");

        if(me->query_skill("yunv-jian",1) <180)
                return notify_fail("你的玉女剑法不够熟练，不能双剑和璧左右互搏！\n");

        if( me->query_skill_mapped("force") != "yunv-xinfa" 
                )
                return notify_fail("你所用的并非玉女心经，无法施展双剑和璧左右互搏！\n");

        if( me->query_skill("yunv-xinfa", 1) < 180 
                )
                return notify_fail("你的玉女心经火候未到，无法施展双剑和璧左右互搏！\n");
        if( !objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword" )
                return notify_fail("必须持有双剑才能和璧左右互搏！\n");

     inv = all_inventory(me);
     for(count=0, i=0; i<sizeof(inv); i++) {
           if( inv[i]->query("equipped") || weapon == inv[i] ) continue;
           if( inv[i]->query("skill_type") == "sword" ) 
                   {
                           weapon2 = inv[i];
                           break;
                   }
     }
        if( me->query("neili") <= 400 )
                return notify_fail("你的内力不够使用双剑和璧左右互搏！\n");
        if( me->query("jing") <= 100 )
                return notify_fail("你的精不够使用双剑和璧左右互搏！\n");

        skill =  ( me->query_skill("yunv-jian",1) + me->query_skill("yunv-jian",1)
                + me->query_skill("quanzhen-jian",1) +me->query_skill("yunv-xinfa",1) 
                + me->query_skill("yunv-xinfa")) / 10; 
        message_vision(
        HIR "$N突然间左手抽出另一把剑，双手使出截然不同的剑法，正是左右互搏绝技。\n"+HIC"只见$N双剑一交，左右手玉女剑法与全真剑法配合得天衣无缝，攻守之势猛然大增！\n\n" NOR, me);

        me->add_temp("apply/attack", skill/2);
        me->add_temp("apply/damage", skill/2);
        me->add_temp("apply/dodge",  skill/2);
        me->add_temp("apply/parry",  skill/2);
        me->set_temp("hubo", 1);

    me->add_temp("apply/damage", 180);

        bei_skill = me->query_skill_mapped("sword");
    me->map_skill("sword", "yunv-jian");
        message_vision(HIG"浪迹天涯！\n" NOR,me,target);
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
    me->map_skill("sword", "quanzhen-jian");
        me->setup();
        message_vision(HIY"花前月下！\n" NOR,me,target);
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
    me->map_skill("sword", "yunv-jian");
        me->setup();
        message_vision(HIG"抚琴按萧！\n" NOR,me,target);
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
    me->map_skill("sword", "quanzhen-jian");

        message_vision(
        HIR "$N剑招愈来愈怪,可是互相呼应，厉害杀招却是层出不穷\n" NOR, me);

        me->setup();
        message_vision(HIY"小园艺菊！\n" NOR,me,target);
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
    me->map_skill("sword", "yunv-jian");
        me->setup();
        message_vision(HIG"西窗夜话！\n" NOR,me,target);
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
    me->map_skill("sword", "quanzhen-jian");
        me->setup();
        message_vision(HIY"松下对弈！\n" NOR,me,target);
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
    me->map_skill("sword", "quanzhen-jian");
        me->setup();
        message_vision(HIG"清饮小酎！\n" NOR,me,target);
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));

    me->map_skill("sword", bei_skill);
        me->setup();
    me->add_temp("apply/damage", -180);
        me->add("jing", -50);
        me->add("neili", -400);
        me->start_busy(2+random(2));


        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/2,weapon2 :), 6);
        return 1;
}

private int remove_effect(object me, int amount,object weapon)
{
        int skill;
        skill =  ( me->query_skill("yunv-jian",1) + me->query_skill("yunv-jian",1)
                + me->query_skill("quanzhen-jian",1) +me->query_skill("yunv-xinfa",1) 
                + me->query_skill("yunv-xinfa")) / 10; 

        me->add_temp("apply/attack", -skill/2);
        me->add_temp("apply/damage", -skill/2);
        me->add_temp("apply/parry", -skill/2);
        me->add_temp("apply/dodge", -skill/2);
        me->delete_temp("hubo");
        message_vision(
        HIY "\n$N吸了一口气，左手潇洒地将手足的剑" + HIY "插回剑鞘，收回左右互搏绝技！\n\n" NOR, me,weapon);

        return 0;
}
