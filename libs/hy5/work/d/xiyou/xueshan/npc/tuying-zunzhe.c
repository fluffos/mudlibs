// tuying-zunzhe.c...weiqi, 97.09.15.

#include <ansi.h>

inherit NPC;
string expell_me(object me);
void create()
{
	set_name("秃鹰尊者", ({"tuying zunzhe", "tuying", "zunzhe"}));
	set("title", "明王护法");
	set("gender", "男性" );
	set("age", 53);
	set("per", 112);//no rongmao description.

	set("long", "大鹏明王座下四护法尊者之一。额头高耸，一看就知道功力深厚。\n");
	set("class", "yaomo");
	set("combat_exp", 500000);
	set("daoxing", 400000);

	set("attitude", "peaceful");
	create_family("大雪山", 2, "弟子");

	set("max_kee", 800);
	set("max_sen", 600);
	set("force", 1600);
	set("max_force", 800);
	set("mana", 1000);
	set("max_mana", 500);	
	set("force_factor", 50);
	set("mana_factor", 25);

        set("eff_dx", -120000);
        set("nkgain", 300);

	set("inquiry", ([

		"name": "嘿嘿！\n",
		"here": "多看少说！\n",
	]) );


	setup();
	carry_object("/d/obj/cloth/xueshan-pao")->wear();
	//carry_object("/d/obj/weapon/blade/iceblade")->wield();
}

