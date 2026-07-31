// /u/chen/murong/npc/puren.c ÆÍÈË
// by chen

inherit NPC;
void create()
{
        set_name("ÆÍÈË", ({ "pu ren", "ren" }));
        set("gender", "ÄÐÐÔ");
        set("age", 30);       
	set("str", 17);
        set("int", 20);
        set("con", 20);
        set("dex", 20);
              set("combat_exp", 3000);
        set("shen_type", 0);
        set("attitude", "peaceful");
	set("max_qi",800);
        set("max_jing",800);
        set("neili",600);
        set("max_neili",600);
	set("jiali",0);

        set_temp("apply/attack", 20);
        set_temp("apply/defense", 20);

        setup();
        carry_object("/d/murong/obj/cloth2")->wear();
	add_money("silver", 20);
}
