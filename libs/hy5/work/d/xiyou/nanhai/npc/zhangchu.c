//Cracked by Roath
// zhangchu.c ÕÆ³øÉ®º
// By Dream Dec. 20, 1996

inherit NPC;

string *have_yao=({});
string *have_dan=({});

string ask_yao(object who);
string ask_dan(object who);

void create()
{
	set_name("ÕÆ³øÉ®", ({ "zhangchu seng", "seng" }));
	set("gender", "ÄĞĞÔ");
	set("age", 25);
	set("attitude", "peaceful");
	set("class", "bonze");
	set("max_kee", 200);
	set("max_gin", 200);
	set("max_sen", 200);
	set("force", 100);
	set("max_force", 100);
	set("force_factor", 10);
	set("max_mana", 100);
	set("mana", 100);
	set("mana_factor", 10);
	set("combat_exp", 5000);
	set("daoxing", 10000);

//	set("chat_chance_combat", 80);
//	set("chat_msg_combat", ({
//		(: cast_spell, "thunder" :),
//	}) );


        set("apply/yaono", 10);
        set("apply/danno", 10);

        create_family("ÄÏº£ÆÕÍÓÉ½", 4, "µÜ×Ó");
	
	setup();
        add_money("silver", 10);
	carry_object("/d/xiyou/nanhai/obj/sengpao")->wear();
}

