#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
        object soldier;
        int alert_time, btime;
		int random_cnt;
        int strategy,leadership, exp, MAX_GUARD;
        if ((string)me->query("class") != "officer")
        return notify_fail("你不是朝廷命官，还是自己照顾自己吧！\n");
//        if ( me->is_busy() )
//        return notify_fail("你现在正忙，无法呼唤大内高手。\n");
        if( !me->is_fighting() )
        return notify_fail("好象没有人要杀你！\n");
        
        if((int)me->query("jing")< 100)
        return notify_fail("你的精神太差了！\n");
        strategy = (int)me->query_skill("strategy", 1);
        leadership = (int)me->query_skill("leadership", 1);
        exp = (int)me->query("combat_exp");
        if(strategy < 10 || leadership < 10)
        return notify_fail("你兵法和用人之技太差了，没人愿意理你！\n");
        //两项技能均为200级，可以呼唤出5个大内高手,至少要5品官员才能使用
        //leadership 200 能召唤5个
   
        alert_time=30+(90 - strategy/2);
        if(alert_time<15) alert_time=15;
        MAX_GUARD = leadership  / 50 + 1;
		if(me->query("safari_skill/ct_alert") && (me->query("family/family_name")=="朝廷"))
		{
			alert_time -= leadership/150;
			if (alert_time < 10)
			{
				alert_time = 10;
			}
			MAX_GUARD += strategy/250;
			if (MAX_GUARD > 8)
			{
				MAX_GUARD = 8;
			}
		}
        if((time()-me->query("last_alert"))<alert_time)
        return notify_fail("你刚叫过大内高手，他们都被你叫烦了！\n");



        if( me->query_temp("max_guard") >= MAX_GUARD )
                return notify_fail("以你现在的官位，无法召唤更多的高手了！\n");
        if( me->query("pin") > 5 )
                return notify_fail("以你现在的官位，还无法呼唤高手帮忙！\n");
        seteuid(getuid());
        me->receive_damage("jing", 100);
        soldier= new("/d/beijing/npc/danei");
        soldier->move(environment(me));
        soldier->invocation(me, (leadership+strategy));
        soldier->set("possessed", me);
        //在副本里，让主人可以看到大内高手
        soldier->set_temp("seeme", me->query("id"));
        soldier->set_temp("do_attack_from", me);
        me->add_temp("max_guard",1);
        me->remove_all_killer();
        me->set("last_alert",time());
        message_vision(HIB "\n$N发出一声长啸求援！\n" NOR, me);
        message_vision(HIB "\n$N应声而来！\n" NOR, soldier);
        if (!me->is_busy())
          me->start_busy(1);
        else
        {	random_cnt=10;
			if(me->query("safari_skill/ct_alert") && (me->query("family/family_name")=="朝廷"))
			{
				if ((!me->query("chushi/done")) && (!me->query("betrayer")))
				{
					random_cnt=10 + ( strategy + leadership )/80;
					if (random_cnt > 34)
					{
						random_cnt = 34;
					}
					if ( me->query_temp("busy_stat/type") == "jiemai" &&
					   me->query_temp("busy_stat/time")>time() )
						{
							if ( random(100)<random_cnt )
							{
								me->start_busy(0);
								me->delete_temp("busy_stat");
								message_vision(HIB "\n$N解除了$n身上的痛苦！\n" NOR, soldier, me);
							}
							else
							{
								btime=me->query_busy();
								me->start_busy(btime/2);
								me->set_temp("busy_stat/time", time()+btime/2 );
								message_vision(HIB "\n$N缓解了$n身上的痛苦！\n" NOR, soldier, me);
							}
						}
				}
			}
        	//如果主角处于busy状态并且busy类型是缠绕有一定概率减少或者解除busy
        	if ( me->query_temp("busy_stat/type") == "body" &&
        		   me->query_temp("busy_stat/time")>time() )
        	{
        		if ( random(100)<random_cnt )
        		{
        			me->start_busy(0);
        			me->delete_temp("busy_stat");
        			message_vision(HIB "\n$N解除了$n身上的束缚！\n" NOR, soldier, me);
        		}
        		else
        		{
        			btime=me->query_busy();
        			me->start_busy(btime/2);
        			me->set_temp("busy_stat/time", time()+btime/2 );
        			message_vision(HIB "\n$N缓解了$n身上的束缚！\n" NOR, soldier, me);
        		}
        	}
        }

        return 1;
}

int help(object me)
{
        write(@HELP
指令格式：alert

这个指令让官员呼唤高手来保护自己。
能否招呼出高手，呼出高手水平的高低就要看官员
官职的大小了以及为官之道和兵法策略的等级高低了。

HELP
    );
    return 1;
}

