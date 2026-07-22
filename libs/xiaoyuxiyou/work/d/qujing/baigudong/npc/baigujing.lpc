// created by smile 12/08/1998
#include <ansi.h>

inherit NPC;

void create()
{
  set_name("白骨精", ({"baigu jing", "jing"}));
  set("title", "白骨夫人");
  set("long",@LONG
    白骨夫人乃是千年白骨精修炼成形，前世是怨死鬼魂不
得超生，修炼成形后，怨恨人类，于是发誓要吃尽天下人。
LONG);
 set("gender", "女性");
 set_level(110);
  set("age", 40);
  set("attitude", "friendly");

  set_skill("dodge", 1100);
  set_skill("parry", 1100);
  set_skill("force", 1100);
  set_skill("spells", 1100);
  set_skill("unarmed", 1100);
  set_skill("stick",1100);
  set_skill("gouhunshu", 1100);
  set_skill("tonsillit", 1100);
  set_skill("ghost-steps", 1100);
  set_skill("jinghun-zhang", 1100);
  set_skill("kusang-bang", 1100);
  map_skill("dodge","ghost-steps");
  map_skill("unarmed", "jinghun-zhang");
  map_skill("force", "tonsillit");
  map_skill("spells", "gouhunshu");
  map_skill("stick", "kusang-bang");
  map_skill("parry", "kusang-bang");
  set("eff_dx",-90000);
  set("nkgain",400);

  set("force_factor", 1100);
  set("mana_factor", 80);
  set("chat_chance_combat",35);
  set("chat_msg_combat", ({
		(: cast_spell, "gouhun" :),
                          }) );
  setup();
  carry_object("/d/qujing/baigudong/obj/renpipifeng")->wear();
  carry_object("/d/qujing/baigudong/obj/baigugun")->wield();
}

void die()
{
  object me=this_object(), gutou;
  message_vision ("\n$N惨叫一声，化成一堆骷髅，散落在地上。\n",me);
  if( environment() )
  {
  	gutou = new("/d/qujing/baigudong/obj/fenkulou");
  	gutou->move(environment());
  }
  destruct(me);
}

void unconcious()
{
	die();
}