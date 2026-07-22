// judge_guard.c
int back_home(string arg);

inherit BHNPC;

void create()
{
            set_name("值勤兵", ({ "zhi qin bing","zhi","bing" }) );
        set("gender", "男性" );
        set("shen_type",1);
set ("no_arrest",1);
                set("age", 44);
        set("cor", 18);
        set("con", 21);
             set("str", 50);
        set("int", 25);
        set("per", 5);
        set("long", @LONG
值勤兵威风凛凛的望着你，如果没有兵符,休想让他们放你进兵营!
LONG
);
        set("vendetta_mark", "authority");
        set("combat_exp", 400000);

        set("max_neili", 1000);
            set("neili", 1000);
        set("force_factor", 20);

        set("attitude", "heroism");
        set("chat_chance_combat", 15);
        set("chat_msg_combat", ({
              "值勤兵说道：你当这里是什么地方，敢来这里骚扰？\n",
               "值勤兵说道：你要是再无理取闹，把你抓去坐牢!\n",
        }) );

            set_skill("parry", 160);
        set_skill("blade", 160);
        set_skill("dodge", 160);
        
        set_skill("chaos-steps", 160);

        map_skill("dodge", "chaos-steps");

        setup();
        
            carry_object("/obj/npc/obj/blade")->wield();
            carry_object(__DIR__"obj/cloth")->wear();
}

