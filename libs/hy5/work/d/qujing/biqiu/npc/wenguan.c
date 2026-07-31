// by snowcat oct 22 1997

inherit NPC;

void create()
{
  set_name("ÎÄ¹Ù", ({"wen guan", "guan"}));
  set("gender", "ÄĞĞÔ");
  set("combat_exp", 50000);
  set("age", 50);
  set("attitude", "friendly");
  set("shen_type", 1);
  set("force_factor",5);
  set("max_jing",400);
  set("max_qi",400);
  set("max_jing",400);
  set("max_neili",400);
  set("max_neili",400);
  set_skill("unarmed", 30);
  set_skill("dodge", 30);
  set_skill("parry", 30);
  set_skill("force", 30);
  set_skill("spells", 30);
  setup();
  carry_object("/d/qujing/chechi/obj/gongpao")->wear();
}

