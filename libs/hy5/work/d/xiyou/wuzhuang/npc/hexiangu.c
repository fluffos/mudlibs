//Cracked by Roath
// hexiangu.c...weiqi, 98.02.24.

inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
	set_name("何仙姑", ({"he xiangu", "he", "xiangu"}));
	//set("title", "");
	set("gender", "女性" );
	set("age", 25);
	set("per", 20);
	set("long", "何仙姑深得镇元大仙喜爱，各位同门大多跟她交好。\n何仙姑原名何秀姑，父亲是开豆腐坊的，她投入五庄观前是当地有名的“豆腐西施”。\n");
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
	initlvl((300+random(280)),15);
	carry_object("/d/obj/cloth/skirt")->wear();
	carry_object("/d/obj/cloth/shoes")->wear();
	carry_object("/d/obj/weapon/sword/heye")->wield();
}
