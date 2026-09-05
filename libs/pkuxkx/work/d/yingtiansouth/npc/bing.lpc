inherit NPC;

void create()
{
	set_name("都府亲军", ({ "qin jun", "jun","bing" }));
	set("gender", "男性");
	set("age", random(10) + 30);
	set("str", 25);
	set("dex", 16);
	set("long", "他是一名都府亲军，武艺不凡。\n");
	set("combat_exp", 1000000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("unarmed", 100);
	set_skill("force", 100);
	set_skill("spear", 100);
	set_skill("yangjia-qiang", 200);
	set_skill("dodge", 100);
	set_skill("parry", 100);

	map_skill("spear", "yangjia-qiang");
	map_skill("parry", "yangjia-qiang");

	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 30);
	set("is_DFQJ",1);
	set("neili", 4000); 
	set("max_neili", 4000);
	set("jiali", 10);

	setup();
	carry_object("/clone/weapon/changqiang")->wield();
	carry_object("/d/city/npc/obj/tiejia")->wear();
}

