// riyue.c 日月神技

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

void check_fight(object me,object target,object weapon,int count);
int perform(object me, object target)
{
        object weapon = me->query_temp("weapon");  
        string msg;
        int ap,dp,damage,i,improve,jl,time;

        if( !target ) target = offensive_target(me);

        if (!weapon || weapon->query("skill_type") != "whip")
                return notify_fail("你手里无鞭，无法使用「日月神鞭」！\n");

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("[日月神鞭]只能在战斗中使用。\n");

        if ((int)me->query_temp("ryb_yue"))
                return notify_fail("你正在使用「日月神鞭」绝技。\n"); 

        if( me->query_temp("fumo"))
                return notify_fail("你正在使用大金刚拳的特殊攻击「金刚伏魔」！\n");

        if ((int)me->query_temp("ryb_fumo") ) 
                return notify_fail("你正在使用「金刚伏魔圈」。\n");

        if( (int)me->query_skill("yijin-jing", 1) < 140 )
                return notify_fail("你的易筋经修为不够，使不出「日月神鞭」绝技。\n");

        if (me->query_skill_mapped("force") != "yijin-jing")
                return notify_fail("没有易肋经法作为根基，是无法使出「日月神鞭」绝技的！\n"); 

        if((int)me->query_skill("riyue-bian",1) < 150)
                return notify_fail("你的日月鞭法修为不够,目前还不能使用「日月神鞭」！\n");

        if ((int)me->query_skill("buddhism",1)<140)
                return notify_fail("佛门神功，慈悲为怀，你佛法修为甚浅，如何使用这门神功？\n");

        if((int)me->query("max_neili") < 2500)
                return notify_fail("你内力修为现在不够, 不能用「日月神鞭」！\n");

        if ((int)me->query("neili") < 1200)
                return notify_fail("你内力用尽, 不能用「日月神鞭」！\n");


        me->add("neili",- 700); 
        improve =(int)me->query_skill("buddhism", 1) / 5;
        time = improve/2;
        me->set_temp("ryb_yue",improve); 
        me->add_temp("apply/strength", improve);
        me->add_temp("apply/attack", improve);
        call_out("check_fight", 1 , me, target, weapon, time);
        me->start_perform(5 ,"日月神鞭");
        if (random((int)me->query_skill("riyue-bian",1)+(int)me->query_skill("buddhism",1)+(int)me->query_skill("whip",1)) > 450)
         i=0;
        else if(random((int)me->query_skill("riyue-bian",1)+(int)me->query_skill("buddhism",1)+(int)me->query_skill("whip",1)) > 400)
         i=1;
        else 
         i=2;
     
//      tell_object(me,"i=%d",i);  
        switch (i){
          case 0:
            msg= HIC"$N口中高宣佛号，使出日月鞭中「日月」绝技，手中长索滚动飞舞，宛若灵蛇乱颤，自上而下劈向$n,\n";
            msg+=   "接着$N手腕一抖，便如张牙舞爪的墨龙相似，急升而上，又往$n扑到。\n"NOR;
            message_vision(msg, me, target);
            ap = random(me->query("combat_exp")+me->query_skill("buddhism",1))*(1+random(me->query("int")/4));
            dp = (int)target->query("combat_exp")/2; 
            if(ap > dp ) {
              damage=me->query_skill("riyue-bian",1)+me->query_skill("whip",1)+me->query_skill("buddhism",1);
              damage=damage*(1+random(2));   
              if (damage>2000) damage=2000;
              msg=CYN"$n大惊失色，躲闪不及，被淹没在漫天鞭影当中。\n"NOR;
              target->receive_damage("qi",damage);
//            target->receive_damage("jingli",damage/2);
              target->receive_wound("qi",damage/3);
              target->stary_busy(random(5));
              message_vision(msg, me, target); 
            }
            else {
              msg="$n早知日月鞭法的厉害,一见鞭出早以跳出圈外。\n";
              me->start_busy(random(10));
              message_vision(msg, me, target);
            }
          break;     

          case 1:    
            msg=HIY"$N高宣“阿弥陀佛！”，使出「日」字诀，手中长索一扬，向$n的咽喉点去，索头未到，索上所挟劲风\n";
            msg+=  "犹如红日当空，令对方一阵气窒，只听见「啪啪」几声巨响，索头昂起，便如一条假死的毒蛇忽地反噬挥动，\n";
            msg+=  "带动无数风沙，呼啸而出。\n"NOR;
            message_vision(msg, me, target);
            for (jl=0; jl<2; jl++)
            COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SUPER);
            me->start_busy(2);
          break;

          case 2:
            msg=HBCYN "$N又宣“我佛慈悲！”，使出「月」字诀，内力返照空明，功力精纯，不露棱角，手中长索舞动时瞧不见\n";
            msg+=     "半点影子无声无息，似缓实急，却又无半点风声，如鬼似魅，说不尽的诡异莫名。\n"NOR;
            message_vision(msg, me, target);
          break;   
        }
}

void check_fight(object me,object weapon,object target,int count)
{  
       object wep;
       int i;
       if(!me) return;     
       if( !target
        || !me->is_fighting()
        || !living(me)
        || me->is_ghost() 
        || !objectp(wep = me->query_temp("weapon"))
        || weapon != wep
        || count < 1 ){
           i = me->query_temp("ryb_yue");
           me->add_temp("apply/strength", -i);
           me->add_temp("apply/attack", -i);
           me->delete_temp("ryb_yue");
           if(living(me) && !me->is_ghost())
                 message_vision(HIC"\n只听见$N一声轻叹，长索渐渐缓慢下来。\n"NOR, me);
       }
       else {
           call_out("check_fight", 1, me, weapon,target,count -1);
           me->start_perform(1,"「日月神鞭」");
       }
}
