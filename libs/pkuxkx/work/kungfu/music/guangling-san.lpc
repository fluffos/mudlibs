//广陵散
//广陵散贯注一种愤慨不屈的浩然之气，“纷披灿烂，戈矛纵横”
//给敌人加debuff，3级攻击命中降低，3级膂力/身法天赋降低，持续掉气掉精
#include <ansi.h>
#define MinTuneLevel 300   //演奏该乐曲的最低等级限制
#define SectSpiRed -200    //每演奏完一节的精神消耗
#define SectForceRed -30   //每演奏完一节的内力消耗
#define SectTime 4         //每节持续的时间
#define Sections 45        //该乐曲一共有多少节
#define RestTime 20        //演奏完一首乐曲以后的休息时间
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
  
  recover_level=4+pri_coef/300+aux_coef/100;
  if ( pri_coef<=1500 && recover_level>9 )
  	recover_level=9;
  else if ( pri_coef>1500 && recover_level>14 )
  	recover_level=14;
  
  if ( !play_mode )
  {
 	  effect_skill(player, listeners, instrument, tune, ({"attack", "defense"}), 2+aux_level, pri_coef, aux_coef, -1);
 	  effect_attribute(player, listeners, instrument, tune, ({"strength", "dexerity"}), 2+aux_level, pri_coef, aux_coef, -1);
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
	({"「开指」",
    "「小序」止息第一",
    "「小序」止息第二",
    "「小序」止息第三",
    "「大序」井里",
    "「大序」申诚",
    "「大序」顺物",
    "「大序」因时",
    "「大序」干时",
    "「正声」取韩",
    "「正声」呼幽",
    "「正声」亡身",
    "「正声」作气",
    "「正声」含志",
    "「正声」沉思",
    "「正声」返魂",
    "「正声」狥物",
    "「正声」冲冠",
    "「正声」长虹",
    "「正声」寒风",
    "「正声」发怒",
    "「正声」烈妇",
    "「正声」收义",
    "「正声」扬名",
    "「正声」含光",
    "「正声」沉名",
    "「正声」投剑",
    "「乱声」峻迹",
    "「乱声」守质",
    "「乱声」归政",
    "「乱声」仇毕",
    "「乱声」终思",
    "「乱声」同志",
    "「乱声」用事",
    "「乱声」辞卿",
    "「乱声」气衔",
    "「乱声」微行",
    "「后序」会止息意",
    "「后序」意绝",
    "「后序」悲志",
    "「后序」叹息",
    "「后序」长吁",
    "「后序」伤感",
    "「后序」恨愤",
    "「后序」亡计",});
	
	if ( section>=Sections )
		error("『"+query_tune_name(tune)+"』并没有这么多段音乐，不存在"+chinese_number(section+1)+"节音乐。\n");
	
	return RED"$N弹完了『"WHT+query_tune_name(tune)+RED"』的第"+chinese_number(section+1)+"乐段"HIR+song[section]+RED"。\n"NOR;
}

//载入公共的对敌人Debuff效果库文件
#include "tune_debuff.h"