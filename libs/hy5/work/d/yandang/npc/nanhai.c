// musix yangzhou's 男孩

inherit NPC;

void create()
{
	set_name("男孩",({ "nanhai","hai","boy" }) );
        set("gender", "男性" );
        set("age", 13);
        set("long", 
"不知谁家的小男孩。\n");

        set("str", 17);
        set("cpi", 16);
        set("con", 15);
        set("int", 17);
	set("mingwang", 1);
        set_temp("apply/defense", 10);
        set("combat_exp", 150);
        set("attitude", "peaceful");

        setup();

        carry_object("/clone/misc/cloth")->wear();
}

