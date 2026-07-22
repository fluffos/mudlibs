// rewritten by snowcat on 4.12.1997

inherit NPC;

void create()
{
  set_name("弥勒佛祖", ({"mile fozu", "mile", "fozu"}));
  set("gender", "男性");
  set("age", 100);
  set("attitude", "friendly");
  set_level(180);

  set_skill("dodge",1800);
  set_skill("force",1800);
  set_skill("parry",1800);
  set_skill("spells",1800);
  set_skill("staff",1800);
  set_skill("buddhism",1800);
  set_skill("jienan-zhi",1800);
  set_skill("lotusmove",1800);
  set_skill("lunhui-zhang",1800);
  map_skill("unarmed", "jienan-zhi");
  map_skill("dodge", "lotusmove");
  map_skill("spells", "buddhism");
  map_skill("staff", "lunhui-zhang");
  map_skill("parry", "lunhui-zhang");
  set("force_factor",125);
  setup();
  carry_object("/d/obj/cloth/changpao")->wear();

}