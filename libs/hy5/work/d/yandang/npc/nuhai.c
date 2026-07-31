
// musix yangzhou's 女孩
inherit NPC;

void create()
{
	set_name("女孩",({ "nuhai","nvhai","girl" }) );
        set("gender", "女性" );
        set("age", 12);
        set("long", 
"不知谁家的小女孩。\n");
        set_temp("apply/defense", 10);
	set("combat_exp", 100);
	set("mingwang", 1);
        set("str", 14);
        set("int", 15);
        set("attitude", "friendly");
        setup();
carry_object("/clone/misc/cloth")->wear();
}

