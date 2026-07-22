// by snowcat oct 24 1997

inherit NPC;

string *names = ({
  "大少爷",
  "二少爷",
  "小少爷",
  "大痞子",
  "小痞子",
  "小官人",
  "大公子",
  "二公子",
  "少公子",
  "花公子",
  "浪公子",
  "公子",
  "王孙",
});

string *ids = ({
  "da shaoye",
  "er shaoye",
  "xiao shaoye",
  "da pizi",
  "xiao pizi",
  "xiao guanren",
  "da gongzi",
  "er gongzi",
  "shao gongzi",
  "hua gongzi",
  "lang gongzi",
  "gongzi",
  "wang sun",
});

void create()
{
  int i = random(sizeof(names));
  set_name(names[i], ({ids[i]}));
  set("gender", "男性");
  i = 1+random(9);
  set_level(i);
  set("age", 20+random(9));
  set("per", 14+random(20));
  set("attitude", "friendly");
  set("shen_type", 1);
  set("people", "people");
  set("force_factor",2);
  set_skill("unarmed",i*10);
  setup();
  carry_object("/d/qujing/chechi/obj/changpao")->wear();
  add_money("silver", random(5));
}
