#include <ansi.h>

inherit NPC;
inherit F_DEALER;
void create()
{
        set_name("木拉提", ({ "mulati" }) );
        set("gender", "男性" );
        set("age", 69);
        set("richness",1000000);
        set("combat_exp", 50);
        set("no_arrest",1);
        set("attitude", "friendly");
        setup();
        carry_object("/clone/misc/cloth")->wear();
} 
void init()
{       
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
	add_action("do_list", "list");
        add_action("do_buy", "buy");
	add_action("do_sell", "sell");
	add_action("do_value", "value");
	add_action("do_redeem", "redeem");
} 
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(5) ) {
                case 0:
message_vision("$N说道：这位"+RANK_D->query_respect(ob)+
"，亚克西姆赛斯！\n",this_object(),ob);
                        break;
                case 1:
message_vision("$N说道：这位"+RANK_D->query_respect(ob)+
"，亚克西姆赛斯！\n",this_object(),ob);
                        break;
                case 2:
message_vision("$N抬头看了一眼．．．\n"
,this_object(),ob);
                        break;
                                }
}   
