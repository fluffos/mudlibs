inherit F_VENDOR_SALE;

void create()
{
       set_name("竹小弟", ({"bamboo kid", "kid"}));
       set("long", "他是竹老大捡来养大的，人人都叫他小弟。\n");
       set("gender", "男性");
       set_level(2);
       set("per", 18);
       set("age", 16);
       set("attitude", "peaceful");
       set("shen_type", 1);
       set_skill("unarmed", 20);
	set_skill("dodge", 15);
        set("vendor_goods", ([
                "kuang": "/d/obj/misc/kuang",
        ]) );
        setup();
       	add_money("coin", 20);
	carry_object("/d/obj/cloth/linen")->wear();
}

int accept_fight(object me)
{	
	if( me->query_level()>=5 )
		return 0;
        return 1;
}
void init()
{
        add_action("do_vendor_list", "list");
}