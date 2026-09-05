// huoji. 药铺伙计

inherit NPC;
inherit F_DEALER;

void create()
{
    int i=random(100);
	set_name("药铺伙计", ({ "yaopu huoji", "huoji" }));
	set("str", 20);
	set("gender", "男性");
	set("age", 18);
	set("long", "他是从乡下招来帮忙的。\n");
	set("combat_exp", 250);
	set("attitude", "friendly");
	if (i>30)
    {
        set("vendor_goods", ({
		"/d/city/obj/jinchuang",
       
        }));
    }
	else
    {
        set("vendor_goods", ({
		"/d/city/obj/jinchuang",
        
        "/d/taishan/obj/shechuangzi",
    }));
    
   }

	set("shen_type",1);set("score",200);setup();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
