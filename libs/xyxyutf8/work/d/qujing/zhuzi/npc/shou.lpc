// by snowcat oct 15 1997
#include <ansi.h>
inherit NPC;

mixed says()
{
	if( !environment() || !present("pang dianzhu",environment()) )
		return 0;
	if( random(2) )
		say(CYN"瘦店娘对着胖店主「哼」地冷笑一声。\n"NOR);
	else	say(CYN"胖店主轻轻地拥着瘦店娘。\n"NOR);
	return 1;
}

void create()
{
  set_name("瘦店娘", ({"shou dianniang", "dianniang"}));
  set("gender", "女性");
  set_level(4);
  set("age", 30);
  set("per", 34);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 50);
  set("chat_chance",10);
  set("chat_msg",({
  	(: says :),
  }));
  setup();
  carry_object("/d/obj/cloth/nichang")->wear();
}