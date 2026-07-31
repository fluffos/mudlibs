#include <ansi.h>

void init()
{
        add_action("do_sao","sao");
}

int do_sao(string arg)
{

        object me,ob,weapon;
        int times;
     
        me = this_player();
        if (me->is_fighting())return notify_fail("边扫地边打架？你是神仙呀？！\n");
        if (me->is_busy()) return notify_fail("你正忙着呢！！\n");
	if (me->query_temp("working")) return notify_fail("你已经在扫地了！\n");
	if (me->query_temp("扫地_finish") >= 1) return notify_fail("这里已经打扫完了，快去交差吧！\n");
        if (me->query_temp("扫地_job")!= 1) return notify_fail("你想义务劳动吗？多帮些新手好了。\n"); 
        if (me->query("qi") < 20 ) return notify_fail("你太累了，还是休息一下吧！\n");
        if (me->query("jing") < 20 ) return notify_fail("你太累了，还是休息一下吧！\n");
        if (!present("sao ba",me)) return notify_fail("没有扫把怎么扫地呀？\n");
	if(!arg || arg!="地")
        return notify_fail("你要干什么？\n");
    
	times = 12 + random(10);

        if ((int)me->query_temp("job_times") > times )
	{
	tell_object(me,"这里已经打扫干净了，你终于完成了任务，人也累坏了。\n");
	me->set_temp("扫地_finish",1);	   
	return 1;
  	}                     

	if ((int)me->query_temp("bad_job") > random(5)+8)
	{ 
	tell_object(me,"宋远桥猛的往你的后脑勺敲了一下，骂道：你这猪头猪脑的东西？连扫地都不会！\n");
	tell_object(me,"宋远桥又喝道：我真是看你越来越不顺眼，你给我滚！！\n");
	me->delete_temp("working");
	me->delete_temp("扫地_job");
	me->delete_temp("job_times");
	me->delete_temp("bad_job");
	me->move("/d/wudang/guangchang");
	message_vision("$N被宋远桥赶了出来，一副狼狈相.......\n",me);
	return 1;
}


        me->set_temp("working",1);
        message_vision("$N拿着扫把，仔细的打扫着这里的每一个角落。\n",me);
        call_out( "compelete_sao", 1, me );
	me->start_busy(1);
        return 1;
}
void compelete_sao(object me)
{
        object ob;
        int i, n,percost,karcost;
        

        percost = random(15)*(me->query("per")) / 10;
        karcost = random(15)*(me->query("kar")) / 10;
        if ((int)me->query("per") < percost)
        {
                message_vision("$N把一堆树叶扫成一堆，谁知一阵狂风吹来，落叶漫天飞舞.....\n",me);
                me->add("qi",- random(40));
                me->add_temp("bad_job",1);
		me->delete_temp("working");
                return 0;
        }
        if ((int)me->query("kar") < karcost)
        {
   		message_vision("$N用力过猛，扫把头被$N给甩了出来，不偏不倚还打在$N的头上。\n",me);
	        me->add("qi",- random(40));
		me->add("jing",- random(10));
		me->add_temp("bad_job",1);
		me->delete_temp("working");
		return 0;
  	}

       
        if( present(me) ) {                    
                message_vision("只听见唰唰的声响，$N认真的打扫着，这里显得干净了许多。\n", me);
                me->delete_temp("working");
                me->add("jing", - random(10));
		me->add("qi", - random(10));
                me->add_temp("job_times",1);
                return;
        }

        return;
}