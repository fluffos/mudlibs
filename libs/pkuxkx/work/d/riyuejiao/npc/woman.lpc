//woman.c	农妇

inherit NPC;

void create()
{
	set_name("农妇",({ "woman" }) );
        set("gender", "女性" );
        set("age", 33);
        set("long", 
"这是个农家妇女，正盘着腿在炕上绣花。\n");

        set("str", 27);
        set("dex", 26);
        set("con", 25);
        set("int", 27);
	set("shen_type", 1);
//	set("shen", 100);
        set_temp("apply/defense", 20);
        set("combat_exp", 10000);
        set("attitude", "peaceful");

        setup();

        carry_object(__DIR__"obj/cloth")->wear();
	carry_object(__DIR__"obj/xiuhuajia");
	carry_object("/d/quanzhou/obj/xiuhua");
}

