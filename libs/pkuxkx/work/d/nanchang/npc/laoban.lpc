// chen.c
// Jay 5/7/96

inherit NPC;
inherit F_DEALER;
#include <ansi.h>

void create()
{
        
        set_name("李老三",({"li laosan","li","laosan"}));
        set("title", HIC"酒馆老板"+NOR);
        set("shen_type", 1);

        set("str", 20);
        set("gender", "男性");
        set("age", random(20)+25);
        set("long",
                "他是一个汉人，自从宁王之乱后就一直避祸在这里。\n");
        set("combat_exp", 8000);
        set("attitude", "friendly");
        set("inquiry", ([
                
                "here" : "南昌固然是好，哪及这里世外桃源般得自在？\n",
                
        ]));
        set("sinan","yes");
        set("vendor_goods", ({
		
		"/d/city/npc/obj/ncfood2",
        "/d/city/npc/obj/ncfood3",
        "/d/city/npc/obj/jiudai2",}));

        setup();
        
}



void init()
{
        object ob;
        
        
        if (interactive(ob = this_player()) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

void greeting(object ob)
{
        if (!ob || environment(ob) != environment())
                return;
        switch(random(2)) {
        case 0 :
                say(this_object()->query("name")+"大声地说道：不好吃不要钱。\n");
                break;
        case 1 :
                say("李老三说道：客官，我的手艺不用吹的。\n");
                break;
        }
}
