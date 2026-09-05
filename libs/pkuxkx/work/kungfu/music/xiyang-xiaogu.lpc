//夕阳箫鼓
//它宛如一幅山水画卷，把春天静谧的夜晚，月亮在东山升起，小舟在江面荡漾，花影在西岸轻轻摇曳的大自然迷人景色，一幕幕地展现在我们眼前。
//组队技，给队友加buff，4级气血/精神恢复buff，2级膂力、身法天赋，持续恢复气血/精神
#include <ansi.h>
#define MinTuneLevel 300   //演奏该乐曲的最低等级限制
#define SectSpiRed -100    //每演奏完一节的精神消耗
#define SectForceRed -25   //每演奏完一节的内力消耗
#define SectTime 4         //每节持续的时间
#define Sections 27        //该乐曲一共有多少节
#define RestTime 12        //演奏完一首乐曲以后的休息时间
#define MinSpi   500       //最低精神
#define MinForce 500       //最低内力
inherit F_MUSIC;
#include <combat/music.h>

//定义该曲目的伴奏效果
//鼓和箫伴奏有正效果，无负效果乐器，其他乐器没有伴奏效果
int query_aux_instrument(string instrument)
{
	if ( instrument=="drum" || 
		   instrument=="shaw" )
	  return 1;
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
  
  recover_level=3+pri_coef/600+aux_coef/150;
  if ( pri_coef<=1800 && recover_level>4 )
  	recover_level=6;
  else if ( pri_coef>1800 && recover_level>6 )
  	recover_level=8;
  
  if ( !play_mode )
  {
 	  effect_recover(player, listeners, instrument, tune, ({"qi_recover","jing_recover"}), 4+aux_level, pri_coef, aux_coef, 1);
 	  effect_attribute(player, listeners, instrument, tune, ({"strength","dexerity"}), 1+aux_level, pri_coef, aux_coef, 1);
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
	return "春江花月夜";
}

//返回乐曲中某一节的内容，调用的时候使用message_vision函数发送内容
string query_tune(string tune, int section)
{
	string *song=
	({"春江潮水连海平，海上明月共潮生。",
    "滟滟随波千万里，何处春江无月明。",
		"《江楼钟鼓》，\n表现夕阳映江面，熏风拂涟漪的景色",
		"江流宛转绕芳甸，月照花林皆似霰。",
    "空里流霜不觉飞，汀上白沙看不见。",
		"《月上东山》",
		"江天一色无纤尘，皎皎空中孤月轮。",
    "江畔何人初见月，江月何年初照人？",
		"《风回曲水》",
		"人生代代无穷已，江月年年只相似。",
    "不知江月待何人，但见长江送流水。",
		"《花影层叠》，\n如见江风习习，花草摇曳，水中倒影，层迭恍惚",
    "白云一片去悠悠，青枫浦上不胜愁。",
    "谁家今夜扁舟子，何处相思明月楼？",
		"《水深云际》，\n表现\"江天一色无纤尘，皎皎空中孤月轮\"的壮阔景色",
    "可怜楼上月徘徊，应照离人妆镜台。",
    "玉户帘中卷不去，捣衣砧上拂还来。",
		"《渔歌唱晚》，\n表现白帆点点，遥闻渔歌，由远而近，逐歌四起的画面",
    "此时相望不相闻，愿逐月华流照君。",
    "鸿雁长飞光不度，鱼龙潜跃水成文。",
		"《回澜拍岸》，\n表现渔舟破水，掀起波涛拍岸的动态",
    "昨夜闲潭梦落花，可怜春半不还家。",
    "江水流春去欲尽，江潭落月复西斜。",
		"《桡鸣远漱》",
    "斜月沉沉藏海雾，碣石潇湘无限路。",
    "不知乘月几人归，落月摇情满江树。",
		"《欸乃归舟》，\n表现归舟破水，浪花飞溅，橹声\"欸乃\"，由远而近的意境，接着轻舟在远处的江面渐渐消失，春江的夜空幽静而安详。"});
	
	if ( section>=Sections )
		error("『"+query_tune_name(tune)+"』并没有这么多段音乐，不存在"+chinese_number(section+1)+"节音乐。\n");
	
	if ( !((section+1)%3) )
	  return GRN"$N弹完了『"WHT+query_tune_name(tune)+GRN"』的第"+chinese_number((section+1)/3)+"乐段"HIG+song[section]+"。\n"NOR;
	else
		return HIG+song[section]+"\n"NOR;
}

//载入公共的对队友Buffer效果库文件
#include "tune_teambuff.h"