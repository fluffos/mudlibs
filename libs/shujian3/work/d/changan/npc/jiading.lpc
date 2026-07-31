// Write By Yanyang@SJ 2001.10.2
// NPC : /d/changan/npc/jiading.c

inherit NPC;

void create()
{
        set_name("家丁", ({ "jia ding", "ding" }));
        set("age", 22);
        set("gender", "男性");
        set("long", "这些家丁看来从小就被买下了，为主人忠心耿耿的做活。\n");
        set("attitude", "peaceful");

        set("str", 24);
        set("dex", 16);
        set("combat_exp", 10000);
        set("shen_type", 1);

        set_skill("unarmed", 40);
        set_skill("dodge", 40);
        set_skill("parry", 40);
        set_skill("blade", 40);
        set_skill("force", 40);
        set_temp("apply/attack", 40);
        set_temp("apply/defense", 40);
        set_temp("apply/damage", 20);
        set_temp("apply/armor", 40);
        setup();
        carry_object(ARMOR_D("cloth"))->wear();
}