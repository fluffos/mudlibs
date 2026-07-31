// created 11/20/1997 by snowcat

inherit NPC;

void create()
{
  set_name("美后", ({ "mei hou", "hou", "queen" }));
  set("title", "比丘国");   
  set("long", "一位娇俊无比，貌似观音的王后。\n");
  set("gender", "女性");
  set("age", 17);
  set_level(55);
  set("attitude", "heroism");
  set("force_factor", 60);
  set("mana_factor", 60);

  set_skill("dodge",550);
  set_skill("parry",550);
  set_skill("force",550);
  set_skill("spells",550);
  set_skill("unarmed",550);
  set_skill("staff",550);
  set_skill("gouhunshu",550);
  set_skill("tonsillit",550);
  set_skill("ghost-steps",550);
  set_skill("jienan-zhi",550);
  set_skill("lunhui-zhang",550);
  map_skill("unarmed", "jienan-zhi");
  map_skill("force", "tonsillit");
  map_skill("spells", "gouhunshu");
  map_skill("staff", "lunhui-zhang");
  setup();
  carry_object("/d/obj/cloth/gongpao")->wear();
  carry_object("/d/qujing/biqiu/obj/ring")->wear();
  carry_object("/d/qujing/biqiu/obj/neck")->wear();
  carry_object("/d/qujing/biqiu/obj/wrists")->wear();
}
