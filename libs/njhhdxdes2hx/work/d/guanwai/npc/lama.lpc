
inherit NPC;

void create()
{
	set_name("护寺喇嘛", ({ "lama"}) );
	set("gender", "男性" );
	set("age", 35);
	set("str", 20);
	set("long", @LONG
一个大招寺的藏僧。
LONG
);
	set("attitude", "heroism");

        set("combat_exp", 600);
        create_family("大招寺", 24, "弟子");
        set_skill("unarmed", 100);
        set_skill("bloodystrike", random(20)+50);
        set_skill("force", 40);
	map_skill("unarmed", "bloodystrike");
	set_skill("iron-cloth", 20);
        set("chat_chance", 20);
        set("chat_msg", ({
                (: random_move :),
        }) );

	setup();

        carry_object(__DIR__"obj/redcloth")->wear();
}
