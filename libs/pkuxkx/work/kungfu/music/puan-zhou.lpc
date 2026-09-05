//普庵咒
//此咒可普安十方、驱除虫蚁、蚊蚋不生、消灾解厄、镇煞安胎、驱邪除秽、逢凶化吉。
//组队技，给队友加buff，去除负面效果（中毒）、恢复气血精神（不超过36级）
#include <ansi.h>
#define MinTuneLevel 300   //演奏该乐曲的最低等级限制
#define SectSpiRed -200    //每演奏完一节的精神消耗
#define SectForceRed -100  //每演奏完一节的内力消耗
#define SectTime 5         //每节持续的时间
#define Sections 25        //该乐曲一共有多少节
#define RestTime 25        //演奏完一首乐曲以后的休息时间
#define MinSpi   1000      //最低精神
#define MinForce 1000      //最低内力
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
	int recover_level;
  
  recover_level=10+pri_coef/100+aux_coef/50;
  if ( pri_coef<=1500 && recover_level>25 )
  	recover_level=25;
  else if ( pri_coef>1500 && recover_level>35 )
  	recover_level=35;
  
  if ( !play_mode )
  {
 	  effect_detoxify(player, listeners, instrument, tune);
 	  effect_heal(player, listeners, tune, ({"qi", "jing"}), recover_level, pri_coef, aux_coef);
  }
  else
  {
 	  effect_heal(player, listeners, tune, ({"qi", "jing"}), recover_level, pri_coef, aux_coef);
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
	({"南无佛驮耶.南无达摩耶.南无僧伽耶.南无本师释迦牟尼佛.南无大悲观世",
    "南无普庵祖师菩萨.南无百万火首金刚王菩萨",
    "唵 迦迦迦研界.遮遮遮神惹.吒吒吒怛那.多多多檀那.波波波梵摩.",
    "摩梵波波波.那檀多多多.那怛吒吒吒.惹神遮遮遮 界研迦迦迦.迦迦迦研界",
    "迦迦鸡鸡俱俱鸡.俱鸡俱.兼乔鸡.乔鸡兼. 界研迦迦迦.迦迦迦研界",
    "遮遮支支朱朱支.朱支朱.占昭支.昭支占. 惹神遮遮遮.遮遮遮神惹",
    "吒吒知知都都知.都知都.担多知.多知担. 那怛吒吒吒.吒吒吒怛那",
    "多多谛谛多多谛.多谛多.谈多谛.多谛谈. 那檀多多多.多多多檀那",
    "波波悲悲波波悲.波悲波.梵波悲.波悲梵. 摩梵波波波.波波波梵摩",
    "摩梵波波波.那檀多多多.那怛吒吒吒.惹神遮遮遮 界研迦迦迦.迦迦迦研界",
    "迦迦鸡鸡俱俱鸡乔兼.兼兼兼兼兼.验尧倪.尧倪验 界研迦迦迦.迦迦迦研界",
    "遮遮支支朱朱支昭占.占占占占占.验尧倪.尧倪验 惹神遮遮遮.遮遮遮神惹",
    "吒吒知知都都知多担.担担担担担.喃那呢.那呢喃 那怛吒吒吒.吒吒吒怛那",
    "多多谛谛多多谛多谈.谈谈谈谈谈.喃那呢.那呢喃 那檀多多多.多多多檀那",
    "波波悲悲波波悲波梵.梵梵梵梵梵.梵摩迷.摩迷梵 摩梵波波波.波波波梵摩",
    "摩梵波波波.那檀多多多.那怛吒吒吒.惹神遮遮遮 界研迦迦迦.迦迦迦研界",
    "迦迦鸡鸡俱俱耶.喻喻喻喻喻喻喻喻喻. 界研迦迦迦.迦迦迦研界",
    "遮遮支支朱朱耶.喻喻喻喻喻喻喻喻喻. 惹神遮遮遮.遮遮遮神惹",
    "吒吒知知都都耶.奴奴奴奴奴奴奴奴奴. 那怛吒吒吒.吒吒吒怛那",
    "多多谛谛多多耶.奴奴奴奴奴奴奴奴奴. 那檀多多多.多多多檀那",
    "波波悲悲波波耶.母母母母母母母母母. 摩梵波波波.波波波梵摩",
    "摩梵波波波.那檀多多多.那怛吒吒吒.惹神遮遮遮 界研迦迦迦.迦迦迦研界",
    "唵 波多咤 遮迦耶 夜兰阿 阿瑟咤 萨海咤 呼嚧呼嚧咤 遮迦耶 娑婆诃",
    "无数天龙八部 百万火首金刚 咋日方隅 今朝佛地 普庵到此 百无禁忌",
    "南无普庵祖师菩萨摩诃萨　摩诃般若波罗蜜"});
	
	if ( section>=Sections )
		error("『"+query_tune_name(tune)+"』并没有这么多段音乐，不存在"+chinese_number(section+1)+"节音乐。\n");
	
	return HIY+song[section]+"\n"NOR;
}

//载入公共的对队友Buffer效果库文件
#include "tune_teambuff.h"