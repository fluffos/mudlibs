// xunshi.c
#include <ansi.h>

inherit NPC;
int give_jiasha();

void create()
{
        set_name("枷蓝", ({"jia lan", "pusa"}));
	set("gender", "男性" );
	set("age", 33);
         set("per",40);
	set("class", "yaomo");
	set("combat_exp", 25000);
  set("daoxing", 20000);

	set("attitude", "peaceful");
	create_family("大雪山", 4, "弟子");


	set("max_kee", 300);
	set("max_sen", 300);
	set("force", 300);
	set("max_force", 250);
	set("force_factor", 5);

	set("eff_dx", -8000);
	set("nkgain", 60);


	setup();
	carry_object("/d/obj/cloth/xueshan-pao")->wear();
	carry_object("/d/obj/weapon/blade/iceblade")->wield();
}

