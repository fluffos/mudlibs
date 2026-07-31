//tianlei.c 峨嵋山最终技 天雷合一 海上飘(piao)
#include <ansi.h>
#include <combat.h> 
void tianlei_ok(object);
inherit SSERVER;
int perform(object me, object target)
{
              string str;
              object weapon;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这一招「"HIW"天雷合并"NOR"」？\n");
        if(!me->is_fighting())
                return notify_fail("「"HIW"天雷合并"NOR"」只能在战斗中使用！\n");
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
              return notify_fail(" 你使用的武器不对，无法施展「"HIW"天雷合并"NOR"」。\n");
        if (me->query_skill_mapped("force")!="emeiforce")
                return notify_fail("「"HIW"天雷合并"NOR"」必须配合峨嵋心法才能使用。\n");
          if((int)me->query("force") < 1000 )
		  return notify_fail("你的内力不足！\n");
        if((int)me->query("max_force") < 3000 )
                return notify_fail("你的内力不够！\n");
        if((int)me->query("sen") < 1000 )
                return notify_fail("你的精神不足，没法子施用外功！\n");
        if((int)me->query("combat_exp") < 1500000 )
                return notify_fail("你武学经验不够，领悟不到「"HIW"天雷合并"NOR"」！\n");
        if( me->query("force_factor") > 0)
                return notify_fail("「"HIW"天雷合并"NOR"」绝技重招不重力。加力出招怎能剑走轻灵？\n");
        if((int)me->query_skill("emeiforce",1) < 180 )
                return notify_fail("你的峨嵋心法级别还不够，使不出「"HIW"天雷合并"NOR"」！\n");
        if((int)me->query_skill("zhutian-bu",1) < 180 )
                return notify_fail("你的诸天化身步级别还不够，使不出「"HIW"天雷合并"NOR"」！\n");
        if((int)me->query_skill("jinding-zhang",1) < 180 )
                return notify_fail("你的金顶绵掌级别还不够，使不出「"HIW"天雷合并"NOR"」！\n");
        if((int)me->query_skill("tianlei-sword", 1) < 180 )
                return notify_fail("你的天雷双剑还不够，使用这一招会有困难！\n");
        if(me->query_temp("no_tianlei"))  //在此处设置标志位 ;
		return notify_fail("你刚刚使过「"HIW"天雷合并"NOR"」,先歇一歇吧。\n");
        me->delete("env/brief_message");
	target->delete("env/brief_message");

message_vision(HIM "$N右手幻出一道红光，正是天玑剑！"HIG"左手幻出一道绿光，正是雷炎剑。\n"NOR,me,target);
message_vision(HIW"双手缓缓之间将此二剑并为一处，瞬间化作一条彩虹进入流光速，正是一招「"HIC"天雷合并"HIW"」。\n"NOR,me,target);
message_vision(HIC"$n还没有来得及看清楚是怎么回事，以被彩虹透体而过。\n" NOR,me,target);
        me->set_temp("QJB_perform", 1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->set_temp("QJB_perform", 2);  
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 

        me->set_temp("QJB_perform", 3);  
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 

        me->set_temp("QJB_perform", 4);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        if( (int)me->query_skill("tianlei-sword", 1) > 150 ) {
message_vision(HIR"┏━━┓\n"NOR,me,target);
message_vision(HIR"┃ "HIY"天"HIR" ┃\n"NOR,me,target);
message_vision(HIR"┗━━┛\n"NOR,me,target);
        me->set_temp("QJB_perform", 5);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
}
        if( (int)me->query_skill("tianlei-sword", 1) > 160 ) {
message_vision(HIR"          ┏━━┓\n"NOR,me,target);
message_vision(HIR"          ┃ "HIY"雷"HIR" ┃\n"NOR,me,target);
message_vision(HIR"          ┗━━┛\n"NOR,me,target);
        me->set_temp("QJB_perform", 6);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
}
        if( (int)me->query_skill("tianlei-sword", 1) > 170 ) {
message_vision(HIR"                    ┏━━┓\n"NOR,me,target);
message_vision(HIR"                    ┃ "HIY"合"HIR" ┃\n"NOR,me,target);
message_vision(HIR"                    ┗━━┛\n"NOR,me,target);
        me->set_temp("QJB_perform", 7);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
}
        if( (int)me->query_skill("tianlei-sword", 1) > 180 ) {
message_vision(HIR"                               ┏━━┓\n"NOR,me,target);
message_vision(HIR"                               ┃ "HIY"并"HIR" ┃\n"NOR,me,target);
message_vision(HIR"                               ┗━━┛\n"NOR,me,target);
        me->set_temp("QJB_perform", 8);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
}
        if( (int)me->query_skill("tianlei-sword", 1) > 190 ) {
message_vision(HIR"                               ┏━━┓\n"NOR,me,target);
message_vision(HIR"                               ┃ "HIY"天"HIR" ┃\n"NOR,me,target);
message_vision(HIR"                               ┗━━┛\n"NOR,me,target);
        me->set_temp("QJB_perform", 9);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
}
        if( (int)me->query_skill("tianlei-sword", 1) > 200 ) {
message_vision(HIR"                    ┏━━┓\n"NOR,me,target);
message_vision(HIR"                    ┃ "HIY"雷"HIR" ┃\n"NOR,me,target);
message_vision(HIR"                    ┗━━┛\n"NOR,me,target);
        me->set_temp("QJB_perform", 10);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
}
        if( (int)me->query_skill("tianlei-sword", 1) > 210 ) {
message_vision(HIR"          ┏━━┓\n"NOR,me,target);
message_vision(HIR"          ┃ "HIY"合"HIR" ┃\n"NOR,me,target);
message_vision(HIR"          ┗━━┛\n"NOR,me,target);
        me->set_temp("QJB_perform", 11);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
}
        if( (int)me->query_skill("tianlei-sword", 1) > 220 ) {
message_vision(HIR"┏━━┓\n"NOR,me,target);
message_vision(HIR"┃ "HIY"并"HIR" ┃\n"NOR,me,target);
message_vision(HIR"┗━━┛\n"NOR,me,target);
        me->set_temp("QJB_perform", 12);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
}
 if (target->query("eff_kee")<0 || !living(target))  
{str=target->name()+"被"+""HIW""+me->name()+""HIM""+"用峨嵋山的绝招『"HIW"天雷合并"HIM"』杀死了。听说尸体被天雷烧成了灰烬！";
        message("channel:rumor",HIM"【"HIW"空穴来凤"HIM"】某人："+str+"\n"NOR,users());
	               }
        me->delete_temp("QJB_perform");
        me->receive_damage("sen", 100);
        me->add("force", -1000);
        me->set_temp("no_tianlei",1); ;
        me->start_busy(3);
        call_out("tianlei_ok",20+random(10),me); ;
        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }
        return 1;
}
void tianlei_ok(object me) 
{ if (!me) return; 
      me->delete_temp("no_tianlei"); 
}












