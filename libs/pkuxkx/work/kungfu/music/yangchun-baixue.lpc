//阳春白雪
//此曲的意境是万物生机，春意盎然的景象。
//组队技，给队友加buff，3级气血/精神恢复buff，1级气血/精神治疗buff，持续恢复气血/精神
#include <ansi.h>
#define MinTuneLevel 100   //演奏该乐曲的最低等级限制
#define SectSpiRed -100    //每演奏完一节的精神消耗
#define SectForceRed -20   //每演奏完一节的内力消耗
#define SectTime 8         //每节持续的时间
#define Sections 7         //该乐曲一共有多少节
#define RestTime 15        //演奏完一首乐曲以后的休息时间
#define MinSpi   200       //最低精神
#define MinForce 200       //最低内力
inherit F_MUSIC;
#include <combat/music.h>

//定义该曲目的伴奏效果
//笛和箫伴奏有正效果，鼓和铜钹伴奏有负效果，其他乐器没有伴奏效果
int query_aux_instrument(string instrument)
{
	if ( instrument=="flute" || 
		   instrument=="shaw" )
	  return 1;
	else if ( instrument=="drum" ||
		   instrument=="cymbals" )
		return -1;
  else 
  	return 0;
}

//演奏效果函数，play_mode分为两种模式，play_mode=0是所有效果重置，play_mode=1是仅瞬间生效技能生效
void play_effect(object player, object *listeners, string instrument, string tune, int pri_coef, int aux_coef, int play_mode)
{
	int aux_level, recover_level;
	
  if ( aux_coef>=300 )
    aux_level=1;
  else if ( aux_coef<=-300 )
  	aux_level=-1;
  else
  	aux_level=0;
  
  recover_level=1+pri_coef/500+aux_coef/100;
  if ( pri_coef<=1500 && recover_level>4 )
  	recover_level=4;
  else if ( pri_coef>1500 && recover_level>6 )
  	recover_level=6;
  
  if ( !play_mode )
  {
 	  effect_recover(player, listeners, instrument, tune, ({"qi_recover","jing_recover"}), 2+aux_level, pri_coef, aux_coef, 1);
 	  effect_recover(player, listeners, instrument, tune, ({"qi_cure","jing_cure"}), 0+aux_level, pri_coef, aux_coef, 1);
 	  effect_heal(player, listeners-({player}), tune, ({"qi", "jing"}), recover_level, pri_coef, aux_coef);
 	  effect_heal(player, ({player}), tune, ({"qi", "jing"}), recover_level+3, pri_coef, aux_coef);
  }
  else
  {
 	  effect_heal(player, listeners-({player}), tune, ({"qi", "jing"}), recover_level, pri_coef, aux_coef);
 	  effect_heal(player, ({player}), tune, ({"qi", "jing"}), recover_level+3, pri_coef, aux_coef);
  }
}

//返回乐曲的名称
string query_tune_name(string tune)
{
	return subskill_info[tune]["name"];
}

//返回乐曲中某一节的内容，调用的时候使用message_vision函数发送内容
string query_tune(string tune, int section)
{
	string *song=
	({"独占鳌头",
		"风摆荷花",
		"一轮明月",
		"玉版参禅",
		"铁策板声",
		"道院琴声",
		"东皋鹤鸣"});
	
	if ( section>=Sections )
		error("『"+query_tune_name(tune)+"』并没有这么多段音乐，不存在"+chinese_number(section+1)+"节音乐。\n");
	
	return HIC"$N弹完了『"HIW+query_tune_name(tune)+HIC"』的第"+chinese_number(section+1)+"乐段《"GRN+song[section]+HIC"》。\n"NOR;
}

//载入公共的对队友Buffer效果库文件
#include "tune_teambuff.h"