// jingbing.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("守城官兵", ({ "bing" }) );
        set("long",
                
"这是个正在执行公务的京城官兵，虽然和许多武林人物比起来，官兵\n"
                
"们的武功实在稀松平常，但是他们是有组织、有纪律的战士，谁也不\n"
                "轻易地招惹他们。\n");

        set("attitude", "heroism");
        set("pursuer", 1);    // 追捕？  1=yes 0=no
        set("vendetta_mark", "authority");  // 记仇标记=“authority” (官府)

        set("str", 27);
        set("cor", 26);
        set("cps", 25);

        set("combat_exp", 500000);

        set("chat_chance", 10);
        

        set("chat_chance_combat", 15);
        set("chat_msg_combat", ({
                "官兵喝道：还不快放下武器束手就缚？\n",
                "官兵喝道：大胆刁民竟敢拒捕？反了！反了！\n"
        }) );

        set_skill("unarmed", 100);
        set_skill("sword", 50);
        set_skill("parry", 50);
        set_skill("dodge", 40);

        set_temp("apply/attack", 70);
        set_temp("apply/defense", 70);
        set_temp("apply/damage", 30);
        set_temp("apply/armor", 70);
        set_temp("apply/move", 100);

        setup();

        carry_object(__DIR__"obj/g_cloth")->wear();
        carry_object(__DIR__"obj/longsword")->wield();
}

 
