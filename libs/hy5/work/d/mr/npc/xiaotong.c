// /u/beyond/mr/npc/xiaotong.c Ğ¡Í¯
// this is made by beyond
// update 1997.6.23
inherit NPC;
void create()
{
        set_name("Ğ¡Í¯", ({ "xiao tong", "tong" }));
        set("gender", "ÄĞĞÔ");
        set("age", 14);
	set("str", 15);
        set("int", 26);
        set("con", 26);
        set("dex", 26);
        set("combat_exp", 100);
        set("shen_type", 0);
        set("attitude", "peaceful");
	set("max_qi",400);
        set("max_jing",1000);

        set_temp("apply/attack", 10);
        set_temp("apply/defense", 10);

        setup();
        carry_object(__DIR__"obj/cloth2")->wear();
      
}
