inherit NPC;
void create()
{
        set_name("¼Ò¶¡", ({ "jia ding", "ding" }));
        set("gender", "ÄĞĞÔ");
        set("age", 24);
        set("str", 24);
        set("int", 23);
        set("con", 23);
        set("dex", 22);
        set("combat_exp", 30000);
        set("shen_type", 0);
        set("attitude", "peaceful");
        set("max_qi",750);
        set("max_jing",500);
        set("neili",550);
        set("max_neili",550);
        set("jiali",0);
        set("score", 6000);

        set_skill("cuff", 75);
        set_skill("parry",75);
        set_skill("ding-dodge",55);
        set_skill("dodge",55);
        set_skill("force",55);
        set_skill("ding-force",55);
        set_skill("sword",55);

        map_skill("force","ding-force");
        map_skill("dodge","ding-dodge");

        set_temp("apply/attack", 20);
        set_temp("apply/defense", 20);

        setup();
        carry_object(__DIR__"obj/cloth2")->wear();
}
