inherit NPC;
void create()
{
        set_name("仆人", ({"puren"}));
        set("gender", "男性");
        set("age", 40);
        set("long", 
        "这是桃花岛的聋哑仆人。\n");
        set("attitude", "peaceful");
        set("str", 28);
        set("int", 17);
        set("con", 25);
        set("dex", 21);
        set("max_qi", 200);
        set("max_jing", 200);
        set("neili", 100);
        set("max_neili", 100);
        set("combat_exp", 10000);
        set_skill("force", 40);
        set_skill("unarmed", 40);
        set_skill("dodge", 40);
        set_skill("parry", 40);
        setup();
        carry_object("/clone/misc/cloth")->wear();
}
