inherit NPC;

void create()
{
	set_name("挑夫", ({ "tiaofu","tiao fu", "fu" }) );
	set("gender", "男性" );
	set("age", 30);
       set("mingwang",1);
       set("score",20); 
	set("int", 28);
        set("combat_exp",800);
	set("long","身强力壮的汉子。\n");
	set("attitude", "peaceful");
	set_skill("literate", 0);
        set_skill("unarmed",10);
        set_skill("parry",20);
        set_skill("staff",20);
        set_skill("dodge",20);
	setup();
       carry_object("/clone/misc/cloth")->wear();
       carry_object(__DIR__"obj/biandan")->wield();
        add_money("silver", 3);
}

