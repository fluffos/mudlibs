// biaotou.h
// by augx@sj  10/17/2001

string ask_guard()
{	
	object me = this_player();
	int lvl,i,j,k;
	
	if( me->query_user_type() == "worker" ) {
		lvl = me->query_temp("worker_skill_highest");
		i = lvl/2; j = lvl*2/3; k = lvl;
		if(i<50) i = 50;
		if(j<50) j = 50;
		me->delete_temp("worker_skill_limit");
		me->delete_temp("worker_skill_highest");		

		return  "本镖局提供贴身保镖服务，每次服务的时间为一刻钟，目前能为您提供三钟档次的保镖：\n"+
			sprintf("%-32s%-14s%-6s%-30s\n","普通保镖(guard1) －－－ 武功等级：",CHINESE_D->chinese_number(i),"佣金：",MONEY_D->price_str( (i>300)?(i*1500):(i*1000) ))+
			sprintf("%-32s%-14s%-6s%-30s\n","高级保镖(guard2) －－－ 武功等级：",CHINESE_D->chinese_number(j),"佣金：",MONEY_D->price_str( (j>300)?(j*1500):(j*1000) ))+
			sprintf("%-32s%-14s%-6s%-30s\n","超级保镖(guard3) －－－ 武功等级：",CHINESE_D->chinese_number(k),"佣金：",MONEY_D->price_str( (k>300)?(k*1500):(k*1000) )) ;
	}
	else
		return "说笑了，像阁下这样的武林高手还需要人保护？";
}

string do_fire(int type)
{
	object me = this_player() , guard;
	int lvl;
	
	if( !wizardp(me) && (int)me->query_temp("fire_guard") && me->query_temp("fire_guard")>time() )
		return "你不是已经聘请保镖了吗？";
	if( me->query_user_type() != "worker" )
		return "说笑了，像阁下这样的武林高手还需要人保护？";
		
	lvl = me->query_temp("worker_skill_highest");
	lvl = lvl * type / 6;
	if(lvl<50) lvl = 50;
	me->delete_temp("worker_skill_limit");
	me->delete_temp("worker_skill_highest");
	
	if( is_wanted(me) )
		return "我们不保护通缉犯！";
			
	switch( MONEY_D->player_pay(me, (lvl>300)?(lvl*1500):(lvl*1000)) ) {
		case 0:
		case 2:	return "你没有足够的钱支付佣金。";
		default: break;
	}
	message_vision("$N付给$n"+MONEY_D->price_str((lvl>300)?(lvl*1500):(lvl*1000))+"来雇佣保镖。\n",me,this_object());
	
	guard = new(__DIR__"wguard");
	if(!guard) return "error! please tell wizard!";
	guard->do_copy(me,lvl);
	
	guard->move(environment(me));
	message_vision("$N从内堂走了出来。\n",guard);
	guard->set_leader(me);
	
	me->set_temp("fire_guard",time()+15*60);
	return "您放心，在下一刻钟内，我们会保证您的安全！";
}

string ask_guard1()
{
	return do_fire(3);
}

string ask_guard2()
{
	return do_fire(4);
}

string ask_guard3()
{
	return do_fire(6);
}
