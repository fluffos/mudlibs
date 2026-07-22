#include <ansi.h>;

int ask_job()
{
        object me;
        mapping myfam;
        
        me = this_player();
        myfam=(mapping)me->query("family");
        

        if ( !myfam || myfam["family_name"]!="四川唐门" )
        {
                command("say 你是我们的人吗？再说我的job你不一定肯做啊，回去吧！");
                return 1;
        }

        if (me->query("yanli") >= 51 )
        {       
                command("gongxi");
                command("say 看你长的一表人才，就知道你是一块料，上山去吧！");
                me->set("upshan",1);
                return 1;
        }

        if (me->query_temp("started", 1))
        {
                command("say 你有任务，为什么不去做？");
                return 1;
        }
    if (me->query_temp("tmjob_failed") )
        {
                me->delete_temp("tmjob_failed");
                me->apply_condition("again",20);
                command("hmm");
                command("你先下去歇歇吧，过会再来！\n");
                return 1;
        }               
        
        if (me->query_condition("again") > 0)
        {       command("heng");
                command("say 做不了说一下，你等等吧！");
                return 1;
        }        

        if (me->query_temp("jobok") == 1)
        {
                command("say 好好，干的好，你下去歇歇吧。");
                me->add("combat_exp", 1000);
                me->delete_temp("started");
                me->delete_temp("find_wz");
                me->apply_condition("tmjob",0);
                me->delete_temp("jobok");
                me->add("yanli",1);
                return 1;
        }
        

        command("say 你去给我抓一只蚊子回来吧。");
        command("say 此事不可马虎，关系到你的前程，一定要全力去做。");
        command("say 找不到的话就问问别人，说不定有收获啊");

        me->set_temp("started",1);
        call_out("putting", 2 , me);
                       
        return 1;
}

int putting(object me)
{
	object ob1,ob2;
	string wh1,wh2;
	string *str = ({"/d/tangmen/tangmenzhen/kedian","/d/tangmen/tangmenzhen/edajie",
	                "/d/tangmen/tangmenzhen/tjpuzi","/d/tangmen/tangmenzhen/hcfdian",
	                "/d/tangmen/tangmenzhen/tsqianz","/d/tangmen/tangmenzhen/xdajie",
                        "/d/tangmen/tangmenzhen/tmbingqi","/d/tangmen/tangmenzhen/ndajie",
	                "/d/tangmen/tangmenzhen/bdajie1","/d/tangmen/tangmenzhen/bdajie2",
	                "/d/tangmen/tangmenzhen/jiulou","/d/tangmen/tangmenzhen/zhongxin"
	               });
        wh1 = str[random(sizeof(str))];
        wh2 = str[random(sizeof(str))];
	ob1 =new("/d/tangmen/tangmenzhen/npc/askdizi1.lpc");
	ob2 =new("/d/tangmen/tangmenzhen/npc/askdizi2.lpc");
        ob2->set("dname",me->query("id") );
        ob1->set("dname",me->query("id") );
        ob1->apply_condition("tmjob1",10);
        ob2->apply_condition("tmjob2",15);
        me->apply_condition("tmjob",20);
	ob1->move(wh1);
	ob2->move(wh2);        
	tell_object(me,HIC"要快去快回啊！\n"NOR);
	return 1;
}	
	
