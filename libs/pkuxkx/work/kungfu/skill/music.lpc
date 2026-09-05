// music.c 音律
#include <ansi.h>
inherit SKILL;
#include <combat/level.h>
#include <combat/music.h>

//定义具体音乐的等级名称，目前仅预定义五个等级
//其中前两个等级仅限于大众音乐，该音乐在武功上的效果非常差，也就是说和内功的可融合性特别差
//后面三个等级的乐谱一般都是门派专有的乐谱或者需要解谜，和对应内功的可融合性非常好，可以对
//特定对象的战斗力造成非常显著的影响。
string *level_name=({HIW"基础乐谱"NOR,YEL"稀有乐谱"NOR,CYN"高深乐谱"NOR,MAG"禁忌乐谱"NOR,RED"传说乐谱"NOR});

string skill_name(string sk_id);
protected float skill_exp(int level, int learned);
protected int skill_level(float exp);

string type() { return "knowledge"; }

void skill_improved(object me)
{}

//识别是否可以学习该子技能
int valid_learn_subskill(object me, string *subsks)
{
	mapping skl,music;
	int *reqlv, *master, lp, p2;
	int isMst=0, *isReq=({0,0,0,0,0});
	string *sub_key, *delkey;
	
	if ( sizeof(subsks)<=1 || sizeof(subsks)>3 )
		error("你的子技能层级非法，只能是2层或者3层。\n");
	
	if ( !subskill_info[subsks[1]] || 
		   (sizeof(subsks)==3 &&
		    !subskill_info[subsks[2]] ) )
	{
		tell_object(me, "未定义的子技能信息，请联系相关巫师添加该子技能的具体信息。\n");
		return 0;
	}
	
	if ( subsks[0]!="music" )
	{
		tell_object(me, "仅检查音律下面的子技能是否能够学习。\n");
		return 0;
	}
	
	skl=me->query_skills();
	if ( skl["music"] && !mapp(skl["music"]) )
	{
		tell_object(me, "你目前的音律技能还是旧的音律技能，请转换完成以后再来学习音律下面的各种音乐知识。\n");
		return 0;
	}
	
	if ( !skl["music"] ) 
		skl["music"]=([]);
	
	music=skl["music"];
	if ( sizeof(subsks)==3 &&
		   !music[subsks[1]] )
	{
		tell_object(me, "你还未学习技能"+skill_name(subsks[1])+"，不能学习基于该技能下的音乐"+skill_name(subsks[2])+"。\n");
		return 0;
	}
	
	if ( subsks[1]!="music-theory" &&
		   !music["music-theory"] )
	{
		tell_object(me, "你必须先学习基础乐理，才能学习其他技能。\n");
		return 0;
	}
	
	if ( sizeof(subsks)==2 )
	{
		reqlv=subskill_info[subsks[1]]["require"];
		if ( subskill_info[subsks[1]]["class"]!=2 )
		{
			tell_object(me, skill_name(subsks[2])+"似乎不是一种乐器基础知识，而是一种音乐。\n");
			return 0;
		}

		if ( subsks[1]!="music-theory" && music["music-theory"]["level"]<reqlv[0] )
		{
			tell_object(me, "基础乐理等级过低不能学习"+skill_name(subsks[1])+"。\n");
			return 0;
		}
	}
	else
	{
		reqlv=subskill_info[subsks[2]]["require"];
		master=subskill_info[subsks[2]]["master"];
		if ( subskill_info[subsks[2]]["class"]!=3 )
			return notify_fail(skill_name(subsks[2])+"似乎不是一种音乐，而是仅仅是一种乐器基础知识。\n");
		
		if ( music["music-theory"]["level"]<reqlv[0] )
		{
			tell_object(me, "基础乐理等级过低不能学习"+skill_name(subsks[2])+"。\n");
			return 0;
		}
		
		if ( music[subsks[1]]["self_level"]<reqlv[1] )
		{
			tell_object(me, skill_name(subsks[1])+"的基础知识掌握不够扎实，不能够学习"+skill_name(subsks[2])+"。\n");
			return 0;
		}
		
		if ( member_array( subsks[1], master )<0 )
		{
			for ( lp=0;lp<sizeof(master);lp++ )
			{
				if ( mapp(music[master[lp]]) &&
					   mapp(music[master[lp]][subsks[2]]) &&
					   music[master[lp]][subsks[2]]["level"]>=300 )
					isMst=1;
			}
			
			if ( !isMst )
			{
				tell_object(me, "音乐"+skill_name(subsks[2])+"的主乐器非技能"+skill_name(subsks[1])+"，而你在该音乐主乐器上的造诣不够，\n"+
				                "无法将该音乐演绎到其他乐器上。\n");
				return 0;
			}
		}
		
		if ( sizeof(reqlv)>2 )
		{
			sub_key=keys(music[subsks[1]]);
			delkey=({});
			for(lp=0;lp<sizeof(sub_key);lp++)
			  if ( !mapp(music[subsks[1]][sub_key[lp]]) )
			  	delkey+=({sub_key[lp]});
			
			sub_key-=delkey;
			for(lp=0;lp<sizeof(sub_key);lp++)
			{
				if ( subskill_info[sub_key[lp]]["level"]<=sizeof(reqlv)-3 && 
					   music[subsks[1]][sub_key[lp]]["level"]>=reqlv[subskill_info[sub_key[lp]]["level"]+2] )
					isReq[subskill_info[sub_key[lp]]["level"]]=1;
			}
			
			for(lp=2;lp<sizeof(reqlv);lp++)
			  if ( !isReq[lp-2] )
			  {
			  	tell_object(me, "你学习的音乐"+skill_name(subsks[2])+"要求你在"+level_name[lp-2]+"上具有一定的造诣才行。\n");
			  	return 0;
			  }
		}
	}
	
	return 1;
}

//返回子技能的名称
string skill_name(string sk_id)
{
	if ( !subskill_info[sk_id] )
		error("在music技能下面并无子技能"+sk_id+"。\n");
	
	if ( subskill_info[sk_id]["class"]!=3 )
	  return subskill_info[sk_id]["name"];
	else
		return subskill_info[sk_id]["name"]+"-"+level_name[subskill_info[sk_id]["level"]]+"-";
}

//music技能自定义的不同层级技能之间的换算关系
mapping improve_skill(object ob)
{
	mapping music,sk,sub_music;
	string *sk_key, *subsk_key, *delkey;
	float t_exp,sub_exp, buf_exp;
	int *sublv, *sublrn, sklev,lp,p2;
	
	sk=ob->query_skills();
	if ( !sk || !mapp(sk["music"]) )
		return 0;
	
	music=sk["music"];
	
	sk_key=keys(music);
	if(!sizeof(sk_key)) return 0;
	delkey=({});
	for(lp=0;lp<sizeof(sk_key);lp++)
	{
    if ( !mapp(music[sk_key[lp]]) )
   	  delkey+=({sk_key[lp]});
   	else if ( subskill_info[sk_key[lp]]["class"]!=2 )
   		delkey+=({sk_key[lp]});
  }
  delkey+=({"music-theory"});
  sk_key-=delkey;
	if ( mapp(music["music-theory"]) )
	{
		music["music-theory"]["level"]=music["music-theory"]["self_level"];
		t_exp=skill_exp(music["music-theory"]["level"], music["music-theory"]["learned"])/2;
	}
	
	sub_exp=0;
	for(lp=0;lp<sizeof(sk_key);lp++)
	{
		sub_music=music[sk_key[lp]];
		subsk_key=keys(sub_music);
		delkey=({});
		for(p2=0;p2<sizeof(subsk_key);p2++)
		{
      if ( !mapp(sub_music[subsk_key[p2]]) )
   	    delkey+=({subsk_key[p2]});
   	  else if ( subskill_info[subsk_key[p2]]["class"]!=3 )
   	  	delkey+=({subsk_key[p2]});
   	}
   	subsk_key-=delkey;
   	sublv=({0,0,0,0,0,0,0,0,0,0});
   	sublrn=({0,0,0,0,0,0,0,0,0,0});
   	for(p2=0;p2<sizeof(subsk_key);p2++)
   	{
   		sklev=subskill_info[subsk_key[p2]]["level"];
   		if ( sub_music[subsk_key[p2]]["level"]>sublv[sklev] ||
   			   ( sub_music[subsk_key[p2]]["level"]==sublv[sklev] && 
   			     sub_music[subsk_key[p2]]["learned"]>sublrn[sklev] ) )
   		{
   			sublv[sklev]=sub_music[subsk_key[p2]]["level"];
   			sublrn[sklev]=sub_music[subsk_key[p2]]["learned"];
   		}
   	}
   	buf_exp=0;
   	for (p2=0;p2<sizeof(sublv);p2++)
   		buf_exp+=skill_exp(sublv[p2], sublrn[p2])*(10+(p2-3)*2)/10;
   	buf_exp+=skill_exp(sub_music["self_level"], sub_music["learned"])/2;
   	if ( buf_exp>sub_exp )
   		sub_exp=buf_exp;
   	sub_music["level"]=skill_level(buf_exp);
  }
  music["level"]=skill_level(t_exp+sub_exp);
  return music;
}

protected float skill_exp(int level, int learned)
{
	float exp;
	
	exp=0.0;
/*	for(int lp=0;lp<level;lp++)
		exp+=(lp+1)*(lp+1);*/
	if ( level ) 
	  exp=level_exp[to_int(level-1)];
	else
		exp=0;
	
	exp+=learned;
	return exp;
}

protected int skill_level(float exp)
{
	float tmp;
	int level;
	tmp=exp;
	level=0;
	for(int lp=0;lp<1999;lp++)
	{
		if ( exp>=level_exp[lp] &&
			exp<level_exp[lp+1] )
		{
			level=lp+1;
			break;
		}
	}
	
	if ( !level && exp>1 )
		level=2000;
	
	return level;
}