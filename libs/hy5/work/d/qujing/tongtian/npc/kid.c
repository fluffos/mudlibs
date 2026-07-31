// by snowcat  11/22/1997

inherit NPC;

void create()
{
  set_name("小童", ({"kid"}));
  if (random(2))
    set("gender", "男性");
  else
    set("gender", "女性");
  set("combat_exp", random(1000));
  set("age", 3+random(5));
  set("per", 14+random(20));
  set("attitude", "friendly");
  set("shen_type", 1);
  set("people", "people");
  set("force_factor",2);
  set("max_jing",1000);
  set("max_qi",1000);
  set("max_jing",1000);
  setup();
  carry_object("/d/obj/cloth/linen")->wear();
}


