// kid.c

inherit NPC;

void create()
{
	set_name("书生",({ "shusheng" }) );
        set("gender", "男性" );
        set("age", 17);
        set("long", "这是个不得志的书生\n");
        set("combat_exp", 500);
//        set("shen", 50);
	set("shen_type", 1);
	set("str", 21);
	set("dex", 21);
	set("con", 21);
	set("int", 21);
        set("attitude", "friendly");
        setup();
	carry_object(__DIR__"obj/cloth")->wear();
        carry_object(__DIR__"obj/shuji"+(random(4)+1));
}

