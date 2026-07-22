//dadi.c, dummy npc for announcement...

inherit NPC;

void create()
{
        set_name("ºÚ¿Í", ({ "lonely" }));
        set("long", "É³Ä®¹ÂÀÇ¡£\n");
        set("gender", "ÄĞĞÔ");
        set("age", 50);
        set("attitude", "friendly");
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("per" ,10);
        set("combat_exp", 5000000);

        setup();
       carry_object("/clone/cloth/cloth")->wear();
}


