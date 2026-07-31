// npc: /d/xingxiu/npc/alamuhan.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("阿拉木罕", ({ "alamuhan", "ala", "muhan" }));
	set("long", "她身段不肥也不瘦。她的眉毛像弯月，她的眼睛很多情。\n");
	set("title", "牧羊姑娘");
	set("gender", "女性");
	set("age", 17);

	set_skill("unarmed", 20);
	set_skill("dodge", 30);
	set_skill("parry", 20);
	set_skill("whip", 30);

	set_temp("apply/attack", 30);
	set_temp("apply/defense", 30);
	set_temp("apply/damage", 5);

	set("vendor_goods", ({
		(["name":"/d/xingxiu/obj/yangrou","number":20]),
		(["name":"/d/xingxiu/obj/nang","number":20]),
		(["name":"/d/xingxiu/obj/hamigua","number":20]),
	}));

        set("combat_exp", 5000);
        set("attitude","friendly");

        setup();
        carry_object(BINGQI_D("changbian"))->wield();
        carry_object(ARMOR_D("wcloth"))->wear();
}

void init()
{
	object ob;
	::init();
	add_action("do_buy", "buy");
	add_action("do_list", "list");
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(2) ) {
		case 0:
			say( "阿拉木罕笑嘻嘻地说道：色兰姆阿里空。\n");
			break;
		case 1:
			say( "阿拉木罕浅鞠一躬说道：阿里空色兰姆。\n");
			break;
	}
}
