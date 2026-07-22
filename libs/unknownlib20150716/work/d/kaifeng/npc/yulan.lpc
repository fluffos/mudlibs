//雪影 2000/2  解迷九色祥云系统
inherit NPC;
/*
#include <quest_wr.h>
#include <reporting.h>
*/
int test_player();

void create()
{
  set_name("玉兰", ({"yu lan", "yu", "lan"}));
  set("gender", "女性");
  set("age", 25);
  set("per", 28);
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("combat_exp", 4500);
  set_skill("unarmed", 40);
  set_skill("dodge", 40);
  set_skill("parry", 40);
  set_skill("force", 40);
  set_skill("spells", 40);
  set_skill("baihua-zhang", 40);
  set_skill("moondance", 40);
  set_skill("moonshentong", 40);
  map_skill("spells", "moonshentong");
  map_skill("unarmed", "baihua-zhang");
  map_skill("force", "moonforce");
  map_skill("spells", "moonshentong");
  set("max_gin",400);
  set("max_kee",400);
  set("max_sen",400);
  set("max_force",200);
  set("max_mana",200);
  set("force_factor",20);
  set("chat_chance",10);
  set("chat_msg",({
    "玉兰咯咯一笑：首饰鞋冠陆陆续续募捐了不少。\n",
    "玉兰宛尔一笑说道：那些想出嫁的姑娘及娶亲的光棍真有福份也。\n",
    "玉兰又说道：捐了不少了，想出嫁的姑娘们真可以有点嫁妆了。\n",
    "玉兰说：近来捐的鞋冠真多，该让那些期盼的穷光棍们来挑一挑了。\n",
  }));
/*  set("inquiry", ([
        "here":   "此乃高姓兰亭府也，姑娘在此募捐首饰鞋冠。\n",
        "name":   "高家小姐玉兰也。\n",
        "wearing":   (: test_player() :),
        "首饰鞋冠":   (: test_player() :),
        "募捐":   (: test_player() :),
        "首饰":   (: test_player() :),
        "鞋冠":   (: test_player() :),
        "捐":   (: test_player() :),
        "鞋":   (: test_player() :),
        "冠":   (: test_player() :),
      ]));*/
  setup();
  carry_object("/d/obj/cloth/pinkskirt")->wear();
  carry_object("/d/obj/cloth/shoes")->wear();
}
