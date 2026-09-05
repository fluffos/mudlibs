//提供以下几种特效：
//迟缓1～5：普通攻击速度降低
//紊乱1～20：特殊攻击有几率失败
//技能增幅1～10和技能抑制1～10：提供技能类BUFF和技能类DEBUFF
//天赋增幅1～10和天赋抑制1～10：提供天赋类BUFF和天赋类DEBUFF
//增加气血/精神最大值1～20：临时增加气血/精神最大值
//恢复速率增幅1～20和恢复速率抑制1～20：提供气血/精神/内力/精力的恢复治疗速率BUFF和恢复治疗速率DEBUFF
//伤害/防御增幅1～10和伤害/防御抑制1～10：提供伤害/防御类BUFF和伤害/防御类DEBUFF
//持续掉血/持续伤精1～100
//持续恢复1～50

#include <combat/music.h>
#include <ansi.h>
int compare_effect( object player, object target, string tune, int effect_level, int effect_coef);

//音乐效果作用主系数计算
//音乐效果系数主要由音乐技能和最大内力来决定，并且有先天智力决定系数上限
int primary_coef(object player, string instrument, string tune)
{
	int neili, gift, base_sk, instr_sk, tune_sk;
	int coef;
	
	if ( !player )
		return 0;
	
	if ( member_array(instrument, subskill_info[tune]["master"])<0 )
		return 0;
	
	neili=player->query("max_neili");
	gift=player->query("int");
	base_sk=player->query_sub_skill("music::music-theory");
	instr_sk=player->query_sub_skill("music::"+instrument);
	tune_sk=player->query_sub_skill("music::"+instrument+"::"+tune);
	
	if ( neili>33000 )
		neili=33000;
	
	if ( gift>50 )
		gift=50;
	
	if ( base_sk>1500 )
		base_sk=1500;
	
	if ( instr_sk>1500 )
		instr_sk=1500;
	
	if ( tune_sk>1500 )
		tune_sk=1500;

//最大值是1500+300+150+1100=3050
	coef=tune_sk+instr_sk/5+base_sk/10+neili/30;
	if ( gift<=15 && coef>=500 )
		coef=500;
	
	if ( gift>15 && gift<=25 && coef>=1000 )
		coef=1000;
	
	if ( gift>25 && gift<=35 && coef>=1500 )
		coef=1500;
	
	return coef;
}

//音乐效果作用辅系数计算
//辅系数数值是主系数/5
int auxiliary_coef(object player, string instrument, string tune)
{
	int neili, gift, base_sk, instr_sk, tune_sk;
	int coef;
	
	if ( !player )
		return 0;
	
	if ( member_array(instrument, subskill_info[tune]["master"])>=0 )
		return 0;
	
	neili=player->query("max_neili");
	gift=player->query("int");
	base_sk=player->query_sub_skill("music::music-theory");
	instr_sk=player->query_sub_skill("music::"+instrument);
	tune_sk=player->query_sub_skill("music::"+instrument+"::"+tune);
	
	if ( neili>33000 )
		neili=33000;
	
	if ( gift>50 )
		gift=50;
	
	if ( base_sk>1500 )
		base_sk=1500;
	
	if ( instr_sk>1500 )
		instr_sk=1500;
	
	if ( tune_sk>1500 )
		tune_sk=1500;

//最大值是300+60+30+220=610	
	coef=tune_sk/5+instr_sk/25+base_sk/50+neili/150;
	if ( gift<=15 && coef>=100 )
		coef=100;
	
	if ( gift>15 && gift<=25 && coef>=200 )
		coef=200;
	
	if ( gift>25 && gift<=35 && coef>=300 )
		coef=300;
	
	return coef;
}

//寻找伴奏者
//需要作用对象提供查询伴奏乐器限定列表的函数query_aux_instrument(string instrument)
//返回值大于0表示有正伴奏效果，小于0表示有负伴奏效果，等于0表示该乐器可以忽略
//本函数返回值是伴奏者实际的音乐效果辅助系数
int find_accompanist(object player, string instrument, string tune)
{
	object *invs, inv, env;
	object ob=this_object();
	int aux_coef, t_coef, aux_direct, t_direct;
	
  if ( !instrument || !subskill_info[instrument] || subskill_info[instrument]["class"]!=2 )
  	return 0;
  
  if ( !tune || !subskill_info[tune] || subskill_info[tune]["class"]!=3 )
  	return 0;
  
  if ( member_array(instrument, subskill_info[tune]["master"])<0 )
  	return 0;
  
  if ( !player || !(env=environment(player) ) ||
  	   !env->isroom() )
  	return 0;
  
  invs=all_inventory(env);
  aux_coef=0;
  foreach( inv in invs)
  {
  	if ( !inv->is_character() || inv==player )
  		continue;
  	//不同乐曲或者同一种乐器的不考虑伴奏效果
  	if ( inv->query_temp("play_music/tune") != tune ||
  		   inv->query_temp("play_music/instrument") == instrument )
  		continue;
  	
  	if ( !inv->query_temp("play_music/instrument") ||
  		   inv->query_temp("play_music/auxiliary_coef")<=0 )
  	  continue;
  	
  	t_direct=ob->query_aux_instrument(inv->query_temp("play_music/instrument"));	
  	if ( !t_direct )
  		continue;
  	
  	t_coef=inv->query_temp("play_music/auxiliary_coef");
  	if ( aux_coef>t_coef ) 
  		continue;
  	
  	if ( aux_coef==t_coef &&
  		   t_direct*aux_direct<0 )
  	{
  		aux_coef=0;
  		aux_direct=0;
  		continue;
  	}
  	else if ( aux_coef==t_coef )
  		continue;
  	
  	aux_coef=t_coef;
  	aux_direct=t_direct;
  }
  
  if ( aux_direct>0 )
  	return aux_coef;
  else
  	return -aux_coef;
}

//寻找其他演奏者
//本函数返回值是其他演奏者实际的音乐效果作用系数
//参数mode是寻找模式，
//0--表示找所有主乐器演奏者
//1--表示寻找使用不同主乐器的演奏者
//2--表示寻找使用相同主乐器的演奏者
int find_player(object player, string instrument, string tune, int mode)
{
	object *invs, inv, env;
	object ob=this_object();
	int pri_coef, t_coef;
	
  if ( !instrument || !subskill_info[instrument] || subskill_info[instrument]["class"]!=2 )
  	return 0;
  
  if ( !tune || !subskill_info[tune] || subskill_info[tune]["class"]!=3 )
  	return 0;
  
  if ( member_array(instrument, subskill_info[tune]["master"])<0 )
  	return 0;
  
  if ( !player || !(env=environment(player) ) ||
  	   !env->isroom() )
  	return 0;
  
  invs=all_inventory(env);
  pri_coef=0;
  foreach( inv in invs)
  {
  	if ( !inv->is_character() || inv==player )
  		continue;
  	//不同乐曲或者同一种乐器的不考虑伴奏效果
  	if ( inv->query_temp("play_music/tune") != tune ||
  		   (mode==1 && inv->query_temp("play_music/instrument") == instrument) ||
  		   (mode==2 && inv->query_temp("play_music/instrument") != instrument) )
  		continue;
  	
  	if ( !inv->query_temp("play_music/instrument") ||
  		   inv->query_temp("play_music/primary_coef")<=0 )
  	  continue;
  	
  	t_coef=inv->query_temp("play_music/primary_coef");
  	if ( pri_coef>=t_coef ) 
  		continue;
  	
  	pri_coef=t_coef;
  }
  
 	return pri_coef;
}

//寻找其他演奏者
//本函数返回值是其他演奏者实际的音乐效果作用系数
//参数mode是寻找模式，
//0--表示找所有主乐器演奏者
//1--表示寻找使用不同主乐器的演奏者
//2--表示寻找使用相同主乐器的演奏者
object findo_player(object player, string instrument, string tune, int mode)
{
	object *invs, inv, env;
	object ob=this_object(), tgt;
	int pri_coef, t_coef;
	
  if ( !instrument || !subskill_info[instrument] || subskill_info[instrument]["class"]!=2 )
  	return 0;
  
  if ( !tune || !subskill_info[tune] || subskill_info[tune]["class"]!=3 )
  	return 0;
  
  if ( member_array(instrument, subskill_info[tune]["master"])<0 )
  	return 0;
  
  if ( !player || !(env=environment(player) ) ||
  	   !env->isroom() )
  	return 0;
  
  invs=all_inventory(env);
  pri_coef=0;
  tgt=0;
  foreach( inv in invs)
  {
  	if ( !inv->is_character() || inv==player )
  		continue;
  	//不同乐曲或者同一种乐器的不考虑伴奏效果
  	if ( inv->query_temp("play_music/tune") != tune ||
  		   (mode==1 && inv->query_temp("play_music/instrument") == instrument) ||
  		   (mode==2 && inv->query_temp("play_music/instrument") != instrument) )
  		continue;
  	
  	if ( !inv->query_temp("play_music/instrument") ||
  		   inv->query_temp("play_music/primary_coef")<=0 )
  	  continue;
  	
  	t_coef=inv->query_temp("play_music/primary_coef");
  	if ( pri_coef>=t_coef ) 
  		continue;
  	
  	pri_coef=t_coef;
  	tgt=inv;
  }
  
 	return tgt;
}

//效果对抗系数，暂时设定为最大内力/20
int anti_coef(object target)
{
	int con,base_sk;
	
	if ( !target || !target->is_character() )
		return 0;
	
	con=target->query("con");
	base_sk=target->query_sub_skill("music::music-theory");
	if ( con<20 ) 
	  return target->query("max_neili")/40+base_sk/2;
	else if ( con<30 )
		return target->query("max_neili")/30+base_sk/2;
	else
		return target->query("max_neili")/20+base_sk/2;
}

//特效迟缓，作用是让对方的普通攻击的攻击速度降低
//具体效果是有效果级别，主系数，辅系数三者综合决定
//其中效果级别分为0，1，2, 3, 4五级，代表迟钝效果的三种效果
//tune指的是产生该效果的乐谱
int effect_slow(object player, object *targets, string instrument, string tune, int effect_level, int pri_coef, int aux_coef)
{
  int lp, eff;
  
  if ( !player || !tune )
  	return 0;

//降低攻速-5%到-150%  
  if ( pri_coef+aux_coef< 300 ||
  	   effect_level<0 )
  	eff=-5;
  else if ( effect_level<=4 && pri_coef+aux_coef<=1800 )
    eff=-5*(1+effect_level)*(pri_coef+aux_coef)/300;
  else if ( effect_level>4 && pri_coef+aux_coef<=1800 )
  	eff=-25*(pri_coef+aux_coef)/300;
  else if ( effect_level<=4 && pri_coef+aux_coef>1800 )
  	eff=-30*(1+effect_level);
  else
  	eff=-150;
  
  for( lp=0; lp<sizeof(targets); lp++)
  {
  	if ( !targets[lp]->is_character() )
  		continue;
  	if ( anti_coef(targets[lp])>pri_coef+aux_coef ) //如果角色的对抗系数大于音乐效果系数，则音乐效果对该角色无效
    {
    	tell_object(targets[lp], sprintf(CYN"%s对你弹奏了乐曲"WHT"『%s』"CYN"，你运起真气抵抗了音乐的效果。\n"NOR, player->name(), subskill_info[tune]["name"]));
  		continue;
  	}
//如果这个角色已经中了该音乐效果，并且效果强于你的音乐效果
//则你的音乐效果被忽略  	
  	if ( targets[lp]->query_temp(tune+"/attack_speed")!=0 &&
  		   compare_effect( player, targets[lp], tune, effect_level, pri_coef+aux_coef)>=0 )
  		continue;
//如果这个角色已经中了该音乐效果，并且效果弱于你的音乐效果
//则你的音乐效果覆盖对方的音乐效果
  	else if ( targets[lp]->query_temp(tune+"/attack_speed")!=0 &&
  		   compare_effect( player, targets[lp], tune, effect_level, pri_coef+aux_coef)<0 )
  	{
  		targets[lp]->add_temp("apply/attack_speed",-targets[lp]->query_temp(tune+"/attack_speed"));
  	}
  	targets[lp]->add_temp("apply/attack_speed", eff);
  	targets[lp]->set_temp(tune+"/attack_speed", eff);
  	targets[lp]->set_temp(tune+"/effect_coef", pri_coef+aux_coef );
  	targets[lp]->set_temp(tune+"/effect_level", effect_level );
  	targets[lp]->set_temp("music_status/"+tune+"/name", subskill_info[tune]["name"]+"【"+instrument_name[instrument]+"】");
  	targets[lp]->set_temp("music_status/"+tune+"/id", player->query("id") );
  	targets[lp]->set_temp("music_status/"+tune+"/effect_slow", "迟缓"+(effect_level+1)+"级");
  }
  
  return eff;
}

//特效破甲/防护，作用是普通攻击伤害加深/伤害削弱
//具体效果是有效果级别，主系数，辅系数三者综合决定
//其中效果级别分为0到9十级
//tune指的是产生该效果的乐谱
int effect_sunder(object player, object *targets, string instrument, string tune, int effect_level, int pri_coef, int aux_coef, int direct)
{
  int lp, eff;
  
  if ( !player || !tune )
  	return 0;
  	
  if ( direct != -1 &&
  	   direct != 1 )
    error("破甲/防护类音乐特效只能加载BUFF类或者DEBUFF类特效。");

//破甲（加深伤害）+2%到+60%  
//防御（削弱伤害）-2%到-60%
  if ( pri_coef+aux_coef< 300 ||
  	   effect_level<0 )
  	eff=2;
  else if ( effect_level<=9 && pri_coef+aux_coef<=1800 )
    eff=2*(1+effect_level)*(pri_coef+aux_coef)/600;
  else if ( effect_level>9 && pri_coef+aux_coef<=1800 )
  	eff=20*(pri_coef+aux_coef)/600;
  else if ( effect_level<=9 && pri_coef+aux_coef>1800 )
  	eff=6*(1+effect_level);
  else
  	eff=60;
  
  for( lp=0; lp<sizeof(targets); lp++)
  {
  	if ( !targets[lp]->is_character() )
  		continue;
  		
  	if ( direct<0 && anti_coef(targets[lp])>pri_coef+aux_coef ) //如果角色的对抗系数大于音乐效果系数，则音乐效果对该角色无效
    {
    	tell_object(targets[lp], sprintf(CYN"%s对你弹奏了乐曲"WHT"『%s』"CYN"，你运起真气抵抗了音乐的效果。\n"NOR, player->name(), subskill_info[tune]["name"]));
  		continue;
  	}
//如果这个角色已经中了该音乐效果，并且效果强于你的音乐效果
//则你的音乐效果被忽略  	
  	if ( targets[lp]->query_temp(tune+"/week_injure")!=0 &&
  		   compare_effect( player, targets[lp], tune, effect_level, pri_coef+aux_coef)>=0 )
  		continue;
//如果这个角色已经中了该音乐效果，并且效果弱于你的音乐效果
//则你的音乐效果覆盖对方的音乐效果
  	else if ( targets[lp]->query_temp(tune+"/week_injure")!=0 &&
  		   compare_effect( player, targets[lp], tune, effect_level, pri_coef+aux_coef)<0 )
  	{
  		targets[lp]->add_temp("apply/week_injure",-targets[lp]->query_temp(tune+"/week_injure"));
  	}
  	targets[lp]->add_temp("apply/week_injure", direct*eff);
  	targets[lp]->set_temp(tune+"/week_injure", direct*eff);
  	targets[lp]->set_temp(tune+"/effect_coef", pri_coef+aux_coef );
  	targets[lp]->set_temp(tune+"/effect_level", effect_level );
  	targets[lp]->set_temp("music_status/"+tune+"/name", subskill_info[tune]["name"]+"【"+instrument_name[instrument]+"】");
  	targets[lp]->set_temp("music_status/"+tune+"/id", player->query("id") );
  	targets[lp]->set_temp("music_status/"+tune+"/effect_sunder", sprintf("%s%d级", direct>0?"防护":"破甲", (effect_level+1)));
  }
  
  return eff;
}

//特效紊乱，作用是PERFORM/EXERT等功能随机失效，失效后产生1s的busy
//效果级别分为20级
int effect_disorder(object player, object *targets, string instrument, string tune, int effect_level, int pri_coef, int aux_coef)
{
  int lp, eff;
  
  if ( !player || !tune )
  	return 0;

//紊乱几率从1%到100%  
  if ( pri_coef+aux_coef< 300 ||
  	   effect_level<0 )
  	eff=1;
  else if ( effect_level<=19 && pri_coef+aux_coef<=1500 )
    eff=(1+effect_level)*(pri_coef+aux_coef)/300;
  else if ( effect_level>19 && pri_coef+aux_coef<=1500 )
  	eff=(pri_coef+aux_coef)/15;
  else if ( effect_level<=19 && pri_coef+aux_coef>1500 )
  	eff=5*(1+effect_level);
  else
  	eff=100;
  
  for( lp=0; lp<sizeof(targets); lp++)
  {
  	if ( !targets[lp]->is_character() )
  		continue;
  	if ( anti_coef(targets[lp])>pri_coef+aux_coef ) //如果角色的对抗系数大于音乐效果系数，则音乐效果对该角色无效
    {
    	tell_object(targets[lp], sprintf(CYN"%s对你弹奏了乐曲"WHT"『%s』"CYN"，你运起真气抵抗了音乐的效果。\n"NOR, player->name(), subskill_info[tune]["name"]));
  		continue;
  	}
//如果这个角色已经中了该音乐效果，并且效果强于你的音乐效果
//则你的音乐效果被忽略  	
  	if ( targets[lp]->query_temp(tune+"/disorder_percent")!=0 &&
  		   compare_effect( player, targets[lp], tune, effect_level, pri_coef+aux_coef)>=0 )
  		continue;
//如果这个角色已经中了该音乐效果，并且效果弱于你的音乐效果
//则你的音乐效果覆盖对方的音乐效果
  	else if ( targets[lp]->query_temp(tune+"/disorder_percent")!=0 &&
  		   compare_effect( player, targets[lp], tune, effect_level, pri_coef+aux_coef)<0 )
  	{
  		targets[lp]->add_temp("apply/disorder_percent",-targets[lp]->query_temp(tune+"/disorder_percent"));
  	}
  	targets[lp]->add_temp("apply/disorder_percent", eff);
  	targets[lp]->set_temp(tune+"/disorder_percent", eff);
  	targets[lp]->set_temp(tune+"/effect_coef", pri_coef+aux_coef );
  	targets[lp]->set_temp(tune+"/effect_level", effect_level );
  	targets[lp]->set_temp("music_status/"+tune+"/name", subskill_info[tune]["name"]+"【"+instrument_name[instrument]+"】");
  	targets[lp]->set_temp("music_status/"+tune+"/id", player->query("id") );
  	targets[lp]->set_temp("music_status/"+tune+"/effect_disorder", "紊乱"+(effect_level+1)+"级");
  }
  
  return eff;
}

//特效提高技能类BUFF和DEBUFF
//支持以下几种技能类的自由组合:
//attack, defense, dodge, parry, sword, blade, staff, whip, hammer, spear, dagger, cuff, strike, claw, hand, finger
//参数direct有两个值-1和1分别表示debuff和buff
int effect_skill(object player, object *targets, string instrument, string tune, string *effects, int effect_level, int pri_coef, int aux_coef, int direct)
{
  int lp, eff, p2;
  string *effect_scope=({"attack", "defense", "dodge", "parry", "sword", "blade", "staff", "whip", 
  	     "hammer", "spear", "dagger", "cuff", "strike", "claw", "hand", "finger"});
  mapping effect_name=(["attack":"攻击命中", "defense":"防御命中", "dodge":"轻功", "parry":"招架",
  	"sword":"剑法", "blade":"刀法", "staff":"杖法", "whip":"鞭法", "hammer":"锤法", "spear":"枪法",
  	"dagger":"匕首", "cuff":"拳法", "strike":"掌法","claw":"爪法","hand":"手法","finger":"指法"]);
  string *teffs, *deleffs, meff;
  
  if ( !player || !tune )
  	return 0;
  
  if ( direct != -1 &&
  	   direct != 1 )
    error("技能类音乐特效只能加载BUFF类或者DEBUFF类特效。");
    
  teffs=effects;
  deleffs=({});
  foreach(meff in teffs)
   if ( member_array(meff, effect_scope)<0 )
   	deleffs+=({meff});
  
  teffs=teffs-deleffs;
  if ( sizeof(teffs)==0 )
  	return 0;
  
//增加级别从10级到800级范围内浮动  
  if ( pri_coef+aux_coef< 300 ||
  	   effect_level<0 )
  	eff=10;
  else if ( effect_level<=9 && pri_coef+aux_coef<=2400 )
    eff=10*(1+effect_level)*(pri_coef+aux_coef)/300;
  else if ( effect_level>9 && pri_coef+aux_coef<=2400 )
  	eff=100*(pri_coef+aux_coef)/300;
  else if ( effect_level<=9 && pri_coef+aux_coef>2400 )
  	eff=80*(1+effect_level);
  else
  	eff=800;
  
  for( lp=0; lp<sizeof(targets); lp++)
  {
  	if ( !targets[lp] || !targets[lp]->is_character() )
  		continue;

  	if ( direct<0 && anti_coef(targets[lp])>pri_coef+aux_coef ) //如果角色的对抗系数大于音乐效果系数，则音乐效果对该角色无效
    {
    	tell_object(targets[lp], sprintf(CYN"%s对你弹奏了乐曲"WHT"『%s』"CYN"，你运起真气抵抗了音乐的效果。\n"NOR, player->name(), subskill_info[tune]["name"]));
  		continue;
  	}
  	
  	foreach( meff in teffs) 
  	{
//如果这个角色已经中了该音乐效果，并且效果强于你的音乐效果
//则你的音乐效果被忽略  	
  	  if ( targets[lp]->query_temp(tune+"/"+meff)!=0 &&
  		   compare_effect( player, targets[lp], tune, effect_level, pri_coef+aux_coef)>=0 )
  		  continue;
//如果这个角色已经中了该音乐效果，并且效果弱于你的音乐效果
//则你的音乐效果覆盖对方的音乐效果
  	  else if ( targets[lp]->query_temp(tune+"/"+meff)!=0 &&
  		   compare_effect( player, targets[lp], tune, effect_level, pri_coef+aux_coef)<0 )
  	  {
  		  targets[lp]->add_temp("apply/"+meff,-targets[lp]->query_temp(tune+"/"+meff));
  	  }
  	  targets[lp]->add_temp("apply/"+meff, direct*eff);
  	  targets[lp]->set_temp(tune+"/"+meff, direct*eff);
  	  targets[lp]->set_temp("music_status/"+tune+"/effect_"+meff, sprintf("%s%s%d级", effect_name[meff],(direct>0?"增益":"减益"),(effect_level+1)));
  	}
  	targets[lp]->set_temp(tune+"/effect_coef", pri_coef+aux_coef );
  	targets[lp]->set_temp(tune+"/effect_level", effect_level );
  	targets[lp]->set_temp("music_status/"+tune+"/id", player->query("id") );
  	targets[lp]->set_temp("music_status/"+tune+"/name", subskill_info[tune]["name"]+"【"+instrument_name[instrument]+"】");
  }
  
  return eff;
}

//特效提高天赋类BUFF和DEBUFF
//支持以下几种天赋类的自由组合:
//strength, intelligence, constitution, dexerity
int effect_attribute(object player, object *targets, string instrument, string tune, string *effects, int effect_level, int pri_coef, int aux_coef, int direct)
{
  int lp, eff, p2;
  string *effect_scope=({"strength", "intelligence", "constitution", "dexerity"});
  mapping effect_name=(["strength":"膂力天赋", "intelligence":"悟性天赋", "constitution":"根骨天赋", "dexerity":"身法天赋"]);
  string *teffs, *deleffs, meff;

  if ( !player || !tune )
  	return 0;

  if ( direct != -1 &&
  	   direct != 1 )
    error("天赋类音乐特效只能加载BUFF类或者DEBUFF类特效。");
  
  teffs=effects;
  deleffs=({});
  foreach(meff in teffs)
   if ( member_array(meff, effect_scope)<0 )
   	deleffs+=({meff});
  
  teffs=teffs-deleffs;
  if ( sizeof(teffs)==0 )
  	return 0;

//增加天赋从3点到210点范围内浮动  
  if ( pri_coef+aux_coef< 300 ||
  	   effect_level<0 )
  	eff=3;
  else if ( effect_level<=9 && pri_coef+aux_coef<=2100 )
    eff=3*(1+effect_level)*(pri_coef+aux_coef)/300;
  else if ( effect_level>9 && pri_coef+aux_coef<=2100 )
  	eff=30*(pri_coef+aux_coef)/300;
  else if ( effect_level<=9 && pri_coef+aux_coef>2100 )
  	eff=21*(1+effect_level);
  else
  	eff=210;
  
  for( lp=0; lp<sizeof(targets); lp++)
  {
  	if ( !targets[lp] || !targets[lp]->is_character() )
  		continue;

  	if ( direct<0 && anti_coef(targets[lp])>pri_coef+aux_coef ) //如果角色的对抗系数大于音乐效果系数，则音乐效果对该角色无效
    {
    	tell_object(targets[lp], sprintf(CYN"%s对你弹奏了乐曲"WHT"『%s』"CYN"，你运起真气抵抗了音乐的效果。\n"NOR, player->name(), subskill_info[tune]["name"]));
  		continue;
  	}
  	
  	foreach( meff in teffs) 
  	{
//如果这个角色已经中了该音乐效果，并且效果强于你的音乐效果
//则你的音乐效果被忽略  	
  	  if ( targets[lp]->query_temp(tune+"/"+meff)!=0 &&
  		   compare_effect( player, targets[lp], tune, effect_level, pri_coef+aux_coef)>=0 )
  		  continue;
//如果这个角色已经中了该音乐效果，并且效果弱于你的音乐效果
//则你的音乐效果覆盖对方的音乐效果
  	  else if ( targets[lp]->query_temp(tune+"/"+meff)!=0 &&
  		   compare_effect( player, targets[lp], tune, effect_level, pri_coef+aux_coef)<0 )
  	  {
  		  targets[lp]->add_temp("apply/"+meff,-targets[lp]->query_temp(tune+"/"+meff));
  	  }
  	  targets[lp]->add_temp("apply/"+meff, direct*eff);
  	  targets[lp]->set_temp(tune+"/"+meff, direct*eff);
  	  targets[lp]->set_temp("music_status/"+tune+"/effect_"+meff, sprintf("%s%s%d级", effect_name[meff],(direct>0?"增益":"减益"),(effect_level+1)));
  	}
  	targets[lp]->set_temp(tune+"/effect_coef", pri_coef+aux_coef );
  	targets[lp]->set_temp(tune+"/effect_level", effect_level );
  	targets[lp]->set_temp("music_status/"+tune+"/id", player->query("id") );
  	targets[lp]->set_temp("music_status/"+tune+"/name", subskill_info[tune]["name"]+"【"+instrument_name[instrument]+"】");
  }
  
  return eff;
}

//仅支持加特定标记
//效果级别就是特定标记的效果数值
//这里effect_level必须大于等于1
int effect_mark(object player, object *targets, string instrument, string tune, string *effects, string *effects_desc, int effect_level, int pri_coef, int aux_coef)
{
  int lp, p2;

  if ( !player || !tune )
  	return 0;
  
  if ( !effect_level )
    return 0;

  for( lp=0; lp<sizeof(targets); lp++)
  {
  	if ( !targets[lp] || !targets[lp]->is_character() )
  		continue;

  	for( p2=0; p2<sizeof(effects); p2++)
  	{
//如果这个角色已经中了该音乐效果，并且效果强于你的音乐效果
//则你的音乐效果被忽略  	
  	  if ( targets[lp]->query_temp(tune+"/"+effects[p2])!=0 &&
  		   compare_effect( player, targets[lp], tune, effect_level, pri_coef+aux_coef)>=0 )
  		  continue;

  	  targets[lp]->set_temp("apply/"+effects[p2], effect_level);
  	  targets[lp]->set_temp(tune+"/"+effects[p2], effect_level);
  	  targets[lp]->set_temp("music_status/"+tune+"/effect_"+effects[p2], sprintf("%s%d级", effects_desc[p2],effect_level));
  	}
  	targets[lp]->set_temp(tune+"/effect_coef", pri_coef+aux_coef );
  	targets[lp]->set_temp(tune+"/effect_level", effect_level );
  	targets[lp]->set_temp("music_status/"+tune+"/id", player->query("id") );
  	targets[lp]->set_temp("music_status/"+tune+"/name", subskill_info[tune]["name"]+"【"+instrument_name[instrument]+"】");
  }
  
  return effect_level;
}

//特效提高气血精神类BUFF（气血精神类可以设置0-19级一共20个级别）
//支持以下几种气血精神类的自由组合:
//max_qi, max_jing
int effect_hp(object player, object *targets, string instrument, string tune, string *effects, int effect_level, int pri_coef, int aux_coef)
{
  int lp, eff, p2;
  string *effect_scope=({"max_qi", "max_jing"});
  mapping effect_name=(["max_qi":"气血", "max_jing":"精神"]);
  string *teffs, *deleffs, meff;

  if ( !player || !tune )
  	return 0;
  
  teffs=effects;
  deleffs=({});
  foreach(meff in teffs)
   if ( member_array(meff, effect_scope)<0 )
   	deleffs+=({meff});
  
  teffs=teffs-deleffs;
  if ( sizeof(teffs)==0 )
  	return 0;
  	
//增加气血从75点到15000点范围内浮动  
  if ( pri_coef+aux_coef< 300 ||
  	   effect_level<0 )
  	eff=75;
  else if ( effect_level<=19 && pri_coef+aux_coef<=3000 )
    eff=(1+effect_level)*(pri_coef+aux_coef)/4;
  else if ( effect_level>19 && pri_coef+aux_coef<=3000 )
  	eff=5*(pri_coef+aux_coef);
  else if ( effect_level<=19 && pri_coef+aux_coef>3000 )
  	eff=750*(1+effect_level);
  else
  	eff=15000;
  
  for( lp=0; lp<sizeof(targets); lp++)
  {
  	if ( !targets[lp] || 
  		   !targets[lp]->is_character() ||
  		   !userp(targets[lp]) )
  		continue;
  	
  	foreach( meff in teffs) 
  	{
//如果这个角色已经中了该音乐效果，并且效果强于你的音乐效果
//则你的音乐效果被忽略  	
  	  if ( targets[lp]->query_temp(tune+"/"+meff)!=0 &&
  		   compare_effect( player, targets[lp], tune, effect_level, pri_coef+aux_coef)>=0 )
  		  continue;
//如果这个角色已经中了该音乐效果，并且效果弱于你的音乐效果
//则你的音乐效果覆盖对方的音乐效果
  	  else if ( targets[lp]->query_temp(tune+"/"+meff)!=0 &&
  		   compare_effect( player, targets[lp], tune, effect_level, pri_coef+aux_coef)<0 )
  	  {
  		  targets[lp]->add_temp("apply/"+meff,-targets[lp]->query_temp(tune+"/"+meff));
  		  if ( meff=="max_qi" )
  		    targets[lp]->add("eff_qi", -targets[lp]->query_temp(tune+"/"+meff) );
  		  else
  		  	targets[lp]->add("eff_jing", -targets[lp]->query_temp(tune+"/"+meff) );
  	  }
  	  targets[lp]->add_temp("apply/"+meff, eff);
  	  targets[lp]->set_temp(tune+"/"+meff, eff);
  	  targets[lp]->set("max_qi", targets[lp]->query_max_qi());
  	  targets[lp]->set("max_jing", targets[lp]->query_max_jing());
  		if ( meff=="max_qi" )
  		  targets[lp]->add("eff_qi", targets[lp]->query_temp(tune+"/"+meff) );
  		else
  			targets[lp]->add("eff_jing", targets[lp]->query_temp(tune+"/"+meff) );
  	  targets[lp]->set_temp("music_status/"+tune+"/effect_"+meff, sprintf("%s%s%d级", effect_name[meff],"增益",(effect_level+1)));
  	}
  	targets[lp]->set_temp(tune+"/effect_coef", pri_coef+aux_coef );
  	targets[lp]->set_temp(tune+"/effect_level", effect_level );
  	targets[lp]->set_temp("music_status/"+tune+"/id", player->query("id") );
  	targets[lp]->set_temp("music_status/"+tune+"/name", subskill_info[tune]["name"]+"【"+instrument_name[instrument]+"】");
  }
  
  return eff;
}

//特效提高恢复速率类BUFF和DEBUFF（恢复类可以设置0-19级一共20个级别）
//支持以下几种气血精神类的自由组合:
//qi_recover, jing_recover, neili_recover, jingli_recover, qi_cure, jing_cure
int effect_recover(object player, object *targets, string instrument, string tune, string *effects, int effect_level, int pri_coef, int aux_coef, int direct)
{
  int lp, eff, p2;
  string *effect_scope=({"qi_recover", "jing_recover", "neili_recover", "jingli_recover", "qi_cure", "jing_cure"});
  mapping effect_name=(["qi_recover":"气血恢复", "jing_recover":"精神恢复", "neili_recover":"内力回复", "jingli_recover":"精力恢复", 
  	      "qi_cure":"气血治疗", "jing_cure":"精神治疗"]);
  string *teffs, *deleffs, meff;

  if ( !player || !tune )
  	return 0;

  if ( direct != -1 &&
  	   direct != 1 )
    error("恢复速率类音乐特效只能加载BUFF类或者DEBUFF类特效。");
  
  teffs=effects;
  deleffs=({});
  foreach(meff in teffs)
   if ( member_array(meff, effect_scope)<0 )
   	deleffs+=({meff});
  
  teffs=teffs-deleffs;
  if ( sizeof(teffs)==0 )
  	return 0;

//增加恢复速率从5点到1000点范围内浮动  
  if ( pri_coef+aux_coef<= 300 ||
  	   effect_level<0 )
  	eff=5;
  else if ( effect_level<=19 && pri_coef+aux_coef<=3000 )
    eff=5*(1+effect_level)*(pri_coef+aux_coef)/300;
  else if ( effect_level>19 && pri_coef+aux_coef<=3000 )
  	eff=100*(pri_coef+aux_coef)/300;
  else if ( effect_level<=19 && pri_coef+aux_coef>3000 )
  	eff=50*(1+effect_level);
  else
  	eff=1000;
  
  for( lp=0; lp<sizeof(targets); lp++)
  {
  	if ( !targets[lp] || 
  		   !targets[lp]->is_character() )
  		continue;

  	if ( direct<0 && anti_coef(targets[lp])>pri_coef+aux_coef ) //如果角色的对抗系数大于音乐效果系数，则音乐效果对该角色无效
    {
    	tell_object(targets[lp], sprintf(CYN"%s对你弹奏了乐曲"WHT"『%s』"CYN"，你运起真气抵抗了音乐的效果。\n"NOR, player->name(), subskill_info[tune]["name"]));
  		continue;
  	}
  	
  	foreach( meff in teffs) 
  	{
//如果这个角色已经中了该音乐效果，并且效果强于你的音乐效果
//则你的音乐效果被忽略  	
  	  if ( targets[lp]->query_temp(tune+"/"+meff)!=0 &&
  		   compare_effect( player, targets[lp], tune, effect_level, pri_coef+aux_coef)>=0 )
  		  continue;
//如果这个角色已经中了该音乐效果，并且效果弱于你的音乐效果
//则你的音乐效果覆盖对方的音乐效果
  	  else if ( targets[lp]->query_temp(tune+"/"+meff)!=0 &&
  		   compare_effect( player, targets[lp], tune, effect_level, pri_coef+aux_coef)<0 )
  	  {
  		  targets[lp]->add_temp("apply/"+meff,-targets[lp]->query_temp(tune+"/"+meff));
  	  }
  	  targets[lp]->add_temp("apply/"+meff, direct*eff);
  	  targets[lp]->set_temp(tune+"/"+meff, direct*eff);
  	  targets[lp]->set_temp("music_status/"+tune+"/effect_"+meff, sprintf("%s%s%d级", effect_name[meff],(direct>0?"增益":"减益"),(effect_level+1)));
  	}
  	targets[lp]->set_temp(tune+"/effect_coef", pri_coef+aux_coef );
  	targets[lp]->set_temp(tune+"/effect_level", effect_level );
  	targets[lp]->set_temp("music_status/"+tune+"/id", player->query("id") );
  	targets[lp]->set_temp("music_status/"+tune+"/name", subskill_info[tune]["name"]+"【"+instrument_name[instrument]+"】");
  }
  
  return eff;
}

//特效提高伤害防御类BUFF和DEBUFF
//支持以下几种伤害防御类的自由组合:
//damage, armor
int effect_damage(object player, object *targets, string instrument, string tune, string *effects, int effect_level, int pri_coef, int aux_coef, int direct)
{
  int lp, eff, p2;
  string *effect_scope=({"damage", "armor"});
  mapping effect_name=(["damage":"伤害", "armor":"防御"]);
  string *teffs, *deleffs, meff;

  if ( !player || !tune )
  	return 0;

  if ( direct != -1 &&
  	   direct != 1 )
    error("伤害防御类音乐特效只能加载BUFF类或者DEBUFF类特效。");
  
  teffs=effects;
  deleffs=({});
  foreach(meff in teffs)
   if ( member_array(meff, effect_scope)<0 )
   	deleffs+=({meff});
  
  teffs=teffs-deleffs;
  if ( sizeof(teffs)==0 )
  	return 0;
  	
//增加伤害从5点到400点范围内浮动  
  if ( pri_coef+aux_coef<= 300 ||
  	   effect_level<0 )
  	eff=5;
  else if ( effect_level<=9 && pri_coef+aux_coef<=2400 )
    eff=5*(1+effect_level)*(pri_coef+aux_coef)/300;
  else if ( effect_level>9 && pri_coef+aux_coef<=2400 )
  	eff=50*(pri_coef+aux_coef)/300;
  else if ( effect_level<=9 && pri_coef+aux_coef>2400 )
  	eff=40*(1+effect_level);
  else
  	eff=400;
  
  for( lp=0; lp<sizeof(targets); lp++)
  {
  	if ( !targets[lp] || !targets[lp]->is_character() )
  		continue;

  	if ( direct<0 && anti_coef(targets[lp])>pri_coef+aux_coef ) //如果角色的对抗系数大于音乐效果系数，则音乐效果对该角色无效
    {
    	tell_object(targets[lp], sprintf(CYN"%s对你弹奏了乐曲"WHT"『%s』"CYN"，你运起真气抵抗了音乐的效果。\n"NOR, player->name(), subskill_info[tune]["name"]));
  		continue;
  	}
  	
  	foreach( meff in teffs) 
  	{
//如果这个角色已经中了该音乐效果，并且效果强于你的音乐效果
//则你的音乐效果被忽略  	
  	  if ( targets[lp]->query_temp(tune+"/"+meff)!=0 &&
  		   compare_effect( player, targets[lp], tune, effect_level, pri_coef+aux_coef)>=0 )
  		  continue;
//如果这个角色已经中了该音乐效果，并且效果弱于你的音乐效果
//则你的音乐效果覆盖对方的音乐效果
  	  else if ( targets[lp]->query_temp(tune+"/"+meff)!=0 &&
  		   compare_effect( player, targets[lp], tune, effect_level, pri_coef+aux_coef)<0 )
  	  {
  		  targets[lp]->add_temp("apply/"+meff,-targets[lp]->query_temp(tune+"/"+meff));
  	  }
  	  targets[lp]->add_temp("apply/"+meff, direct*eff);
  	  targets[lp]->set_temp(tune+"/"+meff, direct*eff);
  	  targets[lp]->set_temp("music_status/"+tune+"/effect_"+meff, sprintf("%s%s%d级", effect_name[meff],(direct>0?"增益":"减益"),(effect_level+1)));
  	}
  	targets[lp]->set_temp(tune+"/effect_coef", pri_coef+aux_coef );
  	targets[lp]->set_temp(tune+"/effect_level", effect_level );
  	targets[lp]->set_temp("music_status/"+tune+"/id", player->query("id") );
  	targets[lp]->set_temp("music_status/"+tune+"/name", subskill_info[tune]["name"]+"【"+instrument_name[instrument]+"】");
  }
  
  return eff;
}

//持续掉血或者掉精（效果分为0-99级，一共100个级别）
int effect_wound(object player, object *targets, string tune, string *effects, int effect_level, int pri_coef, int aux_coef)
{
  int lp, eff, p2;
  string *effect_scope=({"qi", "jing"});
  string *teffs, *deleffs, meff;

  if ( !player || !tune )
  	return 0;
  
  teffs=effects;
  deleffs=({});
  foreach(meff in teffs)
    if ( member_array(meff, effect_scope)<0 )
   	  deleffs+=({meff});
  
  teffs=teffs-deleffs;
  if ( sizeof(teffs)==0 )
  	return 0;
  	
//每次减少气血/精神从5点到700点范围内浮动  
  if ( pri_coef+aux_coef<= 300 ||
  	   effect_level<0 )
  	eff=5;
  else if ( effect_level<=99 && pri_coef+aux_coef<=2100 )
    eff=(1+effect_level)*(pri_coef+aux_coef)/60;
  else if ( effect_level>99 && pri_coef+aux_coef<=2100 )
  	eff=5*(pri_coef+aux_coef)/3;
  else if ( effect_level<=99 && pri_coef+aux_coef>2100 )
  	eff=35*(1+effect_level);
  else
  	eff=3500;
  
  for( lp=0; lp<sizeof(targets); lp++)
  {
  	if ( !targets[lp] || 
  		   !targets[lp]->is_character() )
  		continue;

  	if ( anti_coef(targets[lp])>pri_coef+aux_coef ) //如果角色的对抗系数大于音乐效果系数，则音乐效果对该角色无效
    {
    	tell_object(targets[lp], sprintf(CYN"%s对你弹奏了乐曲"WHT"『%s』"CYN"，你运起真气抵抗了音乐的效果。\n"NOR, player->name(), subskill_info[tune]["name"]));
  		continue;
  	}
  	
  	foreach( meff in teffs) 
  	{
  	  targets[lp]->receive_damage(meff, eff, player);
  	  if ( effect_level>=10 )
  	  {
  	    targets[lp]->receive_wound(meff, eff/3, player);
  	  }

	  tell_object( targets[lp], sprintf(RED"你受到%s弹奏的乐曲『%s』的影响。\n"NOR, player->name(), subskill_info[tune]["name"]) );
	  COMBAT_D->report_status(targets[lp]);
	  if ( !targets[lp]->is_fighting(player) )
	    targets[lp]->kill_ob(player);
  	}
  }
  
  return eff;
}

//持续治疗（效果分为0-49级，一共50个级别）
int effect_heal(object player, object *targets, string tune, string *effects, int effect_level, int pri_coef, int aux_coef)
{
  int lp, eff, p2;
  string *effect_scope=({"qi", "jing"});
  string *teffs, *deleffs, meff;

  if ( !player || !tune )
  	return 0;
  
  teffs=effects;
  deleffs=({});
  foreach(meff in teffs)
    if ( member_array(meff, effect_scope)<0 )
   	  deleffs+=({meff});
  
  teffs=teffs-deleffs;
  if ( sizeof(teffs)==0 )
  	return 0;
  	
//每次减少气血/精神从5点到2000点范围内浮动  
  if ( pri_coef+aux_coef<= 300 ||
  	   effect_level<0 )
  	eff=5;
  else if ( effect_level<=49 && pri_coef+aux_coef<=2400 )
    eff=(1+effect_level)*(pri_coef+aux_coef)/60;
  else if ( effect_level>49 && pri_coef+aux_coef<=2400 )
  	eff=5*(pri_coef+aux_coef)/6;
  else if ( effect_level<=49 && pri_coef+aux_coef>2400 )
  	eff=40*(1+effect_level);
  else
  	eff=2000;
  
  for( lp=0; lp<sizeof(targets); lp++)
  {
  	if ( !targets[lp] || 
  		   !targets[lp]->is_character() )
  		continue;
  	
  	foreach( meff in teffs) 
  	{
  	  targets[lp]->receive_heal(meff, eff);
  	  if ( effect_level>=20 )
  	  {
  	    targets[lp]->receive_curing(meff, eff/4);
  	    if ( targets[lp]==player )
  	    	tell_object( targets[lp], sprintf(GRN"你受到自己弹奏的乐曲『%s』的影响，恢复了%d点%s，治疗了%d点伤害。\n"NOR, 
    	    subskill_info[tune]["name"], eff, meff=="qi"?"气血":"精神", eff/4 ) );
  	    else
    	    tell_object( targets[lp], sprintf(GRN"你受到%s弹奏的乐曲『%s』的影响，恢复了%d点%s，治疗了%d点伤害。\n"NOR, 
    	      player->name(), subskill_info[tune]["name"], eff, 
  	        meff=="qi"?"气血":"精神", eff/4 ) );
  	  }
  	  else
  	  {
  	  	if ( targets[lp]==player )
  	  	  tell_object( targets[lp], sprintf(GRN"你受到自己弹奏的乐曲『%s』的影响，恢复了%d点%s。\n"NOR, 
    	      subskill_info[tune]["name"], eff, meff=="qi"?"气血":"精神") );
    	  else
    	    tell_object( targets[lp], sprintf(GRN"你受到%s弹奏的乐曲『%s』的影响，恢复了%d点%s。\n"NOR, 
    	      player->name(), subskill_info[tune]["name"], eff, meff=="qi"?"气血":"精神") );
    	}
  	}
  }
  
  return eff;
}

//清除毒素
int effect_detoxify(object player, object *targets, string instrument, string tune)
{
	int lp;
	
  if ( !player || !tune )
  	return 0;
  
  for( lp=0; lp<sizeof(targets); lp++)
  {
  	if ( !targets[lp] || 
  		   !targets[lp]->is_character() )
  		continue;
  	
  	targets[lp]->clear_conditions_by_type("poison");
  	targets[lp]->set_temp("music_status/"+tune+"/effect_detoxify", "免疫中毒");
  	targets[lp]->set_temp("music_status/"+tune+"/id", player->query("id") );
  	targets[lp]->set_temp("music_status/"+tune+"/name", subskill_info[tune]["name"]+"【"+instrument_name[instrument]+"】");
  	if ( targets[lp]==player )
  		tell_object( targets[lp], sprintf(GRN"你受到自己弹奏的乐曲『%s』的影响，消除了体内的毒素。\n"NOR, 
    	    subskill_info[tune]["name"]) );
    else
 	    tell_object( targets[lp], sprintf(GRN"你受到%s弹奏的乐曲『%s』的影响，消除了体内的毒素。\n"NOR, 
    	    player->name(), subskill_info[tune]["name"]) );
  }
  
  return 1;
}

//音乐效果比较
//1表示被作用者之前的音乐效果大于现在演奏者想作用的效果
//0表示相同
//-1表示现在演奏者的效果可以覆盖以前音乐效果
int compare_effect( object player, object target, string tune, int effect_level, int effect_coef)
{
	string playid;
	playid=target->query_temp("music_status/"+tune+"/id");
//同一个演奏者产生的效果不管什么原因都是可以被覆盖掉的
	if ( playid && player->query("id") == playid )
		return -1;

	if ( target->query_temp(tune+"/effect_level")>effect_level ||
  		 ( target->query_temp(tune+"/effect_level")==effect_level &&
  		   target->query_temp(tune+"/effect_coef")>effect_coef ) )
    return 1;
  else if ( target->query_temp(tune+"/effect_level")==effect_level &&
  	        target->query_temp(tune+"/effect_coef")==effect_coef )
  	return 0;
  else
  	return -1;
}

//移除听众的音乐效果
int remove_effect( object player, object target, string tune )
{
	mapping tune_effect;
	string effect;
	if ( !target )
		return 0;
	
	if ( player &&
		   player->query("id") != target->query_temp("music_status/"+tune+"/id") )
		return 0;
	
	tune_effect=target->query_temp(tune);
	if ( !mapp(tune_effect) )
		return 0;
	foreach( effect in keys(tune_effect) )
	{
		if ( effect=="effect_coef" ||
			   effect=="effect_level" )
		  continue;
		
		target->add_temp("apply/"+effect, -tune_effect[effect]);
  	if ( effect=="max_qi" ||
  		   effect=="max_jing" )
  	{
  	  target->set("max_qi", target->query_max_qi());
  	  target->set("max_jing", target->query_max_jing());
  	  if ( target->query("eff_qi")>target->query("max_qi") )
  	  	target->set("eff_qi", target->query("max_qi") );
  	  if ( target->query("eff_jing")>target->query("max_jing") )
  	  	target->set("eff_jing", target->query("max_jing") );
  	}
	}
	target->delete_temp(tune);
	target->delete_temp("music_status/"+tune);
}

//演奏结束，如果是主乐器演奏者，消除听众的状态，伴奏者只需要消除自己的状态
void end_play(object player, object *listeners, string tune, int master)
{
	object listener;
	
	if ( master && arrayp(listeners) && sizeof(listeners)>0 )
  {
    foreach(listener in listeners )
	  {
		  if ( objectp(listener) )
	      remove_effect(player, listener, tune);
	  }
  }
  
	if ( !player )
		return;
	
	player->delete_temp("play_music");
	player->set_temp("play_music/end_time", time());
}

//搜索听众，仅支持mode='TEAM' 同一队伍的，或者mode='ENEMY' 敌人
object *search_listeners(object player, object *listeners, string tune, string mode)
{
	object listener, *team, env, *dellis, *newlis, *inv;
	
	env=environment(player);
	dellis=({});
	team=player->query_team(); 
	if ( arrayp(listeners) && sizeof(listeners)>0 )
	{
		foreach(listener in listeners )
		{
			if ( !listener || 
				   !environment(listener) ||
				   environment(listener)!=env ||
				   !living(listener) ||
				   (!player->visible(listener) &&
				    wizardp(listener) ) )       //对于不可见物件不发生作用（主要是巫师隐身）
			{
			  dellis+=({listener});
//和演奏者不在一个房间的听众消除他的音乐效果			
			  if ( objectp(listener) )
			  {
				  remove_effect(player, listener, tune);
			  }
			}
			
			if ( !arrayp( team ) || 
		       sizeof(team)<2 ||
		       mode=="ENEMY" )
		    continue;
			
			if ( member_array(listener, team)<0 )
			{
			  remove_effect(player, listener, tune);
			  dellis+=({listener});
			}
		}
	}
	
	newlis=({});
	if ( mode=="TEAM" )
	{
		if ( !arrayp( team ) || 
		     sizeof(team)==0 )
		{
			if ( arrayp(listeners) )
				return listeners-dellis;
			else
				return ({});
		}
		
    foreach(listener in team)
    {
  	  if ( !listener || !environment(listener) || !living(listener) )
  		  continue;
  	  if ( environment(listener) != env )
  		  continue;
  		if ( arrayp(listeners) && member_array(listener, listeners)>=0 )
  			continue;
  	  newlis+=({listener});
    }
  }
  else if ( mode=="ENEMY" )
  {
  	inv=all_inventory(env);
  	foreach(listener in inv)
  	{
  		if ( !listener->is_character() || !living(listener) ||
				   (!player->visible(listener) &&
				    wizardp(listener) ) || 
				   (objectp(listener->query("uni_target")) &&
				    listener->query("uni_target")!=player) )     //屏蔽巫师隐身和有唯一作用人的npc
  			continue;
  		if ( listener==player || 
  			   (arrayp(team) && member_array(listener, team)>=0 ) )
  			continue;
  		if ( arrayp(listeners) && member_array(listener, listeners)>=0 )
  			continue;
  		newlis+=({listener});
  	}
  }
  
  if ( arrayp(listeners) )
  	return listeners-dellis+newlis;
  else
  	return newlis;
}

//音乐练习效果函数
void music_practice(object me, string instrument, string music, string skill)
{
	int learn_speed, music_level, mint, learn_exp;
	
	me->add("learned_points", 10 );
	me->add("jing", -20 );
	mint=me->query("int");
	if ( mint< 20 )
		learn_speed=8;
	else if ( mint < 30 )
		learn_speed=10;
	else if ( mint < 35 )
		learn_speed=12;
	else
		learn_speed=14;
	
	music_level=me->query_sub_skill("music::music-theory",1);
	learn_exp=mint*(learn_speed+music_level*3/(160+subskill_info[music]["level"]*20-mint)-subskill_info[music]["level"]*2);
	
	me->improve_skill(skill, learn_exp);
	me->improve_skill("music::"+instrument, learn_exp/2);
	me->improve_skill("music::music-theory", learn_exp/4);
}