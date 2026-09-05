//by skywolf 2009-2-13 for bingcan-cloth
#include <ansi.h> 
inherit NPC;
inherit F_MASTER;


void create()
{
	set_name("慧净", ({
		"hui jing",
	}));
	set("long",
		"这和尚肥半已极，身材即又矮，宛然是个大肉球\n"
		"一看就知道是个酒肉和尚。\n"
	);


	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 50);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 600);
	set("max_jing", 300);
	set("neili", 600);
	set("max_neili", 600);
	set("jiali", 50);
	set("combat_exp", 200000);
	set("score", 200);

	set_skill("force", 80);
	set_skill("hunyuan-yiqi", 80);
	set_skill("dodge", 80);
	set_skill("shaolin-shenfa", 80);
	set_skill("staff", 80);
	set_skill("wuchang-zhang", 80);
	set_skill("parry", 80);
	set_skill("buddhism", 80);
	set_skill("literate", 80);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("staff", "wuchang-zhang");
	map_skill("parry", "wuchang-zhang");

	create_family("少林派", 38, "弟子");

	setup();

        carry_object("/d/shaolin/obj/chanzhang")->wield();
        carry_object("/d/shaolin/obj/hui-cloth")->wear();
}

void init()
{
	object me=this_player();
	object ob=this_object();
	if (me->query_temp("bingcan/findcan"))
	{
		me->delete_temp("bingcan/findcan");
		write(RED"慧净见你走近,不免大吃一惊,片刻后眼中凶光毕露.\n"NOR);
		write(RED"但他自知不是你的对手,纵然以死相拼也是枉然,便把心一横,\n"NOR);
		write(RED"说道:老纳今天鱼死网破,我得不到,你也休想!!话音刚落,一脚\n"NOR);
		write(RED"踏在冰蚕之上,你阻挡不及,好好的冰蚕却已变成了肉酱...\n"NOR);
		ob->kill_ob(me);
		
	}
}



