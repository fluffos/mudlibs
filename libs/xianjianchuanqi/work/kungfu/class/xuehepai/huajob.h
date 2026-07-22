int ask_job()
{
        object me;
          mapping myfam;

        me=this_player();
        myfam=(mapping)me->query("family");
        

        
        if ( (int)me->query("combat_exp")>400000 )
        {
                command("say 老大你是个高手啊，还有很多的事情要你去做别在这里穷晃荡！");
                return 1;
        }
  
        if ( me->query_temp("xhjob_failed") )
        {
                command("poor "+me->query("id"));
                command("say 你还是先练练功夫吧，免得又把工作搞咂了。");
                        me->delete_temp("xhjob_start");
                        me->delete_temp("xhjob_failed");
                return 1;
        }
        
        if (me->query_condition("job_nodo") > 0)
        {
                command("say 现在不需要你去做,你还是趁这段时间多练练功吧。");
                return 1;
        }

        if ( me->query_temp("xhjob_start") && !(me->query_temp("xhjob_ok")) )
        {
                command("hmm");
                command("say 你已经有工作了。还不快去做？");
                return 1;
        }
        
        if (me->query_temp("xhjob_ok") ==1 )
        {
                command("say 好好，干的好，你下去歇歇吧。");
                me->add("potential", 40+random(60));
                me->add("combat_exp", 80+random(80));
                me->delete_temp("xhjob_start");
                me->add("kill",20);
                me->delete_temp("xhjob_ok");
                return 1;
        }
        
        command("say 你来的正好，你就在这里帮守护这里吧，防止江湖义士来破坏我，大西夏国的美好环境。");
        command("say 注意，别让江湖人士进来了。");
        command("say 限你在一分钟之内赶到那里去。");
        
        me->set_temp("xhjob_start",1);
        me->set_temp("where","/d/xingxiu/jyg");
        
        call_out("do_goto", 60, me);

        return 1;
}

void do_goto(object me)
{
        object where;

        where = environment(me);

        if ((file_name(where)==me->query_temp("where")) || (file_name(where)=="/d/xingxiu/jyg"))
        {
                if (!(me->query_temp("shouwei")))  {
                tell_object(me,HIC"你应该开始守卫(shouwei)了。\n"NOR);
                }
                return;
        }
        else
        {
                tell_object(me,"\n你显然没能在一分钟之内赶到目的地，任务失败。\n");
                me->set_temp("xhjob_failed",1);
                  me->apply_condition("job_nodo",30);
        }
        return;
}

