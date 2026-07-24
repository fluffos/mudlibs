//created by yekai for axtj
#define YEKAI_GEN "/d/wiz/gift/gen/"
#define YEKAI_BUG "/d/wiz/gift/bug/"

#define JIERI_E 0
#define JIERI_LIWU 1
#define FIXLOC "系统公告室"
nosave mapping gift_type = ([
  "春节"    :  ({"chunjie" , YEKAI_GEN"gift_spring"}) ,
  "端午节"  :  ({"duanwu"  , YEKAI_GEN"gift_duanwu"}) ,
  "劳动节"  :  ({"laodong" , YEKAI_GEN"gift_labor" }) ,
  "儿童节"  :  ({"ertong"  , YEKAI_GEN"gift_child" }) ,
  "建党节"  :  ({"jiandang", YEKAI_GEN"gift_party" }) ,
  "七夕"    :  ({"qixi"    , YEKAI_GEN"gift_qixi"  }) ,
  "建军节"  :  ({"jianjun" , YEKAI_GEN"gift_army"  }) ,
  "中秋节"  :  ({"zhongqiu", YEKAI_GEN"gift_autum" }) ,
  "重阳节"  :  ({"chongyang",YEKAI_GEN"gift_chongyang"}),
  "元旦"    :  ({"yuandan" , YEKAI_GEN"gift_year"  }) ,
  "清明节"  :  ({"qingming", YEKAI_GEN"gift_qingming"}),
  "圣诞节"  :  ({"shengdan", YEKAI_GEN"gift_shengdan"}),
  "情人节"  :  ({"lover"   , YEKAI_GEN"gift_lover" }),
  "国庆节"  :  ({"nation"  , YEKAI_GEN"gift_nation"}),
]);
nosave mapping bug_gift = ([
  10     :  YEKAI_BUG"gift_bug0" ,
  20     :  YEKAI_BUG"gift_bug1" ,
  50     :  YEKAI_BUG"gift_bug2" ,
  100    :  YEKAI_BUG"gift_bug3" ,
  150    :  YEKAI_BUG"gift_bug4" ,
  200    :  YEKAI_BUG"gift_bug5" ,
  300    :  YEKAI_BUG"gift_bug6" ,
  400    :  YEKAI_BUG"gift_bug7" ,
  500    :  YEKAI_BUG"gift_bug8" ,
  1000   :  YEKAI_BUG"gift_bug9" ,
]);
nosave mapping tianfu=([
   "str"     : "膂力",
   "cor"     : "胆识",
   "int"     : "悟性",
   "spi"     : "灵性",
   "cps"     : "定力",
   "per"     : "容貌",
   "con"     : "根骨",
   "kar"     : "福缘",
   "dex"     : "敏捷",
]);
int check_bug_level(int bug_want)
{
  int *bug_value ;
  int i;
  bug_value = sort_array(keys(bug_gift), 1);
  for (i = 1; i <= sizeof(bug_value); i++)
    if (bug_want < bug_value[i])
      break;
  return i;
}