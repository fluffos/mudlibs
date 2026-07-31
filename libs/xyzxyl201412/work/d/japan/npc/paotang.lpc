// Npc: japan/npc/paotang.c

inherit NPC;
inherit F_DEALER;
#include <ansi.h>

void create()
{
         set_name("龙本大叔",({"longben dashu","longben","dashu"}));
        set("gender", "男性" );
        set("age",42);
        set("title","神户海鲜店");
        set("long",
                 "海鲜店的龙本大叔可是老实厚道，他正冲你微笑着。\n");
        set("combat_exp",150);
        set("attitude", "friendly");
        set("rank_info/respect","大叔");


set("vendor_goods", ({
                __DIR__"obj/youyu",
                __DIR__"obj/yupian",
                __DIR__"obj/fantuan",
                __DIR__"obj/jiuhu",
	}));
        setup();
        add_money("silver",5);
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

}

void greeting(object ob)
{

        if( !ob || environment(ob) != environment() ) return;
         switch( random(5) ) {
                case 0:
               message_vision("$N快步上前道：这位"+
               RANK_D->query_respect(ob)+"想点些什么？\n",this_object(), ob);
                        break;
                case 1:
             message_vision("$n正看着$N，等着$N点菜。\n",ob,this_object());
                        break;
                           }
}
