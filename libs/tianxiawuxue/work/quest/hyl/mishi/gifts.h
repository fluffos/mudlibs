int give_gifts(object ob);

int give_gifts(object ob)
{
	int exp,pot,time,times,bouns,bouns1;
	
	time=ob->query_condition("tdh_job_busy");
	times=ob->query("tiandihui/job");
	bouns=1;
	bouns1=1;
	if(time>=15)
    	bouns=2;
    if(time>=20)
        bouns=4;
    if(time>=30)
        bouns=8;
    if(times>1200)
        bouns1=2;
    if(times>1700)
        bouns1=4;
    if(times>2400)
        bouns1=6;
    if(times>3000)
        bouns1=8;
    if(times>4800)
        bouns1=10;
        
    exp=100+bouns*12+bouns1/2*15+random(100-bouns*bouns1);
	pot=50+bouns*10+bouns1/2*12+random(40);
    ob->add("potential",pot);
    ob->add("combat_exp",exp);
    ob->add("tiandihui/job",1);
    
	ob->delete_temp("tdh_job");
	tell_object(ob,HIY"
你保护火云教特别人物安然返回，功劳颇大，得到了：" + 

                       chinese_number(exp) + "点实战经验，" +

                       chinese_number(pot) + "点潜能的奖励。\n"+

"你为天地会做了"HIW+chinese_number(ob->query("tiandihui/job"))+HIG"次工作。\n"NOR);
	ob->apply_condition("tdh_job_busy",4+random(4));
	return 1;
}

void init()
{
	add_action("do_point","point");
}

int do_point(string arg)
{
	object mishi,ma,ob=this_player();
	
	if(!arg) return notify_fail("你乱戳了一通，发现没人理你。\n");
	if(ob->query_temp("tdh_job/job_name")!="保护密使")
		return notify_fail("你乱戳什么？\n");
	if(!(mishi=present(arg,environment(ob))))
		return notify_fail("你要指谁？\n");
	if(!(ma=present("xu tianchuan",environment(ob))))
		return notify_fail("教主不在，还是先等等再说。\n");
	if(mishi->query("guarder_id")!=ob->query("id"))
		return notify_fail("你用手指了"+mishi->name()+"一下，"+ma->name()+"摇了摇头。\n");
	if(!ob->query_condition("tdh_job_busy"))
		return notify_fail(CYN"你指了指"+mishi->name()+"，"+ma->name()+"叹道：此次时日花费太多，我等反倒不便。\n"NOR);
	message_vision("$N用目光指了指$n。",ob,mishi);
	message_vision("$N冲上前去，激动地握住$n的手，哽咽得一句话也说不出来。\n",ma,mishi);
	message_vision("$N嘻嘻傻笑了一下：教中任务繁多，所幸不负教主所望，"+RANK_D->query_self(ob)+"就此别过。\n",ob);
	call_out("destructing",1,mishi);
	give_gifts(ob);
	return 1;
}

void destructing(object ob)
{
    destruct(ob);
}
