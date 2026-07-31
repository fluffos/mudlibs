//昆仑正两仪剑之双剑合壁
//update by cool 981104
#include <ansi.h>
inherit F_SSERVER;
//int remove_effect(object me);
int perform(object me, string arg)
{
    object weapon, weapon1, target;
    int skill, skill1;
    string msg;

    if(!arg) return notify_fail("你想和谁一起合璧？\n");
    if(!objectp(target = present(arg, environment(me))))
             return notify_fail("这里没有这个人。\n");
/*需要判断是否攻击同一个人*/
    if( !target->is_fighting() || !target->is_character() || !me->is_fighting())
                return notify_fail("合璧只能在战斗中使用。\n");
    if(!living(target))
                return notify_fail(target->name()+"已经无法战斗了。\n"); 
    if(target==me) return notify_fail("和自己合璧？\n"); 
    if(me->is_fighting(target))
                return notify_fail("你正在和"+target->name()+"打架呢。\n");            

    weapon = me->query_temp("weapon");  
    weapon1 = target->query_temp("weapon");  

    if(!weapon || weapon->query("skill_type") != "sword"
      || me->query_skill_mapped("sword") != "liangyi-jian"
      || me->query_skill_mapped("parry") != "liangyi-jian")
        return notify_fail("你现在无法使用「双剑合璧」。\n");

    if(!weapon1 || weapon1->query("skill_type") != "sword"
      || target->query_skill_mapped("sword") != "liangyi-jian"
      || target->query_skill_mapped("parry") != "liangyi-jian")
        return notify_fail(target->name()+"现在无法使用「双剑合璧」。\n");

    skill = me->query_skill("liangyi-jian", 1);
    skill1 = target->query_skill("liangyi-jian", 1);

    if(skill < 100 )
        return notify_fail("你的两仪剑法等级不够，不能使用「双剑合璧」。\n");
    
    if((int)me->query_skill("xuantian-wuji", 1) < 100 )
        return notify_fail("你的玄天无级功等级不够，不能使用「双剑合璧」。\n");       
    
    if((int)me->query("neili") < 500 )
        return notify_fail("你现在真气太弱，不能使用「双剑合璧」。\n");
    if((int)me->query("max_neili") < 1000 )
        return notify_fail("你现在内力太弱，不能使用「双剑合璧」。\n");

    if(me->query_temp("ly_hebi")) 
        return notify_fail("你已经在使用「双剑合璧」了。\n");

   if(target->query_temp("ly_hebi")) 
        return notify_fail(target->name()+"已经在和他人使用「双剑合璧」了。\n");

          
    if(me->query_temp("lyhebi_target")){
          if(me->query_temp("lyhebi_target")==target)
                return notify_fail("你已经做好和"+target->name()+"双剑合璧的准备了。\n");
          else{
               tell_object(me->query_temp("hebi_target"), YEL+me->name()+"不打算和你进行双剑合璧了。\n"NOR); 
                me->delete_temp("lyprepare_hebi");
                me->delete_temp("lyhebi_target");
               }
          }
     if(target->query_temp("lyprepare_hebi") && target->query_temp("lyhebi_target") ==me){
        message_vision(MAG"\n $N对$n使个眼色,手中"+weapon->name()+MAG+"和$n的"+weapon1->name()+MAG+"交错相击，双剑齐上，顿时只见剑光凌厉，威力大增！\n"NOR, me, target);
       me->delete_temp("lyprepare_hebi");
       me->delete_temp("lyhebi_target");
       target->delete_temp("lyprepare_hebi");
        target->delete_temp("lyhebi_target");
        me->set_temp("ly_hebi", 1); 
        target->set_temp("ly_hebi", 1); 
        me->add("neili", -300);
        target->add("neili", -300);
        me->add("jingli", -50);
        target->add("jingli", -50);
        remove_call_out("check_reply");
        me->start_call_out( (: call_other, __FILE__, "check_fight", me, target :), 1);
        target->start_call_out( (: call_other, __FILE__, "check_fight", target, me :), 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), (skill+skill1)/2);
        target->start_call_out( (: call_other, __FILE__, "remove_effect", target :), (skill+skill1)/2);
        return 1;
        }
    message_vision(HIC"\n $N将手中"+weapon->name()+HIC"一横，暗示$n和$P一起运用双剑合璧。\n"NOR, me, target);
    tell_object(target, YEL"你如果愿意和"+me->name()+"进行双剑和壁，请也对"+me->name()+"下一次 ( perform hebi <player's id> ) 的命令。\n"NOR); 
    me->set_temp("lyprepare_hebi", 1);     
    me->set_temp("lyhebi_target", target);
      call_out("check_reply", 15, me); 
    return 1;
}

void check_fight(object me, object target)
{
    object weapon,weapon1;  
    
 	weapon = me->query_temp("weapon");  
      weapon1 = target->query_temp("weapon");  

    if(!weapon || weapon->query("skill_type") != "sword"
      || me->query_skill_mapped("sword") != "liangyi-jian"
      || me->query_skill_mapped("parry") != "liangyi-jian")
         call_out("remove_effect", 0, me);

    if(!weapon1 || weapon1->query("skill_type") != "sword"
      || target->query_skill_mapped("sword") != "liangyi-jian"
      || target->query_skill_mapped("parry") != "liangyi-jian")
		  call_out("remove_effect", 0, me);

     else if((!present(target->query("id"), environment(me))) ||
            !me->is_fighting() || !living(target) || !target->is_fighting()
            || target->is_ghost() || me->is_ghost() || !living(me)
            || !target->query_temp("ly_hebi"))
         call_out("remove_effect", 0, me);

    else call_out("check_fight", 1, me, target);
}
void check_reply(object me)
{
if (me->query_temp("lyprepare_hebi", 1)) {     
        me->delete_temp("lyprepare_hebi");     
        me->delete_temp("lyhebi_target");
            return notify_fail("似乎对方对你的暗示没有反应，你在只好取消了双剑合壁的请求。\n");
}   
}
void remove_effect(object me)
{
  if(me->query_temp("ly_hebi")){
    me->delete_temp("ly_hebi");
	return notify_fail(HIR"你双剑合璧完结，攻守也恢复正常了。\n"NOR);
       }
}