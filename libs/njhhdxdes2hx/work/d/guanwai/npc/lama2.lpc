
inherit NPC;

void create()
{
	set_name("护寺藏尼", ({ "zhang ni", "ni"}) );
	set("gender", "女性" );
	set("age", 25);
	set("str", 20);
	set("long", @LONG
一个大招寺的藏尼。
LONG
);
	set("attitude", "peaceful");

        set("combat_exp", 600);
        create_family("大招寺", random(4)+24, "弟子");
        set_skill("unarmed", 50);
        set_skill("bloodystrike", random(20)+10);
        set_skill("force", 40);
	map_skill("unarmed", "bloodystrike");
	set_skill("iron-cloth", 10);
        set("chat_chance", 20);
        set("chat_msg", ({
                (: random_move :),
        }) );

	setup();

        carry_object(__DIR__"obj/redcloth2")->wear();
}
