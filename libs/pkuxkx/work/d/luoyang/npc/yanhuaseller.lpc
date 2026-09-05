// yanhua seller Zine Oct 16 2010

inherit NPC;
inherit F_DEALER;
#include <ansi.h>
#include <random_name.h>

void create()
{
	set_name(get_rndname(), ({get_rndid(), }));
    set("title", "烟花店伙计");
	set("gender", "女性" );
	set("age", 20+random(10));
    set("yanhuaseller","yes");
	set("long",
		"这位小姑娘水灵水灵的，而且能说会道，所以这家店生意极好。\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("vendor_goods", ({
		"/d/luoyang/obj/fireworksa",
        "/d/luoyang/obj/fireworksb",
        "/d/luoyang/obj/fireworksc",
        "/d/luoyang/obj/fireworksd",
        "/d/luoyang/obj/fireworkse",
        "/d/luoyang/obj/fireworksf",
        "/d/luoyang/obj/fireworksg",
        "/d/luoyang/obj/fireworksh",
        "/d/luoyang/obj/fireworksi",
        
		
	}));
	setup();
}

void init()
{	
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}

void unconcious()
{
        die();
}

void die()
{
        message_vision("$N摇了摇头，似乎很不理解你想干嘛。\n",this_object());
        this_object()->fullme();
        return;
}