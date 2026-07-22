// snowcat 12 9 1997

inherit NPC;

void create()
{
  set_name("宫兵", ({ "gong bing", "bing" }) );
  set("gender", "男性");
  set("age", 35);
  set_level(32);
  set("daoxing", 20000);

  set("attitude", "heroism");

  set("force_factor", random(50)+25);
  set_skill("unarmed",320);
  set_skill("parry",320);
  set_skill("dodge",320);
  set_skill("blade",320);
  setup();

  carry_object("/d/obj/weapon/blade/wandao")->wield();
  carry_object("/d/qujing/tianzhu/obj/tiekui")->wear();
  carry_object("/d/obj/cloth/zhanpao")->wear();
}