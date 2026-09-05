//胡笳十八拍
//反映了蔡文姬思念故乡而又不忍骨肉分离的极端矛盾的痛苦心情。音乐委婉悲伤，撕裂肝肠。 
//给敌人加debuff，2级紊乱，持续掉精
#include <ansi.h>
#define MinTuneLevel 150   //演奏该乐曲的最低等级限制
#define SectSpiRed -30     //每演奏完一节的精神消耗
#define SectForceRed -5    //每演奏完一节的内力消耗
#define SectTime 3         //每节持续的时间
#define Sections 36        //该乐曲一共有多少节
#define RestTime 12        //演奏完一首乐曲以后的休息时间
#define MinSpi   200       //最低精神
#define MinForce 200       //最低内力
inherit F_MUSIC;
#include <combat/music.h>

//定义该曲目的伴奏效果
//琵琶和筝伴奏有正效果，鼓和铜钹伴奏有负效果，其他乐器没有伴奏效果
int query_aux_instrument(string instrument)
{
	if ( instrument=="zheng" || 
		   instrument=="pipa" )
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
	
  if ( aux_coef>=150 )
    aux_level=1;
  else if ( aux_coef<=-150 )
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
 	  effect_disorder(player, listeners, instrument, tune, 1+aux_level, pri_coef, aux_coef);
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
	({"我生之初尚无为，我生之后汉祚衰。天不仁兮降乱离，地不仁兮使我逢此时。干戈日寻兮道路危，民卒流亡兮共哀悲。",
		"烟尘蔽野兮胡虏盛，志意乖兮节义亏。对殊俗兮非我宜，遭恶辱兮当告谁？笳一会兮琴一拍，心愤怨兮无人知。",
    "戎羯逼我兮为室家，将我行兮向天涯。云山万重兮归路遐，疾风千里兮扬尘沙。",
    "人多暴猛兮如虺蛇，控弦被甲兮为骄奢。两拍张弦兮弦欲绝，志摧心折兮自悲嗟。",
    "越汉国兮入胡城，亡家失身兮不如无生。毡裘为裳兮骨肉震惊，羯羶为味兮枉遏我情。",
    "鼙鼓喧兮从夜达明，胡风浩浩兮暗塞营。伤今感昔兮三拍成，衔悲畜恨兮何时平。",
    "无日无夜兮不思我乡土，禀气含生兮莫过我最苦。天灾国乱兮人无主，唯我薄命兮没戎虏。",
    "殊俗心异兮身难处，嗜欲不同兮谁可与语！寻思涉历兮多艰阻，四拍成兮益凄楚。",
    "雁南征兮欲寄边心，雁北归兮为得汉音。雁飞高兮邈难寻，",
    "空断肠兮思愔愔。攒眉向月兮抚雅琴，五拍泠泠兮意弥深。",
    "冰霜凛凛兮身苦寒，饥对肉酪兮不能餐。夜闻陇水兮声呜咽，",
    "朝见长城兮路杳漫。追思往日兮行李难，六拍悲来兮欲罢弹。",
    "日暮风悲兮边声四起，不知愁心兮说向谁是！原野萧条兮烽戍万里，俗贱老弱兮少壮为美。",
    "逐有水草兮安家葺垒，牛羊满野兮聚如蜂蚁。草尽水竭兮羊马皆徙，七拍流恨兮恶居于此。",
    "为天有眼兮何不见我独漂流？为神有灵兮何事处我天南海北头？我不负天兮天何配我殊匹？",
    "我不负神兮神何殛我越荒州？制兹八拍兮拟排忧，何知曲成兮心转愁。",
    "天无涯兮地无边，我心愁兮亦复然。人生倏忽兮如白驹之过隙，然不得欢乐兮当我之盛年。",
    "怨兮欲问天，天苍苍兮上无缘。举头仰望兮空云烟，九拍怀情兮谁与传？",
    "城头烽火不曾灭，疆场征战何时歇？杀气朝朝冲塞门，胡风夜夜吹边月。",
    "故乡隔兮音尘绝，哭无声兮气将咽。一生辛苦兮缘别离，十拍悲深兮泪成血。",
    "我非贪生而恶死，不能捐身兮心有以。生仍冀得兮归桑梓，死当埋骨兮长已矣。日居月诸兮在戎垒，",
    "胡人宠我兮有二子。鞠之育之兮不羞耻，愍之念之兮生长边鄙。十有一拍兮因兹起，哀响缠绵兮彻心髓。",
    "东风应律兮暖气多，知是汉家天子兮布阳和。羌胡蹈舞兮共讴歌，两国交欢兮罢兵戈。忽遇汉使兮称近诏，",
    "遣千金兮赎妾身。喜得生还兮逢圣君，嗟别稚子兮会无因。十有二拍兮哀乐均，去住两情兮难具陈。",
    "不谓残生兮却得旋归，抚抱胡儿兮泣下沾衣。汉使迎我兮四牡騑騑，胡儿号兮谁得知？与我生死兮逢此时，",
    "愁为子兮日无光辉，焉得羽翼兮将汝归。一步一远兮足难移，魂消影绝兮恩爱遗。十有三拍兮弦急调悲，肝肠搅刺兮人莫我知。",
    "身归国兮儿莫之随，心悬悬兮长如饥。四时万物兮有盛衰，唯我愁苦兮不暂移。山高地阔兮见汝无期，",
    "更深夜阑兮梦汝来斯。梦中执手兮一喜一悲，觉后痛吾心兮无休歇时。十有四拍兮涕泪交垂，河水东流兮心自思。",
    "十五拍兮节调促，气填胸兮谁识曲？处穹庐兮偶殊俗。愿得归来兮天从欲，再还汉国兮欢心足。",
    "心有怀兮愁转深，日月无私兮曾不照临。子母分离兮意难任，同天隔越兮如商参，生死不相知兮何处寻！",
    "十六拍兮思茫茫，我与儿兮各一方。日东月西兮徒相望，不得相随兮空断肠。对萱草兮忧不忘，",
    "弹鸣琴兮情何伤！今别子兮归故乡，旧怨平兮新怨长！泣血仰头兮诉苍苍，胡为生我兮独罹此殃！",
    "十七拍兮心鼻酸，关山阻修兮行路难。去时怀土兮心无绪，来时别儿兮思漫漫。塞上黄蒿兮枝枯叶干，",
    "沙场白骨兮刀痕箭瘢。风霜凛凛兮春夏寒，人马饥豗兮筋力覃。岂知重得兮入长安，叹息欲绝兮泪阑干。",
    "胡笳本自出胡中，缘琴翻出音律同。十八拍兮曲虽终，响有余兮思无穷。是知丝竹微妙兮均造化之功，",
    "哀乐各随人心兮有变则通。胡与汉兮异域殊风，天与地隔兮子西母东。苦我怨气兮浩于长空，六合虽广兮受之应不容！ "});
	
	if ( section>=Sections )
		error("『"+query_tune_name(tune)+"』并没有这么多段音乐，不存在"+chinese_number(section+1)+"节音乐。\n");
	
	return HIM+song[section]+"\n"NOR;
}

//载入公共的对敌人Debuff效果库文件
#include "tune_debuff.h"