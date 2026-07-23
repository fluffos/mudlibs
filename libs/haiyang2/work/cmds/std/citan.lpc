// hubo.c
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me)
{
	string msg;
	int count,a,exp,pot;
 object obj,maxpot;
    if( me->is_busy() )
	return notify_fail("你的动作还没有完成。\n");
    if( me->is_fighting() )
        return notify_fail("你正打得热闹呢!。\n");

    if( (int)me->query("jing") < 70 ) return notify_fail("你的精不够！\n");
    if( (int)me->query("qi") < 70 ) return notify_fail("你的精不够！\n");

    if( !me->query_temp("roomjob") ) return notify_fail("你没有这个任务啊！\n");

    //if( !me->query_condition("roomjob") ) return notify_fail("你这个任务已经过期了！\n");

    if (environment(me)->query("short") !=me->query_temp("roomjob"))
     {
         tell_object(me,HIR"好像是叫你到"+me->query_temp("roomjob")+"去刺探情报的吧！\n"NOR);
          return 1;
     }


    msg = GRN "$N与附近的江湖人物，混在一起，说了一会把"+environment(me)->query("short")+GRN"这里发生的事的情况大致了解了！\n" NOR;

if( !environment(me)->query("no_fight"))
{
if (random(30)==1 && me->query("combat_exp") > 2000000)
//if (me->query("combat_exp") > 2000000)
{
obj=new("/quest/menpaijob/shenlong/menggu"); 
obj->move(environment(me));
obj->do_copy(me,maxpot,2);
obj->set("title",HIY"巡逻官兵"NOR);
obj->set("usename",me->query("name"));
me->start_busy(1);
message_vision(HIY"附近走来一名很凶狠的巡逻官兵！\n"NOR, obj);
message_vision(HIR"$N说道: 你这个妖人竟敢打探地方军政，我特来消灭你这等妖人！\n"NOR, obj);
me->kill_ob(obj);
obj->kill_ob(me);
return notify_fail("先把这恶官兵消灭再说吧？\n");
}
}
me->apply_condition("roomjob",0);
me->clear_condition("roomjob",0);
me->set_temp("roomjob",0);
me->delete_temp("roomjob");

a=FAMILY_D->query_family_fame(me->query("family/family_name"));
if (a> 10 && random(10)==0) 
{	
exp=(int)a/10+10;
pot=(int)exp*2/3+10;
	me->add("combat_exp",exp);
	me->add("potential",pot);
        tell_object(me, me->query("family/family_name")+"在江湖上的威望是" + chinese_number(a) + "。\n" NOR);
        tell_object(me,  "你的经验增长了" + chinese_number(exp) + "。潜能增长了"+chinese_number(pot) +
                         "。\n" NOR);

}
exp=30+random(100)+(int)me->query_temp("menpaijob")/2;
pot=30+random(100)+(int)me->query_temp("menpaijob")/3;
        me->add_temp("menpaijob",1);
        me->add("combat_exp",exp);
        me->add("potential",pot);
    message_vision(msg, me);
    msg = GRN "$N的经验增加了" + chinese_number(exp) + "！\n" NOR;
    message_vision(msg, me);
    msg = GRN "$N的潜能增加了" + chinese_number(pot) + "！\n" NOR;    
    message_vision(msg, me);
    me->set("quest", 0);
    me->start_busy(8);
    me->receive_damage("jing", 50);
    me->receive_damage("qi", 50);
    return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : hubo
 
这个指令可以让你在任务中，来刺探情报的。
 
HELP
    );
    return 1;
}
