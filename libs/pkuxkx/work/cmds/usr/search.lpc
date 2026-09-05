#include <ansi.h>
//门派大师兄可以找人，类似pp

int main(object me,string arg)
{
        object ob, where;
        object uniob;
        string env;
        int flag;
		int order;
		int rep;

        if (!arg)
                return notify_fail("请输入想查找的人物id，只限英文!\n"); 
                
        if (me->is_busy())
                return notify_fail("你正忙着呢！\n"); 
                
        if (me->query("jingli")<120)
                return notify_fail("你的精力不够，面对本门繁杂的事务，感到力不从心。\n");   

		if(!me->query("family/family_name"))
		{
			return notify_fail("你无门无派，无依无靠，孤身一人，想在茫茫江湖里找一个人谈何容易？\n");
		}

		if(me->query("id") != FAMILY_D->get_dadizi(me->query("family/family_name")) && !wizardp(me))
		{
			return notify_fail("除非你是神，否则只有掌门人和掌门大弟子才能调动门人在江湖中追行探迹。\n");
		}

		//门派排名，1是最高。不存在的门派是-1
        order = FAMILY_D->get_family_order(me->query("family/family_name"));
		rep = FAMILY_D->get_repute(me->query("family/family_name"));

		if(order < 0 || rep < 0 )
		{
			return notify_fail("本派在江湖中势力衰微，人丁凋零，没有能力追行探迹。\n");
		}
					
        if (time()-me->query_temp("last_search_jh_time") < order * 12 && !wizardp(me))
                return notify_fail("人手刚刚都派出去了，暂时还没有回来。\n");

        me->set_temp("last_search_jh_time",time());        
        
        ob = find_player(arg);
        if( !ob ) ob = find_living(arg);
        
        if( !ob || !me->visible(ob)) 
                return notify_fail("回报，江湖中似乎没这个人。\n");
                
        if ( userp(ob) && wiz_level(ob)>1)
                return notify_fail("回报，我们无法探查神的踪迹\n");
                
        printf(HIR""+me->query("family/family_name")+"弟子听令，全力调查"+arg+"的踪迹。\n"NOR);
        
        where = environment(ob);
        if (!where) return notify_fail(HIW"回报，我们找不到此人...\n"NOR);

        me->add("jingli",-50);
        me->start_busy(2)+random(2);
        if (ob->query("hide"))
        {
            write(HIR"回报，我们找不到此人..."NOR);
            return 1;
        }
        if((objectp(uniob=ob->query("uni_target")))&& (uniob->query("id")!=me->query("id"))) 
        {        
                if (random(3))
                {
                write(HIR"回报，我们找不到此人..."NOR);
                return 1;
                }
        }
        if(ob->query("is_tasknpc") && ob->query("task_bekill")!=me->query("id"))
        {
                if (random(3))
                {
                write(HIR"回报，我们找不到此人...\n"NOR);
                return 1;
                }        	
        }
        if((int)me->query("combat_exp")/5 <= random((int)ob->query("combat_exp")))
                tell_object(ob, HIR"你发觉"
                +me->query("family/family_name")+"正在江湖中搜索你的踪迹。\n"NOR);

        env = where->query("short");
        write(sprintf(HIW"回报，本门弟子查到%s(%s)"+HIW+"曾在"+HIY+"%s"HIW"一带出现。\n"NOR,
                (string)ob->name(1),
                capitalize((string)ob->query("id")),
                env));                

        return 1;

}

int help(object me)
{
        write(@HELP
指令格式: search ID
 
掌门大弟子调用门派力量在江湖中搜索某人的踪迹。
 
HELP
    );
    return 1;

}
