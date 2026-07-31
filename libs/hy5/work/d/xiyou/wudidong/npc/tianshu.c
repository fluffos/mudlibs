// guanjia.c
// 9-2-97 pickle

inherit NPC;
#include "/d/migong/romnpc2.c"

string expell_me(object me);
void create()
{
  set_name("田鼠精", ({"tian shu", "tian", "shu", "tianshu", "monster"}));
  set("gender", "女性");
  set("age", 23);
  set("long",
"她就是无底洞的大管家。想当年她和玉鼠一齐修仙成了人形，\n"
"但因资质太差，成正果终究是无望。照顾着当年的交情，玉鼠\n"
"安排她做了这洞的管家。\n");
  set("title", "大管家");
  set("cor", 25);
  set("combat_exp", 200000);
  set("combat_exp", 33400000);

  set("attitude", "heroic");
  create_family("陷空山无底洞", 2, "弟子");
  set_skill("literate", 10);

  
  set("str", 30);
  set("per", 30);
  set("max_qi", 300);
  set("max_jing", 300);
  set("neili", 350);
  set("max_neili", 350);
  set("force_factor", 20);
  set("neili", 550);
  set("max_neili", 500);
  set("mana_factor", 25);
  set("inquiry", ([

		   "name": "本姑娘就是这无底洞的大总管！",
		   "here": "你瞎了眼啦？这里就是鼎鼎大名的陷空山无底洞！",
		   "rumors": "不知道！找别人问去。",
		   "人肉包子": "你瞎了眼啦？本姑娘又不是厨子！",
                 ]) );  
  setup();
  initlvl((550+random(550)),32);  
  carry_object("/d/obj/weapon/blade/blade.c")->wield();
  carry_object("/d/obj/cloth/yuanxiang")->wear();
  carry_object("/d/obj/cloth/nichang")->wear();
}

