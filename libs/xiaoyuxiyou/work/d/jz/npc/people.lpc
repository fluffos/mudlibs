//Cracked by Roath
inherit NPC;
string *names = ({
  "逛街的",
  "说书的",
  "买东西的",
  "喝茶的",
  "听戏的",
  "吹牛的",
  "赌钱的",
});

string *ids = ({
    "man",
    "man",
    "seller",
    "man",
    "man",
    "man",
    "man",
});

string *genders = ({
  "男性",
 "男性",
  "女性",
  "男性",
  "男性",
  "男性",
  "男性",

});

void create()
{
  int k,i = random(sizeof(names));
  k = 1+random(10);
  set_name(names[i], ({ids[i]}));
  set("gender", genders[i]);
  set_level(k);
  set("age", 20+random(20));
  set("per", 14+random(20));
  set("attitude", "friendly");
  set("shen_type", 1);
  set("people", "people");
  set("force_factor",2);
  set_skill("unarmed",k*10);
  set_skill("dodge",k*10);
  set_skill("parry",k*10);
  set("chat_chance", 8);
  set("chat_msg", ({ (: random_move :) }));
  setup();
  carry_object(0,"cloth",random(2))->wear();
  add_money("silver", 1+random(5));
}
