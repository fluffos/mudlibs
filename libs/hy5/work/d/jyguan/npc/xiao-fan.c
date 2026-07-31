// seller.c

inherit NPC;
inherit F_DEALER;


void create()
{
	set_name("卖羊肉串的小贩", ({ "xiao fan", "seller", "fan" }) );
	set("gender", "男性" );
	set("age", 32);
	set("long",
		"他正忙着翻烤羊肉串，不时用油腻的手搓揉着被烟熏的通红的双眼。\n");
	set("shen_type", 1);
	set("combat_exp", 300);
        set("str", 17);
        set("dex", 20);
        set("con", 17);
        set("int", 22);
	set("attitude", "peaceful");
	set("vendor_goods", ({
		"/d/jyguan/obj/yangrou",
                "/d/village/npc/obj/bottle",
	}) );

        set("chat_chance",10);
        set("chat_msg",({
     "小贩高声叫卖：“羊肉串儿——羊肉串儿——新鲜的羊肉串儿...”\n",
     "小贩叫到：“各位客官，来买水喽，再往前走就没有水了啊，来买喽~”\n",
	}));


	setup();
        carry_object("clone/misc/cloth")->wear();
        add_money("coin", 100);
}
void init()
{
        ::init();
        add_action("do_buy", "buy");
        add_action("do_list", "list");
}

