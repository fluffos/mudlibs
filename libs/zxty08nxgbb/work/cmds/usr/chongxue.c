// write By zjb@TY

int chongxue(object me);
int end_chongxue(object me);
int main(object me)
{
        int busy;

        if ((int)me->query_skill("force",1)<10)
                return notify_fail("你还是先学些呼吸心法的技巧！\n");

        if (!me->is_busy() || me->query("doing") || me->query_temp("pending/exercise") )
                return notify_fail("你的穴道并没有被封啊？\n");
                
        if( environment(me)->query("no_fight") )
        return notify_fail("这里是是非之地，不可久留，别练功了，快走吧！\n");
                        
        if( (int)me->query("neili") < 5000 )
                return notify_fail("你现在的内力太少了，无法产生内息运行全身经脉。\n");

        if( (int)me->query_temp("chongxue") && !wizardp(me))
                return notify_fail("你现在已经在冲穴了，想重新来的话，请先halt吧。\n");

        if( !intp( busy = (me->query_busy()) ) )
        {
                write_file("/u/zjb/log/chongxue",me->query("id")+"充穴返回值出错！\n");
                me->start_busy(1);
                return notify_fail("返回值出错，请再尝试一便！\n");   
        }
        
        if( busy < 8 )
                return notify_fail("你的穴道还算不上被封，只是稍微堵塞，用不着冲穴吧。\n");

        message_vision(HIB"$N试图强制运行体内真气冲开穴道，一股"HIC"内息"HIB"开始在体内流动。\n"NOR, me); 

        me->set_temp("chongxue", busy);

        me->start_busy((: chongxue :), (:end_chongxue:));
        return 1;
}
int chongxue(object me)
{
        int busy, force;
        
        if ( !me ) return 0;
        if (!interactive(me)) return 0;

        me->add_temp("chongxue",-1);
        busy = (int)me->query_temp("chongxue");
        force = me->query_skill("force",1)/300;        
        
        if ( force < 10 ) force = 10;
        if ( force > 30 ) force = 30;
        
        if ( random(busy*3/2) < random(force/2) || busy < 1 )
        {
                me->delete_temp("chongxue");
         message_vision(HIR"$N只觉丹田处一股热流涌向全身，有着说不出来舒服得感觉，$N终于解开了穴道。\n"NOR, me); 
         return 0;                
        }
        
        if ((int)me->query("neili") < 2000)
        {
                me->delete_temp("chongxue");
                message_vision(HIR"$N的内力不够，$N不得不放弃冲穴。\n"NOR, me);    
                me->start_busy(busy); 
                return 1;                  
        }
        
        me->add("neili",-(me->query("max_neili")/50));
        message_vision(HIC"$N试图冲开穴道，可是怎么也找不到门路。\n"NOR, me);       
        return 1;
}
int end_chongxue(object me)
{
                me->start_busy(me->query_temp("chongxue"));        
                me->delete_temp("chongxue");
                message_vision(HIR"$N放弃了继续冲穴。\n"NOR, me);   
}
int help(object me)
{
        write(@HELP
指令格式 : chongxue
运气充开穴道，当你被BUSY的时候，可以使用该
指令来进行冲穴，不过损耗内力较大！
HELP
        );
        return 1;
}
