inherit NPC;
inherit F_DEALER;

void create()
{
    int i=random(100);
	set_name("酒馆老板", ({ "jiuguan laoban", "lao ban","laoban","boss" }));
	set("str", 20);
	set("gender", "男性");
	set("age", 48);
	set("long", "他是这家酒馆的老板。\n");
	set("combat_exp", 25000);
	set("attitude", "friendly");
    set("vendor_goods", ({
	
                __DIR__"obj/jiudai",
                __DIR__"obj/paomo",
    }));
    set("shen_type",1);set("score",200);setup();
	carry_object("/clone/cloth/cloth")->wear();
}

void init()
{
		object ob;
        add_action("do_list", "list");
        add_action("do_buy", "buy");
		::init();
        if((random(10)||wizardp(this_player())) &&interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}


void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        if( !this_object()->visible(ob)) return;
        switch( random(2) ) {
                case 0:
                        say( query("name")+"说道：这位" + RANK_D->query_respect(ob)
                                + "，来了还能不喝一碗？\n");
                        break;
                case 1:
                        say( query("name")+"说道：这位" + RANK_D->query_respect(ob)
                                + "，我家的烧刀子可是远近闻名的。\n");
                        break;
        }
}
