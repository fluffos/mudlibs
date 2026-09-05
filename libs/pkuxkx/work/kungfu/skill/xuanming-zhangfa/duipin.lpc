//duipin 对拼内力

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        int skill,limit;

        limit = (me->query("con") + (int)me->query("max_neili") / 50) * 2;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("对拼内力只能对战斗中的对手使用。\n");

        if( me->query_temp("duipin"))
                return notify_fail("你正在与对手以内力对拼，不能分心！\n");

        msg = CYN "$N大喝一声，两掌已搭上$n的手，运起全身内力贯于双臂，欲以内力与$n相拼。\n"NOR;

        message_vision(msg, me, target);

	if (random((int)me->query_skill("dodge"))>random((int)target->query_skill("dodge")))
    {	message_vision(CYN"\n$N收手不及，只得运起全身内力，与$n全力一拼。\n"NOR,target,me);
        me->set_temp("duipin", 1);
	me->start_busy(1);
	target->start_busy(1);
        remove_call_out("get_effect");
        call_out("get_effect",1, me,target);
        return 1;
    }
	message_vision(CYN"$N身躯一扭，轻轻松松的躲开了。\n"NOR,target);
	return 1;
}

int get_effect(object me, object ob)
{	int my;
	int lose1=((int)me->query_skill("force",1) + (int)me->query("neili")) /10;
	int lose2=((int)ob->query_skill("force",1) + (int)ob->query("neili")) /10;
	if ((int)me->query("neili")>0 && (int)ob->query("neili")>0)
    {	me->add("neili",-random(lose2));
	ob->add("neili",-random(lose1));
	if (((int)me->query("neili")-50)>(int)ob->query("neili") && random (5)==1)
		message_vision(WHT"$N手上内力不断催动,内力如大江大海般一浪高过一浪，仿佛有无穷后劲。\n"
				"$n只觉的双臂酸麻，胸中凝滞，便似压着千钧重物，痛苦不堪。\n"NOR,me,ob);
	if (((int)ob->query("neili")-50)>(int)me->query("neili") && random(5)==1)
		message_vision(WHT"$N手上内力不断催动,内力如大江大海般一浪高过一浪，仿佛有无穷后劲。\n"
				"$n只觉的双臂酸麻，胸中凝滞，便似压着千钧重物，痛苦不堪。\n"NOR,ob,me);
	me->start_busy(2);
	ob->start_busy(2);
	call_out("get_effect",1,me,ob);
    	return 1;
    }
	if ((int)me->query("neili")<0 && (int)ob->query("neili")<0)
    {	message_vision("\n\n突然间，$N和$n相对大笑三声,双掌一分，两厢跳开，互相恭恭敬敬的一拱手，说声：乘让。\n\n",me,ob);
	me->unconsious();
	ob->unconsious();
        me->delete_temp("duipin");
        ob->delete_temp("duipin");
	return 1;
    }
	if ((int)me->query("neili")>(int)ob->query("neili"))
   {	my=(int)me->query("neili");
	if (random(my)>500)
      {	message_vision(HIY"\n\n骤然间$N冷笑一声：“不自量力！”随即鼓起全身内力一送而出。\n\n"NOR);
	message_vision(RED"只听一声惨叫，$n全身经脉寸断，狂吐鲜血而死,。\n",me,ob);
        me->delete_temp("duipin");
        ob->delete_temp("duipin");
        ob->receive_damage("qi", 0, me);
        ob->die();
      	return 1;
      }
	message_vision("\n$N几声冷笑，突然催动内力，只见$n一声闷哼，吐出一口鲜血，软瘫在地。\n\n",me,ob);
        me->delete_temp("duipin");
        ob->delete_temp("duipin");
	ob->unconsious();
	return 1;
   }
	if ((int)ob->query("neili")>(int)me->query("neili"))
   {	my=(int)ob->query("neili");
	if (random(my)>500)
      {	message_vision(HIY"\n\n骤然间$N冷笑一声：“不自量力！”随即鼓起全身内力一送而出。\n\n"NOR);
	message_vision(RED"只听一声惨叫，$n全身经脉寸断，狂吐鲜血而死。\n\n"NOR,ob,me);
        me->delete_temp("duipin");
        ob->delete_temp("duipin");
        ob->receive_damage("qi", 0, me);
        ob->die();
      	return 1;
      }
	message_vision("\n$N几声冷笑，突然催动内力，只见$n一声闷哼，吐出一口鲜血，软瘫在地。\n\n",ob,me);
        me->delete_temp("duipin");
        ob->delete_temp("duipin");
        ob->unconsious();
	return 1;
   }
}
