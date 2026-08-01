//common skills and pfm file skills_pfm.h
//created by campsun 2003/09/19
//通用的skills调用和pfm调用函数
//使用方法：copy_menpai(门派名字，高低级武功，是否使用武器，pfm的概率）
//第一个参数通过数组调用（必须数组调用），如果数组内为空，则使用内定的str_menpai来随机选择一个门派。
//武功的高低指该门派的高级武功和低级武功之分。
//是否使用武器指定产生的npc是否使用武器
//pfm的概率：如果为0，则不发pfm
//注1：并不是所有门派都有高级和初级的空手或者

#include "r_name.h"

int copy_menpai(string, int, int, int);
int set_skills_level(int);   //设定npc的武功等级，自动排除一些限制等级的武功
void copy_state();    //根据npc的门派，获得一定的jing，qi加成	
void get_npc_name();    //根据npc的门派，获得npc的名字

string *nick_first = ({
  HIB "南海" NOR, HIY "平原" NOR, HIW "辽东" NOR, HIG "川西" NOR, RED "平阳" NOR, WHT "天外" NOR,
  HIB "独孤" NOR, HIW "飘雪" NOR, YEL "求败" NOR, HIY "无心" NOR, MAG "红粉" NOR, HIR "夕阳" NOR,
  HIY "江南" NOR, });

string *nick_second = ({
  HIM "霸" NOR, CYN "刀" NOR, RED "剑" NOR, WHT "枪" NOR, HIB "鞭" NOR, YEL "索" NOR, HIR "红" NOR,
  CYN "娇" NOR, HIB "虎" NOR, HIY "豹" NOR, HIR "老人" NOR, HIG "客" NOR, WHT "侠" NOR, HIB "龙" NOR,
});

string create_nick() {
  string nick1, nick2;
  nick1 = nick_first[random(sizeof(nick_first))];
  nick2 = nick_second[random(sizeof(nick_second))];
  if (random(5) > 3)
    return nick1 + "一" + nick2;
  else
    return nick1 + nick2;
}

void get_npc_name() {
  mapping name;
  object ob = this_object();
  int sex = random(3);
  int i;

  string *sl_fre_name = ({ "渡", "玄", "澄", "慧", "道", "清", "虚", "圆" });
  string *sl_fre_id = ({ "du", "xuan", "chen", "hui", "dao", "qing", "xu", "yuan" });
  string *em_fre_name = ({ "灭", "静" });
  string *em_fre_id = ({ "mie", "jing" });
  string *tls_fre_name = ({ "本", "了" });
  string *tls_fre_id = ({ "ben", "liao" });
  switch (ob->query("family/family_name")) {
    case "少林派":
      name = get_random_name(1, 1);
      set("gender", "男性");
      i = random(sizeof(sl_fre_name));
      set_name(sl_fre_name[i] + name["name"], ({ sl_fre_id[i] + " " + name["id"][0] }));
      break;
    case "娥眉派":
      name = get_random_name(0, 1);
      set("gender", "女性");
      i = random(sizeof(em_fre_name));
      set_name(em_fre_name[i] + name["name"], ({ em_fre_id[i] + " " + name["id"][0] }));
      break;
    case "姑苏慕容":
      name = get_random_name(sex, random(2) + 1);
      set("gender", (sex ? "男性" : "女性"));
      if (sizeof(name["id"]) == 1)
        set_name("慕容" + name["name"], ({ "murong " + name["id"][0] }));
      else
        set_name("慕容" + name["name"], ({ "murong " + name["id"][1] + name["id"][2] }));        //特别注释：０是生成的全名，１和２才是分开的字，下同
        break;
    case "桃花岛":
      name = get_random_name(sex, 2);
      set("gender", (sex ? "男性" : "女性"));
      if (sizeof(name["id"]) == 1)
        set_name(name["name"] + "风", ({ name["id"][0] + " feng" }));
      else
        set_name(name["name"] + "风", ({ name["id"][1] + name["id"][2] + " feng" }));
      break;
    case "天龙寺":
      name = get_random_name(1, 1);
      set("gender", "男性");
      i = random(sizeof(tls_fre_name));
      set_name(tls_fre_name[i] + name["name"], ({ tls_fre_id[i] + " " + name["id"][0] }));
      break;
    default:
      set("gender", (sex ? "男性" : "女性"));
      if (random(10))
        name = get_random_name(sex, 3);
      else
        name = get_random_name(sex, 2);
      set_name(name["name"], name["id"]);
  }


}


void copy_state() {
  object ob;
  mapping skl;
  ob = this_object();
  skl = ob->query_skills();

  switch (ob->query("family/family_name")) {
    case "昆仑派":
      if (skl["art"] > 81) {
        ob->add("max_jing",
          (skl["art"] / 2 - 40) * (skl["xuantian-wuji"] / 15));
        ob->add("max_qi",
          (skl["art"] / 2 - 40) * (skl["xuantian-wuji"] / 15));
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
      if (ob->query("death_times") > 1) {
        ob->add("max_qi", ob->query("death_times") * ob->query("con"));
        ob->add("max_jing", ob->query("death_times") * ob->query("con"));
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
      if (skl["shenlong-yaoli"] > 51 && skl["dulong-dafa"] > 81) {
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
      if (skl["hamagong"]) {
        ob->add("max_qi", skl["hamagong"] * 5);
        ob->add("max_jing", skl["hamagong"] * 5);
      }
  }

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



int copy_menpai(string *in_menpai, int in_level, int in_weapon, int in_pfmrate) {
  string *str_menpai = ({ "wd", "hs",
    "ss", "gm",
    "gb", "tz",
    "dls", "mr",
    "sld", "xx",
    "em", "mj",
    "thd", "tls",
    "sl", "kl", "9y"
  });

  string *str_liumai = ({
    "shaoze",
    "guanchong",
    "shangyang",
    "shaochong",
    "zhongchong",
    "shaoshang"
  });

  string u_weapon = "";
  string u_menpai = "";
  string nw_parry = "";
  string w_parry = "";
  string u_liumai = "";
  string *u_pfm = ({});          //初试化武器，空手招架，武器招架，pfm列表				
  string *skill;           //skill 列表	

  mapping pmap;           //prepare的武功				

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

  if (in_level) in_level = 1;        //

  switch (u_menpai) {
    case "wd":           //设定武当的武功
      set("family/family_name", "武当派");
      set_skill("yinyun-ziqi", 500);     //武当内功：氤氲紫气
      set_skill("tiyunzong", 500);      //武当轻功: 踢云纵
      set_skill("taoism", 200);                        //武当杂项：道学心法
      map_skill("force", "yinyun-ziqi");
      map_skill("dodge", "tiyunzong");
      u_pfm = u_pfm + ({ (: exert_function, "yinyun" :) });             //氤氲紫气pfm:氤氲内聚
      u_pfm = u_pfm + ({ (: exert_function, "taiji" :) });             //太极
      u_pfm = u_pfm + ({ (: perform_action, "dodge.zong" :) });         //踢云纵pfm:纵   
      switch (in_level) {
        case 0:
          switch (random(3)) {
            case 0:
              set_skill("wudang-quan", 500);                 //武当低级空手：武当长拳
              map_skill("cuff", "wudang-quan");
              nw_parry = "wudang-quan";
              prepare_skill("cuff", "wudang-quan");
              set("f_skill", "wudang-quan");
              break;
            case 1:
              set_skill("zhenshan-mianzhang", 500);          //武当低级空手：震山绵掌 
              map_skill("strike", "zhenshan-mianzhang");
              nw_parry = "zhenshan-mianzhang";
              prepare_skill("strike", "zhenshan-mianzhang");
              u_pfm = u_pfm + ({ (: perform_action, "strike.bingdi" :) });  //震山绵掌pfm:花开并蒂
              set("f_skill", "zhenshan-mianzhang");
              break;
            case 2:
              set_skill("juehu-shou", 500);
              map_skill("hand", "juehu-shou");
              nw_parry = "juehu-shou";
              prepare_skill("hand", "juehu-shou");
              set("f_skill", "juehu-shou");
              break;
          }
          switch (random(1)) {
            case 0:
              set_skill("xuanxu-daofa", 500);                          //武当低级兵器：玄虚刀法
              map_skill("blade", "xuanxu-daofa");
              w_parry = "xuanxu-daofa";
              set("f_w_skill", "xuanxu-daofa");
              u_weapon = "blade";
              break;
          }
          break;
        case 1:
          switch (random(1)) {
            case 0:
              set_skill("taiji-quan", 500);                                    //武当高级空手：太极拳
              map_skill("cuff", "taiji-quan");
              nw_parry = "taiji-quan";
              prepare_skill("cuff", "taiji-quan");
              u_pfm = u_pfm + ({ (: perform_action, "cuff.ji" :) });    //太极拳pfm:挤
              u_pfm = u_pfm + ({ (: perform_action, "cuff.zhannian" :) });   //粘黏
              u_pfm = u_pfm + ({ (: perform_action, "cuff.zhen" :) });    //震
              u_pfm = u_pfm + ({ (: perform_action, "cuff.luanhuan" :) });   //乱还决
              u_pfm = u_pfm + ({ (: perform_action, "cuff.yinyang" :) });   //阴阳决
              u_pfm = u_pfm + ({ (: perform_action, "cuff.gangrou" :) });   //刚柔决
              u_pfm = u_pfm + ({ (: perform_action, "cuff.dongjing" :) });   //动静决
              u_pfm = u_pfm + ({ (: perform_action, "cuff.an" :) });    //按
              u_pfm = u_pfm + ({ (: perform_action, "cuff.taiji" :) });                           //太极
              set("f_skill", "taiji-quan");
              break;
          }
          switch (random(1)) {
            case 0:
              set_skill("taiji-jian", 500);          //武当高级兵器：太极剑
              map_skill("sword", "taiji-jian");
              w_parry = "taiji-jian";
              u_pfm = u_pfm + ({ (: perform_action, "sword.chan" :) });    //太极剑pfm：缠
              u_pfm = u_pfm + ({ (: perform_action, "sword.sanhuan" :) });   //三环套月
              u_pfm = u_pfm + ({ (: perform_action, "sword.lian" :) });    //连
              set("wd/raozhi", 1);
              u_pfm = u_pfm + ({ (: perform_action, "sword.raozhi" :) });   //绕指柔剑
              //							u_pfm = u_pfm + ({(: perform_action, "sword.tongshou" :)});			//天地同寿
              u_weapon = "sword";
              set("f_w_skill", "taiji-jian");
              break;
          }
          break;
      }
      break;  //end case wd
    case "ss":            //设定嵩山武功
      set("family/family_name", "嵩山派");
      set_skill("hanbing-zhenqi", 500);     //嵩山内功：寒冰真气			
      set_skill("zhongyuefeng", 500);      //嵩山轻功：中岳风
      map_skill("force", "hanbing-zhenqi");
      map_skill("dodge", "zhongyuefeng");
      u_pfm = u_pfm + ({ (: exert_function, "hanbing" :) });   //寒冰真气pfm：寒冰
      u_pfm = u_pfm + ({ (: exert_function, "juhan" :) });     //聚寒
      switch (in_level) {
        case 0:
          switch (random(1)) {
            case 0:
              set_skill("songyang-shou", 500);                             //嵩山低级空手：嵩阳手
              map_skill("hand", "songyang-shou");
              nw_parry = "songyang-shou";
              prepare_skill("hand", "songyang-shou");
              u_pfm = u_pfm + ({ (: perform_action, "hand.junji" :) });        //嵩阳手pfm：竣极
              u_pfm = u_pfm + ({ (: perform_action, "hand.yinyang" :) });      //阴阳
              set("f_skill", "songyang-shou");
              break;

          }
          switch (random(1)) {
            case 0:
              set_skill("songyang-bian", 500);                               //嵩山低级武器：嵩阳鞭
              map_skill("whip", "songyang-bian");
              w_parry = "songyang-bian";
              u_pfm = u_pfm + ({ (: perform_action, "whip.luan" :) });          //嵩阳鞭pfm：乱
              u_weapon = "whip";
              set("f_w_skill", "songyang-bian");
              break;
          }
          break;
        case 1:
          switch (random(1)) {
            case 0:
              set_skill("hanbing-shenzhang", 500);        //嵩山高级空手：寒冰神掌		
              map_skill("strike", "hanbing-shenzhang");
              nw_parry = "hanbing-shenzhang";
              prepare_skill("strike", "hanbing-shenzhang");
              u_pfm = u_pfm + ({ (: perform_action, "strike.hanbing" :) });     //寒冰神掌pfm：寒冰
              set("f_skill", "hanbing-shenzhang");
              break;
          }
          switch (random(1)) {
            case 0:
              set_skill("songshan-jian", 500);          //嵩山高级兵器：嵩山剑法
              map_skill("sword", "songshan-jian");
              w_parry = "songshan-jian";
              u_pfm = u_pfm + ({ (: perform_action, "sword.feiwu" :) });         //嵩山剑法pfm：飞舞
              u_pfm = u_pfm + ({ (: perform_action, "sword.leiting" :) });   //雷霆一击
              u_pfm = u_pfm + ({ (: perform_action, "sword.longfeng" :) });   //龙飞	
              u_pfm = u_pfm + ({ (: perform_action, "sword.songyang" :) });   //嵩阳
              u_weapon = "sword";
              set("f_w_skill", "songshan-jian");
              break;
          }
          break;
      }
      break;  //end case ss			
    case "gb":                                                      //设定丐帮武功
      set("family/family_name", "丐帮");
      set_skill("huntian-qigong", 500);       //丐帮内功：混天一气功
      set_skill("xiaoyaoyou", 500);        //丐帮轻功：逍遥游	
      set_skill("begging", 200);
      set("death_times", 50);
      set_skill("bangjue", 200);
      set_skill("stealing", 200);
      set_skill("checking", 200);         //丐帮杂项：begging，bangjue，stealing，checking		
      map_skill("force", "huntian-qigong");
      map_skill("dodge", "xiaoyaoyou");
      u_pfm = u_pfm + ({ (: exert_function, "powerup" :) });          //混天气功pfm：powerup
      switch (in_level) {
        case 0:
          switch (random(2)) {
            case 0:
              set_skill("lianhua-zhang", 500);    //丐帮低级空手：莲花掌
              map_skill("strike", "lianhua-zhang");
              nw_parry = "lianhua-zhang";
              prepare_skill("strike", "lianhua-zhang");
              set("f_skill", "lianhua-zhang");
              break;
            case 1:
              set_skill("suohou-shou", 500);              //丐帮低级空手：锁喉手
              map_skill("hand", "suohou-shou");
              nw_parry = "suohou-shou";
              prepare_skill("hand", "suohou-shou");
              set("f_skill", "suohou-shou");
              break;


          }
          switch (random(3)) {
            case 0:
              set_skill("huifeng-bian", 500);                                //丐帮低级兵器：回风鞭
              map_skill("whip", "huifeng-bian");
              w_parry = "huifeng-bian";
              u_pfm = u_pfm + ({ (: perform_action, "whip.huixuan" :) });       //回风鞭pfm：回风
              u_weapon = "whip";
              set("f_w_skill", "huifeng-bian");
              break;
            case 1:
              set_skill("liuhe-daofa", 500);          //丐帮低级兵器：莲花刀法				
              map_skill("blade", "liuhe-daofa");
              w_parry = "liuhe-daofa";
              u_pfm = u_pfm + ({ (: perform_action, "blade.sancai" :) });       //莲花刀法pfm：奇门三才	
              u_weapon = "blade";
              set("f_w_skill", "liuhe-daofa");
              break;
            case 2:
              set_skill("fengmo-zhang", 500);          //丐帮低级兵器：疯魔杖
              set("shen", -5000000);
              map_skill("staff", "fengmo-zhang");
              w_parry = "fengmo-zhang";
              u_weapon = "staff";
              u_pfm = u_pfm + ({ (: perform_action, "staff.feizhi" :) });       //莲花刀法pfm：奇门三才	
              set("f_w_skill", "fengmo-zhang");
              break;
          }
          break;
        case 1:
          switch (random(1)) {
            case 0:
              set_skill("xianglong-zhang", 500);        //丐帮高级空手：降龙掌
              map_skill("strike", "xianglong-zhang");
              nw_parry = "xianglong-zhang";
              prepare_skill("strike", "xianglong-zhang");
              u_pfm = u_pfm + ({ (: perform_action, "strike.paiyun" :) });         //降龙掌pfm：排云双掌
              u_pfm = u_pfm + ({ (: perform_action, "strike.xiao" :) });  //啸
              u_pfm = u_pfm + ({ (: perform_action, "strike.kanglong" :) });  //亢龙无悔
              set("xlz/hang", 1);                      //出亢龙的条件
              set("f_skill", "xianglong-zhang");

              break;
          }
          switch (random(1)) {
            case 0:
              set_skill("dagou-bang", 500);         //丐帮高级兵器：打狗棒法
              set_skill("dagou-bang", 500);
              map_skill("stick", "dagou-bang");
              w_parry = "dagou-bang";
              u_pfm = u_pfm + ({ (: perform_action, "stick.chan" :) });        //打狗棒法pfm：缠
              u_pfm = u_pfm + ({ (: perform_action, "stick.chuo" :) });   //戳
              u_pfm = u_pfm + ({ (: perform_action, "stick.shuangjue" :) });  //棒掌双绝
              u_pfm = u_pfm + ({ (: perform_action, "stick.tiao" :) });   //挑
              u_pfm = u_pfm + ({ (: perform_action, "stick.zhuan" :) });  //转
              u_pfm = u_pfm + ({ (: perform_action, "stick.wugou" :) });  //天下无狗
              u_weapon = "stick";
              set("f_w_skill", "dagou-bang");
              break;
          }
          break;
      }
      break;  //end case gb		
    case "hs":                                                      //设定华山武功
      set("family/family_name", "华山派");
      set_skill("zixia-gong", 500);        //华山内功：紫霞功
      set_skill("huashan-shenfa", 500);       //华山轻功：华山身法	
      set_skill("zhengqi-jue", 200);        //华山杂项：正气决			
      map_skill("force", "zixia-gong");
      map_skill("dodge", "huashan-shenfa");
      u_pfm = u_pfm + ({ (: exert_function, "zixia" :) });            //紫霞功pfm：zixia    
      switch (in_level) {
        case 0:
          switch (random(1)) {
            case 0:
              set_skill("poyu-quan", 500);    //华山低级空手：破玉拳
              map_skill("cuff", "poyu-quan");
              nw_parry = "poyu-quan";
              prepare_skill("cuff", "poyu-quan");
              set("f_skill", "poyu-quan");
              break;
          }
          switch (random(2)) {
            case 0:
              set_skill("fanliangyi-dao", 500);                              //华山低级兵器：反两仪刀法
              map_skill("blade", "fanliangyi-dao");
              w_parry = "fanliangyi-dao";
              u_pfm = u_pfm + ({ (: perform_action, "blade.sanshenfeng" :) });       //反两仪刀法pfm：华岳三神峰
              u_weapon = "blade";
              set("f_w_skill", "fanliangyi-dao");
              break;
            case 1:
              set_skill("chongling-jian", 500);                              //华山低级兵器：冲灵剑法
              map_skill("sword", "chongling-jian");
              w_parry = "chongling-jian";
              //							u_pfm=u_pfm + ({(: perform_action, "sword.hebi" :)});       //冲灵剑法pfm：合壁
              u_weapon = "sword";
              set("f_w_skill", "chongling-jian");
              break;
          }
          break;
        case 1:
          switch (random(1)) {
            case 0:
              set_skill("hunyuan-zhang", 500);    //华山低级空手：混元掌
              map_skill("strike", "hunyuan-zhang");
              nw_parry = "hunyuan-zhang";
              prepare_skill("strike", "hunyuan-zhang");
              u_pfm = u_pfm + ({ (: perform_action, "strike.wuji" :) });       //混元掌pfm：混元无极
              set("f_skill", "hunyuan-zhang");
              break;
          }
          switch (random(2)) {
            case 0:
              set_skill("huashan-jianfa", 500);        //华山高级兵器：华山剑法
              map_skill("sword", "huashan-jianfa");
              w_parry = "huashan-jianfa";
              u_pfm = u_pfm + ({ (: perform_action, "sword.feijian" :) });      //华山剑法pfm：飞剑
              u_pfm = u_pfm + ({ (: perform_action, "sword.junzi" :) });  //君子
              u_pfm = u_pfm + ({ (: perform_action, "sword.kuaijian" :) });  //快剑
              u_pfm = u_pfm + ({ (: perform_action, "sword.lianhuan" :) });  //连环
              u_pfm = u_pfm + ({ (: perform_action, "sword.sanqingfeng" :) });  //三清风
              u_pfm = u_pfm + ({ (: perform_action, "sword.shijiushi" :) });  //十九式
              u_pfm = u_pfm + ({ (: perform_action, "sword.shunv" :) });  //淑女
              u_pfm = u_pfm + ({ (: perform_action, "sword.wushuang" :) });  //无双
              u_pfm = u_pfm + ({ (: perform_action, "sword.xiyi" :) });   //希夷
              u_pfm = u_pfm + ({ (: perform_action, "sword.yangwu" :) });  //仰吾
              u_weapon = "sword";
              set("f_w_skill", "huashan-jianfa");
              break;
            case 1:
              set_skill("dugu-jiujian", 500);        //华山高级兵器：独孤九剑
              map_skill("dodge", "dugu-jiujian");
              map_skill("sword", "dugu-jiujian");
              w_parry = "dugu-jiujian";
              u_pfm = u_pfm + ({ (: perform_action, "sword.kuangfeng" :) });    //独孤九剑pfm：狂风
              u_pfm = u_pfm + ({ (: perform_action, "sword.pobian" :) });
              u_pfm = u_pfm + ({ (: perform_action, "sword.pojian" :) });
              u_pfm = u_pfm + ({ (: perform_action, "sword.pozhang" :) });
              u_pfm = u_pfm + ({ (: perform_action, "sword.poqi" :) });
              u_pfm = u_pfm + ({ (: perform_action, "sword.poqiang" :) });
              u_pfm = u_pfm + ({ (: perform_action, "sword.posuo" :) });
              u_pfm = u_pfm + ({ (: perform_action, "sword.zongjue" :) });  //总决
              u_weapon = "sword";
              set("f_w_skill", "dugu-jiujian");
              break;
          }
          break;
      }
      break;  //end case hs
    case "tz":            //设定铁掌武功
      set("family/family_name", "铁掌帮");
      set_skill("guiyuan-tunafa", 500);     //铁掌内功：归元吐纳法			
      set_skill("shuishangpiao", 500);      //铁掌轻功：水上漂
      set_skill("tiezhang-xinfa", 200);     //铁掌杂项：铁掌心法
      map_skill("force", "guiyuan-tunafa");
      map_skill("dodge", "shuishangpiao");
      u_pfm = u_pfm + ({ (: exert_function, "focus" :) });          //铁掌气功pfm：focus
      u_pfm = u_pfm + ({ (: perform_action, "dodge.piao" :) });     //水上漂pfm:漂
      switch (in_level) {
        case 0:
          switch (random(1)) {
            case 0:
              set_skill("tiezhang-zhangfa", 500);        //铁掌高级空手：铁掌掌法		
              map_skill("strike", "tiezhang-zhangfa");       //tz 无低级空手，所以低级空手也是铁掌掌法
              nw_parry = "tiezhang-zhangfa";
              prepare_skill("strike", "tiezhang-zhangfa");
              u_pfm = u_pfm + ({ (: perform_action, "strike.duoming" :) });     //铁掌掌法pfm：夺命铁爪
              u_pfm = u_pfm + ({ (: perform_action, "strike.heisha" :) });     //铁掌掌法pfm：黑 砂 掌
              u_pfm = u_pfm + ({ (: perform_action, "strike.heyi" :) });     //铁掌掌法pfm：阴阳合一
              u_pfm = u_pfm + ({ (: perform_action, "strike.honglei" :) });     //铁掌掌法pfm：轰雷双掌
              u_pfm = u_pfm + ({ (: perform_action, "strike.judu" :) });     //铁掌掌法pfm：聚    毒
              u_pfm = u_pfm + ({ (: perform_action, "strike.pangen" :) });     //铁掌掌法pfm：枯树盘根
              u_pfm = u_pfm + ({ (: perform_action, "strike.pushan" :) });     //铁掌掌法pfm：铁蒲扇掌
              u_pfm = u_pfm + ({ (: perform_action, "strike.qinna" :) });     //铁掌掌法pfm：铁掌擒拿
              u_pfm = u_pfm + ({ (: perform_action, "strike.rubairen" :) });     //铁掌掌法pfm：入 白 刃
              u_pfm = u_pfm + ({ (: perform_action, "strike.tianlei" :) });     //铁掌掌法pfm：天 雷 气
              u_pfm = u_pfm + ({ (: perform_action, "strike.xuanfeng" :) });     //铁掌掌法pfm：旋风快掌
              u_pfm = u_pfm + ({ (: perform_action, "strike.zhangdao" :) });     //铁掌掌法pfm：铁掌掌刀
              u_pfm = u_pfm + ({ (: perform_action, "strike.tiezhang" :) });     //铁掌掌法pfm：铁掌
              set("f_skill", "tiezhang-zhangfa");
              break;
          }
          switch (random(2)) {
            case 0:
              set_skill("liuye-daofa", 500);                               //铁掌低级武器：柳叶刀法
              map_skill("blade", "liuye-daofa");
              w_parry = "liuye-daofa";
              u_pfm = u_pfm + ({ (: perform_action, "blade.daozhang" :) });   //柳叶刀法pfm：刀掌
              u_weapon = "blade";           //需要铁掌掌法为招架，并且prepare
              set("f_w_skill", "liuye-daofa");
              break;
            case 1:
              set_skill("yingou-bifa", 500);                               //铁掌低级武器：银钩笔法
              map_skill("brush", "yingou-bifa");
              w_parry = "yingou-bifa";
              u_pfm = u_pfm + ({ (: perform_action, "brush.caoshu" :) });   //银钩笔法pfm：草书
              u_pfm = u_pfm + ({ (: perform_action, "brush.kaishu" :) });   //银钩笔法pfm：草书
              u_pfm = u_pfm + ({ (: perform_action, "brush.shigu" :) });   //银钩笔法pfm：草书
              u_weapon = "brush";
              set("f_w_skill", "yingou-bifa");
              break;
          }
          break;
        case 1:
          switch (random(1)) {
            case 0:
              set_skill("tiezhang-zhangfa", 500);        //铁掌高级空手：铁掌掌法		
              map_skill("strike", "tiezhang-zhangfa");
              nw_parry = "tiezhang-zhangfa";
              prepare_skill("strike", "tiezhang-zhangfa");
              u_pfm = u_pfm + ({ (: perform_action, "strike.duoming" :) });     //铁掌掌法pfm：夺命铁爪
              u_pfm = u_pfm + ({ (: perform_action, "strike.heisha" :) });     //铁掌掌法pfm：黑 砂 掌
              u_pfm = u_pfm + ({ (: perform_action, "strike.heyi" :) });     //铁掌掌法pfm：阴阳合一
              u_pfm = u_pfm + ({ (: perform_action, "strike.honglei" :) });     //铁掌掌法pfm：轰雷双掌
              u_pfm = u_pfm + ({ (: perform_action, "strike.judu" :) });     //铁掌掌法pfm：聚    毒
              u_pfm = u_pfm + ({ (: perform_action, "strike.pangen" :) });     //铁掌掌法pfm：枯树盘根
              u_pfm = u_pfm + ({ (: perform_action, "strike.pushan" :) });     //铁掌掌法pfm：铁蒲扇掌
              u_pfm = u_pfm + ({ (: perform_action, "strike.qinna" :) });     //铁掌掌法pfm：铁掌擒拿
              u_pfm = u_pfm + ({ (: perform_action, "strike.rubairen" :) });     //铁掌掌法pfm：入 白 刃
              u_pfm = u_pfm + ({ (: perform_action, "strike.tianlei" :) });     //铁掌掌法pfm：天 雷 气
              u_pfm = u_pfm + ({ (: perform_action, "strike.xuanfeng" :) });     //铁掌掌法pfm：旋风快掌
              u_pfm = u_pfm + ({ (: perform_action, "strike.zhangdao" :) });     //铁掌掌法pfm：铁掌掌刀
              u_pfm = u_pfm + ({ (: perform_action, "strike.tiezhang" :) });     //铁掌掌法pfm：铁掌
              set("f_skill", "tiezhang-zhangfa");
              break;
          }
          switch (random(1)) {
            case 0:
              set_skill("lietian-fu", 500);                               //铁掌高级武器：裂天斧
              map_skill("axe", "lietian-fu");
              w_parry = "lietian-fu";
              u_pfm = u_pfm + ({ (: perform_action, "axe.lihun" :) });    //裂天斧pfm：离魂
              u_weapon = "axe";
              set("f_w_skill", "lietian-fu");
              break;
          }
          break;
      }
      break;  //end case tz

    case "dls":            //设定大轮寺武功
      set("family/family_name", "大轮寺");
      set_skill("longxiang-boruo", 500);     //大轮寺内功：龙象般若功			
      set_skill("yuxue-dunxing", 500);      //大轮寺轻功：御雪遁形
      set_skill("huanxi-chan", 200);      //大轮寺杂项：欢喜禅
      map_skill("force", "longxiang-boruo");
      map_skill("dodge", "yuxue-dunxing");
      u_pfm = u_pfm + ({ (: exert_function, "longxiang" :) });   //龙象般若功pfm：龙象
      u_pfm = u_pfm + ({ (: exert_function, "shield" :) });      //气盾
      switch (in_level) {
        case 0:
          switch (random(2)) {
            case 0:
              set_skill("dashou-yin", 500);                             //大轮寺低级空手：大手印
              map_skill("hand", "dashou-yin");
              nw_parry = "dashou-yin";
              prepare_skill("hand", "dashou-yin");
              u_pfm = u_pfm + ({ (: perform_action, "hand.tianyin" :) });  //大手印pfm：阿修罗天印
              set("f_skill", "dashou-yin");
              break;
            case 1:
              set_skill("tianwang-zhua", 500);                             //大轮寺低级空手：大手印
              map_skill("claw", "tianwang-zhua");
              nw_parry = "tianwang-zhua";
              prepare_skill("claw", "tianwang-zhua");
              set("f_skill", "tianwang-zhua");
              break;

          }
          switch (random(1)) {
            case 0:
              set_skill("wushang-dali", 500);                               //大轮寺低级武器：无上大力杵
              map_skill("staff", "wushang-dali");
              w_parry = "wushang-dali";
              u_weapon = "staff";
              set("f_w_skill", "wushang-dali");
              break;
          }
          break;
        case 1:
          switch (random(1)) {
            case 0:
              set_skill("huoyan-dao", 500);        //大轮寺高级空手：火焰刀		
              map_skill("strike", "huoyan-dao");
              nw_parry = "huoyan-dao";
              prepare_skill("strike", "huoyan-dao");
              u_pfm = u_pfm + ({ (: perform_action, "strike.fen" :) });     //火焰刀pfm：棼
              set("f_skill", "huoyan-dao");
              break;
          }
          switch (random(2)) {
            case 0:
              set_skill("xuedao-jing", 500);          //大轮寺高级兵器：血刀经
              map_skill("blade", "xuedao-jing");
              w_parry = "xuedao-jing";
              set("env/jixue", random(5) + 1);                                       //pfm 祭血设置条件
              u_pfm = u_pfm + ({ (: perform_action, "blade.jixue" :) });         //pfm 祭血
              u_pfm = u_pfm + ({ (: perform_action, "blade.shendao" :) });   //神刀穿心
              u_weapon = "blade";
              set("f_w_skill", "xuedao-jing");
              break;
            case 1:
              set_skill("xiangfu-lun", 500);          //大轮寺高级兵器：降服轮
              map_skill("hammer", "xiangfu-lun");
              w_parry = "xiangfu-lun";
              u_pfm = u_pfm + ({ (: perform_action, "hammer.wushuai" :) });         //天人五衰
              u_pfm = u_pfm + ({ (: perform_action, "hammer.dazhuan" :) });   //大转
              u_weapon = "hammer";
              set("f_w_skill", "xiangfu-lun");
              break;
          }
          break;
      }
      break;  //end case dls				
    case "gm":            //设定古墓武功
      set("family/family_name", "古墓派");
      set_skill("yunu-xinjing", 500);      //古墓内功：玉女心经			
      set_skill("yunu-shenfa", 500);      //古墓轻功：玉女身法
      map_skill("force", "yunu-xinjing");
      map_skill("dodge", "yunu-shenfa");
      u_pfm = u_pfm + ({ (: exert_function, "xinjing" :) });  //玉女心经pfm：xinjing
      switch (in_level) {
        case 0:
          switch (random(2)) {
            case 0:
              set_skill("tianluo-diwang", 500);                             //古墓低级空手：天罗地网式
              map_skill("strike", "tianluo-diwang");
              nw_parry = "tianluo-diwang";
              prepare_skill("strike", "tianluo-diwang");
              set("f_skill", "tianluo-diwang");
              break;
            case 1:
              set_skill("meinu-quanfa", 500);                             //古墓低级空手：美女拳法
              map_skill("cuff", "meinu-quanfa");
              nw_parry = "meinu-quanfa";
              prepare_skill("cuff", "meinu-quanfa");
              u_pfm = u_pfm + ({ (: perform_action, "cuff.shexin" :) });  //美女拳法pfm:摄心
              set("f_skill", "meinu-quanfa");
              break;

          }
          switch (random(2)) {
            case 0:
              set_skill("yunu-jianfa", 500);                               //古墓低级武器：玉女素心剑
              map_skill("sword", "yunu-jianfa");
              w_parry = "yunu-jianfa";
              u_pfm = u_pfm + ({ (: perform_action, "sword.suxin" :) });      //玉女素心剑pfm：素心
              u_weapon = "sword";
              set("f_w_skill", "yunu-jianfa");
              break;
            case 1:
              set_skill("quanzhen-jianfa", 500);                               //古墓低级武器：全真剑法
              map_skill("sword", "quanzhen-jianfa");
              w_parry = "quanzhen-jianfa";
              u_pfm = u_pfm + ({ (: perform_action, "sword.qixing" :) });      //全真剑法pfm：七星聚顶
              u_pfm = u_pfm + ({ (: perform_action, "sword.sanqing" :) });        //三清风
              u_weapon = "sword";
              set("f_w_skill", "quanzhen-jianfa");
              break;
          }
          break;
        case 1:
          switch (random(1)) {
            case 0:
              set_skill("anran-zhang", 500);        //古墓高级空手：黯然销魂掌		
              map_skill("strike", "anran-zhang");
              nw_parry = "anran-zhang";
              prepare_skill("strike", "anran-zhang");
              u_pfm = u_pfm + ({ (: perform_action, "strike.anran" :) });     //黯然销魂掌pfm：黯然
              u_pfm = u_pfm + ({ (: perform_action, "strike.jishi" :) });     //黯然销魂掌pfm：嫉世
              u_pfm = u_pfm + ({ (: perform_action, "strike.xiaohun" :) });     //黯然销魂掌pfm：销魂
              set("f_skill", "anran-zhang");
              break;
          }
          switch (random(2)) {
            case 0:
              set_skill("xuantie-jianfa", 500);         //古墓高级兵器：玄铁剑法
              map_skill("sword", "xuantie-jianfa");
              w_parry = "xuantie-jianfa";
              set("env/玄铁剑法", random(2) ? "海潮" : "汹涌");      //pfm 海潮的随机设定
              u_pfm = u_pfm + ({ (: perform_action, "sword.haichao" :) });         //玄铁pfm：海潮
              u_pfm = u_pfm + ({ (: perform_action, "sword.wujian" :) });   //无剑
              u_weapon = "sword";
              set("f_w_skill", "xuantie-jianfa");
              break;
            case 1:
              set_skill("yinsuo-jinling", 500);         //古墓高级兵器：银索金铃
              if (in_weapon) {
                pmap = query_skill_prepare();
                if (sizeof(pmap)) {
                  skill = keys(pmap);
                  foreach (string item in skill)
                    prepare_skill(item);
                }
                set_skill("meinu-quanfa", 500);          //pfm sanwu的条件之一
                map_skill("cuff", "meinu-quanfa");
                prepare_skill("cuff", "meinu-quanfa");
                set("f_skill", "meinu-quanfa");
              }
              map_skill("whip", "yinsuo-jinling");
              set("gmsanwu", 1);
              w_parry = "yinsuo-jinling";
              u_pfm = u_pfm + ({ (: perform_action, "whip.sanwu" :) });         //银索金铃pfm：三无三不手
              //							u_pfm = u_pfm + ({(: perform_action, "whip.yueyin" :)});			//yueyin
              u_weapon = "whip";
              set("f_w_skill", "yinsuo-jinling");
              break;
          }
          break;
      }
      break;  //end case gm	

    case "mr":            //设定慕容武功
      set("family/family_name", "姑苏慕容");
      set_skill("shenyuan-gong", 500);     //慕容内功：神元功			
      set_skill("yanling-shenfa", 500);      //慕容轻功：燕灵身法
      set_skill("douzhuan-xingyi", 500);      //斗转星移
      map_skill("force", "shenyuan-gong");
      map_skill("dodge", "yanling-shenfa");
      u_pfm = u_pfm + ({ (: exert_function, "shenyuan" :) });     //神元功pfm：神元
      u_pfm = u_pfm + ({ (: perform_action, "parry.xingyi" :) });     //斗转星移pfm：星移

      switch (in_level) {
        case 0:
          switch (random(1)) {
            case 0:
              set_skill("xingyi-zhang", 500);                             //慕容低级空手：星移掌
              map_skill("strike", "xingyi-zhang");
              nw_parry = "xingyi-zhang";
              prepare_skill("strike", "xingyi-zhang");
              u_pfm = u_pfm + ({ (: perform_action, "strike.riyue" :) });        //星移掌pfm：日月同辉
              set("f_skill", "xingyi-zhang");
              break;

          }
          switch (random(1)) {
            case 0:
              set_skill("murong-daofa", 500);                               //慕容低级武器：慕容刀法
              map_skill("blade", "murong-daofa");
              w_parry = "murong-daofa";
              u_pfm = u_pfm + ({ (: perform_action, "blade.daoying" :) });     //慕容刀法pfm：刀影掌
              u_weapon = "blade";
              set("f_w_skill", "murong-daofa");
              break;
          }
          break;
        case 1:
          switch (random(1)) {
            case 0:
              set_skill("canhe-zhi", 500);        //慕容高级空手：参合指
              map_skill("finger", "canhe-zhi");
              nw_parry = "douzhuan-xingyi";                             //只有在参合指的情况下，才能设定douzhuan-xingyi为parry并且发pfm 
              prepare_skill("finger", "canhe-zhi");
              u_pfm = u_pfm + ({ (: perform_action, "finger.ci" :) });     //参合指pfm：刺
              set("f_skill", "canhe-zhi");
              break;
          }
          switch (random(1)) {
            case 0:
              set_skill("murong-jianfa", 500);          //慕容高级兵器：慕容剑法
              map_skill("sword", "murong-jianfa");
              w_parry = "murong-jianfa";
              u_pfm = u_pfm + ({ (: perform_action, "sword.lianhuan" :) });         //慕容剑法pfm：连环
              u_pfm = u_pfm + ({ (: perform_action, "sword.sanhua" :) });   //散花
              u_weapon = "sword";
              set("f_w_skill", "murong-jianfa");
              break;
          }
          break;
      }
      break;  //end case mr				

    case "sld":            //设定神龙岛武功
      set("family/family_name", "神龙教");
      set("family/master_id", "hong antong");
      set_skill("dulong-dafa", 500);      //神龙岛内功：毒龙大法 			
      set_skill("youlong-shenfa", 500);     //神龙岛轻功：游龙身法
      set_skill("shenlong-yaoli", 200);     //神龙岛杂项：神龙药理学
      map_skill("force", "dulong-dafa");
      map_skill("dodge", "youlong-shenfa");
      u_pfm = u_pfm + ({ (: exert_function, "wudi" :) });     //毒龙大法pfm：无敌
      switch (in_level) {
        case 0:
          switch (random(2)) {
            case 0:
              set_skill("hansha-sheying", 500);                             //神龙岛低级空手：含沙射影
              map_skill("throwing", "hansha-sheying");
              nw_parry = "hansha-sheying";
              prepare_skill("throwing", "hansha-sheying");
              set("f_skill", "hansha-sheying");
              break;
            case 1:
              set_skill("shenlong-tuifa", 500);                             //神龙岛低级空手：神龙腿法
              map_skill("leg", "shenlong-tuifa");
              nw_parry = "shenlong-tuifa";
              prepare_skill("leg", "shenlong-tuifa");
              set("env/zhuiming", random(60) + 1);
              u_pfm = u_pfm + ({ (: perform_action, "leg.zhuiming" :) });          //神龙腿法pfm：追命
              set("f_skill", "shenlong-tuifa");
              break;
          }
          switch (random(1)) {
            case 0:
              set_skill("lingshe-bianfa", 500);                               //神龙岛低级武器：灵蛇鞭法
              map_skill("whip", "lingshe-bianfa");
              w_parry = "lingshe-bianfa";
              u_pfm = u_pfm + ({ (: perform_action, "whip.chan" :) });          //灵蛇鞭法pfm：缠绕
              u_pfm = u_pfm + ({ (: perform_action, "whip.sandou" :) });        //灵蛇鞭法pfm：缠绕
              u_weapon = "whip";
              set("f_w_skill", "lingshe-bianfa");
              break;
          }
          break;
        case 1:
          switch (random(1)) {
            case 0:
              set_skill("huagu-mianzhang", 500);        //神龙岛高级空手：化骨绵掌
              map_skill("strike", "huagu-mianzhang");
              nw_parry = "huagu-mianzhang";
              prepare_skill("strike", "huagu-mianzhang");
              u_pfm = u_pfm + ({ (: perform_action, "strike.bujue" :) });     //化骨绵掌pfm：不绝
              u_pfm = u_pfm + ({ (: perform_action, "strike.huagu" :) });     //化骨绵掌pfm：化骨
              //							u_pfm = u_pfm + ({(: perform_action, "strike.puhuo" :)});     //化骨绵掌pfm：飞蛾扑火
              set("f_skill", "huagu-mianzhang");

              break;
          }
          switch (random(1)) {
            case 0:
              set_skill("tenglong-bifa", 500);          //神龙岛高级兵器：腾龙匕法
              map_skill("dagger", "tenglong-bifa");
              w_parry = "tenglong-bifa";
              u_pfm = u_pfm + ({ (: perform_action, "dagger.diqing" :) });         //腾龙匕法pfm：狄青降龙
              u_pfm = u_pfm + ({ (: perform_action, "dagger.feiyan" :) });   //飞燕回翔
              u_pfm = u_pfm + ({ (: perform_action, "dagger.guifei" :) });   //贵妃回眸	
              u_pfm = u_pfm + ({ (: perform_action, "dagger.luda" :) });   //鲁达拔柳
              u_pfm = u_pfm + ({ (: perform_action, "dagger.xiaolian" :) });  //小怜横陈
              u_pfm = u_pfm + ({ (: perform_action, "dagger.zixu" :) });   //子胥举鼎
              u_weapon = "dagger";
              set("f_w_skill", "tenglong-bifa");
              break;
          }
          break;
      }
      break;  //end case sld		

    case "xx":            //设定星宿武功
      set("family/family_name", "星宿派");
      set_skill("huagong-dafa", 500);      //星宿内功：化功大法			
      set_skill("zhaixingshu", 500);      //星宿轻功：摘星术 
      map_skill("force", "huagong-dafa");
      map_skill("dodge", "zhaixingshu");
      //			u_pfm=u_pfm + ({(: exert_function, "duwu" :)});   //化功大法pfm：毒雾
      set_skill("poison", 200);        // judu need poison >150							
      u_pfm = u_pfm + ({ (: exert_function, "judu" :) });   //聚毒
      switch (in_level) {
        case 0:
          switch (random(1)) {
            case 0:
              set_skill("sanyin-zhua", 500);                             //星宿低级空手：三阴蜈蚣爪
              map_skill("claw", "sanyin-zhua");
              nw_parry = "sanyin-zhua";
              prepare_skill("claw", "sanyin-zhua");
              set("f_skill", "sanyin-zhua");
              break;
          }
          switch (random(1)) {
            case 0:
              set_skill("tianshan-zhang", 500);          //星宿高级兵器：天山杖法
              map_skill("staff", "tianshan-zhang");
              w_parry = "tianshan-zhang";
              u_pfm = u_pfm + ({ (: perform_action, "staff.feizhi" :) });         //天山杖法pfm：飞掷
              u_weapon = "staff";
              set("f_w_skill", "tianshan-zhang");
              break;
          }
          break;
        case 1:
          switch (random(1)) {
            case 0:
              set_skill("chousui-zhang", 500);        //星宿高级空手：抽髓掌		
              map_skill("strike", "chousui-zhang");
              nw_parry = "chousui-zhang";
              prepare_skill("strike", "chousui-zhang");
              u_pfm = u_pfm + ({ (: perform_action, "strike.biyan" :) });     //抽髓掌pfm：碧焰
              //							u_pfm = u_pfm + ({(: perform_action, "strike.fushidu" :)});     //抽髓掌pfm：腐尸毒
              u_pfm = u_pfm + ({ (: perform_action, "strike.huoqiang" :) });     //抽髓掌pfm：火墙
              u_pfm = u_pfm + ({ (: perform_action, "strike.huoqiu" :) });     //抽髓掌pfm：火球
              u_pfm = u_pfm + ({ (: perform_action, "strike.yinhuo" :) });     //抽髓掌pfm：银火
              set("f_skill", "chousui-zhang");
              break;
          }
          switch (random(1)) {
            case 0:
              set_skill("tianshan-zhang", 500);          //星宿高级兵器：天山杖法
              map_skill("staff", "tianshan-zhang");
              w_parry = "tianshan-zhang";
              u_pfm = u_pfm + ({ (: perform_action, "staff.feizhi" :) });         //天山杖法pfm：飞掷
              u_weapon = "staff";
              set("f_w_skill", "tianshan-zhang");
              break;
          }
          break;
      }
      break;  //end case xx

    case "em":            //设定娥眉武功
      set("family/family_name", "娥眉派");
      set_skill("linji-zhuang", 500);      //娥眉内功：临济十二庄			
      set_skill("anying-fuxiang", 500);     //娥眉轻功：暗影浮香
      set_skill("dacheng-fofa", 500);      //娥眉杂项：大乘佛法
      set("class", "bonze");
      map_skill("force", "linji-zhuang");
      map_skill("dodge", "anying-fuxiang");
      u_pfm = u_pfm + ({ (: exert_function, "fengyun" :) });   //临济十二庄pfm：风云
      u_pfm = u_pfm + ({ (: exert_function, "riyue" :) });  //日月
      u_pfm = u_pfm + ({ (: exert_function, "tiandi" :) });    //天地 
      u_pfm = u_pfm + ({ (: exert_function, "wuwo" :) });      //无我
      u_pfm = u_pfm + ({ (: exert_function, "yinyang" :) });   //阴阳  
      if (random(5) == 1)
        u_pfm = u_pfm + ({ (: exert_function, "youming" :) });   //幽冥  
        u_pfm = u_pfm + ({ (: exert_function, "zhixin" :) });    //之心 

        switch (in_level) {
          case 0:
            switch (random(1)) {
              case 0:
                set_skill("sixiang-zhang", 500);                             //娥眉低级空手：四象掌
                map_skill("strike", "sixiang-zhang");
                nw_parry = "sixiang-zhang";
                prepare_skill("strike", "sixiang-zhang");
                set("f_skill", "sixiang-zhang");
                break;

            }
            switch (random(1)) {
              case 0:
                set_skill("yanxing-daofa", 500);                               //娥眉低级武器：雁行刀法
                map_skill("blade", "yanxing-daofa");
                w_parry = "yanxing-daofa";
                u_pfm = u_pfm + ({ (: perform_action, "blade.feiyang" :) });          //雁行刀法pfm：飞扬
                u_pfm = u_pfm + ({ (: perform_action, "blade.huanying" :) });         //雁行刀法pfm：幻影
                u_weapon = "blade";
                set("f_w_skill", "yanxing-daofa");
                break;
            }
            break;
          case 1:
            switch (random(1)) {
              case 0:
                set_skill("jieshou-jiushi", 500);        //娥眉高级空手：截手九式		
                map_skill("hand", "jieshou-jiushi");
                nw_parry = "jieshou-jiushi";
                prepare_skill("hand", "jieshou-jiushi");
                u_pfm = u_pfm + ({ (: perform_action, "hand.foguang" :) });     //截手九式pfm：寒冰
                set("f_skill", "jieshou-jiushi");
                break;
            }
            switch (random(1)) {
              case 0:
                set_skill("huifeng-jian", 500);          //娥眉高级兵器：回风拂柳剑
                map_skill("sword", "huifeng-jian");
                w_parry = "huifeng-jian";
                u_pfm = u_pfm + ({ (: perform_action, "sword.jue" :) });          //回风拂柳剑pfm：绝
                u_pfm = u_pfm + ({ (: perform_action, "sword.liaoyuan" :) });   //燎原
                u_pfm = u_pfm + ({ (: perform_action, "sword.mie" :) });    //灭
                u_weapon = "sword";
                set("f_w_skill", "huifeng-jian");
                break;
            }
            break;
        }
      break;  //end case em		
    case "mj":            //设定明教武功
      set("family/family_name", "明教");
      set_skill("piaoyi-shenfa", 500);      //明教轻功：飘翼身法
      map_skill("dodge", "piaoyi-shenfa");
      set_skill("qiankun-danuoyi", 500);
      u_pfm = u_pfm + ({ (: perform_action, "parry.hua" :) });
      u_pfm = u_pfm + ({ (: perform_action, "parry.xu" :) });
      u_pfm = u_pfm + ({ (: perform_action, "parry.yin" :) });
      switch (in_level) {
        case 0:
          set_skill("shenghuo-shengong", 500);         //明教低级内功：圣火神功
          map_skill("force", "shenghuo-shengong");
          u_pfm = u_pfm + ({ (: exert_function, "tougu" :) });  //圣火神功pfm:透骨
          u_pfm = u_pfm + ({ (: exert_function, "yinfeng" :) });  //阴风		


          switch (random(2)) {
            case 0:
              set_skill("yingzhua-shou", 500);                             //明教低级空手：鹰爪擒拿手
              map_skill("hand", "yingzhua-shou");
              nw_parry = "qiankun-danuoyi";         //设定乾坤大挪移为招架
              prepare_skill("hand", "yingzhua-shou");
              set("f_skill", "yingzhua-shou");
              break;
            case 1:
              set_skill("hanbing-mianzhang", 500);                             //明教低级空手：寒冰绵掌
              map_skill("strike", "hanbing-mianzhang");
              nw_parry = "hanbing-mianzhang";         //pfm xixue 要求parry 为hanbing-mianzhang
              prepare_skill("strike", "hanbing-mianzhang");
              u_pfm = u_pfm + ({ (: perform_action, "strike.xixue" :) });  //寒冰绵掌pfm:吸血
              set("f_skill", "hanbing-mianzhang");
              break;

          }
          switch (random(2)) {
            case 0:
              set_skill("liehuo-jian", 500);                                 //明教低级武器：烈火剑
              map_skill("sword", "liehuo-jian");
              w_parry = "qiankun-danuoyi";               //设定乾坤大挪移为招架
              u_weapon = "sword";
              set("f_w_skill", "liehuo-jian");
              break;
            case 1:
              set_skill("lieyan-dao", 500);                                 //明教低级武器：烈焰刀
              map_skill("blade", "lieyan-dao");
              w_parry = "qiankun-danuoyi";           //设定乾坤大挪移为招架
              u_pfm = u_pfm + ({ (: perform_action, "blade.shenghuo" :) });   //烈焰刀pfm:圣火
              u_weapon = "blade";
              set("f_w_skill", "lieyan-dao");
              break;
          }
          break;
        case 1:
          set_skill("jiuyang-shengong", 500);         //明教高级内功：九阳神功
          set_skill("shenghuo-shengong", 500);         //明教低级内功：圣火神功
          map_skill("force", "jiuyang-shengong");
          u_pfm = u_pfm + ({ (: exert_function, "tougu" :) });  //圣火神功pfm:透骨
          u_pfm = u_pfm + ({ (: exert_function, "yinfeng" :) });  //阴风	
          u_pfm = u_pfm + ({ (: exert_function, "powerup" :) });  //powerup	
          if (!in_weapon)
            switch (random(1))             //明教圣火令法可以为cuff，但强制要求tisha需要cuff 为shenghuo-lingfa 则不好
            {                 //至少限制了空手后明教的主打武功七伤拳。 campsun 注	
              case 0:
                set_skill("qishang-quan", 500);        //明教高级空手：七伤拳		
                map_skill("cuff", "qishang-quan");
                nw_parry = "qiankun-danuoyi";          //设定乾坤大挪移为招架
                prepare_skill("cuff", "qishang-quan");
                u_pfm = u_pfm + ({ (: perform_action, "cuff.qishang" :) });     //七伤拳pfm：七伤
                u_pfm = u_pfm + ({ (: perform_action, "cuff.duanhun" :) });     //七伤拳pfm：断魂
                set("f_skill", "qishang-quan");
                break;
            } else
              switch (random(1)) {
                case 0:
                  set_skill("shenghuo-lingfa", 500);          //明教高级兵器：圣火令法
                  map_skill("dagger", "shenghuo-lingfa");         //设定乾坤大挪移为招架
                  if (in_weapon) {
                    pmap = query_skill_prepare();
                    if (sizeof(pmap)) {
                      skill = keys(pmap);
                      foreach (string item in skill)
                        prepare_skill(item);
                    }                  //防止hubei

                    map_skill("cuff", "shenghuo-lingfa");
                    prepare_skill("cuff", "shenghuo-lingfa");
                    nw_parry = "qiankun-danuoyi";
                    set("f_skill", "shenghuo-lingfa");
                  }
                  w_parry = "qiankun-danuoyi";
                  u_pfm = u_pfm + ({ (: perform_action, "dagger.duo" :) });         //圣火令法pfm：夺
                  u_pfm = u_pfm + ({ (: perform_action, "dagger.ji" :) });   //击
                  u_pfm = u_pfm + ({ (: perform_action, "dagger.tisha" :) });   //踢沙	
                  u_pfm = u_pfm + ({ (: perform_action, "dagger.xinmo" :) });   //心魔
                  u_weapon = "dagger";
                  set("f_w_skill", "shenghuo-lingfa");
                  break;
              }
          break;
      }
      break;  //end case mj	

    case "thd":            //设定桃花岛武功
      set("family/family_name", "桃花岛");
      set_skill("bihai-chaosheng", 500);     //桃花岛内功：碧海潮生功			
      set_skill("suibo-zhuliu", 500);      //桃花岛轻功：随波逐流 
      set_skill("qimen-bagua", 200);
      set("thd/perform", 31);
      map_skill("force", "bihai-chaosheng");
      map_skill("dodge", "suibo-zhuliu");
      //			u_pfm=u_pfm + ({(: exert_function, "play" :)});   //碧海潮生功pfm：吹箫
      u_pfm = u_pfm + ({ (: exert_function, "maze" :) });     //布阵
      u_pfm = u_pfm + ({ (: exert_function, "qimen" :) });     //奇门五行
      u_pfm = u_pfm + ({ (: perform_action, "dodge.wuzhuan" :) });   //随波逐流pfm:五转

      switch (in_level) {
        case 0:
          switch (random(3)) {
            case 0:
              set_skill("lanhua-shou", 500);                             //桃花岛低级空手：兰花拂穴手
              map_skill("hand", "lanhua-shou");
              nw_parry = "lanhua-shou";
              prepare_skill("hand", "lanhua-shou");
              u_pfm = u_pfm + ({ (: perform_action, "hand.fuxue" :) });        //兰花拂穴手pfm：抚穴
              set("f_skill", "lanhua-shou");
              break;
            case 1:
              set_skill("luoying-zhang", 500);                             //桃花岛低级空手：落英神剑掌
              map_skill("strike", "luoying-zhang");
              nw_parry = "luoying-zhang";
              prepare_skill("strike", "luoying-zhang");
              //							u_pfm=u_pfm + ({(: perform_action, "strike.fugu" :)});        //落英神剑掌pfm：抚骨
              u_pfm = u_pfm + ({ (: perform_action, "strike.pikong" :) });        //落英神剑掌pfm：劈空
              //							u_pfm=u_pfm + ({(: perform_action, "strike.bading" :)});        //落英神剑掌pfm：拔钉
              set("f_skill", "luoying-zhang");

              break;
            case 2:
              set_skill("xuanfeng-tui", 500);                             //桃花岛低级空手：旋风扫叶腿
              set_skill("luoying-zhang", 500);                             //pfm xuanfeng 的要求
              map_skill("strike", "luoying-zhang");
              map_skill("leg", "xuanfeng-tui");
              nw_parry = "xuanfeng-tui";
              prepare_skill("leg", "xuanfeng-tui");
              u_pfm = u_pfm + ({ (: perform_action, "leg.kuangfeng" :) });        //旋风扫叶腿pfm：狂风
              set("f_skill", "xuanfeng-tui");
              break;
          }
          switch (random(1))               //thd 无低级兵器,所以设定低级兵器为yxj
          {
            case 0:
              set_skill("yuxiao-jian", 500);          //桃花岛高级兵器：玉箫剑法
              set_skill("tanzhi-shentong", 500);
              map_skill("finger", "tanzhi-shentong");
              set_skill("xuanfeng-tui", 500);
              map_skill("leg", "xuanfeng-tui");
              set_skill("luoying-zhang", 500);
              map_skill("strike", "luoying-zhang");
              set_skill("lanhua-shou", 500);
              map_skill("hand", "lanhua-shou");
              map_skill("sword", "yuxiao-jian");
              w_parry = "yuxiao-jian";
              u_pfm = u_pfm + ({ (: perform_action, "sword.feiying" :) });         //玉箫剑法pfm：飞影
              u_pfm = u_pfm + ({ (: perform_action, "sword.qimen" :) });   //奇门
              u_weapon = "xiao";             //pfm feiying 需要装备箫为武器		
              set("f_w_skill", "yuxiao-jian");
              break;
          }

          break;
        case 1:
          switch (random(1)) {
            case 0:
              set_skill("tanzhi-shentong", 500);        //桃花岛高级空手：弹指神通	
              map_skill("finger", "tanzhi-shentong");
              map_skill("throwing", "tanzhi-shentong");      //弹指神通做暗器
              nw_parry = "tanzhi-shentong";
              prepare_skill("finger", "tanzhi-shentong");
              u_pfm = u_pfm + ({ (: perform_action, "finger.qiankun" :) });     //弹指神通pfm：乾坤一指
              u_pfm = u_pfm + ({ (: perform_action, "finger.shentong" :) });     //弹指神通pfm：神通
              //							u_pfm = u_pfm + ({(: perform_action, "finger.huayu" :)});     //弹指神通pfm：漫天花雨
              set("f_skill", "tanzhi-shentong");

              break;
          }
          switch (random(1)) {
            case 0:
              set_skill("yuxiao-jian", 500);          //桃花岛高级兵器：玉箫剑法
              set_skill("tanzhi-shentong", 500);
              map_skill("finger", "tanzhi-shentong");
              set_skill("xuanfeng-tui", 500);
              map_skill("leg", "xuanfeng-tui");
              set_skill("luoying-zhang", 500);
              map_skill("strike", "luoying-zhang");
              set_skill("lanhua-shou", 500);
              map_skill("hand", "lanhua-shou");
              map_skill("sword", "yuxiao-jian");
              w_parry = "yuxiao-jian";
              u_pfm = u_pfm + ({ (: perform_action, "sword.feiying" :) });         //玉箫剑法pfm：飞影
              u_pfm = u_pfm + ({ (: perform_action, "sword.qimen" :) });   //奇门
              u_weapon = "xiao";             //pfm feiying 需要装备箫为武器		
              set("f_w_skill", "yuxiao-jian");
              break;
          }
          break;
      }
      break;  //end case thd

    case "tls":                  //tls kungfu set							
      set("family/family_name", "天龙寺");
      set_skill("qiantian-yiyang", 500);           //天龙寺低级内功：乾天一阳
      set_skill("tianlong-xiang", 500);           //天龙寺轻功：天龙翔
      set_skill("buddhism", 200);
      set("class", "bonze");
      map_skill("force", "qiantian-yiyang");
      map_skill("dodge", "tianlong-xiang");
      u_pfm = u_pfm + ({ (: exert_function, "xinjing" :) });
      switch (in_level) {
        case 0:
          switch (random(3)) {
            case 0:
              set_skill("qingyan-zhang", 500);                               //天龙寺低级空手：五罗轻烟掌
              map_skill("strike", "qingyan-zhang");
              nw_parry = "qingyan-zhang";
              prepare_skill("strike", "qingyan-zhang");
              set("f_skill", "qingyan-zhang");
              break;
            case 1:
              set_skill("duanjia-quan", 500);                                //天龙寺低级空手：段家拳法
              map_skill("cuff", "duanjia-quan");
              nw_parry = "duanjia-quan";
              prepare_skill("cuff", "duanjia-quan");
              set("f_skill", "duanjia-quan");
              break;
            case 2:
              set_skill("yiyang-zhi", 500);          //天龙寺低级空手：一阳指
              map_skill("finger", "yiyang-zhi");
              nw_parry = "yiyang-zhi";
              prepare_skill("finger", "yiyang-zhi");
              u_pfm = u_pfm + ({ (: perform_action, "finger.sandie" :) });    //一阳指pfm：阳关三叠
              u_pfm = u_pfm + ({ (: perform_action, "finger.yizhisanmai" :) });  //一指三脉
              //							u_pfm = u_pfm + ({(: perform_action, "qianlong" :)});     
              set("f_skill", "yiyang-zhi");
              break;

          }
          switch (random(1)) {
            case 0:
              set_skill("duanjia-jianfa", 500);                                 //天龙寺低级兵器：段家剑法
              map_skill("sword", "duanjia-jianfa");
              if (in_weapon) {
                pmap = query_skill_prepare();
                if (sizeof(pmap)) {
                  skill = keys(pmap);
                  foreach (string item in skill)
                    prepare_skill(item);
                }
                set_skill("qingyan-zhang", 500);
                map_skill("strike", "qingyan-zhang");
                prepare_skill("strike", "qingyan-zhang");
                set("f_skill", "qingyan-zhang");
              }
              w_parry = "qingyan-zhang";
              u_pfm = u_pfm + ({ (: perform_action, "sword.fenglei" :) });           //段家剑法pfm：风雷四击
              u_weapon = "sword";
              set("f_w_skill", "duanjia-jianfa");
              break;
          }
          break;
        case 1:
          set_skill("kurong-changong", 500);           //天龙寺高级内功：枯荣禅功
          map_skill("force", "kurong-changong");
          switch (random(2)) {
            case 0:
              map_skill("strike", "kurong-changong");        //天龙寺高级空手：枯荣禅功
              nw_parry = "kurong-changong";
              prepare_skill("strike", "kurong-changong");
              u_pfm = u_pfm + ({ (: exert_function, "rong" :) });      //枯荣禅功pfm：荣
              u_pfm = u_pfm + ({ (: perform_action, "strike.jiuchong" :) });  //九重天
              set("f_skill", "kurong-changong");
              break;
            case 1:
              u_liumai = str_liumai[random(sizeof(str_liumai))];     //天龙寺高级空手：六脉神剑
              set("env/liumai", u_liumai);
              set("liumai-shenjian/" + u_liumai, 1);
              set_skill("yiyang-zhi", 500);
              set_skill("liumai-shenjian", 500);
              map_skill("finger", "yiyang-zhi");
              nw_parry = "yiyang-zhi";
              prepare_skill("finger", "yiyang-zhi");
              u_pfm = u_pfm + ({ (: perform_action, "finger.sandie" :) });
              u_pfm = u_pfm + ({ (: perform_action, "finger.yizhisanmai" :) });
              //							u_pfm = u_pfm + ({(: perform_action, "qianlong" :)});     
              set("f_skill", "liumai-shenjian");
              break;

          }
          switch (random(2)) {
            case 0:
              set_skill("cihang-bian", 500);          //天龙寺高级兵器：慈航鞭
              set("shen", 5000000);            //need for pfm	
              map_skill("whip", "cihang-bian");
              w_parry = "cihang-bian";
              u_pfm = u_pfm + ({ (: perform_action, "whip.cibei" :) });          //慈航鞭pfm：慈悲字诀
              u_weapon = "whip";
              set("f_w_skill", "cihang-bian");
              break;
            case 1:
              set_skill("pangen-fu", 500);           //天龙寺高级兵器：盘根错结斧
              map_skill("axe", "pangen-fu");
              w_parry = "pangen-fu";
              u_pfm = u_pfm + ({ (: perform_action, "axe.jingtian" :) });         //盘根错结斧pfm：惊天断云斧
              u_weapon = "axe";
              set("f_w_skill", "pangen-fu");
              break;
          }
          break;
      }
      break;  //end case tls		

    case "sl":
      set("family/family_name", "少林派");
      set_skill("yijin-jing", 500);             //少林内功：易筋经
      set_skill("shaolin-shenfa", 500);            //少林轻功：少林身法
      set_skill("buddhism", 200);              //少林杂项：禅宗心法
      map_skill("force", "yijin-jing");
      map_skill("dodge", "shaolin-shenfa");
      u_pfm = u_pfm + ({ (: exert_function, "jingang" :) });          //易筋经pfm：金刚不坏体神功
      switch (in_level) {
        case 0:
          switch (random(8)) {
            case 0:
              set_skill("fengyun-shou", 500);                               //少林低级空手：风云手
              map_skill("hand", "fengyun-shou");
              nw_parry = "fengyun-shou";
              prepare_skill("hand", "fengyun-shou");
              set("f_skill", "fengyun-shou");
              break;
            case 1:
              set_skill("yingzhua-gong", 500);                              //少林低级空手：鹰爪功
              map_skill("claw", "yingzhua-gong");
              nw_parry = "yingzhua-gong";
              prepare_skill("claw", "yingzhua-gong");
              set("f_skill", "yingzhua-gong");
              break;
            case 2:
              set_skill("mohe-zhi", 500);                                //少林低级空手：摩诃指
              map_skill("finger", "mohe-zhi");
              nw_parry = "mohe-zhi";
              prepare_skill("finger", "mohe-zhi");
              set("f_skill", "mohe-zhi");
              break;
            case 3:
              set_skill("jimie-zhua", 500);                               //少林低级空手：寂灭爪
              map_skill("claw", "jimie-zhua");
              nw_parry = "jimie-zhua";
              prepare_skill("claw", "jimie-zhua");
              set("f_skill", "jimie-zhua");
              break;
            case 4:
              set_skill("shaolin-tantui", 500);                              //少林低级空手：少林弹腿
              map_skill("leg", "shaolin-tantui");
              nw_parry = "shaolin-tantui";
              prepare_skill("leg", "shaolin-tantui");
              set("f_skill", "shaolin-tantui");
              break;
            case 5:
              set_skill("weituo-zhang", 500);                               //少林低级空手：韦陀掌
              map_skill("strike", "weituo-zhang");
              nw_parry = "weituo-zhang";
              prepare_skill("strike", "weituo-zhang");
              set("f_skill", "weituo-zhang");
              break;
            case 6:
              set_skill("luohan-quan", 500);                               //少林低级空手：罗汉拳
              map_skill("cuff", "luohan-quan");
              nw_parry = "luohan-quan";
              prepare_skill("cuff", "luohan-quan");
              set("f_skill", "luohan-quan");
              break;
            case 7:
              set_skill("sanhua-zhang", 500);             //少林低级空手：散花掌
              set_skill("nianhua-zhi", 500);                               //少林低级空手：拈花指
              map_skill("strike", "sanhua-zhang");
              map_skill("finger", "nianhua-zhi");
              prepare_skill("strike", "sanhua-zhang");
              prepare_skill("finger", "nianhua-zhi");
              nw_parry = "nianhua-zhi";
              u_pfm = u_pfm + ({ (: perform_action, "strike.sanhua" :) });
              u_pfm = u_pfm + ({ (: perform_action, "finger.fuxue" :) });
              set("f_skill", "sanhua-zhang");         //散花掌pfm：四季散花
              set("f_skill2", "nianhua-zhi");         //拈花指pfm：拈花拂穴

              break;

          }
          switch (random(8)) {
            case 0:
              set_skill("xiuluo-dao", 500);                                 //少林低级兵器：修罗刀 
              map_skill("blade", "xiuluo-dao");
              w_parry = "xiuluo-dao";
              u_weapon = "blade";
              set("f_w_skill", "xiuluo-dao");
              break;
            case 1:
              set_skill("pudu-zhang", 500);                                 //少林低级兵器：普渡杖
              map_skill("staff", "pudu-zhang");
              w_parry = "pudu-zhang";
              u_weapon = "staff";
              set("f_w_skill", "pudu-zhang");
              break;
            case 2:
              set_skill("zui-gun", 500);                                 //少林低级兵器：少林醉棍
              map_skill("club", "zui-gun");
              apply_condition("drunk", 300);
              w_parry = "zui-gun";
              u_weapon = "club";
              u_pfm = u_pfm + ({ (: perform_action, "club.zuijiu" :) });   //少林醉棍pfm：八仙醉打
              set("f_w_skill", "zui-gun");
              break;
            case 3:
              set_skill("damo-jian", 500);                                 //少林低级兵器：达摩剑
              map_skill("sword", "damo-jian");
              w_parry = "damo-jian";
              u_weapon = "sword";
              set("f_w_skill", "damo-jian");
              break;
            case 4:
              set_skill("weituo-gun", 500);                                 //少林低级兵器：韦陀棍
              map_skill("club", "weituo-gun");
              w_parry = "weituo-gun";
              u_weapon = "club";
              set("f_w_skill", "weituo-gun");
              break;
            case 5:
              set_skill("cibei-dao", 500);                                 //少林低级兵器：慈悲刀
              map_skill("blade", "cibei-dao");
              w_parry = "cibei-dao";
              u_weapon = "blade";
              set("f_w_skill", "cibei-dao");
              break;
            case 6:
              set_skill("fumo-jian", 500);                                 //少林低级兵器：伏魔剑	
              map_skill("sword", "fumo-jian");
              w_parry = "fumo-jian";
              u_weapon = "sword";
              set("f_w_skill", "fumo-jian");
              break;
            case 7:
              set_skill("wuchang-zhang", 500);                                //少林低级兵器：无常杖
              map_skill("staff", "wuchang-zhang");
              w_parry = "wuchang-zhang";
              u_weapon = "staff";
              set("f_w_skill", "wuchang-zhang");
              break;
          }
          break;
        case 1:
          switch (random(4)) {
            case 0:
              set_skill("yizhi-chan", 500);          //少林高级空手：一指禅
              set_skill("longzhua-gong", 500);          //少林高级空手：龙爪功
              map_skill("claw", "longzhua-gong");
              map_skill("finger", "yizhi-chan");
              prepare_skill("claw", "longzhua-gong");
              prepare_skill("finger", "yizhi-chan");
              nw_parry = "yizhi-chan";
              u_pfm = u_pfm + ({ (: perform_action, "finger.wofo" :) });      //一指禅pfm：皈依我佛
              u_pfm = u_pfm + ({ (: perform_action, "finger.qiankun" :) });   //一指乾坤
              u_pfm = u_pfm + ({ (: perform_action, "claw.canyun" :) });    //龙爪功pfm：风卷残云
              set("f_skill", "yizhi-chan");
              set("f_skill2", "longzhua-gong");
              break;
            case 1:
              set_skill("ruying-suixingtui", 500);         //少林高级空手：如影随形腿
              set_skill("qianye-shou", 500);          //少林高级空手：如来千叶手
              map_skill("leg", "ruying-suixingtui");
              map_skill("hand", "qianye-shou");
              prepare_skill("leg", "ruying-suixingtui");
              prepare_skill("hand", "qianye-shou");
              nw_parry = "qianye-shou";
              u_pfm = u_pfm + ({ (: perform_action, "hand.qianshou" :) });      //如来千叶手pfm：千手如来
              u_pfm = u_pfm + ({ (: perform_action, "leg.ruying" :) });       //如影随形腿pfm：如影随形
              set("f_skill", "ruying-suixingtui");
              set("f_skill2", "qianye-shou");
              break;
            case 2:
              set_skill("jingang-quan", 500);          //少林高级空手：大金刚拳
              map_skill("cuff", "jingang-quan");
              set_skill("banruo-zhang", 500);          //少林高级空手：般若掌
              map_skill("strike", "banruo-zhang");
              nw_parry = "banruo-zhang";
              prepare_skill("strike", "banruo-zhang");
              prepare_skill("cuff", "jingang-quan");
              u_pfm = u_pfm + ({ (: perform_action, "strike.chaodu" :) });    //般若掌pfm：超度连环诀
              if (random(5) == 1)
                u_pfm = u_pfm + ({ (: perform_action, "strike.yipai" :) });     //一拍两散
                u_pfm = u_pfm + ({ (: perform_action, "cuff.fumo" :) });       //大金刚拳pfm：金刚伏魔
                set("f_skill", "jingang-quan");
              set("f_skill2", "banruo-zhang");
              break;
            case 3:
              set_skill("wuxiang-zhi", 500);          //少林高级空手：无相劫指
              map_skill("finger", "wuxiang-zhi");
              prepare_skill("finger", "wuxiang-zhi");
              nw_parry = "wuxiang-zhi";
              u_pfm = u_pfm + ({ (: perform_action, "finger.qiankun" :) });   //无相劫指pfm：袖里乾坤
              set("f_skill", "wuxiang-zhi");
              break;
          }
          switch (random(3)) {
            case 0:
              set_skill("riyue-bian", 500);          //少林高级兵器：日月鞭法
              map_skill("whip", "riyue-bian");
              w_parry = "riyue-bian";
              u_pfm = u_pfm + ({ (: perform_action, "whip.fumoquan" :) });         //日月鞭法pfm：金刚伏魔圈
              u_pfm = u_pfm + ({ (: perform_action, "whip.chanrao" :) });         //天缠地绕 
              u_weapon = "whip";
              set("f_w_skill", "riyue-bian");
              break;
            case 1:
              set_skill("ranmu-daofa", 500);          //少林高级兵器：燃木刀法
              map_skill("blade", "ranmu-daofa");
              w_parry = "ranmu-daofa";
              u_pfm = u_pfm + ({ (: perform_action, "blade.fentian" :) });   //燃木刀法pfm：举火焚天
              u_pfm = u_pfm + ({ (: perform_action, "blade.fenwo" :) });         //焚我
              //							u_pfm = u_pfm + ({(: perform_action, "blade.fenxin" :)});        	//焚心 需要木刀才能发
              u_weapon = "blade";
              set("f_w_skill", "ranmu-daofa");
              break;
            case 2:
              set_skill("weituo-chu", 500);          //少林高级兵器：韦陀杵
              map_skill("club", "weituo-chu");
              w_parry = "weituo-chu";
              u_pfm = u_pfm + ({ (: perform_action, "club.leidong" :) });   //韦陀杵pfm：雷动九天
              u_pfm = u_pfm + ({ (: perform_action, "club.chaodu" :) });         //超度极乐 
              u_weapon = "club";
              set("f_w_skill", "weituo-chu");
              break;
          }
          break;
      }
      break;  //end case sl	
    case "kl":
      set("family/family_name", "昆仑派");
      set_skill("xuantian-wuji", 500);             //昆仑内功：玄天无极功
      set_skill("taxue-wuhen", 500);             //昆仑轻功：踏雪无痕
      set_skill("art", 200);               //昆仑杂项：琴棋书画	
      map_skill("force", "xuantian-wuji");
      map_skill("dodge", "taxue-wuhen");
      u_pfm = u_pfm + ({ (: exert_function, "hanbing" :) });          //玄天无极功pfm：寒冰
      u_pfm = u_pfm + ({ (: exert_function, "juhan" :) });            //聚寒
      switch (in_level) {
        case 0:
          switch (random(2)) {
            case 0:
              set_skill("chuanyun-tui", 500);                              //昆仑低级空手：穿云腿
              map_skill("leg", "chuanyun-tui");
              nw_parry = "chuanyun-tui";
              prepare_skill("leg", "chuanyun-tui");
              set("f_skill", "chuanyun-tui");
              break;
            case 1:
              set_skill("zhentian-quan", 500);                              //昆仑低级空手：震天拳
              map_skill("cuff", "zhentian-quan");
              nw_parry = "zhentian-quan";
              prepare_skill("cuff", "zhentian-quan");
              set("f_skill", "zhentian-quan");
              break;

          }
          switch (random(1)) {
            case 0:
              set_skill("xunlei-jian", 500);                                //昆仑低级兵器：迅雷剑
              map_skill("sword", "xunlei-jian");
              w_parry = "xunlei-jian";
              u_weapon = "sword";
              set("f_w_skill", "xunlei-jian");
              break;
          }
          break;
        case 1:
          switch (random(1)) {
            case 0:
              set_skill("kunlun-zhang", 500);          //昆仑高级空手：昆仑掌法
              map_skill("strike", "kunlun-zhang");
              nw_parry = "kunlun-zhang";
              prepare_skill("strike", "kunlun-zhang");
              u_pfm = u_pfm + ({ (: perform_action, "strike.diezhang" :) });     //昆仑掌法pfm：昆山叠掌
              set("f_skill", "kunlun-zhang");
              break;
          }
          switch (random(1)) {
            case 0:
              set_skill("liangyi-jian", 500);         //昆仑高级兵器：两仪剑法	
              map_skill("sword", "liangyi-jian");
              w_parry = "liangyi-jian";
              //							u_pfm = u_pfm + ({(: perform_action, "sword.hebi" :)});        	//两仪剑法pfm：双剑合壁 
              u_weapon = "sword";
              set("f_w_skill", "liangyi-jian");
              break;
          }
          break;
      }
      break;  //end case kl	
    case "9y":
      set("family/family_name", "九阴真经传人");
      set_skill("jiuyin-zhengong", 500);            //九阴内功：九阴真功	
      set_skill("jiuyin-shenfa", 500);             //九阴轻功：九阴身法	
      set_skill("daode-jing", 200);
      map_skill("force", "jiuyin-zhengong");
      map_skill("dodge", "jiuyin-shenfa");
      u_pfm = u_pfm + ({ (: exert_function, "yihuen" :) });
      u_pfm = u_pfm + ({ (: exert_function, "zongjue" :) });          //九阴总诀
      u_pfm = u_pfm + ({ (: perform_action, "dodge.huanyinbu" :) });          //九阴身法pfm：幻阴步
      switch (in_level) {
        case 0:
          switch (random(2)) {
            case 0:
              set_skill("jiuyin-baiguzhua", 500);                              //九阴低级空手：九阴白骨爪
              map_skill("claw", "jiuyin-baiguzhua");
              nw_parry = "jiuyin-baiguzhua";
              prepare_skill("claw", "jiuyin-baiguzhua");
              u_pfm = u_pfm + ({ (: perform_action, "claw.jiuyin" :) });   //九阴白骨爪pfm：九阴三绝爪
              set("f_skill", "jiuyin-baiguzhua");
              break;
            case 1:
              set_skill("cuixin-zhang", 500);                               //九阴低级空手：摧心掌
              map_skill("strike", "cuixin-zhang");
              nw_parry = "cuixin-zhang";
              prepare_skill("strike", "cuixin-zhang");
              u_pfm = u_pfm + ({ (: perform_action, "strike.cuixin" :) });
              set("f_skill", "cuixin-zhang");              //摧心掌pfm：催心断肠
              break;

          }
          switch (random(1)) {
            case 0:
              set_skill("yinlong-bian", 500);                                 //九阴低级兵器：九阴银龙鞭
              map_skill("whip", "yinlong-bian");
              w_parry = "yinlong-bian";
              u_pfm = u_pfm + ({ (: perform_action, "whip.chanrao" :) });       //九阴银龙鞭pfm：缠绕诀
              u_pfm = u_pfm + ({ (: perform_action, "whip.feilong" :) });        //飞龙  
              u_weapon = "whip";
              set("f_w_skill", "yinlong-bian");
              break;
          }
          break;
        case 1:
          switch (random(3)) {
            case 0:
              set_skill("jiuyin-shenzhang", 500);        //九阴高级空手：九阴神掌
              map_skill("strike", "jiuyin-shenzhang");
              nw_parry = "jiuyin-shenzhang";
              prepare_skill("strike", "jiuyin-shenzhang");
              u_pfm = u_pfm + ({ (: perform_action, "strike.shenzhang" :) });   //九阴神掌pfm：神掌夺魄
              u_pfm = u_pfm + ({ (: perform_action, "strike.yinyang" :) });  //阴阳双掌   
              set("f_skill", "jiuyin-shenzhang");
              break;
            case 1:
              set_skill("jiuyin-shenzhua", 500);        //九阴高级空手：九阴神爪
              map_skill("claw", "jiuyin-shenzhua");
              nw_parry = "jiuyin-shenzhua";
              prepare_skill("claw", "jiuyin-shenzhua");
              u_pfm = u_pfm + ({ (: perform_action, "strike.sanjue" :) });      //九阴神爪pfm：九阴三绝爪
              set("f_skill", "jiuyin-shenzhua");
              break;
            case 2:
              set_skill("dafumo-quan", 500);            //九阴高级空手：大伏魔拳
              map_skill("cuff", "dafumo-quan");
              nw_parry = "dafumo-quan";
              prepare_skill("cuff", "dafumo-quan");
              u_pfm = u_pfm + ({ (: perform_action, "cuff.fumo" :) });       //大伏魔拳pfm：伏魔 
              set("f_skill", "dafumo-quan");
              break;
          }
          switch (random(1)) {
            case 0:
              set_skill("xuanyin-jian", 500);         //九阴高级兵器：玄阴剑法	
              map_skill("sword", "xuanyin-jian");
              w_parry = "xuanyin-jian";
              u_pfm = u_pfm + ({ (: perform_action, "sword.xuanyin" :) });      //玄阴剑法pfm：玄阴诀 	
              u_pfm = u_pfm + ({ (: perform_action, "sword.zhan" :) });   //斩字诀	
              u_weapon = "sword";
              set("f_w_skill", "xuanyin-jian");
              break;
          }
          break;
      }
      break;  //end case 9y		
    case "hmg":
      set("family/family_name", "蛤蟆功传人");
      set_skill("hamagong", 500);
      map_skill("force", "hamagong");
      map_skill("strike", "hamagong");
      prepare_skill("strike", "hamagong");
      nw_parry = "hamagong";
      set("oyf/hamagong", 3);
      u_pfm = u_pfm + ({ (: perform_action, "strike.hama" :) });
      u_pfm = u_pfm + ({ (: exert_function, "nizhuan" :) });
      set("f_skill", "hamagong");

      break;  //end hmg
    case "pxj":
      set("family/family_name", "东方不败的传人");
      set_skill("pixie-jian", 500);
      set_skill("hanbing-zhenqi", 500);     //嵩山内功：寒冰真气			
      map_skill("force", "hanbing-zhenqi");
      map_skill("dodge", "pixie-jian");
      map_skill("sword", "pixie-jian");
      u_pfm = u_pfm + ({ (: exert_function, "hanbing" :) });   //寒冰真气pfm：寒冰
      u_pfm = u_pfm + ({ (: exert_function, "juhan" :) });     //聚寒
      u_pfm = u_pfm + ({ (: perform_action, "sword.cimu" :) });
      u_pfm = u_pfm + ({ (: perform_action, "dodge.feiying" :) });
      u_pfm = u_pfm + ({ (: perform_action, "sword.jue" :) });
      w_parry = "pixie-jian";
      u_weapon = "xiuhua";
      set("f_w_skill", "pixie-jian");
      break;  //end pxj
    case "jsj":
      set("family/family_name", "金蛇剑法的传人");
      set_skill("zixia-gong", 500);        //华山内功：紫霞功
      set_skill("huashan-shenfa", 500);       //华山轻功：华山身法				
      set_skill("jinshe-jianfa", 500);
      set_skill("jinshe-zhangfa", 500);
      map_skill("force", "zixia-gong");
      map_skill("dodge", "huashan-shenfa");
      map_skill("sword", "jinshe-jianfa");
      map_skill("strike", "jinshe-zhangfa");
      prepare_skill("strike", "jinshe-zhangfa");
      nw_parry = "jinshe-zhangfa";
      w_parry = "jinshe-jianfa";
      set("f_w_skill", "jinshe-jianfa");
      set("f_skill", "jinshe-zhangfa");
      u_weapon = "sword";
      u_pfm = u_pfm + ({ (: perform_action, "sword.kuangwu" :) });


      break;  //end jsj
  }  //end whole switch


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
    u_pfm = u_pfm + ({ (: perform_action, "blade.duan" :) });
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
    set("chat_msg_combat", u_pfm);
  }

  //记录obejct所用的空手招架和兵器招架以及使用的武器，在需要改变时可以调用
  set("w_parry", w_parry);
  set("nw_parry", nw_parry);
  set("u_weapon", u_weapon);

  return 1;
}
