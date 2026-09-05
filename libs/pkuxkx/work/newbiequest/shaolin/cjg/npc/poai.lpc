// poai.c 破爱 黄眉僧二徒弟 天龙八部人物
// 这里借做黄眉僧的跟班。

#include <ansi.h>

inherit NPC;

void create()
{
	seteuid(getuid());
	set_name("破爱", ({ "po ai", "po", "seng" }) );
	set("title", YEL "黄眉僧二徒弟" NOR);
	set("gender", "男性" );
	set("age", 40);
	set("long", "黄眉僧的二徒弟，一向以拿人钱财替人消灾而著称。\n");
	set("attitude", "heroism");
	set("class", "bonze");

	set("str", 30);
	set("con", 30);
	set("int", 27);
	set("dex", 23);

	set("max_qi", 3000);
	set("max_jing", 1500);
	set("neili", 5000);
	set("max_neili", 5000);
	set("jiali", 50);
	set("shen_type", 1);
	set("nianhua", 1);

	set_temp("apply/attack",  30);
	set_temp("apply/defense", 50);

	set("combat_exp", 1500000);

	set_skill("force", 180); 
	set_skill("cuff", 180);
	set_skill("staff", 180);
	set_skill("dodge", 180);
	set_skill("parry", 180);
	set_skill("shaolin-shenfa", 180); 
	set_skill("jingang-quan", 180); 
	set_skill("jingang-chu", 180); 
	set_skill("hunyuan-yiqi", 180);

	map_skill("force", "hunyuan-yiqi");
	map_skill("cuff","jingang-quan");
	map_skill("parry", "jingang-chu");
	map_skill("staff", "jingang-chu");
	map_skill("dodge", "shaolin-shenfa");
	prepare_skill("cuff", "jingang-quan");

	setup();

  carry_object("/d/shaolin/obj/dao-cloth")->wear();
  carry_object("/clone/weapon/gangzhang")->wield();
}

#include "huangmei.h"