// /u/chen/murong/npc/jiading.c ¼Ò¶¡
//by chen

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

        set_temp("apply/attack", 20);
        set_temp("apply/defense", 20);

        setup();
        carry_object("/d/murong/obj/cloth2")->wear();
	add_money("silver", 30);
}
