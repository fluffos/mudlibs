// created 11/5/1997 by snowcat
#include <ansi.h>

inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
  string dir;

  set_name("±·Á¦´óÏÉ", ({"beili daxian", "daxian"}));
  set("gender", "ÄÐÐÔ");
  set("age", 40);
  set("attitude", "peaceful");
  set("combat_exp", 5100000);
  set("combat_exp", 3000000);

  set_skill("dodge", 290);
  set_skill("parry", 290);
  set_skill("force", 290);
  set_skill("spells", 290);
  set_skill("unarmed", 290);
 

  set("max_jing", 3200);
  set("max_qi", 3200);
  set("max_jing", 3200);
  set("neili", 3200);
  set("max_neili", 3200);
  set("neili", 3200);
  set("max_neili", 3200);
  set("force_factor", 15);
  set("mana_factor", 80);
  setup();
       initlvl((180+random(180)),57);
  carry_object("/d/obj/cloth/shoupiqun")->wear();
}

