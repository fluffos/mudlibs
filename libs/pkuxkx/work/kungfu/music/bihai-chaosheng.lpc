//碧海潮生曲
//它模拟大海浩淼，万里无波，远处潮水缓缓推近，渐近渐快，其后洪涛汹涌，白浪连山，而潮水中鱼跃鲸浮，
//海面上风啸鸥飞，再加上飘至，忽而海如沸，极尽变幻之能事，而潮退后水平如镜，海底却又是暗流湍急，
//于无声处隐伏凶险。
//给敌人加debuff，3级迟钝，5级紊乱（主系数超过1000），持续掉精
#include <ansi.h>
#define MinTuneLevel 200   //演奏该乐曲的最低等级限制
#define SectSpiRed -200    //每演奏完一节的精神消耗
#define SectForceRed -100  //每演奏完一节的内力消耗
#define SectTime 5         //每节持续的时间
#define Sections 29        //该乐曲一共有多少节
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
	  return -1;
	else if ( instrument=="qin" ||
		   instrument=="zheng" )
		return 1;
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
  
  recover_level=3+pri_coef/500+aux_coef/100;
  if ( pri_coef<=1500 && recover_level>7 )
  	recover_level=7;
  else if ( pri_coef>1500 && recover_level>9 )
  	recover_level=9;
  
  if ( !play_mode )
  {
  	effect_slow(player, listeners, instrument, tune, pri_coef/1000+aux_level, pri_coef, aux_coef);
 	  if ( pri_coef>=1000 && pri_coef<2000 )
 	    effect_disorder(player, listeners, instrument, tune, 4+aux_level, pri_coef, aux_coef);
 	  else if ( pri_coef>=2000 )
 	  	effect_disorder(player, listeners, instrument, tune, 9+aux_level, pri_coef, aux_coef);
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
	({"尘寰外，碧海中，桃花之间桃花岛。",
    "秋风起，海波兴，几度潮来听玉箫。",
    "箫声起处落英飞，遽引心情向碧霄。",
    "桃花纷飞诉往事，风中烟柳叶飘摇。",
    "相逢本是瑶池间，盈盈花开芙蓉仙。",
    "芙蓉仙子织涟漪，油壁香车待鲜妍。",
    "蓬莱三山固所道，亦羡人间好情缘。",
    "从此千里不独行，侠义江湖同仗剑。",
    "未必女流让须眉，兰心蕙质更比肩。",
    "博闻强记天下事，九阴真经只等闲。",
    "九阴又何贵? 九阴竟使君命违。",
    "明日峰前再论剑，相伴华山知者谁？",
    "由来文字与武功，未如心意双高飞。",
    "十年不得慕红颜，敢笑唐皇与杨妃。",
    "梦时抚琴商转徵，丁香愁肠枉自悲。",
    "梧桐故事漫嗟呀，细把云烟裁作纱。",
    "一处杜鹃悄无语，一处萧萧半白发。",
    "七月七日梦天桥，闻道君思寄桃花？",
    "若无鸿雁奉鱼书，还叫无常带句话。",
    "我于浊世间，君在黄泉下，",
    "相忆相依两无期，相思何事纪年华! ",
    "碧海潮起天地惊，碧海潮落鬼神泣。",
    "碧海桃花之精英，凝于碧海潮生曲。",
    "此曲一出奋鹰扬，能使妖魔胆尽丧。",
    "弹指一挥风波起，太虚蹑后步天罡。",
    "再吟此曲凋日月，纷纷四海大浪张。",
    "世人未谙碧海意，尽道此潮最泱泱。",
    "不知潮起潮落间，碧海一曲为君飨。",
    "桃花飞殇哀往事，曲尽碧海尚彷徨。"});
	
	if ( section>=Sections )
		error("『"+query_tune_name(tune)+"』并没有这么多段音乐，不存在"+chinese_number(section+1)+"节音乐。\n");
	
	return HIC+song[section]+"\n"NOR;
}

//载入公共的对敌人Debuff效果库文件
#include "tune_debuff.h"