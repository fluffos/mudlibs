// seller.c
// Lklv Modify 2001.10.10

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("小贩", ({ "xiao fan", "xiao", "fan" }) );
	set("gender", "男性" );
	set("age", 22);
	set("long", "这是个小贩，别看他长的老老实实，可你别想从他那儿掏便宜。\n");
	set("shen_type", 1);
	set("combat_exp", 300);
	set("str", 17);
	set("dex", 20);
	set("con", 17);
	set("int", 22);
	set("attitude", "peaceful");
	set("vendor_goods", ({
		(["name":"/d/shaolin/obj/map","number":2]),
		(["name":"/d/shaolin/obj/guide","number":2]),
		(["name":"/d/village/npc/obj/stick","number":2]),
		(["name":"/d/village/npc/obj/shoes","number":2]),
		(["name":"/d/village/npc/obj/bottle","number":2])
	}) );
	setup();
        carry_object(ARMOR_D("cloth"))->wear();
        carry_object(ARMOR_D("shoes"))->wear();
	add_money("coin", 100);
}
void init()
{
        ::init();
        add_action("do_buy", "buy");
        add_action("do_list", "list");
}