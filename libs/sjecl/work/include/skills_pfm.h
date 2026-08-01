//common skills and pfm file skills_pfm.h
//created by campsun 2003/09/19
//通用的skills调用和pfm调用函数
//使用方法：copy_menpai(门派名字，高低级武功，是否使用武器，pfm的概率）
//第一个参数通过数组调用（必须数组调用），如果数组内为空，则使用内定的str_menpai来随机选择一个门派。
//武功的高低指该门派的高级武功和低级武功之分。
//是否使用武器指定产生的npc是否使用武器
//pfm的概率：如果为0，则不发pfm
//注1：并不是所有门派都有高级和初级的空手或者
//copy to /inclue/下 by campsun 2003/10/30
//使用该.h文件之前，必须inhert 一个npc或者master

#ifndef _SKILL_PFM_
#define _SKILL_PFM_
#endif

int copy_menpai(string, int, int, int);
int set_skills_level(int);                   //设定npc的武功等级，自动排除一些限制等级的武功
void copy_state();                     //根据npc的门派，获得一定的jing，qi加成	



void copy_state() {
  object ob;
  mapping skl;
  int death;
  ob = this_object();
  skl = ob->query_skills();

  switch (ob->query("family/family_name")) {
    case "昆仑派":
      if (skl["xuantian-wuji"] > 400) {
        ob->add("max_jing", (skl["art"] / 2 - 40) * (skl["xuantian-wuji"] / 15));
        ob->add("max_qi", (skl["art"] / 2 - 30) * (skl["xuantian-wuji"] / 12));
        break;
      }
      if (skl["art"] > 81) {
        ob->add("max_jing", (skl["art"] / 2 - 40) * (skl["xuantian-wuji"] / 15));
        ob->add("max_qi", (skl["art"] / 2 - 30) * (skl["xuantian-wuji"] / 15));
      }
      break;
    case "少林派":
    case "天龙寺":
      if (skl["buddhism"] > 61)
        ob->add("max_jing", (skl["buddhism"] / 2 - 30) * (skl["force"] / 10));
      if (skl["buddhism"] > 101)
        ob->add("max_qi", (skl["buddhism"] / 2 - 40) * (skl["force"] / 20));
      break;
    case "铁掌帮":
      if (skl["tiezhang-xinfa"] > 61) {
        ob->add("max_qi", (skl["tiezhang-xinfa"] / 2 - 30) * (skl["guiyuan-tunafa"] / 20));
        ob->add("max_jing", (skl["tiezhang-xinfa"] / 2 - 40) * (skl["guiyuan-tunafa"] / 20));
      }
    case "峨嵋派":
      if (skl["dacheng-fofa"] > 61)
        ob->add("max_jing", (skl["dacheng-fofa"] / 2 - 30) * (skl["linji-zhuang"] / 10));
      if (skl["dacheng-fofa"] > 101)
        ob->add("max_qi", (skl["dacheng-fofa"] / 2 - 40) * (skl["linji-zhuang"] / 20));
      break;
    case "桃花岛":
      if (skl["qimen-bagua"] > 61) {
        ob->add("max_qi", (skl["qimen-bagua"] / 2 - 30) * (skl["bihai-chaosheng"] / 15));
        ob->add("max_jing", (skl["qimen-bagua"] / 2 - 30) * (skl["bihai-chaosheng"] / 15));
      }
      break;
    case "武当派":
      if (skl["taoism"] > 61)
        ob->add("max_qi", (skl["taoism"] / 2 - 30) * (skl["yinyun-ziqi"] / 10));
      if (skl["taoism"] > 121)
        ob->add("max_jing", (skl["taoism"] / 2 - 50) * (skl["yinyun-ziqi"] / 25));
      break;
    case "星宿派":
      if (skl["poison"] > 61)
        ob->add("max_qi", (skl["poison"] / 2 - 25) * (skl["huagong-dafa"] / 10));
      if (skl["poison"] > 121)
        ob->add("max_jing", (skl["poison"] / 2 - 50) * (skl["huagong-dafa"] / 20));
      break;
    case "姑苏慕容":
    case "明教":
      if (skl["force"] > 81)
        ob->add("max_qi", (skl["force"] / 2 - 40) * 15);
      if (skl["force"] > 151)
        ob->add("max_jing", (skl["force"] / 2 - 40) * 15);
      break;
    case "丐帮":
      death = ob->query("death_times");
      if (death > 100) death = 100;
      if (death > 1) {
        ob->add("max_qi", death * ob->query("con"));
        ob->add("max_jing", death * ob->query("con"));
      }
      if (skl["begging"] > 61)
        ob->add("max_qi", (skl["begging"] / 2 - 30) * (skl["huntian-qigong"] / 20));
      break;
    case "大轮寺":
      if (skl["huanxi-chan"] > 61)
        ob->add("max_jing", (skl["huanxi-chan"] / 2 - 30) * (skl["longxiang-boruo"] / 10));
      if (skl["huanxi-chan"] > 121)
        ob->add("max_qi", (skl["huanxi-chan"] / 2 - 50) * (skl["longxiang-boruo"] / 40));
      break;
    case "古墓派":
      if (skl["yunu-xinjing"] > 81)
        ob->add("max_qi", (skl["yunu-xinjing"] / 2 - 40) * 10);
      if (skl["yunu-xinjing"] > 81)
        ob->add("max_jing", (skl["yunu-xinjing"] / 2 - 40) * 15);
      break;
    case "神龙教":
      if (skl["shenlong-yaoli"] > 81 && skl["dulong-dafa"] > 81) {
        ob->add("max_qi", (skl["shenlong-yaoli"] / 2 - 35) * (skl["dulong-dafa"] / 16));
        ob->add("max_jing", (skl["shenlong-yaoli"] / 2 - 35) * (skl["dulong-dafa"] / 25));
      }
      break;
    case "嵩山派":
      if (skl["songshan-jian"] > 51)
        ob->add("max_qi", skl["songshan-jian"] * 3);
      if (skl["hanbing-zhenqi"] > 81)
        ob->add("max_jing", (skl["hanbing-zhenqi"] / 2 - 40) * 10);
      break;
    case "华山派":
      if (skl["zhengqi-jue"] > 61) {
        ob->add("max_qi", (skl["zhengqi-jue"] / 2 - 30) * (skl["zixia-gong"] / 20));
        ob->add("max_jing", (skl["zhengqi-jue"] / 2 - 30) * (skl["zixia-gong"] / 20));
      }
      break;
    default:
      if (skl["hamagong"] >= 1) {
        ob->add("max_qi", skl["hamagong"] * 5);
        ob->add("max_jing", skl["hamagong"] * 5);
      }
  }

  ob->add("max_qi", ob->query("max_neili") * ob->query("con") / 80);


}  //end copy_state
int set_skills_level(int level) {
  object me;
  mapping skills;
  string *sk;
  int i;
  string *str_skill_other = ({ "taoism",      //武当：道学心法
  "begging",      //丐帮：叫化绝活
  "bangjue",      //丐帮：打狗棒口诀
  "stealing",      //丐帮：妙手空空
  "checking",      //丐帮：
  "zhenqijue",     //华山：正气诀
  "tiezhang-xinfa",    //铁掌：铁掌心法
  "huanxi-chan",     //大轮寺：欢喜禅
  "shenlong-yaoli",    //神龙岛：神龙药理
  "dacheng-fofa",     //峨嵋：大乘佛法
  "qimen-bagua",     //桃花岛：奇门八卦
  "buddhism",      //天龙寺，少林：禅宗心法
  "art",       //昆仑：琴棋书画
  "daode-jing",     //九阴：道德经
  "literate",
    "poison",
    "medicine"
  });

  me = this_object();
  skills = me->query_skills();
  if (mapp(skills)) {
    sk = keys(skills);
    sk = sk - str_skill_other;
    for (i = 0; i < sizeof(sk); i++)
      skills[sk[i]] = level;
  }


}  //end set_skills_level  


nosave string u_weapon = "";
nosave string nw_parry = "";
nosave string w_parry = "";
nosave string u_liumai = "";
nosave string *u_ub_pfm = ({});         //非战斗状态的pfm
nosave string *u_f_pfm = ({});
nosave string *u_w_pfm = ({});
nosave string *u_pfm = ({});          //初试化武器，空手招架，武器招架，pfm列表				
nosave string *skill;                                                                    //skill 列表	
nosave int in_level;
nosave string u_menpai = "";
nosave string *in_menpai;
nosave mapping pmap;           //prepare的武功				
nosave string *str_liumai = ({
  "shaoze",
  "guanchong",
  "shangyang",
  "shaochong",
  "zhongchong",
  "shaoshang"
});
nosave int in_weapon;

#include "skills_pfm_set.h"

int copy_menpai(string *in_menpai2, int in_level2, int in_weapon2, int in_pfmrate) {
  string *str_menpai = ({ "wd", "hs",
    "ss", "gm",
    "gb", "tz",
    "dls", "mr",
    "sld", "xx",
    "em", "mj",
    "thd", "tls",
    "sl", "kl", "9y",
    "pxj", "jsj", "hmg"
  });

  //string u_menpai="";	
  in_menpai = in_menpai2;
  in_weapon = in_weapon2;

  set_skill("literate", 100);
  set_skill("poison", 100);
  set_skill("medicine", 100);        //初试化武功杂项三种	

  set_skill("force", 500);
  set_skill("dodge", 500);
  set_skill("parry", 500);                                 //初试化基本内功，基本躲闪，基本招架

  set_skill("cuff", 500);
  set_skill("finger", 500);
  set_skill("leg", 500);
  set_skill("strike", 500);
  set_skill("claw", 500);
  set_skill("throwing", 500);
  set_skill("hand", 500);         //初试化基本空手武功

  set_skill("sword", 500);
  set_skill("blade", 500);
  set_skill("stick", 500);
  set_skill("staff", 500);
  set_skill("axe", 500);
  set_skill("brush", 500);
  set_skill("dagger", 500);
  set_skill("club", 500);
  set_skill("whip", 500);         //初试化基本兵器武功

  if (sizeof(in_menpai))
    u_menpai = in_menpai[random(sizeof(in_menpai))];
  else
    u_menpai = str_menpai[random(sizeof(str_menpai))];

  if (in_level2) in_level = 1;       //

  copy_menpai2();
  ///

  //如果一组武功中没有空手武功 空手武功设定为空明拳 太祖拳
  if (nw_parry == "") {
    switch (random(2)) {
      case 0:
        set_skill("kongming-quan", 500);                 //空明拳
        set("zhou/jieyi", 1);
        map_skill("cuff", "kongming-quan");
        nw_parry = "kongming-quan";
        prepare_skill("cuff", "kongming-quan");
        u_pfm = u_pfm + ({ (: perform_action, "cuff.kong" :) });   //空明拳pfm：空			
        u_pfm = u_pfm + ({ (: perform_action, "cuff.ming" :) });   //明
        set("f_skill", "kongming-quan");
        break;
      case 1:
        set_skill("taizu-quan", 500);
        map_skill("cuff", "taizu-quan");
        nw_parry = "taizu-quan";
        prepare_skill("cuff", "taizu-quan");
        set("f_skill", "taizu-quan");
        break;
    }
  }
  //如果一组武功中没有兵器武功 wuhu-duanmendao
  if (w_parry == "") {
    set_skill("wuhu-duanmendao", 500);
    map_skill("blade", "wuhu-duanmendao");
    w_parry = "wuhu-duanmendao";
    u_weapon = "blade";
    u_f_pfm = u_f_pfm + ({ (: perform_action, "blade.duan" :) });
    set("f_w_skill", "wuhu-duanmendao");

  }
  //装备武器并设定使用的招架	
  if (in_weapon && u_weapon != "") {
    carry_object(BINGQI_D(u_weapon))->wield();
    map_skill("parry", w_parry);
  } else {
    map_skill("parry", nw_parry);
  }
  //设定是否出pfm以及出pfm的概率
  if (in_pfmrate) {
    set("chat_chance_combat", in_pfmrate);
    if (in_weapon)
      set("chat_msg_combat", u_f_pfm + u_w_pfm);
    else
      set("chat_msg_combat", u_f_pfm + u_pfm);
    if (sizeof(u_ub_pfm) != 0) {
      set("chat_chance", in_pfmrate);
      set("chat_msg", u_ub_pfm);
    }
    if (sizeof(query("chat_msg")) == 0)
      delete("chat_msg");
    if (sizeof(query("chat_msg_combat")) == 0)
      delete("chat_msg_combat");
  }

  //记录obejct所用的空手招架和兵器招架以及使用的武器，在需要改变时可以调用
  set("u_pfm", u_pfm);
  set("u_w_pfm", u_w_pfm);
  set("u_f_pfm", u_f_pfm);
  set("w_parry", w_parry);
  set("nw_parry", nw_parry);
  set("u_weapon", u_weapon);

  return 1;
}
