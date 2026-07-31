#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
string perform_name(){ return HBBLU"三阴毒蛭抓"NOR; }
int perform(object me, object target)
{
        object room, ob;
       if( !target ) target = offensive_target(me);

       if( !target || !me->is_fighting(target) )
            return notify_fail("「三阴抓」只能在战斗中对对手使用。\n");

       if( !userp(target))
            return notify_fail("你不能对他使用这个招数。\n");

        if(!( room = find_object("/d/taishan/fengchan")) )
                room = load_object("/d/taishan/fengchan");
        if( objectp(ob = present("zhong shentong", room)) ) {
                if(target->query("id") == ob->query("winner"))
                        return notify_fail("大胆！竟敢对中神通运用化功大法！\n");
        }

       if( target->query("combat_exp")<me->query("combat_exp"))
            return notify_fail("他对你来说没什么功力可以吸取了。\n");

       if( objectp(me->query_temp("weapon")) )
            return notify_fail("你必须空手才能使用「三阴抓」！\n");

       if( (int)me->query_skill("sanyin-zhua", 1) < 250 )
            return notify_fail("你的星宿毒抓还不够娴熟，使不出「三阴抓」绝技。\n");

       if( (int)me->query_skill("huagong-dafa",1) < 250 )
            return notify_fail("你的化功大法修为不够，不能使用「三阴抓」。\n");

       if((int)me->query_skill("poison",1)<200)
           return notify_fail("你积毒不够无法使用三阴抓。\n"); 

       if (me->query_skill_prepared("claw") != "sanyin-zhua"
        || me->query_skill_mapped("claw") != "sanyin-zhua"
        || me->query_skill_mapped("parry") != "sanyin-zhua")
           return notify_fail("你现在无法使用「三阴抓」！\n");

       if( (int)me->query("max_neili") < 3000) 
           return notify_fail("你内力太弱，使不出「三阴抓」。\n");

       if( (int)me->query("neili") < 6000)
           return notify_fail("你现在真气太弱，使不出「三阴抓」。\n");

     message_vision(HBBLU"$N伸出手来，突然抓向$n的丹田！\n"NOR,me,target);
     message_vision(HBBLU"$n只觉得$N用尽全力把全身的内力强行注入你体中！\n"NOR,me,target);
       if (!target->is_killing(me))
         me->kill_ob(target);
       me->start_perform(8, "三阴抓");
       target->add("neili",me->query("neili"));
       me->set("neili", 0);
       me->start_busy(random(2)+1);
       if (random(me->query("combat_exp")) > target->query("combat_exp")/2) {
     message_vision(HBRED"$n在强大的内力克制下，觉得功力不断流出！\n"NOR,me,target);
       me->add("combat_exp",me->query_skill("force")*10);
       target->add("combat_exp",-(me->query_skill("force")*25)); 
       target->apply_condition("xx_poison",random(10)+5);
	if (userp(me) && userp(target) && me->query_condition("killer") < 15)
		me->apply_condition("killer", 15);
       target->start_busy(3);
      } else {     message_vision(HBGRN"$n使出本门内功心法，反而使用$N的内力把$N逼了回去！\n"NOR,me,target);
      }
      return 1;
}

