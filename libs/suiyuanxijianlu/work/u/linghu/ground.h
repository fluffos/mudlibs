// create by five 

#include <ansi.h>

#define DEBUG 0

#define REWARD 16

#define STEP_PREPARE 0
#define STEP_FIGHT   1
#define STEP_FINISH  2

#define MODE_SINGLE_SD 0
#define MODE_SINGLE_LT 1
#define MODE_TEAM_LT   2
#define MODE_TEAM_DZ   3
#define MODE_TEAM_XH   4
string *modes = ({
  "个人散打",
  "个人擂台",
  "门派擂台",
  "门派对阵",
  "门派循环赛",
});
string *mode_hints = ({
  "由任意两名玩家上场较量",
  "玩家依次上场与擂主较量，赢者为新擂主",
  "每门派的选手依次上场打擂，该选手赢了为本门派擂主",
  "每门派的选手按弱强等级分类，各门派间的同级选手较量",
  "每门派的选手依次与别的门派所有选手较量",
});

#define FAMILY_NONE     0
#define FAMILY_SHAOLIN  1
#define FAMILY_WUDANG   2
#define FAMILY_HUASHAN  3
#define FAMILY_GAIBANG  4
#define FAMILY_TAOHUA   5
#define FAMILY_XINGXIU  6
#define FAMILY_RIYUE    7
#define FAMILY_GUSHU    8
#define FAMILY_MINGJIAO 9
#define FAMILY_GUMU     10
#define FAMILY_EMEI     11
#define FAMILY_QUANZ    12

string *families = ({
  "混合门派",
  "少林派",
  "武当派",
  "华山派",
  "丐帮",
  "桃花岛",
  "星宿派",
  "日月神教",
  "姑苏慕容",
  "明教",
  "古墓派",
  "峨嵋派",
  "全真教",  
});


