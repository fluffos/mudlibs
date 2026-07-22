// mazei.c

inherit NPC;


void create()
{
        set_name("马贼", ({ "ma zei", "zei" }));
        set("gender", "男性");
        set("age", random(10) + 30);
        set("str", 25);
        set("dex", 16);
        set("per", 16);
        set("long", "一个彪悍的马贼。\n");
        set("combat_exp", 50000);
        set("shen_type", -1);
        set("attitude", "peaceful");

        set_skill("unarmed", 60);
        set_skill("force", 60);
        set_skill("sword", 60);
        set_skill("dodge", 60);
        set_skill("parry", 60);
        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/armor", 50);
        set_temp("apply/damage", 30);

        set("neili", 400);
        set("max_neili", 400);
        set("jiali", 10);

        setup();
        carry_object(BINGQI_D("gangjian"))->wield();
        carry_object(ARMOR_D("armor"))->wear();
}
