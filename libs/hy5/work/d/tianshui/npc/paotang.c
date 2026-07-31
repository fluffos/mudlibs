// paotang.c


inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("跑堂", ({ "waiter" }) );
	set("title","醉仙阁");
        set("gender", "男性" );
        set("age", 22);
        set("long","小跑堂里外忙着，还不时要和进来的客人打招呼。\n");
        set("combat_exp", 50);
        set("attitude", "friendly");
	set("vendor_goods", ({
		__DIR__"obj/noodles",
		"/d/city/npc/obj/jitui",
		"/d/city/npc/obj/jiudai",
		"/d/city/npc/obj/baozi",
	}));        
        setup();
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
                        say( "小跑堂笑咪咪地说道：醉仙阁的饭菜远近闻名。\n");
                        break;
                case 1:
                        say( "小跑堂一哈腰说道：这位" + RANK_D->query_respect(ob)
                                + "，请进请进。\n");
                        break;
        }
}
