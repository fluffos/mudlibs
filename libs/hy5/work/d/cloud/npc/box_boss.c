
// box_boss.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("林三爷", ({ "boxboss", "lin" }) );
        set("title", "棺材铺老板");
        set("gender", "男性" );
        set("age", 55);
        set("long", "这位面目慈善的老人经营棺材铺已经有很多年了。\n");
        set("str", 29);
        set("int", 14);
	set("max_kee",800);

	
	set("vendor_goods", ({
		__DIR__"obj/zhiqian",
		__DIR__"obj/zhihua",
		"/d/city/npc/obj/baozi",
	}));	
        set("combat_exp", 2000);
        set("attitude", "heroism");
        set_skill("unarmed", 60);
        set_skill("parry", 60);
        set_skill("dodge", 70);
	set_temp("apply/armor",20);

        set("inquiry", ([
                "棺材" : "您这么年轻就要棺材，早了点吧？",
                "香茗坊" : "您也知道'碧海银针'？茶楼就在街对面，我常去的。", 
        ]) );

        setup();
        add_money("silver", 4);
        add_money("coin", 100);
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

	add_action("do_buy", "buy");
	add_action("do_list", "list");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(10) ) {
                case 0:
message_vision("$N看了$n一眼道：木棺没货，都订了，酞多人死了。\n",this_object(),ob);
                        break;
                case 1:
message_vision("$N向$n问道：谁死了？\n",this_object(),ob);
                        break;
        }
}
