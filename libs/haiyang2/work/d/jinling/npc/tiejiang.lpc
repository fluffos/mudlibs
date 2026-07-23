// smith.c
inherit NPC;
inherit F_DEALER;


void create()
{
	set_name("铁匠", ({ "tie jiang","tie","jiang" }) );
	set("str", 29);
	set("cor", 17);
	set("cps", 15);

	set("long",
		"一个身材粗壮的铁匠，正忙碌地工作著　\n"
		"如果你想买一些铁器，可以用 list 看有哪些东西，用 buy 向铁匠购买　\n");
	set("vendor_goods", ({
		__DIR__"obj/longsword",
		__DIR__"obj/blade",
		__DIR__"obj/hammer",
		__DIR__"obj/shield",		
	}));


	set("chat_chance", 5);
	set("chat_msg", ({
		"铁匠将一块烧红的铁块「嗤」地一声浸入一旁的水箱中。\n",
		"铁匠用手中的铁　在铁砧上用力敲打。\n",
		"铁匠说道：站开点，小心别烫著了。\n",
		"铁匠说道：唉 ... 真把我给忙坏了。\n",
	}));
	setup();
	carry_object(__DIR__"obj/linen")->wear();
}

void init()
{
	::init();
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}

int accept_fight(object me)
{
        command("say " + RANK_D->query_respect(me) + 
"想打架？难道我还怕你吗！\n");
        return 1;
}
 
