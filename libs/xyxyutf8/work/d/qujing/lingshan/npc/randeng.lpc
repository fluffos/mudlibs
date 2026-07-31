// snowcat 12 14 1997

inherit NPC;

int give_book ();

void create()
{
  set_name("燃灯古佛", ({ "randeng gufo", "randeng", "gufo" }));
  set_level(179);
  set("title", "灵山");
  set("gender", "男性");
  set("age", 1000);
  set("attitude", "peaceful");
  set("force_factor", 100);
  set("mana_factor", 100);

  set_skill("literate",1790);
  set_skill("spells",1790);
  set_skill("buddhism",1790);
  set_skill("unarmed",1790);
  set_skill("jienan-zhi",1790);
  set_skill("dodge",1790);
  set_skill("lotusmove",1790);
  set_skill("parry",1790);
  set_skill("force",1790);
  set_skill("lotusforce",1790);
  set_skill("staff",1790);
  set_skill("lunhui-zhang",1790);
  map_skill("spells", "buddhism");
  map_skill("unarmed", "jienan-zhi");
  map_skill("dodge", "lotusmove");
  map_skill("force", "lotusforce");
  map_skill("parry", "lunhui-zhang");
  map_skill("staff", "lunhui-zhang");
  set_skill("tianlong-chanchang",1790);
  
  set("chat_chance_combat", 80);
  set("chat_msg_combat", ({
   (: cast_spell, "bighammer" :),
  }) );
  setup();
  carry_object("/d/obj/cloth/jia_sha")->wear();
}
