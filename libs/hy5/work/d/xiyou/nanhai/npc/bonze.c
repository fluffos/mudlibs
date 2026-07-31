//Cracked by Roath
// bonze.c ºÍÉĞº
// By Dream Dec. 20, 1996

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("ºÍÉĞ", ({ "heshang", "bonze" }));
	set("gender", "ÄĞĞÔ");
	set("age", 30);
	set("attitude", "peaceful");
	set("class", "bonze");
	set("max_kee", 600);
	set("max_gin", 600);
	set("max_sen", 600);
	set("force", 300);
	set("max_force", 300);
	set("force_factor", 20);
	set("max_mana", 300);
	set("mana", 300);
	set("mana_factor", 20);
	set("combat_exp", 100000);
	set("daoxing", 200000);


        set("eff_dx", 35000);
        set("nkgain", 200);

	

	set("chat_chance", 5);
	set("chat_msg", ({
		(: random_move :)
	}) );
        
	create_family("ÄÏº£ÆÕÍÓÉ½", 3, "µÜ×Ó");
	
	setup();

	carry_object("/d/xiyou/nanhai/obj/sengpao")->wear();
}

