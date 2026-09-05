// yanhua seller Zine Oct 16 2010

inherit NPC;
inherit F_DEALER;
#include <ansi.h>
#include <random_name.h>
int ask_ruyi();

void create()
{
	set_name(get_rndname(), ({get_rndid(), }));
    set("title", "喜店伙计");
	set("gender", "女性" );
	set("age", 15+random(10));
    set("xiseller","yes");
	set("long",
		"这位小姑娘水灵水灵的，而且能说会道，所以这家店生意极好。\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("vendor_goods", ({
		"/d/luoyang/obj/bridalcloth",
        "/d/luoyang/obj/bridalhat",
        "/d/luoyang/obj/groomcloth",
        "/d/luoyang/obj/groomneck",
        
        
		
	}));
    set("inquiry", ([
            
			"秘宝" :(: ask_ruyi :),
            "如意" :(: ask_ruyi :),
			
        ]) );
	setup();
}

int ask_ruyi()
{
    object me=this_player();
    object ruyi;
    if (!me->query("marry/lover"))
    {
        tell_object(me,"小姑娘看了看你，欲言又止。\n");
        return 1;
    }
    if (present("ru yi",me))
    {
        tell_object(me,"小姑娘道：你身上不是有如意吗？贪心不足，会折福的。\n");
        return 1;
    }
    if (me->query("balance")<200000)
    {
        tell_object(me,"小姑娘道：玉如意是至宝，我看你的钱似乎不够呀。\n");
        return 1;
    }
    else
    {
        if (me->query("gender")=="男性")
        {
            ruyi=new("/d/luoyang/obj/groomitem");
            ruyi->move(me);
            me->add("balance",-150000);
            tell_object(me,"小姑娘道：好吧，那我就卖给你一柄玉如意吧。\n");
            return 1;
        }
        if (me->query("gender")=="女性")
        {
            ruyi=new("/d/luoyang/obj/bridalitem");
            ruyi->move(me);
            me->add("balance",-150000);
            tell_object(me,"小姑娘道：好吧，那我就卖给你一柄玉如意吧。\n");
            return 1;
        }
        if (me->query("gender")=="无性")
        {
            tell_object(me,"小姑娘道：真是新鲜，不知道公公要如意干嘛？\n");
            return 1;
        }
    }
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