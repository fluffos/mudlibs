// /u/beyond/mr/npc/xiaotong.c Ñ¾÷ß 
// this is made by beyond
// update 1997.6.23
inherit NPC;
void create()
{
        set_name("Ñ¾÷ß", ({ "ya huan", "yahuan" }));
        set("gender", "Å®ĞÔ");
        set("age", 18);
	set("str", 25);
        set("int", 26);
        set("con", 26);
        set("dex", 26);
        set("combat_exp", 5000);
        set("shen_type", 0);
        set("attitude", "peaceful");
	set("max_qi",500);
        set("max_jing",250);
        set("neili",250);
        set("max_neili",250);
	set("jiali",0);
	set("score", 4000);

        set_skill("cuff", 35);
	set_skill("parry",35);
	set_skill("yanling-shenfa",35);
        set_skill("dodge", 35);
	set_skill("force",35);
	set_skill("shenyuan-gong",35);

	map_skill("force","shenyuan-gong");
	map_skill("dodge","yanling-shenfa");

        set_temp("apply/attack", 20);
        set_temp("apply/defense", 20);

        setup();
        carry_object(__DIR__"obj/skirt1")->wear();
        carry_object(__DIR__"obj/shoe")->wear();
        carry_object(__DIR__"obj/green_silk")->wear();
	add_money("silver", 5);
}