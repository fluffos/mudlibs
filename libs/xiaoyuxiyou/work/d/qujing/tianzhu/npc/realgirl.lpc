// created 11/22/1997 by snowcat
#include <ansi.h>

inherit NPC;

void create()
{
  set_name("公主", ({"gong zhu", "zhu", "princess"}));
  set("title", "天竺国");
  set_level(43);
  set("gender", "女性");
  set("age", 30);
  set("attitude", "peaceful");
  set_skill("dodge",430);
  set_skill("parry",430);
  set_skill("force",430);
  set_skill("spells",430);
  set_skill("unarmed",430);
  set_skill("staff",430);
  set_skill("moonshentong",430);
  set_skill("moonforce",430);
  set_skill("moondance",430);
  set_skill("baihua-zhang",430);
  map_skill("unarmed", "baihua-zhang");
  map_skill("force", "moonforce");
  map_skill("spells", "moondance");

  set("force_factor", 30);
  set("mana_factor", 30);
  setup();
  carry_object("/d/obj/cloth/linen")->wear();
}
