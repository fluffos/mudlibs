// by snowcat  11/22/1997

inherit NPC;

string *names = ({
  "摇铃水客",
  "江湖骗子",
  "卖菜妇女",
  "闲人",
  "路人",
  "苦行僧",
  "脚夫",
  "艺人",
});

string *ids = ({
  "yaoling shuike",
  "jianghu pianzi",
  "maicai funu",
  "xuan ren",
  "lu ren",
  "kuxing sen",
  "jiao fu",
  "yi ren",
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
  int k,i = random(sizeof(names));
  set_name(names[i], ({ids[i]}));
  set("gender", genders[i]);
  k = 1+random(9);
  set("age", 20+random(20));
  set("attitude", "friendly");
  set("shen_type", 1);
  set("people", "people");
  set("force_factor",2);
  set_skill("unarmed",i*10);
  set_skill("dodge",i*10);
  set_skill("parry",i*10);
  set("chat_chance", 5);
  set("chat_msg", ({ (: random_move :) }));
  setup();
  carry_object("/d/obj/cloth/linen")->wear();
  add_money("silver", random(3));
}


