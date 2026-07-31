//Cracked by Roath
// hanxiangzi.c...weiqi, 98.02.24.

inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
	set_name("韩湘子", ({"han xiangzi", "han", "xiangzi"}));
	//set("title", "");
	set("gender", "男性" );
	set("age", 22);
	set("per", 30);
	set("long", "好一位俊雅潇洒的相公。韩湘子本是名门之后，却不喜念书入仕。\n被其族中长者以轻狂不学斥出家门。\n");
	set("class", "xian");
	set("combat_exp", 120000);
  set("combat_exp", 200000);

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
	carry_object("/d/obj/cloth/choupao")->wear();
	carry_object("/d/obj/weapon/sword/zijinxiao")->wield();
}


