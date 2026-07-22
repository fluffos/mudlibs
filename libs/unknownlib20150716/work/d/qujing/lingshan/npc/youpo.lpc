// snowcat 12 14 1997

inherit NPC;

void create()
{
  if (random(2))
  {
    set_name("优婆塞", ({ "youpo sai", "youpo", "sai" }));
    set("gender", "男性");
  }
  else
  {
    set_name("优婆夷", ({ "youpo yi", "youpo", "yi" }));
    set("gender", "女性");
  }
  set("title", "灵山");
  set_level(129);
  set("age",1290);
  set("attitude", "peaceful");
  set("force_factor", 40);
  set("mana_factor", 40);

  set_skill("spells",1290);
  set_skill("buddhism",1290);
  set_skill("unarmed",1290);
  set_skill("jienan-zhi",1290);
  set_skill("dodge",1290);
  set_skill("lotusmove",1290);
  set_skill("parry",1290);
  set_skill("force",1290);
  set_skill("lotusforce",1290);
  set_skill("staff",1290);
  set_skill("lunhui-zhang",1290);
  map_skill("spells", "buddhism");
  map_skill("unarmed", "jienan-zhi");
  map_skill("dodge", "lotusmove");
  map_skill("force", "lotusforce");
  map_skill("parry", "lunhui-zhang");
  map_skill("staff", "lunhui-zhang");
  

  setup();
  carry_object("/d/obj/cloth/jia_sha")->wear();
}