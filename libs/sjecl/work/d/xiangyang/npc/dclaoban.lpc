// dclaoban.c 赌场老板

inherit NPC;

void create()
{
        set_name("赌场老板", ({ "lao ban", "laoban" }));
        set("shen_type", 0);
        set("gender", "男性");
        set("age", 42);
        set("long", "他手里拿着一摞彩票，正在翻看着。\n");
        set("no_get_from", 1);
        set("no_get", 1);
        set("no_bark", 1);

        set_skill("unarmed", 60);
        set_skill("dodge", 60);
        set_temp("apply/attack", 30);
        set_temp("apply/attack", 30);
        set_temp("apply/damage", 15);

        set("combat_exp", 200000);
        set("attitude", "friendly");

        setup();
        carry_object(ARMOR_D("changshan3"))->wear();
        carry_object(ARMOR_D("ryyaodai"))->wear();
        carry_object(ARMOR_D("shoes"))->wear();
}

