inherit BHNPC;
void create()
{
        set_name("ÆÍÈË", ({ "pu ren", "ren" }));
        set("gender", "ÄĞĞÔ");
        set("age", 30);       
        set("str", 17);
        set("int", 20);
        set("con", 20);
        set("dex", 20);
        set("combat_exp", 22000);
        set("shen_type", 0);
        set("attitude", "peaceful");
        set("max_qi",800);
        set("max_jing",800);
        set("neili",600);
        set("max_neili",600);
        set("jiali",0);
        set("score", 7000);

        set_skill("cuff", 60);
        set_skill("parry",60);
set_skill("ding-force", 60);
        set_skill("dodge", 60);
        set_skill("force",60);
set_skill("ding-dodge", 60);

map_skill("force", "ding-force");
map_skill("dodge", "ding-dodge");

        set_temp("apply/attack", 20);
        set_temp("apply/defense", 20);

        setup();
        carry_object(__DIR__"obj/cloth2")->wear();
}
