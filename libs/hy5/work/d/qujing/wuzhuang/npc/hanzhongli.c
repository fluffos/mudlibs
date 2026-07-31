//Cracked by Roath
// hanzhongli.c...weiqi, 98.02.24.

inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
	set_name("汉钟离", ({"han zhongli", "han", "zhongli"}));
	//set("title", "");
	set("gender", "男性" );
	set("age", 50);
	set("per", 20);
	set("long", "一位大腹便便的胖老头。大概总是觉得太热，时不时地要扇几扇。\n据说他以前喜欢带兵打仗，却又实在不是当将军的料，每每大败而回。\n心灰意冷之下便出门学道访仙，后拜在了镇元门下。\n");
	set("class", "xian");
	set("combat_exp", 120000);
  set("combat_exp", 400000);

	set("attitude", "peaceful");
	create_family("五庄观", 3, "弟子");
	set_skill("unarmed", 60);


	set("max_qi", 500);
	set("max_jing", 500);
	set("neili", 1000);
	set("max_neili", 800);
	set("neili", 1600);
	set("max_neili", 800);	
	set("force_factor", 40);
	set("mana_factor", 40);

	setup();
	initlvl((300+random(280)),16);
	carry_object("/d/obj/cloth/xianpao")->wear();
	carry_object("/d/obj/weapon/blade/bajiaoshan")->wield();
}

