//李清照的浣溪沙·春景
//小院闲窗春已深，重帘未卷影沉沉，倚楼无语理瑶琴。远岫出山催薄暮，细风吹雨弄轻阴，梨花欲谢恐难禁。
#include <ansi.h>
#define MinTuneLevel 300   //演奏该乐曲的最低等级限制
#define SectSpiRed -200    //每演奏完一节的精神消耗
#define SectForceRed -30   //每演奏完一节的内力消耗
#define SectTime 30        //每节持续的时间
#define Sections 6         //该乐曲一共有多少节
#define RestTime 15        //演奏完一首乐曲以后的休息时间
#define MinSpi   1000      //最低精神
#define MinForce 1000      //最低内力
inherit F_MUSIC;
#include <combat/music.h>

//定义该曲目的伴奏效果
//琵琶和箫伴奏有正效果，鼓和铜钹伴奏有负效果，其他乐器没有伴奏效果
int query_aux_instrument(string instrument)
{
	if ( instrument=="pipa" || 
		   instrument=="flute" )
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
	int music_level;
	
  music_level=1+pri_coef/600+aux_coef/250;
  if ( music_level>5 )
  	music_level=5;
  
  if ( !play_mode )
  {
 	  effect_mark(player, listeners, instrument, tune, ({"VeinThroughEnhance"}), ({"降低通脉走火几率"}), music_level, pri_coef, aux_coef);
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
	({"小院闲窗春已深，",
	  "重帘未卷影沉沉，",
	  "倚楼无语理瑶琴。",
	  "远岫出山催薄暮，",
	  "细风吹雨弄轻阴，",
	  "梨花欲谢恐难禁。"});
	
	return HIC+song[random(sizeof(song))]+"\n"NOR;
}

//载入公共的对队友Buffer效果库文件
#include "tune_teambuff.h"