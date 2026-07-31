// /d/xiangyang/npc/heiyi-dadao.c

inherit NPC;

void create()
{
        set_name("黑衣大盗", ({"heiyi dadao", "heiyi", "dadao", "dao"}));
        set("long", "他是一个横行湖北的大盗，经常打劫富室，他身着黑衣。\n");

        set("gender", "男性");
        set("attitude", "heroism");

        set("age", 55);
        set("shen_type", -1);
        set("shen", -4000);
        set("str", 28);
        set("int", 20);
        set("con", 25);
        set("dex", 23);
        set("max_qi", 800);
        set("max_jing", 700);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiaji", 10);
        set("combat_exp", 250000);

        set_skill("force", 90);
        set_skill("dodge", 90);
        set_skill("unarmed", 90);
        set_skill("parry", 90);

        setup();
	add_money("gold", 1);
        carry_object(ARMOR_D("blackcloth"))->wear();
        carry_object(ARMOR_D("shoes"))->wear();
}
