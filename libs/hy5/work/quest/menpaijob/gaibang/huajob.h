#include <ansi.h>
#include "/quest/givegift.c"
int ask_job()
{
        object me;
        object ob;
int exp,pot;
          mapping myfam;

        me=this_player();
        myfam=(mapping)me->query("family");
        

        if (  !myfam || myfam["family_name"]!="丐帮"  )
        {
                command("say 你与本派毫无关系，这种事不能让你做。");
                return 1;
        }
        

        if ( (int)me->query("combat_exp")<80000 )
        {
                command("say 你的功夫不行，还要多学点功夫！");
                return 1;
        }
        

      if( (int)me->query_skill("huntian-qigong",1) < 50)
            {
                message_vision("$N对着$n大喝一声：你的本门内功不够！\n", this_object(), me);
                return 1;
            }
   if ((int)me->query_condition("guojob2_busy"))
            {
                      message_vision("鲁长老对着$N摇了摇头说：你等会再来!\n", me);
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
        
        if ( me->query_temp("xhjob_start") && !(me->query_temp("xhjob_ok")) )
        {
                command("hmm");
                command("say 你已经有工作了。还不快去做？");
                return 1;
        }
        
        if (me->query_temp("xhjob_ok") ==1 )
        {
        	
        if (!me->query_temp("gbkill"))
        {
                command("say 你杀了几个敌人！算你白干了!!");
                               me->delete_temp("xhjob_start");
                me->add("kill",20);
                me->delete_temp("xhjob_ok");
                me->set_temp("gbkill",0);
                me->delete_temp("gbkill");
                //me->delete_temp("xhjob_start");
                return 1;
        }
              if (random(10)==0)
              this_object()->set("book_count", 1);
                command("say 好好，干的好，你下去歇歇吧。");

exp=600+random(300);
pot=280+random(300);

exp=exp/2+188;
addnl(me,"exp",exp);

                me->delete_temp("xhjob_start");
                me->add("kill",20);
                me->delete_temp("xhjob_ok");
                me->set_temp("gbkill",0);
                me->delete_temp("gbkill");
                return 1;
        }

        if (me->query_condition("xh_busy"))
        {
                //command("say 你先休息一会，等会再来！");
                tell_object(me, me->query("name")+"先休息一会，等会再来！。\n");
                return 1;
        }
        
        tell_object(me, me->query("name")+"来的正好，听说护卫在关卡处顶不过来了，你去帮帮他。\n");
        tell_object(me, me->query("name")+"，注意，别让蒙古兵打来了。\n");
        tell_object(me, me->query("name")+"，在一分钟之内赶到那里去。。\n");
                        me->set_temp("gbkill",1);
                me->delete_temp("gbkill");
        me->set_temp("xhjob_ok",0);
        me->set_temp("xhjob_start",1);
        me->set_temp("where",__DIR__"guanka");
        
        call_out("do_goto", 60, me);

        return 1;
}

void do_goto(object me)
{
        object where;

        where = environment(me);

        if (file_name(where)==me->query_temp("where"))
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
                me->apply_condition("zzz_busy",6);
        }
        return;
}

