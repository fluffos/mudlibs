inherit NPC;
inherit F_DEALER;

void create()
{
        set_name("胭松", ({ "yan song", "song" }) );
        set("gender", "女性" );
        set("age", 22);
        set("per", 30);
        set("class","lama");
        set("long",
                "胭松是葛伦高僧的得意二弟子。\n");
        create_family("大昭寺", 21, "弟子");
        set("combat_exp", 500000);
        set("attitude", "friendly");

        set_skill("lamaism", 10);
        set_skill("unarmed", 100);
        set_skill("staff", 100);
	set("vendor_goods", ({
		__DIR__"obj/fake-tooth",
	}));
        set("inquiry", ([
                "舍利子": "嗯....你出银子，我卖给你。\n",
                "真舍利子": "嗯....我派人送入关，但那人死在大漠中了。\n",
        ]) );

        setup();
        carry_object(__DIR__"obj/whtclothh")->wear();
        carry_object(__DIR__"obj/5staff");
        
}       
void init()
{	
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}