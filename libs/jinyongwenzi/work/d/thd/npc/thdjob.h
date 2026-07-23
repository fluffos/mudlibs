int ask_job_s()
{
        object ob = this_player();
// 判断 门派        
        if (ob->query("family/family_name") != "桃花岛")
        {
                tell_room(environment(ob),"黄蓉疑惑的看着" + ob->query("name") + ",说道: 什么师母不师母的，我母亲是你随便叫的吗?\n",({ob}));
                tell_object(ob,"黄蓉疑惑的看着你,说道: 什么师母不师母的，我母亲是你随便叫的吗?\n");
                return 1;
        }
               
        ob->set_temp("thd/job_s",1);
        say( "黄蓉叹了口气，说道: 我母亲绝顶聪明，可惜她英年早逝，我爹爹将她葬在桃花岛上的一座墓里。\n");
        this_object()->start_busy(3);
        return 1;
}

int ask_job()
{
        object me = this_object();
        object ob = this_player();
        mixed *local;
        
        local = localtime(time()*60);
/*
// 判断 时间        
        if (local[2] > 9 && local[2] < 17)
        {
                tell_room(environment(ob),"黄蓉疑惑的看着" + ob->query("name") + ",说道: 现在大白天的，还守什么墓呀?\n",({ob}));
                tell_object(ob,"黄蓉疑惑的看着你,说道: 现在大白天的，守什么墓呀?\n");
                ob->delete_temp("thd/job_s");
                return 1;
        }
*/
        if( ob->query("job_name") == "桃花守墓"){
         	command("say 你刚刚做好守墓任务，还是先休息一会吧。");
         	return 1;
        }
         
        if (ob->query("combat_exp") > 2000000)
        {
                command("say 你武功这么好，不用麻烦啦。");
                ob->delete_temp("thd/job_s");
                return 1;
        }

// 判断 经验        
        if ((int)ob->query("combat_exp") < 100000)
        {
                tell_room(environment(ob),"黄蓉看了看" + ob->query("name") + ",说道: 你武功基础还没打好，这么危险的任务还是别做了！\n",({ob}));
                tell_object(ob,"黄蓉看了看你,说道：你武功基础还没打好，这么危险的任务还是别做了！\n");
                ob->delete_temp("thd/job_s");
                return 1;
        }
// 判断 是否已经接了任务
        if ((int)ob->query_temp("thd/job")>0)
        {
                tell_room(environment(ob),"黄蓉瞪了" + ob->query("name") + "一眼,说道: 不是叫你去了吗，你还呆在这里干什么?\n",({ob}));
                tell_object(ob,"黄蓉瞪了你一眼,说道: 不是叫你去了吗，你还呆在这里干什么?\n");
                ob->delete_temp("thd/job_s");
                return 1;
        }
// 判断 是否有人在做任务        
        if ((int)me->query("thd/havejob")  < 1 )
        {
                command( "say 已经有人去守墓了，你下次再去吧！");
                ob->delete_temp("thd/job_s");
                return 1;
        }
        if ((int)ob->query_condition("thd_job") > 0)
        {
                command( "say 你刚守完墓，休息一下再去吧！");
                ob->delete_temp("thd/job_s");
                return 1;
        }
// 判断 qimen-bagua是否>=100
        if (!ob->query_temp("thd/job_s") 
        ||  ob->query_skill("qimen-bagua",1) < 80)
        {
                command( "say 难得你有这份心意，但是我母亲的墓不是随便就能进去的。");
                return 1;
        }
// job busy
 if ( ob->query_condition("job_busy") || ob->query_condition("thd_job")>0) {
    command("say 对不起，现在这里没有什么可以给你做的。");
return 1; }
// 接受任务
        switch( random(2))
        {
                case 0:
                        command( "say 难得你有这份心意，但是我母亲的墓不是随便就能进去的。");
                        break;  
                case 1:
                        command( "say 你要小心点，我母亲的墓可不是一般人都能进去的。");
                        break;
        }
        say( "黄蓉想了想，说道: 这样吧,我带你去!\n");
        ob->delete_temp("thd/job_s");
        ob->set_temp("thd/job",1);
        me->delete("thd/havejob");
   // 设置 busy
        ob->apply_condition("thd_job", 3+random(3));
        ob->apply_condition("job_busy", 9);
        ob->set("job_name", "桃花守墓");
        tell_object(ob,"你紧跟着黄蓉，左一转，右一转，不一会就到了墓前。\n");
        ob->move(__THD__"tomb");
        tell_object(ob,GRN"黄蓉在你耳边悄悄说道: 你要好好守墓。如果有什么人进到墓里，你不要对他客气!\n"NOR);
   // 设置 任务失败时间
        call_out("job_failed",250);
        return 1;
}

int accept_object(object who, object ob)
{
        object me = this_object();
        int exp,pot,job_busy;
        
        if (!who->query_temp("thd/dojob"))
                return 0;
                        
        if (ob->query("id")=="lv feicui"
        ||  ob->query("id")=="meiyu"
        ||  ob->query("id")=="yeming zhu"
        ||  ob->query("id")=="zi manao")
        {
            if(ob->query_temp("thdjob") != who->query("id")){
                    command("hehe "+ who->query("id"));
                    command("say 你从哪里弄来这"+ob->query("name")+"，那可不是你干的哦。");
                    return 0;
                }
                switch( random(5) )
                {
                        case 0:
                                command("pat " + who->query("id"));
                                say("黄蓉欣喜的说道：你干的很出色，这是给你的奖励。\n");
                                break;
                        case 1:
                                command("nod " + who->query("id"));
                                say("黄蓉说道：你日后要加油练功，多为我们桃花岛作些贡献！\n");
                                break;
                        case 2:
                                command("thumb " + who->query("id"));
                                say("黄蓉看了看" + ob->query("name") + "，说道：你追回了被盗贼窃走的宝物，功劳可不小呀！\n");
                                break;
                        case 3:
                                command("touch " + who->query("id"));
                                say("黄蓉用手颠着" + ob->query("name") + "，说道：我爹爹辛辛苦苦弄来的这些宝物，可都是无价之宝呀！\n");
                                break;
                        case 4:
                                command("pat " + who->query("id"));
                                say("黄蓉说道：你为咱们桃花岛作了大贡献，我不会亏待你的。\n");
                                break;
                }
                                
// give rewards
// calculate combat_exp
                job_busy = 7 - (int)who->query_condition("thd_job");
                exp = 30 
                        + random((int)who->query("thd_job",1)/20)
                        + random(who->query("thd_job",1)/10)
                        + random((int)who->query("age",1))
                        + random((int)who->query("int",1))
                        - job_busy;
                if (exp < 150) exp = 130 + random(30);
        if(exp>250) exp=200+random(50);
                who->add("combat_exp",exp);
// calculate potential
                pot = exp/5+ random(exp/6);
/*                pot = random((int)who->query("int",1)*3)
                    + random((int)who->query("thd_job",1)/20)
                    + random(who->query_skill("qimen-bagua",1)/5)
                    + random(50)
                    + 50;
                  30
                        + random((int)who->query("thd_job",1)/40)
                        + random((int)who->query("age",1))
                        - job_busy*job_busy;
                if (pot < 50) pot = 30 + random(20);
                if (pot > 150) pot = 150 + random(10);*/
/*             if (pot < 50) pot = 30 + random(20);
                if (pot > 100) pot = 50 + random(100);
*/                who->add("potential",pot);
                   if (who->query("potential")>who->query("max_pot"))
                   who->set("potential", who->query("max_pot"));
                   who->add("balance", pot*1000);
// add log to /log/thdjobs 测试时用，用后去掉
	log_file("job/thdjobs",sprintf("%s %s(%s)%d次任务奖励经验%d，潜能%d。\n",
                ctime(time())[4..19],who->name(1),who->query("id"),(int)who->query("thd_job"),exp,pot));

// add job times
                if (!who->query("thd_job"))
                        who->set("thd_job",1);
                who->add("thd_job",1);
                who->delete_temp("thd/dojob");
// 又可以有人作任务了
                me->set("thd/havejob",1);
// 去掉 job fail
                remove_call_out("job_failed");
// 加入job busy time
who->apply_condition("job_busy",5+random(2));
 who->apply_condition("thd_job",4+random(3)+exp/50);
                call_out("destroy", 1, ob);
                tell_room(environment(),HIY "黄蓉在"+ who->query("name")+ "的耳边低声说了几句，"+ who->query("name") +"听的不住点头，面呈喜色。\n"NOR, ({ who }));
                switch( random(3))
                {
                        case 0:
                                tell_object(who,HIG"你觉的脑中豁然开朗，得到了"+CHINESE_D->chinese_number(exp)+"点经验，"
                                        +CHINESE_D->chinese_number(pot)+"点潜能。\n"NOR);
                                break;
                        case 1:
                                tell_object(who,HIY"你获得了"+CHINESE_D->chinese_number(exp)+"点经验，"
                                        +CHINESE_D->chinese_number(pot)+"点潜能的奖励。\n"NOR);
                                break;
                        case 2:
                                tell_object(who,HIR"你感觉一股真气在体内游走，增加了"+CHINESE_D->chinese_number(exp)+"点经验，"
                                        +CHINESE_D->chinese_number(pot)+"点潜能。\n"NOR);
                                break;
                }
                return 1;
        }
        else return 0;
}

void job_failed()
{
        object me = this_object();
        switch( random(3))
        {
                case 0:
                        say( "黄蓉说道：哎呀，去守墓的那小子怎么还不回来？\n");
                        break;
                case 1:
                        say( "黄蓉紧张的说道：去守墓的那小子不会死了吧？怎么还不见人影？\n");
                        break;
                case 2:
                        say( "黄蓉叹了口气，说道：还是找些武功高的弟子去守墓吧！\n");
                        break;
        }
        say( "黄蓉说道：算了，我还是另外找别人去守墓吧！\n");
        me->set("thd/havejob",1);
}

void destroy(object ob)
{
        destruct(ob);
}
