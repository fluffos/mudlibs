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

set("max_jing",4834);
set("jing",4834);
set("max_qi",7600);
set("qi",7600);
set("max_jingli",5000);
set("jingli",5000);
set("max_neili",7800);
set("neili",7800);
set("jiali",100);
set("combat_exp",36800000);

set_skill("literate",1152);
set_skill("medical-skill",700);
set_skill("staff",700);
set_skill("fanwen",700);
set_skill("force",700);
set_skill("parry",700);
set_skill("strike",700);
set_skill("finger",700);
set_skill("dodge",700);
set_skill("sword",700);
set_skill("blade",700);
set_skill("taoism",310);
set_skill("throwing",700);
set_skill("daoxue-xinfa",101);

set_skill("huntian-qigong",380);
set_skill("bihai-shengong",280);
set_skill("taiji-shengong",340);
set_skill("xiake-shengong",462);
set_skill("jiuyin-shengong",540);
set_skill("xianglong-zhang",700);
set_skill("dagou-bang",700);
set_skill("luoying-shenfa",700);
set_skill("xiake-jianfa",700);
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

        set("inquiry", ([
        "hp"    : (: do_hp :),
        "skills" : (: do_skills :),
        "score" : (: do_score :),
        ]));
setup();
}
int do_hp()
{
      message_vision("$N说： 我的基本状态如下：\n\n"+
"——————————————————————————————————\n"+
"  精 ： 4834/ 4834 (100%)        精力： 5000 / 5000 (+0)            \n"+
"  精 ： 4834/ 4834 (100%)        精力： 5000 / 5000 (+0)            \n"+
"  气 ： 7600/ 7600 (100%)        内力： 7800 / 7800 (+100)          \n"+
" 食物：    0/  500               潜能：   0                         \n"+
" 饮水：    0/  500               经验：   36800000                  \n"+
"——————————————————————————————————\n", this_object());
        return 1;
}
int do_score()
{
        message_vision("$N说: 我的基本状况如下: \n\n"+
"【 平  民 】古墓派使者「四大名捕之无情||福威镖局菜鸟镖头」曲清(Quqing)\n"+
"                                                                      \n"+
" 你是一位五十九岁的未婚男性人类，辛酉年十月二十六日辰时一刻生。       \n"+
"                                                                      \n"+
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
" 你到目前为止总共杀了 0 个人，其中有 0 个是其他玩家。                 \n"+
"                                                                      \n"+
" 道     德：  0                                                       \n"+
" 潜     能：  0 (100%)                                                \n"+
" 实战 经验：  36800000                                                \n"+
"                                                                      \n"+
" 师门忠诚度：0                                                        \n"+
" 江湖声望： 120764                                                    \n",this_object());
	return 1;
}
int do_skills()
{
	message_vision("$N说: 我的所有的武功如下: \n\n"+
"——————————————————————————————————\n"+
"  碧海神功 (bihai-shengong)                - 深不可测 280/    0     \n"+
"  基本刀法 (blade)                         - 深不可测 700/    0     \n"+
"□打狗棒法 (dagou-bang)                    - 深不可测 700/    0     \n"+
"  道学心法 (daoxue-xinfa)                  - 震古烁今 101/    0     \n"+
"  基本轻功 (dodge)                         - 深不可测 700/    0     \n"+
"  基础梵文 (fanwen)                        - 深不可测 700/    0     \n"+
"  基本指法 (finger)                        - 深不可测 700/    0     \n"+
"  基本内功 (force)                         - 深不可测 700/    0     \n"+
"  混天气功 (huntian-qigong)                - 深不可测 380/    0     \n"+
"□九阴神功 (jiuyin-shengong)               - 深不可测 540/    0     \n"+
"  读书写字 (literate)                      - 深不可测 1152/    0    \n"+
"□落英身法 (luoying-shenfa)                - 深不可测 700/    0     \n"+
"  医    术 (medical-skill)                 - 深不可测 700/    0     \n"+
"  基本招架 (parry)                         - 深不可测 700/    0     \n"+
"  基本杖法 (staff)                         - 深不可测 700/    0     \n"+
"  基本掌法 (strike)                        - 深不可测 700/    0     \n"+
"  基本剑法 (sword)                         - 深不可测 700/    0     \n"+
"  太极神功 (taiji-shengong)                - 深不可测 340/    0     \n"+
"□弹指神功 (tanzhi-shengong)               - 深不可测 700/    0     \n"+
"  道学心法 (taoism)                        - 深不可测 310/    0     \n"+
"  基本暗器 (throwing)                      - 深不可测 700/    0     \n"+
"□侠客刀法 (xiake-daofa)                   - 深不可测 700/    0     \n"+
"□侠客剑法 (xiake-jianfa)                  - 深不可测 700/    0     \n"+
"  侠客神功 (xiake-shengong)                - 深不可测 462/    0     \n"+
"□降龙十八掌 (xianglong-zhang)             - 深不可测 700/    0     \n"+
"——————————————————————————————————\n",this_object());
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

