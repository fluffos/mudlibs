//Mine Job Place.h
//Created By ChinaNet
//By 2004/1/11
//Modified 2004/2/1 By ChinaNet
//Modified 2004/3/10 by ChinaNet
//Modified 2004/4/27 By ChinaNet fixed address bug

#include <ansi.h>
#include <regions.h>

string *wheres_easy = ({
  "/d/emei/guanyinqiao", "/d/emei/basipan3", "/d/emei/caopeng",
  "/d/wudang/xiaolu2",
  "/d/songshan/suishilu3", "/d/songshan/suishilu4", "/d/songshan/suishilu1", "/d/songshan/suishilu2",
  "/d/songshan/shidao1", "/d/songshan/shidao2", "/d/songshan/shidao3",
  "/d/songshan/shanlu5", "/d/songshan/shanlu4", "/d/songshan/shanlu3", "/d/songshan/shanlu2", "/d/songshan/shanlu1",
  "/d/xiangyang/outeroad1", "/d/xiangyang/zhuquemen", "/d/xiangyang/hanshui1",
  "/d/chengdu/sroad1", "/d/chengdu/tulu1", "/d/chengdu/tulu2", "/d/chengdu/tulu3", "/d/chengdu/wroad1", "/d/chengdu/wroad2", "/d/chengdu/eroad1", "/d/chengdu/eroad2",
  "/d/hengshan/shandao1", "/d/hengshan/shandao2", "/d/hengshan/jijiaoshi", "/d/hengshan/kutianjing",
  "/d/city/eroad1", "/d/city/eroad2",
  "/d/tiezhang/hclu", "/d/tiezhang/shanmen",
});
string *wheres_normal = ({
  "/d/jiaxing/nanhu", "/d/jiaxing/tieqiang", "/d/hz/longjing", "/d/hz/huanglongdong", "/d/hz/tianxianglou", "/d/hz/longjing",
  "/d/emei/basipan3", "/d/emei/basipan2", "/d/emei/basipan1",
  "/d/emei/shierpan", "/d/emei/shierpan2", "/d/emei/shierpan3", "/d/emei/shierpan4",
  "/d/tiezhang/hclu-2", "/d/tiezhang/hclu-3", "/d/tiezhang/hclu-4", "/d/tiezhang/hclu-5", "/d/tiezhang/hclu-6",
  "/d/xueshan/xuelu2", "/d/xueshan/houzidong", "/d/xueshan/shanlu7",
  "/d/huanghe/shulin1", "/d/huanghe/shulin2", "/d/huanghe/shulin3", "/d/huanghe/shulin4", "/d/huanghe/shulin5", "/d/huanghe/shulin6",
});
string *wheres_hard = ({
  "/d/shaolin/stoneroad1", "/d/shaolin/sblu-2", "/d/shaolin/sblu-3", "/d/mr/xiaojing1-2", "/d/shaolin/stoneroad2",
  "/d/shaolin/stoneroad4", "/d/shaolin/sblu-1",
  "/d/shaolin/stoneroad3",
  "/d/shaolin/shijie1", "/d/shaolin/shijie2", "/d/shaolin/shijie3", "/d/shaolin/shijie4", "/d/shaolin/shijie5",
  "/d/shaolin/shijie6", "/d/shaolin/shijie7", "/d/shaolin/shijie8", "/d/shaolin/shijie9", "/d/shaolin/shijie10",
  "/d/city/wroad2", "/d/city/wroad3", "/d/city/wroad1",
  "/d/dali/dalisouth/shanlu6", "/d/dali/dalieast/shanlu7", "/d/dali/wuliang/shanlu5",
  "/d/dali/wuliang/shanlu8", "/d/dali/wuliang/shanlu10",
  "/d/dali/wuliang/shanlu11", "/d/dali/wuliang/shanlu12", "/d/dali/wuliang/shanlu13",
  "/d/tiezhang/shanlu-2", "/d/tiezhang/shanlu-3", "/d/tiezhang/shanlu-4", "/d/tiezhang/shanlu-5", "/d/tiezhang/shanlu-6",
  "/d/tiezhang/shanlu-7", "/d/tiezhang/shanlu-8", "/d/tiezhang/shanlu-9",
});
string *wheres_veryhard = ({
  "/d/huanghe/shamo",
  "/d/xingxiu/shamo3",
  "/d/emei/gudelin3",
  "/d/emei/lengshanlin2",
  "/d/mr/xiaojing1-1", "/d/mr/xiaojing1-2", "/d/mr/xiaojing1-3", "/d/mr/xiaojing1-4",
  "/d/mr/xiaojing2", "/d/mr/xiaojing3", "/d/mr/xiaojing4", "/d/mr/xiaojing5", "/d/mr/xiaojing6", "/d/mr/xiaojing7",
  "/d/mingjiao/ljroad1", "/d/mingjiao/ljroad2", "/d/mingjiao/ljroad3",
  "/d/mingjiao/didao/senlin-1", "/d/mingjiao/didao/senlin-2", "/d/mingjiao/didao/senlin-3", "/d/mingjiao/didao/senlin-4",
  "/d/mingjiao/didao/senlin-5", "/d/mingjiao/didao/senlin-6", "/d/mingjiao/didao/senlin-7", "/d/mingjiao/didao/senlin-8",
  "/d/xingxiu/xxh2",
  "/d/fuzhou/road1", "/d/fuzhou/road2", "/d/fuzhou/road3", "/d/fuzhou/road4", "/d/fuzhou/road5",
  "/d/hz/changlang2", "/d/hz/changlang1",
  "/d/foshan/road14",
});

//铁，铜，锌，银，铝，铅，镁，磷，锰，锡
string *NORMAL_B_NAME = ({
  HIW "铁矿石" NOR, HIW "铜矿石" NOR, HIW "锌矿石" NOR, HIW "银矿石" NOR, HIW "铝矿石" NOR, HIW "镁矿石" NOR, HIW "铅矿石" NOR,
  HIW "磷矿石" NOR, HIW "锰矿石" NOR, HIW "锡矿石" NOR, HIW "钨矿石" NOR, HIW "钼矿石" NOR, HIW "铋矿石" NOR, HIW "硫矿石" NOR,
});

string *NORMAL_B_LONG = ({
  HIW "一块黑色的铁矿石，看起来有些许用处。\n" NOR, HIR "一块红色的铜矿石，看起来有些许用处。\n" NOR, HIW "一块白色的锌矿石，看起来有些许用处。\n" NOR, HIW "一块黑色的银矿石，看起来有些许用处。\n" NOR, HIW "一块白色的铝矿石，看起来有些许用处。\n" NOR, HIW "一块白色的镁矿石，看起来有些许用处。\n" NOR, HIW "一块黑色的铅矿石，看起来有些许用处。\n" NOR,
  HIW "一块白色的磷矿石，看起来有些许用处。\n" NOR, HIW "一块黑色的锰矿石，看起来有些许用处。\n" NOR, HIW "一块黑色的锡矿石，看起来有些许用处。\n" NOR, HIW "一块黑色的钨矿石，看起来有些许用处。\n" NOR, HIW "一块黑色的钼矿石，看起来有些许用处。\n" NOR, HIW "一块黑色的铋矿石，看起来有些许用处。\n" NOR, HIW "一块黑色的硫矿石，看起来有些许用处。\n" NOR,
});

string *NORMAL_B_MATERIAL = ({
  "普通石头", "普通石头", "普通石头", "普通石头", "普通石头", "普通石头", "普通石头",
  "普通石头", "普通石头", "普通石头", "普通石头", "普通石头", "普通石头", "普通石头",
});

string *HARD_B_NAME = ({
  //卤化物
  HIW "萤石" NOR, HIW "石盐" NOR, HIW "钾石盐" NOR,
  //自然矿物
  HIW "金刚石" NOR, HIW "石墨" NOR, HIW "自然金" NOR,
  //氧化物
  HIY "刚玉" NOR, HIY "赤铁矿" NOR, HIY "磁铁矿" NOR, HIY "锡石" NOR, HIY "石英" NOR,
  HIY "软锰矿" NOR, HIY "金红石" NOR, HIY "尖晶石" NOR, HIY "黑钨矿" NOR, HIY "褐铁矿" NOR,
  //硫化物
  HIC "方铅矿" NOR, HIC "闪锌矿" NOR, HIC "辰砂" NOR, HIC "黄铜矿" NOR, HIC "黄铁矿" NOR,
  HIC "辉锑矿" NOR, HIC "雌黄" NOR, HIC "雄黄" NOR, HIC "辉钼矿" NOR, HIC "毒砂" NOR,
  //含氧盐
  HIW "橄榄石" NOR, HIW "方解石" NOR, HIW "白云石" NOR, HIW "孔雀石" NOR, HIW "蓝铜矿" NOR,
  HIW "重晶石" NOR, HIW "石膏" NOR, HIW "白钨矿" NOR, HIW "磷灰石" NOR, HIW "绿柱石" NOR,
  HIW "电气石" NOR, HIW "绿泥石" NOR, HIW "蛇纹石" NOR, HIW "石棉" NOR, HIW "黄玉" NOR,
  HIW "高岭石" NOR, HIW "正长石" NOR, HIW "斜长石" NOR, HIW "普通辉石" NOR, HIW "普通角闪石" NOR,
  HIW "云母" NOR, HIW "滑石" NOR, HIW "石榴子石" NOR, HIW "锆石" NOR, HIW "白榴石" NOR,
  HIW "天青石" NOR, HIW "十字石" NOR, HIW "红柱石" NOR, HIW "霞石" NOR, HIW "蛭石" NOR,
});

string *HARD_B_LONG = ({
  //卤化物
  HIR "一块透着红色的石头，看起来很值钱的样子。\n" NOR, HIR "一块透着红色的石头，看起来很值钱的样子。\n" NOR, HIR "一块透着红色的石头，看起来很值钱的样子。\n" NOR,
  //自然矿物
  HIW "一块白色的石头，看起来很值钱的样子。\n" NOR, HIW "一块白色的石头，看起来很值钱的样子。\n" NOR, HIW "一块白色的石头，看起来很值钱的样子。\n" NOR,
  //氧化物
  HIR "一块透着红色的石头，看起来很值钱的样子。\n" NOR, HIR "一块透着红色的石头，看起来很值钱的样子。\n" NOR, HIR "一块透着红色的石头，看起来很值钱的样子。\n" NOR, HIR "一块透着红色的石头，看起来很值钱的样子。\n" NOR, HIR "一块透着红色的石头，看起来很值钱的样子。\n" NOR,
  HIR "一块透着红色的石头，看起来很值钱的样子。\n" NOR, HIR "一块透着红色的石头，看起来很值钱的样子。\n" NOR, HIR "一块透着红色的石头，看起来很值钱的样子。\n" NOR, HIR "一块透着红色的石头，看起来很值钱的样子。\n" NOR, HIR "一块透着红色的石头，看起来很值钱的样子。\n" NOR,
  //硫化物
  HIW "一块闪着亮光的东西，看起来很值钱的样子。\n" NOR, HIW "一块闪着亮光的东西，看起来很值钱的样子。\n" NOR, HIW "一块闪着亮光的东西，看起来很值钱的样子。\n" NOR, HIW "一块闪着亮光的东西，看起来很值钱的样子。\n" NOR, HIW "一块闪着亮光的东西，看起来很值钱的样子。\n" NOR,
  HIW "一块闪着亮光的东西，看起来很值钱的样子。\n" NOR, HIW "一块闪着亮光的东西，看起来很值钱的样子。\n" NOR, HIW "一块闪着亮光的东西，看起来很值钱的样子。\n" NOR, HIW "一块闪着亮光的东西，看起来很值钱的样子。\n" NOR, HIW "一块闪着亮光的东西，看起来很值钱的样子。\n" NOR,
  //含氧盐
  HIR "一块透出暗红色光芒的矿砂，看起来很值钱的样子。\n" NOR, HIR "一块透出暗红色光芒的矿砂，看起来很值钱的样子。\n" NOR, HIR "一块透出暗红色光芒的矿砂，看起来很值钱的样子。\n" NOR, HIR "一块透出暗红色光芒的矿砂，看起来很值钱的样子。\n" NOR, HIR "一块透出暗红色光芒的矿砂，看起来很值钱的样子。\n" NOR,
  HIR "一块透出暗红色光芒的矿砂，看起来很值钱的样子。\n" NOR, HIR "一块透出暗红色光芒的矿砂，看起来很值钱的样子。\n" NOR, HIR "一块透出暗红色光芒的矿砂，看起来很值钱的样子。\n" NOR, HIR "一块透出暗红色光芒的矿砂，看起来很值钱的样子。\n" NOR, HIR "一块透出暗红色光芒的矿砂，看起来很值钱的样子。\n" NOR,
  HIR "一块透出暗红色光芒的矿砂，看起来很值钱的样子。\n" NOR, HIR "一块透出暗红色光芒的矿砂，看起来很值钱的样子。\n" NOR, HIR "一块透出暗红色光芒的矿砂，看起来很值钱的样子。\n" NOR, HIR "一块透出暗红色光芒的矿砂，看起来很值钱的样子。\n" NOR, HIR "一块透出暗红色光芒的矿砂，看起来很值钱的样子。\n" NOR,
  HIR "一块透出暗红色光芒的矿砂，看起来很值钱的样子。\n" NOR, HIR "一块透出暗红色光芒的矿砂，看起来很值钱的样子。\n" NOR, HIR "一块透出暗红色光芒的矿砂，看起来很值钱的样子。\n" NOR, HIR "一块透出暗红色光芒的矿砂，看起来很值钱的样子。\n" NOR, HIR "一块透出暗红色光芒的矿砂，看起来很值钱的样子。\n" NOR,
  HIR "一块透出暗红色光芒的矿砂，看起来很值钱的样子。\n" NOR, HIR "一块透出暗红色光芒的矿砂，看起来很值钱的样子。\n" NOR, HIR "一块透出暗红色光芒的矿砂，看起来很值钱的样子。\n" NOR, HIR "一块透出暗红色光芒的矿砂，看起来很值钱的样子。\n" NOR, HIR "一块透出暗红色光芒的矿砂，看起来很值钱的样子。\n" NOR,
  HIR "一块透出暗红色光芒的矿砂，看起来很值钱的样子。\n" NOR, HIR "一块透出暗红色光芒的矿砂，看起来很值钱的样子。\n" NOR, HIR "一块透出暗红色光芒的矿砂，看起来很值钱的样子。\n" NOR, HIR "一块透出暗红色光芒的矿砂，看起来很值钱的样子。\n" NOR, HIR "一块透出暗红色光芒的矿砂，看起来很值钱的样子。\n" NOR,
});

string *HARD_B_MATERIAL = ({
  "卤化物", "卤化物", "卤化物",
  "自然矿物", "自然矿物", "自然矿物",
  "氧化物", "氧化物", "氧化物", "氧化物", "氧化物",
  "氧化物", "氧化物", "氧化物", "氧化物", "氧化物",
  "硫化物", "硫化物", "硫化物", "硫化物", "硫化物",
  "硫化物", "硫化物", "硫化物", "硫化物", "硫化物",
  "含氧盐", "含氧盐", "含氧盐", "含氧盐", "含氧盐",
  "含氧盐", "含氧盐", "含氧盐", "含氧盐", "含氧盐",
  "含氧盐", "含氧盐", "含氧盐", "含氧盐", "含氧盐",
  "含氧盐", "含氧盐", "含氧盐", "含氧盐", "含氧盐",
  "含氧盐", "含氧盐", "含氧盐", "含氧盐", "含氧盐",
  "含氧盐", "含氧盐", "含氧盐", "含氧盐", "含氧盐",
});

string *VERYHARD_B_NAME = ({
  //钻石
  HIW "钻石" NOR,
  //绿宝石
  HIG "祖母绿" NOR, HIG "金绿宝石" NOR, HIG "猫眼石" NOR, HIG "变石" NOR, HIG "海蓝宝石" NOR, HIG "绿宝石" NOR,
  //玉石
  HIG "翡翠" NOR, HIG "软玉" NOR, HIG "欧泊" NOR, HIG "绿松石" NOR, HIG "青金石" NOR,
  HIG "玛瑙石" NOR, HIG "独山玉" NOR, HIG "孔雀石" NOR, HIG "木变石" NOR, HIG "虎睛石" NOR,
  //红宝石
  HIR "红宝石" NOR,
  //宝石
  HIR "碧玺" NOR, HIR "尖晶石" NOR, HIR "石榴石" NOR, HIR "黄玉石" NOR,
  HIR "锆石" NOR, HIR "橄榄石" NOR, HIR "水晶石" NOR, HIR "长石" NOR,

});

string *VERYHARD_B_LONG = ({
  //钻石
  HIW "一颗着耀眼光芒的钻石，看起来价值连城。\n" NOR,
  //绿宝石
  HIG "一颗隐约露出暗绿色光芒的宝石，看起来价值连城。\n" NOR,
  HIG "一颗隐约露出暗绿色光芒的宝石，看起来价值连城。\n" NOR,
  HIG "一颗隐约露出暗绿色光芒的宝石，看起来价值连城。\n" NOR,
  HIG "一颗隐约露出暗绿色光芒的宝石，看起来价值连城。\n" NOR,
  HIG "一颗隐约露出暗绿色光芒的宝石，看起来价值连城。\n" NOR,
  HIG "一颗隐约露出暗绿色光芒的宝石，看起来价值连城。\n" NOR,
  //玉石	
  HIG "一颗隐约露出暗绿色光芒的宝石，看起来价值连城。\n" NOR,
  HIG "一颗隐约露出暗绿色光芒的宝石，看起来价值连城。\n" NOR,
  HIG "一颗隐约露出暗绿色光芒的宝石，看起来价值连城。\n" NOR,
  HIG "一颗隐约露出暗绿色光芒的宝石，看起来价值连城。\n" NOR,
  HIG "一颗隐约露出暗绿色光芒的宝石，看起来价值连城。\n" NOR,
  HIG "一颗隐约露出暗绿色光芒的宝石，看起来价值连城。\n" NOR,
  HIG "一颗隐约露出暗绿色光芒的宝石，看起来价值连城。\n" NOR,
  HIG "一颗隐约露出暗绿色光芒的宝石，看起来价值连城。\n" NOR,
  HIG "一颗隐约露出暗绿色光芒的宝石，看起来价值连城。\n" NOR,
  HIG "一颗隐约露出暗绿色光芒的宝石，看起来价值连城。\n" NOR,
  //红宝石
  HIR "一颗隐约露出暗红色光芒的宝石，看起来价值连城。\n" NOR,
  //宝石
  HIR "一颗普通的宝石，看起来价值连城。\n" NOR,
  HIR "一颗普通的宝石，看起来价值连城。\n" NOR,
  HIR "一颗普通的宝石，看起来价值连城。\n" NOR,
  HIR "一颗普通的宝石，看起来价值连城。\n" NOR,
  HIR "一颗普通的宝石，看起来价值连城。\n" NOR,
  HIR "一颗普通的宝石，看起来价值连城。\n" NOR,
  HIR "一颗普通的宝石，看起来价值连城。\n" NOR,
  HIR "一颗普通的宝石，看起来价值连城。\n" NOR,
});

string *VERYHARD_B_MATERIAL = ({
  "钻石",
  "绿宝石", "绿宝石", "绿宝石", "绿宝石", "绿宝石", "绿宝石",
  "玉石", "玉石", "玉石", "玉石", "玉石",
  "玉石", "玉石", "玉石", "玉石", "玉石",
  "红宝石",
  "宝石", "宝石", "宝石", "宝石", "宝石", "宝石", "宝石", "宝石",
});


string get_address(string level, object me) {
  string str;
  switch (level) {
    case "easy":
      str = wheres_easy[random(sizeof(wheres_easy))];
      break;
    case "normal":
      str = wheres_normal[random(sizeof(wheres_normal))];
      break;
    case "hard":
      str = wheres_hard[random(sizeof(wheres_hard))];
      break;
    case "veryhard":
      str = wheres_veryhard[random(sizeof(wheres_veryhard))];
      break;
    default:
      str = "area error";
  }
  return str;
}

string get_place(string str) {
  string *place = explode(str, "/");

  str = "";
  if (place[0] == "d") {
    str = sub_region_names[place[2]];
    if (!str)
      str = region_names[place[1]];
  }
  return str;
}

int get_value(object me, object mine) {
  //	int value;

  if (!me || !mine) return 0;
}

object settings_mine(string level, object mine) {
  int i, value;
  string m_name, m_long, m_material;

  if (!mine)
    return 0;

  //初始化
  mine->set("level", level);
  mine->set("unit", "块");
  mine->set("weight", 800);
  mine->set("long", "这是一块普通的矿石。\n");
  mine->set("no_get", "这块矿石这么重，你搬不起来。\n");
  mine->set("no_drop", "别乱扔石头，砸到人怎么办？\n");
  mine->set("material", "stone");
  mine->set("minejob", 1);
  mine->set("value", 5000);

  switch (level) {
    case "normal":
      i = random(sizeof(NORMAL_B_NAME));
      m_name = NORMAL_B_NAME[i];
      m_long = NORMAL_B_LONG[i];
      m_material = NORMAL_B_MATERIAL[i];
      value = 30000 + random(30000);
      break;
    case "hard":
      i = random(sizeof(HARD_B_NAME));
      m_name = HARD_B_NAME[i];
      m_long = HARD_B_LONG[i];
      m_material = HARD_B_MATERIAL[i];
      value = 200000 + random(30000);
      break;
    case "veryhard":
      i = random(sizeof(VERYHARD_B_NAME));
      m_name = VERYHARD_B_NAME[i];
      m_long = VERYHARD_B_LONG[i];
      m_material = VERYHARD_B_MATERIAL[i];
      value = 500000 + random(50000);
      mine->set("unique", 1);
      break;
  }
  mine->set("name", m_name);
  mine->set("long", m_long);
  mine->set("value", value);
  mine->set("material", m_material);

  return mine;
}

//给予奖励的类型
string check_happy(object me, object mine, int i) {
  int jiangli;
  string msg;

  if (!mine || !me) return 0;

  jiangli = mine->query("value") / 500;
  switch (i) {
    case 1:
      me->add("potential", jiangli);
      msg = "你额外获得了" + CHINESE_D->chinese_number(jiangli) + "点潜能的奖励。\n";
      break;
    case 2:
      me->add("combat_exp", jiangli);
      msg = "你额外获得了" + CHINESE_D->chinese_number(jiangli) + "点经验的奖励。\n";
      break;
    case 3:
      me->add("balance", jiangli * 10000);
      msg = "恭喜，你额外获得了" + MONEY_D->price_str(jiangli * 10000) + "的奖励，已经存进了你的帐户。\n";
      break;
    case 4:
      jiangli = jiangli * 10 + random(jiangli * 10);
      me->improve_skill("mining", jiangli);
      msg = "你额外获得了" + CHINESE_D->chinese_number(jiangli) + "点技能奖励。\n";
      break;
    case 5:
      me->set_skill("mining", me->query_skill("mining", 1) + 1);
      msg = "恭喜，你额外获得了一级的采矿技能。\n";
      break;
    default:
      msg = "你此次任务并无额外的奖励。\n";
      break;
  }
  return msg;
}

//决定给予何种奖励。
int check_encour(object me) {
  int times, failed_times, mine_skill, exp, encour;

  times = me->query("minejob");
  failed_times = me->query("minejob_failed");
  mine_skill = me->query_skill("mining", 1);
  exp = me->query("combat_exp");

  if (times > 500
    && failed_times < 200
    && mine_skill > 200
    && mine_skill < 400
    && random(5) == 1)
    encour = 5;
  else if (times > 300
    && failed_times < 200
    && mine_skill > 150
    && random(5) > 3)
    encour = 4;
  else if (times > 200
    && failed_times < 200
    && mine_skill > 100
    && random(5) > 3)
    encour = 3;
  else if (times > 100
    && failed_times < 200
    && mine_skill > 50
    && random(5) > 3)
    encour = 2;
  else encour = 1;

  return encour;
}
//check 矿石等级
string check_level(object me) {
  string place_level;

  if (random(me->query("kar")) > 18
    && me->query_con() > 30
    && me->query_str() > 30
    && me->query_int() > 30
    && random(me->query_con()) > 20
    && random(me->query_str()) > 20
    && random(20) > 17)
    place_level = "veryhard";

  else if (random(me->query("kar")) > 15
    && me->query_con() > 35
    && me->query_str() > 35
    && me->query_int() > 25
    && random(me->query_con()) > 18
    && random(me->query_str()) > 18
    && random(20) > 14)
    place_level = "hard";

  else if (me->query_con() > 30
    && me->query_str() > 30
    && me->query_int() > 30
    && random(me->query_con()) > 16
    && random(me->query_str()) > 16)
    place_level = "normal";
  else
    place_level = "easy";

  return place_level;
}

//check 是否出现抢劫
int check_killer(string place_level) {
  int killer;
  switch (place_level) {
    case "veryhard": killer = 1; break;
    case "hard":
      if (random(20) > 5)
        killer = 1;
      break;
    case "normal":
      if (random(20) > 10)
        killer = 1;
      break;
    case "easy":
      if (random(20) > 15)
        killer = 1;
      break;
    default: killer = 0; break;
  }
  return killer;
}
