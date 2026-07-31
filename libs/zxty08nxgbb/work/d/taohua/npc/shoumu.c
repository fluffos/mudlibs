// shoumu.c
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("守墓家奴", ({ "shoumu jianu", "jianu" }) );
        set("long",
        "这是一个专门看守墓地的仆人。\n");
        set("attitude", "heroism");
        set("vendetta_mark", "authority");
        set("pursuer", 1);
        set("str", 27);
        set("cor", 26);
        set("cps", 25);
        set("combat_exp", 100000);
        set("chat_chance_combat", 15);
        set("chat_msg_combat", ({
        "守墓人喝道：你好大的胆子，竟敢动墓穴中的东西！\n",
        "守墓人喝道：要让岛主知道，非扒了你的皮不可！\n"
        }) );
 set_skill("luoying-shenjian",40);
        set_skill("sword", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
map_skill("sword","luoying-shenjian");
 map_skill("parry","luoying-shenjian");
        add_temp("apply/attack", 50);
        add_temp("apply/defense", 50);
        add_temp("apply/damage", 50);
        add_temp("apply/armor", 50);
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
}
