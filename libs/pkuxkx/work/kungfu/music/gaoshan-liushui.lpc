//高山流水
//此曲的意境是雄伟而庄重，好像高耸入云的泰山一样；宽广浩荡，好像看见滚滚的流水，无边的大海一般。
//组队技，给队友加buff，1级命中buff，持续恢复气血/精神
#include <ansi.h>
#define MinTuneLevel 100   //演奏该乐曲的最低等级限制
#define SectSpiRed -50     //每演奏完一节的精神消耗
#define SectForceRed -10   //每演奏完一节的内力消耗
#define SectTime 5         //每节持续的时间
#define Sections 12        //该乐曲一共有多少节
#define RestTime 15        //演奏完一首乐曲以后的休息时间
#define MinSpi   200       //最低精神
#define MinForce 200       //最低内力
inherit F_MUSIC;
#include <combat/music.h>

//定义该曲目的伴奏效果
//琵琶和箫伴奏有正效果，鼓和铜钹伴奏有负效果，其他乐器没有伴奏效果
int query_aux_instrument(string instrument)
{
	if ( instrument=="pipa" || 
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
  
  recover_level=4+pri_coef/500+aux_coef/100;
  if ( pri_coef<=1500 && recover_level>7 )
  	recover_level=7;
  else if ( pri_coef>1500 && recover_level>10 )
  	recover_level=10;
  
  if ( !play_mode )
  {
 	  effect_skill(player, listeners, instrument, tune, ({"defense","attack"}), 0+aux_level, pri_coef, aux_coef, 1);
 	  effect_heal(player, ({player}), tune, ({"qi", "jing"}), recover_level, pri_coef, aux_coef);
  }
  else
  {
    effect_heal(player, ({player}), tune, ({"qi", "jing"}), recover_level, pri_coef, aux_coef);
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
	({"高山之巅，云雾缭绕，飘忽无定。",
		"淙淙铮铮，幽间之寒流；清清冷冷，松根之细流。",
		"行云流水一般的扬扬悠悠。",
		"极腾沸澎湃之观，具蛟龙怒吼之象。息心静听，宛然坐危舟过巫峡，目眩神移，惊心动魄，几疑此身已在群山奔赴，万壑争流之际矣。",
		"轻舟已过，势就倘佯，时而余波激石，时而旋洑微沤",
		"巍巍乎若泰山",
		"洋洋乎若江河",
		"水滴石般的柔和清脆"});
	
	return HIC"大家听着感觉旋律好像『"+song[random(sizeof(song))]+"』\n"NOR;
}

//载入公共的对队友Buffer效果库文件
#include "tune_teambuff.h"