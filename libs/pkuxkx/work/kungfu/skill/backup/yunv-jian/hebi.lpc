// hebi.c
// by dubei
#include <ansi.h>
inherit F_SSERVER;
protected int remove_effect(object me, int skill);
int perform(object me, string arg)
{
    object weapon, weapon1, target;
    int skill, skill1;

    if(!arg) return notify_fail("你想和谁一起双剑合璧？\n");
    if(!objectp(target = present(arg, environment(me))))
             return notify_fail("这里没有这个人。\n");

    if( !target->is_fighting() || !target->is_character() || !me->is_fighting() )
                return notify_fail("双剑合璧只能在战斗中使用。\n");

    if(!living(target))
                return notify_fail(target->name()+"已经无法战斗了。\n"); 
    if(target==me) return notify_fail("想和自己合璧？\n"); 
    if(me->is_fighting(target))
                return notify_fail("你正在和"+target->name()+"打架呢。\n");            

    weapon = me->query_temp("weapon");  
    weapon1 = target->query_temp("weapon");  

    if(!weapon || weapon->query("skill_type") != "sword"
      || me->query_skill_mapped("sword") != "yunv-jian"
      || me->query_skill_mapped("parry") != "yunv-jian")
        return notify_fail("你要把玉女剑做为sword,parry才能用「双剑合璧」。\n");

    if(!weapon1 || weapon1->query("skill_type") != "sword"
      || target->query_skill_mapped("sword") != "yunv-jian"
      || target->query_skill_mapped("parry") != "yunv-jian")
        return notify_fail(target->name()+"要把玉女剑做为sword,parry才能用「双剑合璧」。\n");

    skill = me->query_skill("yunv-jian", 1);
    skill1 = target->query_skill("yunv-jian", 1);
    
    if(skill < 120 )
        return notify_fail("你的玉女剑法等级不够，不能使用「双剑合璧」。\n");
    
    if( skill1 < 120 )
	return notify_fail( target->name()+"的玉女剑法不够纯熟，无法和你配合使用「双剑合璧」。\n");

    if((int)me->query_skill("yunv-xinfa", 1) < 120 )
        return notify_fail("你的玉女心法等级不够，不能使用「双剑合璧」。\n");       

    if((int)target->query_skill("yunv-xinfa", 1) < 120 )
        return notify_fail(target->name()+"的玉女剑法不够纯熟，无法和你配合使用「双剑合璧」。\n");       
    
    if((int)me->query("neili") < 300 )
        return notify_fail("你现在真气太弱，不能使用「双剑合璧」。\n");

    if((int)target->query("neili") < 300 )
        return notify_fail( target->name()+"现在真气太弱，不能使用「双剑合璧」。\n");

    if((int)me->query("eff_neili") < 500 )
        return notify_fail("你现在内力太弱，不能使用「双剑合璧」。\n");

    if((int)target->query("eff_neili") < 500 )
        return notify_fail("你现在内力太弱，不能使用「双剑合璧」。\n");

    if(me->query_temp("gumu_hebi")) 
        return notify_fail("你已经在使用「双剑合璧」了。\n");

    if(target->query_temp("gumu_hebi")) 
        return notify_fail(target->name()+"已经在使用「双剑合璧」了。\n");
    
    if(me->query_temp("gmhebi_target")){
          if(me->query_temp("gmhebi_target")==target)
                return notify_fail("你已经做好和"+target->name()+"双剑合璧的准备了。\n");
          else{               
               tell_object(me->query_temp("gmhebi_target"), YEL+me->name()+"决定不和你进行双剑合璧了。\n"NOR); 
               me->delete_temp("gmhebi_target");
               }
          }
    if(target->query_temp("prepare_gmhebi")) {
	message_vision(HIC"$N长啸一声，将手中"+weapon->name()+"一摆，好象给了$n一个信号。\n"NOR,me,target);
        message_vision(HIC"$n将手中"+weapon->name()+"一摆，架在$N的"+weapon1->name()+"上，双刀相加，顿时光芒四射，声震天地！\n"NOR,me,target);
        me->delete_temp("prepare_gmhebi", 1);     
        me->delete_temp("gmhebi_target", 1);
        me->set_temp("gumu_hebi", target); 
        target->set_temp("gumu_hebi", 1); 
        me->add("neili", -300);
        target->add("neili", -300);
        me->add("jing", -50);
        target->add("jing", -50);
        me->add_temp("apply/attack", skill);
        me->add_temp("apply/dexerity", skill/15);
        target->add_temp("apply/attack", skill1);
        target->add_temp("apply/dexerity", skill1/15);
        me->start_call_out( (: call_other, __FILE__, "check_fight", me, target, skill :), 1);
        target->start_call_out( (: call_other, __FILE__, "check_fight", target, me, skill1 :), 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill :), (skill+skill1)/2);
        target->start_call_out( (: call_other, __FILE__, "remove_effect", target, skill1 :), (skill+skill1)/2);
        return 1;
        }
    message_vision(YEL"$N将手中"+weapon->name()+"一横，暗示$n和$P一起运用双剑合璧。\n"NOR,me,target);
    tell_object(target, YEL"你如果愿意和"+me->name()+"进行双剑和壁，请也对"+me->name()+"下一次 ( perform hebi player<name> ) 的命令。\n"NOR); 
    me->set_temp("prepare_gmhebi", 1);     
    me->set_temp("gmhebi_target", target);
    return 1;
}

void check_fight(object me, object target, int skill, int skill1)
{
    object weapon;      

    if(!objectp(weapon = me->query_temp("weapon")) 
     || !objectp(weapon = target->query_temp("weapon"))
     || (string)weapon->query("skill_type") != "blade")
    {
    me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill :), 1);
    target->start_call_out( (: call_other, __FILE__, "remove_effect", target, skill :), 1);
    remove_effect(target, 1);
    remove_effect(me, 1);
	}
    else if( !present(target->query("id"), environment(me)) 
	  || !me->is_fighting() 
	  || !living(target) 
	  || !target->is_fighting()
          || target->is_ghost() 
	  || me->is_ghost() 
	  || !living(me)) {

    me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill :), 1);
    target->start_call_out( (: call_other, __FILE__, "remove_effect", target, skill1 :), 1);
    remove_effect(target, 1);
    remove_effect(me, 1);
	}
    else {
	call_out("check_fight", 1, me, target, skill);
	 return;
	}
}
protected int remove_effect(object me, object target)
{
    int skill;
    me->add_temp("apply/attack", -skill/15);
    me->add_temp("apply/dexerity", -skill/15);
    me->delete_temp("shuangdao_hebi");
    me->delete_temp("gmhebi_target");
    me->delete_temp("prepare_gmhebi");     
    target->delete_temp("gumu_hebi");
    target->delete_temp("prepare_gmhebi");  
    target->delete_temp("gmhebi_target");   
    tell_object(me, HIR"$N的双剑合璧完结，攻守也恢复正常了。\n"NOR);
    tell_object(target, HIR"$n的双剑合璧完结，攻守也恢复正常了。\n"NOR);
}
 