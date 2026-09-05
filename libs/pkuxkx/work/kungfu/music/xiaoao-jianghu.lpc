//笑傲江湖曲
//琴箫合奏组队技
//箫曲为buff类效果，琴曲为debuff类效果
#include <ansi.h>
#define MinTuneLevel 300   //演奏该乐曲的最低等级限制
#define SectSpiRed -150    //每演奏完一节的精神消耗
#define SectForceRed -40   //每演奏完一节的内力消耗
#define SectTime 4         //每节持续的时间
#define Sections 25        //该乐曲一共有多少节
#define RestTime 20        //演奏完一首乐曲以后的休息时间
#define MinSpi   500       //最低精神
#define MinForce 500       //最低内力
inherit F_MUSIC;
#include <combat/music.h>

//定义该曲目的伴奏效果
//筝和笛伴奏有正效果，鼓和钹伴奏有负效果，其他无效果
int query_aux_instrument(string instrument)
{
	if ( instrument=="flute" || 
		   instrument=="zheng" )
	  return 1;
  else if ( instrument=="drum" || 
		        instrument=="cymbals" )
	  return -1;
	else
  	return 0;
}

//获得主乐器的效果种类（buff/debuff）
string query_effect(string instrument)
{
  if ( instrument=="qin" )
    return "debuff";
  else if ( instrument=="shaw" )
    return "buff";
  else
    error("错误的乐器种类，笑傲江湖曲仅支持琴和箫两种主乐器。\n");
}

//演奏效果函数，play_mode分为几种模式，
//0--独奏模式所有效果重置
//1--独奏模式瞬间生效技能
//2--合奏模式所有效果重置
//3--合奏模式瞬间生效技能
void play_effect(object player, object *listeners, string instrument, string tune, int pri_coef, int aux_coef, int play_mode)
{
	int aux_level, ens_mode, pri_level;
	
  if ( aux_coef>=300 )
    aux_level=1;
  else if ( aux_coef<=-300 )
  	aux_level=-1;
  else
  	aux_level=0;
  
  if ( play_mode>=2 )
  {
    ens_mode=1;
    play_mode-=2;
  }
  else
    ens_mode=0;
  
  pri_level=pri_coef/300+aux_coef/100;
  if ( !ens_mode )
  {
    if ( pri_coef<=1800 && pri_level>7 )
  	  pri_level=7;
    else if ( pri_coef>1800 && pri_level>10 )
  	  pri_level=10;
  }
  else
  {
    if ( pri_coef<=2400 && pri_level>10 )
  	  pri_level=10;
    else if ( pri_coef>2400 && pri_level>15 )
  	  pri_level=15;
  }
  
  if ( !play_mode )
  {
    if ( instrument=="shaw" )
    {
      effect_damage(player, listeners, instrument, tune, ({"damage"}), 5+ens_mode*2+aux_level, pri_coef, aux_coef, 1);
      effect_attribute(player, listeners, instrument, tune, ({"strength", "dexerity"}), 5+ens_mode*2+aux_level, pri_coef, aux_coef, 1);
      effect_sunder(player, listeners, instrument, tune, 3+ens_mode*2, pri_coef, aux_coef, 1);
 	    effect_heal(player, ({player}), tune, ({"qi", "jing"}), 3+ens_mode*2+pri_level*2, pri_coef, aux_coef);
 	  }
 	  if ( instrument=="qin" )
 	  {
 	    effect_slow(player, listeners, instrument, tune, 2+ens_mode, pri_coef, aux_coef);
 	    effect_sunder(player, listeners, instrument, tune, 5+ens_mode*2, pri_coef, aux_coef, -1);
 	    effect_wound(player, listeners, tune, ({"qi", "jing"}), 4*(1+ens_mode)+pri_level*3, pri_coef, aux_coef);
 	    effect_damage(player, listeners, instrument, tune, ({"damage"}), 5+ens_mode*2+aux_level, pri_coef, aux_coef, -1);
 	  }
  }
  else
  {
    if ( instrument=="shaw" )
 	    effect_heal(player, ({player}), tune, ({"qi", "jing"}), 3+ens_mode*2+pri_level*2, pri_coef, aux_coef);
 	  if ( instrument=="qin" )
 	    effect_wound(player, listeners, tune, ({"qi", "jing"}), 4*(1+ens_mode)+pri_level*3, pri_coef, aux_coef);
  }
}

//返回乐曲的名称
string query_tune_name(string tune)
{
	return subskill_info[tune]["name"];
}

//返回乐曲中某一节的内容，调用的时候使用message_vision函数发送内容
//mode=0表示独奏
//mode=1表示合奏
string query_tune(string instrument, string tune, int section, int mode)
{
	string *song=
	({"沧海一声笑",
    "滔滔两岸潮",
    "浮沉随浪只记今朝",
    "苍天笑",
    "纷纷世上潮",
    "谁负谁胜出天知晓",
    "江山笑",
    "烟雨遥",
    "涛浪淘尽红尘俗事几多骄",
    "清风笑",
    "竟惹寂寥",
    "豪情还剩了",
    "一襟晚照",
    "沧海一声笑",
    "滔滔两岸潮",
    "浮沉随浪只记今朝",
    "苍天笑",
    "纷纷世上潮",
    "谁负谁胜出天知晓",
    "江山笑",
    "烟雨遥",
    "涛浪淘尽红尘俗事几多骄",
    "苍生笑",
    "不再寂寥",
    "豪情仍在痴痴笑笑"});
	if ( section>=Sections )
		error("『"+query_tune_name(tune)+"』并没有这么多段音乐，不存在"+chinese_number(section+1)+"节音乐。\n");
	
  return HIY+song[section]+"\n"NOR;
}

//载入公共的合奏混合曲目效果库文件
#include "tune_ensemblemixed.h"