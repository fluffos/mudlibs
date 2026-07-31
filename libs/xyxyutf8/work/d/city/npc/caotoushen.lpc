#include <ansi.h>
// creat by canoe 
// 打鸟不中的惩罚
inherit NPC;
void create()
{
  set_name("草头神", ({"caotou shen","shen"}));
  set("gender", "男性");
  set_level(55);
  set("age", 20+random(20));
  set("con", 20);
  set("cor", 20);
  set("int", 20);
  set("per", 20);
  set("long", "他是专管这个园林的草头神中的一个。\n");
  set("attitude", "peaceful");
  set("combat_exp", 30000);
   set_skill("dodge", 25+random(30));
    set_skill("unarmed", 25+random(30));
    set_skill("parry", 25+random(30));
  set("force", 200);
  set("max_force", 100);
    set("force_factor", 30);
  set("mana", 200);
  set("max_mana", 100);
  set("mana_factor", 10);
  set_weight(300000);
  setup();
  carry_object(0,"armor",random(10))->wear();
}