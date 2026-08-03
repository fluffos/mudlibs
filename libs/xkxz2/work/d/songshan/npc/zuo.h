inherit F_QUEST;

string do_ask()
{
    object me, ob;
    int i;	
    string type;
    mapping myfam, quest;
    
    me = this_player();
    ob = this_object();
    
    if(is_busy()) return "我正忙着呢，你等等。\n";
    
    myfam = (mapping)me->query("family");
    if(!myfam || myfam["family_name"] != "嵩山派") 
            return "嗯，"+RANK_D->query_respect(me)+"是在开玩笑吧？"+RANK_D->query_respect(ob)+"可没空理你。\n";
    
    if( me->query("combat_exp") < 50000 
     || me->query_skill("songshan-qigong", 1) < 50
     || me->query("shen") > 0)
            return RANK_D->query_respect(ob)+"我看你手脚散漫，行动迟缓，再加满脸稚气。怎能放心让你去办大事呢？\n";
    
    if( me->query_condition("job_busy"))
            return "你办事不力，坏我并派大事，还有脸来见我？！\n";
    
    if( me->query_temp("quest/id"))
            return "不是让你去"+me->query_temp("quest/type")+me->query_temp("quest/name")+"了吗，怎么还在这里？\n";
        
    type = random(2)?"请":"杀";
    if(!mapp(quest= get_quest(me, 0, type))) 
            return "嗯，我现在正在思考并派大计，你别打扰。\n"; 
            
    me->set_temp("quest", quest);
    me->apply_condition("songshan_job", 25+random(30));    

    if(type == "杀"){
    	    command("grin");
            command("say 你听好了，有弟子回报"+quest["name"]+"这人对我五岳并派之举深表不满，那么。。。");
            return "嘿嘿，你去将他杀了，务必在"YEL+get_time(quest["time"])+CYN"之前带着他的尸体赶回来。\n";
            }
    else{
            command("nod");
            command("say 对了，"+quest["name"]+"和我交情不错，如得他相助，五岳并派之事简直易如反掌。");
            return "你就代表我去邀请他，务必在"YEL+get_time(quest["time"])+CYN"之前赶回来。\n";    
            }   
}

int accept_object(object who, object ob,object me)
{
       mapping quest;
       int type;
       me=this_object();
       
       type = is_target(ob, who);
       switch (type){
       	    case 0: command("say 你拿个"+ob->name()+"给我干嘛？");
                    return 0;
            case -1:command("say 耶？让请人你不去，倒杀人丢脸去了，滚开！");
                    return 0;
            case -2:command("say 嘿嘿，谁让你去乱杀人了？简直是给我嵩山派抹黑！");
                    who->apply_condition("job_busy", 40);
                    return 0;
            case -3:command("say 嗯，这么久才办完，你干什么去了？给我滚一边去！");
                    who->apply_condition("job_busy", 30);
                    return 0;
            case -4:command("say 哦，这是个同名同性的人，算他倒霉吧！");
                    return 0;
            default:command("haha");
                    command("say 好！好！你办事不错，是块好料子。");
                    message_vision("\n$N给$n讲解一些武学上的疑难，$n若有所思地点着头。\n",me, who);
                    quest = who->query_temp("quest");
                    who->add("combat_exp", quest["exp_reward"]);
                    who->add("potential", quest["pot_reward"]);
                    if(who->query("potential") > who->query("max_pot")) 
                          who->set("potential", who->query("max_pot"));
                    who->add("shen", -quest["exp_reward"]*10);
                    who->delete_temp("quest");
                    who->set_temp("quest/last_id", quest["last_id"]);
                    tell_object(who, GRN"你脑中豁然开朗，领悟出"+chinese_number(quest["pot_reward"])+"点潜能和"+chinese_number(quest["exp_reward"])+"点经验！\n"NOR);
                    call_out("destroy", 1, ob);
                    return 1;
            }
      return 1;
}

void destroy(object ob)
{
        destruct(ob);
        return;
}

void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() && !is_busy()
           && ob->query("family/family_name") == "嵩山派"
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
        
        if (!mapp(quest = me->query_temp("quest")) || quest["type"] != "请") return;
        
        command("nod "+me->query("id"));
        
        ob = this_object();
        
        if(objectp(target=present(quest["id"], environment(me)))
          && target->query_temp("songshan_job") == me
          && living(target)){
        	ob->start_busy(2);
        	target->set_leader(0);
        	command("haha");
        	command("touch "+target->query("id"));
        	command("say "+target->name()+"能来，我嵩山派又多了一份力量啦！哈哈！");
        	
        	if ( quest["time"] < time()) {
        		command("say 嗯，"+me->name()+CYN"你这么久才办完，你干什么去了？给我滚一边去！");
        		me->delete_temp("quest");
                        me->set_temp("quest/last_id", quest["last_id"]);
                        me->apply_condition("job_busy", 30);
        		call_out("done", 3, target, me, quest, -1);
        		}
                else call_out("done", 3, target, me, quest, 1);
                return;
        }
}

void done(object target, object me, mapping quest, int i)
{    
  if(me && i >= 0){
  	if(target){          
            message_vision("\n$N点头道："+me->name()+"这娃娃不赖，让我指点他几招，就当是迟来的见面礼吧！\n", target, me);
            tell_object(me,GRN+target->name()+"在你的耳边悄声说道：这个，这个。。。那个，那个。。。\n" NOR);
            tell_room( environment(me), target->name() + "在" + me->name()+ "耳边小声地说了些话。\n", ({ me, target }) );
            me->add("combat_exp", quest["exp_reward"]);
            me->add("potential", quest["pot_reward"]);
            if(me->query("potential") > me->query("max_pot")) 
                  me->set("potential", me->query("max_pot"));
            me->delete_temp("quest");
            me->set_temp("quest/last_id", quest["last_id"]);
            tell_object(me, HIY"你觉得一直以来的障碍被一点而通，增加了"+chinese_number(quest["pot_reward"])+"点潜能和"+chinese_number(quest["exp_reward"])+"点经验！\n"NOR);
            tell_room(environment(target), target->query("name")+"大笑两声，在知客弟子带领下到厢房休息去了。\n", ({target}));	
            destruct(target);
            }
  	}
  else if(target){ 
  	    tell_room(environment(target), target->query("name")+"大笑两声，在知客弟子带领下到厢房休息去了。\n", ({target}));	
            destruct(target);
            }
}

