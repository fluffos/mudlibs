inherit NPC;

void create()
{
	set_name("小孩子",({"xiaohaizi","haizi", "kid" }) );
        set("gender", "男性" );
        set("age", 9);
        set("long", "这是个穷人家的小孩子\n");
        set("combat_exp", 10);
	set("mingwang", 1);
	set("str", 11);
	set("con", 11);
	set("int", 11);
        set("attitude", "friendly");
        setup();
	carry_object("/clone/misc/cloth")->wear();
        add_money("coin",5);
}

