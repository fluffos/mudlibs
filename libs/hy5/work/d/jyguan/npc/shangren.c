// Living: /wizhome/sharkhome/jyguan/npc/shangren.c
// By Shark  10/08/1998

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("西域商人", ({ "shang ren", "shang" }) );
	set("gender", "男性" );
	set("age", 32);
	set("long",
		"身着锦缎，气宇轩昂,看似大富之人。\n");
	set("shen_type", 1);
	set("combat_exp", 22000);
        set("str", 27);
        set("dex", 20);
        set("con", 23);
        set("int", 22);
	set("attitude", "peaceful");

	set_skill("unarmed", 70);
	set_skill("force", 70);
	set_skill("sword", 70);
	set_skill("dodge", 70);
	set_skill("parry", 70);	

        set("chat_chance",10);
        set("chat_msg",({
     "西域商人嘟囔着：“下一次我多带些福寿膏来，嘿嘿，准能发大财了！”\n",
        (: random_move :)
	}));


	setup();
//        carry_object(__DIR__"obj/xiyurobe")->wear();
        add_money("gold", 1);
}

