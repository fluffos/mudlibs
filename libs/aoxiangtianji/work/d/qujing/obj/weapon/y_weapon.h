#define WDIR "/d/qujing/obj/weapon/"
string *t_weap = ({
  "axe",
  "blade",
  "dagger",
  "fork",
  "hammer",
  "mace",
  "rake",
  "spear",
  "staff",
  "stick",
  "sword",
  "whip",
});
mapping s_weap = ([
  "axe"    : "sanban-axe",
  "blade"  : "wuhu-blade",
  "fork"   : "dingbo-fork",
  "hammer" : "huntian-hammer",
  "mace"   : "wusi-mace",
  "spear"  : "lihua-spear",
  "staff"  : "fumo-staff",
  "stick"  : "puti-stick",
  "sword"  : "sancai-sword",
  "whip"   : "mingwang-whip",
  "rake"   : "skyriver-rake",
]);
//total 4
string *y_axe = ({
  "suigu-axe",
  "yinzui-axe",
  "tieren-axe",
  "kaishan-axe",
});
//total 10
string *y_blade = ({
  "hutou-blade",
  "changu-blade",
  "niutou-blade",
  "tieban-blade",
  "shichan-blade",
  "kanshan-blade",
  "fengbeng-blade",
  "pojie-blade",
  "liuye-blade",
  "xinyue-blade",
});
// total 8
string *y_dagger = ({
   "rengu-dagger",
   "danren-dagger",
   "tiezhua-dagger",
   "niujiao-dagger",
   "taibaici-dagger",
   "chiquehuan-dagger",
   "zhuliaoya-dagger",
   "huguci-dagger",
});
//total 9
string *y_fork = ({
  "baigu-fork",
  "longxu-fork",
  "niujiao-fork",
  "gangtou-fork",
  "lujiao-fork",
  "meihualujiao-fork",
  "xieao-fork",
  "qingtong-fork",
  "huaici-fork",
  "yangshu-fork",
});
//total 7
string *y_hammer = ({
  "babao-hammer",
  "fengu-hammer",
  "qingshi-hammer",
  "tieqiu-hammer",
  "qingsho-hammer",
  "shimu-hammer",
  "fa-hammer",
});
// total 4
string *y_mace = ({
  "gouhun-mace",
  "jingji-mace",
  "niuwei-mace",
  "chihuai-mace",
});
//total 5
string *y_rake = ({
  "qinggu-rake",
  "tiezhua-rake",
  "zhushan-rake",
  "qichi-rake",
  "zhuxing-rake",
});
//total 4
string *y_spear = ({
  "hongying-spear",
  "duanhun-spear",
  "biluo-spear",
  "shuangtou-spear",
});
//total 7
string *y_staff = ({
  "yapi-staff",
  "siming-staff",
  "niutui-staff",
  "huntie-staff",
  "shitui-staff",
  "miechan-staff",
  "kosong-staff",
  "yangshu-staff",
});
//total 5
string *y_stick = ({
  "chaotian-stick",
  "niugu-stick",
  "yuanyang-stick",
  "dagou-stick",
  "shaohuo-stick",
  "yangshu-stick",
});
//total 8
string *y_sword = ({
  "wutou-sword",
  "ziwei-sword",
  "tiebing-sword",
  "huazhu-sword",
  "xiangya-sword",
  "ge-sword",
  "tanghua-sword",
  "ziyun-sword",
  "linggu-sword",
});
//total 9
string *y_whip = ({
  "baijie-whip",
  "bopi-whip",
  "niuwei-whip",
  "tielian-whip",
  "niupi-whip",
  "tiesuo-whip",
  "fengwei-whip",
  "manwei-whip",
  "lupi-whip",
  "liutiao-whip",
});
mapping random_w = ([
  "axe"    : WDIR + element_of(y_axe),
  "blade"  : WDIR + element_of(y_blade),
  "dagger" : WDIR + element_of(y_dagger),
  "fork"   : WDIR + element_of(y_fork),
  "hammer" : WDIR + element_of(y_hammer),
  "mace"   : WDIR + element_of(y_mace),
  "rake"   : WDIR + element_of(y_rake),
  "spear"  : WDIR + element_of(y_spear),
  "staff"  : WDIR + element_of(y_staff),
  "stick"  : WDIR + element_of(y_stick),
  "sword"  : WDIR + element_of(y_sword),
  "whip"   : WDIR + element_of(y_whip),
]);
/*
mapping get_random_w(string type)
{
  mapping w ;
  string wtype;
  w = allocate_mapping(2);

  if (stringp(type))
  {
    w["weapon"] = random_w[type];
    w["skill"] = s_weap[type];
  }
  else
  {
    wtype = element_of(t_weap);
    w["weapon"] = random_w[wtype];
    w["skill"] = s_weap[wtype];
  }

  return w;
}

*/