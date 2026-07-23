// snowman
#include <ansi.h>

int check_fight(object me);
int remove_effect(object me);
int perform(object me)
{
        if( !me->is_fighting() || !living(me))
                return notify_fail("「红莲火」只能在战斗中的使用。\n");

        if(objectp(me->query_temp("weapon")) )
                return notify_fail("你必须空手才能运用「红莲火」！\n");
        if(me->query_temp("honglian"))        
                return notify_fail("你正在使用「红莲火」。\n");  
        if(me->query_temp("mz_lx"))        
                return notify_fail("你正在使用「降妖伏魔咒」。\n");  
        if((int)me->query_skill("huoyan-dao", 1) < 180 )
                return notify_fail("你的火焰刀不够娴熟，还不能领会「红莲火」之诀窍。\n");
        if( (int)me->query("max_neili", 1) < 1500 )
                return notify_fail("你的内力修为太弱，使不出「红莲火」。\n");                
        if( (int)me->query("neili", 1) < 800 )
                return notify_fail("你现在真气不够，使不出「红莲火」。\n");
        if(userp(me) && (int)me->query_skill("xiaowuxiang", 1) < 100 )
                return notify_fail("你的小无相功等级不够高，使不出「红莲火」。\n");
        if(userp(me) && (int)me->query_skill("lamaism", 1) < 150 )
                return notify_fail("你对密宗心法的领悟不够，无法使用「红莲火」。\n");
        if (userp(me) && me->query_skill_mapped("parry") != "huoyan-dao")
                return notify_fail("「红莲火」必须在激发招架的情况下才能使用。\n");
        message_vision(RED"\n$N祭起火焰刀之「红莲火」绝技，精纯的内力呈红色缓缓涌出，于身前三尺之处，便即停住不动，
将这飘荡无定的真气定在半空，它虽是虚无缥缈，不可捉摸，却能杀人于无形，实是厉害不过！\n"NOR,me);
        me->start_busy(1);
        me->set_temp("honglian", 1);
        me->add("neili", -300);
        me->add_temp("apply/parry", me->query_skill("huoyan-dao", 1)/2);
        me->add_temp("apply/arrmor", me->query_skill("huoyan-dao", 1)/2);
        check_fight(me);
        return 1;
}

int check_fight(object me)
{
        object *enemy, target;
        int sz;        

	if (!me) return 0;
        if(me->is_ghost() || !living(me) || environment(me)->query("no_fight") || me->query_temp("weapon")){
           me->add_temp("apply/parry", -me->query_skill("huoyan-dao", 1)/2);
           me->add_temp("apply/arrmor",-me->query_skill("huoyan-dao", 1)/2);
           me->delete_temp("honglian");
           return 0;
           }        

        me->add("neili", -5);
        enemy = me->query_enemy();
        if( !enemy || !arrayp(enemy) ) remove_effect(me);
        sz = sizeof(enemy);
        if( sz > 4 ) sz = 4;
        if( sz > 0 ) target = enemy[random(sz)];
        else remove_effect(me);
        if(!me->query_temp("honglian")) return 1;
        else if(!me->is_fighting()){
                if(!me->query_temp("stopped")){
                    me->set_temp("stopped", 1);
                    call_out("check_fight", 2, me);
                    }
                else remove_effect(me);
                }
       else if (userp(me) && (me->query_skill_mapped("strike") != "huoyan-dao" || me->query_skill_mapped("parry") != "huoyan-dao")){
                  message_vision(HIY"$N一刀劈出，突然变招，竟然是完全不同的招数来！\n"NOR,me);
                  me->add_temp("apply/parry", -me->query_skill("huoyan-dao", 1)/2);
                  me->add_temp("apply/arrmor", -me->query_skill("huoyan-dao", 1)/2);
                  me->delete_temp("honglian");
                  return 1;
                  }   
       else if( me->query("neili") <= 10 || !target ) remove_effect(me);
       else call_out("check_fight", 1, me);
       return 1;
}       

int remove_effect(object me)
{
   string msg;
   msg = "/kungfu/skill/huoyan-dao"->query_skill_name(me->query_skill("huoyan-dao", 1));
   message_vision(HIY "\n$N回手一招"+msg+"使完，双手合十立于当地，示慈悲为怀。\n\n"NOR, me);
   me->add_temp("apply/parry", -me->query_skill("huoyan-dao", 1)/2);
   me->add_temp("apply/armor", -me->query_skill("huoyan-dao", 1)/2);
   me->delete_temp("honglian");
   me->delete_temp("stopped");
   remove_call_out("check_fight"); 
   return 0;
}
