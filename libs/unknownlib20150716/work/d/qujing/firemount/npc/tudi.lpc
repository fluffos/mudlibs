// rewritten by snowcat on 4.12.1997

inherit NPC;

void create()
{
  set_name("土地", ({"tudi","tu di"}));
  set("gender", "男性");
  set("age", 100);
  set("long","专管火焰山方园八百里的老土地爷爷。"+
      "他本是老君兜率宫中看炉的道士，因失职而被罚下凡界。\n");
  set("attitude", "friendly");
  set_level(80);
  set("daoxing", 100000);
  set("no_nk_reward",1);

  set("per", 25);
  set_skill("dodge", 800);
  set("force_factor",25);
  set_skill("spells",600);
  set_skill("stick",600);
  setup();
  carry_object("/d/gao/obj/changpao")->wear();
  add_money("coin", 100);
}