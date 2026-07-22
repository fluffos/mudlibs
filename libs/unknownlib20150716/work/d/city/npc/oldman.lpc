inherit NPC;

void create()
{
        set_name("白世卿", ({"bai shiqin", "bai", "shiqin"}));
        set("gender", "男性");
        set_level(5);
        set("age", 65);
        set("long",
"一个文文净净的老人，好象很有学问的样子。\n");
	set("attitude", "friendly");
        set("combat_exp", 1000);
	set("per", 25);
        set_skill("unarmed", 10);
        set_skill("dodge", 10);
        setup();
	carry_object(0,"cloth",random(2))->wear();

}
int accept_fight(object me)
{
        command("say 对不住，小老二老骨头不禁打呀！");
        return 0;
}