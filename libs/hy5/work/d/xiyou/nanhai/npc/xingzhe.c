//Cracked by Roath
// xingzhe.c i·½ÐÐÕßº
// By Dream Dec. 20, 1996

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("ÓÎ·½ÐÐÕß", ({ "xingzhe" }));
	set("gender", "ÄÐÐÔ");
	set("age", 40);
	set("attitude", "peaceful");
	set("class", "bonze");
	set("max_kee", 350);
	set("max_gin", 300);
	set("max_sen", 350);
	set("force", 300);
	set("max_force", 300);
	set("force_factor", 20);
	set("max_mana", 250);
	set("mana", 250);
	set("mana_factor", 10);
	set("combat_exp", 100000);
	set("daoxing", 200000);


        set("eff_dx", 40000);
        set("nkgain", 250);

	
//	set("chat_msg_combat", ({
//		(: cast_spell, "thunder" :),
//	}) );

        create_family("ÄÏº£ÆÕÍÓÉ½", 3, "µÜ×Ó");
	
	setup();
	carry_object("/d/xiyou/nanhai/obj/sengpao")->wear();
        add_money("silver", 20);
	carry_object("/d/xiyou/nanhai/obj/tiezhang")->wield();
}

