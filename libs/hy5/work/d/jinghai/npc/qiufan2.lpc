inherit NPC;
 
void create()
{
        set_name("死囚甲", ({"si jia","jia"}));
        set("long", "这是一个满脸横肉的中年汉子。\n");
        set("gender","男性");
        set("title","[囚犯]");

        set("age",39);
        set("con",30);
        set("str",40);
        set("max_qi",2500);
        set("max_jing",2500);
        set("max_sen",2500);
        set("max_neili", 4000);
        set("neili", 4000);
        set("force_factor", 200);
        set("attitude", "aggressive");

        set("chat_chance",10);
        set("chat_msg",({
        "囚犯高声喊道:别让我出去了，砍死你们这些龟儿子的！\n"
}));

        set_skill("dodge",250);
        set_skill("demon-blade",250);
        set_skill("parry",250);
        set_skill("unarmed",250);
        set_skill("force",250);
        set_skill("fengyu-piaoxiang",280);
        set_skill("changquan",300);
        set_skill("jingyiforce",280);
        set_skill("blade",250);

        map_skill("unarmed","changquan");
        map_skill("dodge","fengyu-piaoxiang");
        map_skill("parry","longjiao-blade");
        map_skill("blade","longjiao-blade");
        map_skill("force","jingyiforce");

        set("combat_exp",2000000+random(700000));

        setup();
        carry_object(__DIR__"obj/qiuyi")->wear();
        carry_object(__DIR__"obj/kao")->wear();
}

