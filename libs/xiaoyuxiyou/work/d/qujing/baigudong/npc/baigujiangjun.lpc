// writted by smile 12/09/1998
#include <ansi.h>

inherit NPC;

void create()
{
  set_name("白骨将军", ({"baigu jiangjun", "jiangjun"}));
  set("gender", "男性");
  set_level(49);
  set("age", 55);
  set("per",10);
  set("attitude", "friendly");
  set_skill("dodge",490);
  set_skill("parry",490);
  set_skill("force",490);
  set_skill("spells",490);
  set_skill("sword", 110);
  set_skill("gouhunshu",490);
  set_skill("tonsillit",490);
  set_skill("ghost-steps",490);
  set_skill("zhuihun-sword",90);
  map_skill("force", "tonsillit");
  map_skill("spells", "gouhunshu");
  map_skill("sword", "zhuihun-sword");
  set("eff_dx",-50000);
  set("nkgain",400);
  set("force_factor", 60);
  set("mana_factor", 60);
  set("chat_chance_combat",25);
  set("chat_msg_combat", ({
		(: cast_spell, "gouhun" :),
  }) );

  setup();
  carry_object("/d/qujing/baigudong/obj/gusword")->wield();
  carry_object("/d/obj/armor/gujia")->wear();
}
