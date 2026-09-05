#include "ansi.h"

inherit NPC;

int do_hp();
int do_skills();
int do_score();
void create()
{
set_name("曲清",({"qu qing","quqing"}));
set("nickname",""HIC"四大名捕"HIR"之"HIW"无情"WHT"||"HIG"福威镖局"HIY"菜鸟镖头"NOR"");
set("title",RED"古墓派"GRN"使者");
set("gender","男性");
set("age",59);
set("attitude", "friendly");
set("shen_type", 0);

set("str", 40);
set("con", 40);
set("int", 40);
set("dex", 40);

set("max_jing",21848);
set("jing",2184);
set("max_qi",7055);
set("qi",7055);
set("max_jingli",5778);
set("jingli",5778);
set("max_neili",7717);
set("neili",7717);
set("jiali",100);
set("combat_exp",36325062);

set_skill("literate",1152);
set_skill("medical-skill",700);
set_skill("staff",701);
set_skill("fanwen",523);
set_skill("force",701);
set_skill("parry",702);
set_skill("strike",703);
set_skill("finger",700);
set_skill("dodge",701);
set_skill("sword",700);
set_skill("blade",701);
set_skill("taoism",310);
set_skill("throwing",701);
set_skill("daoxue-xinfa",101);

set_skill("huntian-qigong",377);
set_skill("jiuyin-shengong",514);
set_skill("bihai-shengong",273);
set_skill("hero-jianfa",701);
set_skill("taiji-shengong",340);
set_skill("taiji-jian",621);
set_skill("taiji-dao",589);
set_skill("xiake-shengong",469);
set_skill("jiuyin-shengong",540);
set_skill("xianglong-zhang",700);
set_skill("dagou-bang",655);
set_skill("luoying-shenfa",613);
set_skill("xiake-jianfa",502);
set_skill("xiake-daofa",700);
set_skill("tanzhi-shengong",700);

map_skill("parry","xianglong-zhang");
map_skill("strike","xianglong-zhang");
map_skill("staff","dagou-bang");
map_skill("force","jiuyin-shengong");
map_skill("dodge","luoying-shenfa");
map_skill("finger","tanzhi-shengong");
map_skill("sword","xiake-jianfa");
map_skill("blade","xiake-daofa");

prepare_skill("strike","xianglong-zhang");

	carry_object(__DIR__"obj/herosword")->wield();
	carry_object(__DIR__"obj/pao")->wear();

	set("inquiry", ([
		"hp"    : (: do_hp :),
        "skills" : (: do_skills :),
        "score" : (: do_score :),
        ]));
setup();
}
int do_hp()
{
      message_vision("$N说： 我的基本状态如下：\n\n", this_object());

printf(HIC"≡"HIY"──────────────────────────────────"HIC"≡\n"NOR);
	message_vision(
"  精 ： 2232/ 2184 (100%)        精力： 5658 / 5778 (+0)            \n"+
"  气 ： 7055/ 7055 (100%)        内力： 7717 / 7717 (+0)            \n"+
" 食物：  471/  500               潜能：   53075                     \n"+
" 饮水：  452/  500               经验：   36325062                  \n", this_object());
printf(HIC"≡"HIY"──────────────────────────────────"HIC"≡\n"NOR);

        return 1;
}
int do_score()
{
        message_vision("$N说: 我的基本状况如下: \n\n"+
"【绝代侠客】古墓派使者「四大名捕之无情||福威镖局菜鸟镖头」曲清(Quqing)\n"+
"                                                                      \n"+
" 你是一位五十九岁的未婚男性人类，辛酉年十月二十六日辰时一刻生。       \n"+
"                                                                      \n"+
" 你的老婆是minis。 目前她正在连线中，快去接她呀！					   \n"+
" 膂力：[110]  悟性：[155]  根骨：[110]  身法：[110]                   \n"+
"                                                                      \n"+
" <精>  ■■■■■■■■■■■■■■■■■■■■■■■■■             \n"+
" <气>  ■■■■■■■■■■■■■■■■■■■■■■■■■             \n"+
"                                                                      \n"+
" 攻击 13475183 (+0)     躲闪 13475183   招架 13475183 (+0)            \n"+
"                                                                      \n"+
" 食物：□□□□□□□□□□□□□□□□□□□□□□□□□             \n"+
" 饮水：□□□□□□□□□□□□□□□□□□□□□□□□□             \n"+
"                                                                      \n"+
" 你到目前为止总共杀了 4464 个人，其中有 0 个是其他玩家。              \n"+
"                                                                      \n"+
" 道     德：  26479                                                   \n"+
" 潜     能：  53075 (96%)                                             \n"+
" 实战 经验：  36325062                                                \n"+
"                                                                      \n"+
" 师门忠诚度：0                                                        \n"+
" 江湖声望： 120764                                                    \n"+
"																	   \n"+
" 你这一生一共竞技一千一百七十一场,其中一千一百六十八胜三败			   \n"+
"																	   \n"+
" 你单场最高奖励为四万九千零五十点经验和一千二百二十六点潜能		   \n"+
"																	   \n"+
" 你连续竞技获胜的最高场数为二十五场!								   \n",this_object());
	return 1;
}
int do_skills()
{
	message_vision("$N说: 我的所有的武功如下: \n\n",this_object());
	
printf(HIC"≡"HIY"──────────────────────────────────"HIC"≡\n"NOR);
	message_vision(
"  碧海神功 (bihai-shengong)                - 深不可测 273/ 3621     \n"+
"  基本刀法 (blade)                         - 深不可测 701/38793     \n"+
"□打狗棒法 (dagou-bang)                    - 深不可测 655/   84     \n"+
"  道学心法 (daoxue-xinfa)                  - 震古烁今 101/    0     \n"+
"  基本轻功 (dodge)                         - 深不可测 701/157618    \n"+
"  基础梵文 (fanwen)                        - 深不可测 523/101850    \n"+
"  基本指法 (finger)                        - 深不可测 700/145522    \n"+
"  基本内功 (force)                         - 深不可测 701/70787     \n"+
"  英雄剑法 (hero-jianfa)                   - 深不可测 701/   21     \n"+
"  混天气功 (huntian-qigong)                - 深不可测 377/    0     \n"+
"□九阴神功 (jiuyin-shengong)               - 深不可测 514/186806    \n"+
"  读书写字 (literate)                      - 深不可测 1157/    0    \n"+
"□落英身法 (luoying-shenfa)                - 深不可测 613/285243    \n"+
"  医    术 (medical-skill)                 - 深不可测 700/55198     \n"+
"  基本招架 (parry)                         - 深不可测 702/24962     \n"+
"  基本杖法 (staff)                         - 深不可测 701/281780    \n"+
"  基本掌法 (strike)                        - 深不可测 703/410318    \n"+
"  基本剑法 (sword)                         - 深不可测 700/66834     \n"+
"  太极刀法 (taiji-dao)                     - 深不可测 589/330000    \n"+
"  太极剑法 (taiji-jian)                    - 深不可测 621/    0     \n"+
"  太极神功 (taiji-shengong)                - 深不可测 340/ 1135     \n"+
"□弹指神功 (tanzhi-shengong)               - 深不可测 700/61515     \n"+
"  道学心法 (taoism)                        - 深不可测 319/82450     \n"+
"  基本暗器 (throwing)                      - 深不可测 701/254760    \n"+
"□侠客刀法 (xiake-daofa)                   - 深不可测 700/95921     \n"+
"□侠客剑法 (xiake-jianfa)                  - 深不可测 502/154729    \n"+
"  侠客拳脚 (xiake-quanjiao)                - 深不可测 167/ 4640     \n"+
"  侠客神功 (xiake-shengong)                - 深不可测 469/49972     \n"+
"  侠客掌法 (xiake-strike)                  - 深不可测 166/23200     \n"+
"□降龙十八掌 (xianglong-zhang)             - 深不可测 700/293097    \n"+
"——————————————————————————————————\n",this_object());
printf(HIC"≡"HIY"──────────────────────────────────"HIC"≡\n"NOR);
       return 1;
}

void heal()
{
object ob=this_object();
if(ob->query("eff_qi") < ob->query("max_qi"))

     {

      command("exert heal");

      command("enforce 150");
      return;

      }

      if(ob->query("qi") < ob->query("eff_qi"))

      {

      command("exert recover");

      return;

      }

      if(ob->query("jing") < ob->query("eff_jing"))

      {

      command("exert regererate");

      return;

      }

}
