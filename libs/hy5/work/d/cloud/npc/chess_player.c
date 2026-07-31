
// chess_player.c

inherit NPC;



void create()
{
        set_name("弈者", ({ "chess player", "player" }) );
        set("gender", "男性" );
        set("age", 43);
        set("long", "一位十分文气的男子，装束象个雅儒。\n");
        set("str", 12);
        set("int", 28);
        set("combat_exp", 500);
        set("attitude", "friendly");
        set_skill("unarmed", 10);
        set_skill("dodge", 80);
        set_skill("throwing", 30);



	setup();
	add_money("coin", 50);
        carry_object("/clone/misc/cloth")->wear();

}


