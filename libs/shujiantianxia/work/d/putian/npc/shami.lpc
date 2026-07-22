// /d/putian/npc/shami.c
// Lklv 2001.9.12

inherit NPC;

void create()
{
        set_name("小沙弥", ({
                "xiao shami",
                "xiao",
                "shami",
        }));
        set("long",
                "一位年轻的小和尚，正微笑地看着你。\n"
        );

        set("gender", "男性");
        set("attitude", "peaceful");
        set("class", "bonze");

        set("age", 13+random(7));
        set("shen_type", 1);
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);
        set("max_qi", 100);
        set("max_jing", 100);
        set("neili", 100);
        set("max_neili", 100);
        set("combat_exp", 500);
        set("score", 100);

        set_skill("force", 10);
        set_skill("dodge", 10);
        set_skill("unarmed", 10);
        set_skill("parry", 10);

        setup();

        carry_object(__DIR__"obj/cloth")->wear();
        carry_object(__DIR__"obj/sengxie")->wear();
}
