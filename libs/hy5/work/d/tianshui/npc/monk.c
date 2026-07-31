// monk.c

inherit NPC;

void create()
{
        set_name("老僧", ({ "old monk" }) );
        set("gender", "男性" );
        set("age", 74);
        set("long",
"这个老人看起来七十多岁了，却精神矍铄。\n");
        set("combat_exp", 1);
        set("attitude", "friendly");
        setup();
	carry_object(__DIR__"obj/jiasha")->wear();
}