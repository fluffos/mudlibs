#include <ansi.h>

inherit NPC;
inherit F_VENDOR;
void create()
{
		set_name("明性", ({ "mingxin","heshang" }) );
		set("nickname", CYN"业余小贩"NOR);
		set("long","...\n");
		set("age", 28);
		set("gender", "男性");
		set("attitude", "peaceful");

		set("str", 27);
		set("int", 30);
		set("spi", 30);
		set("con", 30);
		set("cps", 30);
		set("cor", 20);

        set("mingwang", 1);

        set("max_kee", 2000);
        set("kee", 2000);
        set("max_force", 2000);
        set("force", 2000);
        set("force_factor", 20);
        set("combat_exp", 150000+random(50000));
        set("score", 20000);
		set_skill("force", 80);
		set_skill("parry", 80);
		set_skill("dodge", 80);
		set_skill("sword", 80);
		set_skill("unarmed", 80);
		set_skill("blade", 80);
	set("vendor_goods", ({
		__DIR__"obj/taozi",
		__DIR__"obj/hulu",
		__DIR__"obj/baozi",
		__DIR__"obj/huang",		
	}));

     	set_skill("literate", 50);
		set("inquiry", ([
			"桃子": "这可是我从悬崖边采下来的,不能给你....当然,有钱的话...\n",
			"taozi": "这可是我从悬崖边采下来的,不能给你....当然,有钱的话...\n",
	]) );	
        set("chat_chance", 15);
        set("chat_msg", ({
                "又大又甜的桃儿.......\n",
                "刚出锅的包子.....",
                (: random_move :)
        }) );
        setup();
        add_money("silver",50);
        carry_object(__DIR__"obj/huang_jiasha")->wear();
}
void init()
{
        ::init();
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}


