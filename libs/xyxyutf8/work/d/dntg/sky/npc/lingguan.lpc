inherit NPC;

void create()
{
  set_name("灵官",({"ling guan","guan"}));
  set("gender", "男性");
  set("age", 25);
  set("long", "佑圣真君手下灵官，忠心赤胆，骁勇无比。\n");
  set_level(120);
  set("attitude", "heroism");
  set("class", "xian");
  set("daoxing", 1000000);
  set("force_factor", 100);
  set("mana_factor", 80);

  set_skill("dodge", 1200);
  set_skill("baguazhen", 1200);
  set_skill("force", 1200);
  set_skill("tonsillit", 1200);
  set_skill("spells", 1200);
  set_skill("taiyi", 1200);
  set_skill("unarmed", 1200);
  set_skill("wuxing-quan", 1200);
  set_skill("parry", 1200);
  set_skill("whip", 1200);
  set_skill("hellfire-whip", 1200);

map_skill("dodge", "baguazhen");
map_skill("force", "tonsillit");
map_skill("spells", "taiyi");
map_skill("unarmed", "wuxing-quan");
map_skill("parry", "hellfire-whip");
map_skill("whip", "hellfire-whip");
set("chat_chance_combat", 60);
set("chat_msg_combat", ({
      (: perform_action, "whip", "lunhui" :),
  }) );

setup();
carry_object("/d/obj/armor/tongjia")->wear();
carry_object("/d/obj/weapon/whip/pibian")->wield();
}
