// qingshi-laomo.c...weiqi, 97.09.15.

inherit NPC;
void create()
{
	set_name("青狮老魔", ({"qingshi laomo", "qingshi", "laomo"}));
	set("title", "明王护法");
	set("gender", "男性" );
	set("age", 63);
	set("per", 112);//no rongmao description.

	set("long", "这位青狮老魔原来在狮驼山逍遥，跟大鹏明王颇有交情。\n后来狮驼山被方寸山三星洞的一位得道高人剿灭，\n老魔就投奔大鹏明王做了护法尊者。一个跟和尚有仇，\n一个跟道士有仇，也算是知交好友。\n");
	set("class", "yaomo");
	set("combat_exp", 800000);
	set("daoxing", 1000000);

	set("attitude", "peaceful");
	create_family("大雪山", 2, "弟子");
	
	set("max_kee", 1000);
	set("max_sen", 600);
	set("force", 1600);
	set("max_force", 800);
	set("mana", 1600);
	set("max_mana", 800);	
	set("force_factor", 60);
	set("mana_factor", 25);

	set("eff_dx", -200000);
	set("nkgain", 400);

	setup();
	carry_object("/d/obj/armor/jinjia")->wear();
	carry_object("/d/obj/weapon/blade/iceblade")->wield();
}

