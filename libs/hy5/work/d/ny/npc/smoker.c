
// trainee.c

inherit NPC;

void create()
{
	set_name("烟鬼", ({ "smoker" }) );
	set("gender", "男性" );
	set("age", 30);
	set("long", "你看到一位身材高大的汉子。\n");
	set("combat_exp", 100);
        set("dodge",10);
        set("unarmed",10);	
        setup();
	carry_object("/clone/misc/cloth")->wear();
}
