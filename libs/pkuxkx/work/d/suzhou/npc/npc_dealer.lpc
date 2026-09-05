inherit NPC;
inherit F_DEALER;
void create()
{
	set_name("磁仙鹤", ({ "ci xianhe", "ci","xianhe" }));
	set("title", "NPC店铺老板");
	set("shen_type", 1);
	set("gender", "男性");
	set("age", 45);
	set("long",
		"磁仙鹤是一个心黑的npc商贩。\n");
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_temp("apply/damage", 15);

	set("combat_exp", 40000);
	set("attitude", "friendly");
	set("vendor_goods", ({
"/d/suzhou/obj/npc_only/armor",
"/d/suzhou/obj/npc_only/dagger",
"/d/suzhou/obj/npc_only/whip",
	"/d/suzhou/obj/npc_only/biao",
	"/d/suzhou/obj/npc_only/med_biao",
	"/d/suzhou/obj/npc_only/high_biao",
	"/d/suzhou/obj/npc_only/low_qi",
	"/d/suzhou/obj/npc_only/med_qi",
	"/d/suzhou/obj/npc_only/high_qi",
	"/d/suzhou/obj/npc_only/low_neili",
	"/d/suzhou/obj/npc_only/med_neili",
	"/d/suzhou/obj/npc_only/high_neili",
	"/d/suzhou/obj/npc_only/sk_book",
	}));
	setup();
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}
