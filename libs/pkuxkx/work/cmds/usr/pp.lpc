//whuan@pkuxkx
#include <ansi.h>
//perceive sb 感应××人在什么位置

int main(object me,string arg)
{
        object ob, where;
        object uniob;
        string env;
        int flag,i;
        if ((int)me->query("special_skill/perceive")<1 && !wizardp(me))
                      return notify_fail("你并不具备这个传音搜魂的能力。\n");
        
		if (me->query("special_level/perceive")<2)
		{
	        i=10;
		}
		else
		{
			i=5;
		}
        if (time()-me->query_temp("scan_time") < i && !wizardp(me))
                return notify_fail("不要频繁的查询，谢谢！\n");

        me->set_temp("scan_time",time());

        if (!arg)
                return notify_fail("请输入想查找的人物id，只限英文!\n"); 
                
        if (me->is_busy())
                return notify_fail("你正忙着呢！\n"); 
                
        if (me->query("jingli")<300)
                return notify_fail("你的精力不够，无法感应别人的位置。\n");   
        
        
        ob = find_player(arg);
        if( !ob ) ob = find_living(arg);
        
        if( !ob || !me->visible(ob)) 
                return notify_fail("现在没这个人。\n");
                
        if ( userp(ob) && wiz_level(ob)>1)
                return notify_fail("你没有办法知道他的位置。\n");
                
        printf(HIY"你默运玄功，将功力聚集于耳目，顿时觉得灵台一片空明。\n"NOR);
        
        where = environment(ob);
        if (!where) return notify_fail(HIW"你费了半天劲，就是无法感应这个人在哪里...\n"NOR);

        me->add("jingli",-200);
		if ((int)me->query("special_level/perceive")<2)
		{
	        me->start_busy(2);
		}


        if(ob->query("is_tasknpc"))
        {
            write(HIY"你费了半天的力气，就是感应不出"+ob->name(1)+"的位置。\n"NOR);
            return 1;
        }
        if (ob->query("hide"))
        {
            write(HIY"此人已经隐姓埋名，你费了半天的力气，就是感应不出其位置。\n"NOR);
            return 1;
        }
		if (ob->query("hyw_id"))
		{
			if (ob->query("killer")!=me->query("id"))
			{
			if (random(6)>0)
			{
				write(HIY"你费了半天的力气，就是感应不出+"+ob->name(1)+"的位置。\n"NOR);
				return 1;
			}

			}
		}
        if((objectp(uniob=ob->query("uni_target")))&& (uniob->query("id")!=me->query("id"))) 
        {        
                if (random(8)>0)
                {
                write(HIY"你费了半天的力气，就是感应不出"+ob->name(1)+"的位置。\n"NOR);
                return 1;
                }
        }


        if((int)me->query("combat_exp")/5 <= random((int)ob->query("combat_exp")))
                tell_object(ob, HIY"你狠狠地打了一个大喷嚏，冥冥中你觉得好象"
                +me->query("name")+"正在窥探你所在的方位。\n"NOR);

        env = where->query("short");
        write(sprintf(HIW"你掐指一算，感觉%s(%s)"+HIW+"现在好象在"+HIY+"%s"HIW"一带活动。\n"NOR,
                (string)ob->name(1),
                capitalize((string)ob->query("id")),
                env));                
        if (ob->query("hyw_npc")&&!ob->query("hyw_move")&&!random(4))
        {
            ob->set("hyw_move",1);
            for (i=0;i<1+random(2);i++)
            {
                ob->random_move();
            }
        }
        return 1;

}

int help(object me)
{
        write(@HELP
指令格式: perceive <人物姓名|ID>
 
使用传音搜魂大法寻找某人的位置。
 
相关指令: special
HELP
    );
    return 1;

}
