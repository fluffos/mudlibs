
// seller.c
// By L.G.

#include <ansi.h>

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("书店伙计", ({ "seller" }) );
        set("gender", "男性" );
        set("age", 22);
        set("long", "卖书的是个年轻小伙子，面带微笑。\n");
        set("combat_exp", 100000);
        set("attitude", "friendly");
        set_skill("unarmed", 80);
        set_skill("dodge", 80);
        set("vendor_goods", ({
                "/d/city/npc/obj/lbook1",
                "/d/city/npc/obj/lbook2",
                "/d/city/npc/obj/lbook3"
        }));


//        set("where","north");
        setup();
//        add_money("gold", 1);
        add_money("coin", 300);
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        object ob;

        ::init();
        add_action("do_list","list");
        add_action("do_buy", "buy");
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }


}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(4) ) {
                case 0:
                        say( "书店伙计笑脸相迎，道：这位"
                                + RANK_D->query_respect(ob)
                                + "，要买什么？\n");
                        break;
                case 1:
                        say( "书店伙计正忙着整理书架\n");
                        break;
        }
}

