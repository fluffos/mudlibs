// snowcat 12 14 1997

inherit NPC;

void create()
{
  if (random(2))
  {
    set_name("比丘僧", ({ "biqiu seng", "biqiu", "seng" }));
    set("gender", "男性");
  }
  else
  {
    set_name("比丘尼", ({ "biqiu ni", "biqiu", "ni" }));
    set("gender", "女性");
  }
  set("title", "灵山");
  set("age", 80);
  set_level(49);
  set("attitude", "peaceful");
  set("force_factor", 60);
  set("mana_factor", 60);

  set_skill("spells", 490);
  set_skill("buddhism", 490);
  set_skill("unarmed", 490);
  set_skill("jienan-zhi", 490);
  set_skill("dodge", 490);
  set_skill("lotusmove", 490);
  set_skill("parry", 490);
  set_skill("force", 490);
  set_skill("lotusforce", 490);
  set_skill("staff", 490);
  set_skill("lunhui-zhang", 490);
  map_skill("spells", "buddhism");
  map_skill("unarmed", "jienan-zhi");
  map_skill("dodge", "lotusmove");
  map_skill("force", "lotusforce");
  map_skill("parry", "lunhui-zhang");
  map_skill("staff", "lunhui-zhang");
  
  setup();
  carry_object("/d/obj/cloth/jia_sha")->wear();
}