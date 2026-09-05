#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
        object soldier;
        int btime, bindex;
        int zhaosheshu,MAX_GUARD;

        if( !me->is_fighting() )
                return notify_fail("没事召蛇出来干什么？会吓到小朋友的！\n");
                
        if((int)me->query("neili")< 50)
                return notify_fail("你的内力太差了！\n");
                
        zhaosheshu = (int)me->query_skill("zhaosheshu");
        bindex = zhaosheshu/100;  
        if (bindex<=2) bindex=2;
        if (bindex>=5) bindex=5;
        if(zhaosheshu < 10  )
        return notify_fail("你招蛇之术太差了，没有蛇肯来帮你！\n");       
        
        MAX_GUARD = zhaosheshu * zhaosheshu / 5000 + 1;
        
        if ((int)me->query_temp("zhaoshe_time")>time())  
                return notify_fail("你刚招过蛇！休息一下吧！\n");

        if( me->query_temp("max_guard") > MAX_GUARD )
                return notify_fail("以你现在的能力，你已经没有能力控制更多的蛇了！\n");
                
        seteuid(getuid());
        me->add("neili",-50);
        soldier= new("clone/misc/jinshe");
        soldier->move(environment(me));
        soldier->invocation(me, (zhaosheshu*2));
        soldier->set("possessed", me);
        soldier->set_temp("seeme", me->query("id"));
        soldier->set_temp("do_attack_from", me);
        me->add_temp("max_guard",1);
        //给一定机率解除战斗状态，保留朝廷完全解除战斗特色。
        if (random(me->query("dex"))>=20) me->remove_all_killer();
        	
        me->set_temp("zhaoshe_time",time()+10);
        message_vision(HIB "\n$N撮起嘴唇吹了声尖锐的口哨！\n" NOR, me);   
        message_vision(HIB "\n$N从附近钻了出来！\n" NOR, soldier);
        if (me->is_busy())
        {
        	//如果主角处于busy状态并且busy类型是缠绕有一定概率减少或者解除busy
        	if ( me->query_temp("busy_stat/type") == "body" &&
        		   me->query_temp("busy_stat/time")>time() )
        	{        
       		btime=me->query_busy();
       		me->start_busy(btime/bindex);
       		me->set_temp("busy_stat/time", time()+btime/bindex);}
     			message_vision(HIB "\n$N突然冒出来，打乱了对方的攻势，缓解了$n身上的束缚！\n" NOR, soldier, me);
        	}
        return 1;
}

int help(object me)
{
        write(@HELP
指令格式：zhaoshe
 
这个指令让神龙弟子呼唤所养的金蛇来保护自己。
能否招呼出金蛇，呼出金蛇水平的高低就要看自己
的水平了。有一定几率解除自己的战斗状态。 
HELP
    );
    return 1;
}

