//tz_job1.c
#include <ansi.h>
#include <job_mul.h>

string *names = ({"补寨栏","挖陷井","伐木",});

string ask_job1()
{
        object me;
        object ob;
        string target;
        mapping fam;
        ob=this_player();
        me=this_object();
        fam = ob->query("family");
        
        if(!fam || fam["family_name"] != "铁掌帮")
		return "你不是我帮弟子，嘿嘿....来帮我们干活？是不是想混入铁掌帮当奸细？\n";
        if (ob->query_temp("job_name"))
		return ("你不是已经领了工作吗？还不快去做。\n");
        if (ob->query("combat_exp")>100000)
		return ("你在铁掌帮已经有一段时间了，这里没有适合你的事情可以干。\n");
        if ( (int)ob->query_condition("tz_job") || ob->query_condition("job_busy"))
                return RANK_D->query_respect(ob)+ "现在没有什么事可做，过段时间再来吧。";
        target = names[random(sizeof(names))];
        ob->set_temp("job_name",target);
        ob->apply_condition("tz_job", random(5)+10);
        ob->apply_condition("job_busy", 6);
        return "铁掌帮既要防止官府对我们的清剿，还要防止江湖其它门派对我们帮会的寻仇，\n"+
		"你武功低微，先去" + target + "吧。";
}

int do_task(string arg)
{
        int pot,exp,shen,money;
        object ob,me;
        ob=this_player();
        me=this_object();

        if( !arg || arg !="ok") return 0;

        if(!ob->query_temp("job_name")) 
            return notify_fail(CYN"裘千仞皱了皱眉，说道：没给你工作，你怎么跑来覆命了？\n"NOR);

        if(!ob->query_temp("mark/还了")) 
            return notify_fail(CYN"裘千仞说道：你先把工具还回工具房，再来覆命吧。\n"NOR);

        if(!(ob->query_temp("mark/伐完")||ob->query_temp("mark/挖完")
           ||ob->query_temp("mark/补完")))
            return notify_fail(CYN"裘千仞说道：你偷懒啊，叫你干活你不去干，跑来领功! \n"NOR);

        if( arg=="ok" 
         && (ob->query_temp("mark/伐完")
           || ob->query_temp("mark/挖完")
           || ob->query_temp("mark/补完"))){
		command("haha "+ob->query("id"));
		command("thumb"+ob->query("id"));
		command("say "+RANK_D->query_respect(ob)+"这是给你的奖赏！");
		money =(int)(ob->query_skill("guiyuan-tunafa",1)/10)+random(5);
		exp =random(30)+ob->query("max_pot")/2;
		if( ob->query_temp("mark/done"))
			exp += 50 +random(30);
			
		//ob->add("job_time/铁掌",1);
		//GIFT_D->check_count(ob,this_object(),"铁掌");
		//ob->add("combat_exp",exp);
		exp = ob->add_exp_combat(exp,this_object(),"铁掌");
						
		pot = exp /5 + random(exp/10);
		shen =random(200)+ob->query("max_pot")/2;
		me->add_money("silver",money);
		command("give "+ob->query("id")+" "+ money +" silver");
		
		
		
		ob->add("potential",pot);
		if(ob->query("potential") > ob->query("max_pot")) 
			ob->set("potential", ob->query("max_pot"));		
		ob->add("shen",-shen);
		tell_object(ob,HIW" 你被奖励了：\n" + 
			chinese_number(exp) + "点实战经验\n"+
			chinese_number(pot) + "点潜能\n"+
			chinese_number(shen)+ "负神\n"NOR);
		ob->delete_temp("job_name");
		ob->delete_temp("mark");        
		return 1;
	}
	return 1;
}
