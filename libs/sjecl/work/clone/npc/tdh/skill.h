// include for tdh job npc
// by Lklv

#define DE_LVL 120	// 默认npc skill级别
#define DE_GIFT 20	// 默认npc 属性

string s_sword, s_blade, s_club, s_whip, s_staff, s_dodge, weapon;

string *sword_skill = ({
  "damo-jian", "duanjia-jianfa", "fumo-jian",
  "hengshan-jian", "huashan-jianfa", "huifeng-jian",
  "liangyi-jian", "murong-jianfa", "jinshe-jianfa",
  "qingmang-jian", "quanzhen-jianfa", "songshan-jian",
  "taiji-jian", "tianshan-jianfa", "xuantie-jianfa",
  "xuanyin-jian", "xunlei-jian", "yuxiao-jian",
  "yunu-jianfa",
});

string *blade_skill = ({
  "cibei-dao", "fanliangyi-dao", "liuhe-daofa",
  "lieyan-dao", "murong-daofa", "qingmang-jian",
  "ranmu-daofa", "shandian-daofa", "wenjia-daofa",
  "wuhu-duanmendao", "xiuluo-dao", "xuanxu-daofa",
  "xuedao-daofa", "yanxing-daofa",
});

string *staff_skill = ({
  "wuchang-zhang", "fengmo-zhang", "xinyuegong",
});

string *club_skill = ({
  "weituo-chu", "zui-gun", "weituo-gun",
  "xinyuegong",
});

string *whip_skill = ({
  "cihang-bian", "huifeng-bian", "piaomiao-bianfa",
  "riyue-bian", "songyang-bian", "yinsuo-jinling",
});

string *dodge_skill = ({
  "anying-fuxiang", "huashan-shenfa", "shuishangpiao",
  "suibo-zhuliu", "shaolin-shenfa", "tianlong-xiang",
  "tiyunzong", "xiaoyaoyou", "yunu-shenfa",
  "yanling-shenfa", "yufeng-xiang", "youlong-shenfa",
  "zhaixingshu", "zhongyuefeng", "zuibaxian",
});

string *weapon_list = ({
  "chui", "sword", "blade",
  "whip", "gun", "sword",
  "gangzhang", "blade",
});

void copy_npc(object me, object ob, int i) {
  int x;
  float y, j;

  y = me->query("max_pot") - 100;
  j = i / 100.0;
  y = y * j;
  x = to_int(y);

  s_sword = sword_skill[random(sizeof(sword_skill))];
  s_blade = blade_skill[random(sizeof(blade_skill))];
  s_club = club_skill[random(sizeof(club_skill))];
  s_whip = whip_skill[random(sizeof(whip_skill))];
  s_staff = staff_skill[random(sizeof(staff_skill))];
  s_dodge = dodge_skill[random(sizeof(dodge_skill))];
  weapon = weapon_list[random(sizeof(weapon_list))];

  ob->set("max_jing", to_int(me->query("max_jing") * j));
  ob->set("jing", ob->query("max_jing"));
  ob->set("eff_jing", ob->query("max_jing"));
  ob->set("max_qi", to_int(me->query("max_qi") * j));
  ob->set("qi", ob->query("max_qi"));
  ob->set("eff_qi", ob->query("max_qi"));
  ob->set("eff_jingli", to_int(me->query("eff_jingli") * j));
  ob->set("jingli", ob->query("eff_jingli"));
  ob->set("max_neili", to_int(me->query("max_neili") * j));
  ob->set("neili", ob->query("max_neili"));

  ob->set("combat_exp", to_int(me->query("combat_exp") * j));

  ob->set_skill("sword", x);
  ob->set_skill("dodge", x);
  ob->set_skill("cuff", x);
  ob->set_skill("force", x);
  ob->set_skill("parry", x);
  ob->set_skill("blade", x);
  ob->set_skill("hammer", x);
  ob->set_skill("club", x);
  ob->set_skill("staff", x);
  ob->set_skill("whip", x);
  ob->set_skill("xinyuegong", x);
  ob->set_skill("taiji-shengong", x);
  ob->set_skill("taizu-quan", x);
  ob->set_skill("literate", query("int") * 8);

  ob->set_skill(s_sword, x);
  ob->set_skill(s_blade, x);
  ob->set_skill(s_club, x);
  ob->set_skill(s_whip, x);
  ob->set_skill(s_staff, x);
  ob->set_skill(s_dodge, x);

  ob->map_skill("force", "taiji-shengong");
  ob->map_skill("sword", s_sword);
  ob->map_skill("dodge", s_dodge);
  ob->map_skill("parry", "taizuquan");
  ob->map_skill("hammer", "xinyuegong");
  ob->map_skill("blade", s_blade);
  ob->map_skill("club", s_club);
  ob->map_skill("whip", s_whip);
  ob->map_skill("staff", s_staff);
  ob->prepare_skill("cuff", "taizuquan");
  ob->carry_object(BINGQI_D(weapon))->wield();
}
