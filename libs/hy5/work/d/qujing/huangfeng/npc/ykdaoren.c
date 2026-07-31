// created by angell 1/1/2001
// room: /d/qujing/huangfeng/npc/ykdaoren.c
inherit NPC;

void create()
{
  set_name("迎客道人", ({"yingke daoren", "daoren"}));
  set("gender", "男性");
  set("combat_exp", 20000);
  set("age", 30);
  set("per", 25);
  set("attitude", "friendly");
  set("shen_type", 1);
  set("people", "people");
  set("force_factor",5);
  set("max_jing",300);
  set("max_qi",300);
  set("max_jing",300);
  set("max_neili",400);
  set("max_neili",400);
  set_skill("unarmed", 40+random(90));
  set_skill("dodge", 40+random(90));
  set_skill("parry", 40+random(90));
  set_skill("force", 40+random(90));
  setup();
  carry_object("/d/obj/cloth/daopao")->wear();
}


