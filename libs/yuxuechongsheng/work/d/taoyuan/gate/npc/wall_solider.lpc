
#include <ansi.h>

inherit NPC;

void create()
{
        set_name("值勤兵", ({ "wall solider", "solider" }) );
        set("long",
"这是个正在执行守城任务的值勤兵，虽然和许多武林人物比起来，值勤兵们的武功\n"
"实在平常，但他们是有组织、有纪律的战士，谁也不轻易地招惹他们。\n"
"[31m你最好也不要招惹他们。 [37m\n");
        set("attitude", "heroism");
        set("str", 27);
	set("vendetta", "authority");
        set("cor", 26);
        set("cps", 25);
        set("combat_exp", 100000);


        set("chat_chance_combat", 15);
        set("chat_msg_combat", ({
                "值勤兵喝道：还不快放下武器束手就缚？\n",
                "值勤兵喝道：大胆刁民竟敢拒捕？反了！反了！\n"
        }) );

        set_skill("unarmed", 70+random(100));
        set_skill("dagger", 70+random(100));
        set_skill("parry", 70+random(100));
        set_skill("dodge", 70+random(100));
        set_skill("move", 100+random(100));

        set_temp("apply/attack", 70);
        set_temp("apply/defense", 70);
        set_temp("apply/damage", 30);
        set_temp("apply/armor", 70);
        set_temp("apply/move", 100);

        setup();

        carry_object(__DIR__"obj/kiujia")->wear();
        carry_object(__DIR__"obj/longdagger")->wield();
}
