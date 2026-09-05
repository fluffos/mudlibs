//梅花三弄
//此曲表现了梅花洁白，傲雪凌霜的高尚品性。
//给敌人加debuff，1级迟缓，持续掉精
#include <ansi.h>
#define MinTuneLevel 300   //演奏该乐曲的最低等级限制
#define SectSpiRed -50     //每演奏完一节的精神消耗
#define SectForceRed -10   //每演奏完一节的内力消耗
#define SectTime 6         //每节持续的时间
#define Sections 10        //该乐曲一共有多少节
#define RestTime 15        //演奏完一首乐曲以后的休息时间
#define MinSpi   200       //最低精神
#define MinForce 200       //最低内力
inherit F_MUSIC;
#include <combat/music.h>

//定义该曲目的伴奏效果
//琴和筝伴奏有正效果，鼓和铜钹伴奏有负效果，其他乐器没有伴奏效果
int query_aux_instrument(string instrument)
{
	if ( instrument=="qin" || 
		   instrument=="zheng" )
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
 	  effect_slow(player, listeners, instrument, tune, 0+aux_level, pri_coef, aux_coef);
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
	({"梅花一弄戏风高，薄袄轻罗自在飘。",
		"半点含羞遮绿叶，三分暗喜映红袍。",
    "梅花二弄迎春曲，瑞雪溶成冰玉肌。",
    "错把落英当有意，红尘一梦笑谁痴。",
    "梅花三弄唤群仙，雾绕云蒸百鸟喧。",
    "蝶舞蜂飞腾异彩，丹心谱写九重天。",
    "空凭遐想笑摘蕊，断回肠，思故里。",
    "漫弹绿绮,引《三弄》，不觉魂飞。",
    "更听胡笳，哀怨泪沾衣。",
    "乱插繁花须异日，待孤讽，怕东风，一夜吹。"});
	
	if ( section>=Sections )
		error("『"+query_tune_name(tune)+"』并没有这么多段音乐，不存在"+chinese_number(section+1)+"节音乐。\n");
	
	return HIW+song[section]+"\n"NOR;
}

//载入公共的对敌人Debuff效果库文件
#include "tune_debuff.h"