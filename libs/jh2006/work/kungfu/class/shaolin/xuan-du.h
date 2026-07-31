#include <ansi.h>
string ask_me()
{
	object asker,me;
	asker = this_player();
	me = this_object();

	if( !(asker->query("luohan_winner")))
	    return RANK_D->query_respect(asker)+"连罗汉大阵都没有过，哪有资格教化他人。";

	if((int)asker->query("guilty") > 0 )
	    return RANK_D->query_respect(asker)+ "你累犯数戒，身带重罪，没有资格！";
		    
	if( asker->query("shen")<0)
	    return "我看"+RANK_D->query_respect(asker)+ "一身瘴气，济世救人真不知从何说起。";

	if((int)asker->query_skill("buddhism",1)<101 
	 && asker->query_skill("dacheng-fofa",1)<101)
	    return RANK_D->query_respect(asker)+ "佛法浅薄，无法渡人，还是多多念经的要紧！";

    if(me->query("family/family_name")!="少林派" 
    && me->query("class")=="bonze"
	&& me->query("family/family_name")!="天龙寺"
	&& me->query("family/family_name")!="峨嵋派" )
 return "你是怎么混到我佛门来的？\n";
	if (asker->query("class")!="bonze")
	    return RANK_D->query_respect(asker)+ "非我佛门中人，无法济世救人。";

	if( asker->query_condition("job_busy"))
	    return RANK_D->query_respect(asker) + "刚刚济世渡人完毕，还是休息一会吧。";

	say("\n玄渡大师说道：大师佛法渊深，又肯于渡人，真是天佑我少林。\n");

	asker->set_temp("sl_job",1);
	
	message_vision("\n玄渡大师长袖一拂，一道青焰闪过，现出一个四方莲台。\n\n", asker);
      
	return "老衲已准备好了，请将奸徒交与老衲。";
}

int accept_object(object ob, object obj)
{
	mapping fam;
	object me = this_object();
	int obj_exp,my_exp,got_pot,shen,got_exp;
	int skill;

	shen = obj->query("shen");

	if( !ob->query_temp("sl_job") )
	    return notify_fail("你是哪里跳出来的，想骗老僧我?!\n");

	if(mapp(fam = obj->query("family")) 
	   && fam["family_name"] == "少林派"){
	  say("玄渡怒道:我少林弟子岂有奸徒，老和尚定不饶你。\n");
	  me->kill_ob(ob);
	  ob->delete_temp("sl_job");
	  return 0;
	} 
    
	if( obj->query_temp("last_damage_from")!= ob){
	  command("say 此人与你无缘，难以超渡。");
	  return 0;
	}
	
	if (shen > 0){
	  command("say 你竟把一位侠义之士弄到老衲这里，什麽意思? ");    
	  command("smash "+ob->query("id"));
	  ob->delete_temp("sl_job");
	  return 0;
	}
 
	if (userp(obj))
	   return notify_fail("你让玩家串通作弊，以为老僧是傻瓜?\n");
       
	obj_exp=(int)obj->query("combat_exp",1);
	my_exp=(int)ob->query("combat_exp",1);

	if (my_exp > obj_exp)
	   return notify_fail("你找个小东东来劝导,太也丢身份。\n");
    
	if (obj->query("id")=="killer"
	 || obj->query("id") == "jiaotu"){
	   say("玄渡怒道：你这家伙倒会找窍门，老和尚定不容你。\n");
	   me->delete("assigned_asker"); 
	   me->kill_ob(ob);
	   return 0;
	}    

	message_vision("$N给$n一"+obj->query("unit")+obj->name()+"。\n", ob, me);
	message_vision( HIY"\n玄渡大师双手一挥，已将"+obj->query("name")+"送上莲台，四周风雷大做。\n"NOR, ob);
	
	if( ob->query_skill("buddhism",1)<120 
	 && ob->query_skill("dacheng-fofa",1)<120
	 && !present("jiuhuan xizhang",ob)){
	  message_vision( HIR "一道闪电劈来，正中"+ob->name()+"的头顶。\n" NOR, ob);
	  ob->add("jing",-500);
	  ob->unconcious();
	  ob->delete_temp("sl_job");
	  destruct(obj);
	  return notify_fail("");
	}
 
	if( ob->query("family/family_name") == "峨嵋派" )
		skill = ob->query_skill("dacheng-fofa",1);
	else
		skill = ob->query_skill("buddhism",1);

got_pot=(obj_exp*60/my_exp)+random(skill)/3+skill/5;
got_exp=got_pot/5+random(got_pot)/10;
if(got_pot>250) got_pot=250+(got_pot-250)/10;
if( got_exp > 250) got_exp = 230 + random(20);
	ob->add("potential",got_pot);
	if( ob->query("potential") > ob->query("max_pot"))
	  ob->set("potential",ob->query("max_pot"));
	  ob->add("combat_exp",got_exp);
	ob->add("ffxm_job",1);
ob->apply_condition("job_busy", 2 + random(3));
	log_file( "job/sljob", sprintf("%s %s(%s) 第 %d 次少林任务，得到%d点经验,%d点潜能。\n",
ctime(time())[4..19],ob->query("name"),
ob->query("id"),ob->query("ffxm_job"),got_exp,got_pot));
	if ((int)ob->query("neili") < 0){
	  ob->set("neili",0);
	  ob->unconcious();  
	}  
	
	ob->delete_temp("sl_job");

	if (present("jiuhuan xizhang",ob)){
	   message_vision( HIR+ob->name()+"用力摇动佛门至宝九环锡杖，九环齐飞，风雷顿息。\n",ob); 
	   message_vision( HIR+ob->name()+"大声念诵大乘般若经文，一片红光笼罩着法台。\n",ob);
	   message_vision( ob->name()+"一声断喝，云淡风清，四处踪迹不见。\n"NOR,ob);
	   say("玄渡大师合什礼拜道:大师以无边佛法渡化凶徒，使其破去心魔，真乃功德无量。\n");
	}
	else{
	   message_vision( HIY +ob->name()+"在风雷声中大声念诵经文，然而风雷越演越烈。\n"NOR, ob);		   
	   message_vision( GRN "风雷渐渐远去,法台一片平静。\n"NOR, ob);
	   say("玄渡大师说道:大师虽佛法渊深，但无佛家宝器相助，只能胜过心魔，却无法将之一鼓破去。\n");
	   ob->add("neili", -200);
	   ob->add("jing",-100);
	   if ((int)ob->query("neili")<0 || ob->query("jing")< 0){
	    ob->set("neili",0);
	    ob->set("jing",0);
	    ob->unconcious();  
	   }  
	}

	write( sprintf(HIW "你觉得若有所悟，增加了" 
	    + CHINESE_D->chinese_number( got_exp ) 
	    + "点实战经验和" 
	    + CHINESE_D->chinese_number( got_pot )
	    + "点潜能。\n" NOR),me);

	destruct(obj);
	return notify_fail("");
}
