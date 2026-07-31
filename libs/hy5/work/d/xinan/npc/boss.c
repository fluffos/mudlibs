
inherit NPC;



void create()
{
        set_name("看花老头", ({"lao tou", "old" }) );
        set("gender", "男性" );
        set("age", 67);
        set("str",60);
        set("long", "这是一位老态龙钟的看花老头。\n");
        set("combat_exp", 50000);      
        set("max_kee", 400);
        set("qi", 400);
        set("attitude", "friendly");

		setup();
	    add_money("coin",30);
	    carry_object(__DIR__"obj/cloth2")->wear();
}

