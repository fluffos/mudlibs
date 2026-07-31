// created 12/5/1997 by snowcat
#include <ansi.h>

inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
  set_name("道士", ({"dao shi", "xie gong", "xie", "shi"}));
  set("title", "百脚蝎公");
  set("gender", "男性");
  set("age", 80);
  set("attitude", "aggressive");
  set("combat_exp", 3600000);
  set("combat_exp", 2000000);

  set_skill("dodge", 260);
  set_skill("parry", 260);
  set_skill("force", 260);
  set_skill("spells", 260);
  set_skill("unarmed", 260);


  set("eff_dx",-4300000);
  set("nkgain",400);

  set("max_jing", 3800);
  set("max_qi", 3800);
  set("max_jing", 3800);
  set("neili", 3800);
  set("max_neili", 3800);
  set("neili", 3800);
  set("max_neili", 3800);
//  set("force_factor", 30);
  set("mana_factor", 90);

  setup();
  initlvl((500+random(500)),18);
  carry_object("/d/obj/cloth/shoupiqun")->wear();
}

