//汉宫秋月
//此曲表达了古代宫女哀怨悲愁的情绪及一种无可奈何、寂寥清冷的生命意境。
//杜甫的《咏怀古迹》描写王昭君和整个曲子比较相合，这里就作为这首曲子的
//歌词。
//效果：给敌人加debuff，1级恢复debuff，持续掉精
#include <ansi.h>
#define MinTuneLevel 200   //演奏该乐曲的最低等级限制
#define SectSpiRed -50     //每演奏完一节的精神消耗
#define SectForceRed -10   //每演奏完一节的内力消耗
#define SectTime 5         //每节持续的时间
#define Sections 8         //该乐曲一共有多少节
#define RestTime 10        //演奏完一首乐曲以后的休息时间
#define MinSpi   200       //最低精神
#define MinForce 200       //最低内力
inherit F_MUSIC;
#include <combat/music.h>

//定义该曲目的伴奏效果
//琴和箫伴奏有正效果，鼓和铜钹伴奏有负效果，其他乐器没有伴奏效果
int query_aux_instrument(string instrument)
{
	if ( instrument=="qin" || 
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
	object listener;
	int aux_level, recover_level;
	
  if ( aux_coef>=300 )
    aux_level=1;
  else if ( aux_coef<=-300 )
  	aux_level=-1;
  else
  	aux_level=0;
  
  recover_level=2+pri_coef/500+aux_coef/150;
  if ( pri_coef<=1500 && recover_level>7 )
  	recover_level=7;
  else if ( pri_coef>1500 && recover_level>10 )
  	recover_level=10;
  
  if ( !play_mode )
  {
 	  effect_recover(player, listeners, instrument, tune, ({"qi_recover","jing_recover","neili_recover"}), 0+aux_level, pri_coef, aux_coef, -1);
 	  effect_wound(player, listeners, tune, ({"jing"}), recover_level, pri_coef, aux_coef);
  }
  else
  {
 	  effect_wound(player, listeners, tune, ({"jing"}), recover_level, pri_coef, aux_coef);
  }
  
  foreach(listener in listeners)
    if ( objectp(listener) && !listener->is_fighting(player) )
      listener->kill_ob(player);
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
	({"群山万壑赴荆门，",
    "生长明妃尚有村。",
    "一去紫台连朔漠，",
    "独留青冢向黄昏。",
    "画图省识春风面，",
    "环佩空归月夜魂。",
    "千载琵琶作胡语，",
    "分明怨恨曲中论。"});
	
	if ( section>=Sections )
		error("『"+query_tune_name(tune)+"』并没有这么多段音乐，不存在"+chinese_number(section+1)+"节音乐。\n");
	
	return HIC+song[section]+"\n"NOR;
}

//载入公共的对敌人Debuff效果库文件
#include "tune_debuff.h"