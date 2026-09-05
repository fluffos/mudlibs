//十面埋伏
//记有被时人称为“汤琵琶”的汤应曾弹奏《楚汉》时的情景：
//“当其两军决战时，声动天地，瓦屋若飞坠。徐而察之，有金声、鼓声、剑弩声、人马辟易声，俄而无声，
//久之有怨而难明者，为楚歌声；凄而壮者，为项王悲歌慷慨之声、别姬声。陷大泽有追骑声，至乌江有项王自刎声，
//余骑蹂践争项王声。使闻者始而奋，既而恐，终而涕泣之无从也。”
//给敌人加debuff，2级伤害/护甲降低，4级气血/精神恢复速率降低，持续掉气掉精
#include <ansi.h>
#define MinTuneLevel 300   //演奏该乐曲的最低等级限制
#define SectSpiRed -250    //每演奏完一节的精神消耗
#define SectForceRed -40   //每演奏完一节的内力消耗
#define SectTime 6         //每节持续的时间
#define Sections 10        //该乐曲一共有多少节
#define RestTime 30        //演奏完一首乐曲以后的休息时间
#define MinSpi   1000      //最低精神
#define MinForce 1000      //最低内力
inherit F_MUSIC;
#include <combat/music.h>

//定义该曲目的伴奏效果
//琴和筝伴奏有正效果，鼓和铜钹伴奏有负效果，其他乐器没有伴奏效果
int query_aux_instrument(string instrument)
{
	if ( instrument=="drum" || 
		   instrument=="cymbals" )
	  return 1;
	else if ( instrument=="flute" ||
		   instrument=="shaw" )
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
  
  recover_level=9+pri_coef/300+aux_coef/100;
  if ( pri_coef<=1500 && recover_level>14 )
  	recover_level=14;
  else if ( pri_coef>1500 && recover_level>19 )
  	recover_level=19;
  
  if ( !play_mode )
  {
 	  effect_damage(player, listeners, instrument, tune, ({"damage", "armor"}), 1+aux_level, pri_coef, aux_coef, -1);
 	  effect_recover(player, listeners, instrument, tune, ({"qi_recover","jing_recover"}), 3+aux_level, pri_coef, aux_coef, -1);
 	  effect_wound(player, listeners, tune, ({"qi","jing"}), recover_level, pri_coef, aux_coef);
  }
  else
  {
 	  effect_wound(player, listeners, tune, ({"qi","jing"}), recover_level, pri_coef, aux_coef);
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
	({"「列营」",
    "「吹打」",
    "「点将」",
    "「排阵」",
    "「走队」",
    "「埋伏」",
    "「鸡鸣山小战」",
    "「九里山大战」",
    "「项王败阵」",
    "「乌江自刎」"});
	
	if ( section>=Sections )
		error("『"+query_tune_name(tune)+"』并没有这么多段音乐，不存在"+chinese_number(section+1)+"节音乐。\n");
	
	return MAG"$N弹完了『"WHT+query_tune_name(tune)+MAG"』的第"+chinese_number(section+1)+"乐段"HIM+song[section]+MAG"。\n"NOR;
}

//载入公共的对敌人Debuff效果库文件
#include "tune_debuff.h"