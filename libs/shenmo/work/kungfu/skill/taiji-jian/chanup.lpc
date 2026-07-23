// chan.c 太极剑法「缠」字诀

#include <ansi.h>
inherit F_SSERVER;
int checking(object me, object target, object weapon);

string *number_msg = ({"一","二","三","四","五","六","七","八","九","十","十数","千百","无数"});
string *sword_msg = ({"反撩","斜刺","上挑","下划","正劈","直刺","后拉","前推"});

string *chan_msg = ({
CYN"$N以意驭剑，$S画出$R个"RED"圆圈"CYN"，其千变万化，无穷无尽，要去包裹缠住$n！\n" NOR,
CYN"$N以意驭剑，$S画出$R个"RED"圆圈"CYN"，前后排列，要将$n包裹起来！\n" NOR,
CYN"$N心中不存半点渣滓，以意驭剑，$W"CYN"每发一招，便似放出一条"RED"细丝"CYN"，要去缠住$n！\n"NOR,
CYN"$N以意驭剑，$S画出$R个"RED"圆圈"CYN"，正反相交，要将$n缠在正中！\n" NOR,
CYN"$N手中$W"CYN"挥动，驱太极剑意散发出根根"RED"细丝"CYN"，要将$n裹起来！\n"NOR,
CYN"$N以意驭剑，$S画出$R个"RED"圆圈"CYN"，上下包容，要将$n包裹起来！\n" NOR,
CYN"$N的一柄$W"CYN"画着一个个"RED"圆圈"CYN"，每一招均是以弧形刺出，以弧形收回，缠住$n！\n"NOR,
CYN"$N以意驭剑，$S画出$R个"RED"圆圈"CYN"，左右兼顾，要将$n缠在正中！\n" NOR,
});

string *dodged = ({
HIY"可是$n已然看穿了$P的招数，孤注一掷直入圈心，破了$N的太极剑意！\n\n" NOR,
HIY"$n微觉$N招数涩滞，急忙变招，竭尽全身之力中宫疾进，从剑光圈中冲了出去！\n\n"NOR,
HIY"$n微觉$N招数涩滞，急忙变招，竭尽全身之力飞跃后退，远离了剑圈！\n\n"NOR,
HIY"$n看得真切，回招挡格了$N中宫一剑，接着纵身一跃，已逃出圈外。\n\n"NOR,
});

string *chaned = ({
HIW"结果$n的招数渐见涩滞，偶尔发出一招，真气运得不足，便被$W"HIW"带着连转几个圈子。\n"NOR,
HIW"结果太极剑意散发出的细丝越积越多，似是积成了一团团丝棉，将$n紧紧裹了起来！\n"NOR,
HIW"结果，剑气似是积成了一团团丝棉，将$n紧紧裹了起来！\n"NOR,
HIW"$n越斗越是害怕，一个疏忽，被太极剑意紧紧裹了起来！\n"NOR,
});

int perform(object me, object target)
{
        object weapon = me->query_temp("weapon");
        int cost = me->query_skill("taiji-jian", 1)/2;
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("牵制攻击只能对战斗中的对手使用。\n");

        if(!living(target))
                return notify_fail("「缠」不能动的人？\n");
        if(!weapon || weapon->query("skill_type") != "sword" )
                return notify_fail("你手中无剑，如何使得「缠」字诀？\n");
        if(me->query_temp("tjj/chan"))
                return notify_fail("你正在使用「缠」字诀。\n");
        if( target->is_busy() )
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");
        if( (int)me->query_skill("taiji-jian", 1) < 100 )
                return notify_fail("你的太极剑法极不够娴熟，不会使用「缠」字诀。\n");
        if( me->query("neili") <= 500 )
                return notify_fail("你的内力不够！\n");
        if( me->query("neili") <= 700 )
                return notify_fail("你的内力修为不够！\n");
        if(me->query_temp("combat_yield"))
                return notify_fail("你不出剑，何以使得「缠」字诀？\n");
        if (me->query_skill_mapped("sword") != "taiji-jian")
                 return notify_fail("你现在无法使用「缠」字诀。\n");
        if(userp(me)){
//            if (me->query_skill_mapped("parry") != "taiji-jian")
//                return notify_fail("你没有把太级剑法做为parry!.\n");       
            if( (int)me->query_skill("taiji-shengong", 1) < 100 )
                return notify_fail("你的太极神功修为不够，不会使用「缠」字诀。\n");
            if( me->query_skill_mapped("force") != "taiji-shengong")
                return notify_fail("你所用的内功与太极剑意气路相悖！\n");
            }
        me->add("neili", -cost);
        me->add("jing", -10);

if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/4 ) {
        message_vision(CYN"\n$N使出太极剑法"RED"「缠」"CYN"字诀，一柄"+weapon->name()+CYN"在画着一个个圆圈，每一招均是以弧形刺出，弧形收回。
神在剑先，绵绵不绝，便如撒出了一张大网，逐步向$n收紧！\n\n"NOR, me, target);
        target->start_busy(3);
        me->start_busy(1);
        me->set_temp("tjj/chan", 1);
        call_out("check_fight", 2, me, target, weapon);
        return 1;
        }
        else {
        message_vision(CYN"\n$n看破了$N的企图，镇定逾恒，全神应对自如。\n"NOR, me, target);
//        msg += "可是$p看破了$P的企图，镇定逾恒，全神应对自如。\n" NOR;
        me->start_busy(2);
        }

}

int check_fight(object me, object target, object weapon)
{
        string msg;
        object wep;

        if (!me) return 1;
        if(!me->query_temp("tjj/chan")) return 1;

        if(!living(me) || !target){
           me->delete_temp("tjj/chan");
           return 1;
        }
        
        if(!objectp(wep = me->query_temp("weapon")) || wep->query("skill_type") != "sword"){
           if(!wep)msg = HIY"$N手中武器既失，圆转的太极剑幕也随之消散，$n不禁松了口气．\n"NOR;
           else  msg = HIY"$N亮出"+wep->name()+HIY"而撤回太极剑意，$n身边密布的剑幕也随之消散，压力骤然减轻！\n"NOR;
           if(target->is_busy()) target->start_busy(2);
           me->start_busy(1);
           me->delete_temp("tjj/chan");
           message_vision(msg, me, target);
           return 1;
           } 
        if(environment(me) != environment(target)){
        	msg = HIY"$N将手中"+wep->name()+HIY"向后一摆，抱圆守一，撤回了散开的太极剑意．\n"NOR;
                me->delete_temp("tjj/chan");
                message_vision(msg, me, target);
                return 1;
                }
        if(!me->is_fighting(target) && !me->is_killing(target->query("id"))){
           if(!living(target)) msg = HIY"$N不屑地望了$n一眼，将手中"+wep->name()+HIY"一向后摆，撤回了散开的剑幕．\n"NOR;
           else msg = HIY"$N将手中"+wep->name()+HIY"向后一摆，抱圆守一，撤回了散开的太极剑意．\n"NOR;
           if(target->is_busy()) target->start_busy(2);
           me->delete_temp("tjj/chan");
           message_vision(msg, me, target);
           return 1;
           }           

        if(wep != weapon){
           message_vision(HIY"$N撤后换剑，剑势顿时无法圆转如意，$n身边的太极剑幕威力骤减，使$n有了喘息之机会！\n"NOR,me, target);
           me->start_busy(1);
           if(target->is_busy() 
              && random(me->query_skill("taiji-jian", 1)) < (int)target->query_skill("dodge", 1)/2){
              target->start_busy(2);
              me->delete_temp("tjj/chan");
              return 1;
              }
           else {
		call_out("checking", 1, me, target, wep);
	   }
          }
       if (userp(me) && (me->query_skill_mapped("sword") != "taiji-jian" || me->query_skill_mapped("parry") != "taiji-jian")){
           message_vision(HIY"$N突然变招，划破剑幕，使出和太极剑法完全不同的招数来！\n"NOR,me);
           if(target->is_busy()) target->start_busy(3);
           me->start_busy(1);
           me->delete_temp("tjj/chan");
           return 1;
           }   
       if( me->query("neili") <= me->query_skill("taiji-jian", 1)/2 ){
           message_vision(HIY"$N剑招渐见涩滞，偶尔一剑刺出竟然软弱无力，原来是真气不足了！\n"NOR,me);
           if(target->is_busy()) target->start_busy(2);
           me->start_busy(1);
           me->delete_temp("tjj/chan");
           return 1;
           }           

       if(!target->is_busy() && !me->is_busy() && random(4)==1 && living(target)){
          msg = chan_msg[random(sizeof(chan_msg))];
          msg = replace_string(msg, "$S", sword_msg[random(sizeof(sword_msg))]);
          msg = replace_string(msg, "$R", number_msg[random(sizeof(number_msg))]);
          msg = replace_string(msg, "$W", wep->name());
          message_vision(msg, me, target);
          checking(me, target, wep);
          }
       else {
	call_out("check_fight", 1, me, target, wep);
       }
       return 1;
}       


int checking(object me, object target, object weapon)
{
        string msg;
        int busy_time, ap, dp, cost;
        cost = 20 * target->query_temp("tjj/"+me->query("id")) + me->query_skill("taiji-jian", 1)/2;
        busy_time = (int)me->query_skill("taiji-jian", 1)/20;
        ap = me->query("combat_exp")/1000 * me->query_skill("taiji-jian",1) * me->query_int();
        dp = target->query("combat_exp")/1000 * target->query_skill("dodge",1) * target->query_int();
        if (ap < 1) ap = 1;
        if (dp < 1) dp = 1;

        me->add("neili", -cost);
        me->add("jing", -10);
        if(random(ap) > dp/2){          
          target->start_busy(2+random(busy_time));
          msg = chaned[random(sizeof(chaned))];
          msg = replace_string(msg, "$W", weapon->name());
          message_vision(msg, me, target);
          call_out("check_fight", 1, me, target, weapon);
          }
        else{
          me->start_busy(3);
          me->delete_temp("tjj/chan");
          msg = dodged[random(sizeof(dodged))];
          msg = replace_string(msg, "$W", weapon->name());
          message_vision(msg, me, target);
          }
       return 1;
}       

