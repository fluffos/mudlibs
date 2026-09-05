 // yuebing xiaofan月饼小贩

inherit NPC;
inherit F_DEALER;

void create()
{
        set_name("小贩", ({ "xiao fan", "seller","fan","xiao" }));
        set("title", "专卖月饼");
        set("shen_type", 1);

        set("str", 20);
        set("gender", "男性");
        set("age", 25);
        set("long", "这是一位专卖月饼的小贩，他推着独轮车，笑眯眯地走街串巷卖月饼。\n");
        set("combat_exp", 50000);
        set("qi", 300);
        set("max_qi", 300);
        set("attitude", "friendly");
        set_skill("unarmed", 60);
        set_skill("dodge", 60);
        set("chat_chance", 10);
        set("chat_msg", ({
                (: random_move :),
                "小贩吆喝道：卖月饼咯～～又香又甜的仲秋月饼喔～～～\n",
                "小贩笑眯眯地说道：仲秋节到了，买点月饼赏月的时候吃吧！\n",
        }));
	set_temp("apply/attack", 30);
        set_temp("apply/defense", 30);
        set("vendor_goods", ({
		"/d/gift/mooncake",
                "/d/gift/mooncake",
                "/d/gift/mooncake",
                "/d/gift/mooncake",
                "/d/gift/mooncake",
	}));

        setup();
}

void init()
{
        add_action("do_buy", "buy");
        add_action("do_list", "list");
}
