// created 12/5/1997 by snowcat
#include <ansi.h>

inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
  set_name("道士", ({"dao shi", "xie gong", "xie", "shi"}));
  set("title", "毒尾蝎公");
  set("gender", "男性");
  set("age", 80);
  set("attitude", "aggressive");
  set("combat_exp", 3500000);
  set("combat_exp", 2000000);


  set("eff_dx",-420000);
  set("nkgain",400);

  set("max_jing", 3500);
  set("max_qi", 3500);
  set("max_jing", 3500);
  set("neili", 3500);
  set("max_neili", 3500);
  set("neili", 3500);
  set("max_neili", 3500);
//  set("force_factor", 30);
  set("mana_factor", 90);
  setup();
  initlvl((500+random(500)),19);
  carry_object("/d/obj/cloth/shoupiqun")->wear();
}

