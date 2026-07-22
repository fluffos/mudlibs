string do_ask()
{
    object me, ob;
    int i;	
    string type;
    mapping myfam, quest;
    
    me = this_player();
    ob = this_object();
    
    if(ob->is_busy()) return "我正忙着呢，你等等。\n";
    
    myfam = (mapping)me->query("family");
/*
    if(!myfam || myfam["family_name"] != "密宗") 
            return "嗯，"+RANK_D->query_respect(me)+"是在开玩笑吧？"+RANK_D->query_respect(ob)+"可没空理你。\n";
 */   
    if( me->query("combat_exp") < 50000 )
//     || me->query("shen") > 0)
            return RANK_D->query_respect(ob)+"我看你手脚散漫，行动迟缓，再加满脸稚气。怎能放心让你去办大事呢？\n";
    
    if( me->query_condition("job_busy"))
            return "你办事不力，坏我并派大事，还有脸来见我？！\n";
    
    if( me->query_temp("quest/id"))
            return "不是让你去"+me->query_temp("quest/type")+me->query_temp("quest/name")+"了吗，怎么还在这里？\n";
        
    type = "挑衅";
    if(!mapp(quest= TASK_D->get_quest(me, -1, "挑衅", "密宗"))) 
            return "嗯，我现在正在考虑夺取中原，没空。\n"; 
            
    me->set_temp("quest", quest);
    me->apply_condition("mizong_job", 25+random(30));    

             command("hmm");
            command("say 嗯，"+quest["name"]+"("+quest["id"]+")"+"在中原武林声望很高，对我们将来进军中原是个障碍。");
            command("say 据传闻，他正在"+quest["place"]+"一带散布我们的谣言。");
            return "你就替我去羞辱他一番，务必在"YEL+TASK_D->get_time(quest["time"])+CYN"之前赶回来。\n";    
}

void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() && !is_busy()
//           && ob->query("family/family_name") == "密宗"
           && ob->query_temp("mizong_job_done")
           && ob->query_temp("quest/type")) {
                remove_call_out("greeting");
                call_out("greeting", 2, ob);
        }
}

void greeting(object me)
{
	object target, ob;
	mapping quest;
	int type;
	
        if( !me || environment(me) != environment() || !living(me)) return;
        
        if (!mapp(quest = me->query_temp("quest")) || quest["type"] != "挑衅") return;
        
        command("nod "+me->query("id"));
        
        ob = this_object();
        
        if(me->query_temp("mizong_job_done"))
        	command("say "+me->name()+"干得不错！哈哈！");
	else return ;        	
        	if ( quest["time"] < time()) {
        		command("say 嗯，"+me->name()+CYN"你这么久才办完，你干什么去了？给我滚一边去！");
        		me->delete_temp("quest");
                        me->set_temp("quest/last_id", quest["last_id"]);
                        me->apply_condition("job_busy", 30);
        		call_out("done", 3, ob, me, quest, -1);
        		}
                else call_out("done", 3, ob, me, quest, 1);
                return;
        }

void done(object target, object me, mapping quest, int i)
{
int job_time;
        job_time = (int)me->query("mizong_job")/800;
  if(me && i >= 0){
            message_vision("\n$N点头道："+me->name()+"你干得不错，这是你的奖励！\n", target, me);
            tell_object(me,HIG+target->name()+"在你的耳边悄声说道：这个，这个。。。那个，那个。。。\n" NOR);
            tell_room( environment(me), target->name() + "在" + me->name()+ "耳边小声地说了些话。\n", ({ me, target }) );
            me->add("mizong_job",1);
                 TASK_D->give_reward(me, me->query_temp("quest"), -1, job_time);     
            me->delete_temp("quest");
            me->delete_temp("mizong_job_done");
            me->set_temp("quest/last_id", quest["last_id"]);
            }
}
