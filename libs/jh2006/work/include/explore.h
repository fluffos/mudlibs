//      File    :  /include/explore.h

// 门派对应的数值
#ifndef __EXPLORE__
#define __EXPLORE__
#define EXPLORE_LEVEL 0
#endif
string *titlescolor = ({ HIY, HIR, HIW });

string *dietime = ({ "三天", "两天", "一个月", "五天", "十天", "二十天" });

int Get_Family_Name(object ob, string family)
{
        switch(family){
                case "少林派" : return 1; break;
                case "武当派" : return 2; break;
                case "华山派" : return 3; break;
                case "丐帮"   : return 4; break;
                case "桃花岛" : return 5; break;
                case "星宿派" : return 6; break;
                case "姑苏慕容":return 7; break;
                case "明教"  :  return 8; break;
                case "古墓派" : return 9; break;
                case "峨嵋派" : return 10;break;
                case "全真派" : return 11;break;
        }
}

// 目录对应的中文名称
mapping place = ([
"/d/bdao/" : "冰火岛",
"/d/chengdu/" : "成都",
"/d/city/"  :  "扬州城",
"/d/city2/" :  "北京城",
"/d/death/" :  "地狱",
"/d/diaoyu/" :  "钓鱼岛",
"/d/emei/"  : "峨嵋山",
"/d/gaibang/" : "丐帮",
"/d/gaochang/" : "高昌",
"/d/guiyun/"  : "归云庄",
"/d/gumu/"  : "古墓幽境",
"/d/hmy/" : "黑墓崖",
"/d/huanggon/" : "皇宫",
"/d/huashan/" : "华山",
"/d/jiaxing/" : "嘉兴城",
"/d/liaoguo/" : "辽国",
"/d/mj/" : "明教光明顶",
"/d/murong/" : "慕容山庄",
"/d/npc/"  :  "禁止目录",
"/d/player/" : "禁止目录",
"/d/quanzhou/" : "泉州城",
"/d/quest/" : "禁止目录",
"/d/qz/" : "终南山",
"/d/shaolin/" : "嵩山少林寺",
"/d/shenlong/" : "神龙岛",
"/d/taishan/" : "天山",
"/d/thd/" : "桃花岛",
"/d/village/" : "华山村",
"/d/wizard/" : "禁止目录",
"/d/working/" : "禁止目录",
"/d/wudang/" : "武当山",
"/d/xiangyang/" : "襄阳城",
"/d/xiangyang_old/" : "禁止目录",
"/d/xingxiu/" : "西域星宿海",
"/d/xingxiu_old/"  : "禁止目录",
]);

string *damage_types = ({
  "擦伤",
  "割伤",
  "刺伤",
  "瘀伤",
  "内伤",
  "毒伤",
  "震伤",
  "拉伤",
  "砸伤",
  "抓伤",
  "鞭伤",
  "抽伤",
});

string *families = ({
  "少林派",
  "武当派",
  "丐帮",
  "桃花",
  "星宿派",
  "姑苏慕容",
  "明教",
  "古墓派",
  "峨嵋派",
  "全真派",  
});

