// wujiang.c 武将

inherit NPC;
#include "die.h"

void create()
{
	set_name("御前侍卫", ({ "yuqian shiwei", "shiwei" }));
	set("gender", "男性");
	set("age", random(10) + 30);
	set("str", 25);
	set("dex", 16);
	set("long", "他是一名御前侍卫，正在这里巡逻。\n");
	set("combat_exp", 750000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("unarmed", 200);
	set_skill("force", 200);
	set_skill("spear", 200);
	set_skill("yangjia-qiang", 200);
	set_skill("dodge", 200);
	set_skill("parry", 200);

	map_skill("spear", "yangjia-qiang");
	map_skill("parry", "yangjia-qiang");

	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 30);

	set("neili", 4000); 
	set("max_neili", 4000);
	set("jiali", 10);

	setup();
	carry_object("/clone/weapon/changqiang")->wield();
	carry_object("/d/city/npc/obj/tiejia")->wear();
}

int bow(object me)
{
	command("bow "+me->query("id"));
}

int bow2(object me)
{
	message_vision("$N上前验明了$n的身份，给予放行。道：“职责所在，大人还请见谅。”\n",this_object(),me);
}
int bow3(object me)
{
	message_vision("$N上前验明了$n的穿宫令牌，发现正是御林军统领核发，之后给予放行。道：“职责所在，大人还请见谅。”\n",this_object(),me);
}
int forbid()
{
	if (time()-query("forbid")>60)
	{
		set("forbid",time());
		command("say 竟敢带外人入宫，下次再犯，定斩不赦！");
		return 1;
	}
}