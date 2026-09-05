//Cracked by Roath
// seller.c
// modified by aln  4 / 98

inherit NPC;
inherit F_VENDOR;
#include "/d/beijing/killme.h"

int remove_cha();

void create()
{
        set_name("小贩", ({ "seller" }) );
        set("gender", "男性" );
        set("age", 32);
        set("long",
                "这是个小贩，别看他长的老老实实，可你别想从他那儿掏便宜。\n");
        set("combat_exp", 300);
        set("str", 17);
        set("dex", 20);
        set("con", 17);
        set("int", 22);
        set("attitude", "friendly");
        set("vendor_goods", ({
                __DIR__"obj/tanghulu",
                __DIR__"obj/tea",
                "/d/xingxiu/npc/obj/case",
        }) );

        set("chat_chance", 10);
        set("chat_msg", ({
                (: remove_cha :)
        }) );

        set("shen_type",1);set("score",200);setup();
        carry_object("/clone/armor/cloth")->wear();
        add_money("coin", 60);
}

void init()
{
        ::init();

        add_action("do_buy", "buy");
        add_action("do_list", "list");
        add_action("do_move", "go");
}

int do_move()
{
        if( present("cha wan", this_player()) ) {
	        message_vision("$N一把拦住了$n，说道：这位"+
		RANK_D->query_respect(this_player()) +
		"，您老把小人的茶碗赏还了吧。\n",
		this_object(), this_player());
	        return 1;
        }

        return 0;
}

int remove_cha()
{
        object ob;

        if( objectp(ob = present("cha wan", environment())) ) {
	        destruct(ob);
	        message_vision("$N把地上的茶碗收拾了起来。\n", this_object());
        }

        return 1;
}

int accept_object(object who, object ob)
{
    if (base_name(ob) == "/d/beijing/npc/obj/tea")
    {
        command("joythank "+who->query("id"));
        call_out("destroy", 1, ob);
	return 1;
    }
    return 0;
}
void destroy(object ob)
{
	destruct(ob);
}