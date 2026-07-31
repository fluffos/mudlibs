 // waiter.c
inherit NPC;
inherit F_DEALER;
void create()
{
        set_name("吕恭", ({ "waiter" }) );
        set("gender", "男性" );
    set("title", "老板" );
        set("age", 62);
        set("long",
                "一个老头正笑咪咪地忙著，还不时拿起挂在脖子上的抹布擦脸。\n");
        set("combat_exp", 5);
        set("attitude", "friendly");
        set_skill("iron-cloth", 2000);
        set_skill("unarmed", 100);
        set_skill("bloodystrike", 50);
        map_skill("unarmed", "bloodystrike");
        set("rank_info/respect", "老二哥");

	set("vendor_goods", ({
                __DIR__"obj/junksword",
                __DIR__"obj/junkblade",
                __DIR__"obj/junkstaff",
                __DIR__"obj/jade3",
                __DIR__"obj/huboots",
                __DIR__"obj/wineskin",
                __DIR__"obj/guskin",
                __DIR__"obj/sheep_leg",
                __DIR__"obj/snake_drug",
                __DIR__"obj/movebook", 
	}));        
        setup();
} 
void init()
{       
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
   }
	add_action("do_buy", "buy");
	add_action("do_list", "list");
} 
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(3) ) {
                case 0:
                        say( "店老板吕恭笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                                + "，进来喝杯茶，歇歇腿吧。\n");
                        break;
                case 1:
                        say( "店老板吕恭用脖子上的毛巾抹了抹手，说道：这位" + RANK_D->query_respect(ob)
                                + "，请进请进。\n");
                        break;
                case 2:
                        say( "店老板吕恭说道：这位" + RANK_D->query_respect(ob)
                                + "，进来喝几盅小店的酒吧，这几天才从窖子里开封的哟。\n");
                        break;
        }
} 
