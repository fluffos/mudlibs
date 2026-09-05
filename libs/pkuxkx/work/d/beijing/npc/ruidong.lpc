//Cracked by Roath
// Npc:
// Date:
// kane, 28/9/97

inherit NPC;
void set_shiwei_status(int);
int auto_kill(object player);

void create()
{
	set_name("瑞栋", ({
		"rui dong",
		"rui",
		"dong",
	}));
	set("title", "侍卫副总管");
	set("long",
		"他就是侍卫副总管。\n"
	);


	set("gender", "男性");
	set("attitude", "heroism");

	set("age", 30);
	set("shen_type",0);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 600);
	set("max_jing", 300);
	set("neili", 400);
	set("max_neili", 400);
	set("combat_exp", 200000);
	set("score", 100);



	set("shen_type",1);set("score",500);setup();
	set_shiwei_status(160);

        carry_object("/d/beijing/npc/obj/junfu")->wear();
	carry_object("/d/city/obj/gangjian")->wield();
        carry_object("/d/beijing/npc/obj/book42_5");
}

void init ()
{
    auto_kill(this_player());
}

#include "/d/beijing/autok.h"