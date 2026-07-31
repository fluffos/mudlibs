// Npc: keshang.c 客商
// Date: bobo@SJ 2000/03

inherit NPC;


void create()
{
        set_name("客商", ({
                "ke shang",
                "ke",
                "shang",
        }));
        set("long",
                "他是一位过路的客商，准备去四川进货。\n"
        );


        set("gender", "男性");
        set("attitude", "peaceful");
        

        set("age", 40);
        set("shen_type", 10);
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);
          set("max_qi", 100);
        set("max_jing", 100);
        set("neili", 200);
        set("max_neili", 200);
        set("combat_exp", 4000);
        set("score", 100);

        set_skill("force", 10);
        set_skill("dodge", 10);
        set_skill("strike", 10);
        set_skill("parry", 10);
        set_skill("unarmed",10);


        setup();
        carry_object(__DIR__"obj/heiyi")->wear();
}

