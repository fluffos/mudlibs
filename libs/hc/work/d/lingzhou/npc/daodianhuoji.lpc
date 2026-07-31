// daodianhuoji.c

inherit NPC;
inherit F_DEALER;

void create()
{
        set_name("小伙计", ({ "xiao huoji", "huoji" }));
        set("shen_type", 1);
        set("gender", "男性" );
        set("age", 33);

        set("combat_exp", 400);
	set("attitude", "friendly");
        set("vendor_goods",({
                   "/d/city2/obj/tudao",
                   "/d/city/obj/dagger",
                   "/d/xingxiu/obj/wandao",
                   "/d/city/obj/gangdao",
        }));

	setup();

	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

/*
int buy_object(object who, string what)
{
        if( what=="hammer" ) return 300;
        if( what=="changjian" ) return 700;
        return 0;
}

void compelete_trade(object who, string what)
{
        object ob;
        
        if( what=="hammer" )  ob = new(__DIR__"obj/hammer");
        if( what=="changjian" )  ob = new(__DIR__"changjian");
        ob->move(who);
        if( what=="hammer" )
message_vision("$N交给$n一把沈甸甸的打铁用铁锤。\n", this_object(), who);
        if( what=="changjian" )
message_vision("$N交给$n一把青光闪闪的长剑。\n", this_object(), who);
}
*/ 
