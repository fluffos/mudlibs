string ask_xunluo()
{
        mapping fam; 
        int i;
        object ob, me;
        me = this_player();
        ob = this_object();
        i = ob->query("xl");

        if(!(fam = me->query("family")) || fam["family_name"] != "明教")
                return RANK_D->query_respect(me)+"你在说写什么啊？";    
        if(ob->query_temp("xl_waiting"))
                return "等等，我正在检查呢。";    
        if(!me->query_temp("mj/xunluo"))
                return "你又没在巡逻，要我画印干嘛？";                  
        if(me->query_temp("mj/xunluo") < (i-1))
                return "先去别的地方看看，等会儿再来巡逻这儿。"; 
        if(me->query_temp("mj/xunluo") == 9)
                return "好，你已经巡逻完了。";    
        if(me->query_temp("mj/xunluo") >= i)
                return "这边你已经巡逻完了，再去别的地方看看吧。";        
        if(me->query_temp("mj/attacker") && me->query_temp("mj/attacker") < 2)
                return "咦，不是叫你去看看有没有可疑的人吗？怎么还没去？";          

        command("nod "+me->query("id"));
        ob->set_temp("xl_waiting", 1);  
        call_out("restart", 15+random(30), me, ob);
        return " 等等，让我看看你巡逻得怎么样了。\n";    
}

void restart(object me, object ob)
{     
        string arg;
        if(!ob) return;
        arg = ob->query("xl2");
        ob->delete_temp("xl_waiting");
        if(!me || !objectp(present(me, environment(ob)))){
               command("say 耶？那家伙怎么不见了？");
               command("pat");
               return;
        }
        if(!living(me)){
               command("doubt "+me->query("id")); 
               return;
        }
        if(!me->query_temp(arg)){
               command("shake "+me->query("id")); 
               command("say 你还有些地方没有巡逻到吧？先不忙画印。"); 
               return;
        }
        if(random(3) == 1 && !me->query_temp("mj/attacker")){
               command("say 嗯，刚刚有弟子来报告说好象看见了不明身份的人，你最好再去看看。");          
               command("addoil "+me->query("id")); 
               me->set_temp("mj/attacker", 1);
               return;
        }
        me->delete_temp(arg);
        me->delete_temp("mj/attacker");
        me->add_temp("mj/xunluo", 1);
        command("thumb "+me->query("id")); 
        command("say 好，这里你已经巡逻完毕了，我给你画印吧。");
        return;
}     
