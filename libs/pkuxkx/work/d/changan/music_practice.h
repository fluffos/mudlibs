#include <combat/music.h>

void init()
{
  add_action("do_play", "play");
}

int do_play(string arg)
{
	object me=this_player(), weapon;
	string yueqi, slave;
	int master, pot;
	
	if ( me->query_temp("changan/jf_time")<time() )
	{
		tell_object(me, "你对本练习室的使用时间已到，请出去缴纳足额银两以后再继续练习乐谱。\n");
		me->move("/d/changan/neijiaofang");
		return 1;
	}
	
	if ( !arg || strsrch(arg,"::")>=0 )
	{
		write("命令格式：play 乐谱ID，比如使用琴乐器的广陵散乐谱的技能ID是music::qin::guangling-san，\n只要输入play guangling-san就行，如果你身上装备琴则可以正常弹奏广陵散。\n");
		return 1;
	}
	
	weapon=me->query_temp("weapon");
	if ( !weapon || !weapon->query("music") )
	{
		write("你必须装备乐器才能弹奏乐谱。\n");
		return 1;
	}
	
	yueqi=weapon->query("music");
	if ( me->query_sub_skill("music::music-theory",1)<100 )
	{
		write("基础乐理必须达到100级，才能自行研习乐谱。\n");
		return 1;
	}
	
	if ( me->query_sub_skill("music::"+yueqi,1)<100 )
	{
		write("装备的乐器基础知识必须达到100级才能自行研习该乐器的乐谱。\n");
		return 1;
	}
	
	if ( !subskill_info[arg] ||
		   subskill_info[arg]["class"]!=3 )
	{
		write("你要弹奏的乐谱未定义，或者你要弹奏的并不是乐谱。\n");
		return 1;
	}
	
	if ( member_array(yueqi, subskill_info[arg]["master"])>=0 )
	{
		if ( me->query_sub_skill("music::"+yueqi+"::"+arg)<100 )
		{
			write("你必须掌握装备乐器的该乐谱知识达到100级，才能开始自行弹奏该乐谱。\n");
		  return 1;
	  }
	}
	else
	{
		master=0;
		foreach(slave in subskill_info[arg]["master"])
		{
			if ( me->query_sub_skill("music::"+slave+"::"+arg)>=300 )
				master=1;
		}
		
		if ( !master )
		{
			write("使用辅助乐器弹奏乐谱，必须有一个主乐器的该乐谱知识达到300级。\n");
			return 1;
		}
		
		if ( !SKILL_D("music")->valid_learn_subskill(me, ({"music", yueqi, arg})) )
		  return 1;
	}
	
	pot=(int)me->query("potential") - (int)me->query("learned_points");
	if ( pot<100 )
	{
		write("你的潜能不足，不能自行研习乐谱。\n");
		return 1;
	}
	
	if ( me->query("jing")<300 )
	{
		write("你的精神不够充沛，先养养精神再来吧。\n");
		return 1;
	}
	
	if ( me->is_busy() || me->is_fighting() )
	{
		write("你正忙着！\n");
		return 1;
	}
	
	me->start_busy(100);
	message_vision("$N拿起$n开始弹奏"+SKILL_D("music")->skill_name(arg)+"，沉浸在音乐之中。\n", me, weapon);
	call_out("in_play", 10, me, weapon, arg, "music::"+yueqi+"::"+arg, 5 );
	return 1;
}

void in_play(object me, object weapon, string music, string skill, int times)
{
	int learn_speed, music_level, mint, learn_exp;
	
	if ( !objectp(weapon) )
	{
		me->start_busy(0);
		write("你停止了弹奏站了起来。\n");
		return;
	}
//音乐练习效果算法统一存放在F_MUSIC文件中。	
	F_MUSIC->music_practice(me, weapon->query("music"), music, skill);
	if ( times )
	{
	  message_vision("$N拿起$n弹奏，感觉自己对"+SKILL_D("music")->skill_name(music)+"的理解又深了一步。\n", me, weapon);
	  call_out("in_play", 10, me, weapon, music, skill, times-1 );
	}
	else
	{
		message_vision("$N结束了一首『"+SKILL_D("music")->skill_name(music)+"』，放下乐器站了起来。\n", me);
		me->start_busy(0);
	}
}