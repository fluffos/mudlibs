inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("建筑商", ({ "jianzhu shang", "shang" }) );
	set("gender", "男性" );
	set("age", 52);
	set("long",
		"这是一位走南闯北的建筑商，买一些建筑材料。\n");
	set("combat_exp", 10000);
	set("attitude", "friendly");
	set("vendor_goods", ({
		
		"/d/parties/public/obj/bian",
		"/d/parties/public/obj/bian2",
		"/d/parties/public/obj/bian3",
		"/d/parties/public/obj/muliao",
		"/d/parties/public/obj/mucai",
		"/d/parties/public/obj/shiliao",
		"/d/parties/public/obj/shicai",
	}));
	setup();
}
void init()
{	
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}