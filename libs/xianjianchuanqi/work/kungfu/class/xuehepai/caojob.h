int ask_job()
{
        object me;
         object ob,killer;
        mapping myfam,quest;
        me=this_player();

        myfam=(mapping)me->query("family");
        quest = "quest/xhquest"->query_quest();
            killer=me->query_temp("last_damage_from");
        

        if ( myfam && myfam["family_name"]=="血河派" )
        {
                if ( (int)me->query("combat_exp")<300000 )
                {
                        command("say 这种工作人命关天，我不放心你做！");
                        return 1;
                }
        }
        
        if ( me->query_temp("jobfailed") )
        {
                command("poor "+me->query("id"));
                command("say 你还是先练练功夫吧，免得又把工作搞咂了。");
                me->delete_temp("jobfailed");
                me->delete_temp("jobstart");
                me->apply_condition("job_nodo",20);
                me->delete_temp("followed");
                return 1;
        }
        
        if ( me->query_temp("job-fail") )
        {
                command("sigh "+me->query("id"));
                command("say 这不是你的过错，再给你一次机会吧。");
                me->delete_temp("job-fail");
                me->delete_temp("jobstart");
                return 1;
        }

        if (me->query_condition("job_nodo") > 0)
        {
                command("say 现在不需要你去做,你还是趁这段时间多练练功吧。");
                return 1;
        }

        if ( me->query_temp("jobstart") && !(me->query_temp("jobok") && killer->query("id")!="sha shou"))
        {
                command("hmm");
                command("say 你已经有工作了。还不快去做？");
                return 1;
        }
        
        if (me->query_temp("jobok") ==1 )
        {
                command("say 好好，干的好，你下去歇歇吧。");
                me->add("potential", 80+random(80));
                me->add("combat_exp", 120+random(110));
               me->delete_temp("jobstart");
            me->add("kill",50);
               me->delete_temp("jobok");
                 me->delete_temp("begin");
                me->delete_temp("duishou");
                me->delete_temp("where");
                me->delete_temp("where1");
                me->delete_temp("followed");
                return 1;
        }
        
        command("say 你来的正好，听说" + quest["opp_name"] + "弟子在" + quest["file_env"] + "\n追杀我门派弟子，你赶快去援救，我们会在"+quest["mudi_env"]+"接应你们。");

        me->set_temp("jobstart",1);
        me->set_temp("duishou", quest["opp_name"]);
        me->set_temp("where", quest["file_name"]);
        me->set_temp("where1", quest["mudi_name"]);     
        ob=new("/kungfu/class/xuehepai/dizi");
        ob->set_name("血河派弟子",({"di zi","zi"}));
        ob->set_skill("dodge",me->query_skill("dodge",1)/10);
            ob->set("followid",me->query("id"));
        ob->move(quest["file_name"]);
        remove_call_out("do_datan");
        call_out("do_datan",40, me);

        return 1;
}

void do_datan(object me)
{
        object where,ob,obb;

        me=this_player();
        where = environment(me);

       if (me->query_temp("begin") || me->query_temp("jobok"))
                    return;
        if (file_name(where)==me->query_temp("where"))
        {
                if (!(present("di zi",where)))
                {
                        tell_object(me,HIC"你等了一会，没有人影，可能弟子已经被玩家杀了。\n"NOR);     
                        me->set_temp("job-fail",1);
                        me->delete_temp("jobstart");                    
                        return;
                }
        }
        else
        {
                tell_object(me,HIC"这么久你还没赶到，弟子已经被砍死了。\n"NOR);
                ob=find_object(me->query_temp("where")+".lpc");
                if (obb=present("dizi",ob)) 
                {
                        tell_room(ob,HIG"突然杀出几个"+me->query_temp("duishou")+"弟子对着"+obb->query("name")+"猛砍一阵。\n然后就四处散开，不见了。\n");
                        obb->die();
                }
                me->set_temp("jobfailed",1);
                me->apply_condition("job_nodo",20);
                me->delete_temp("jobstart");
                return;
        }
        return;
}


