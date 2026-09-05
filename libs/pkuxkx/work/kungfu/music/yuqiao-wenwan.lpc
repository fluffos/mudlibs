//渔樵问答
//此曲反映的是一种隐逸之士对渔樵生活的向往，希望摆脱俗尘凡事的羁绊。
//歌词采用了《重修真传》中的歌词，因为只有他标注的歌词是采用问答形式
//琴箫合奏组队技，给队友加buff，最大气血/精神6级，身法天赋4级，伤害/护甲5级，演奏者自身气血/精神恢复
#include <ansi.h>
#define MinTuneLevel 300   //演奏该乐曲的最低等级限制
#define SectSpiRed -150    //每演奏完一节的精神消耗
#define SectForceRed -40   //每演奏完一节的内力消耗
#define SectTime 6         //每节持续的时间
#define Sections 11        //该乐曲一共有多少节
#define RestTime 15        //演奏完一首乐曲以后的休息时间
#define MinSpi   500       //最低精神
#define MinForce 500       //最低内力
inherit F_MUSIC;
#include <combat/music.h>

//定义该曲目的伴奏效果
//鼓和箫伴奏有正效果，无负效果乐器，其他乐器没有伴奏效果
int query_aux_instrument(string instrument)
{
	if ( instrument=="flute" || 
		   instrument=="zheng" )
	  return 1;
  else if ( instrument=="drum" || 
		        instrument=="cymbals" )
	  return -1;
	else
  	return 0;
}

//演奏效果函数，play_mode分为几种模式，
//play_mode=0是所有效果重置（合奏模式下这个演奏模式不存在）
//play_mode=1是仅瞬间生效技能生效
//play_mode=2是合奏模式效果重置
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
  	recover_level=7;
  else if ( pri_coef>1800 && recover_level>6 )
  	recover_level=10;
  
  if ( play_mode==2 )
  {
 	  effect_hp(player, listeners, instrument, tune, ({"max_qi", "max_jing"}), 5+aux_level, pri_coef, aux_coef);
 	  effect_attribute(player, listeners, instrument, tune, ({"dexerity"}), 3+aux_level, pri_coef, aux_coef, 1);
 	  effect_damage(player, listeners, instrument, tune, ({"damage", "armor"}), 4+aux_level, pri_coef, aux_coef, 1);
 	  effect_heal(player, ({player}), tune, ({"qi", "jing"}), recover_level, pri_coef, aux_coef);
  }
  else if ( play_mode==1 )
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
//对于合奏曲，接口增加mode输入参数
//这里mode=0表示主演奏者曲目
//    mode=1表示副演奏者曲目
string query_tune(string tune, int section, int mode)
{
	string *song1=
	({"渔问樵曰，子何求。",
    "渔又诘之曰，草木逢春，生意不然不可遏，伐之为薪，生长莫达。",
    "...",
    "渔乃笑曰，因木欲财，心多嗜欲，因财发身，心必恒辱。",
    "...",
    "...",
	  "渔顾而答曰，一竿一钓一扁舟，五湖四海，任我自在遨游。得鱼贯柳而归，乐觥筹。",    
	  "渔又曰，不专取利抛纶饵，惟爱江山风景清。",
	  "渔乃喜曰，吕望常年渭水滨，丝纶半卷海霞清。有朝得遇文王日，载上安车赍阙京。嘉言傥论为时法，大展鹰扬致太平。",
	  "...",
	  "渔乃喜曰，不惟萃老溪山，还期异日得志见龙颜。投却云峰烟水业，大旱施霖雨，巨川行舟楫，衣锦而还。叹人生能有几何。"
    });
  string *song2=
  ({"樵答渔曰，数椽茅屋，绿树青山，时出时还。生涯不在西方，斧斤丁丁，云中之峦。",
  	"樵又答之曰，木能生火，火能熟物，火与木，天下古今谁没。",
  	"况山木之为性也，当生当牿，伐之而后更夭乔，取之而后枝叶愈足。",
	  "樵曰，昔日朱买臣未遇富贵时，携书挟卷，登山落径行读之。一旦高车驷马驱驰，刍荛脱迹，於子岂有不知。",
	  "我今执柯以伐柯，云龙风虎，终有会期，云龙风虎，终有会期。",
    "樵曰，子亦何为。",
    "樵曰，人生在世，行乐好太平。鱼在水，杨鬐鼓髡受不惊。子垂陆具过用许机心，伤生害命何深。",
    "樵曰，志不在鱼垂直钓，心无贪利坐家吟。子今正是严边獭，何道忘私弄月明。",
	  "樵击担而对曰，子在江兮我在山，计来两物一般般。息肩罢钓相逢话，莫把江山比等闲。",
	  "我是子非休再辨，我非子是莫虚谈。不如得个红鳞鲤，灼火薪蒸共笑颜。",
	  "..."});
	if ( section>=Sections )
		error("『"+query_tune_name(tune)+"』并没有这么多段音乐，不存在"+chinese_number(section+1)+"节音乐。\n");
	
	if ( !mode )
	  return HIC+song1[section]+"\n"NOR;
	else
		return YEL+song2[section]+"\n"NOR;
}

//载入公共的合奏曲对队友Buffer效果库文件
#include "tune_ensemblebuff.h"