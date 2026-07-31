#include <ansi.h>

inherit NPC;

void create()
{
  set_name("蒙云",({ "meng yun", "dizi","girl" }) );
  set("gender", "女性" );
  set("title",YEL+"粉金刚"+NOR);
  set("long", "白云庵弟子之一,专门看管那些偷窥的人.\n");
  set("age", 15+random(10));
  set("attitude", "peaceful");
  set("str", 50);
  set("per", 50);
  set("combat_exp",340000);
  set("force",500);
  set("max_force",500);
  set("force_factor", 100);
  set("max_gin", 400);
  set("max_kee", 400);
  set("max_sen", 400);
  set("inquiry",([
  "出去":"要想过去,先过了我这关.\n",
  ]));
  set_skill("unarmed",150);
  set_skill("dodge",150);
  set_skill("parry",150);
  set_skill("whip",150);
  set_skill("force",150);
	set_temp("apply/attack",220);
	set_temp("apply/defense",220);
	set_temp("apply/armor",220);
	set("max_neili",500+random(5550));
	set("max_jing",500+random(5550));
		set("max_qi",500+random(5550));	

  
  set("chat_chance",6);
  set("chat_msg",({
  "蒙云说道:我最恨那些无赖流氓了.\n",
  "蒙云嘿嘿一笑,到了这里,想出去就难了.\n",
  "蒙云道:要想出去,得先过了我这关.\n",
}));

  setup();
  carry_object("/d/hainan/obj/triger_cloth")->wear();
  carry_object("/d/hainan/obj/whip")->wield();
}
