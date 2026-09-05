inherit NPC;
void create()
{
        set_name("牧羊人", ({ "muyang ren", "ren", "heardsman" }));
        set("gender", "男性");
        set("age", 60 + random(10));

        set("long", "一个蒙古牧民，赶着几十只羊。\n");

        set("attitude", "friendly");

        set("combat_exp", 1000);
        set("shen_type", 1);

        set_skill("unarmed", 20);
        set_skill("dodge", 20);
        set_skill("parry", 20);
        set_skill("whip", 20);
        set_temp("apply/attack", 10);
        set_temp("apply/defense", 10);
        setup();
        set("chat_chance", 10);
        set("chat_msg", ({
              "牧羊老汉一边看着羊儿吃草，一边唱起了蒙古民歌。\n",
        }) );

        carry_object(__DIR__"obj/mgcloth")->wear();
        carry_object(__DIR__"obj/bian")->wield();
}


