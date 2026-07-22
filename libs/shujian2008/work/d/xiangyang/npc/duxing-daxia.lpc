// /d/xiangyang/npc/duxing-daxia.c

inherit NPC;

void create()
{
        set_name("独行大侠", ({"duxing daxia", "duxing", "daxia", "xia"}));
        set("long", "他是一个独来独往的旷世大侠，以铲除江湖恶势力为己任。\n");

        set("gender", "男性");
        set("attitude", "peaceful");

        set("age", 52);
        set("shen_type", 1);
        set("shen", 6000);
        set("str", 27);
        set("int", 17);
        set("con", 20);
        set("dex", 20);
        set("max_qi", 800);
        set("max_jing", 800);
        set("neili", 1300);
        set("max_neili", 1300);
        set("jiaji", 40);
        set("combat_exp", 300000);

        set_skill("force", 100);
        set_skill("dodge", 100);
        set_skill("unarmed", 100);
        set_skill("parry", 100);

        setup();
        add_money("silver", 50);
	carry_object(ARMOR_D("cloth"))->wear();
        carry_object(ARMOR_D("shoes"))->wear();
}
