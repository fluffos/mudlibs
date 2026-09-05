// d/diaoyudao/npc/dywushi.c 东瀛武士
// hongdou 98.10.01

#include <ansi.h>

inherit NPC;

void create()
{
	set_name(HIC"东瀛武士"NOR, ({
		"wu shi",      
		"wushi",
		"shi",
	}));
	set("long",
		"一个全身精光的东瀛武士，正在意图强暴妇女。\n"
	);
	set("gender", "男性");
//	set("attitude", "friendly");
//	set("attitude", "heroism");
//	set("attitude", "aggressive");
	set("age", 35);
//	set("shen_type",-8000);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("max_qi", 600);
	set("max_jing", 500);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 100);
	set("combat_exp", 40000);

	set_skill("force", 100);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_skill("blade", 100);
//        set_skill("liuhe-dao",80);
//	map_skill("parry", "liuhe-dao");
//	map_skill("blade", "liuhe-dao");
	set("shen_type",-1);
set("score",2000);
setup();

        carry_object("/d/diaoyudao/npc/obj/wushi_dao")->wield();
}

void init()
{
	if((string)this_player()->query("family/family_name"))
	{
	this_object()->kill_ob(this_player());
   this_player()->kill_ob(this_object());
	return;
	}
}
