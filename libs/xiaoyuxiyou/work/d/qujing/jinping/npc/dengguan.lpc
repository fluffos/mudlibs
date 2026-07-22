#include <ansi.h>
inherit NPC;

mixed says ()
{
  string *msgs = ({
    "金灯缸里灯火一闪。\n",
    "金灯缸里的灯火被风一吹，跳了一下。\n",
    "灯火闪了一闪。\n",
    "灯火在缸里跳了一下。\n",
  });
  say(msgs[random(sizeof(msgs))]);
  return 1;
}

void create()
{
  	set_name("灯官", ({ "deng guan", "guan" }) );
  	set("gender", "男性");
  	set("age", 40);
  	set_level(8);
  	set("attitude", "heroism");
	set("chat_chance",8);
	set("chat_msg",({
  		(: says :),
	}) );
	
  	set_skill("unarmed", 40);
  	set_skill("parry", 40);
  	set_skill("dodge", 40);
  	set_skill("blade", 40);

  setup();

  carry_object("/d/obj/cloth/changpao")->wear();
  carry_object("/d/obj/weapon/blade/jidao")->wield();
}