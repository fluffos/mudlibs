//下面的两个函数是乐曲演奏组队Buffer的标准函数，一般情况下不要随便修改这两个函数
//弹奏效果主函数
int play_music(object player, object target, string instrument, string tune)
{
	object *listeners, *team;
	int level, coef, oth_coef, aux_coef;
	int master, aux_level;
	string tName;
	
	tName=query_tune_name(tune);
		
	if ( !player )
		return 0;
	
	if ( objectp(target) )
		return notify_fail("『"+tName+"』不支持只针对一个角色进行弹奏乐曲。\n");

//判断该乐器对于该曲效果是伴奏乐器还是主乐器	
	if ( member_array(instrument, subskill_info[tune]["master"])>=0 )
		master=1;
	else
		master=0;
	
	if ( player->is_busy() ||
		   player->query_temp("play_music/status") )
    return notify_fail("你正忙着呢。\n");
  
  if ( player->query("jing")<MinSpi )
  	return notify_fail("你的精神不足，休息休息再来演奏吧。\n");

  if ( player->query("neili")<MinForce )
  	return notify_fail("你的内力不足，休息休息再来演奏吧。\n");
  
  listeners=({});
  team=player->query_team();
  
  level=player->query_sub_skill("music::"+instrument+"::"+tune);
  if ( level<=MinTuneLevel )
  	return notify_fail("你对『"+tName+"』还不够熟悉，无法弹奏出完整的曲调来。\n");
  
  if ( time()-player->query_temp("play_music/end_time")<RestTime )
  	return notify_fail("你刚演奏完一首曲子，过一会儿再演奏吧。\n");
  
//只有主乐器弹奏者才会受具体乐曲种类影响，伴奏者只对主乐器弹奏者负责
  if ( master )
  {
    if ( !team || sizeof(team)==0 )
  	  return notify_fail("『"+tName+"』是组队技，只对队友有效。\n");
    
    listeners=search_listeners(player, 0, tune, "TEAM"); 
    if ( sizeof(listeners)==0 )
  	  return notify_fail("你发现这个房间里面没有任何听众，你放弃了弹奏『"+tName+"』。\n");
  	
  	coef=primary_coef(player, instrument, tune);           //主演奏系数
  	aux_coef=find_accompanist(player, instrument, tune);   //寻找伴奏系数
  	oth_coef=find_player(player, instrument, tune, 0);     //寻找其他演奏者
  	if ( oth_coef>coef )
  		return notify_fail("场上已经有人在演奏『"+tName+"』，你技艺不如人，怎么也弹奏不下去。\n");
  	
  	player->delete_temp("play_music");
  	player->set_temp("play_music/status",1);
  	player->set_temp("play_music/instrument",instrument);
  	player->set_temp("play_music/tune", tune);
  	player->set_temp("play_music/primary_coef", coef);
  	player->set_temp("play_music/end_time", time());
  	player->start_busy(200);
  	
  	message_vision("$N拿起$n开始演奏『"+tName+"』。\n", player, player->query_temp("weapon") );
  	play_effect(player, listeners, instrument, tune, coef, aux_coef,0);
  	player->add("jing",SectSpiRed);
  	player->add("neili",SectForceRed);
  	call_out("in_playing", 1, player, listeners, environment(player), instrument, tune, coef, aux_coef, master, 0);
  }
  else
  {
  	coef=auxiliary_coef(player, instrument, tune);           //主演奏系数
  	
  	player->delete_temp("play_music");
  	player->set_temp("play_music/status",1);
  	player->set_temp("play_music/instrument",instrument);
  	player->set_temp("play_music/tune", tune);
  	player->set_temp("play_music/auxiliary_coef", coef);
  	player->set_temp("play_music/end_time", time());
  	player->start_busy(200);
  	player->add("jing",-50);
  	player->add("neili",-10);
  	message_vision("$N拿起$n开始演奏『"+tName+"』。\n", player, player->query_temp("weapon") );
  	call_out("in_playing", 1, player, listeners, environment(player), instrument, tune, coef, aux_coef, master, 0);
  }
  return 1;
}

void in_playing( object player, object *listeners, object env, string instrument, string tune, int pri_coef, int aux_coef, int master, int times)
{
	object listener, weapon, *reslis;
	int aux_level, n_aux_coef, sectT, sects;
	string tName;
	
	sectT=SectTime;
	sects=Sections;
	tName=query_tune_name(tune);
	
	if ( !player || !env || env!=environment(player) || !living(player) )
	{
		end_play(player, listeners, tune, master);
		write("一曲『"+tName+"』突然终结，大家发现演奏者已经无影无踪。\n");
		return;
	}
	
	weapon=player->query_temp("weapon");
//	printf("test: %O, %O, %d\n", weapon->query("music"), instrument, times);
	if ( !weapon || !weapon->query("music") ||
		   weapon->query("music")!=instrument )
  {
  	end_play(player, listeners, tune, master);
  	player->start_busy(0);
  	message_vision("$N放下了乐器,停止了演奏乐曲『"+tName+"』。\n", player);
  	return;
  }
  
	if ( times>=sectT*sects )
	{
		end_play(player, listeners, tune, master);
		player->start_busy(0);
		message_vision("$N放下了乐器$n,停止了演奏乐曲『"+tName+"』。\n", player, weapon);
		return;
	}
	
	if ( player->query("jing")<MinSpi || player->query("neili")<MinForce )
	{
	  end_play(player, listeners, tune, master);
	  player->start_busy(0);
		tell_object(player, "你的精神或者内力不足，休息休息再来演奏吧。\n");
    return;
  }
	
	if ( master )
	{
		if ( !player->is_busy() )
			player->start_busy(200);
	  player->set_temp("play_music/end_time", time());
//每五秒检查一次听众的合法性，剔除不合法的听众，加入合法的新听众		
		if ( times%sectT==(sectT-1) )
		{
			reslis=search_listeners(player, listeners, tune, "TEAM");
		  n_aux_coef=find_accompanist(player, instrument, tune);   //寻找伴奏系数
//重新给所有人计算演奏效果
      play_effect(player, reslis, instrument, tune, pri_coef, n_aux_coef,0);
  	  
  	  player->add("jing",SectSpiRed);
  	  player->add("neili",SectForceRed);
		  message_vision(query_tune(tune, times/sectT), player);
		  call_out("in_playing", 1, player, reslis, env, instrument, tune, pri_coef, n_aux_coef, master, times+1);
	  }
	  else
	  {
	  	play_effect(player, listeners, instrument, tune, pri_coef, aux_coef,1);
      call_out("in_playing", 1, player, listeners, env, instrument, tune, pri_coef, aux_coef, master, times+1);
	  }

		player->set_temp("play_music/end_time", time());
	}
	else
	{
		if ( !player->is_busy() )
			player->start_busy(200);
		
		if ( times%10==0 )
		{
  	  player->add("jing",-50);
  	  player->add("neili",-10);
		  message_vision("$N用手上的$n正在给『"+tName+"』伴奏。\n", player, weapon);
		}
		
		player->set_temp("play_music/end_time", time());
		call_out("in_playing", 1, player, listeners, env, instrument, tune, pri_coef, aux_coef, master, times+1);
	}
}