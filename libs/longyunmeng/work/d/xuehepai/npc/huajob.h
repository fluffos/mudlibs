int ask_job()
{
        object me;
        object ob;
          mapping myfam;

        me=this_player();
        myfam=(mapping)me->query("family");
        
        if (  !myfam || myfam["family_name"]!="血河派"  )
        {
                command("say 你与本派毫无关系，这种事不能让你做。");
                return 1;
        }
        
        if ( (int)me->query("combat_exp")<40000 )
        {
                command("say 萧萧天还需要你帮忙,你找他去吧！");
                return 1;
        }
              if (me->query("combat_exp")>300000)
             {
                  command("say 你已经小有所成了，曹大悲会给你新的任务做的。");
                    return 1;
             }

          if ( (int)me->query_temp("xhjob_failed") > 0 )
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
                me->add("combat_exp", 120+random(100));
                me->delete_temp("xhjob_start");
                me->add("kill",20);
                me->delete_temp("xhjob_ok");
                return 1;
        }
        
        command("say 你来的正好，听说护卫在关卡处忙不过来了，你去帮帮他。");
        command("say 注意，别让江湖人士进来了。");
        command("say 限你在一分钟之内赶到那里去。");
        
        me->set_temp("xhjob_start",1);
        me->set_temp("where","/d/longmen/guanka");
        
        call_out("do_goto", 60, me);

        return 1;
}

void do_goto(object me)
{
        object where;

        where = environment(me);

        if (file_name(where)==me->query_temp("where") && !me->query_condition("job_nodo"))
        {
                if (!(me->query_temp("shouwei")))  {
                tell_object(me,HIC"你应该开始守卫(shouwei)了。\n"NOR);
                }
                return;
        }
        else if (!me->query_condition("job_nodo"))
        {
                  tell_object(me,HIG"\n你显然没能在一分钟之内赶到目的地，任务失败。\n"NOR);
                me->set_temp("xhjob_failed",1);
                    me->apply_condition("job_nodo",20);
        }
        return;
}

