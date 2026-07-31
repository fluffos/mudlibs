// by snowcat oct 22 1997

inherit NPC;

string *names = ({
  "路人",
  "小贩",
  "女佣",
  "商人",
  "读书人",
  "官客",
  "僧侣",
  "道人",
});

string *ids = ({
  "lu ren",
  "xiao fan",
  "nu yong",
  "shang ren",
  "dushu ren",
  "guan ke",
  "seng lu",
  "dao ren",
});

string *genders = ({
  "男性",
  "男性",
  "女性",
  "男性",
  "男性",
  "男性",
  "男性",
  "男性",
});

void create()
{
  int i = random(sizeof(names));
  set_name(names[i], ({ids[i]}));
  set("gender", genders[i]);
  i = 1+random(9);
  set_level(9);
  set("age", 20+random(20));
  set("per", 14+random(20));
  set("attitude", "friendly");
  set("shen_type", 1);
  set("people", "people");
  set("force_factor",2);
  set_skill("unarmed", i*10);
  set_skill("dodge", i*10);
  set_skill("parry", i*10);
  set("chat_chance", 8);
  set("chat_msg", ({ (: random_move :) }));
  setup();
  carry_object("/d/qujing/chechi/obj/changpao")->wear();
  add_money("silver", random(5));
}


