// jin.c 武当绵掌之劲力
// By lius 99/8

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
  int i,j,p,k,z,damage;
        if( !target ) target = offensive_target(me);
        if( !target
        || !target->is_character()
        || !me->is_fighting(target) )
                return notify_fail("绵掌劲力只能在战斗中使用。\n");       
        if( objectp(me->query_temp("weapon")) )
               return notify_fail("先放下手中的武器再说吧！\n");
        if((int)me->query_skill("strike", 1) < 120 )
                return notify_fail("你的基本掌法太低，无法使用绵掌之劲力。\n");  
        if((int)me->query_skill("wudang-mianzhang", 1) < 120 )
                return notify_fail("你的绵掌还不够娴熟，不能使出绵掌之劲力。\n");
        if ( me->query_skill_mapped("parry") != "wudang-mianzhang")
                return notify_fail("你不使用绵掌，又岂能使得绵掌之劲力？！\n");   
        if ( me->query_skill_mapped("unarmed") != "wudang-mianzhang")
                return notify_fail("你不使用绵掌，又岂能使得绵掌之劲力？！\n");   

        if( (int)me->query("max_neili", 1) < 500 )
                return notify_fail("你内力修为太浅，无法运劲伤敌！\n");                
        if( (int)me->query("neili", 1) < 1000 )
                return notify_fail("你现在真气不够，不能发出绵掌之劲力。\n");
        if( (int)me->query("shen", 1) < 50000 )
                return notify_fail("你现在邪气迷心，岂能领会道家浩然之拳理？？\n");
        if(userp(me) && (int)me->query_skill("taiji-shengong", 1) < 120 )
                return notify_fail("你的本门内功等级不够，不能应用绵掌之劲力。\n");
        if(userp(me) && (int)me->query_skill("taoism", 1) < 100 )
                return notify_fail("练拳先修心，你对道学心法的领悟不够，是不能领悟绵掌之劲力的。\n");
        if(userp(me) && me->query_skill_mapped("force") != "taiji-shengong")
                return notify_fail("你的内功心法不对，发挥不出绵掌劲力之威。\n");                                                                                     
        
  i=me->query_skill("strike",1)+me->query_skill("wudang-mianzhang",1)+me->query_skill("force",1);
  j=target->query_skill("parry",1)+target->query_skill("dodge",1)+target->query_skill("force",1);
  p =(me->query("combat_exp",1)-target->query("combat_exp"))/200000;		 
     z = i/10 - j/10 + p;
     if ( z < 3 ) z = 3;
     if ( z > 13 ) z = 13;
     k = random(z) + 4;

        message_vision(HIY"$N双掌如游蛇，飘逸不定，以三十六路绵劲中的"MAG"[ 钻 ]"HIY"字诀，从$n的破绽中直插而进。\n"NOR,me, target);
         me->add("neili", -500);
         me->start_busy(3);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 2);
	 if ( me->is_fighting(target) && me->query_skill("wudang-mianzhang", 1) > 140 && k > 3 ){
	 message_vision(MAG"$N心中默念“不招不架，顺势而下。”掌掌紧贴$n关节，招招锁"HIG"[ 拿 ]"MAG"对方脉门，
$n顿时被逼得手忙脚乱。\n"NOR,me, target);
	  if (!target->is_busy())
	  target->start_busy(5);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 2);
       }
	 if ( me->is_fighting(target) && !me->query_temp("mz_jin") && me->query_skill("wudang-mianzhang", 1) > 160 && k > 6 ){
	 message_vision(HIG"$N漫不经心的东击一拳，西劈一掌，$n一个身影竟被你这若有若无，似虚还实的漫天掌影所"WHT"[ 封 ]"HIG"住，
空有一身功力也无法施展。\n"NOR,me, target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 2);
	  me->set_temp("mz_jin", 1);
        target->start_call_out((: call_other, __FILE__, "remove_effect", target :),i/6);
        }
	 if ( me->is_fighting(target) && me->query_skill("wudang-mianzhang", 1) > 180 && k > 10 ){
	 message_vision(WHT"$N见$n斗志已失，门户大开，当下再不犹豫，双掌一合，内劲外吐，"RED"[ 震 ]"WHT"字诀出手，已为三十六路绵劲
划下了一个完美的句号。\n"NOR,me, target);        
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 2);
		damage = i/3;	
		damage = damage/2 + random(damage);		
		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage);
		me->add("neili", -(200+random(100)));}
        return 1;
}

void remove_effect(object target)
{
      if(!target) return;      
      target->delete_temp("mz_jin");
      return 0;
}
