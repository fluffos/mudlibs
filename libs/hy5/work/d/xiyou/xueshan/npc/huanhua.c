//huanhua.c
//hehe, this npc is interesting:D...weiqi, 97.09.15

inherit NPC;
void create()
{
	set_name("浣花", ({"huan hua", "huanhua", "hua"}));
	set("gender", "女性" );
	set("age", 16);
	set("long", "雪山门下女弟子。\n");
	set("class", "yaomo");
	set("combat_exp", 25000);
  set("daoxing", 30000);

	set("attitude", "peaceful");
	create_family("大雪山", 4, "弟子");



	set("per", 21);
	set("max_kee", 300);
	set("max_sen", 300);
	set("force", 300);
	set("max_force", 250);
	set("force_factor", 5);
	setup();

	set("eff_dx", -8000);
	set("nkgain", 60);

	carry_object("/d/obj/cloth/skirt")->wear();
	carry_object("/d/obj/cloth/shoes")->wear();
	carry_object("/d/obj/weapon/blade/iceblade")->wield();
}
