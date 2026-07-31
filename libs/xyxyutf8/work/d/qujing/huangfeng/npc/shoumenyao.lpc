// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/npc/shoumenyao.c

#include <ansi.h>
inherit NPC;

void create()
{
  set_name("守门妖", ({"shoumen yao", "yao", "shou men", "shoumen"}));
  set("long","一个虎头虎脑的小妖，看上去傻乎乎的。\n");
  set("gender", "男性");
  set("age", 20+random(15));
  set_level(41);
  set("attitude", "peaceful");
  set("shen_type", 1);
  set_skill("unarmed",410);
  set_skill("parry",410);
  set_skill("dodge",410);
  set_skill("blade",410);
  set_skill("bingpo-blade",410);
  map_skill("blade", "bingpo-blade");
  map_skill("parry", "bingpo-blade");

  setup();
  carry_object("/d/obj/weapon/blade/blade")->wield();
  carry_object("/d/obj/armor/tenjia")->wear();
}